#include "network.h"

void NetworkCreator::showWindow_displayWindow()
{
	remove();
	set_title("Display Entire Network");
	set_border_width(10);
	add(box_fullCnnLayerMatter);
	buffer_fullCnnLayerMatter->set_text(fullCnnLayerMatter);
	textView_fullCnnLayerMatter.set_buffer(buffer_fullCnnLayerMatter);

	ref_currentLayers->clear();
	combo_currentLayers.set_model(ref_currentLayers);
	Gtk::TreeModel::Row row_currentLayers = *(ref_currentLayers->append());
	row_currentLayers[column_currentLayers.m_col_id] = 0;
	row_currentLayers[column_currentLayers.m_col_name] = "Layers";
	row_currentLayers[column_currentLayers.m_col_extra] = "All Layers";
	combo_currentLayers.set_active(row_currentLayers);
	for(int i = 0; i < numLayers; i++)
	{
		Gtk::TreeModel::Row row_currentLayers = *(ref_currentLayers->append());
		row_currentLayers[column_currentLayers.m_col_id] = i + 1;
		row_currentLayers[column_currentLayers.m_col_name] = fullCnnLayersName[i];
	}

	
	
	
	show_all_children();
}


