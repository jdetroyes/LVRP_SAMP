#include <a_samp>

#define MAX_SPIKESTRIPS 200

enum sInfo
{
	sCreated,
    Float:sX,
    Float:sY,
    Float:sZ,
    sObject,
};
new SpikeInfo[MAX_SPIKESTRIPS][sInfo];


stock CreateStrip(Float:x,Float:y,Float:z,Float:Angle)
{
    for(new i = 0; i < sizeof(SpikeInfo); i++)
  	{
  	    if(SpikeInfo[i][sCreated] == 0)
  	    {
            SpikeInfo[i][sCreated]=1;
            SpikeInfo[i][sX]=x;
            SpikeInfo[i][sY]=y;
            SpikeInfo[i][sZ]=z-0.7;
            SpikeInfo[i][sObject] = CreateObject(2899, x, y, z-0.9, 0, 0, Angle-90);
	        return 1;
  	    }
  	}
  	return 0;
}

stock DeleteAllStrip()
{
    for(new i = 0; i < sizeof(SpikeInfo); i++)
  	{
  	    if(SpikeInfo[i][sCreated] == 1)
  	    {
  	        SpikeInfo[i][sCreated]=0;
            SpikeInfo[i][sX]=0.0;
            SpikeInfo[i][sY]=0.0;
            SpikeInfo[i][sZ]=0.0;
            DestroyObject(SpikeInfo[i][sObject]);
  	    }
	}
    return 0;
}

stock DeleteClosestStrip(playerid)
{
    for(new i = 0; i < sizeof(SpikeInfo); i++)
  	{
  	    if(IsPlayerInRangeOfPoint(playerid, 2.0, SpikeInfo[i][sX], SpikeInfo[i][sY], SpikeInfo[i][sZ]))
        {
  	        if(SpikeInfo[i][sCreated] == 1)
            {
                SpikeInfo[i][sCreated]=0;
                SpikeInfo[i][sX]=0.0;
                SpikeInfo[i][sY]=0.0;
                SpikeInfo[i][sZ]=0.0;
                DestroyObject(SpikeInfo[i][sObject]);
                return 1;
  	        }
  	    }
  	}
    return 0;
}
