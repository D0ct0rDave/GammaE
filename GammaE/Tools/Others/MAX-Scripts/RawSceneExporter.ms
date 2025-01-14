Utility GammaESceneExport "GammaE RawScene exporter"
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
		-- Save the object
		-----------------------------------------------------------------			
		function SaveSceneObject f obj =
		(
			-- export triangle list		
			for i = 1 to getnumfaces obj do
			(
				tri  = GetFace 		obj i
				
				-- Vertices
				VXa	 = GetVert 		obj tri.x
				VXb	 = GetVert 		obj tri.y				
				VXc	 = GetVert 		obj tri.z		
			
				format "(% % %) (% % %) (% % %)\n"  	VXa.x VXa.y VXa.z 	VXb.x VXb.y VXb.z 	VXc.x VXc.y VXc.z 	to: f
			)
		)

		-----------------------------------------------------------------
		-- Saves the entire scene
		-----------------------------------------------------------------
		function SaveScene f =
		(
			iTotalTris = GetNumTrianglesInScene()
			format "%\n"  iTotalTris to: f
							
				-- For each object in the scene
				for obj = $* do
				(
					if (obj.category == #Editable_Objects) do
					(
						SaveSceneObject f obj
					)
				)
		)
		-------------------------------------------------------------------------------------
		function GetSaveFileStream =
		(
			fname = GetSaveFileName types:"Raw scene triangles files(*.rs)|*.rs|All Files(*.*)|*.*|"
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
 