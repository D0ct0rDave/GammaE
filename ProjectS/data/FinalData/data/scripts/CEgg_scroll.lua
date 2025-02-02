------------------------------------------
-- Start script code
------------------------------------------
GammaE.DebugClear()
GammaE.DebugPrint('CEgg_scroll\n')

-- Get this
this = GammaE.poThis()

------------------------------------------
-- Retrieve position
------------------------------------------
delta = 2.0 * this:fDeltaT();
Pos = this:poGraphicInstance():oPos()
Pos.x = Pos.x - delta;
this:UpdatePos(Pos);

------------------------------------------
-- Set new angle
------------------------------------------
this:poGraphicInstance():Pitch(0)
this:poGraphicInstance():Yaw( 6.2 * this:fTime()* 0.1 )
this:poGraphicInstance():Roll(0)

------------------------------------------
-- Handle lifetime
------------------------------------------
if (this:fTime() > 25) then
	
	this:Reset()

end

