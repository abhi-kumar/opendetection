#include "network.h"

void NetworkCreator::showWindow_criticalLayerType(Glib::ustring data)
{
	
	remove();
	set_title("Critical Layer");
	set_border_width(10);
	add(m_sw_criticalLayerType);
	m_grid_criticalLayerType.set_column_spacing (10);
	m_grid_criticalLayerType.set_row_spacing (50);

	//level 0
	if(data == "")
		title_criticalLayerType.set_text("Set the Properties of Critical Layer type: Accuracy");
	else
		title_criticalLayerType.set_text("Set the Properties of Critical Layer type: " + data);
	title_criticalLayerType.set_line_wrap();
	title_criticalLayerType.set_justify(Gtk::JUSTIFY_FILL);
//	m_grid_criticalLayerType.attach(title_criticalLayerType,0,0,2,1);
	title_criticalLayerType.show();

	button_setCriticalParameters.show();
	button_addMoreLayer2.show();

	if(data == "" or data == "Accuracy" or data == "Softmax")
	{
		label_criticalLayerBottom1.hide();
		text_criticalLayerBottom1.hide();
		label_criticalLayerBottom2.hide();
		text_criticalLayerBottom2.hide();
		label_criticalLayerTop.hide();
		text_criticalLayerTop.hide();
		label_criticalLayerName.hide();
		text_criticalLayerName.hide();	
		label_criticalLayerFilterLr.hide();
		text_criticalLayerFilterLr.hide();
		label_criticalLayerFilterDm.hide();
		text_criticalLayerFilterDm.hide();
		label_criticalLayerBiasLr.hide();
		text_criticalLayerBiasLr.hide();
		label_criticalLayerBiasDm.hide();
		text_criticalLayerBiasDm.hide();
		label_criticalLayerNumOutput.hide();
		text_criticalLayerNumOutput.hide();		
		label_criticalLayerKernelW.hide();
		text_criticalLayerKernelW.hide();
		label_criticalLayerKernelH.hide();
		text_criticalLayerKernelH.hide();	
		label_criticalLayerStrideW.hide();
		text_criticalLayerStrideW.hide();
		label_criticalLayerStrideH.hide();
		text_criticalLayerStrideH.hide();
		label_criticalLayerPadW.hide();
		text_criticalLayerPadW.hide();
		label_criticalLayerPadH.hide();
		text_criticalLayerPadH.hide();
		label_criticalLayerWeightFiller.hide();
		rbutton_criticalLayerWeightFillerConstant.hide();
		rbutton_criticalLayerWeightFillerUniform.hide();
		rbutton_criticalLayerWeightGaussian.hide();
		rbutton_criticalLayerWeightFillerPositiveUnitBall.hide();
		rbutton_criticalLayerWeightFillerXavier.hide();
		rbutton_criticalLayerWeightFillerMSRA.hide();
		rbutton_criticalLayerWeightFillerBilinear.hide();
		label_criticalLayerWeightFillerConstantValue.hide();
		text_criticalLayerWeightFillerConstantValue.hide();
		label_criticalLayerWeightFillerUniformMin.hide();
		label_criticalLayerWeightFillerUniformMax.hide();
		text_criticalLayerWeightFillerUniformMin.hide();
		text_criticalLayerWeightFillerUniformMax.hide();
		label_criticalLayerWeightFillerGaussianMean.hide();
		text_criticalLayerWeightFillerGaussianMean.hide();
		label_criticalLayerWeightFillerGaussianStd.hide();
		text_criticalLayerWeightFillerGaussianStd.hide();
		label_criticalLayerWeightFillerXavierVariance.hide();
		rbutton_criticalLayerWeightFillerXavierIn.hide();
		rbutton_criticalLayerWeightFillerXavierOut.hide();
		rbutton_criticalLayerWeightFillerXavierAvg.hide();
		label_criticalLayerWeightFillerMSRAVariance.hide();
		rbutton_criticalLayerWeightFillerMSRAIn.hide();
		rbutton_criticalLayerWeightFillerMSRAOut.hide();
		rbutton_criticalLayerWeightFillerMSRAAvg.hide();
		label_criticalLayerDropoutRatio.hide();
		text_criticalLayerDropoutRatio.hide();
		label_criticalLayerPool.hide();
		label_criticalLayerBias.hide();
		text_criticalLayerBias.hide();
		rbutton_criticalLayerPoolMax.hide();
		rbutton_criticalLayerPoolAve.hide();


		label_criticalLayerBottom1.set_text("Bottom1 Layer Name: ");
		label_criticalLayerBottom1.set_line_wrap();
		label_criticalLayerBottom1.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerBottom1,0,1,2,1);
		label_criticalLayerBottom1.show();

		text_criticalLayerBottom1.set_max_length(100);
		text_criticalLayerBottom1.set_text("");
		text_criticalLayerBottom1.select_region(0, text_criticalLayerBottom1.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerBottom1,2,1,1,1);	
		text_criticalLayerBottom1.show();

		label_criticalLayerBottom2.set_text("Bottom2 Layer Name: ");
		label_criticalLayerBottom2.set_line_wrap();
		label_criticalLayerBottom2.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerBottom2,0,1,2,1);
		label_criticalLayerBottom2.show();

		text_criticalLayerBottom2.set_max_length(100);
		text_criticalLayerBottom2.set_text("");
		text_criticalLayerBottom2.select_region(0, text_criticalLayerBottom2.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerBottom2,2,1,1,1);	
		text_criticalLayerBottom2.show();

		label_criticalLayerTop.set_text("Top Layer Name: ");
		label_criticalLayerTop.set_line_wrap();
		label_criticalLayerTop.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerTop,0,3,2,1);
		label_criticalLayerTop.show();

		text_criticalLayerTop.set_max_length(100);
		text_criticalLayerTop.set_text("");
		text_criticalLayerTop.select_region(0, text_criticalLayerTop.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerTop,2,3,1,1);	
		text_criticalLayerTop.show();

		label_criticalLayerName.set_text("Current Layer Name: ");
		label_criticalLayerName.set_line_wrap();
		label_criticalLayerName.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerName,0,4,2,1);
		label_criticalLayerName.show();

		text_criticalLayerName.set_max_length(100);
		text_criticalLayerName.set_text("");
		text_criticalLayerName.select_region(0, text_criticalLayerName.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerName,2,4,1,1);	
		text_criticalLayerName.show();
	}
	else if( data == "Concat")
	{
		label_criticalLayerBottom1.hide();
		text_criticalLayerBottom1.hide();
		label_criticalLayerBottom2.hide();
		text_criticalLayerBottom2.hide();
		label_criticalLayerTop.hide();
		text_criticalLayerTop.hide();
		label_criticalLayerName.hide();
		text_criticalLayerName.hide();	
		label_criticalLayerFilterLr.hide();
		text_criticalLayerFilterLr.hide();
		label_criticalLayerFilterDm.hide();
		text_criticalLayerFilterDm.hide();
		label_criticalLayerBiasLr.hide();
		text_criticalLayerBiasLr.hide();
		label_criticalLayerBiasDm.hide();
		text_criticalLayerBiasDm.hide();
		label_criticalLayerNumOutput.hide();
		text_criticalLayerNumOutput.hide();		
		label_criticalLayerKernelW.hide();
		text_criticalLayerKernelW.hide();
		label_criticalLayerKernelH.hide();
		text_criticalLayerKernelH.hide();	
		label_criticalLayerStrideW.hide();
		text_criticalLayerStrideW.hide();
		label_criticalLayerStrideH.hide();
		text_criticalLayerStrideH.hide();
		label_criticalLayerPadW.hide();
		text_criticalLayerPadW.hide();
		label_criticalLayerPadH.hide();
		text_criticalLayerPadH.hide();
		label_criticalLayerWeightFiller.hide();
		rbutton_criticalLayerWeightFillerConstant.hide();
		rbutton_criticalLayerWeightFillerUniform.hide();
		rbutton_criticalLayerWeightGaussian.hide();
		rbutton_criticalLayerWeightFillerPositiveUnitBall.hide();
		rbutton_criticalLayerWeightFillerXavier.hide();
		rbutton_criticalLayerWeightFillerMSRA.hide();
		rbutton_criticalLayerWeightFillerBilinear.hide();
		label_criticalLayerWeightFillerConstantValue.hide();
		text_criticalLayerWeightFillerConstantValue.hide();
		label_criticalLayerWeightFillerUniformMin.hide();
		label_criticalLayerWeightFillerUniformMax.hide();
		text_criticalLayerWeightFillerUniformMin.hide();
		text_criticalLayerWeightFillerUniformMax.hide();
		label_criticalLayerWeightFillerGaussianMean.hide();
		text_criticalLayerWeightFillerGaussianMean.hide();
		label_criticalLayerWeightFillerGaussianStd.hide();
		text_criticalLayerWeightFillerGaussianStd.hide();
		label_criticalLayerWeightFillerXavierVariance.hide();
		rbutton_criticalLayerWeightFillerXavierIn.hide();
		rbutton_criticalLayerWeightFillerXavierOut.hide();
		rbutton_criticalLayerWeightFillerXavierAvg.hide();
		label_criticalLayerWeightFillerMSRAVariance.hide();
		rbutton_criticalLayerWeightFillerMSRAIn.hide();
		rbutton_criticalLayerWeightFillerMSRAOut.hide();
		rbutton_criticalLayerWeightFillerMSRAAvg.hide();\
		label_criticalLayerDropoutRatio.hide();
		text_criticalLayerDropoutRatio.hide();
		label_criticalLayerPool.hide();
		label_criticalLayerBias.hide();
		text_criticalLayerBias.hide();
		rbutton_criticalLayerPoolMax.hide();
		rbutton_criticalLayerPoolAve.hide();


		label_criticalLayerBottom1.set_text("Facility will be added soon");
		label_criticalLayerBottom1.set_line_wrap();
		label_criticalLayerBottom1.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerBottom1,0,1,2,1);
		label_criticalLayerBottom1.show();
	}
	else if( data == "Convolution" or data == "Deconvolution")
	{
		label_criticalLayerBottom1.hide();
		text_criticalLayerBottom1.hide();
		label_criticalLayerBottom2.hide();
		text_criticalLayerBottom2.hide();
		label_criticalLayerTop.hide();
		text_criticalLayerTop.hide();
		label_criticalLayerName.hide();
		text_criticalLayerName.hide();	
		label_criticalLayerFilterLr.hide();
		text_criticalLayerFilterLr.hide();
		label_criticalLayerFilterDm.hide();
		text_criticalLayerFilterDm.hide();
		label_criticalLayerBiasLr.hide();
		text_criticalLayerBiasLr.hide();
		label_criticalLayerBiasDm.hide();
		text_criticalLayerBiasDm.hide();
		label_criticalLayerNumOutput.hide();
		text_criticalLayerNumOutput.hide();		
		label_criticalLayerKernelW.hide();
		text_criticalLayerKernelW.hide();
		label_criticalLayerKernelH.hide();
		text_criticalLayerKernelH.hide();	
		label_criticalLayerStrideW.hide();
		text_criticalLayerStrideW.hide();
		label_criticalLayerStrideH.hide();
		text_criticalLayerStrideH.hide();
		label_criticalLayerPadW.hide();
		text_criticalLayerPadW.hide();
		label_criticalLayerPadH.hide();
		text_criticalLayerPadH.hide();
		label_criticalLayerWeightFiller.hide();
		rbutton_criticalLayerWeightFillerConstant.hide();
		rbutton_criticalLayerWeightFillerUniform.hide();
		rbutton_criticalLayerWeightGaussian.hide();
		rbutton_criticalLayerWeightFillerPositiveUnitBall.hide();
		rbutton_criticalLayerWeightFillerXavier.hide();
		rbutton_criticalLayerWeightFillerMSRA.hide();
		rbutton_criticalLayerWeightFillerBilinear.hide();
		label_criticalLayerWeightFillerConstantValue.hide();
		text_criticalLayerWeightFillerConstantValue.hide();
		label_criticalLayerWeightFillerUniformMin.hide();
		label_criticalLayerWeightFillerUniformMax.hide();
		text_criticalLayerWeightFillerUniformMin.hide();
		text_criticalLayerWeightFillerUniformMax.hide();
		label_criticalLayerWeightFillerGaussianMean.hide();
		text_criticalLayerWeightFillerGaussianMean.hide();
		label_criticalLayerWeightFillerGaussianStd.hide();
		text_criticalLayerWeightFillerGaussianStd.hide();
		label_criticalLayerWeightFillerXavierVariance.hide();
		rbutton_criticalLayerWeightFillerXavierIn.hide();
		rbutton_criticalLayerWeightFillerXavierOut.hide();
		rbutton_criticalLayerWeightFillerXavierAvg.hide();
		label_criticalLayerWeightFillerMSRAVariance.hide();
		rbutton_criticalLayerWeightFillerMSRAIn.hide();
		rbutton_criticalLayerWeightFillerMSRAOut.hide();
		rbutton_criticalLayerWeightFillerMSRAAvg.hide();
		label_criticalLayerDropoutRatio.hide();
		text_criticalLayerDropoutRatio.hide();
		label_criticalLayerPool.hide();
		label_criticalLayerBias.hide();
		text_criticalLayerBias.hide();
		rbutton_criticalLayerPoolMax.hide();
		rbutton_criticalLayerPoolAve.hide();

		label_criticalLayerBottom1.set_text("Bottom1 Layer Name: ");
		label_criticalLayerBottom1.set_line_wrap();
		label_criticalLayerBottom1.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerBottom1,0,1,2,1);
		label_criticalLayerBottom1.show();

		text_criticalLayerBottom1.set_max_length(100);
		text_criticalLayerBottom1.set_text("");
		text_criticalLayerBottom1.select_region(0, text_criticalLayerBottom1.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerBottom1,2,1,1,1);	
		text_criticalLayerBottom1.show();

		label_criticalLayerTop.set_text("Top Layer Name: ");
		label_criticalLayerTop.set_line_wrap();
		label_criticalLayerTop.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerTop,0,3,2,1);
		label_criticalLayerTop.show();

		text_criticalLayerTop.set_max_length(100);
		text_criticalLayerTop.set_text("");
		text_criticalLayerTop.select_region(0, text_criticalLayerTop.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerTop,2,3,1,1);	
		text_criticalLayerTop.show();

		label_criticalLayerName.set_text("Current Layer Name: ");
		label_criticalLayerName.set_line_wrap();
		label_criticalLayerName.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerName,0,4,2,1);
		label_criticalLayerName.show();

		text_criticalLayerName.set_max_length(100);
		text_criticalLayerName.set_text("");
		text_criticalLayerName.select_region(0, text_criticalLayerName.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerName,2,4,1,1);	
		text_criticalLayerName.show();

		label_criticalLayerFilterLr.set_text("Set filter lr_mult:\n(Leave unchanged if not needed) ");
		label_criticalLayerFilterLr.set_line_wrap();
		label_criticalLayerFilterLr.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerFilterLr,0,5,2,1);
		label_criticalLayerFilterLr.show();

		text_criticalLayerFilterLr.set_max_length(100);
		text_criticalLayerFilterLr.set_text("1");
		text_criticalLayerFilterLr.select_region(0, text_criticalLayerFilterLr.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerFilterLr,2,5,1,1);	
		text_criticalLayerFilterLr.show();

		label_criticalLayerFilterDm.set_text("Set filter decay_mult:\n(Leave unchanged if not needed) ");
		label_criticalLayerFilterDm.set_line_wrap();
		label_criticalLayerFilterDm.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerFilterDm,0,6,2,1);
		label_criticalLayerFilterDm.show();

		text_criticalLayerFilterDm.set_max_length(100);
		text_criticalLayerFilterDm.set_text("1");
		text_criticalLayerFilterDm.select_region(0, text_criticalLayerFilterDm.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerFilterDm,2,6,1,1);	
		text_criticalLayerFilterDm.show();

		label_criticalLayerBiasLr.set_text("Set bias lr_mult:\n(Leave unchanged if not needed) ");
		label_criticalLayerBiasLr.set_line_wrap();
		label_criticalLayerBiasLr.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerBiasLr,0,7,2,1);
		label_criticalLayerBiasLr.show();

		text_criticalLayerBiasLr.set_max_length(100);
		text_criticalLayerBiasLr.set_text("2");
		text_criticalLayerBiasLr.select_region(0, text_criticalLayerBiasLr.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerBiasLr,2,7,1,1);	
		text_criticalLayerBiasLr.show();

		label_criticalLayerBiasDm.set_text("Set bias decay_mult:\n(Leave unchanged if not needed) ");
		label_criticalLayerBiasDm.set_line_wrap();
		label_criticalLayerBiasDm.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerBiasDm,0,8,2,1);
		label_criticalLayerBiasDm.show();

		text_criticalLayerBiasDm.set_max_length(100);
		text_criticalLayerBiasDm.set_text("0");
		text_criticalLayerBiasDm.select_region(0, text_criticalLayerBiasDm.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerBiasDm,2,8,1,1);	
		text_criticalLayerBiasDm.show();

		label_criticalLayerNumOutput.set_text("Set param num_output: ");
		label_criticalLayerNumOutput.set_line_wrap();
		label_criticalLayerNumOutput.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerNumOutput,0,9,2,1);
		label_criticalLayerNumOutput.show();

		text_criticalLayerNumOutput.set_max_length(100);
		text_criticalLayerNumOutput.set_text("64");
		text_criticalLayerNumOutput.select_region(0, text_criticalLayerNumOutput.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerNumOutput,2,9,1,1);	
		text_criticalLayerNumOutput.show();

		label_criticalLayerKernelW.set_text("Set param kernel_w: ");
		label_criticalLayerKernelW.set_line_wrap();
		label_criticalLayerKernelW.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerKernelW,0,10,2,1);
		label_criticalLayerKernelW.show();

		text_criticalLayerKernelW.set_max_length(100);
		text_criticalLayerKernelW.set_text("3");
		text_criticalLayerKernelW.select_region(0, text_criticalLayerKernelW.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerKernelW,2,10,1,1);	
		text_criticalLayerKernelW.show();

		label_criticalLayerKernelH.set_text("Set param kernel_h: ");
		label_criticalLayerKernelH.set_line_wrap();
		label_criticalLayerKernelH.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerKernelH,0,11,2,1);
		label_criticalLayerKernelH.show();

		text_criticalLayerKernelH.set_max_length(100);
		text_criticalLayerKernelH.set_text("3");
		text_criticalLayerKernelH.select_region(0, text_criticalLayerKernelH.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerKernelH,2,11,1,1);	
		text_criticalLayerKernelH.show();

		label_criticalLayerStrideW.set_text("Set param stride_w: ");
		label_criticalLayerStrideW.set_line_wrap();
		label_criticalLayerStrideW.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerStrideW,0,12,2,1);
		label_criticalLayerStrideW.show();

		text_criticalLayerStrideW.set_max_length(100);
		text_criticalLayerStrideW.set_text("1");
		text_criticalLayerStrideW.select_region(0, text_criticalLayerStrideW.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerStrideW,2,12,1,1);	
		text_criticalLayerStrideW.show();

		label_criticalLayerStrideH.set_text("Set param stride_h: ");
		label_criticalLayerStrideH.set_line_wrap();
		label_criticalLayerStrideH.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerStrideH,0,13,2,1);
		label_criticalLayerStrideH.show();

		text_criticalLayerStrideH.set_max_length(100);
		text_criticalLayerStrideH.set_text("1");
		text_criticalLayerStrideH.select_region(0, text_criticalLayerStrideH.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerStrideH,2,13,1,1);	
		text_criticalLayerStrideH.show();

		label_criticalLayerPadW.set_text("Set param pad_w: ");
		label_criticalLayerPadW.set_line_wrap();
		label_criticalLayerPadW.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerPadW,0,14,2,1);
		label_criticalLayerPadW.show();

		text_criticalLayerPadW.set_max_length(100);
		text_criticalLayerPadW.set_text("1");
		text_criticalLayerPadW.select_region(0, text_criticalLayerPadW.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerPadW,2,14,1,1);	
		text_criticalLayerPadW.show();

		label_criticalLayerPadH.set_text("Set param pad_h: ");
		label_criticalLayerPadH.set_line_wrap();
		label_criticalLayerPadH.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerPadH,0,14,2,1);
		label_criticalLayerPadH.show();

		text_criticalLayerPadH.set_max_length(100);
		text_criticalLayerPadH.set_text("1");
		text_criticalLayerPadH.select_region(0, text_criticalLayerPadH.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerPadH,2,14,1,1);	
		text_criticalLayerPadH.show();

		label_criticalLayerWeightFiller.set_text("Set Weight Filler : ");
		label_criticalLayerWeightFiller.set_line_wrap();
		label_criticalLayerWeightFiller.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerWeightFiller,0,16,2,1);
		label_criticalLayerWeightFiller.show();

