//
// A Driver NPC that goes around a path continuously
// Kye 2009
//

#include <a_npc>

public npc_taxiStart();
new gPlaybackFileCycle=0;
new gPlayBackType=0;

//------------------------------------------

main(){}

//------------------------------------------

public npc_taxiStart()
{
	print("Test Bot");
	ResumeRecordingPlayback();
    /*StopRecordingPlayback();
    gPlaybackFileCycle=1;
    if(type == 1)
		{StartRecordingPlayback(PLAYER_RECORDING_TYPE_DRIVER,"taxiAirPort_LS1"); gPlayBackType=type;}*/
}


//------------------------------------------

public OnRecordingPlaybackEnd()
{
	StartRecordingPlayback(PLAYER_RECORDING_TYPE_DRIVER,"taxiAirPort_LS1b");
}
//------------------------------------------

public OnNPCEnterVehicle(vehicleid, seatid)
{
    StartRecordingPlayback(PLAYER_RECORDING_TYPE_DRIVER,"taxiAirPort_LS1");
    PauseRecordingPlayback();
}

//------------------------------------------

public OnNPCExitVehicle()
{
    StopRecordingPlayback();
}

//------------------------------------------
