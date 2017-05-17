//
// Mode Npc Pour La Vie RolePlay
// By Dark_Rider
//

#include <a_npc>

//------------------------------------------
main(){}
//------------------------------------------

NextPlayback()
{
	StartRecordingPlayback(PLAYER_RECORDING_TYPE_ONFOOT,"lvrp_BotBarHopital");
}
//------------------------------------------
public OnRecordingPlaybackEnd()
{
    NextPlayback();
}
//------------------------------------------

public OnNPCSpawn()
{
    NextPlayback();
}
//------------------------------------------
