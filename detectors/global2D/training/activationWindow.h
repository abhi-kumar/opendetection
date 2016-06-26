#include "network.h"

void NetworkCreator::showWindow_activationLayerType(Glib::ustring data)
{
	
	remove();
	set_title("Activation Layer");
	set_border_width(10);
	add(m_sw_activationLayerType);
	m_grid_activationLayerType.set_column_spacing (10);
	m_grid_activationLayerType.set_row_spacing (50);

	//level 0
	if(data == "")
		title_activationLayerType.set_text("Set the Properties of Activation Layer type: AbsVal");
	else
		title_activationLayerType.set_text("Set the Properties of Activation Layer type: " + data);
	title_activationLayerType.set_line_wrap();
	title_activationLayerType.set_justify(Gtk::JUSTIFY_FILL);
//	m_grid_activationLayerType.attach(title_activationLayerType,0,0,2,1);
	title_activationLayerType.show();

	button_setActivationParameters.show();
	button_addMoreLayer.show();

	//level next
	if(data == "" or data == "AbsVal" or data == "PReLU" or data == "Sigmoid" or data == "TanH")
	{
/*		m_grid_activationLayerType.remove(label_activationLayerBottom);
		m_grid_activationLayerType.remove(label_activationLayerName);
		m_grid_activationLayerType.remove(label_activationLayerTop);
		m_grid_activationLayerType.remove(label_activationLayerScale);
		m_grid_activationLayerType.remove(label_activationLayerShift);
		m_grid_activationLayerType.remove(label_activationLayerBase);
		m_grid_activationLayerType.remove(label_activationLayerNegativeSlope);
		m_grid_activationLayerType.remove(text_activationLayerBottom);
		m_grid_activationLayerType.remove(text_activationLayerName);
		m_grid_activationLayerType.remove(text_activationLayerTop);
		m_grid_activationLayerType.remove(text_activationLayerScale);
		m_grid_activationLayerType.remove(text_activationLayerShift);
		m_grid_activationLayerType.remove(text_activationLayerBase);
		m_grid_activationLayerType.remove(text_activationLayerNegativeSlope);
//		m_grid_activationLayerType.remove(button_setActivationParameters);
//		m_grid_activationLayerType.remove(button_addMoreLayer);
*/		
		label_activationLayerBottom.hide();
		label_activationLayerName.hide();
		label_activationLayerTop.hide();
		label_activationLayerScale.hide();
		label_activationLayerShift.hide();
		label_activationLayerBase.hide();
		label_activationLayerNegativeSlope.hide();
		text_activationLayerBottom.hide();
		text_activationLayerName.hide();
		text_activationLayerTop.hide();
		text_activationLayerScale.hide();
		text_activationLayerShift.hide();
		text_activationLayerBase.hide();
		text_activationLayerNegativeSlope.hide();

		label_activationLayerBottom.set_text("Bottom Layer Name: ");
		label_activationLayerBottom.set_line_wrap();
		label_activationLayerBottom.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_activationLayerType.attach(label_activationLayerBottom,0,1,2,1);
		label_activationLayerBottom.show();

		text_activationLayerBottom.set_max_length(100);
		text_activationLayerBottom.set_text("");
		text_activationLayerBottom.select_region(0, text_activationLayerBottom.get_text_length());
//		m_grid_activationLayerType.attach(text_activationLayerBottom,2,1,1,1);	
		text_activationLayerBottom.show();

		label_activationLayerTop.set_text("Top Layer Name: ");
		label_activationLayerTop.set_line_wrap();
		label_activationLayerTop.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_activationLayerType.attach(label_activationLayerTop,0,2,2,1);
		label_activationLayerTop.show();

		text_activationLayerTop.set_max_length(100);
		text_activationLayerTop.set_text("");
		text_activationLayerTop.select_region(0, text_activationLayerTop.get_text_length());
//		m_grid_activationLayerType.attach(text_activationLayerTop,2,2,1,1);	
		text_activationLayerTop.show();

		label_activationLayerName.set_text("Current Layer Name: ");
		label_activationLayerName.set_line_wrap();
		label_activationLayerName.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_activationLayerType.attach(label_activationLayerName,0,3,2,1);
		label_activationLayerName.show();

		text_activationLayerName.set_max_length(100);
		text_activationLayerName.set_text("");
		text_activationLayerName.select_region(0, text_activationLayerName.get_text_length());
//		m_grid_activationLayerType.attach(text_activationLayerName,2,3,1,1);	
		text_activationLayerName.show();

	}
	else if(data == "ReLU")
	{
/*		m_grid_activationLayerType.remove(label_activationLayerBottom);
		m_grid_activationLayerType.remove(label_activationLayerName);
		m_grid_activationLayerType.remove(label_activationLayerTop);
		m_grid_activationLayerType.remove(label_activationLayerScale);
		m_grid_activationLayerType.remove(label_activationLayerShift);
		m_grid_activationLayerType.remove(label_activationLayerBase);
		m_grid_activationLayerType.remove(label_activationLayerNegativeSlope);
		m_grid_activationLayerType.remove(text_activationLayerBottom);
		m_grid_activationLayerType.remove(text_activationLayerName);
		m_grid_activationLayerType.remove(text_activationLayerTop);
		m_grid_activationLayerType.remove(text_activationLayerScale);
		m_grid_activationLayerType.remove(text_activationLayerShift);
		m_grid_activationLayerType.remove(text_activationLayerBase);
		m_grid_activationLayerType.remove(text_activationLayerNegativeSlope);
//		m_grid_activationLayerType.remove(button_setActivationParameters);
//		m_grid_activationLayerType.remove(button_addMoreLayer);
*/		
		label_activationLayerBottom.hide();
		label_activationLayerName.hide();
		label_activationLayerTop.hide();
		label_activationLayerScale.hide();
		label_activationLayerShift.hide();
		label_activationLayerBase.hide();
		label_activationLayerNegativeSlope.hide();
		text_activationLayerBottom.hide();
		text_activationLayerName.hide();
		text_activationLayerTop.hide();
		text_activationLayerScale.hide();
		text_activationLayerShift.hide();
		text_activationLayerBase.hide();
		text_activationLayerNegativeSlope.hide();

		label_activationLayerBottom.set_text("Bottom Layer Name: ");
		label_activationLayerBottom.set_line_wrap();
		label_activationLayerBottom.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_activationLayerType.attach(label_activationLayerBottom,0,1,2,1);
		label_activationLayerBottom.show();

		text_activationLayerBottom.set_max_length(100);
		text_activationLayerBottom.set_text("");
		text_activationLayerBottom.select_region(0, text_activationLayerBottom.get_text_length());
//		m_grid_activationLayerType.attach(text_activationLayerBottom,2,1,1,1);	
		text_activationLayerBottom.show();

		label_activationLayerTop.set_text("Top Layer Name: ");
		label_activationLayerTop.set_line_wrap();
		label_activationLayerTop.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_activationLayerType.attach(label_activationLayerTop,0,2,2,1);
		label_activationLayerTop.show();

		text_activationLayerTop.set_max_length(100);
		text_activationLayerTop.set_text("");
		text_activationLayerTop.select_region(0, text_activationLayerTop.get_text_length());
//		m_grid_activationLayerType.attach(text_activationLayerTop,2,2,1,1);	
		text_activationLayerTop.show();

		label_activationLayerName.set_text("Current Layer Name: ");
		label_activationLayerName.set_line_wrap();
		label_activationLayerName.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_activationLayerType.attach(label_activationLayerName,0,3,2,1);
		label_activationLayerName.show();

		text_activationLayerName.set_max_length(100);
		text_activationLayerName.set_text("");
		text_activationLayerName.select_region(0, text_activationLayerName.get_text_length());
//		m_grid_activationLayerType.attach(text_activationLayerName,2,3,1,1);	
		text_activationLayerName.show();

		label_activationLayerNegativeSlope.set_text("Relu Param Negative Slope: ");
		label_activationLayerNegativeSlope.set_line_wrap();
		label_activationLayerNegativeSlope.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_activationLayerType.attach(label_activationLayerNegativeSlope,0,4,2,1);
		label_activationLayerNegativeSlope.show();

		text_activationLayerNegativeSlope.set_max_length(100);
		text_activationLayerNegativeSlope.set_text("0");
		text_activationLayerNegativeSlope.select_region(0, text_activationLayerNegativeSlope.get_text_length());
//		m_grid_activationLayerType.attach(text_activationLayerNegativeSlope,2,4,1,1);	
		text_activationLayerNegativeSlope.show();
/*
		button_setActivationParameters.signal_clicked().connect(sigc::bind<Glib::ustring>(
		      sigc::mem_fun(*this, &NetworkCreator::on_button_clicked), "setActivationParameters"));
		m_grid_activationLayerType.attach(button_setActivationParameters,0,5,2,1);
		button_setActivationParameters.show();

		button_addMoreLayer.signal_clicked().connect(sigc::bind<Glib::ustring>(
		      sigc::mem_fun(*this, &NetworkCreator::on_button_clicked), "addMoreLayer"));
		m_grid_activationLayerType.attach(button_addMoreLayer,2,5,1,1);
		button_addMoreLayer.show();
*/	}
	else if(data == "Exp" or data == "Log")
	{
/*		m_grid_activationLayerType.remove(label_activationLayerBottom);
		m_grid_activationLayerType.remove(label_activationLayerName);
		m_grid_activationLayerType.remove(label_activationLayerTop);
		m_grid_activationLayerType.remove(label_activationLayerScale);
		m_grid_activationLayerType.remove(label_activationLayerShift);
		m_grid_activationLayerType.remove(label_activationLayerBase);
		m_grid_activationLayerType.remove(label_activationLayerNegativeSlope);
		m_grid_activationLayerType.remove(text_activationLayerBottom);
		m_grid_activationLayerType.remove(text_activationLayerName);
		m_grid_activationLayerType.remove(text_activationLayerTop);
		m_grid_activationLayerType.remove(text_activationLayerScale);
		m_grid_activationLayerType.remove(text_activationLayerShift);
		m_grid_activationLayerType.remove(text_activationLayerBase);
		m_grid_activationLayerType.remove(text_activationLayerNegativeSlope);
//		m_grid_activationLayerType.remove(button_setActivationParameters);
//		m_grid_activationLayerType.remove(button_addMoreLayer);
*/		
		label_activationLayerBottom.hide();
		label_activationLayerName.hide();
		label_activationLayerTop.hide();
		label_activationLayerScale.hide();
		label_activationLayerShift.hide();
		label_activationLayerBase.hide();
		label_activationLayerNegativeSlope.hide();
		text_activationLayerBottom.hide();
		text_activationLayerName.hide();
		text_activationLayerTop.hide();
		text_activationLayerScale.hide();
		text_activationLayerShift.hide();
		text_activationLayerBase.hide();
		text_activationLayerNegativeSlope.hide();
		
		label_activationLayerBottom.set_text("Bottom Layer Name: ");
		label_activationLayerBottom.set_line_wrap();
		label_activationLayerBottom.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_activationLayerType.attach(label_activationLayerBottom,0,1,2,1);
		label_activationLayerBottom.show();

		text_activationLayerBottom.set_max_length(100);
		text_activationLayerBottom.set_text("");
		text_activationLayerBottom.select_region(0, text_activationLayerBottom.get_text_length());
//		m_grid_activationLayerType.attach(text_activationLayerBottom,2,1,1,1);	
		text_activationLayerBottom.show();

		label_activationLayerTop.set_text("Top Layer Name: ");
		label_activationLayerTop.set_line_wrap();
		label_activationLayerTop.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_activationLayerType.attach(label_activationLayerTop,0,2,2,1);
		label_activationLayerTop.show();

		text_activationLayerTop.set_max_length(100);
		text_activationLayerTop.set_text("");
		text_activationLayerTop.select_region(0, text_activationLayerTop.get_text_length());
//		m_grid_activationLayerType.attach(text_activationLayerTop,2,2,1,1);	
		text_activationLayerTop.show();

		label_activationLayerName.set_text("Current Layer Name: ");
		label_activationLayerName.set_line_wrap();
		label_activationLayerName.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_activationLayerType.attach(label_activationLayerName,0,3,2,1);
		label_activationLayerName.show();

		text_activationLayerName.set_max_length(100);
		text_activationLayerName.set_text("");
		text_activationLayerName.select_region(0, text_activationLayerName.get_text_length());
//		m_grid_activationLayerType.attach(text_activationLayerName,2,3,1,1);	
		text_activationLayerName.show();

		label_activationLayerScale.set_text("Layer Parameter Scale: ");
		label_activationLayerScale.set_line_wrap();
		label_activationLayerScale.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_activationLayerType.attach(label_activationLayerScale,0,4,2,1);
		label_activationLayerScale.show();

		text_activationLayerScale.set_max_length(100);
		text_activationLayerScale.set_text("1");
		text_activationLayerScale.select_region(0, text_activationLayerScale.get_text_length());
//		m_grid_activationLayerType.attach(text_activationLayerScale,2,4,1,1);	
		text_activationLayerScale.show();

		label_activationLayerShift.set_text("Layer Parameter Shift: ");
		label_activationLayerShift.set_line_wrap();
		label_activationLayerShift.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_activationLayerType.attach(label_activationLayerShift,0,5,2,1);
		label_activationLayerShift.show();

		text_activationLayerShift.set_max_length(100);
		text_activationLayerShift.set_text("0");
		text_activationLayerShift.select_region(0, text_activationLayerShift.get_text_length());
//		m_grid_activationLayerType.attach(text_activationLayerShift,2,5,1,1);	
		text_activationLayerShift.show();

		label_activationLayerBase.set_text("Layer Parameter Base: ");
		label_activationLayerBase.set_line_wrap();
		label_activationLayerBase.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_activationLayerType.attach(label_activationLayerBase,0,6,2,1);
		label_activationLayerBase.show();

		text_activationLayerBase.set_max_length(100);
		text_activationLayerBase.set_text("-1");
		text_activationLayerBase.select_region(0, text_activationLayerBase.get_text_length());
//		m_grid_activationLayerType.attach(text_activationLayerBase,2,6,1,1);	
		text_activationLayerBase.show();
/*
		button_setActivationParameters.signal_clicked().connect(sigc::bind<Glib::ustring>(
		      sigc::mem_fun(*this, &NetworkCreator::on_button_clicked), "setActivationParameters"));
		m_grid_activationLayerType.attach(button_setActivationParameters,0,7,2,1);
		button_setActivationParameters.show();

		button_addMoreLayer.signal_clicked().connect(sigc::bind<Glib::ustring>(
		      sigc::mem_fun(*this, &NetworkCreator::on_button_clicked), "addMoreLayer"));
		m_grid_activationLayerType.attach(button_addMoreLayer,2,7,1,1);
		button_addMoreLayer.show();
*/	}
	else if(data == "Power")
	{
/*		m_grid_activationLayerType.remove(label_activationLayerBottom);
		m_grid_activationLayerType.remove(label_activationLayerName);
		m_grid_activationLayerType.remove(label_activationLayerTop);
		m_grid_activationLayerType.remove(label_activationLayerScale);
		m_grid_activationLayerType.remove(label_activationLayerShift);
		m_grid_activationLayerType.remove(label_activationLayerBase);
		m_grid_activationLayerType.remove(label_activationLayerNegativeSlope);
		m_grid_activationLayerType.remove(text_activationLayerBottom);
		m_grid_activationLayerType.remove(text_activationLayerName);
		m_grid_activationLayerType.remove(text_activationLayerTop);
		m_grid_activationLayerType.remove(text_activationLayerScale);
		m_grid_activationLayerType.remove(text_activationLayerShift);
		m_grid_activationLayerType.remove(text_activationLayerBase);
		m_grid_activationLayerType.remove(text_activationLayerNegativeSlope);
//		m_grid_activationLayerType.remove(button_setActivationParameters);
//		m_grid_activationLayerType.remove(button_addMoreLayer);
*/		
		label_activationLayerBottom.hide();
		label_activationLayerName.hide();
		label_activationLayerTop.hide();
		label_activationLayerScale.hide();
		label_activationLayerShift.hide();
		label_activationLayerBase.hide();
		label_activationLayerNegativeSlope.hide();
		text_activationLayerBottom.hide();
		text_activationLayerName.hide();
		text_activationLayerTop.hide();
		text_activationLayerScale.hide();
		text_activationLayerShift.hide();
		text_activationLayerBase.hide();
		text_activationLayerNegativeSlope.hide();
		
		label_activationLayerBottom.set_text("Bottom Layer Name: ");
		label_activationLayerBottom.set_line_wrap();
		label_activationLayerBottom.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_activationLayerType.attach(label_activationLayerBottom,0,1,2,1);
		label_activationLayerBottom.show();

		text_activationLayerBottom.set_max_length(100);
		text_activationLayerBottom.set_text("");
		text_activationLayerBottom.select_region(0, text_activationLayerBottom.get_text_length());
//		m_grid_activationLayerType.attach(text_activationLayerBottom,2,1,1,1);	
		text_activationLayerBottom.show();

		label_activationLayerTop.set_text("Top Layer Name: ");
		label_activationLayerTop.set_line_wrap();
		label_activationLayerTop.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_activationLayerType.attach(label_activationLayerTop,0,2,2,1);
		label_activationLayerTop.show();

		text_activationLayerTop.set_max_length(100);
		text_activationLayerTop.set_text("");
		text_activationLayerTop.select_region(0, text_activationLayerTop.get_text_length());
//		m_grid_activationLayerType.attach(text_activationLayerTop,2,2,1,1);	
		text_activationLayerTop.show();

		label_activationLayerName.set_text("Current Layer Name: ");
		label_activationLayerName.set_line_wrap();
		label_activationLayerName.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_activationLayerType.attach(label_activationLayerName,0,3,2,1);
		label_activationLayerName.show();

		text_activationLayerName.set_max_length(100);
		text_activationLayerName.set_text("");
		text_activationLayerName.select_region(0, text_activationLayerName.get_text_length());
//		m_grid_activationLayerType.attach(text_activationLayerName,2,3,1,1);	
		text_activationLayerName.show();

		label_activationLayerScale.set_text("Layer Parameter Scale: ");
		label_activationLayerScale.set_line_wrap();
		label_activationLayerScale.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_activationLayerType.attach(label_activationLayerScale,0,4,2,1);
		label_activationLayerScale.show();

		text_activationLayerScale.set_max_length(100);
		text_activationLayerScale.set_text("1");
		text_activationLayerScale.select_region(0, text_activationLayerScale.get_text_length());
//		m_grid_activationLayerType.attach(text_activationLayerScale,2,4,1,1);	
		text_activationLayerScale.show();

		label_activationLayerShift.set_text("Layer Parameter Shift: ");
		label_activationLayerShift.set_line_wrap();
		label_activationLayerShift.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_activationLayerType.attach(label_activationLayerShift,0,5,2,1);
		label_activationLayerShift.show();

		text_activationLayerShift.set_max_length(100);
		text_activationLayerShift.set_text("0");
		text_activationLayerShift.select_region(0, text_activationLayerShift.get_text_length());
//		m_grid_activationLayerType.attach(text_activationLayerShift,2,5,1,1);	
		text_activationLayerShift.show();

		label_activationLayerBase.set_text("Layer Parameter Power: ");
		label_activationLayerBase.set_line_wrap();
		label_activationLayerBase.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_activationLayerType.attach(label_activationLayerBase,0,6,2,1);
		label_activationLayerBase.show();

		text_activationLayerBase.set_max_length(100);
		text_activationLayerBase.set_text("1");
		text_activationLayerBase.select_region(0, text_activationLayerBase.get_text_length());
//		m_grid_activationLayerType.attach(text_activationLayerBase,2,6,1,1);	
		text_activationLayerBase.show();
/*
		button_setActivationParameters.signal_clicked().connect(sigc::bind<Glib::ustring>(
		      sigc::mem_fun(*this, &NetworkCreator::on_button_clicked), "setActivationParameters"));
		m_grid_activationLayerType.attach(button_setActivationParameters,0,7,2,1);
		button_setActivationParameters.show();

		button_addMoreLayer.signal_clicked().connect(sigc::bind<Glib::ustring>(
		      sigc::mem_fun(*this, &NetworkCreator::on_button_clicked), "addMoreLayer"));
		m_grid_activationLayerType.attach(button_addMoreLayer,2,7,1,1);
		button_addMoreLayer.show();	
*/	}
/*	else
	{
		m_grid_activationLayerType.remove(label_activationLayerBottom);
		m_grid_activationLayerType.remove(label_activationLayerName);
		m_grid_activationLayerType.remove(label_activationLayerTop);
		m_grid_activationLayerType.remove(label_activationLayerScale);
		m_grid_activationLayerType.remove(label_activationLayerShift);
		m_grid_activationLayerType.remove(label_activationLayerBase);
		m_grid_activationLayerType.remove(label_activationLayerNegativeSlope);
		m_grid_activationLayerType.remove(text_activationLayerBottom);
		m_grid_activationLayerType.remove(text_activationLayerName);
		m_grid_activationLayerType.remove(text_activationLayerTop);
		m_grid_activationLayerType.remove(text_activationLayerScale);
		m_grid_activationLayerType.remove(text_activationLayerShift);
		m_grid_activationLayerType.remove(text_activationLayerBase);
		m_grid_activationLayerType.remove(text_activationLayerNegativeSlope);
		m_grid_activationLayerType.remove(button_setActivationParameters);
		m_grid_activationLayerType.remove(button_addMoreLayer);


		button_setActivationParameters.signal_clicked().connect(sigc::bind<Glib::ustring>(
		      sigc::mem_fun(*this, &NetworkCreator::on_button_clicked), "setActivationParameters"));
		m_grid_activationLayerType.attach(button_setActivationParameters,0,1,7,1);
		button_setActivationParameters.show();

		button_addMoreLayer.signal_clicked().connect(sigc::bind<Glib::ustring>(
		      sigc::mem_fun(*this, &NetworkCreator::on_button_clicked), "addMoreLayer"));
		m_grid_activationLayerType.attach(button_addMoreLayer,2,1,7,1);
		button_addMoreLayer.show();
	}
*/	
//	m_sw_activationLayerType.add(m_grid_activationLayerType);
	m_sw_activationLayerType.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
	m_grid_activationLayerType.show();
//	show_all_children();
	m_sw_activationLayerType.show();
}
