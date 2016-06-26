#include "network.h"

void NetworkCreator::showWindow_normalizationLayerType(Glib::ustring data)
{
	remove();
	set_title("Normalization Layer");
	set_border_width(10);
	add(m_sw_normalizationLayerType);
	m_grid_normalizationLayerType.set_column_spacing (10);
	m_grid_normalizationLayerType.set_row_spacing (50);

	title_normalizationLayerType.set_text("Will be updated soon");
	title_normalizationLayerType.set_line_wrap();
	title_normalizationLayerType.set_justify(Gtk::JUSTIFY_FILL);
//	m_grid_normalizationLayerType.attach(title_normalizationLayerType,0,0,2,1);
	title_normalizationLayerType.show();

	button_addMoreLayer3.show();

	m_sw_normalizationLayerType.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
	m_grid_normalizationLayerType.show();
//	show_all_children();
	m_sw_normalizationLayerType.show();
}
