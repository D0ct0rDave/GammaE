------------------------------------------
-- Start script code
------------------------------------------
GammaE.DebugClear()
GammaE.DebugPrint('Player\n')
-- Get this
this = GammaE.poThis()
state = this:eGetState()

------------------------------------------
ENTSTATE_SPAWNING		= GammaE.ENTSTATE_UNUSED;
ENTSTATE_INVULNERABLE	= GammaE.ENTSTATE_UNUSED + 1;
ENTSTATE_READY			= GammaE.ENTSTATE_UNUSED + 2;

------------------------------------------
-- Set new angle
------------------------------------------
this:poGraphicInstance():Pitch(0)
this:poGraphicInstance():Yaw(3.14159265)
this:poGraphicInstance():Roll(0)
-- this:poGraphicInstance():Yaw( this:poGraphicInstance():fYaw() + 0.01 )

------------------------------------------
-- Retrieve position
------------------------------------------
Pos = this:poGraphicInstance():oPos()

------------------------------------------
-- Retrieve input
------------------------------------------
smoother = GammaE.CGUObject( this:hGetUserData(0) ):toSmoother();

Pos.x = Pos.x + (this:poInput():fGetValue( GammaE.CGString('right') ) - this:poInput():fGetValue( GammaE.CGString('left') )) * 0.1;
Pos.y = Pos.y + (this:poInput():fGetValue( GammaE.CGString('up')    ) - this:poInput():fGetValue( GammaE.CGString('down') )) * 0.1;
Pos.z = 0;

this:UpdatePos(Pos);

angle = (this:poInput():fGetValue( GammaE.CGString('down') ) - this:poInput():fGetValue( GammaE.CGString('up'  ) )) * 0.5;
newangle = smoother:fValue(angle);
this:poGraphicInstance():Pitch(newangle);

------------------------------------------
-- State machine
------------------------------------------
if (state == GammaE.ENTSTATE_ALIVE) then

	-- Recently spawned	
	Pos.y = 0.0;
	Pos.x = -13.5;

	this:SwitchToState(ENTSTATE_SPAWNING);

elseif (state == ENTSTATE_SPAWNING) then
	
	-- repositioning
	Pos.x = Pos.x + 0.125;

	if (this:fTime() > 1.5) then

		this:SwitchToState(ENTSTATE_INVULNERABLE);

	end

elseif (state == ENTSTATE_INVULNERABLE) then

	-- 
	if (this:fTime() > 3.0) then
		
		-- Set opaque color
		color = GammaE.CGColor(1,1,1,1);
		this:SetColor(color);

		this:SwitchToState(ENTSTATE_READY);
		state = ENTSTATE_READY;

	end

elseif (state == ENTSTATE_READY) then

end

------------------------------------------
-- Handle limits
------------------------------------------
if (state == ENTSTATE_READY) then
	Pos.x = GammaE.MATH_Common_fClamp(-10.5,10.5,Pos.x);
end;

Pos.y = GammaE.MATH_Common_fClamp(-7.5,7.5,Pos.y);

------------------------------------------
-- Handle coloring while in invulnerability mode
------------------------------------------
if ((state == ENTSTATE_SPAWNING) or (state == ENTSTATE_INVULNERABLE)) then 

	value = (GammaE.MATH_Common_fSin( GammaE._2PI_ * this:fTime() * 4.0) + 1.0) * 0.5;

	-- color = GammaE.CGColor(1,1,1,value);
	-- this:SetColor(color);

	-- handle color
	if (value < 0.5) then
		color = GammaE.CGColor(1,1,1,1);
		this:SetColor(color);
	else
		color = GammaE.CGColor(1,1,1,0);
		this:SetColor(color);		
	end

end
------------------------------------------

