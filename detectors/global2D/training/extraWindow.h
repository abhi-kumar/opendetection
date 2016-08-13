#include "network.h"

void NetworkCreator::showWindow_extraLayerType(Glib::ustring data)
{
	remove();
	set_title("Extra Layer");
	set_border_width(10);
	add(m_sw_extraLayerType);
	m_grid_extraLayerType.set_column_spacing (10);
	m_grid_extraLayerType.set_row_spacing (50);

	if(data == "" or data == "ArgMax")
		title_extraLayerType.set_text("Set the Properties of Loss Layer type: ArgMax");
	else if(data == "BNLL" or data == "Eltwise" or data == "ImageData" or data == "Data" or data == "HDF5Data")
		title_extraLayerType.set_text("Set the Properties of Loss Layer type: " + data);
	else
		title_extraLayerType.set_text("Will be updated soon");
	title_extraLayerType.set_line_wrap();
	title_extraLayerType.set_justify(Gtk::JUSTIFY_FILL);
//	m_grid_extraLayerType.attach(title_extraLayerType,0,0,2,1);
	title_extraLayerType.show();

	button_addMoreLayer5.show();


	if(data == "" or data == "ArgMax")
	{
		button_setExtraParameters.hide();
		label_extraLayerBottom1.hide();
		label_extraLayerTop1.hide();
		label_extraLayerTop2.hide();
		label_extraLayerName.hide();
		text_extraLayerBottom1.hide();
		text_extraLayerTop1.hide();
		text_extraLayerTop2.hide();
		text_extraLayerName.hide();
		text_extraLayerTopK.hide();
		label_extraLayerTopK.hide();
		label_extraLayerOutMaxVal.hide();
		rbutton_extraLayerOutMaxValTrue.hide();
		rbutton_extraLayerOutMaxValFalse.hide();
		label_extraLayerBottom2.hide();
		text_extraLayerBottom2.hide();
		label_extraLayerPhase.hide();
		rbutton_extraLayerTrain.hide();
		rbutton_extraLayerTest.hide();
		label_extraLayerScale.hide();
		label_extraLayerNewHeight.hide();
		label_extraLayerNewWidth.hide();
		label_extraLayerCropSize.hide();
		label_extraLayerMeanFile.hide();
		rbutton_extraLayerScaleYes.hide();
		rbutton_extraLayerScaleNo.hide();
		rbutton_extraLayerNewHeightYes.hide();
		rbutton_extraLayerNewHeightNo.hide();
		rbutton_extraLayerNewWidthYes.hide();
		rbutton_extraLayerNewWidthNo.hide();
		rbutton_extraLayerCropSizeYes.hide();
		rbutton_extraLayerCropSizeNo.hide();
		rbutton_extraLayerMeanFileYes.hide();
		rbutton_extraLayerMeanFileNo.hide();
		text_extraLayerScale.hide();
		text_extraLayerNewHeight.hide();
		text_extraLayerNewWidth.hide();
		text_extraLayerCropSize.hide();
		text_extraLayerMeanFile.hide();
		label_extraLayerSource.hide();
		label_extraLayerBatchSize.hide();
		text_extraLayerSource.hide();
		text_extraLayerBatchSize.hide();
		label_extraLayerBackend.hide();
		rbutton_extraLayerLMDB.hide();
		rbutton_extraLayerLEVELDB.hide();


		label_extraLayerBottom1.set_text("Bottom1 Layer Name: ");
		label_extraLayerBottom1.set_line_wrap();
		label_extraLayerBottom1.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerBottom1,0,1,2,1);
		label_extraLayerBottom1.show();

		text_extraLayerBottom1.set_max_length(100);
		text_extraLayerBottom1.set_text("");
		text_extraLayerBottom1.select_region(0, text_extraLayerBottom1.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerBottom1,2,1,1,1);	
		text_extraLayerBottom1.show();

		label_extraLayerTop1.set_text("Top1 Layer Name: ");
		label_extraLayerTop1.set_line_wrap();
		label_extraLayerTop1.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerTop1,0,2,2,1);
		label_extraLayerTop1.show();

		text_extraLayerTop1.set_max_length(100);
		text_extraLayerTop1.set_text("");
		text_extraLayerTop1.select_region(0, text_extraLayerTop1.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerTop1,2,2,1,1);	
		text_extraLayerTop1.show();

		label_extraLayerName.set_text("Current Layer Name: ");
		label_extraLayerName.set_line_wrap();
		label_extraLayerName.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerName,0,3,2,1);
		label_extraLayerName.show();

		text_extraLayerName.set_max_length(100);
		text_extraLayerName.set_text("");
		text_extraLayerName.select_region(0, text_extraLayerName.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerName,2,3,1,1);	
		text_extraLayerName.show();

		label_extraLayerTopK.set_text("top_k: \n(Top K Classifications)");
		label_extraLayerTopK.set_line_wrap();
		label_extraLayerTopK.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerTopK,0,4,2,1);
		label_extraLayerTopK.show();

		text_extraLayerTopK.set_max_length(100);
		text_extraLayerTopK.set_text("");
		text_extraLayerTopK.select_region(0, text_extraLayerTopK.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerName,2,4,1,1);	
		text_extraLayerTopK.show();

		label_extraLayerOutMaxVal.set_text("out_max_val: \n(if true returns pair \n{max_index, max_value} the input)");
		label_extraLayerOutMaxVal.set_line_wrap();
		label_extraLayerOutMaxVal.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerOutMaxVal,0,5,2,1);
		label_extraLayerOutMaxVal.show();

