#pragma once
class Character
{
private:
	typedef void(__thiscall* Hook_so_KilledBy)(void* ShinePlayer, void* attacker, int damage, int aggrorate, unsigned int lot_rate);
public:
	static Hook_so_KilledBy Org_so_KilledBy;
	static void __fastcall so_KilledBy(void* ShinePlayer, void* _edx, void* attacker, int damage, int aggrorate, unsigned int lot_rate);
};

