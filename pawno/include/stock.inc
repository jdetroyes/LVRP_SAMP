/* 
	*	Stock Include, inc qui regroupe tous les stocks du gamemode LS:RP
*/

#define IsValidWeaponID(%0) \
    (%0 < 47)

#define WALK_DEFAULT    0
#define WALK_NORMAL     1
#define WALK_PED        2
#define WALK_GANGSTA    3
#define WALK_GANGSTA2   4
#define WALK_OLD        5
#define WALK_FAT_OLD    6
#define WALK_FAT        7
#define WALK_LADY      	8
#define WALK_LADY2      9
#define WALK_WHORE      10
#define WALK_WHORE2     11
#define WALK_DRUNK     	12
#define WALK_BLIND     	13
//**VARIABLES**//
new walktime[MAX_PLAYERS];
new WalkStyle[MAX_PLAYERS];
//**NATIVES**//
/*
	native SetPlayerWalkingStyle(playerid, style)
	native GetPlayerWalkingStyle(playerid)
*/
/*x---------------------------------CallBacks-------------------------------------x*/
public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if (((newkeys & KEY_WALK && newkeys & KEY_UP) || (newkeys & KEY_WALK && newkeys & KEY_DOWN) || (newkeys & KEY_WALK && newkeys & KEY_LEFT) || (newkeys & KEY_WALK && newkeys & KEY_RIGHT))
		|| ((oldkeys & KEY_WALK && newkeys & KEY_UP) || (oldkeys & KEY_WALK && newkeys & KEY_DOWN) || (oldkeys & KEY_WALK && newkeys & KEY_LEFT) || (oldkeys & KEY_WALK && newkeys & KEY_RIGHT))
		|| ((newkeys & KEY_WALK && oldkeys & KEY_UP) || (newkeys & KEY_WALK && oldkeys & KEY_DOWN) || (newkeys & KEY_WALK && oldkeys & KEY_LEFT) || (newkeys & KEY_WALK && oldkeys & KEY_RIGHT))
		&& GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
			walktime[playerid] = SetTimerEx("WalkAnim",200,0,"d",playerid);
	return Walk_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
}

forward Walk_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);

#define OnPlayerKeyStateChange Walk_OnPlayerKeyStateChange

forward WalkAnim(playerid);
public  WalkAnim(playerid)
{
	new keys, updown, leftright;
	GetPlayerKeys(playerid,keys,updown,leftright);
	if (GetPlayerWalkingStyle(playerid) == WALK_NORMAL)
	{
 	 	if ((keys & KEY_WALK && updown & KEY_UP) || (keys & KEY_WALK && updown & KEY_DOWN) || (keys & KEY_WALK && leftright & KEY_LEFT) || (keys & KEY_WALK && leftright & KEY_RIGHT))
		{
		   	KillTimer(walktime[playerid]);
			ApplyAnimation(playerid,"PED","WALK_player",4.1,1,1,1,1,1);
			walktime[playerid] = SetTimerEx("WalkAnim",200,0,"d",playerid);
		}
		else ApplyAnimation(playerid,"PED","WALK_player",4.0,0,0,0,0,1), KillTimer(walktime[playerid]);
	}
	else if (GetPlayerWalkingStyle(playerid) == WALK_PED)
	{
 	 	if ((keys & KEY_WALK && updown & KEY_UP) || (keys & KEY_WALK && updown & KEY_DOWN) || (keys & KEY_WALK && leftright & KEY_LEFT) || (keys & KEY_WALK && leftright & KEY_RIGHT))
		{
		   	KillTimer(walktime[playerid]);
			ApplyAnimation(playerid,"PED","WALK_civi",4.1,1,1,1,1,1);
			walktime[playerid] = SetTimerEx("WalkAnim",200,0,"d",playerid);
		}
		else ApplyAnimation(playerid,"PED","WALK_civi",4.0,0,0,0,0,1), KillTimer(walktime[playerid]);
	}
 	else if (GetPlayerWalkingStyle(playerid) == WALK_GANGSTA)
	{
 	 	if ((keys & KEY_WALK && updown & KEY_UP) || (keys & KEY_WALK && updown & KEY_DOWN) || (keys & KEY_WALK && leftright & KEY_LEFT) || (keys & KEY_WALK && leftright & KEY_RIGHT))
		{
		   	KillTimer(walktime[playerid]);
			ApplyAnimation(playerid,"PED","WALK_gang1",4.1,1,1,1,1,1);
			walktime[playerid] = SetTimerEx("WalkAnim",200,0,"d",playerid);
		}
		else ApplyAnimation(playerid,"PED","WALK_gang1",4.0,0,0,0,0,1), KillTimer(walktime[playerid]);
	}
	else if (GetPlayerWalkingStyle(playerid) == WALK_GANGSTA2)
	{
 	 	if ((keys & KEY_WALK && updown & KEY_UP) || (keys & KEY_WALK && updown & KEY_DOWN) || (keys & KEY_WALK && leftright & KEY_LEFT) || (keys & KEY_WALK && leftright & KEY_RIGHT))
		{
		   	KillTimer(walktime[playerid]);
			ApplyAnimation(playerid,"PED","WALK_gang2",4.1,1,1,1,1,1);
			walktime[playerid] = SetTimerEx("WalkAnim",200,0,"d",playerid);
		}
		else ApplyAnimation(playerid,"PED","WALK_gang2",4.0,0,0,0,0,1), KillTimer(walktime[playerid]);
	}
	else if (GetPlayerWalkingStyle(playerid) == WALK_OLD)
	{
 	 	if ((keys & KEY_WALK && updown & KEY_UP) || (keys & KEY_WALK && updown & KEY_DOWN) || (keys & KEY_WALK && leftright & KEY_LEFT) || (keys & KEY_WALK && leftright & KEY_RIGHT))
		{
		   	KillTimer(walktime[playerid]);
			ApplyAnimation(playerid,"PED","WALK_old",4.1,1,1,1,1,1);
			walktime[playerid] = SetTimerEx("WalkAnim",200,0,"d",playerid);
		}
		else ApplyAnimation(playerid,"PED","WALK_old",4.0,0,0,0,0,1), KillTimer(walktime[playerid]);
	}
	else if (GetPlayerWalkingStyle(playerid) == WALK_FAT_OLD)
	{
 	 	if ((keys & KEY_WALK && updown & KEY_UP) || (keys & KEY_WALK && updown & KEY_DOWN) || (keys & KEY_WALK && leftright & KEY_LEFT) || (keys & KEY_WALK && leftright & KEY_RIGHT))
		{
		   	KillTimer(walktime[playerid]);
			ApplyAnimation(playerid,"PED","WALK_fatold",4.1,1,1,1,1,1);
			walktime[playerid] = SetTimerEx("WalkAnim",200,0,"d",playerid);
		}
		else ApplyAnimation(playerid,"PED","WALK_fatold",4.0,0,0,0,0,1), KillTimer(walktime[playerid]);
	}
	else if (GetPlayerWalkingStyle(playerid) == WALK_FAT)
	{
 	 	if ((keys & KEY_WALK && updown & KEY_UP) || (keys & KEY_WALK && updown & KEY_DOWN) || (keys & KEY_WALK && leftright & KEY_LEFT) || (keys & KEY_WALK && leftright & KEY_RIGHT))
		{
		   	KillTimer(walktime[playerid]);
			ApplyAnimation(playerid,"PED","WALK_fat",4.1,1,1,1,1,1);
			walktime[playerid] = SetTimerEx("WalkAnim",200,0,"d",playerid);
		}
		else ApplyAnimation(playerid,"PED","WALK_fat",4.0,0,0,0,0,1), KillTimer(walktime[playerid]);
	}
	else if (GetPlayerWalkingStyle(playerid) == WALK_LADY)
	{
 	 	if ((keys & KEY_WALK && updown & KEY_UP) || (keys & KEY_WALK && updown & KEY_DOWN) || (keys & KEY_WALK && leftright & KEY_LEFT) || (keys & KEY_WALK && leftright & KEY_RIGHT))
		{
		   	KillTimer(walktime[playerid]);
			ApplyAnimation(playerid,"PED","WOMAN_walknorm",4.1,1,1,1,1,1);
			walktime[playerid] = SetTimerEx("WalkAnim",200,0,"d",playerid);
		}
		else ApplyAnimation(playerid,"PED","WOMAN_walknorm",4.0,0,0,0,0,1), KillTimer(walktime[playerid]);
	}
	else if (GetPlayerWalkingStyle(playerid) == WALK_LADY2)
	{
 	 	if ((keys & KEY_WALK && updown & KEY_UP) || (keys & KEY_WALK && updown & KEY_DOWN) || (keys & KEY_WALK && leftright & KEY_LEFT) || (keys & KEY_WALK && leftright & KEY_RIGHT))
		{
		   	KillTimer(walktime[playerid]);
			ApplyAnimation(playerid,"PED","WOMAN_walkbusy",4.1,1,1,1,1,1);
			walktime[playerid] = SetTimerEx("WalkAnim",200,0,"d",playerid);
		}
		else ApplyAnimation(playerid,"PED","WOMAN_walkbusy",4.0,0,0,0,0,1), KillTimer(walktime[playerid]);
	}
	else if (GetPlayerWalkingStyle(playerid) == WALK_WHORE)
	{
 	 	if ((keys & KEY_WALK && updown & KEY_UP) || (keys & KEY_WALK && updown & KEY_DOWN) || (keys & KEY_WALK && leftright & KEY_LEFT) || (keys & KEY_WALK && leftright & KEY_RIGHT))
		{
		   	KillTimer(walktime[playerid]);
			ApplyAnimation(playerid,"PED","WOMAN_walkpro",4.1,1,1,1,1,1);
			walktime[playerid] = SetTimerEx("WalkAnim",200,0,"d",playerid);
		}
		else ApplyAnimation(playerid,"PED","WOMAN_walkpro",4.0,0,0,0,0,1), KillTimer(walktime[playerid]);
	}
	else if (GetPlayerWalkingStyle(playerid) == WALK_WHORE2)
	{
 	 	if ((keys & KEY_WALK && updown & KEY_UP) || (keys & KEY_WALK && updown & KEY_DOWN) || (keys & KEY_WALK && leftright & KEY_LEFT) || (keys & KEY_WALK && leftright & KEY_RIGHT))
		{
		   	KillTimer(walktime[playerid]);
			ApplyAnimation(playerid,"PED","WOMAN_walksexy",4.1,1,1,1,1,1);
			walktime[playerid] = SetTimerEx("WalkAnim",200,0,"d",playerid);
		}
		else ApplyAnimation(playerid,"PED","WOMAN_walksexy",4.0,0,0,0,0,1), KillTimer(walktime[playerid]);
	}
	else if (GetPlayerWalkingStyle(playerid) == WALK_DRUNK)
	{
 	 	if ((keys & KEY_WALK && updown & KEY_UP) || (keys & KEY_WALK && updown & KEY_DOWN) || (keys & KEY_WALK && leftright & KEY_LEFT) || (keys & KEY_WALK && leftright & KEY_RIGHT))
		{
		   	KillTimer(walktime[playerid]);
			ApplyAnimation(playerid,"PED","WALK_drunk",4.1,1,1,1,1,1);
			walktime[playerid] = SetTimerEx("WalkAnim",200,0,"d",playerid);
		}
		else ApplyAnimation(playerid,"PED","WALK_drunk",4.0,0,0,0,0,1), KillTimer(walktime[playerid]);
	}
	else if (GetPlayerWalkingStyle(playerid) == WALK_BLIND)
	{
 	 	if ((keys & KEY_WALK && updown & KEY_UP) || (keys & KEY_WALK && updown & KEY_DOWN) || (keys & KEY_WALK && leftright & KEY_LEFT) || (keys & KEY_WALK && leftright & KEY_RIGHT))
		{
		   	KillTimer(walktime[playerid]);
			ApplyAnimation(playerid,"PED","Walk_Wuzi",4.1,1,1,1,1,1);
			walktime[playerid] = SetTimerEx("WalkAnim",200,0,"d",playerid);
		}
		else ApplyAnimation(playerid,"PED","Walk_Wuzi",4.0,0,0,0,0,1), KillTimer(walktime[playerid]);
	}
	return 1;
}

