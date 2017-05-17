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
	StartRecordingPlayback(PLAYER_RECORDING_TYPE_ONFOOT,"noelEat1_Ls");
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
	SendCommand("/npc_eat");
	return 1;
}
//------------------------------------------
