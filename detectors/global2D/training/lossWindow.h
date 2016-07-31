#include "network.h"

void NetworkCreator::showWindow_lossLayerType(Glib::ustring data)
{
	remove();
	set_title("Loss Layer");
	set_border_width(10);
	add(m_sw_lossLayerType);
	m_grid_lossLayerType.set_column_spacing (10);
	m_grid_lossLayerType.set_row_spacing (50);

	//level 0
	if(data == "" or data == "SoftmaxWithLoss")
		title_lossLayerType.set_text("Set the Properties of Loss Layer type: SoftmaxWithLoss");
	else
		title_lossLayerType.set_text("Will be updated soon");
	title_lossLayerType.set_line_wrap();
	title_lossLayerType.set_justify(Gtk::JUSTIFY_FILL);
//	m_grid_lossLayerType.attach(title_lossLayerType,0,0,2,1);
	title_lossLayerType.show();

	
	button_addMoreLayer4.show();

	if(data == "" or data == "SoftmaxWithLoss")
	{
		label_lossLayerBottom1.hide();
		text_lossLayerBottom1.hide();
		label_lossLayerBottom2.hide();
		text_lossLayerBottom2.hide();
		label_lossLayerTop.hide();
		text_lossLayerTop.hide();
		label_lossLayerName.hide();
		text_lossLayerName.hide();
		label_lossLayerNormalize.hide();
		text_lossLayerNormalize.hide();
		button_setLossParameters.hide();
		label_lossLayerNormalize.hide();		
		
		label_lossLayerBottom1.set_text("Bottom1 Layer Name: ");
		label_lossLayerBottom1.set_line_wrap();
		label_lossLayerBottom1.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_lossLayerType.attach(label_lossLayerBottom1,0,1,2,1);
		label_lossLayerBottom1.show();

		text_lossLayerBottom1.set_max_length(100);
		text_lossLayerBottom1.set_text("");
		text_lossLayerBottom1.select_region(0, text_lossLayerBottom1.get_text_length());
//		m_grid_lossLayerType.attach(text_lossLayerBottom1,2,1,1,1);	
		text_lossLayerBottom1.show();

		label_lossLayerBottom2.set_text("Bottom2 Layer Name: ");
		label_lossLayerBottom2.set_line_wrap();
		label_lossLayerBottom2.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_lossLayerType.attach(label_lossLayerBottom2,0,2,2,1);
		label_lossLayerBottom2.show();

		text_lossLayerBottom2.set_max_length(100);
		text_lossLayerBottom2.set_text("");
		text_lossLayerBottom2.select_region(0, text_lossLayerBottom2.get_text_length());
//		m_grid_lossLayerType.attach(text_lossLayerBottom2,2,2,1,1);	
		text_lossLayerBottom2.show();

		label_lossLayerTop.set_text("Top Layer Name: ");
		label_lossLayerTop.set_line_wrap();
		label_lossLayerTop.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_lossLayerType.attach(label_lossLayerTop,0,3,2,1);
		label_lossLayerTop.show();

		text_lossLayerTop.set_max_length(100);
		text_lossLayerTop.set_text("");
		text_lossLayerTop.select_region(0, text_lossLayerTop.get_text_length());
//		m_grid_lossLayerType.attach(text_lossLayerTop,2,3,1,1);	
		text_lossLayerTop.show();

		label_lossLayerName.set_text("Current Layer Name: ");
		label_lossLayerName.set_line_wrap();
		label_lossLayerName.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_lossLayerType.attach(label_lossLayerName,0,4,2,1);
		label_lossLayerName.show();

		text_lossLayerName.set_max_length(100);
		text_lossLayerName.set_text("");
		text_lossLayerName.select_region(0, text_lossLayerName.get_text_length());
//		m_grid_lossLayerType.attach(text_lossLayerName,2,4,1,1);	
		text_lossLayerName.show();

		label_lossLayerNormalize.set_text("Normalize: \n(bool value)");
		label_lossLayerNormalize.set_line_wrap();
		label_lossLayerNormalize.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_lossLayerType.attach(label_lossLayerNormalize,0,5,2,1);
		label_lossLayerNormalize.show();

		text_lossLayerNormalize.set_max_length(100);
		text_lossLayerNormalize.set_text("");
		text_lossLayerNormalize.select_region(0, text_lossLayerNormalize.get_text_length());
//		m_grid_lossLayerType.attach(text_lossLayerNormalize,2,5,1,1);	
		text_lossLayerNormalize.show();

		label_lossLayerNormalize.set_text("Normalization: \n(select type)");
		label_lossLayerNormalize.set_line_wrap();
		label_lossLayerNormalize.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_lossLayerType.attach(label_lossLayerNormalize,0,6,2,1);
		label_lossLayerNormalize.show();
	
		button_setLossParameters.show();
	}
	else
	{
		label_lossLayerBottom1.hide();
		text_lossLayerBottom1.hide();
		label_lossLayerBottom2.hide();
		text_lossLayerBottom2.hide();
		label_lossLayerTop.hide();
		text_lossLayerTop.hide();
		label_lossLayerName.hide();
		text_lossLayerName.hide();
		label_lossLayerNormalize.hide();
		text_lossLayerNormalize.hide();
		button_setLossParameters.hide();
	}

	m_sw_lossLayerType.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
	m_grid_lossLayerType.show();
//	show_all_children();
	m_sw_lossLayerType.show();
}
