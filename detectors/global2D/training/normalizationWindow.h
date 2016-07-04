#include "network.h"

void NetworkCreator::showWindow_normalizationLayerType(Glib::ustring data)
{
	remove();
	set_title("Normalization Layer");
	set_border_width(10);
	add(m_sw_normalizationLayerType);
	m_grid_normalizationLayerType.set_column_spacing (10);
	m_grid_normalizationLayerType.set_row_spacing (50);

	//level 0
	if(data == "")
		title_normalizationLayerType.set_text("Set the Properties of Normalization Layer type: BatchNorm");
	else
		title_normalizationLayerType.set_text("Set the Properties of Critical Layer type: " + data);
	title_normalizationLayerType.set_line_wrap();
	title_normalizationLayerType.set_justify(Gtk::JUSTIFY_FILL);
//	m_grid_normalizationLayerType.attach(title_normalizationLayerType,0,0,2,1);
	title_normalizationLayerType.show();

	button_setNormalizationParameters.show();
	button_addMoreLayer3.show();
	
	if(data == "" or data == "BatchNorm")
	{
		label_normalizationLayerTop.hide();
		label_normalizationLayerBottom.hide();
		label_normalizationLayerName.hide();
		text_normalizationLayerTop.hide();
		text_normalizationLayerBottom.hide();
		text_normalizationLayerName.hide();
		label_normalizationLayerlocalSize.hide();
		text_normalizationLayerlocalSize.hide();
		label_normalizationLayerAlpha.hide();
		text_normalizationLayerAlpha.hide();
		label_normalizationLayerBeta.hide();
		text_normalizationLayerBeta.hide();
		label_normalizationLayerK.hide();
		text_normalizationLayerK.hide();
		label_normalizationLayerNormRegion.hide();
		rbutton_normalizationLayerLRNWithin.hide();
		rbutton_normalizationLayerLRNAcross.hide();
		label_normalizationLayerAcrossChannel.hide();
		text_normalizationLayerAcrossChannel.hide();
		label_normalizationLayerNormalizeVariance.hide();
		text_normalizationLayerNormalizeVariance.hide();
		label_normalizationLayerEps.hide();
		text_normalizationLayerEps.hide();


		label_normalizationLayerBottom.set_text("Bottom Layer Name: ");
		label_normalizationLayerBottom.set_line_wrap();
		label_normalizationLayerBottom.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_normalizationLayerType.attach(label_normalizationLayerBottom,0,1,2,1);
		label_normalizationLayerBottom.show();

		text_normalizationLayerBottom.set_max_length(100);
		text_normalizationLayerBottom.set_text("");
		text_normalizationLayerBottom.select_region(0, text_normalizationLayerBottom.get_text_length());
//		m_grid_normalizationLayerType.attach(text_normalizationLayerBottom1,2,1,1,1);	
		text_normalizationLayerBottom.show();

		label_normalizationLayerTop.set_text("Top Layer Name: ");
		label_normalizationLayerTop.set_line_wrap();
		label_normalizationLayerTop.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_normalizationLayerType.attach(label_normalizationLayerTop,0,3,2,1);
		label_normalizationLayerTop.show();

		text_normalizationLayerTop.set_max_length(100);
		text_normalizationLayerTop.set_text("");
		text_normalizationLayerTop.select_region(0, text_normalizationLayerTop.get_text_length());
//		m_grid_normalizationLayerType.attach(text_normalizationLayerTop,2,3,1,1);	
		text_normalizationLayerTop.show();

		label_normalizationLayerName.set_text("Current Layer Name: ");
		label_normalizationLayerName.set_line_wrap();
		label_normalizationLayerName.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_normalizationLayerType.attach(label_normalizationLayerName,0,4,2,1);
		label_normalizationLayerName.show();

		text_normalizationLayerName.set_max_length(100);
		text_normalizationLayerName.set_text("");
		text_normalizationLayerName.select_region(0, text_normalizationLayerName.get_text_length());
//		m_grid_normalizationLayerType.attach(text_normalizationLayerName,2,4,1,1);	
		text_normalizationLayerName.show();
	}
	else if(data == "LRN")
	{
		label_normalizationLayerTop.hide();
		label_normalizationLayerBottom.hide();
		label_normalizationLayerName.hide();
		text_normalizationLayerTop.hide();
		text_normalizationLayerBottom.hide();
		text_normalizationLayerName.hide();	
		label_normalizationLayerlocalSize.hide();
		text_normalizationLayerlocalSize.hide();
		label_normalizationLayerAlpha.hide();
		text_normalizationLayerAlpha.hide();
		label_normalizationLayerBeta.hide();
		text_normalizationLayerBeta.hide();
		label_normalizationLayerK.hide();
		text_normalizationLayerK.hide();
		label_normalizationLayerNormRegion.hide();
		rbutton_normalizationLayerLRNWithin.hide();
		rbutton_normalizationLayerLRNAcross.hide();
		label_normalizationLayerAcrossChannel.hide();
		text_normalizationLayerAcrossChannel.hide();
		label_normalizationLayerNormalizeVariance.hide();
		text_normalizationLayerNormalizeVariance.hide();
		label_normalizationLayerEps.hide();
		text_normalizationLayerEps.hide();


		label_normalizationLayerBottom.set_text("Bottom Layer Name: ");
		label_normalizationLayerBottom.set_line_wrap();
		label_normalizationLayerBottom.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_normalizationLayerType.attach(label_normalizationLayerBottom,0,1,2,1);
		label_normalizationLayerBottom.show();

		text_normalizationLayerBottom.set_max_length(100);
		text_normalizationLayerBottom.set_text("");
		text_normalizationLayerBottom.select_region(0, text_normalizationLayerBottom.get_text_length());
//		m_grid_normalizationLayerType.attach(text_normalizationLayerBottom1,2,1,1,1);	
		text_normalizationLayerBottom.show();

		label_normalizationLayerTop.set_text("Top Layer Name: ");
		label_normalizationLayerTop.set_line_wrap();
		label_normalizationLayerTop.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_normalizationLayerType.attach(label_normalizationLayerTop,0,3,2,1);
		label_normalizationLayerTop.show();

		text_normalizationLayerTop.set_max_length(100);
		text_normalizationLayerTop.set_text("");
		text_normalizationLayerTop.select_region(0, text_normalizationLayerTop.get_text_length());
//		m_grid_normalizationLayerType.attach(text_normalizationLayerTop,2,3,1,1);	
		text_normalizationLayerTop.show();

		label_normalizationLayerName.set_text("Current Layer Name: ");
		label_normalizationLayerName.set_line_wrap();
		label_normalizationLayerName.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_normalizationLayerType.attach(label_normalizationLayerName,0,4,2,1);
		label_normalizationLayerName.show();

		text_normalizationLayerName.set_max_length(100);
		text_normalizationLayerName.set_text("");
		text_normalizationLayerName.select_region(0, text_normalizationLayerName.get_text_length());
//		m_grid_normalizationLayerType.attach(text_normalizationLayerName,2,4,1,1);	
		text_normalizationLayerName.show();

		label_normalizationLayerlocalSize.set_text("Inner Parameter - local_size: ");
		label_normalizationLayerlocalSize.set_line_wrap();
		label_normalizationLayerlocalSize.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_normalizationLayerType.attach(label_normalizationLayerlocalSize,0,5,2,1);
		label_normalizationLayerlocalSize.show();

		text_normalizationLayerlocalSize.set_max_length(100);
		text_normalizationLayerlocalSize.set_text("5");
		text_normalizationLayerlocalSize.select_region(0, text_normalizationLayerlocalSize.get_text_length());
//		m_grid_normalizationLayerType.attach(text_normalizationLayerlocalSize,2,5,1,1);	
		text_normalizationLayerlocalSize.show();

		label_normalizationLayerAlpha.set_text("Inner Parameter - alpha: ");
		label_normalizationLayerAlpha.set_line_wrap();
		label_normalizationLayerAlpha.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_normalizationLayerType.attach(label_normalizationLayerAlpha,0,6,2,1);
		label_normalizationLayerAlpha.show();

		text_normalizationLayerAlpha.set_max_length(100);
		text_normalizationLayerAlpha.set_text("0.0001");
		text_normalizationLayerAlpha.select_region(0, text_normalizationLayerAlpha.get_text_length());
//		m_grid_normalizationLayerType.attach(text_normalizationLayerAlpha,2,6,1,1);	
		text_normalizationLayerAlpha.show();

		label_normalizationLayerBeta.set_text("Inner Parameter - beta: ");
		label_normalizationLayerBeta.set_line_wrap();
		label_normalizationLayerBeta.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_normalizationLayerType.attach(label_normalizationLayerBeta,0,7,2,1);
		label_normalizationLayerBeta.show();

		text_normalizationLayerBeta.set_max_length(100);
		text_normalizationLayerBeta.set_text("0.0001");
		text_normalizationLayerBeta.select_region(0, text_normalizationLayerBeta.get_text_length());
//		m_grid_normalizationLayerType.attach(text_normalizationLayerBeta,2,7,1,1);	
		text_normalizationLayerBeta.show();

		label_normalizationLayerK.set_text("Inner Parameter - k: ");
		label_normalizationLayerK.set_line_wrap();
		label_normalizationLayerK.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_normalizationLayerType.attach(label_normalizationLayerK,0,8,2,1);
		label_normalizationLayerK.show();

		text_normalizationLayerK.set_max_length(100);
		text_normalizationLayerK.set_text("1");
		text_normalizationLayerK.select_region(0, text_normalizationLayerK.get_text_length());
//		m_grid_normalizationLayerType.attach(text_normalizationLayerK,2,8,1,1);	
		text_normalizationLayerK.show();

		label_normalizationLayerNormRegion.set_text("Inner Parameter - norm_region: ");
		label_normalizationLayerNormRegion.set_line_wrap();
		label_normalizationLayerNormRegion.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_normalizationLayerType.attach(label_normalizationLayerNormRegion,0,9,2,1);
		label_normalizationLayerNormRegion.show();

		Gtk::RadioButton::Group group5 = rbutton_normalizationLayerLRNWithin.get_group();
	 	rbutton_normalizationLayerLRNAcross.set_group(group5);
	 	rbutton_normalizationLayerLRNWithin.set_active();
//		m_grid_normalizationLayerType.attach(rbutton_normalizationLayerLRNWithin,2,9,1,1);
		rbutton_normalizationLayerLRNWithin.show();
//		m_grid_normalizationLayerType.attach(rbutton_normalizationLayerLRNAcross,3,9,1,1);
		rbutton_normalizationLayerLRNAcross.show();
	
	}
	else if(data == "MVN")
	{
		label_normalizationLayerTop.hide();
		label_normalizationLayerBottom.hide();
		label_normalizationLayerName.hide();
		text_normalizationLayerTop.hide();
		text_normalizationLayerBottom.hide();
		text_normalizationLayerName.hide();
		label_normalizationLayerlocalSize.hide();
		text_normalizationLayerlocalSize.hide();
		label_normalizationLayerAlpha.hide();
		text_normalizationLayerAlpha.hide();
		label_normalizationLayerBeta.hide();
		text_normalizationLayerBeta.hide();
		label_normalizationLayerK.hide();
		text_normalizationLayerK.hide();
		label_normalizationLayerNormRegion.hide();
		rbutton_normalizationLayerLRNWithin.hide();
		rbutton_normalizationLayerLRNAcross.hide();
		label_normalizationLayerAcrossChannel.hide();
		text_normalizationLayerAcrossChannel.hide();
		label_normalizationLayerNormalizeVariance.hide();
		text_normalizationLayerNormalizeVariance.hide();
		label_normalizationLayerEps.hide();
		text_normalizationLayerEps.hide();


		label_normalizationLayerBottom.set_text("Bottom Layer Name: ");
		label_normalizationLayerBottom.set_line_wrap();
		label_normalizationLayerBottom.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_normalizationLayerType.attach(label_normalizationLayerBottom,0,1,2,1);
		label_normalizationLayerBottom.show();

		text_normalizationLayerBottom.set_max_length(100);
		text_normalizationLayerBottom.set_text("");
		text_normalizationLayerBottom.select_region(0, text_normalizationLayerBottom.get_text_length());
//		m_grid_normalizationLayerType.attach(text_normalizationLayerBottom1,2,1,1,1);	
		text_normalizationLayerBottom.show();

		label_normalizationLayerTop.set_text("Top Layer Name: ");
		label_normalizationLayerTop.set_line_wrap();
		label_normalizationLayerTop.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_normalizationLayerType.attach(label_normalizationLayerTop,0,3,2,1);
		label_normalizationLayerTop.show();

		text_normalizationLayerTop.set_max_length(100);
		text_normalizationLayerTop.set_text("");
		text_normalizationLayerTop.select_region(0, text_normalizationLayerTop.get_text_length());
//		m_grid_normalizationLayerType.attach(text_normalizationLayerTop,2,3,1,1);	
		text_normalizationLayerTop.show();

		label_normalizationLayerName.set_text("Current Layer Name: ");
		label_normalizationLayerName.set_line_wrap();
		label_normalizationLayerName.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_normalizationLayerType.attach(label_normalizationLayerName,0,4,2,1);
		label_normalizationLayerName.show();

		text_normalizationLayerName.set_max_length(100);
		text_normalizationLayerName.set_text("");
		text_normalizationLayerName.select_region(0, text_normalizationLayerName.get_text_length());
//		m_grid_normalizationLayerType.attach(text_normalizationLayerName,2,4,1,1);	
		text_normalizationLayerName.show();
	
		label_normalizationLayerAcrossChannel.set_text("Inner Parameter - across_channels: \n(boolean- 0 or 1)");
		label_normalizationLayerAcrossChannel.set_line_wrap();
		label_normalizationLayerAcrossChannel.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_normalizationLayerType.attach(label_normalizationLayerAcrossChannel,0,10,2,1);
		label_normalizationLayerAcrossChannel.show();

		text_normalizationLayerAcrossChannel.set_max_length(100);
		text_normalizationLayerAcrossChannel.set_text("0");
		text_normalizationLayerAcrossChannel.select_region(0, text_normalizationLayerAcrossChannel.get_text_length());
//		m_grid_normalizationLayerType.attach(text_normalizationLayerAcrossChannel,2,10,1,1);	
		text_normalizationLayerAcrossChannel.show();

		label_normalizationLayerNormalizeVariance.set_text("Inner Parameter - normalize_variance: \n(boolean- 0 or 1)");
		label_normalizationLayerNormalizeVariance.set_line_wrap();
		label_normalizationLayerNormalizeVariance.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_normalizationLayerType.attach(label_normalizationLayerNormalizeVariance,0,11,2,1);
		label_normalizationLayerNormalizeVariance.show();

		text_normalizationLayerNormalizeVariance.set_max_length(100);
		text_normalizationLayerNormalizeVariance.set_text("0");
		text_normalizationLayerNormalizeVariance.select_region(0, text_normalizationLayerNormalizeVariance.get_text_length());
//		m_grid_normalizationLayerType.attach(text_normalizationLayerNormalizeVariance,2,11,1,1);	
		text_normalizationLayerNormalizeVariance.show();

		label_normalizationLayerEps.set_text("Inner Parameter - eps: ");
		label_normalizationLayerEps.set_line_wrap();
		label_normalizationLayerEps.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_normalizationLayerType.attach(label_normalizationLayerEps,0,12,2,1);
		label_normalizationLayerEps.show();

		text_normalizationLayerEps.set_max_length(100);
		text_normalizationLayerEps.set_text("100");
		text_normalizationLayerEps.select_region(0, text_normalizationLayerEps.get_text_length());
//		m_grid_normalizationLayerType.attach(text_normalizationLayerEps,2,12,1,1);	
		text_normalizationLayerEps.show();
	}
	else
	{
		
		label_normalizationLayerTop.hide();
		label_normalizationLayerBottom.hide();
		label_normalizationLayerName.hide();
		text_normalizationLayerTop.hide();
		text_normalizationLayerBottom.hide();
		text_normalizationLayerName.hide();
		label_normalizationLayerlocalSize.hide();
		text_normalizationLayerlocalSize.hide();
		label_normalizationLayerAlpha.hide();
		text_normalizationLayerAlpha.hide();
		label_normalizationLayerBeta.hide();
		text_normalizationLayerBeta.hide();
		label_normalizationLayerK.hide();
		text_normalizationLayerK.hide();
		label_normalizationLayerNormRegion.hide();
		rbutton_normalizationLayerLRNWithin.hide();
		rbutton_normalizationLayerLRNAcross.hide();
		label_normalizationLayerAcrossChannel.hide();
		text_normalizationLayerAcrossChannel.hide();
		label_normalizationLayerNormalizeVariance.hide();
		text_normalizationLayerNormalizeVariance.hide();
		label_normalizationLayerEps.hide();
		text_normalizationLayerEps.hide();
	}

	m_sw_normalizationLayerType.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
	m_grid_normalizationLayerType.show();
//	show_all_children();
	m_sw_normalizationLayerType.show();
}