stock SetPlayerWalkingStyle(playerid, style)
{
	WalkStyle[playerid] = style;
}

stock GetPlayerWalkingStyle(playerid)
{
	return WalkStyle[playerid];
}


stock isNumber(const string[])
{
 new length=strlen(string);
 if (length==0) return false;
 for (new i = 0; i < length; i++)
  {
   if (
      (string[i] > '9' || string[i] < '0' && string[i]!='-' && string[i]!='+') // Not a number,'+' or '-'
       || (string[i]=='-' && i!=0)                       // A '-' but not at first.
       || (string[i]=='+' && i!=0)                       // A '+' but not at first.
     ) return false;
  }
 if (length==1 && (string[0]=='-' || string[0]=='+')) return false;
 return true;
}

stock player_IsAValidSkin(skinID)
{
	new s = skinID, invalide=false;
	if(s==0 || s==50 || s==70 || s==71 || s==163 || s==164 || s==165|| s==166)
	{// Famille Fox
		invalide=true;
	}
	else if(s==265 || s==267 || s==274 || s==275 || s==276 || s==277 || s==278 || s==279 || s==280 || s==281 || s==282 || s==283)
	{// Gouvernement
		invalide=true;
 	}
 	else if(s==284 || s==285 || s==286 || s==287 || s==288)
	{// Divers
	    invalide=true;
	}

	if(invalide)
    	{ return true; }
	return false;
}

stock split(const strsrc[], strdest[][], delimiter)
{
	new i, li;
	new aNum;
	new len;
	while(i <= strlen(strsrc)){
	    if(strsrc[i]==delimiter || i==strlen(strsrc)){
	        len = strmid(strdest[aNum], strsrc, li, i, 128);
	        strdest[aNum][len] = 0;
	        li = i+1;
	        aNum++;
		}
		i++;
	}
	return 1;
}

stock LoopingAnim(playerid,animlib[],animname[], Float:Speed, looping, lockx, locky, lockz, lp)
{
	ApplyAnimation(playerid, animlib, animname, Speed, looping, lockx, locky, lockz, lp);
}

stock ConvertToGameText(in[])
{
	new string[256];
	for(new i = 0; in[i]; ++i)
	{
		string[i] = in[i];
		switch(string[i])
		{
			case 0xC0 .. 0xC3: string[i] -= 0x40;
			case 0xC7 .. 0xC9: string[i] -= 0x42;
			case 0xD2 .. 0xD5: string[i] -= 0x44;
			case 0xD9 .. 0xDC: string[i] -= 0x47;
			case 0xE0 .. 0xE3: string[i] -= 0x49;
			case 0xE7 .. 0xEF: string[i] -= 0x4B;
			case 0xF2 .. 0xF5: string[i] -= 0x4D;
			case 0xF9 .. 0xFC: string[i] -= 0x50;
			case 0xC4, 0xE4: string[i] = 0x83;
			case 0xC6, 0xE6: string[i] = 0x84;
			case 0xD6, 0xF6: string[i] = 0x91;
			case 0xD1, 0xF1: string[i] = 0xEC;
			case 0xDF: string[i] = 0x96;
			case 0xBF: string[i] = 0xAF;
		}
	}
	return string;
}

