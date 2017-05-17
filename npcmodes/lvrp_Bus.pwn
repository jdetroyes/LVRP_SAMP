//
// A Driver NPC that goes around a path continuously
// Kye 2009
//

#include <a_npc>

#define NUM_PLAYBACK_FILES 2
new gPlaybackFileCycle=0;

//------------------------------------------

main(){}

//------------------------------------------

NextPlayback()
{
	if(gPlaybackFileCycle==NUM_PLAYBACK_FILES) gPlaybackFileCycle = 0;

	if(gPlaybackFileCycle==0) {
	    StartRecordingPlayback(PLAYER_RECORDING_TYPE_DRIVER,"lvrp_Bus");
	}
	else if(gPlaybackFileCycle==1) {
		StartRecordingPlayback(PLAYER_RECORDING_TYPE_DRIVER,"lvrp_Bus");
	}
	else if(gPlaybackFileCycle==2) {
	    StartRecordingPlayback(PLAYER_RECORDING_TYPE_DRIVER,"lvrp_Bus");
	}

	gPlaybackFileCycle++;
}
	

//------------------------------------------

public OnRecordingPlaybackEnd()
{
    NextPlayback();
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
    gPlaybackFileCycle = 0;
}

//------------------------------------------
