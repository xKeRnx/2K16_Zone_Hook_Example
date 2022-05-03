#pragma once
class ShineFunctions
{
private:
	typedef char __fastcall GetClass(void*, WORD);
	typedef void(__stdcall* Hook_Send_PROTO_NC_ANNOUNCE_Z2W_CMD)(char AnnounceType, const char* Msg);
public:
	static Hook_Send_PROTO_NC_ANNOUNCE_Z2W_CMD Send_PROTO_NC_ANNOUNCE_Z2W_CMD;

	static const char* GetCharname(void* ShinePlayer);
	static char GetShinePlayerClass(int ShineObject);
};