//		Gtk::RadioButton::Group group8 = rbutton_extraLayerOutMaxValTrue.get_group();
//		rbutton_extraLayerOutMaxValFalse.set_group(group8);
	 	rbutton_extraLayerOutMaxValTrue.set_active();
//		m_grid_lossLayerType.attach(rbutton_extraLayerOutMaxValTrue,2,5,1,1);
		rbutton_extraLayerOutMaxValTrue.show();
//		m_grid_lossLayerType.attach(rbutton_extraLayerOutMaxValFalse,3,5,1,1);
		rbutton_extraLayerOutMaxValFalse.show();

		button_setExtraParameters.show();		
	}
	else if(data == "BNLL")
	{
		button_setExtraParameters.hide();
		label_extraLayerBottom1.hide();
		label_extraLayerTop1.hide();
		label_extraLayerTop2.hide();
		label_extraLayerName.hide();
		text_extraLayerBottom1.hide();
		text_extraLayerTop1.hide();
		text_extraLayerTop2.hide();
		text_extraLayerName.hide();
		text_extraLayerTopK.hide();
		label_extraLayerTopK.hide();
		label_extraLayerOutMaxVal.hide();
		rbutton_extraLayerOutMaxValTrue.hide();
		rbutton_extraLayerOutMaxValFalse.hide();
		label_extraLayerBottom2.hide();
		text_extraLayerBottom2.hide();
		label_extraLayerPhase.hide();
		rbutton_extraLayerTrain.hide();
		rbutton_extraLayerTest.hide();
		label_extraLayerScale.hide();
		label_extraLayerNewHeight.hide();
		label_extraLayerNewWidth.hide();
		label_extraLayerCropSize.hide();
		label_extraLayerMeanFile.hide();
		rbutton_extraLayerScaleYes.hide();
		rbutton_extraLayerScaleNo.hide();
		rbutton_extraLayerNewHeightYes.hide();
		rbutton_extraLayerNewHeightNo.hide();
		rbutton_extraLayerNewWidthYes.hide();
		rbutton_extraLayerNewWidthNo.hide();
		rbutton_extraLayerCropSizeYes.hide();
		rbutton_extraLayerCropSizeNo.hide();
		rbutton_extraLayerMeanFileYes.hide();
		rbutton_extraLayerMeanFileNo.hide();
		text_extraLayerScale.hide();
		text_extraLayerNewHeight.hide();
		text_extraLayerNewWidth.hide();
		text_extraLayerCropSize.hide();
		text_extraLayerMeanFile.hide();
		label_extraLayerSource.hide();
		label_extraLayerBatchSize.hide();
		text_extraLayerSource.hide();
		text_extraLayerBatchSize.hide();
		label_extraLayerBackend.hide();
		rbutton_extraLayerLMDB.hide();
		rbutton_extraLayerLEVELDB.hide();

		label_extraLayerBottom1.set_text("Bottom1 Layer Name: ");
		label_extraLayerBottom1.set_line_wrap();
		label_extraLayerBottom1.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerBottom1,0,1,2,1);
		label_extraLayerBottom1.show();

		text_extraLayerBottom1.set_max_length(100);
		text_extraLayerBottom1.set_text("");
		text_extraLayerBottom1.select_region(0, text_extraLayerBottom1.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerBottom1,2,1,1,1);	
		text_extraLayerBottom1.show();

		label_extraLayerTop1.set_text("Top1 Layer Name: ");
		label_extraLayerTop1.set_line_wrap();
		label_extraLayerTop1.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerTop1,0,2,2,1);
		label_extraLayerTop1.show();

		text_extraLayerTop1.set_max_length(100);
		text_extraLayerTop1.set_text("");
		text_extraLayerTop1.select_region(0, text_extraLayerTop1.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerTop1,2,2,1,1);	
		text_extraLayerTop1.show();

		label_extraLayerName.set_text("Current Layer Name: ");
		label_extraLayerName.set_line_wrap();
		label_extraLayerName.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerName,0,3,2,1);
		label_extraLayerName.show();

		text_extraLayerName.set_max_length(100);
		text_extraLayerName.set_text("");
		text_extraLayerName.select_region(0, text_extraLayerName.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerName,2,3,1,1);	
		text_extraLayerName.show();

		button_setExtraParameters.show();		
	}
	else if(data == "Eltwise")
	{
		button_setExtraParameters.hide();
		label_extraLayerBottom1.hide();
		label_extraLayerTop1.hide();
		label_extraLayerTop2.hide();
		label_extraLayerName.hide();
		text_extraLayerBottom1.hide();
		text_extraLayerTop1.hide();
		text_extraLayerTop2.hide();
		text_extraLayerName.hide();
		text_extraLayerTopK.hide();
		label_extraLayerTopK.hide();
		label_extraLayerOutMaxVal.hide();
		rbutton_extraLayerOutMaxValTrue.hide();
		rbutton_extraLayerOutMaxValFalse.hide();
		label_extraLayerBottom2.hide();
		text_extraLayerBottom2.hide();
		label_extraLayerPhase.hide();
		rbutton_extraLayerTrain.hide();
		rbutton_extraLayerTest.hide();
		label_extraLayerScale.hide();
		label_extraLayerNewHeight.hide();
		label_extraLayerNewWidth.hide();
		label_extraLayerCropSize.hide();
		label_extraLayerMeanFile.hide();
		rbutton_extraLayerScaleYes.hide();
		rbutton_extraLayerScaleNo.hide();
		rbutton_extraLayerNewHeightYes.hide();
		rbutton_extraLayerNewHeightNo.hide();
		rbutton_extraLayerNewWidthYes.hide();
		rbutton_extraLayerNewWidthNo.hide();
		rbutton_extraLayerCropSizeYes.hide();
		rbutton_extraLayerCropSizeNo.hide();
		rbutton_extraLayerMeanFileYes.hide();
		rbutton_extraLayerMeanFileNo.hide();
		text_extraLayerScale.hide();
		text_extraLayerNewHeight.hide();
		text_extraLayerNewWidth.hide();
		text_extraLayerCropSize.hide();
		text_extraLayerMeanFile.hide();
		label_extraLayerSource.hide();
		label_extraLayerBatchSize.hide();
		text_extraLayerSource.hide();
		text_extraLayerBatchSize.hide();
		label_extraLayerBackend.hide();
		rbutton_extraLayerLMDB.hide();
		rbutton_extraLayerLEVELDB.hide();


		label_extraLayerBottom1.set_text("Bottom1 Layer Name: ");
		label_extraLayerBottom1.set_line_wrap();
		label_extraLayerBottom1.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerBottom1,0,1,2,1);
		label_extraLayerBottom1.show();

		text_extraLayerBottom1.set_max_length(100);
		text_extraLayerBottom1.set_text("");
		text_extraLayerBottom1.select_region(0, text_extraLayerBottom1.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerBottom1,2,1,1,1);	
		text_extraLayerBottom1.show();

		label_extraLayerBottom2.set_text("Bottom2 Layer Name: ");
		label_extraLayerBottom2.set_line_wrap();
		label_extraLayerBottom2.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerBottom2,0,2,2,1);
		label_extraLayerBottom2.show();

		text_extraLayerBottom2.set_max_length(100);
		text_extraLayerBottom2.set_text("");
		text_extraLayerBottom2.select_region(0, text_extraLayerBottom2.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerBottom2,2,2,1,1);	
		text_extraLayerBottom2.show();

		label_extraLayerTop1.set_text("Top1 Layer Name: ");
		label_extraLayerTop1.set_line_wrap();
		label_extraLayerTop1.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerTop1,0,2,2,1);
		label_extraLayerTop1.show();

		text_extraLayerTop1.set_max_length(100);
		text_extraLayerTop1.set_text("");
		text_extraLayerTop1.select_region(0, text_extraLayerTop1.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerTop1,2,2,1,1);	
		text_extraLayerTop1.show();

		label_extraLayerName.set_text("Current Layer Name: ");
		label_extraLayerName.set_line_wrap();
		label_extraLayerName.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerName,0,3,2,1);
		label_extraLayerName.show();

		text_extraLayerName.set_max_length(100);
		text_extraLayerName.set_text("");
		text_extraLayerName.select_region(0, text_extraLayerName.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerName,2,3,1,1);	
		text_extraLayerName.show();

		button_setExtraParameters.show();
	}
	else if(data == "ImageData")
	{
		button_setExtraParameters.hide();
		label_extraLayerBottom1.hide();
		label_extraLayerTop1.hide();
		label_extraLayerTop2.hide();
		label_extraLayerName.hide();
		text_extraLayerBottom1.hide();
		text_extraLayerTop1.hide();
		text_extraLayerTop2.hide();
		text_extraLayerName.hide();
		text_extraLayerTopK.hide();
		label_extraLayerTopK.hide();
		label_extraLayerOutMaxVal.hide();
		rbutton_extraLayerOutMaxValTrue.hide();
		rbutton_extraLayerOutMaxValFalse.hide();
		label_extraLayerBottom2.hide();
		text_extraLayerBottom2.hide();
		label_extraLayerPhase.hide();
		rbutton_extraLayerTrain.hide();
		rbutton_extraLayerTest.hide();
		label_extraLayerScale.hide();
		label_extraLayerNewHeight.hide();
		label_extraLayerNewWidth.hide();
		label_extraLayerCropSize.hide();
		label_extraLayerMeanFile.hide();
		rbutton_extraLayerScaleYes.hide();
		rbutton_extraLayerScaleNo.hide();
		rbutton_extraLayerNewHeightYes.hide();
		rbutton_extraLayerNewHeightNo.hide();
		rbutton_extraLayerNewWidthYes.hide();
		rbutton_extraLayerNewWidthNo.hide();
		rbutton_extraLayerCropSizeYes.hide();
		rbutton_extraLayerCropSizeNo.hide();
		rbutton_extraLayerMeanFileYes.hide();
		rbutton_extraLayerMeanFileNo.hide();
		text_extraLayerScale.hide();
		text_extraLayerNewHeight.hide();
		text_extraLayerNewWidth.hide();
		text_extraLayerCropSize.hide();
		text_extraLayerMeanFile.hide();
		label_extraLayerSource.hide();
		label_extraLayerBatchSize.hide();
		text_extraLayerSource.hide();
		text_extraLayerBatchSize.hide();
		label_extraLayerBackend.hide();
		rbutton_extraLayerLMDB.hide();
		rbutton_extraLayerLEVELDB.hide();


		label_extraLayerTop1.set_text("Top1 Layer Name: ");
		label_extraLayerTop1.set_line_wrap();
		label_extraLayerTop1.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerTop1,0,2,2,1);
		label_extraLayerTop1.show();

		text_extraLayerTop1.set_max_length(100);
		text_extraLayerTop1.set_text("");
		text_extraLayerTop1.select_region(0, text_extraLayerTop1.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerTop1,2,2,1,1);	
		text_extraLayerTop1.show();

		label_extraLayerTop2.set_text("Top2 Layer Name: ");
		label_extraLayerTop2.set_line_wrap();
		label_extraLayerTop2.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerTop2,0,4,2,1);
		label_extraLayerTop2.show();

		text_extraLayerTop2.set_max_length(100);
		text_extraLayerTop2.set_text("");
		text_extraLayerTop2.select_region(0, text_extraLayerTop2.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerTop2,2,4,1,1);	
		text_extraLayerTop2.show();

		label_extraLayerName.set_text("Current Layer Name: ");
		label_extraLayerName.set_line_wrap();
		label_extraLayerName.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerName,0,3,2,1);
		label_extraLayerName.show();

		text_extraLayerName.set_max_length(100);
		text_extraLayerName.set_text("");
		text_extraLayerName.select_region(0, text_extraLayerName.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerName,2,3,1,1);	
		text_extraLayerName.show();

		label_extraLayerPhase.set_text("phase: ");
		label_extraLayerPhase.set_line_wrap();
		label_extraLayerPhase.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerPhase,0,8,2,1);
		label_extraLayerPhase.show();