//		Gtk::RadioButton::Group group1 = rbutton_criticalLayerWeightFillerConstant.get_group();
//	 	rbutton_criticalLayerWeightFillerUniform.set_group(group1);
//	 	rbutton_criticalLayerWeightGaussian.set_group(group1);
//	 	rbutton_criticalLayerWeightFillerPositiveUnitBall.set_group(group1);
//	 	rbutton_criticalLayerWeightFillerXavier.set_group(group1);
//	 	rbutton_criticalLayerWeightFillerMSRA.set_group(group1);
//	 	rbutton_criticalLayerWeightFillerBilinear.set_group(group1);
//		rbutton_criticalLayerWeightFillerConstant.set_active();
//		m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerConstant,2,17,1,1);
		rbutton_criticalLayerWeightFillerConstant.show();
//		m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerUniform,2,18,1,1);
		rbutton_criticalLayerWeightFillerUniform.show();
//		m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightGaussian,2,19,1,1);
		rbutton_criticalLayerWeightGaussian.show();
//		m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerPositiveUnitBall,2,20,1,1);
		rbutton_criticalLayerWeightFillerPositiveUnitBall.show();
//		m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerXavier,2,21,1,1);
		rbutton_criticalLayerWeightFillerXavier.show();
//		m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerMSRA,2,22,1,1);
		rbutton_criticalLayerWeightFillerMSRA.show();