new
    vNames[212][] =
    {
        "Landstalker", "Bravura", "Buffalo", "Linerunner", "Pereniel", "Sentinel", "Dumper", "Firetruck", "Trashmaster", "Stretch", "Manana", "Infernus",
        "Voodoo", "Pony", "Mule", "Cheetah", "Ambulance", "Leviathan", "Moonbeam", "Esperanto", "Taxi", "Washington", "Bobcat", "Mr Whoopee", "BF Injection",
        "Hunter", "Premier", "Enforcer", "Securicar", "Banshee", "Predator", "Bus", "Rhino", "Barracks", "Hotknife", "Trailer", "Previon", "Coach", "Cabbie",
        "Stallion", "Rumpo", "RC Bandit", "Romero", "Packer", "Monster", "Admiral", "Squalo", "Seasparrow", "Pizzaboy", "Tram", "Trailer", "Turismo", "Speeder",
        "Reefer", "Tropic", "Flatbed", "Yankee", "Caddy", "Solair", "Berkley's RC Van", "Skimmer", "PCJ-600", "Faggio", "Freeway", "RC Baron", "RC Raider",
        "Glendale", "Oceanic", "Sanchez", "Sparrow", "Patriot", "Quad", "Coastguard", "Dinghy", "Hermes", "Sabre", "Rustler", "ZR3 50", "Walton", "Regina",
        "Comet", "BMX", "Burrito", "Camper", "Marquis", "Baggage", "Dozer", "Maverick", "News Chopper", "Rancher", "FBI Rancher", "Virgo", "Greenwood",
        "Jetmax", "Hotring", "Sandking", "Blista Compact", "Police Maverick", "Boxville", "Benson", "Mesa", "RC Goblin", "Hotring Racer A", "Hotring Racer B",
        "Bloodring Banger", "Rancher", "Super GT", "Elegant", "Journey", "Bike", "Mountain Bike", "Beagle", "Cropdust", "Stunt", "Tanker", "RoadTrain",
        "Nebula", "Majestic", "Buccaneer", "Shamal", "Hydra", "FCR-900", "NRG-500", "HPV1000", "Cement Truck", "Tow Truck", "Fortune", "Cadrona", "FBI Truck",
        "Willard", "Forklift", "Tractor", "Combine", "Feltzer", "Remington", "Slamvan", "Blade", "Freight", "Streak", "Vortex", "Vincent", "Bullet", "Clover",
        "Sadler", "Firetruck", "Hustler", "Intruder", "Primo", "Cargobob", "Tampa", "Sunrise", "Merit", "Utility", "Nevada", "Yosemite", "Windsor", "Monster A",
        "Monster B", "Uranus", "Jester", "Sultan", "Stratum", "Elegy", "Raindance", "RC Tiger", "Flash", "Tahoma", "Savanna", "Bandito", "Freight", "Trailer",
        "Kart", "Mower", "Duneride", "Sweeper", "Broadway", "Tornado", "AT-400", "DFT-30", "Huntley", "Stafford", "BF-400", "Newsvan", "Tug", "Trailer A", "Emperor",
        "Wayfarer", "Euros", "Hotdog", "Club", "Trailer B", "Trailer C", "Andromada", "Dodo", "RC Cam", "Launch", "Police Car (LSPD)", "Police Car (SFPD)",
        "Police Car (LVPD)", "Police Ranger", "Picador", "S.W.A.T. Van", "Alpha", "Phoenix", "Glendale", "Sadler", "Luggage Trailer A", "Luggage Trailer B",
        "Stair Trailer", "Boxville", "Farm Plow", "Utility Trailer"
    };

new GunObjectIDs[200] ={

   1575,  331, 333, 334, 335, 336, 337, 338, 339, 341, 321, 322, 323, 324, 325, 326, 342, 343, 344, -1,  -1 , -1 ,
   346, 347, 348, 349, 350, 351, 352, 353, 355, 356, 372, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367,
   368, 369, 1575
};

stock GetGunObjectID(WeaponID)
{
    if (WeaponID < 0 || WeaponID > 64)
    {
        return 1575;
    }
    return GunObjectIDs[WeaponID];
}
	
ReturnVehicleID(vName[])
{
    for(new x; x != 211; x++) if(strfind(vNames[x], vName, true) != -1) return x + 400;
    return INVALID_VEHICLE_ID;
}

stock udb_hash(buf[]) {
    new length=strlen(buf);
    new s1 = 1;
    new s2 = 0;
    new n;
    for (n=0; n<length; n++)
    {
       s1 = (s1 + buf[n]) % 65521;
       s2 = (s2 + s1)     % 65521;
    }
    return (s2 << 16) + s1;
}

stock Freeze(playerid, on)
{
	TogglePlayerControllable(playerid, on);
}

stock ClearChatbox(playerid, lines)
{
        if (IsPlayerConnected(playerid))
        {
                for(new i=0; i<lines; i++)
                {
                        SendClientMessage(playerid, 0xAFAFAFAA, " ");
                }
        }
        return 1;
}

stock RespawnVehicle(vehicleid)
{
	SetVehicleToRespawn(vehicleid);
	return 1;
}

stock strtok(const string[], &index, const seperator[] = " ")
{
	const size = 30;
	new idx = strfind(string, seperator, false, index), result[size];
	if(idx == -1)
	{
		if((idx = strlen(string)) > index)
		strmid(result, string, index, idx, size),index = idx;
	}
	else if(idx > (index + size - 1))
	strmid(result, string, index, (idx = index + size - 1), size), index = idx;
	else strmid(result, string, index, idx, size), index = idx + 1;
	return result;
}

stock PlayerToPoint(Float:radi, playerid, Float:x, Float:y, Float:z)
{
    if(IsPlayerConnected(playerid))
	{
		new Float:oldposx, Float:oldposy, Float:oldposz;
		new Float:tempposx, Float:tempposy, Float:tempposz;
		GetPlayerPos(playerid, oldposx, oldposy, oldposz);
		tempposx = (oldposx -x);
		tempposy = (oldposy -y);
		tempposz = (oldposz -z);
		if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi)))
		{
			return 1;
		}
	}
	return 0;
}