//		Gtk::RadioButton::Group group9 = rbutton_extraLayerTrain.get_group();
//		rbutton_extraLayerTest.set_group(group9);
//	 	rbutton_extraLayerTrain.set_active();
//		m_grid_extraLayerType.attach(rbutton_extraLayerTrain,2,8,1,1);
		rbutton_extraLayerTrain.show();
//		m_grid_extraLayerType.attach(rbutton_extraLayerTest,3,8,1,1);
		rbutton_extraLayerTest.show();

		label_extraLayerScale.set_text("scale: ");
		label_extraLayerScale.set_line_wrap();
		label_extraLayerScale.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerScale,0,9,2,1);
		label_extraLayerScale.show();

//		Gtk::RadioButton::Group group10 = rbutton_extraLayerScaleYes.get_group();
//		rbutton_extraLayerScaleNo.set_group(group10);
	 	rbutton_extraLayerScaleNo.set_active();
//		m_grid_extraLayerType.attach(rbutton_extraLayerScaleYes,2,9,1,1);
		rbutton_extraLayerScaleYes.show();
//		m_grid_extraLayerType.attach(rbutton_extraLayerScaleNo,3,9,1,1);
		rbutton_extraLayerScaleNo.show();

		text_extraLayerScale.set_max_length(100);
		text_extraLayerScale.set_text("");
		text_extraLayerScale.select_region(0, text_extraLayerScale.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerScale,4,9,1,1);	
		text_extraLayerScale.show();

		label_extraLayerNewHeight.set_text("new_height: ");
		label_extraLayerNewHeight.set_line_wrap();
		label_extraLayerNewHeight.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerNewHeight,0,10,2,1);
		label_extraLayerNewHeight.show();

