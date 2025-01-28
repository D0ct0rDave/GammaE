------------------------------------------
-- Start script code
------------------------------------------
GammaE.DebugClear()
GammaE.DebugPrint('Camera\n')
-- Get this
this = GammaE.poThis()

------------------------------------------
-- Retrieve position
------------------------------------------
Pos = this:poGraphicInstance():oPos()
smootherX = GammaE.CGUObject( this:hGetUserData(0) ):toSmoother();
smootherY = GammaE.CGUObject( this:hGetUserData(1) ):toSmoother();
smootherZ = GammaE.CGUObject( this:hGetUserData(2) ):toSmoother();
------------------------------------------
-- Retrieve input
------------------------------------------


	newz = Pos.z;

	if (this:fTime() < 60.0) then

		newz = 20.0;
		Pos.z = smootherZ:fValue(newz);

	elseif (this:fTime()<150) then
		
		player = GammaE.castto_CGGameEntity(  GammaE.CGGameRegistry_oGetVar("player") );
		if (player ~= nil) then
			
			PlayerPos = player:poGraphicInstance():oPos()			
			-- Pos.y = PlayerPos.y;

			if ( ((Pos.y - PlayerPos.y) > 1.5) and (PlayerPos.y > -7.2)) then
								
				Pos.y = smootherY:fValue(PlayerPos.y + 1.5);
			
			elseif (((Pos.y - PlayerPos.y) < -1.5)  and (PlayerPos.y < 7.2)) then
				
				Pos.y = smootherY:fValue(PlayerPos.y - 1.5);

			end

		end
		
		
		newz = 10.0;
		Pos.z = smootherZ:fValue(newz);
	else
	
		newz = 20.0;
		Pos.z = smootherZ:fValue(newz);

	end
	
	this:UpdatePos(Pos);
	

