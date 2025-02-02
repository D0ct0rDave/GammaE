Utility GammaESceneExport "Orion ControlPoint exporter"
(
		button btn_export "Save As..." width:100
		-------------------------------------------------------------------------------------
		function GetSaveFileStream =
		(
			fname = GetSaveFileName types:"Orion ControlPoint files(*.cp)|*.cp|All Files(*.*)|*.*|"
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
	
		-----------------------------------------------------------------		
		-- Save the current scene control points
		-----------------------------------------------------------------
		function SaveControlPoints f =
		(
				format "// CONTROL POINT FILE\n" to: f

				-- For each object in the scene
				for obj = $* do
				(
					if (obj.category == #standard) do			
					(
				    	if (ClassOf obj == Point) do
						(
							format "% %\n" obj.name obj.pos to: f
						)
					)
				)
		)

		-------------------------------------------------------------------------------------
		on btn_export pressed do
		(		
			ostream = GetSaveFileStream()
			if ostream != undefined then
			(
				SaveControlPoints ostream
				Close ostream
			)
		)
		-------------------------------------------------------------------------------------
)
 