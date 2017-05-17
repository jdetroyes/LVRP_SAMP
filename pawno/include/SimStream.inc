//========================================================//
//=============[MidoStream - Object Streamer]=============//
//=====================[by MidoBan]=======================//
//=====================EDIT BY SIM========================//

/*

native CreateStreamObject(modelid,Float:xpos,Float:ypos,Float:zpos,Float:xrot,Float:yrot,Float:zrot,Float:viewdist=250) - Create a streamed object
native DestroyStreamObject(id) - Destroy a streamed object
native AddMovingObject(modelid,Float:X1,Float:Y1,Float:Z1,Float:X2,Float:Y2,Float:Z2,Float:RX,Float:RY,Float:RZ,Float:Speed2,Float:DIST=250)
native MoveStreamObject(id,Float:X,Float:Y,Float:Z,Float:Speed)
native StopStreamObject(id);
*/

#if defined _SIM_STREAM_INCLUDED
	#endinput
#endif
#define _SIM_STREAM_INCLUDED

#include <a_samp>
new MaxObjects;

forward OnStreamObjectMoved(objectid);

//----------------------------------------------------------
stock CreateStreamObject(modelid,Float:xpos,Float:ypos,Float:zpos,Float:xrot,Float:yrot,Float:zrot,Float:viewdist=250.0)
{
	MaxObjects++;
	return CallRemoteFunction("Core_CreateStreamObject","ifffffff",modelid,xpos,ypos,zpos,xrot,yrot,zrot,viewdist);
}

//----------------------------------------------------------

stock DestroyStreamObject(id)
{
	MaxObjects--;
	CallRemoteFunction("Core_DestroyStreamObject","i",id);
}

//----------------------------------------------------------

stock AttachStreamObjectToPlayer(id,playerid,Float:xoff,Float:yoff,Float:zoff,Float:xrot,Float:yrot,Float:zrot)
{
    CallRemoteFunction("Core_AttachStreamObjectToPlayer","iiffffff",id,playerid,xoff,yoff,zoff,xrot,yrot,zrot);
}

//----------------------------------------------------------

stock MoveStreamObject(id,Float:X,Float:Y,Float:Z,Float:Speed)
{
	return CallRemoteFunction("Core_PutMovingObject","iffff",id,X,Y,Z,Speed);
}

//----------------------------------------------------------

stock AddMovingObject(modelid,Float:X1,Float:Y1,Float:Z1,Float:X2,Float:Y2,Float:Z2,Float:RX,Float:RY,Float:RZ,Float:Speed2,Float:DIST=250.0)
{
	MaxObjects++;
	return CallRemoteFunction("Core_AddMovingObject","ifffffffffff",modelid,X1,Y1,Z1,X2,Y2,Z2,RX,RY,RZ,Speed2,DIST);
}

//----------------------------------------------------------

stock StopStreamObject(id)
{
	CallRemoteFunction("Core_StopMovingObject","i",id);
}