//		m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerBilinear,2,23,1,1);
		rbutton_criticalLayerWeightFillerBilinear.show();

		label_criticalLayerWeightFillerConstantValue.set_text("value: ");
		label_criticalLayerWeightFillerConstantValue.set_line_wrap();
		label_criticalLayerWeightFillerConstantValue.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerWeightFillerConstantValue,4,17,1,1);
		label_criticalLayerWeightFillerConstantValue.show();

		text_criticalLayerWeightFillerConstantValue.set_max_length(100);
		text_criticalLayerWeightFillerConstantValue.set_text("0.5");
		text_criticalLayerWeightFillerConstantValue.select_region(0, text_criticalLayerWeightFillerConstantValue.get_text_length());
//		m_grid_criticalLayerWeightFillerConstantValue.attach(text_criticalLayerWeightFillerConstantValue,5,15,1,1);	
		text_criticalLayerWeightFillerConstantValue.show();

		label_criticalLayerWeightFillerUniformMin.set_text("min: ");
		label_criticalLayerWeightFillerUniformMin.set_line_wrap();
		label_criticalLayerWeightFillerUniformMin.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerWeightFillerUniformMin,4,18,1,1);
		label_criticalLayerWeightFillerUniformMin.show();

		text_criticalLayerWeightFillerUniformMin.set_max_length(100);
		text_criticalLayerWeightFillerUniformMin.set_text("0");
		text_criticalLayerWeightFillerUniformMin.select_region(0, text_criticalLayerWeightFillerUniformMin.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerWeightFillerUniformMin,5,18,1,1);	
		text_criticalLayerWeightFillerUniformMin.show();

		label_criticalLayerWeightFillerUniformMax.set_text("max: ");
		label_criticalLayerWeightFillerUniformMax.set_line_wrap();
		label_criticalLayerWeightFillerUniformMax.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerWeightFillerUniformMax,4,19,1,1);
		label_criticalLayerWeightFillerUniformMax.show();

		text_criticalLayerWeightFillerUniformMax.set_max_length(100);
		text_criticalLayerWeightFillerUniformMax.set_text("1");
		text_criticalLayerWeightFillerUniformMax.select_region(0, text_criticalLayerWeightFillerUniformMax.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerWeightFillerUniformMax,5,19,1,1);	
		text_criticalLayerWeightFillerUniformMax.show();

		label_criticalLayerWeightFillerGaussianMean.set_text("mean: ");
		label_criticalLayerWeightFillerGaussianMean.set_line_wrap();
		label_criticalLayerWeightFillerGaussianMean.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerWeightFillerGaussianMean,4,19,1,1);
		label_criticalLayerWeightFillerGaussianMean.show();

		text_criticalLayerWeightFillerGaussianMean.set_max_length(100);
		text_criticalLayerWeightFillerGaussianMean.set_text("0");
		text_criticalLayerWeightFillerGaussianMean.select_region(0, text_criticalLayerWeightFillerGaussianMean.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerWeightFillerGaussianMean,5,19,1,1);	
		text_criticalLayerWeightFillerGaussianMean.show();

		label_criticalLayerWeightFillerGaussianStd.set_text("std: ");
		label_criticalLayerWeightFillerGaussianStd.set_line_wrap();
		label_criticalLayerWeightFillerGaussianStd.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerWeightFillerGaussianStd,6,19,1,1);
		label_criticalLayerWeightFillerGaussianStd.show();

		text_criticalLayerWeightFillerGaussianStd.set_max_length(100);
		text_criticalLayerWeightFillerGaussianStd.set_text("0.1");
		text_criticalLayerWeightFillerGaussianStd.select_region(0, text_criticalLayerWeightFillerGaussianStd.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerWeightFillerGaussianStd,7,19,1,1);	
		text_criticalLayerWeightFillerGaussianStd.show();

		label_criticalLayerWeightFillerXavierVariance.set_text("variance_norm: ");
		label_criticalLayerWeightFillerXavierVariance.set_line_wrap();
		label_criticalLayerWeightFillerXavierVariance.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerWeightFillerXavierVariance,4,20,1,1);
		label_criticalLayerWeightFillerXavierVariance.show();

