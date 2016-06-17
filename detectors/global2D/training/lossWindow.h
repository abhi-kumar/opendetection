#include "network.h"

void NetworkCreator::showWindow_lossLayerType(Glib::ustring data)
{
	remove();
	set_title("Loss Layer");
	set_border_width(10);
	add(m_sw_lossLayerType);
	m_grid_lossLayerType.set_column_spacing (10);
	m_grid_lossLayerType.set_row_spacing (50);

	title_lossLayerType.set_text("Will be updated soon");
	title_lossLayerType.set_line_wrap();
	title_lossLayerType.set_justify(Gtk::JUSTIFY_FILL);
//	m_grid_normalizationLayerType.attach(title_lossLayerType,0,0,2,1);
	title_lossLayerType.show();

	button_addMoreLayer4.show();

	m_sw_lossLayerType.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
	m_grid_lossLayerType.show();
//	show_all_children();
	m_sw_lossLayerType.show();
}
