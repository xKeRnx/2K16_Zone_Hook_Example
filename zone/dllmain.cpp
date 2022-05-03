#include "pch.h"
#include <cstring>
#include <detours.h>
#include <string>

// Standard Function declarations
void setHooks();

// Imitating winmm.dll 
// Skip if you inject manually
typedef DWORD(__cdecl* tTimeGetTime)();
tTimeGetTime ctimeGetTime;

DWORD __stdcall timeGetTime() {
	return ctimeGetTime();
}


BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved) {
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
	{
		HMODULE temp = LoadLibraryA("Winmm.dll");
		ctimeGetTime = (tTimeGetTime)GetProcAddress(temp, "timeGetTime");
		setHooks();
	}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

void setHooks() {
	DetourTransactionBegin();
	DetourAttach(&(PVOID&)Character::Org_so_KilledBy, Character::so_KilledBy);
	DetourTransactionCommit();
}