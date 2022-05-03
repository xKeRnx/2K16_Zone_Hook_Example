#include "pch.h"
#include <string>

Character::Hook_so_KilledBy Character::Org_so_KilledBy = reinterpret_cast<Hook_so_KilledBy>(Pointer::so_KilledBy);
void __fastcall Character::so_KilledBy(void* ShinePlayer, void* _edx, void* attacker, int damage, int aggrorate, unsigned int lot_rate) {
	std::string ShinePlayer_Charname = ShineFunctions::GetCharname(ShinePlayer);
	std::string attacker_Charname = ShineFunctions::GetCharname(attacker);

	char Class = ShineFunctions::GetShinePlayerClass((int)attacker);
	if (Class != 0) {
		std::string arg = "[Notice] " + ShinePlayer_Charname + " was killed by " + attacker_Charname;
		ShineFunctions::Send_PROTO_NC_ANNOUNCE_Z2W_CMD(1, arg.c_str());
	}
	Org_so_KilledBy(ShinePlayer, attacker, damage, aggrorate, lot_rate);
}