//		m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerXavierIn,5,20,1,1);
		rbutton_criticalLayerWeightFillerXavierIn.show();
//		m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerXavierOut,6,20,1,1);
		rbutton_criticalLayerWeightFillerXavierOut.show();
//		m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerXavierAvg,7,20,1,1);
		rbutton_criticalLayerWeightFillerXavierAvg.show();

		label_criticalLayerWeightFillerMSRAVariance.set_text("variance_norm: ");
		label_criticalLayerWeightFillerMSRAVariance.set_line_wrap();
		label_criticalLayerWeightFillerMSRAVariance.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerWeightFillerMSRAVariance,4,20,1,1);
		label_criticalLayerWeightFillerMSRAVariance.show();

//		m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerXavierIn,5,20,1,1);
		rbutton_criticalLayerWeightFillerMSRAIn.show();
//		m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerXavierOut,6,20,1,1);
		rbutton_criticalLayerWeightFillerMSRAOut.show();
//		m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerXavierAvg,7,20,1,1);
		rbutton_criticalLayerWeightFillerMSRAAvg.show();

		label_criticalLayerBias.set_text("Set bias value: ");
		label_criticalLayerBias.set_line_wrap();
		label_criticalLayerBias.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerBias,0,24,2,1);
		label_criticalLayerBias.show();

		text_criticalLayerBias.set_max_length(100);
		text_criticalLayerBias.set_text("0.1");
		text_criticalLayerBias.select_region(0, text_criticalLayerBias.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerBias,2,24,1,1);	
		text_criticalLayerBias.show();
	}
	else if(data == "InnerProduct")
	{
		label_criticalLayerBottom1.hide();
		text_criticalLayerBottom1.hide();
		label_criticalLayerBottom2.hide();
		text_criticalLayerBottom2.hide();
		label_criticalLayerTop.hide();
		text_criticalLayerTop.hide();
		label_criticalLayerName.hide();
		text_criticalLayerName.hide();	
		label_criticalLayerFilterLr.hide();
		text_criticalLayerFilterLr.hide();
		label_criticalLayerFilterDm.hide();
		text_criticalLayerFilterDm.hide();
		label_criticalLayerBiasLr.hide();
		text_criticalLayerBiasLr.hide();
		label_criticalLayerBiasDm.hide();
		text_criticalLayerBiasDm.hide();
		label_criticalLayerNumOutput.hide();
		text_criticalLayerNumOutput.hide();		
		label_criticalLayerKernelW.hide();
		text_criticalLayerKernelW.hide();
		label_criticalLayerKernelH.hide();
		text_criticalLayerKernelH.hide();	
		label_criticalLayerStrideW.hide();
		text_criticalLayerStrideW.hide();
		label_criticalLayerStrideH.hide();
		text_criticalLayerStrideH.hide();
		label_criticalLayerPadW.hide();
		text_criticalLayerPadW.hide();
		label_criticalLayerPadH.hide();
		text_criticalLayerPadH.hide();
		label_criticalLayerWeightFiller.hide();
		rbutton_criticalLayerWeightFillerConstant.hide();
		rbutton_criticalLayerWeightFillerUniform.hide();
		rbutton_criticalLayerWeightGaussian.hide();
		rbutton_criticalLayerWeightFillerPositiveUnitBall.hide();
		rbutton_criticalLayerWeightFillerXavier.hide();
		rbutton_criticalLayerWeightFillerMSRA.hide();
		rbutton_criticalLayerWeightFillerBilinear.hide();
		label_criticalLayerWeightFillerConstantValue.hide();
		text_criticalLayerWeightFillerConstantValue.hide();
		label_criticalLayerWeightFillerUniformMin.hide();
		label_criticalLayerWeightFillerUniformMax.hide();
		text_criticalLayerWeightFillerUniformMin.hide();
		text_criticalLayerWeightFillerUniformMax.hide();
		label_criticalLayerWeightFillerGaussianMean.hide();
		text_criticalLayerWeightFillerGaussianMean.hide();
		label_criticalLayerWeightFillerGaussianStd.hide();
		text_criticalLayerWeightFillerGaussianStd.hide();
		label_criticalLayerWeightFillerXavierVariance.hide();
		rbutton_criticalLayerWeightFillerXavierIn.hide();
		rbutton_criticalLayerWeightFillerXavierOut.hide();
		rbutton_criticalLayerWeightFillerXavierAvg.hide();
		label_criticalLayerWeightFillerMSRAVariance.hide();
		rbutton_criticalLayerWeightFillerMSRAIn.hide();
		rbutton_criticalLayerWeightFillerMSRAOut.hide();
		rbutton_criticalLayerWeightFillerMSRAAvg.hide();
		label_criticalLayerDropoutRatio.hide();
		text_criticalLayerDropoutRatio.hide();
		label_criticalLayerPool.hide();
		label_criticalLayerBias.hide();
		text_criticalLayerBias.hide();
		rbutton_criticalLayerPoolMax.hide();
		rbutton_criticalLayerPoolAve.hide();

		label_criticalLayerBottom1.set_text("Bottom1 Layer Name: ");
		label_criticalLayerBottom1.set_line_wrap();
		label_criticalLayerBottom1.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerBottom1,0,1,2,1);
		label_criticalLayerBottom1.show();

		text_criticalLayerBottom1.set_max_length(100);
		text_criticalLayerBottom1.set_text("");
		text_criticalLayerBottom1.select_region(0, text_criticalLayerBottom1.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerBottom1,2,1,1,1);	
		text_criticalLayerBottom1.show();

		label_criticalLayerTop.set_text("Top Layer Name: ");
		label_criticalLayerTop.set_line_wrap();
		label_criticalLayerTop.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerTop,0,3,2,1);
		label_criticalLayerTop.show();

		text_criticalLayerTop.set_max_length(100);
		text_criticalLayerTop.set_text("");
		text_criticalLayerTop.select_region(0, text_criticalLayerTop.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerTop,2,3,1,1);	
		text_criticalLayerTop.show();

		label_criticalLayerName.set_text("Current Layer Name: ");
		label_criticalLayerName.set_line_wrap();
		label_criticalLayerName.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerName,0,4,2,1);
		label_criticalLayerName.show();

		text_criticalLayerName.set_max_length(100);
		text_criticalLayerName.set_text("");
		text_criticalLayerName.select_region(0, text_criticalLayerName.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerName,2,4,1,1);	
		text_criticalLayerName.show();

		label_criticalLayerFilterLr.set_text("Set filter lr_mult:\n(Leave unchanged if not needed) ");
		label_criticalLayerFilterLr.set_line_wrap();
		label_criticalLayerFilterLr.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerFilterLr,0,5,2,1);
		label_criticalLayerFilterLr.show();

		text_criticalLayerFilterLr.set_max_length(100);
		text_criticalLayerFilterLr.set_text("1");
		text_criticalLayerFilterLr.select_region(0, text_criticalLayerFilterLr.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerFilterLr,2,5,1,1);	
		text_criticalLayerFilterLr.show();

		label_criticalLayerFilterDm.set_text("Set filter decay_mult:\n(Leave unchanged if not needed) ");
		label_criticalLayerFilterDm.set_line_wrap();
		label_criticalLayerFilterDm.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerFilterDm,0,6,2,1);
		label_criticalLayerFilterDm.show();

		text_criticalLayerFilterDm.set_max_length(100);
		text_criticalLayerFilterDm.set_text("1");
		text_criticalLayerFilterDm.select_region(0, text_criticalLayerFilterDm.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerFilterDm,2,6,1,1);	
		text_criticalLayerFilterDm.show();

		label_criticalLayerBiasLr.set_text("Set bias lr_mult:\n(Leave unchanged if not needed) ");
		label_criticalLayerBiasLr.set_line_wrap();
		label_criticalLayerBiasLr.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerBiasLr,0,7,2,1);
		label_criticalLayerBiasLr.show();

		text_criticalLayerBiasLr.set_max_length(100);
		text_criticalLayerBiasLr.set_text("2");
		text_criticalLayerBiasLr.select_region(0, text_criticalLayerBiasLr.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerBiasLr,2,7,1,1);	
		text_criticalLayerBiasLr.show();

		label_criticalLayerBiasDm.set_text("Set bias decay_mult:\n(Leave unchanged if not needed) ");
		label_criticalLayerBiasDm.set_line_wrap();
		label_criticalLayerBiasDm.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerBiasDm,0,8,2,1);
		label_criticalLayerBiasDm.show();

		text_criticalLayerBiasDm.set_max_length(100);
		text_criticalLayerBiasDm.set_text("0");
		text_criticalLayerBiasDm.select_region(0, text_criticalLayerBiasDm.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerBiasDm,2,8,1,1);	
		text_criticalLayerBiasDm.show();

		label_criticalLayerNumOutput.set_text("Set param num_output: ");
		label_criticalLayerNumOutput.set_line_wrap();
		label_criticalLayerNumOutput.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerNumOutput,0,9,2,1);
		label_criticalLayerNumOutput.show();

		text_criticalLayerNumOutput.set_max_length(100);
		text_criticalLayerNumOutput.set_text("64");
		text_criticalLayerNumOutput.select_region(0, text_criticalLayerNumOutput.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerNumOutput,2,9,1,1);	
		text_criticalLayerNumOutput.show();


		label_criticalLayerWeightFiller.set_text("Set Weight Filler : ");
		label_criticalLayerWeightFiller.set_line_wrap();
		label_criticalLayerWeightFiller.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerWeightFiller,0,16,2,1);
		label_criticalLayerWeightFiller.show();

