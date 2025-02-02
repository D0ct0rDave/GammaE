Utility GammaEAnimExport "GammaE Anim Exporter"
(
	group "Animation"
	(
		checkbox oneframe "Save Animation" checked:false align:#center
		spinner stepframe "Frame Step" range:[1,200,1] fieldwidth:40 type:#integer
		radiobuttons useanim labels:#("Active Time Segment","Custom Time Segment")
		spinner animstart "from" range:[0,1000,0] type:#integer fieldwidth:40 across:2
		spinner animend "to" range:[0,1000,40] type:#integer fieldwidth:40
	)

	group "About"
	(
		label titleLabel	"GammaE Anim Exporter v1.0"
		HyperLink credits1 "by David Márquez de la Cruz" align:#center address:"mailto:vkiller2k@yahoo.es" color:(color 0 100 0) hoverColor:(color 0 0 100)
	)

	button btn_export "Save As..." width:100

		-----------------------------------------------------------------		
		-- Retrieves total the number of triangles in the scene
		-----------------------------------------------------------------			
		function GetNumTrianglesInScene =
		(
			iTotalTris = 0

			-- For each object in the scene
			for obj = $* do
			(
				if (obj.category == #Editable_Objects) do
				(
					iTotalTris = iTotalTris + GetNumFaces obj
				)
			)
			
			return iTotalTris
		)

		-----------------------------------------------------------------		
		-- Save the current scene materials
		-----------------------------------------------------------------
		function SaveMaterials f =
		(
			-- Write SceneMaterials
			format "	BEGIN MATERIALS %\n" meditMaterials.count to: f
			format "	{\n" to: f
	
			for imat = 1 to meditMaterials.count do
			(
				oMat = getMeditMaterial imat
				
				if (oMat.category==#standard) do
				(
					if (oMat.diffuseMap != undefined) then
					(
						format "		% %\n" imat oMat.diffuseMap.bitmap.filename to: f
					)
					else
						format "		% <undefined>\n" imat to: f
				)
			)
			format "	}\n" to: f
			format "	END MATERIALS\n" to: f

			format "\n" to: f
		)
		
		-----------------------------------------------------------------		
		-- Save the first object
		-----------------------------------------------------------------			
		function SaveStartupObject f obj =
		(
			-- export triangle list		
			for i = 1 to getnumfaces obj do
			(
				tri  = GetFace 		obj i
				ttri = getTVFace 	obj i				
				mat  = GetFaceMatID obj i				
				-- ctri = getVCFace obj i
				
				-- Vertices
				VXa	 = GetVert 		obj tri.x
				VXb	 = GetVert 		obj tri.y				
				VXc	 = GetVert 		obj tri.z

				-- Normals
				VNa	 = Normalize(GetNormal obj tri.x)
				VNb	 = Normalize(GetNormal obj tri.y)
				VNc	 = Normalize(GetNormal obj tri.z)
				
				-- Vertex colors
				-- VCa	 = GetVertColor obj ctri.x
				-- VCb	 = GetVertColor obj ctri.y									
				-- VCc	 = GetVertColor obj ctri.z				
			
				-- Texture coordinates
				UVa	 = GetTVert 	obj ttri.x
				UVb	 = GetTVert 	obj ttri.y				
				UVc	 = GetTVert 	obj ttri.z
				
				format "		{\n" to: f
				format "			<%>\n" mat to: f
				format "			<% % %><% % %><% % %>\n"  	VXa.x VXa.y VXa.z 	VXb.x VXb.y VXb.z 	VXc.x VXc.y VXc.z 	to: f
				format "			<% % %><% % %><% % %>\n"  	VNa.x VNa.y VNa.z 	VNb.x VNb.y VNb.z 	VNc.x VNc.y VNc.z 	to: f
				--format "			<% % %><% % %><% % %>\n"  	VCa.r VCa.g VCa.b 	VCb.r VCb.g VCb.b 	VCc.r VCc.g VCc.b 	to: f
				format "			<% % %><% % %><% % %>\n"  	100 100 100 		100 100 100			100 100 100 		to: f
				format "			<% %><% %><% %>\n"      			UVa.x (1.0 - UVa.y)		UVb.x (1.0-UVb.y)		 	UVc.x (1.0 - UVc.y)			to: f
				format "		}\n" to: f
			)
		)

		-----------------------------------------------------------------
		-- Saves one complete model
		-----------------------------------------------------------------
		function SaveStartupModel f =
		(
			iTotalTris = GetNumTrianglesInScene()
			format "    BEGIN TRIS %\n"  iTotalTris to: f
			format "    {\n" to: f
				
				-- For each object in the scene
				for obj = $* do
				(
					if (obj.category == #Editable_Objects) do
					(
						SaveStartupObject f obj 
					)
				)

			format "    }\n" to: f
			format "    END TRIS\n" to: f		
			format "\n" to: f
			)

		-----------------------------------------------------------------
		-- Save the anin object
		-----------------------------------------------------------------
		function SaveAnimObject f obj frame =
		(
			-- export triangle list		
			for i = 1 to getnumfaces obj do at time frame
			(
				tri  = GetFace 		obj i
				ttri = getTVFace 	obj i

				-- Vertices
				VXa	 = GetVert 		obj tri.x
				VXb	 = GetVert 		obj tri.y
				VXc	 = GetVert 		obj tri.z

				-- Normals
				VNa	 = Normalize(GetNormal obj tri.x)
				VNb	 = Normalize(GetNormal obj tri.y)
				VNc	 = Normalize(GetNormal obj tri.z)

				format "		    {\n" to: f
				format "			    <% % %><% % %><% % %>\n"  	VXa.x VXa.y VXa.z 	VXb.x VXb.y VXb.z 	VXc.x VXc.y VXc.z 	to: f
				format "			    <% % %><% % %><% % %>\n"  	VNa.x VNa.y VNa.z 	VNb.x VNb.y VNb.z 	VNc.x VNc.y VNc.z 	to: f
				format "		    }\n" to: f
			)
		)

		-----------------------------------------------------------------
		-- Saves one complete model
		-----------------------------------------------------------------
		function SaveAnimModel f frame =
		(
			fNumFrame = frame / GammaEAnimExport.stepframe.value			
			iNumFrame  = fNumFrame as Integer
			-- frame =  floor(frame)

			format "        BEGIN ANIMFRAME % \n"  frame to: f
			format "        {\n" to: f

			-- For each object in the scene
				for obj = $* do
				(
					if (obj.category == #Editable_Objects) do
					(
						SaveAnimObject f obj frame
					)
				)

			format "        }\n" to: f	
			format "        END ANIMFRAME\n" to: f
			format "\n" to: f
		)
				
		-----------------------------------------------------------------
		-- Saves the entire animation scene
		-----------------------------------------------------------------
		function SaveAnimFrames f =
		(
			if GammaEAnimExport.useanim.state==1 then 
			(
				astart=animationrange.start
				aend=animationrange.end
			)
			else
			(
				astart=GammaEAnimExport.animstart.value
				aend=GammaEAnimExport.animend.value
			)

			if not(GammaEAnimExport.oneframe.state) do 
			(
				astart=1
				aend=1
			)

			fNumFrames = (aend - astart) / GammaEAnimExport.stepframe.value
			iNumFrames = fNumFrames as Integer 
			iNumFrames = iNumFrames + 1
			-- fNumFrames = ceil fNumFrames

			-- numframes = ceil ( fNumFrames / GammaEAnimExport.stepframe.value)
			-- iNumFrames = numframes as Integer 

			format "    BEGIN ANIMFRAMES %\n" fNumFrames to: f
			format "    {\n" to: f

				for frame=astart to aend by GammaEAnimExport.stepframe.value do
				(
					SaveAnimModel f frame
				)

			format "    }\n" to: f
			format "    END ANIMFRAMES\n" to: f
			format "\n" to: f
		)

		-----------------------------------------------------------------
		-- Saves the animation information
		-----------------------------------------------------------------
		function SaveAnimInfo f =
		(
			format "    BEGIN ANIMINFO\n" to: f
			format "    {\n" to: f


			format "    }\n" to: f			
			format "    END ANIMINFO\n" to: f
			format "\n" to: f			
		)
		
		-----------------------------------------------------------------
		-- Saves the entire animation scene
		-----------------------------------------------------------------
		function SaveAnim f =
		(
			format "BEGIN ANIMSCENE\n" to: f
			format "{\n" to: f

			-- Save the materials used
			SaveMaterials f

			-- Save the animation information
			SaveAnimInfo f
			
			-- Save the startup frame
			SaveStartupModel f

			-- Save all the animation frames
			SaveAnimFrames f

			format "}\n" to: f
			format "END ANIMSCENE\n" to: f
		)
		-------------------------------------------------------------------------------------
		function GetSaveFileStream =
		(
			fname = GetSaveFileName types:"GammaE AnimScene files(*.gas)|*.gas|All Files(*.*)|*.*|"
			if fname == undefined then
				return undefined
	
			ostream = CreateFile fname
			if ostream == undefined then
			(
				MessageBox "Couldn't open file for writing !"
				return undefined
			)
	
			return ostream
		)
	
		-------------------------------------------------------------------------------------
		on cb_exportAsPlugin changed enable do
		(
			ed_name.enabled = enable
			ed_category.enabled = enable
		)

		-------------------------------------------------------------------------------------
		on btn_export pressed do
		(
			ostream = GetSaveFileStream()
			if ostream != undefined then
			(
				SaveAnim ostream
				Close ostream
			)
		)
		-------------------------------------------------------------------------------------
)
