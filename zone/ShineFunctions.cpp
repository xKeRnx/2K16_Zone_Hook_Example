#include "pch.h"

ShineFunctions::Hook_Send_PROTO_NC_ANNOUNCE_Z2W_CMD ShineFunctions::Send_PROTO_NC_ANNOUNCE_Z2W_CMD = reinterpret_cast<ShineFunctions::Hook_Send_PROTO_NC_ANNOUNCE_Z2W_CMD>(Pointer::Send_PROTO_NC_ANNOUNCE_Z2W_CMD);

const char* ShineFunctions::GetCharname(void* ShinePlayer) {
	return (*(const char* (__thiscall**)(void*))(*(DWORD*)ShinePlayer + 1388))(ShinePlayer);
}

char ShineFunctions::GetShinePlayerClass(int ShineObject) {
	GetClass* f = (GetClass*)0x5598C0;
	return f((void*)ShineObject, ShineObject);
}