//		Gtk::RadioButton::Group group11 = rbutton_extraLayerNewHeightYes.get_group();
//		rbutton_extraLayerNewHeightNo.set_group(group11);
	 	rbutton_extraLayerNewHeightNo.set_active();
//		m_grid_extraLayerType.attach(rbutton_extraLayerNewHeightYes,2,10,1,1);
		rbutton_extraLayerNewHeightYes.show();
//		m_grid_extraLayerType.attach(rbutton_extraLayerNewHeightNo,3,10,1,1);
		rbutton_extraLayerNewHeightNo.show();

		text_extraLayerNewHeight.set_max_length(100);
		text_extraLayerNewHeight.set_text("");
		text_extraLayerNewHeight.select_region(0, text_extraLayerNewHeight.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerNewHeight,4,10,1,1);	
		text_extraLayerNewHeight.show();
	
		label_extraLayerNewWidth.set_text("new_width: ");
		label_extraLayerNewWidth.set_line_wrap();
		label_extraLayerNewWidth.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerNewWidth,0,11,2,1);
		label_extraLayerNewWidth.show();

//		Gtk::RadioButton::Group group12 = rbutton_extraLayerNewWidthYes.get_group();
//		rbutton_extraLayerNewWidthNo.set_group(group12);
	 	rbutton_extraLayerNewWidthNo.set_active();
//		m_grid_extraLayerType.attach(rbutton_extraLayerNewWidthYes,2,11,1,1);
		rbutton_extraLayerNewWidthYes.show();
//		m_grid_extraLayerType.attach(rbutton_extraLayerNewWidthNo,3,11,1,1);
		rbutton_extraLayerNewWidthNo.show();

		text_extraLayerNewWidth.set_max_length(100);
		text_extraLayerNewWidth.set_text("");
		text_extraLayerNewWidth.select_region(0, text_extraLayerNewWidth.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerNewWidth,4,11,1,1);	
		text_extraLayerNewWidth.show();

		label_extraLayerCropSize.set_text("crop_size: ");
		label_extraLayerCropSize.set_line_wrap();
		label_extraLayerCropSize.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerCropSize,0,12,2,1);
		label_extraLayerCropSize.show();

//		Gtk::RadioButton::Group group13 = rbutton_extraLayerCropSizeYes.get_group();
//		rbutton_extraLayerCropSizeNo.set_group(group13);
	 	rbutton_extraLayerCropSizeNo.set_active();
