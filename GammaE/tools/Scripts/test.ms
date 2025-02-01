Utility OrionSceneExport "Prueba"
(
	button btn_export "Do" width:100


		-------------------------------------------------------------------------------------
		on cb_exportAsPlugin changed enable do
		(
			ed_name.enabled = enable
			ed_category.enabled = enable
		)
	
		-------------------------------------------------------------------------------------
		on btn_export pressed do
		(
			-- Write SceneMaterials
--			format "	BEGIN MATERIALS %\n" meditMaterials.count
--			oMat = getMeditMaterial 1
--			format " Category %\n" oMat.category
--			format " SubMaterials %\n" oMat.numsubs
--
--			for imat = 1 to oMat.numsubs do
--			(
--				oSubMat = oMat[imat]
--				
--				if (oSubMat.category==#standard) do
--				(
--					if (oSubMat.diffuseMap != undefined) then
--					(
--						format "		% %\n" imat oSubMat.diffuseMap.bitmap.filename
--					)
--					else
--						format "		% <undefined>\n" imat
--				)
--			)

			-- For each object in the scene
			iObj = 1
			for obj = $* do
			(
				format "%\n" obj.category
				if (obj.category == #Editable_Objects) do
				(
					-- export triangle list		
					for i = 1 to getnumfaces obj do
					(
						tri  = GetFace 		obj i
						mat  = GetFaceMatID obj i

						format "% \n" mat
						iObj = iObj+1
					)
				)
			)
		)
)