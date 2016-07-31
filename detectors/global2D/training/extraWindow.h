#include "network.h"

void NetworkCreator::showWindow_extraLayerType(Glib::ustring data)
{
	remove();
	set_title("Extra Layer");
	set_border_width(10);
	add(m_sw_extraLayerType);
	m_grid_extraLayerType.set_column_spacing (10);
	m_grid_extraLayerType.set_row_spacing (50);

	title_extraLayerType.set_text("Will be updated soon");
	title_extraLayerType.set_line_wrap();
	title_extraLayerType.set_justify(Gtk::JUSTIFY_FILL);
//	m_grid_extraLayerType.attach(title_extraLayerType,0,0,2,1);
	title_extraLayerType.show();

	button_addMoreLayer5.show();

	m_sw_extraLayerType.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
	m_grid_extraLayerType.show();
//	show_all_children();
	m_sw_extraLayerType.show();
}
