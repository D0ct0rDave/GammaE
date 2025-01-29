Utility GammaESceneExport "GammaE TriScene exporter"
(
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
		function SaveSceneMaterials f =
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
		-- Save the object
		-----------------------------------------------------------------			
		function SaveSceneObject f obj =
		(
			-- export triangle list		
			for i = 1 to getnumfaces obj do
			(
				tri  = GetFace 		obj i
				ttri = getTVFace 	obj i				
				mat  = GetFaceMatID obj i				
				ctri = getVCFace obj i
				
				-- Vertices
				VXa	 = GetVert 		obj tri.x
				VXb	 = GetVert 		obj tri.y				
				VXc	 = GetVert 		obj tri.z

				-- Normals
				VNa	 = Normalize(GetNormal obj tri.x)
				VNb	 = Normalize(GetNormal obj tri.y)
				VNc	 = Normalize(GetNormal obj tri.z)
				
				-- Vertex colors
				VCa	 = GetVertColor obj ctri.x
				VCb	 = GetVertColor obj ctri.y									
				VCc	 = GetVertColor obj ctri.z				
			
				-- Texture coordinates
				UVa	 = GetTVert 	obj ttri.x
				UVb	 = GetTVert 	obj ttri.y				
				UVc	 = GetTVert 	obj ttri.z
				
				format "		{\n" to: f
				format "			<%>\n" mat to: f
				format "			<% % %><% % %><% % %>\n"  	VXa.x VXa.y VXa.z 	VXb.x VXb.y VXb.z 	VXc.x VXc.y VXc.z 	to: f
				format "			<% % %><% % %><% % %>\n"  	VNa.x VNa.y VNa.z 	VNb.x VNb.y VNb.z 	VNc.x VNc.y VNc.z 	to: f
				format "			<% % %><% % %><% % %>\n"  	VCa.r VCa.g VCa.b 	VCb.r VCb.g VCb.b 	VCc.r VCc.g VCc.b 	to: f
				format "			<% %><% %><% %>\n"      	UVa.x (1.0 - UVa.y)		UVb.x (1.0-UVb.y)		 	UVc.x (1.0 - UVc.y)			to: f
				format "		}\n" to: f
			)
		)

		-----------------------------------------------------------------
		-- Saves the entire scene
		-----------------------------------------------------------------
		function SaveScene f =
		(
			format "BEGIN TRISCENE\n" to: f
			format "{\n" to: f

			SaveSceneMaterials f
			iTotalTris = GetNumTrianglesInScene()
			format "	BEGIN TRIS %\n"  iTotalTris to: f
			format "	{\n" to: f
				
				-- For each object in the scene
				for obj = $* do
				(
					if (obj.category == #Editable_Objects) do
					(
						SaveSceneObject f obj 
					)
				)

			format "	}\n" to: f
			format "	END TRIS\n" to: f			
			
			format "}\n" to: f
			format "END TRISCENE\n" to: f
		)
		-------------------------------------------------------------------------------------
		function GetSaveFileStream =
		(
			fname = GetSaveFileName types:"GammaE TriScene files(*.gts)|*.gts|All Files(*.*)|*.*|"
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
				SaveScene ostream
				Close ostream
			)
		)
		-------------------------------------------------------------------------------------
)
 