stock GetVehicleName(vehicleid)
{
 new name[32];
 switch(GetVehicleModel(vehicleid))
 {
   case 400: format(name,32,"Landstalker");
   case 401: format(name,32,"Bravura");
   case 402: format(name,32,"Buffalo");
   case 403: format(name,32,"Linerunner");
   case 404: format(name,32,"Perenniel");
   case 405: format(name,32,"Sentinel");
   case 406: format(name,32,"Dumper");
   case 407: format(name,32,"Firetruck");
   case 408: format(name,32,"Trashmaster");
   case 409: format(name,32,"Stretch");
   case 410: format(name,32,"Manana");
   case 411: format(name,32,"Infernus");
   case 412: format(name,32,"Voodoo");
   case 413: format(name,32,"Pony");
   case 414: format(name,32,"Mule");
   case 415: format(name,32,"Cheetah");
   case 416: format(name,32,"Ambulance");
   case 417: format(name,32,"Leviathan");
   case 418: format(name,32,"Moonbeam");
   case 419: format(name,32,"Esperanto");
   case 420: format(name,32,"Taxi");
   case 421: format(name,32,"Washington");
   case 422: format(name,32,"Bobcat");
   case 423: format(name,32,"Mr Whoopee");
   case 424: format(name,32,"BF Injection");
   case 425: format(name,32,"Hunter");
   case 426: format(name,32,"Premier");
   case 427: format(name,32,"Enforcer");
   case 428: format(name,32,"Securicar");
   case 429: format(name,32,"Banshee");
   case 430: format(name,32,"Predator");
   case 431: format(name,32,"Bus");
   case 432: format(name,32,"Rhino");
   case 433: format(name,32,"Barracks");
   case 434: format(name,32,"Hotknife");
   case 435: format(name,32,"Article Trailer");
   case 436: format(name,32,"Previon");
   case 437: format(name,32,"Coach");
   case 438: format(name,32,"Cabbie");
   case 439: format(name,32,"Stallion");
   case 440: format(name,32,"Rumpo");
   case 441: format(name,32,"RC Bandit");
   case 442: format(name,32,"Romero");
   case 443: format(name,32,"Packer");
   case 444: format(name,32,"Monster");
   case 445: format(name,32,"Admiral");
   case 446: format(name,32,"Squallo");
   case 447: format(name,32,"Seasparrow");
   case 448: format(name,32,"Pizzaboy");
   case 449: format(name,32,"Tram");
   case 450: format(name,32,"Article Trailer 2");
   case 451: format(name,32,"Turismo");
   case 452: format(name,32,"Speeder");
   case 453: format(name,32,"Reefer");
   case 454: format(name,32,"Tropic");
   case 455: format(name,32,"Flatbed");
   case 456: format(name,32,"Yankee");
   case 457: format(name,32,"Caddy");
   case 458: format(name,32,"Solair");
   case 459: format(name,32,"Berkley's RC Van");
   case 460: format(name,32,"Skimmer");
   case 461: format(name,32,"PCJ-600");
   case 462: format(name,32,"Faggio");
   case 463: format(name,32,"Freeway");
   case 464: format(name,32,"RC Baron");
   case 465: format(name,32,"RC Raider");
   case 466: format(name,32,"Glendale");
   case 467: format(name,32,"Oceanic");
   case 468: format(name,32,"Sanchez");
   case 469: format(name,32,"Sparrow");
   case 470: format(name,32,"Patriot");
   case 471: format(name,32,"Quad");
   case 472: format(name,32,"Coastguard");
   case 473: format(name,32,"Dinghy");
   case 474: format(name,32,"Hermes");
   case 475: format(name,32,"Sabre");
   case 476: format(name,32,"Rustler");
   case 477: format(name,32,"ZR-350");
   case 478: format(name,32,"Walton");
   case 479: format(name,32,"Regina");
   case 480: format(name,32,"Comet");
   case 481: format(name,32,"BMX");
   case 482: format(name,32,"Burrito");
   case 483: format(name,32,"Camper");
   case 484: format(name,32,"Marquis");
   case 485: format(name,32,"Baggage");
   case 486: format(name,32,"Dozer");
   case 487: format(name,32,"Maverick");
   case 488: format(name,32,"SAN News Maverick");
   case 489: format(name,32,"Rancher");
   case 490: format(name,32,"FBI Rancher");
   case 491: format(name,32,"Virgo");
   case 492: format(name,32,"Greenwood");
   case 493: format(name,32,"Jetmax");
   case 494: format(name,32,"Hotring Racer");
   case 495: format(name,32,"Sandking");
   case 496: format(name,32,"Blista Compact");
   case 497: format(name,32,"Police Maverick");
   case 498: format(name,32,"Boxville");
   case 499: format(name,32,"Benson");
   case 500: format(name,32,"Mesa");
   case 501: format(name,32,"RC Goblin");
   case 502: format(name,32,"Hotring Racer");
   case 503: format(name,32,"Hotring Racer");
   case 504: format(name,32,"Bloodring Banger");
   case 505: format(name,32,"Rancher");
   case 506: format(name,32,"Super GT");
   case 507: format(name,32,"Elegant");
   case 508: format(name,32,"Journey");
   case 509: format(name,32,"Bike");
   case 510: format(name,32,"Mountain Bike");
   case 511: format(name,32,"Beagle");
   case 512: format(name,32,"Cropduster");
   case 513: format(name,32,"Stuntplane");
   case 514: format(name,32,"Tanker");
   case 515: format(name,32,"Roadtrain");
   case 516: format(name,32,"Nebula");
   case 517: format(name,32,"Majestic");
   case 518: format(name,32,"Buccaneer");
   case 519: format(name,32,"Shamal");
   case 520: format(name,32,"Hydra");
   case 521: format(name,32,"FCR-900");
   case 522: format(name,32,"NRG-500");
   case 523: format(name,32,"HPV1000");
   case 524: format(name,32,"Cement Truck");
   case 525: format(name,32,"Towtruck");
   case 526: format(name,32,"Fortune");
   case 527: format(name,32,"Cadrona");
   case 528: format(name,32,"FBI Truck");
   case 529: format(name,32,"Willard");
   case 530: format(name,32,"Forklift");
   case 531: format(name,32,"Tractor");
   case 532: format(name,32,"Combine Harvester");
   case 533: format(name,32,"Feltzer");
   case 534: format(name,32,"Remington");
   case 535: format(name,32,"Slamvan");
   case 536: format(name,32,"Blade");
   case 537: format(name,32,"Freight");
   case 538: format(name,32,"Brownstreak");
   case 539: format(name,32,"Vortex");
   case 540: format(name,32,"Vincent");
   case 541: format(name,32,"Bullet");
   case 542: format(name,32,"Clover");
   case 543: format(name,32,"Sadler");
   case 544: format(name,32,"Firetruck LA");
   case 545: format(name,32,"Hustler");
   case 546: format(name,32,"Intruder");
   case 547: format(name,32,"Primo");
   case 548: format(name,32,"Cargobob");
   case 549: format(name,32,"Tampa");
   case 550: format(name,32,"Sunrise");
   case 551: format(name,32,"Merit");
   case 552: format(name,32,"Utility Van");
   case 553: format(name,32,"Nevada");
   case 554: format(name,32,"Yosemite");
   case 555: format(name,32,"Windsor");
   case 556: format(name,32,"Monster A");
   case 557: format(name,32,"Monster B");
   case 558: format(name,32,"Uranus");
   case 559: format(name,32,"Jester");
   case 560: format(name,32,"Sultan");
   case 561: format(name,32,"Stratum");
   case 562: format(name,32,"Elegy");
   case 563: format(name,32,"Raindance");
   case 564: format(name,32,"RC Tiger");
   case 565: format(name,32,"Flash");
   case 566: format(name,32,"Tahoma");
   case 567: format(name,32,"Savanna");
   case 568: format(name,32,"Bandito");
   case 569: format(name,32,"Freight Flat Trailer");
   case 570: format(name,32,"Streak Trailer");
   case 571: format(name,32,"Kart");
   case 572: format(name,32,"Mower");
   case 573: format(name,32,"Dune");
   case 574: format(name,32,"Sweeper");
   case 575: format(name,32,"Broadway");
   case 576: format(name,32,"Tornado");
   case 577: format(name,32,"AT400");
   case 578: format(name,32,"DFT-30");
   case 579: format(name,32,"Huntley");
   case 580: format(name,32,"Stafford");
   case 581: format(name,32,"BF-400");
   case 582: format(name,32,"Newsvan");
   case 583: format(name,32,"Tug");
   case 584: format(name,32,"Petrol Trailer");
   case 585: format(name,32,"Emperor");
   case 586: format(name,32,"Wayfarer");
   case 587: format(name,32,"Euros");
   case 588: format(name,32,"Hotdog");
   case 589: format(name,32,"Club");
   case 590: format(name,32,"Freight Box Trailer");
   case 591: format(name,32,"Article Trailer 3");
   case 592: format(name,32,"Andromada");
   case 593: format(name,32,"Dodo");
   case 594: format(name,32,"RC Cam");
   case 595: format(name,32,"Launch");
   case 596: format(name,32,"Police Car (LSPD)");
   case 597: format(name,32,"Police Car (SFPD)");
   case 598: format(name,32,"Police Car (LVPD)");
   case 599: format(name,32,"Police Ranger");
   case 600: format(name,32,"Picador");
   case 601: format(name,32,"S.W.A.T.");
   case 602: format(name,32,"Alpha");
   case 603: format(name,32,"Phoenix");
   case 604: format(name,32,"Glendale Shit");
   case 605: format(name,32,"Sadler Shit");
   case 606: format(name,32,"Baggage Trailer A");
   case 607: format(name,32,"Baggage Trailer B");
   case 608: format(name,32,"Tug Stairs Trailer");
   case 609: format(name,32,"Boxville");
   case 610: format(name,32,"Farm Trailer");
   case 611: format(name,32,"Utility Trailer");
 }
 return name;
}