//		Gtk::RadioButton::Group group1 = rbutton_criticalLayerWeightFillerConstant.get_group();
//	 	rbutton_criticalLayerWeightFillerUniform.set_group(group1);
//	 	rbutton_criticalLayerWeightGaussian.set_group(group1);
//	 	rbutton_criticalLayerWeightFillerPositiveUnitBall.set_group(group1);
//	 	rbutton_criticalLayerWeightFillerXavier.set_group(group1);
//	 	rbutton_criticalLayerWeightFillerMSRA.set_group(group1);
//	 	rbutton_criticalLayerWeightFillerBilinear.set_group(group1);
//		rbutton_criticalLayerWeightFillerConstant.set_active();
//		m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerConstant,2,17,1,1);
		rbutton_criticalLayerWeightFillerConstant.show();
//		m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerUniform,2,18,1,1);
		rbutton_criticalLayerWeightFillerUniform.show();
//		m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightGaussian,2,19,1,1);
		rbutton_criticalLayerWeightGaussian.show();
//		m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerPositiveUnitBall,2,20,1,1);
		rbutton_criticalLayerWeightFillerPositiveUnitBall.show();
//		m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerXavier,2,21,1,1);
		rbutton_criticalLayerWeightFillerXavier.show();
//		m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerMSRA,2,22,1,1);
		rbutton_criticalLayerWeightFillerMSRA.show();
//		m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerBilinear,2,23,1,1);
		rbutton_criticalLayerWeightFillerBilinear.show();

		label_criticalLayerWeightFillerConstantValue.set_text("value: ");
		label_criticalLayerWeightFillerConstantValue.set_line_wrap();
		label_criticalLayerWeightFillerConstantValue.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerWeightFillerConstantValue,4,17,1,1);
		label_criticalLayerWeightFillerConstantValue.show();

		text_criticalLayerWeightFillerConstantValue.set_max_length(100);
		text_criticalLayerWeightFillerConstantValue.set_text("0.5");
		text_criticalLayerWeightFillerConstantValue.select_region(0, text_criticalLayerWeightFillerConstantValue.get_text_length());