//		m_grid_extraLayerType.attach(rbutton_extraLayerCropSizeYes,2,12,1,1);
		rbutton_extraLayerCropSizeYes.show();
//		m_grid_extraLayerType.attach(rbutton_extraLayerCropSizeNo,3,12,1,1);
		rbutton_extraLayerCropSizeNo.show();

		text_extraLayerCropSize.set_max_length(100);
		text_extraLayerCropSize.set_text("");
		text_extraLayerCropSize.select_region(0, text_extraLayerCropSize.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerCropSize,4,12,1,1);	
		text_extraLayerCropSize.show();

		label_extraLayerMeanFile.set_text("mean_file: ");
		label_extraLayerMeanFile.set_line_wrap();
		label_extraLayerMeanFile.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerMeanFile,0,13,2,1);
		label_extraLayerMeanFile.show();

//		Gtk::RadioButton::Group group14 = rbutton_extraLayerMeanFileYes.get_group();
//		rbutton_extraLayerMeanFileNo.set_group(group14);
	 	rbutton_extraLayerMeanFileNo.set_active();
//		m_grid_extraLayerType.attach(rbutton_extraLayerMeanFileYes,2,13,1,1);
		rbutton_extraLayerMeanFileYes.show();
//		m_grid_extraLayerType.attach(rbutton_extraLayerMeanFileNo,3,13,1,1);
		rbutton_extraLayerMeanFileNo.show();

		text_extraLayerMeanFile.set_max_length(100);
		text_extraLayerMeanFile.set_text("");
		text_extraLayerMeanFile.select_region(0, text_extraLayerMeanFile.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerMeanFile,4,13,1,1);	
		text_extraLayerMeanFile.show();

		label_extraLayerSource.set_text("source: ");
		label_extraLayerSource.set_line_wrap();
		label_extraLayerSource.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerSource,0,14,2,1);
		label_extraLayerSource.show();

		text_extraLayerSource.set_max_length(100);
		text_extraLayerSource.set_text("");
		text_extraLayerSource.select_region(0, text_extraLayerSource.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerSource,2,14,1,1);	
		text_extraLayerSource.show();

		label_extraLayerBatchSize.set_text("batch_size: ");
		label_extraLayerBatchSize.set_line_wrap();
		label_extraLayerBatchSize.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerBatchSize,0,15,2,1);
		label_extraLayerBatchSize.show();

		text_extraLayerBatchSize.set_max_length(100);
		text_extraLayerBatchSize.set_text("");
		text_extraLayerBatchSize.select_region(0, text_extraLayerBatchSize.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerBatchSize,2,15,1,1);	
		text_extraLayerBatchSize.show();

		button_setExtraParameters.show();
	}
	else if(data == "Data")
	{
		button_setExtraParameters.hide();
		label_extraLayerBottom1.hide();
		label_extraLayerTop1.hide();
		label_extraLayerTop2.hide();
		label_extraLayerName.hide();
		text_extraLayerBottom1.hide();
		text_extraLayerTop1.hide();
		text_extraLayerTop2.hide();
		text_extraLayerName.hide();
		text_extraLayerTopK.hide();
		label_extraLayerTopK.hide();
		label_extraLayerOutMaxVal.hide();
		rbutton_extraLayerOutMaxValTrue.hide();
		rbutton_extraLayerOutMaxValFalse.hide();
		label_extraLayerBottom2.hide();
		text_extraLayerBottom2.hide();
		label_extraLayerPhase.hide();
		rbutton_extraLayerTrain.hide();
		rbutton_extraLayerTest.hide();
		label_extraLayerScale.hide();
		label_extraLayerNewHeight.hide();
		label_extraLayerNewWidth.hide();
		label_extraLayerCropSize.hide();
		label_extraLayerMeanFile.hide();
		rbutton_extraLayerScaleYes.hide();
		rbutton_extraLayerScaleNo.hide();
		rbutton_extraLayerNewHeightYes.hide();
		rbutton_extraLayerNewHeightNo.hide();
		rbutton_extraLayerNewWidthYes.hide();
		rbutton_extraLayerNewWidthNo.hide();
		rbutton_extraLayerCropSizeYes.hide();
		rbutton_extraLayerCropSizeNo.hide();
		rbutton_extraLayerMeanFileYes.hide();
		rbutton_extraLayerMeanFileNo.hide();
		text_extraLayerScale.hide();
		text_extraLayerNewHeight.hide();
		text_extraLayerNewWidth.hide();
		text_extraLayerCropSize.hide();
		text_extraLayerMeanFile.hide();
		label_extraLayerSource.hide();
		label_extraLayerBatchSize.hide();
		text_extraLayerSource.hide();
		text_extraLayerBatchSize.hide();
		label_extraLayerBackend.hide();
		rbutton_extraLayerLMDB.hide();
		rbutton_extraLayerLEVELDB.hide();


		label_extraLayerTop1.set_text("Top1 Layer Name: ");
		label_extraLayerTop1.set_line_wrap();
		label_extraLayerTop1.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerTop1,0,2,2,1);
		label_extraLayerTop1.show();

		text_extraLayerTop1.set_max_length(100);
		text_extraLayerTop1.set_text("");
		text_extraLayerTop1.select_region(0, text_extraLayerTop1.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerTop1,2,2,1,1);	
		text_extraLayerTop1.show();

		label_extraLayerTop2.set_text("Top2 Layer Name: ");
		label_extraLayerTop2.set_line_wrap();
		label_extraLayerTop2.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerTop2,0,4,2,1);
		label_extraLayerTop2.show();

		text_extraLayerTop2.set_max_length(100);
		text_extraLayerTop2.set_text("");
		text_extraLayerTop2.select_region(0, text_extraLayerTop2.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerTop2,2,4,1,1);	
		text_extraLayerTop2.show();

		label_extraLayerName.set_text("Current Layer Name: ");
		label_extraLayerName.set_line_wrap();
		label_extraLayerName.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerName,0,3,2,1);
		label_extraLayerName.show();

		text_extraLayerName.set_max_length(100);
		text_extraLayerName.set_text("");
		text_extraLayerName.select_region(0, text_extraLayerName.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerName,2,3,1,1);	
		text_extraLayerName.show();

		label_extraLayerPhase.set_text("phase: ");
		label_extraLayerPhase.set_line_wrap();
		label_extraLayerPhase.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerPhase,0,8,2,1);
		label_extraLayerPhase.show();