stock NiceMoney(amount,sep[]=",")
{
	new str[16],count=-1;
	format(str,16,"%i",amount);
	if(strlen(str)<4)return str;
	for(new i=strlen(str);i>0;i--)//backwards loop ftw!
	{
	    count++;
	    if(count==3)
	    {
			strins(str,sep,i);
			count=0;
		}
	}
	return str;
}

stock CheckPlayerDistanceToVehicle(Float:radi, playerid, vehicleid)
{
	if(IsPlayerConnected(playerid))
	{
	    new Float:PX,Float:PY,Float:PZ,Float:X,Float:Y,Float:Z;
	    GetPlayerPos(playerid,PX,PY,PZ);
	    GetVehiclePos(vehicleid, X,Y,Z);
	    new Float:Distances = (X-PX)*(X-PX)+(Y-PY)*(Y-PY)+(Z-PZ)*(Z-PZ);
	    if(Distances <= radi*radi)
	    {
			if(GetPlayerVirtualWorld(playerid) == GetVehicleVirtualWorld(vehicleid)){
				return 1;
			}
		}
	}
	return 0;
}

stock GetXYBehindPoint(Float:x,Float:y,&Float:x2,&Float:y2,Float:angle,Float:distance)
{
    x2 = x - (distance * floatsin(-angle,degrees));
    y2 = y - (distance * floatcos(-angle,degrees));
}

stock PreloadAnimLib(playerid, animlib[]) 
{ 
    ApplyAnimation(playerid,animlib,"null",0.0,0,0,0,0,0); 
    return 1; 
}  

stock IsPlayerNearBoot(playerid, vehicleid,Float:range = 2.0)
{    
	new Float:X, Float:Y, Float:Z;
	new Float:X2, Float:Y2, Float:angle;
	GetVehiclePos(vehicleid, X, Y, Z); 
    GetVehicleZAngle(vehicleid, angle);
	GetXYBehindPoint(X, Y, X2, Y2, angle, range);
	if(IsPlayerInRangeOfPoint(playerid, range, X2, Y2, Z)) return 1;
	
	return 0;
}

stock RemovePlayerWeapon(playerid, weaponid)
{
        new pWeaponData[13][2];
        for (new i = 0; i < 13; i++)
        {
            GetPlayerWeaponData(playerid, i, pWeaponData[i][0], pWeaponData[i][1]);
        }
       
        ResetPlayerWeapons(playerid);
        for(new i=0; i<13; i++)
        {
                if(pWeaponData[i][0] != 0 && pWeaponData[i][0] != weaponid)
                {
                        GivePlayerWeapon(playerid, pWeaponData[i][0], pWeaponData[i][1]);
                }
        }
        return 0;
}

stock IsABike(carid)
{
    if(carid==0)
	    { return 0; }
	if(GetVehicleModel(carid) == 481 || GetVehicleModel(carid) == 509 || GetVehicleModel(carid) == 510)
	    { return 1; }
	return 0;
}

stock IsAMoto(carid)
{
	if(carid==0)
	    { return 0; }
	new model=GetVehicleModel(carid);
	if(model==471 || model==581 || model==521 || model==522 || model==523 || model==463 || model==461 || model==468 || model==586 || model==462 || model==448)
	    { return 1; }
	return 0;
}

#define SpeedCheck(%0,%1,%2,%3,%4) floatround(floatsqroot(%4?(%0*%0+%1*%1+%2*%2):(%0*%0+%1*%1) ) *%3*1.6)

stock GetVehicleSpeed3D(vehicleid, get3d)
{
	new Float:x, Float:y, Float:z;
	GetVehicleVelocity(vehicleid, x, y, z);
	return SpeedCheck(x, y, z, 100.0, get3d);
}

stock GetVehicleSpeed(vehicleid)
{
	new
		Float:vel[3],
		Float:tempspeed;
	GetVehicleVelocity(vehicleid, vel[0], vel[1], vel[2]);
	tempspeed = floatsqroot((vel[0] * vel[0]) + (vel[1] * vel[1]) + (vel[2] * vel[2])) * 136.666667;
	return floatround(tempspeed, floatround_round);
}

stock house_getExitPos(IntID, &Float:x, &Float:y, &Float:z)
{
	switch(IntID)
	{
		case 1:
	    	{x=235.508994; y=1189.169897; z=1080.339966;}
		case 2:
	    	{x=225.756989; y=1240.000000; z=1082.149902;}
		case 3:
	    	{x=223.043991; y=1289.259888; z=1082.199951;}
		case 4:
	    	{x=225.630997; y=1022.479980; z=1084.069946;}
		case 5:
	    	{x=295.138977; y=1474.469971; z=1080.519897;}
		case 6:
	    	{x=328.493988; y=1480.589966; z=1084.449951;}
		case 7:
	    	{x=385.803986; y=1471.769897; z=1080.209961;}
		case 8:
	    	{x=375.971985; y=1417.269897; z=1081.409912;}
		case 9:
	    	{x=490.810974; y=1401.489990; z=1080.339966;}
 		case 10:
	    	{x=447.734985; y=1400.439941; z=1084.339966;}
		case 11:
	    	{x=227.722992; y=1114.389893; z=1081.189941;}
		case 12:
	    	{x=260.983978; y=1286.549927; z=1080.299927;}
		case 13:
	    	{x=221.666992; y=1143.389893; z=1082.679932;}
		case 14:
	    	{x=27.132700; y=1341.149902; z=1084.449951;}
		case 15:
	    	{x=-262.601990; y=1456.619995; z=1084.449951;}
		case 16:
	    	{x=22.778299; y=1404.959961; z=1084.449951;}
		case 17:
	    	{x=140.278000; y=1368.979980; z=1083.969971;}
		case 18:
	    	{x=234.045990; y=1064.879883; z=1084.309937;}
        case 19:
	    	{x=-68.294098; y=1353.469971; z=1080.279907;}
		case 20:
	    	{x=-285.548981; y=1470.979980; z=1084.449951;}
 		case 21:
	    	{x=-42.581997; y=1408.109985; z=1084.449951;}
		case 22:
	    	{x=83.345093; y=1324.439941; z=1083.889893;}
		case 23:
	    	{x=260.941986; y=1238.509888; z=1084.259888;}
		case 24:
	    	{x=244.411987; y=305.032990; z=999.231995;}
		case 25:
	    	{x=271.884979; y=306.631989; z=999.325989;}
		case 26:
	    	{x=291.282990; y=310.031982; z=999.154968;}
		case 27:
	    	{x=302.181000; y=300.722992; z=999.231995;}
		case 28:
	    	{x=322.197998; y=302.497986; z=999.231995;}
		case 29:
	    	{x=346.870025; y=309.259033; z=999.155700;}
 		case 30:
	    	{x=2496.049805; y=-1693.929932; z=1014.750000;}
        case 31:
	    	{x=1263.079956; y=-785.308960; z=1091.959961;}
        case 32:
	    	{x=2464.109863; y=-1698.659912; z=1013.509949;}
        case 33:
	    	{x=2526.459961; y=-1679.089966; z=1015.500000;}
        case 34:
	    	{x=2543.659912; y=-1303.629883; z=1025.069946;}
        case 35:
	    	{x=744.542969; y=1437.669922; z=1102.739990;}
        case 36:
	    	{x=964.106995; y=-53.205498; z=1001.179993;}
        case 37:
	    	{x=2350.339844; y=-1181.649902; z=1028.000000;}
        case 38:
	    	{x=2807.619873; y=-1171.899902; z=1025.579956;}
        case 39:
	    	{x=318.564972; y=1118.209961; z=1083.979980;}
        case 40:
	    	{x=2324.419922; y=-1147.539917; z=1050.719971;}
        case 41:
	    	{x=446.622986; y=509.318970; z=1001.419983;}
        case 42:
	    	{x=2216.339844; y=-1150.509888; z=1025.799927;}

		default:
	    	{x=235.508994; y=1189.169897; z=1080.339966;}
	}
}

