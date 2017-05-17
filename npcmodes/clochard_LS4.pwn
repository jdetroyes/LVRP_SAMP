//
// Mode Npc
// By Dark_Rider
//

#include <a_npc>

//------------------------------------------
main(){}
//------------------------------------------

NextPlayback()
{
	StartRecordingPlayback(PLAYER_RECORDING_TYPE_ONFOOT,"clochard_LS4");
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
public OnPlayerStreamIn(playerid)
{
	SendCommand("/npc_clochard");
	return 1;
}
//------------------------------------------
