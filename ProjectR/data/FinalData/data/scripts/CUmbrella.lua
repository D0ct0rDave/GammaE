------------------------------------------
-- Start script code
------------------------------------------
GammaE.DebugClear()
GammaE.DebugPrint('CUmbrella\n')
-- Get this
this = GammaE.poThis()

------------------------------------------
-- Set new angle
------------------------------------------
this:poGraphicInstance():Pitch(0)
this:poGraphicInstance():Yaw( 0.25 * 6.2 * this:fTime() )
this:poGraphicInstance():Roll(0)

GammaE.DebugPrint('a\n')