//		Gtk::RadioButton::Group group9 = rbutton_extraLayerTrain.get_group();
//		rbutton_extraLayerTest.set_group(group9);
//	 	rbutton_extraLayerTrain.set_active();
//		m_grid_extraLayerType.attach(rbutton_extraLayerTrain,2,8,1,1);
		rbutton_extraLayerTrain.show();
//		m_grid_extraLayerType.attach(rbutton_extraLayerTest,3,8,1,1);
		rbutton_extraLayerTest.show();

		label_extraLayerScale.set_text("scale: ");
		label_extraLayerScale.set_line_wrap();
		label_extraLayerScale.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerScale,0,9,2,1);
		label_extraLayerScale.show();

//		Gtk::RadioButton::Group group10 = rbutton_extraLayerScaleYes.get_group();
//		rbutton_extraLayerScaleNo.set_group(group10);
	 	rbutton_extraLayerScaleNo.set_active();
//		m_grid_extraLayerType.attach(rbutton_extraLayerScaleYes,2,9,1,1);
		rbutton_extraLayerScaleYes.show();
//		m_grid_extraLayerType.attach(rbutton_extraLayerScaleNo,3,9,1,1);
		rbutton_extraLayerScaleNo.show();

		text_extraLayerScale.set_max_length(100);
		text_extraLayerScale.set_text("");
		text_extraLayerScale.select_region(0, text_extraLayerScale.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerScale,4,9,1,1);	
		text_extraLayerScale.show();

		label_extraLayerNewHeight.set_text("new_height: ");
		label_extraLayerNewHeight.set_line_wrap();
		label_extraLayerNewHeight.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerNewHeight,0,10,2,1);
		label_extraLayerNewHeight.show();

//		Gtk::RadioButton::Group group11 = rbutton_extraLayerNewHeightYes.get_group();
//		rbutton_extraLayerNewHeightNo.set_group(group11);
	 	rbutton_extraLayerNewHeightNo.set_active();
//		m_grid_extraLayerType.attach(rbutton_extraLayerNewHeightYes,2,10,1,1);
		rbutton_extraLayerNewHeightYes.show();
//		m_grid_extraLayerType.attach(rbutton_extraLayerNewHeightNo,3,10,1,1);
		rbutton_extraLayerNewHeightNo.show();

		text_extraLayerNewHeight.set_max_length(100);
		text_extraLayerNewHeight.set_text("");
		text_extraLayerNewHeight.select_region(0, text_extraLayerNewHeight.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerNewHeight,4,10,1,1);	
		text_extraLayerNewHeight.show();
	
		label_extraLayerNewWidth.set_text("new_width: ");
		label_extraLayerNewWidth.set_line_wrap();
		label_extraLayerNewWidth.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerNewWidth,0,11,2,1);
		label_extraLayerNewWidth.show();

//		Gtk::RadioButton::Group group12 = rbutton_extraLayerNewWidthYes.get_group();
//		rbutton_extraLayerNewWidthNo.set_group(group12);
	 	rbutton_extraLayerNewWidthNo.set_active();
//		m_grid_extraLayerType.attach(rbutton_extraLayerNewWidthYes,2,11,1,1);
		rbutton_extraLayerNewWidthYes.show();
//		m_grid_extraLayerType.attach(rbutton_extraLayerNewWidthNo,3,11,1,1);
		rbutton_extraLayerNewWidthNo.show();

		text_extraLayerNewWidth.set_max_length(100);
		text_extraLayerNewWidth.set_text("");
		text_extraLayerNewWidth.select_region(0, text_extraLayerNewWidth.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerNewWidth,4,11,1,1);	
		text_extraLayerNewWidth.show();

		label_extraLayerCropSize.set_text("crop_size: ");
		label_extraLayerCropSize.set_line_wrap();
		label_extraLayerCropSize.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerCropSize,0,12,2,1);
		label_extraLayerCropSize.show();

//		Gtk::RadioButton::Group group13 = rbutton_extraLayerCropSizeYes.get_group();
//		rbutton_extraLayerCropSizeNo.set_group(group13);
	 	rbutton_extraLayerCropSizeNo.set_active();
//		m_grid_extraLayerType.attach(rbutton_extraLayerCropSizeYes,2,12,1,1);
		rbutton_extraLayerCropSizeYes.show();
