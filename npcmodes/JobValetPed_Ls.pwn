//
// A Driver NPC that goes around a path continuously
// Kye 2009
//

#include <a_npc>


//------------------------------------------

main(){}

//------------------------------------------

NextPlayback()
{
		StartRecordingPlayback(PLAYER_RECORDING_TYPE_DRIVER,"JobValetPed_Ls");
}
	

//------------------------------------------

public OnRecordingPlaybackEnd()
{
    PauseRecordingPlayback();
}

//------------------------------------------

public OnNPCEnterVehicle(vehicleid, seatid)
{
    NextPlayback();
}

//------------------------------------------

public OnNPCExitVehicle()
{
    StopRecordingPlayback();
}

//------------------------------------------