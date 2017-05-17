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
	StartRecordingPlayback(PLAYER_RECORDING_TYPE_ONFOOT,"jobValetPed_Sf");
}
//------------------------------------------
public OnRecordingPlaybackEnd()
{
    PauseRecordingPlayback();
}
//------------------------------------------

public OnNPCSpawn()
{
    NextPlayback();
}
//------------------------------------------