//		m_grid_criticalLayerWeightFillerConstantValue.attach(text_criticalLayerWeightFillerConstantValue,5,15,1,1);	
		text_criticalLayerWeightFillerConstantValue.show();

		label_criticalLayerWeightFillerUniformMin.set_text("min: ");
		label_criticalLayerWeightFillerUniformMin.set_line_wrap();
		label_criticalLayerWeightFillerUniformMin.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerWeightFillerUniformMin,4,18,1,1);
		label_criticalLayerWeightFillerUniformMin.show();

		text_criticalLayerWeightFillerUniformMin.set_max_length(100);
		text_criticalLayerWeightFillerUniformMin.set_text("0");
		text_criticalLayerWeightFillerUniformMin.select_region(0, text_criticalLayerWeightFillerUniformMin.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerWeightFillerUniformMin,5,18,1,1);	
		text_criticalLayerWeightFillerUniformMin.show();

		label_criticalLayerWeightFillerUniformMax.set_text("max: ");
		label_criticalLayerWeightFillerUniformMax.set_line_wrap();
		label_criticalLayerWeightFillerUniformMax.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerWeightFillerUniformMax,4,19,1,1);
		label_criticalLayerWeightFillerUniformMax.show();

		text_criticalLayerWeightFillerUniformMax.set_max_length(100);
		text_criticalLayerWeightFillerUniformMax.set_text("1");
		text_criticalLayerWeightFillerUniformMax.select_region(0, text_criticalLayerWeightFillerUniformMax.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerWeightFillerUniformMax,5,19,1,1);	
		text_criticalLayerWeightFillerUniformMax.show();

		label_criticalLayerWeightFillerGaussianMean.set_text("mean: ");
		label_criticalLayerWeightFillerGaussianMean.set_line_wrap();
		label_criticalLayerWeightFillerGaussianMean.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerWeightFillerGaussianMean,4,19,1,1);
		label_criticalLayerWeightFillerGaussianMean.show();

		text_criticalLayerWeightFillerGaussianMean.set_max_length(100);
		text_criticalLayerWeightFillerGaussianMean.set_text("0");
		text_criticalLayerWeightFillerGaussianMean.select_region(0, text_criticalLayerWeightFillerGaussianMean.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerWeightFillerGaussianMean,5,19,1,1);	
		text_criticalLayerWeightFillerGaussianMean.show();

		label_criticalLayerWeightFillerGaussianStd.set_text("std: ");
		label_criticalLayerWeightFillerGaussianStd.set_line_wrap();
		label_criticalLayerWeightFillerGaussianStd.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerWeightFillerGaussianStd,6,19,1,1);
		label_criticalLayerWeightFillerGaussianStd.show();

		text_criticalLayerWeightFillerGaussianStd.set_max_length(100);
		text_criticalLayerWeightFillerGaussianStd.set_text("0.1");
		text_criticalLayerWeightFillerGaussianStd.select_region(0, text_criticalLayerWeightFillerGaussianStd.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerWeightFillerGaussianStd,7,19,1,1);	
		text_criticalLayerWeightFillerGaussianStd.show();

		label_criticalLayerWeightFillerXavierVariance.set_text("variance_norm: ");
		label_criticalLayerWeightFillerXavierVariance.set_line_wrap();
		label_criticalLayerWeightFillerXavierVariance.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerWeightFillerXavierVariance,4,20,1,1);
		label_criticalLayerWeightFillerXavierVariance.show();

//		m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerXavierIn,5,20,1,1);
		rbutton_criticalLayerWeightFillerXavierIn.show();
//		m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerXavierOut,6,20,1,1);
		rbutton_criticalLayerWeightFillerXavierOut.show();
//		m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerXavierAvg,7,20,1,1);
		rbutton_criticalLayerWeightFillerXavierAvg.show();

		label_criticalLayerWeightFillerMSRAVariance.set_text("variance_norm: ");
		label_criticalLayerWeightFillerMSRAVariance.set_line_wrap();
		label_criticalLayerWeightFillerMSRAVariance.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerWeightFillerMSRAVariance,4,20,1,1);
		label_criticalLayerWeightFillerMSRAVariance.show();

//		m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerXavierIn,5,20,1,1);
		rbutton_criticalLayerWeightFillerMSRAIn.show();
//		m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerXavierOut,6,20,1,1);
		rbutton_criticalLayerWeightFillerMSRAOut.show();
