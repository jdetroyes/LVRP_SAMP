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
		StartRecordingPlayback(PLAYER_RECORDING_TYPE_DRIVER,"jobValetBot3_Sf");
}
	

//------------------------------------------

public OnRecordingPlaybackEnd()
{
    StopRecordingPlayback();
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
