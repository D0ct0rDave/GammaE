------------------------------------------
-- Start script code
------------------------------------------
GammaE.DebugClear()
GammaE.DebugPrint('\nCGameFlow\n')
this = GammaE.poThis()
state = this:eGetState()

------------------------------------------
-- Define states
------------------------------------------
-- The very first state right after (re)initialization
INIT_STATE = 0;

-- estados pares son de "spawn", impares "idle"
STATE0 = GammaE.ENTSTATE_UNUSED;
STATE1 = GammaE.ENTSTATE_UNUSED + 1;
STATE2 = GammaE.ENTSTATE_UNUSED + 2;
STATE3 = GammaE.ENTSTATE_UNUSED + 3;
STATE4 = GammaE.ENTSTATE_UNUSED + 4;

-- Stores the first state to reach after initialization
FIRST_STATE = STATE0;

------------------------------------------
-- State machine code
------------------------------------------

	if ((state == GammaE.ENTSTATE_NONE) or (state == GammaE.ENTSTATE_INIT)) then

		this:Time(0);
		this:ClearUserData();

		-- Create the player
		object = GammaE.CallExtension("CreateEntity","Player");
		this:uiAddUserData(object);
		player = GammaE.castto_CGGameEntity(object);

		-- Create the player
		object = GammaE.CallExtension("CreateEntity","Camera");
		-- this:uiAddUserData(object);
		camera = GammaE.castto_CGGameEntity(object);

		-- Create the enemy group
		object = GammaE.CallExtension("CreateGroupExt","5,0.5,0.0,0,0,0,data/scripts/cbrainslug.lua,data/actors/brainslug/brainslug.gem,Path0,0.3,0xff4080ff,0xff40ff80");
		-- this:uiAddUserData(object);
		group1 = GammaE.castto_CGGameEntity(object);
		object = GammaE.CallExtension("CreateGroupExt","5,0.5,0.0,0,0,0,data/scripts/cbrainslug.lua,data/actors/brainslug/brainslug.gem,Path0,0.3,0xff4080ff,0xff40ff80");
		-- this:uiAddUserData(object);
		group1b = GammaE.castto_CGGameEntity(object);


		object = GammaE.CallExtension("CreateGroupExt","5,0.5,0.0,0,0,0,data/scripts/cbrainslug.lua,data/actors/brainslug/brainslug.gem,Path1,0.3,0xff4080ff,0xff40ff80");
		-- this:uiAddUserData(object);
		group2 = GammaE.castto_CGGameEntity(object);
		object = GammaE.CallExtension("CreateGroupExt","5,0.5,0.0,0,0,0,data/scripts/cbrainslug.lua,data/actors/brainslug/brainslug.gem,Path1,0.3,0xff4080ff,0xff40ff80");
		-- this:uiAddUserData(object);
		group2b = GammaE.castto_CGGameEntity(object);

		object = GammaE.CallExtension("CreateGroupExt","7,3,100.0,0,0,0,data/scripts/cumbrella.lua,data/actors/umbrella/umbrella.gem,Path2,0.3");
		-- this:uiAddUserData(object);
		group3 = GammaE.castto_CGGameEntity(object);
		object = GammaE.CallExtension("CreateGroupExt","7,3,100.0,0,0,0,data/scripts/cumbrella.lua,data/actors/umbrella/umbrella.gem,Path2,0.3");
		-- this:uiAddUserData(object);
		group3b = GammaE.castto_CGGameEntity(object);

		-- 
		object = GammaE.CallExtension("CreateEntity","Enemy,100.0,900,400,0,data/scripts/cegg_scroll.lua,data/actors/egg/egg.gem,NULL,4.0f");
		this:uiAddUserData(object);

		object = GammaE.CallExtension("CreateEntity","Enemy,100.0,900,0,0,data/scripts/cegg_scroll.lua,data/actors/egg/egg.gem,NULL,3.0f");
		this:uiAddUserData(object);

		object = GammaE.CallExtension("CreateEntity","Enemy,100.0,900,300,0,data/scripts/cegg_scroll.lua,data/actors/egg/egg.gem,NULL,5.0f");		
		this:uiAddUserData(object);

		object = GammaE.CallExtension("CreateEntity","Enemy,100.0,900,0,0,data/scripts/cegg_scroll.lua,data/actors/egg/egg.gem,NULL,3.0f");
		this:uiAddUserData(object);

		object = GammaE.CallExtension("CreateEntity","Enemy,100.0,900,400,0,data/scripts/cegg_scroll.lua,data/actors/egg/egg.gem,NULL,4.0f");
		this:uiAddUserData(object);

		object = GammaE.CallExtension("CreateEntity","Enemy,100.0,900,0,0,data/scripts/cegg_scroll.lua,data/actors/egg/egg.gem,NULL,3.0f");
		this:uiAddUserData(object);

		object = GammaE.CallExtension("CreateEntity","Enemy,100.0,900,300,0,data/scripts/cegg_scroll.lua,data/actors/egg/egg.gem,NULL,3.5f");		
		this:uiAddUserData(object);

		object = GammaE.CallExtension("CreateEntity","Enemy,100.0,900,0,0,data/scripts/cegg_scroll.lua,data/actors/egg/egg.gem,NULL,2.5f");
		this:uiAddUserData(object);

		-- Play the video
		GammaE.CallExtension("PlayVideo");

		-- Switch to the first transitional state
		this:SwitchToState(FIRST_STATE);

	elseif (state == STATE0) then

		this:Time(0);
		GammaE.CallExtension("GotoVideoSec","0");

		-- Defferred spawning		
		GammaE.SpawnEntity(group1,5.0);
		GammaE.SpawnEntity(group2,10.0);
		GammaE.SpawnEntity(group3,17.0);
		GammaE.SpawnEntity(group2b,23.0);
		GammaE.SpawnEntity(group1b,28.0);
		GammaE.SpawnEntity(group3b,35.0);
		GammaE.SpawnEntity(group1,40.0);
		GammaE.SpawnEntity(group2,45.0);

		this:SwitchToState(STATE1);

	elseif (state == STATE1) then

		if (this:fTime() > 60) then

			this:SwitchToState(STATE2);

		end	

	elseif (state == STATE2) then

		this:Time(60);
		GammaE.CallExtension("GotoVideoSec","60");

		GammaE.SpawnEntity(GammaE.castto_CGGameEntity( this:hGetUserData(1) ) ,1.0);
		GammaE.SpawnEntity(GammaE.castto_CGGameEntity( this:hGetUserData(2) ) ,9.0);
		GammaE.SpawnEntity(GammaE.castto_CGGameEntity( this:hGetUserData(3) ) ,17.0);
		GammaE.SpawnEntity(GammaE.castto_CGGameEntity( this:hGetUserData(4) ) ,24.0);
		GammaE.SpawnEntity(GammaE.castto_CGGameEntity( this:hGetUserData(5) ) ,32.0);
		GammaE.SpawnEntity(GammaE.castto_CGGameEntity( this:hGetUserData(6) ) ,36.0);
		GammaE.SpawnEntity(GammaE.castto_CGGameEntity( this:hGetUserData(7) ) ,42.0);
		GammaE.SpawnEntity(GammaE.castto_CGGameEntity( this:hGetUserData(8) ) ,49.0);
		GammaE.SpawnEntity(GammaE.castto_CGGameEntity( this:hGetUserData(3) ) ,56.0);
		GammaE.SpawnEntity(GammaE.castto_CGGameEntity( this:hGetUserData(2) ) ,62.0);
		GammaE.SpawnEntity(GammaE.castto_CGGameEntity( this:hGetUserData(5) ) ,68.0);
		GammaE.SpawnEntity(GammaE.castto_CGGameEntity( this:hGetUserData(4) ) ,73.0);
		GammaE.SpawnEntity(GammaE.castto_CGGameEntity( this:hGetUserData(1) ) ,78.0);

		this:SwitchToState(STATE3);

	elseif (state == STATE3) then

		if (this:fTime() > 140) then

			this:SwitchToState(STATE4);

		end

	end

------------------------------------------
-- Spawn the player in case is dead or just created
------------------------------------------
player = GammaE.castto_CGGameEntity( this:hGetUserData(0) );


if (player:eGetState() == GammaE.ENTSTATE_IDLE) then

	-- Spawn the player
	GammaE.SpawnEntity(player,0.0);

end

------------------------------------------
-- Retrieve timer
------------------------------------------
object = GammaE.CGGameRegistry_oGetVar("timer_label");

if (object ~= nil) then
	time = this:fTime();
	time_mins = time / 60;
	time_secs = time % 60;
	time_mils = time - (time_mins*60 + time_secs);

	time_text = string.format("%02d:%02d:%01d",time_mins,time_secs,time_mils);
	
	timer = GammaE.castto_CHUDLabel( object );
	timer:SetText(time_text);
end;

------------------------------------------
-- Retrieve state label
------------------------------------------
object = GammaE.CGGameRegistry_oGetVar("score_label");

if (object ~= nil) then
	label = GammaE.castto_CHUDLabel( object );
	state = GammaE.castto_uint( state );
	lolo = string.format("State %d",state - GammaE.ENTSTATE_UNUSED);
	label:SetText(lolo);
end

GammaE.DebugPrint('7\n');