//		m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerXavierAvg,7,20,1,1);
		rbutton_criticalLayerWeightFillerMSRAAvg.show();
	
		label_criticalLayerBias.set_text("Set bias value: ");
		label_criticalLayerBias.set_line_wrap();
		label_criticalLayerBias.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerBias,0,24,2,1);
		label_criticalLayerBias.show();

		text_criticalLayerBias.set_max_length(100);
		text_criticalLayerBias.set_text("0.1");
		text_criticalLayerBias.select_region(0, text_criticalLayerBias.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerBias,2,24,1,1);	
		text_criticalLayerBias.show();	
	}
	else if( data == "Dropout")
	{
		label_criticalLayerBottom1.hide();
		text_criticalLayerBottom1.hide();
		label_criticalLayerBottom2.hide();
		text_criticalLayerBottom2.hide();
		label_criticalLayerTop.hide();
		text_criticalLayerTop.hide();
		label_criticalLayerName.hide();
		text_criticalLayerName.hide();	
		label_criticalLayerFilterLr.hide();
		text_criticalLayerFilterLr.hide();
		label_criticalLayerFilterDm.hide();
		text_criticalLayerFilterDm.hide();
		label_criticalLayerBiasLr.hide();
		text_criticalLayerBiasLr.hide();
		label_criticalLayerBiasDm.hide();
		text_criticalLayerBiasDm.hide();
		label_criticalLayerNumOutput.hide();
		text_criticalLayerNumOutput.hide();		
		label_criticalLayerKernelW.hide();
		text_criticalLayerKernelW.hide();
		label_criticalLayerKernelH.hide();
		text_criticalLayerKernelH.hide();	
		label_criticalLayerStrideW.hide();
		text_criticalLayerStrideW.hide();
		label_criticalLayerStrideH.hide();
		text_criticalLayerStrideH.hide();
		label_criticalLayerPadW.hide();
		text_criticalLayerPadW.hide();
		label_criticalLayerPadH.hide();
		text_criticalLayerPadH.hide();
		label_criticalLayerWeightFiller.hide();
		rbutton_criticalLayerWeightFillerConstant.hide();
		rbutton_criticalLayerWeightFillerUniform.hide();
		rbutton_criticalLayerWeightGaussian.hide();
		rbutton_criticalLayerWeightFillerPositiveUnitBall.hide();
		rbutton_criticalLayerWeightFillerXavier.hide();
		rbutton_criticalLayerWeightFillerMSRA.hide();
		rbutton_criticalLayerWeightFillerBilinear.hide();
		label_criticalLayerWeightFillerConstantValue.hide();
		text_criticalLayerWeightFillerConstantValue.hide();
		label_criticalLayerWeightFillerUniformMin.hide();
		label_criticalLayerWeightFillerUniformMax.hide();
		text_criticalLayerWeightFillerUniformMin.hide();
		text_criticalLayerWeightFillerUniformMax.hide();
		label_criticalLayerWeightFillerGaussianMean.hide();
		text_criticalLayerWeightFillerGaussianMean.hide();
		label_criticalLayerWeightFillerGaussianStd.hide();
		text_criticalLayerWeightFillerGaussianStd.hide();
		label_criticalLayerWeightFillerXavierVariance.hide();
		rbutton_criticalLayerWeightFillerXavierIn.hide();
		rbutton_criticalLayerWeightFillerXavierOut.hide();
		rbutton_criticalLayerWeightFillerXavierAvg.hide();
		label_criticalLayerWeightFillerMSRAVariance.hide();
		rbutton_criticalLayerWeightFillerMSRAIn.hide();
		rbutton_criticalLayerWeightFillerMSRAOut.hide();
		rbutton_criticalLayerWeightFillerMSRAAvg.hide();
		label_criticalLayerDropoutRatio.hide();
		text_criticalLayerDropoutRatio.hide();
		label_criticalLayerPool.hide();
		label_criticalLayerBias.hide();
		text_criticalLayerBias.hide();
		rbutton_criticalLayerPoolMax.hide();
		rbutton_criticalLayerPoolAve.hide();

		label_criticalLayerBottom1.set_text("Bottom1 Layer Name: ");
		label_criticalLayerBottom1.set_line_wrap();
		label_criticalLayerBottom1.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerBottom1,0,1,2,1);
		label_criticalLayerBottom1.show();

		text_criticalLayerBottom1.set_max_length(100);
		text_criticalLayerBottom1.set_text("");
		text_criticalLayerBottom1.select_region(0, text_criticalLayerBottom1.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerBottom1,2,1,1,1);	
		text_criticalLayerBottom1.show();

		label_criticalLayerTop.set_text("Top Layer Name: ");
		label_criticalLayerTop.set_line_wrap();
		label_criticalLayerTop.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerTop,0,3,2,1);
		label_criticalLayerTop.show();

		text_criticalLayerTop.set_max_length(100);
		text_criticalLayerTop.set_text("");
		text_criticalLayerTop.select_region(0, text_criticalLayerTop.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerTop,2,3,1,1);	
		text_criticalLayerTop.show();

		label_criticalLayerName.set_text("Current Layer Name: ");
		label_criticalLayerName.set_line_wrap();
		label_criticalLayerName.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerName,0,4,2,1);
		label_criticalLayerName.show();

		text_criticalLayerName.set_max_length(100);
		text_criticalLayerName.set_text("");
		text_criticalLayerName.select_region(0, text_criticalLayerName.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerName,2,4,1,1);	
		text_criticalLayerName.show();

		label_criticalLayerDropoutRatio.set_text("Set Dropout Ratio: ");
		label_criticalLayerDropoutRatio.set_line_wrap();
		label_criticalLayerDropoutRatio.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerDropoutRatio,0,22,2,1);
		label_criticalLayerDropoutRatio.show();

		text_criticalLayerDropoutRatio.set_max_length(100);
		text_criticalLayerDropoutRatio.set_text("0.5");
		text_criticalLayerDropoutRatio.select_region(0, text_criticalLayerDropoutRatio.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerDropoutRatio,2,22,1,1);	
		text_criticalLayerDropoutRatio.show();
	}
	else if(data == "Pooling")
	{
		label_criticalLayerBottom1.hide();
		text_criticalLayerBottom1.hide();
		label_criticalLayerBottom2.hide();
		text_criticalLayerBottom2.hide();
		label_criticalLayerTop.hide();
		text_criticalLayerTop.hide();
		label_criticalLayerName.hide();
		text_criticalLayerName.hide();	
		label_criticalLayerFilterLr.hide();
		text_criticalLayerFilterLr.hide();
		label_criticalLayerFilterDm.hide();
		text_criticalLayerFilterDm.hide();
		label_criticalLayerBiasLr.hide();
		text_criticalLayerBiasLr.hide();
		label_criticalLayerBiasDm.hide();
		text_criticalLayerBiasDm.hide();
		label_criticalLayerNumOutput.hide();
		text_criticalLayerNumOutput.hide();		
		label_criticalLayerKernelW.hide();
		text_criticalLayerKernelW.hide();
		label_criticalLayerKernelH.hide();
		text_criticalLayerKernelH.hide();	
		label_criticalLayerStrideW.hide();
		text_criticalLayerStrideW.hide();
		label_criticalLayerStrideH.hide();
		text_criticalLayerStrideH.hide();
		label_criticalLayerPadW.hide();
		text_criticalLayerPadW.hide();
		label_criticalLayerPadH.hide();
		text_criticalLayerPadH.hide();
		label_criticalLayerWeightFiller.hide();
		rbutton_criticalLayerWeightFillerConstant.hide();
		rbutton_criticalLayerWeightFillerUniform.hide();
		rbutton_criticalLayerWeightGaussian.hide();
		rbutton_criticalLayerWeightFillerPositiveUnitBall.hide();
		rbutton_criticalLayerWeightFillerXavier.hide();
		rbutton_criticalLayerWeightFillerMSRA.hide();
		rbutton_criticalLayerWeightFillerBilinear.hide();
		label_criticalLayerWeightFillerConstantValue.hide();
		text_criticalLayerWeightFillerConstantValue.hide();
		label_criticalLayerWeightFillerUniformMin.hide();
		label_criticalLayerWeightFillerUniformMax.hide();
		text_criticalLayerWeightFillerUniformMin.hide();
		text_criticalLayerWeightFillerUniformMax.hide();
		label_criticalLayerWeightFillerGaussianMean.hide();
		text_criticalLayerWeightFillerGaussianMean.hide();
		label_criticalLayerWeightFillerGaussianStd.hide();
		text_criticalLayerWeightFillerGaussianStd.hide();
		label_criticalLayerWeightFillerXavierVariance.hide();
		rbutton_criticalLayerWeightFillerXavierIn.hide();
		rbutton_criticalLayerWeightFillerXavierOut.hide();
		rbutton_criticalLayerWeightFillerXavierAvg.hide();
		label_criticalLayerWeightFillerMSRAVariance.hide();
		rbutton_criticalLayerWeightFillerMSRAIn.hide();
		rbutton_criticalLayerWeightFillerMSRAOut.hide();
		rbutton_criticalLayerWeightFillerMSRAAvg.hide();
		label_criticalLayerDropoutRatio.hide();
		text_criticalLayerDropoutRatio.hide();
		label_criticalLayerPool.hide();
		label_criticalLayerBias.hide();
		text_criticalLayerBias.hide();
		rbutton_criticalLayerPoolMax.hide();
		rbutton_criticalLayerPoolAve.hide();


		label_criticalLayerBottom1.set_text("Bottom1 Layer Name: ");
		label_criticalLayerBottom1.set_line_wrap();
		label_criticalLayerBottom1.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerBottom1,0,1,2,1);
		label_criticalLayerBottom1.show();

		text_criticalLayerBottom1.set_max_length(100);
		text_criticalLayerBottom1.set_text("");
		text_criticalLayerBottom1.select_region(0, text_criticalLayerBottom1.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerBottom1,2,1,1,1);	
		text_criticalLayerBottom1.show();

		label_criticalLayerTop.set_text("Top Layer Name: ");
		label_criticalLayerTop.set_line_wrap();
		label_criticalLayerTop.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerTop,0,3,2,1);
		label_criticalLayerTop.show();

		text_criticalLayerTop.set_max_length(100);
		text_criticalLayerTop.set_text("");
		text_criticalLayerTop.select_region(0, text_criticalLayerTop.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerTop,2,3,1,1);	
		text_criticalLayerTop.show();

		label_criticalLayerName.set_text("Current Layer Name: ");
		label_criticalLayerName.set_line_wrap();
		label_criticalLayerName.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerName,0,4,2,1);
		label_criticalLayerName.show();

		text_criticalLayerName.set_max_length(100);
		text_criticalLayerName.set_text("");
		text_criticalLayerName.select_region(0, text_criticalLayerName.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerName,2,4,1,1);	
		text_criticalLayerName.show();

		label_criticalLayerKernelW.set_text("Set param kernel_w: ");
		label_criticalLayerKernelW.set_line_wrap();
		label_criticalLayerKernelW.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerKernelW,0,10,2,1);
		label_criticalLayerKernelW.show();

		text_criticalLayerKernelW.set_max_length(100);
		text_criticalLayerKernelW.set_text("3");
		text_criticalLayerKernelW.select_region(0, text_criticalLayerKernelW.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerKernelW,2,10,1,1);	
		text_criticalLayerKernelW.show();

		label_criticalLayerKernelH.set_text("Set param kernel_h: ");
		label_criticalLayerKernelH.set_line_wrap();
		label_criticalLayerKernelH.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerKernelH,0,11,2,1);
		label_criticalLayerKernelH.show();

		text_criticalLayerKernelH.set_max_length(100);
		text_criticalLayerKernelH.set_text("3");
		text_criticalLayerKernelH.select_region(0, text_criticalLayerKernelH.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerKernelH,2,11,1,1);	
		text_criticalLayerKernelH.show();

		label_criticalLayerStrideW.set_text("Set param stride_w: ");
		label_criticalLayerStrideW.set_line_wrap();
		label_criticalLayerStrideW.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerStrideW,0,12,2,1);
		label_criticalLayerStrideW.show();

		text_criticalLayerStrideW.set_max_length(100);
		text_criticalLayerStrideW.set_text("1");
		text_criticalLayerStrideW.select_region(0, text_criticalLayerStrideW.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerStrideW,2,12,1,1);	
		text_criticalLayerStrideW.show();

		label_criticalLayerStrideH.set_text("Set param stride_h: ");
		label_criticalLayerStrideH.set_line_wrap();
		label_criticalLayerStrideH.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerStrideH,0,13,2,1);
		label_criticalLayerStrideH.show();

		text_criticalLayerStrideH.set_max_length(100);
		text_criticalLayerStrideH.set_text("1");
		text_criticalLayerStrideH.select_region(0, text_criticalLayerStrideH.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerStrideH,2,13,1,1);	
		text_criticalLayerStrideH.show();

		label_criticalLayerPadW.set_text("Set param pad_w: ");
		label_criticalLayerPadW.set_line_wrap();
		label_criticalLayerPadW.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerPadW,0,14,2,1);
		label_criticalLayerPadW.show();

		text_criticalLayerPadW.set_max_length(100);
		text_criticalLayerPadW.set_text("1");
		text_criticalLayerPadW.select_region(0, text_criticalLayerPadW.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerPadW,2,14,1,1);	
		text_criticalLayerPadW.show();

		label_criticalLayerPadH.set_text("Set param pad_h: ");
		label_criticalLayerPadH.set_line_wrap();
		label_criticalLayerPadH.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerPadH,0,14,2,1);
		label_criticalLayerPadH.show();

		text_criticalLayerPadH.set_max_length(100);
		text_criticalLayerPadH.set_text("1");
		text_criticalLayerPadH.select_region(0, text_criticalLayerPadH.get_text_length());