stock house_getInterior(IntID)
{
	switch(IntID)
	{
		case 1:
	    	{return 3;}
		case 2:
	    	{return 2;}
		case 3:
	    	{return 1;}
		case 4:
	    	{return 7;}
		case 5:
	    	{return 15;}
		case 6:
	    	{return 15;}
		case 7:
	    	{return 15;}
		case 8:
	    	{return 15;}
		case 9:
	    	{return 2;}
        case 10:
	    	{return 2;}
		case 11:
	    	{return 5;}
		case 12:
	    	{return 4;}
		case 13:
	    	{return 4;}
		case 14:
	    	{return 10;}
		case 15:
	    	{return 4;}
		case 16:
	    	{return 5;}
		case 17:
	    	{return 5;}
		case 18:
	    	{return 6;}
        case 19:
	    	{return 6;}
		case 20:
	    	{return 15;}
		case 21:
	    	{return 8;}
		case 22:
	    	{return 9;}
		case 23:
	    	{return 9;}
		case 24:
	    	{return 1;}
		case 25:
	    	{return 2;}
		case 26:
	    	{return 3;}
		case 27:
	    	{return 4;}
 		case 28:
	    	{return 5;}
   		case 29:
	    	{return 6;}
		case 30:
	    	{return 3;}
		case 31:
	    	{return 5;}
		case 32:
	    	{return 2;}
		case 33:
	    	{return 1;}
		case 34:
	    	{return 2;}
		case 35:
	    	{return 6;}
		case 36:
	    	{return 3;}
 		case 37:
	    	{return 5;}
        case 38:
	    	{return 8;}
		case 39:
	    	{return 5;}
		case 40:
	    	{return 12;}
		case 41:
	    	{return 12;}
		case 42:
	    	{return 15;}
	}
	return 0;
}

stock PlayerToPointStripped(Float:radi, playerid, Float:x, Float:y, Float:z, Float:curx, Float:cury, Float:curz)
{
    if(IsPlayerConnected(playerid))
	{
		new Float:tempposx, Float:tempposy, Float:tempposz;
		tempposx = (curx -x);
		tempposy = (cury -y);
		tempposz = (curz -z);
		if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi))) return 1;
	}
	return 0;
}

stock OnePlayAnim(playerid,animlib[],animname[], Float:Speed, looping, lockx, locky, lockz, lp)
{
	ApplyAnimation(playerid, animlib, animname, Speed, looping, lockx, locky, lockz, lp);
}

stock ProxDetectorTwo(Float:radi, playerid, string[],color)
{
    new Float:x,Float:y,Float:z;
    GetPlayerPos(playerid,x,y,z);
    for(new i=0; i<MAX_PLAYERS; i++)
    {
        if(IsPlayerInRangeOfPoint(i,radi,x,y,z) && GetPlayerVirtualWorld(playerid) == GetPlayerVirtualWorld(i) && GetPlayerInterior(playerid) == GetPlayerInterior(i)) 
        {
            SendClientMessage(i,color,string);
        }
    }
}

stock ModifyVehicleSpeed(vehicleid,mph) //Miles Per Hour
{
	new Float:Vx,Float:Vy,Float:Vz,Float:DV,Float:multiple;
	GetVehicleVelocity(vehicleid,Vx,Vy,Vz);
	DV = floatsqroot(Vx*Vx + Vy*Vy + Vz*Vz);
	if(DV > 0) //Directional velocity must be greater than 0 (display strobes if 0)
	{
		multiple = ((mph + DV * 100) / (DV * 100)); //Multiplying DV by 100 calculates speed in MPH
		return SetVehicleVelocity(vehicleid,Vx*multiple,Vy*multiple,Vz*multiple);
	}
	return 0;
}


stock ProxDetector(Float:radi, playerid, string[],col1,col2,col3,col4,col5,sendToPlayer)
{
	if(IsPlayerConnected(playerid))
	{
		new Float:posx, Float:posy, Float:posz;
		new Float:oldposx, Float:oldposy, Float:oldposz;
		new Float:tempposx, Float:tempposy, Float:tempposz;
		GetPlayerPos(playerid, oldposx, oldposy, oldposz);
		for(new i=0; i<MAX_PLAYERS; i++)
		{
			if(IsPlayerConnected(i) && GetPlayerVirtualWorld(playerid)==GetPlayerVirtualWorld(i))
			{
			    if(!sendToPlayer && i==playerid)
					{continue;}
				GetPlayerPos(i, posx, posy, posz);
				tempposx = (oldposx -posx);
				tempposy = (oldposy -posy);
				tempposz = (oldposz -posz);
				if (((tempposx < radi/16) && (tempposx > -radi/16)) && ((tempposy < radi/16) && (tempposy > -radi/16)) && ((tempposz < radi/16) && (tempposz > -radi/16)))
					{SendClientMessage(i, col1, string);}
				else if (((tempposx < radi/8) && (tempposx > -radi/8)) && ((tempposy < radi/8) && (tempposy > -radi/8)) && ((tempposz < radi/8) && (tempposz > -radi/8)))
					{SendClientMessage(i, col2, string);}
				else if (((tempposx < radi/4) && (tempposx > -radi/4)) && ((tempposy < radi/4) && (tempposy > -radi/4)) && ((tempposz < radi/4) && (tempposz > -radi/4)))
					{SendClientMessage(i, col3, string);}
				else if (((tempposx < radi/2) && (tempposx > -radi/2)) && ((tempposy < radi/2) && (tempposy > -radi/2)) && ((tempposz < radi/2) && (tempposz > -radi/2)))
					{SendClientMessage(i, col4, string);}
				else if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi)))
					{SendClientMessage(i, col5, string);}
			}
		}
	}//not connected
	return 1;
}

stock ReturnUser(text[], playerid = INVALID_PLAYER_ID)
{
	new pos = 0;
	while (text[pos] < 0x21) // Strip out leading spaces
	{
		if (text[pos] == 0) return INVALID_PLAYER_ID; // No passed text
		pos++;
	}
	new userid = INVALID_PLAYER_ID;
	if (IsNumeric(text[pos])) // Check whole passed string
	{
		// If they have a numeric name you have a problem (although names are checked on id failure)
		userid = strval(text[pos]);
		if (userid >=0 && userid < MAX_PLAYERS)
		{
			if(!IsPlayerConnected(userid))
			{
				/*if (playerid != INVALID_PLAYER_ID)
				{
					SendClientMessage(playerid, 0xFF0000AA, "User not connected");
				}*/
				userid = INVALID_PLAYER_ID;
			}
			else
			{
				return userid; // A player was found
			}
		}
		/*else
		{
			if (playerid != INVALID_PLAYER_ID)
			{
				SendClientMessage(playerid, 0xFF0000AA, "Invalid user ID");
			}
			userid = INVALID_PLAYER_ID;
		}
		return userid;*/
		// Removed for fallthrough code
	}
	// They entered [part of] a name or the id search failed (check names just incase)
	new len = strlen(text[pos]);
	new count = 0;
	new name[MAX_PLAYER_NAME];
	for (new i = 0; i < MAX_PLAYERS; i++)
	{
		if (IsPlayerConnected(i))
		{
			GetPlayerName(i, name, sizeof (name));
			if (strcmp(name, text[pos], true, len) == 0) // Check segment of name
			{
				if (len == strlen(name)) // Exact match
				{
					return i; // Return the exact player on an exact match
					// Otherwise if there are two players:
					// Me and MeYou any time you entered Me it would find both
					// And never be able to return just Me's id
				}
				else // Partial match
				{
					count++;
					userid = i;
				}
			}
		}
	}
	if (count != 1)
	{
		if (playerid != INVALID_PLAYER_ID)
		{
			if (count)
			{
				SendClientMessage(playerid, 0xFF0000AA, "Multiple users found, please narrow earch");
			}
			else
			{
				SendClientMessage(playerid, 0xFF0000AA, "No matching user found");
			}
		}
		userid = INVALID_PLAYER_ID;
	}
	return userid; // INVALID_USER_ID for bad return
}