//		m_grid_extraLayerType.attach(rbutton_extraLayerCropSizeNo,3,12,1,1);
		rbutton_extraLayerCropSizeNo.show();

		text_extraLayerCropSize.set_max_length(100);
		text_extraLayerCropSize.set_text("");
		text_extraLayerCropSize.select_region(0, text_extraLayerCropSize.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerCropSize,4,12,1,1);	
		text_extraLayerCropSize.show();

		label_extraLayerMeanFile.set_text("mean_file: ");
		label_extraLayerMeanFile.set_line_wrap();
		label_extraLayerMeanFile.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerMeanFile,0,13,2,1);
		label_extraLayerMeanFile.show();

//		Gtk::RadioButton::Group group14 = rbutton_extraLayerMeanFileYes.get_group();
//		rbutton_extraLayerMeanFileNo.set_group(group14);
	 	rbutton_extraLayerMeanFileNo.set_active();
//		m_grid_extraLayerType.attach(rbutton_extraLayerMeanFileYes,2,13,1,1);
		rbutton_extraLayerMeanFileYes.show();
//		m_grid_extraLayerType.attach(rbutton_extraLayerMeanFileNo,3,13,1,1);
		rbutton_extraLayerMeanFileNo.show();

		text_extraLayerMeanFile.set_max_length(100);
		text_extraLayerMeanFile.set_text("");
		text_extraLayerMeanFile.select_region(0, text_extraLayerMeanFile.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerMeanFile,4,13,1,1);	
		text_extraLayerMeanFile.show();

		label_extraLayerSource.set_text("source: ");
		label_extraLayerSource.set_line_wrap();
		label_extraLayerSource.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerSource,0,14,2,1);
		label_extraLayerSource.show();

		text_extraLayerSource.set_max_length(100);
		text_extraLayerSource.set_text("");
		text_extraLayerSource.select_region(0, text_extraLayerSource.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerSource,2,14,1,1);	
		text_extraLayerSource.show();

		label_extraLayerBatchSize.set_text("batch_size: ");
		label_extraLayerBatchSize.set_line_wrap();
		label_extraLayerBatchSize.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerBatchSize,0,15,2,1);
		label_extraLayerBatchSize.show();

		text_extraLayerBatchSize.set_max_length(100);
		text_extraLayerBatchSize.set_text("");
		text_extraLayerBatchSize.select_region(0, text_extraLayerBatchSize.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerBatchSize,2,15,1,1);	
		text_extraLayerBatchSize.show();

		label_extraLayerBackend.set_text("backend: ");
		label_extraLayerBackend.set_line_wrap();
		label_extraLayerBackend.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerBackend,0,16,2,1);
		label_extraLayerBackend.show();
	
//		Gtk::RadioButton::Group group15 = rbutton_extraLayerLMDB.get_group();
//		rbutton_extraLayerLEVELDB.set_group(group15);
	 	rbutton_extraLayerLMDB.set_active();
//		m_grid_extraLayerType.attach(rbutton_extraLayerLMDB,2,16,1,1);
		rbutton_extraLayerLMDB.show();
//		m_grid_extraLayerType.attach(rbutton_extraLayerLEVELDB,3,16,1,1);
		rbutton_extraLayerLEVELDB.show();

		button_setExtraParameters.show();
	}
	else if(data == "HDF5Data")
	{
		button_setExtraParameters.hide();
		label_extraLayerBottom1.hide();
		label_extraLayerTop1.hide();
		label_extraLayerTop2.hide();
		label_extraLayerName.hide();
		text_extraLayerBottom1.hide();
		text_extraLayerTop1.hide();
		text_extraLayerTop2.hide();
		text_extraLayerName.hide();
		text_extraLayerTopK.hide();
		label_extraLayerTopK.hide();
		label_extraLayerOutMaxVal.hide();
		rbutton_extraLayerOutMaxValTrue.hide();
		rbutton_extraLayerOutMaxValFalse.hide();
		label_extraLayerBottom2.hide();
		text_extraLayerBottom2.hide();
		label_extraLayerPhase.hide();
		rbutton_extraLayerTrain.hide();
		rbutton_extraLayerTest.hide();
		label_extraLayerScale.hide();
		label_extraLayerNewHeight.hide();
		label_extraLayerNewWidth.hide();
		label_extraLayerCropSize.hide();
		label_extraLayerMeanFile.hide();
		rbutton_extraLayerScaleYes.hide();
		rbutton_extraLayerScaleNo.hide();
		rbutton_extraLayerNewHeightYes.hide();
		rbutton_extraLayerNewHeightNo.hide();
		rbutton_extraLayerNewWidthYes.hide();
		rbutton_extraLayerNewWidthNo.hide();
		rbutton_extraLayerCropSizeYes.hide();
		rbutton_extraLayerCropSizeNo.hide();
		rbutton_extraLayerMeanFileYes.hide();
		rbutton_extraLayerMeanFileNo.hide();
		text_extraLayerScale.hide();
		text_extraLayerNewHeight.hide();
		text_extraLayerNewWidth.hide();
		text_extraLayerCropSize.hide();
		text_extraLayerMeanFile.hide();
		label_extraLayerSource.hide();
		label_extraLayerBatchSize.hide();
		text_extraLayerSource.hide();
		text_extraLayerBatchSize.hide();
		label_extraLayerBackend.hide();
		rbutton_extraLayerLMDB.hide();
		rbutton_extraLayerLEVELDB.hide();


		label_extraLayerTop1.set_text("Top1 Layer Name: ");
		label_extraLayerTop1.set_line_wrap();
		label_extraLayerTop1.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerTop1,0,2,2,1);
		label_extraLayerTop1.show();

		text_extraLayerTop1.set_max_length(100);
		text_extraLayerTop1.set_text("");
		text_extraLayerTop1.select_region(0, text_extraLayerTop1.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerTop1,2,2,1,1);	
		text_extraLayerTop1.show();

		label_extraLayerTop2.set_text("Top2 Layer Name: ");
		label_extraLayerTop2.set_line_wrap();
		label_extraLayerTop2.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerTop2,0,4,2,1);
		label_extraLayerTop2.show();

		text_extraLayerTop2.set_max_length(100);
		text_extraLayerTop2.set_text("");
		text_extraLayerTop2.select_region(0, text_extraLayerTop2.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerTop2,2,4,1,1);	
		text_extraLayerTop2.show();

		label_extraLayerName.set_text("Current Layer Name: ");
		label_extraLayerName.set_line_wrap();
		label_extraLayerName.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerName,0,3,2,1);
		label_extraLayerName.show();

		text_extraLayerName.set_max_length(100);
		text_extraLayerName.set_text("");
		text_extraLayerName.select_region(0, text_extraLayerName.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerName,2,3,1,1);	
		text_extraLayerName.show();

		label_extraLayerPhase.set_text("phase: ");
		label_extraLayerPhase.set_line_wrap();
		label_extraLayerPhase.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerPhase,0,8,2,1);
		label_extraLayerPhase.show();