//		m_grid_criticalLayerType.attach(text_criticalLayerPadH,2,14,1,1);	
		text_criticalLayerPadH.show();

		label_criticalLayerPool.set_text("Set Pool Type: ");
		label_criticalLayerPool.set_line_wrap();
		label_criticalLayerPool.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_criticalLayerType.attach(label_criticalLayerPool,0,23,2,1);
		label_criticalLayerPool.show();

		Gtk::RadioButton::Group group4 = rbutton_criticalLayerPoolMax.get_group();
	 	rbutton_criticalLayerPoolAve.set_group(group4);
	 	rbutton_criticalLayerPoolMax.set_active();
//		m_grid_criticalLayerType.attach(rbutton_criticalLayerPoolMax,2,23,1,1);
		rbutton_criticalLayerPoolMax.show();
//		m_grid_criticalLayerType.attach(rbutton_criticalLayerPoolAve,3,23,1,1);
		rbutton_criticalLayerPoolAve.show();

	}
	else
	{
		label_criticalLayerBottom1.hide();
		text_criticalLayerBottom1.hide();
		label_criticalLayerBottom2.hide();
		text_criticalLayerBottom2.hide();
		label_criticalLayerTop.hide();
		text_criticalLayerTop.hide();
		label_criticalLayerName.hide();
		text_criticalLayerName.hide();	
		label_criticalLayerFilterLr.hide();
		text_criticalLayerFilterLr.hide();
		label_criticalLayerFilterDm.hide();
		text_criticalLayerFilterDm.hide();
		label_criticalLayerBiasLr.hide();
		text_criticalLayerBiasLr.hide();
		label_criticalLayerBiasDm.hide();
		text_criticalLayerBiasDm.hide();
		label_criticalLayerNumOutput.hide();
		text_criticalLayerNumOutput.hide();		
		label_criticalLayerKernelW.hide();
		text_criticalLayerKernelW.hide();
		label_criticalLayerKernelH.hide();
		text_criticalLayerKernelH.hide();	
		label_criticalLayerStrideW.hide();
		text_criticalLayerStrideW.hide();
		label_criticalLayerStrideH.hide();
		text_criticalLayerStrideH.hide();
		label_criticalLayerPadW.hide();
		text_criticalLayerPadW.hide();
		label_criticalLayerPadH.hide();
		text_criticalLayerPadH.hide();
		label_criticalLayerWeightFiller.hide();
		rbutton_criticalLayerWeightFillerConstant.hide();
		rbutton_criticalLayerWeightFillerUniform.hide();
		rbutton_criticalLayerWeightGaussian.hide();
		rbutton_criticalLayerWeightFillerPositiveUnitBall.hide();
		rbutton_criticalLayerWeightFillerXavier.hide();
		rbutton_criticalLayerWeightFillerMSRA.hide();
		rbutton_criticalLayerWeightFillerBilinear.hide();
		label_criticalLayerWeightFillerConstantValue.hide();
		text_criticalLayerWeightFillerConstantValue.hide();
		label_criticalLayerWeightFillerUniformMin.hide();
		label_criticalLayerWeightFillerUniformMax.hide();
		text_criticalLayerWeightFillerUniformMin.hide();
		text_criticalLayerWeightFillerUniformMax.hide();
		label_criticalLayerWeightFillerGaussianMean.hide();
		text_criticalLayerWeightFillerGaussianMean.hide();
		label_criticalLayerWeightFillerGaussianStd.hide();
		text_criticalLayerWeightFillerGaussianStd.hide();
		label_criticalLayerWeightFillerXavierVariance.hide();
		rbutton_criticalLayerWeightFillerXavierIn.hide();
		rbutton_criticalLayerWeightFillerXavierOut.hide();
		rbutton_criticalLayerWeightFillerXavierAvg.hide();
		label_criticalLayerWeightFillerMSRAVariance.hide();
		rbutton_criticalLayerWeightFillerMSRAIn.hide();
		rbutton_criticalLayerWeightFillerMSRAOut.hide();
		rbutton_criticalLayerWeightFillerMSRAAvg.hide();
		label_criticalLayerDropoutRatio.hide();
		text_criticalLayerDropoutRatio.hide();
		label_criticalLayerPool.hide();
		label_criticalLayerBias.hide();
		text_criticalLayerBias.hide();
		rbutton_criticalLayerPoolMax.hide();
		rbutton_criticalLayerPoolAve.hide();
	}
	m_sw_criticalLayerType.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
	m_grid_criticalLayerType.show();
//	show_all_children();
	m_sw_criticalLayerType.show();

}