stock IsNumeric(const string[])
{
	for (new i = 0, j = strlen(string); i < j; i++)
	{
		if (string[i] > '9' || string[i] < '0') return 0;
	}
	return 1;
}


stock player_isValid(playerid)
{
	if(IsPlayerConnected(playerid) && !IsPlayerNPC(playerid))
	    {return true;}
	return false;
}

stock playerDistance(Float:radi, playerid, targetid)
{
    if(IsPlayerConnected(playerid)&&IsPlayerConnected(targetid))
	{
		new Float:posx, Float:posy, Float:posz;
		new Float:oldposx, Float:oldposy, Float:oldposz;
		new Float:tempposx, Float:tempposy, Float:tempposz;
		GetPlayerPos(playerid, oldposx, oldposy, oldposz);
		//radi = 2.0; //Trigger Radius
		GetPlayerPos(targetid, posx, posy, posz);
		tempposx = (oldposx -posx);
		tempposy = (oldposy -posy);
		tempposz = (oldposz -posz);
		//printf("DEBUG: X:%f Y:%f Z:%f",posx,posy,posz);
		if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi)))
		{
			return 1;
		}
	}
	return 0;
}

stock strreplace(string[], find, replace)
{
    for(new i=0; string[i]; i++)
    {
        if(string[i] == find)
        {
            string[i] = replace;
        }
    }
	
}

stock GetName(playerid)
{
    new
        name[24];
    GetPlayerName(playerid, name, sizeof(name));
    strreplace(name, '_', ' ');
    return name;
}

stock SendQuery()
{
        return 1;
}

stock  MySQLFetchAcctSingle(sqlplayerid, sqlvalname[], sqlresult[])
{
	new query[128];
	format(query, sizeof(query), "SELECT %s FROM lsrp_comptes WHERE id = %d LIMIT 1", sqlvalname, sqlplayerid);
	mysql_query(query);
	mysql_store_result();
	if(mysql_fetch_row(sqlresult)==1)
		{mysql_free_result(); return 1;}
    mysql_free_result();
	return 0;
}

stock MySQLCheckAccount(sqlplayersname[])
{
	new query[128];
	new escstr[MAX_PLAYER_NAME];
	mysql_real_escape_string(sqlplayersname, escstr);
	format(query, sizeof(query), "SELECT id FROM lsrp_comptes WHERE LOWER(Name) = LOWER('%s') LIMIT 1", escstr);
	mysql_query(query);
	mysql_store_result();
	if (mysql_num_rows()==0)
		{mysql_free_result(); return 0;}
	else
	{
		new strid[32];
		new intid;
		mysql_fetch_row(strid);
		intid = strval(strid);
		mysql_free_result();
		return intid;
	}
}

stock pName(playerid)
{
        new name[24];
        GetPlayerName(playerid, name, 24);
        return name;
}

stock check_sqlChar(string[])
{
	new caractere1 = strfind(string, "\"", true);
	new caractere2 = strfind(string, "\\", true);
	new caractere3 = strfind(string, "'", true);
    new caractere4 = strfind(string, "#", true);
    new caractere5 = strfind(string, "`", true);
    new caractere6 = strfind(string, "[", true);
    new caractere7 = strfind(string, "]", true);
    new caractere8 = strfind(string, "|", true);

	if(caractere1 != -1 || caractere2 != -1 || caractere3 != -1 || caractere4 != -1 || caractere5 != -1 || caractere6 != -1 || caractere7 != -1 || caractere8 != -1)
		{return 1;}
	return 0;
}

stock IsARolePlayName(newName[])
{
    new ValideName=true;
	if(strlen(newName) < 6 || strlen(newName) > MAX_PLAYER_NAME-1)
 		{ValideName=false;}
	else if(check_sqlChar(newName))
 		{ValideName=false;}
	else if(strfind(newName,"²",true) != -1 || strfind(newName,",",true) != -1 || strfind(newName,";",true) != -1)
 		{ValideName=false;}
   	else if(strfind(newName,"!",true) != -1 || strfind(newName,"?",true) != -1 || strfind(newName,".",true) != -1)
    	{ValideName=false;}
   	else if(strfind(newName,"§",true) != -1 || strfind(newName,"+",true) != -1 || strfind(newName,"=",true) != -1)
    	{ValideName=false;}
   	else if(strfind(newName,")",true) != -1 || strfind(newName,"°",true) != -1 || strfind(newName,"-",true) != -1)
		{ValideName=false;}
  	else if(strfind(newName,"(",true) != -1 || strfind(newName,"/",true) != -1 || strfind(newName,"&",true) != -1)
   		{ValideName=false;}
   	else if(strfind(newName,"@",true) != -1 || strfind(newName,"~",true) != -1 || strfind(newName,"ç",true) != -1)
    	{ValideName=false;}
    else if(strfind(newName,"}",true) != -1 || strfind(newName,"ô",true) != -1 || strfind(newName,"^",true) != -1)
    	{ValideName=false;}
    else if(strfind(newName,"€",true) != -1 || strfind(newName,"$",true) != -1 || strfind(newName,"*",true) != -1)
    	{ValideName=false;}
	else if(strfind(newName,"%",true) != -1 || strfind(newName,"¤",true) != -1 || strfind(newName,"9",true) != -1)
 		{ValideName=false;}
	else if(strfind(newName,"0",true) != -1 || strfind(newName,"1",true) != -1 || strfind(newName,"2",true) != -1)
 		{ValideName=false;}
   	else if(strfind(newName,"3",true) != -1 || strfind(newName,"4",true) != -1 || strfind(newName,"5",true) != -1)
    	{ValideName=false;}
    else if(strfind(newName,"6",true) != -1 || strfind(newName,"7",true) != -1 || strfind(newName,"8",true) != -1)
    	{ValideName=false;}
	else if(strfind(newName,"ù",true) != -1 || strfind(newName,"à",true) != -1 || strfind(newName,"é",true) != -1)
	    {ValideName=false;}
    else if(strfind(newName,"è",true) != -1 || strfind(newName,"ê",true) != -1 || strfind(newName,"â",true) != -1)
	    {ValideName=false;}
    else if(strfind(newName,"û",true) != -1 || strfind(newName,"î",true) != -1 || strfind(newName,"ã",true) != -1)
	    {ValideName=false;}
    else if(strfind(newName,"ä",true) != -1 || strfind(newName,"ë",true) != -1 || strfind(newName,"ï",true) != -1)
	    {ValideName=false;}
    else if(strfind(newName,"ö",true) != -1 || strfind(newName,"ü",true) != -1 || strfind(newName,"ÿ",true) != -1)
	    {ValideName=false;}
    else if(strfind(newName,"ñ",true) != -1 || strfind(newName,"õ",true) != -1 || strfind(newName,"tamere",true) != -1)
	    {ValideName=false;}
	else if(strfind(newName," ",true) != -1)
		{ValideName=false;}
    else if(strfind(newName,"_",true) == -1)
 		{ValideName=false;}

	if(ValideName)
	    {return true;}
	return false;
}