//		Gtk::RadioButton::Group group9 = rbutton_extraLayerTrain.get_group();
//		rbutton_extraLayerTest.set_group(group9);
//	 	rbutton_extraLayerTrain.set_active();
//		m_grid_extraLayerType.attach(rbutton_extraLayerTrain,2,8,1,1);
		rbutton_extraLayerTrain.show();
//		m_grid_extraLayerType.attach(rbutton_extraLayerTest,3,8,1,1);
		rbutton_extraLayerTest.show();

		label_extraLayerSource.set_text("source: ");
		label_extraLayerSource.set_line_wrap();
		label_extraLayerSource.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerSource,0,14,2,1);
		label_extraLayerSource.show();

		text_extraLayerSource.set_max_length(100);
		text_extraLayerSource.set_text("");
		text_extraLayerSource.select_region(0, text_extraLayerSource.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerSource,2,14,1,1);	
		text_extraLayerSource.show();

		label_extraLayerBatchSize.set_text("batch_size: ");
		label_extraLayerBatchSize.set_line_wrap();
		label_extraLayerBatchSize.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_extraLayerType.attach(label_extraLayerBatchSize,0,15,2,1);
		label_extraLayerBatchSize.show();

		text_extraLayerBatchSize.set_max_length(100);
		text_extraLayerBatchSize.set_text("");
		text_extraLayerBatchSize.select_region(0, text_extraLayerBatchSize.get_text_length());
//		m_grid_extraLayerType.attach(text_extraLayerBatchSize,2,15,1,1);	
		text_extraLayerBatchSize.show();

	

		button_setExtraParameters.show();
	}
	else
	{
		button_setExtraParameters.hide();
		label_extraLayerBottom1.hide();
		label_extraLayerTop1.hide();
		label_extraLayerTop2.hide();
		label_extraLayerName.hide();
		text_extraLayerBottom1.hide();
		text_extraLayerTop1.hide();
		text_extraLayerTop2.hide();
		text_extraLayerName.hide();
		text_extraLayerTopK.hide();
		label_extraLayerTopK.hide();
		label_extraLayerOutMaxVal.hide();
		rbutton_extraLayerOutMaxValTrue.hide();
		rbutton_extraLayerOutMaxValFalse.hide();
		label_extraLayerBottom2.hide();
		text_extraLayerBottom2.hide();
		label_extraLayerPhase.hide();
		rbutton_extraLayerTrain.hide();
		rbutton_extraLayerTest.hide();
		label_extraLayerScale.hide();
		label_extraLayerNewHeight.hide();
		label_extraLayerNewWidth.hide();
		label_extraLayerCropSize.hide();
		label_extraLayerMeanFile.hide();
		rbutton_extraLayerScaleYes.hide();
		rbutton_extraLayerScaleNo.hide();
		rbutton_extraLayerNewHeightYes.hide();
		rbutton_extraLayerNewHeightNo.hide();
		rbutton_extraLayerNewWidthYes.hide();
		rbutton_extraLayerNewWidthNo.hide();
		rbutton_extraLayerCropSizeYes.hide();
		rbutton_extraLayerCropSizeNo.hide();
		rbutton_extraLayerMeanFileYes.hide();
		rbutton_extraLayerMeanFileNo.hide();
		text_extraLayerScale.hide();
		text_extraLayerNewHeight.hide();
		text_extraLayerNewWidth.hide();
		text_extraLayerCropSize.hide();
		text_extraLayerMeanFile.hide();
		label_extraLayerSource.hide();
		label_extraLayerBatchSize.hide();
		text_extraLayerSource.hide();
		text_extraLayerBatchSize.hide();
		label_extraLayerBackend.hide();
		rbutton_extraLayerLMDB.hide();
		rbutton_extraLayerLEVELDB.hide();
	}

	

	m_sw_extraLayerType.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
	m_grid_extraLayerType.show();
//	show_all_children();
	m_sw_extraLayerType.show();
}
