------------------------------------------
-- Start script code
------------------------------------------
GammaE.DebugClear()
GammaE.DebugPrint('CBrainSlug\n')
-- Get this
this = GammaE.poThis()

uiState = GammaE.castto_uint( this:eGetState() )

ENTSTATE_NONE = 0;
ENTSTATE_INIT = 1;
ENTSTATE_IDLE = 5;
ENTSTATE_AFTERFIRE = 6;

INIT_STATE = 0;

------------------------------------------
-- 
------------------------------------------


	if ((uiState == ENTSTATE_NONE) or (uiState == ENTSTATE_INIT)) then

		-- Switch to the first transitional state
		this:SwitchToState(ENTSTATE_IDLE);

	elseif (uiState == ENTSTATE_IDLE) then
		
		time = this:fTime();

		-- if (time > 5) then

			-- fire a bullet
			-- object = GammaE.CallExtension("FireToPlayer","0.1");
			object = GammaE.CallExtension("FireToPlayer",this:sUID():szString());

			-- set next state
			this:SwitchToState(ENTSTATE_AFTERFIRE);
		-- end

	elseif (uiState == ENTSTATE_AFTERFIRE) then

	end


------------------------------------------
-- Set new angle
------------------------------------------
this:poGraphicInstance():Pitch(0)
this:poGraphicInstance():Yaw( 6.2 * this:fTime()* 0.1 )
this:poGraphicInstance():Roll(0)