stock IsVehicleOccupied(vehicleid)
{
        for(new i = 0; i < MAX_PLAYERS; i++)
        {
                if(GetPlayerVehicleID(i) == vehicleid)
                {
                        return 1;
                }
        }
       
        return 0;
}

stock GetXYInFrontOfPlayer2(playerid, &Float:x, &Float:y, Float:distance)
{
        new Float:a;
        GetPlayerPos(playerid, x, y, a);
        GetPlayerFacingAngle(playerid, a);
        if (GetPlayerVehicleID(playerid))
        {
            GetVehicleZAngle(GetPlayerVehicleID(playerid), a);
        }
        x += (distance * floatsin(-a, degrees));
        y += (distance * floatcos(-a, degrees));
}

stock GetXYInFrontOfPlayer(playerid, &Float:x, &Float:y, &Float:z, &Float:a, Float:distance)
{
	GetPlayerPos(playerid, x, y ,z);
	if(IsPlayerInAnyVehicle(playerid))
	{
		GetVehicleZAngle(GetPlayerVehicleID(playerid),a);
	}
	else
	{
		GetPlayerFacingAngle(playerid, a);
	}
	x += (distance * floatsin(-a, degrees));
	y += (distance * floatcos(-a, degrees));
	return 0;
}

stock IsVehicleOccupiedDriver(vehicleid)
{
        for(new i = 0; i < MAX_PLAYERS; i++)
        {
        	if(GetPlayerState(i) == PLAYER_STATE_DRIVER)
        	{
                if(GetPlayerVehicleID(i) == vehicleid)
                {
                        return 1;
                }
        	}
        }
       
        return 0;
}

stock returnLetterFromNumber(number,letter[2])
{
	switch(number)
	{
	    case 1: letter="A";
	    case 2: letter="B";
	    case 3: letter="C";
	    case 4: letter="D";
	    case 5: letter="E";
	    case 6: letter="F";
	    case 7: letter="G";
	    case 8: letter="H";
	    case 9: letter="I";
	    case 10: letter="J";
	    case 11: letter="K";
	    case 12: letter="L";
	    case 13: letter="M";
	    case 14: letter="N";
	    case 15: letter="O";
	    case 16: letter="P";
	    case 17: letter="Q";
	    case 18: letter="R";
	    case 19: letter="S";
	    case 20: letter="T";
	    case 21: letter="U";
	    case 22: letter="V";
	    case 23: letter="W";
	    case 24: letter="X";
	    case 25: letter="Y";
	    case 26: letter="Z";
		default: letter="A";
	}
}

IsNumeric2(const string[])
{
    for (new i = 0, j = strlen(string); i < j; i++)
    {
        if (string[i] > '9' || string[i] < '0') return 0;
    }
    return 1;
}

stock SendClientMessageEx(playerid, color, str[], ...)
{
    #define isint(%0)   (getarg(%0, 0) == EOS)
    for(new x = 0; getarg(2, x) != EOS; x++)
    {
        str[x] = getarg(2, x);
    }
    if((numargs()-3) == 0) return SendClientMessage(playerid, color, str);
    if((numargs()-3) > 3) return true;
    new y;
    new final[128];
    new string[6][128];
    y = 3;
    while(y < numargs())
    {
        if(!isint(y))
        {
            for(new x = 0; x < sizeof(string); x++)
            {
                string[y][x] = getarg(y, x);
                if(string[y][x] == EOS) break;
            }
        }
        else
        {
            string[y][0] = getarg(y, 0);
        }
        y++;
    }
    switch(numargs()-3)
    {
        case 1:  //1 argumento
        {
            if(isint(3))    format(final,128,str,string[3][0]);
            else if(!isint(3))    format(final,128,str,string[3]);
        }
        case 2:  //2 argumentos
        {
            if(isint(3) && isint(4))    format(final,128,str,string[3][0], string[4][0]);
            else if(!isint(3) && isint(4))   format(final,128,str,string[3], string[4][0]);
            else if(isint(3) && !isint(4))   format(final,128,str,string[3][0], string[4]);
            else if(!isint(3) && !isint(4))  format(final,128,str,string[3], string[4]);
        }
        case 3: //3 argumentos
        {
            if(isint(3) && isint(4) && isint(5))    format(final,128,str,string[3][0],string[4][0],string[5][0]);
            else if(!isint(3) && !isint(4) && !isint(5))    format(final,128,str,string[3],string[4],string[5]);
            else if(isint(3) && !isint(4) && isint(5))    format(final,128,str,string[3][0],string[4],string[5][0]);
            else if(isint(3) && isint(4) && !isint(5))    format(final,128,str,string[3][0],string[4][0],string[5]);
            else if(isint(3) && !isint(4) && !isint(5))    format(final,128,str,string[3][0],string[4],string[5]);
            else if(!isint(3) && isint(4) && isint(5))    format(final,128,str,string[3],string[4][0],string[5][0]);
            else if(isint(3) && isint(4) && !isint(5))    format(final,128,str,string[3][0],string[4][0],string[5]);
            else if(!isint(3) && isint(4) && !isint(5))    format(final,128,str,string[3],string[4][0],string[5]);
            else if(isint(3) && !isint(4) && isint(5))    format(final,128,str,string[3][0],string[4],string[5][0]);
            else if(!isint(3) && isint(4) && isint(5))    format(final,128,str,string[3],string[4][0],string[5][0]);
            else if(!isint(3) && !isint(4) && isint(5))    format(final,128,str,string[3],string[4],string[5][0]);
        }
    }
    SendClientMessage(playerid, color, final);
    return true;
}

stock date( UnixTimestamp,  _form=0 )
{

	new timestamp=UnixTimestamp+3600; // Decalage de 1h
	new year=1970, day=0, month=0, hour=0, mins=0, sec=0;

	new days_of_month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	new names_of_month[12][10] = {"Janvier","Fevrier","Mars","Avril","Mai","Juin","Juillet","Aout","Septembre","Octobre","Novembre","Decembre"};
	new returnstring[32];

	while(timestamp>31622400){
		timestamp -= 31536000;
		if ( ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) )  timestamp -= 86400;
		year++;
	}

	if ( ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) )
		days_of_month[1] = 29;
	else
		days_of_month[1] = 28;


	while(timestamp>86400)
	{
		timestamp -= 86400, day++;
		if(day==days_of_month[month]) day=0, month++;
	}

	if(_form<4)
	{
		while(timestamp>60)
		{
			timestamp -= 60, mins++;
			if( mins == 60) mins=0, hour++;
		}

		sec=timestamp;
	}
	switch( _form )
	{
		case 1: format(returnstring, 31, "%02d/%02d/%d %02d:%02d:%02d", day+1, month+1, year, hour, mins, sec);
		case 2: format(returnstring, 31, "%s %02d, %d, %02d:%02d:%02d", names_of_month[month],day+1,year,  hour, mins, sec);
		case 3: format(returnstring, 31, "%d %c%c%c %d, %02d:%02d", day+1,names_of_month[month][0],names_of_month[month][1],names_of_month[month][2],  year,hour,mins);
        case 4: format(returnstring, 31, "%d %s %d", day+1,names_of_month[month],  year);
        case 5: format(returnstring, 31, "%02d/%02d/%d", day+1, month+1, year);
        case 6: format(returnstring, 31, "%02d/%s/%d - %02d:%02d:%02d", day+1, names_of_month[month], year, hour, mins, sec);

		default: format(returnstring, 31, "%02d.%02d.%d-%02d:%02d:%02d", day+1, month+1, year, hour+1, mins, sec);
	}

	return returnstring;
}

