#include "network.h"

void NetworkCreator::showWindow_main()
{
	remove();
	set_title("Network Creator");
	set_border_width(10);
	add(m_sw1);
	m_grid1.set_column_spacing (10);
	m_grid1.set_row_spacing (50);
//	m_sw1.add(m_grid1);
	m_sw1.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
//	m_grid1.show();
	show_all_children();
	m_sw1.show();	
}


void NetworkCreator::on_cell_data_extra(const Gtk::TreeModel::const_iterator& iter)
{
	// level 1
	auto row_activationLayerType = *iter;
	const Glib::ustring extra_activationLayerType = row_activationLayerType[column_activationLayerType.m_col_extra];
	if(extra_activationLayerType.empty())
		cell_activationLayerType.property_text() = "(none)";
	else
		cell_activationLayerType.property_text() = "-" + extra_activationLayerType + "-";
	cell_activationLayerType.property_foreground() = "green";

	// level 2
	auto row_criticalLayerType = *iter;
	const Glib::ustring extra_criticalLayerType = row_criticalLayerType[column_criticalLayerType.m_col_extra];
	if(extra_criticalLayerType.empty())
		cell_criticalLayerType.property_text() = "(none)";
	else
		cell_criticalLayerType.property_text() = "-" + extra_criticalLayerType + "-";
	cell_criticalLayerType.property_foreground() = "red";

	// level 3
	auto row_normalizationLayerType = *iter;
	const Glib::ustring extra_normalizationLayerType = row_normalizationLayerType[column_normalizationLayerType.m_col_extra];
	if(extra_normalizationLayerType.empty())
		cell_normalizationLayerType.property_text() = "(none)";
	else
		cell_normalizationLayerType.property_text() = "-" + extra_normalizationLayerType + "-";
	cell_normalizationLayerType.property_foreground() = "blue";

	// level 4
	auto row_lossLayerType = *iter;
	const Glib::ustring extra_lossLayerType = row_lossLayerType[column_lossLayerType.m_col_extra];
	if(extra_lossLayerType.empty())
		cell_lossLayerType.property_text() = "(none)";
	else
		cell_lossLayerType.property_text() = "-" + extra_lossLayerType + "-";
	cell_lossLayerType.property_foreground() = "brown";

	// level 5
	auto row_extraLayerType = *iter;
	const Glib::ustring extra_extraLayerType = row_extraLayerType[column_extraLayerType.m_col_extra];
	if(extra_extraLayerType.empty())
		cell_extraLayerType.property_text() = "(none)";
	else
		cell_extraLayerType.property_text() = "-" + extra_extraLayerType + "-";
	cell_extraLayerType.property_foreground() = "purple";

}

void NetworkCreator::on_combo_changed()
{
	Gtk::TreeModel::iterator iter_activationLayerType = combo_activationLayerType.get_active();
	Gtk::TreeModel::iterator iter_criticalLayerType = combo_criticalLayerType.get_active();
	Gtk::TreeModel::iterator iter_normalizationLayerType = combo_normalizationLayerType.get_active();
	Gtk::TreeModel::iterator iter_lossLayerType = combo_lossLayerType.get_active();
	Gtk::TreeModel::iterator iter_extraLayerType = combo_extraLayerType.get_active();
	

	// level 1
	if(iter_activationLayerType)
	{
		Gtk::TreeModel::Row row_activationLayerType = *iter_activationLayerType;
		if(row_activationLayerType)
		{
			int id_activationLayerType = row_activationLayerType[column_activationLayerType.m_col_id];
			Glib::ustring name_activationLayerType = row_activationLayerType[column_activationLayerType.m_col_name];
//			std::cout << " ID=" << id_activationLayerType << ", name=" << name_activationLayerType << std::endl;
			activationLayerTypeData = name_activationLayerType;
		}
		
	}
	
	//level 2
	if(iter_criticalLayerType)
	{
		Gtk::TreeModel::Row row_criticalLayerType = *iter_criticalLayerType;
	 	if(row_criticalLayerType)
		{
			int id_criticalLayerType = row_criticalLayerType[column_criticalLayerType.m_col_id];
			Glib::ustring name_criticalLayerType = row_criticalLayerType[column_criticalLayerType.m_col_name];
//			std::cout << " ID=" << id_criticalLayerType << ", name=" << name_criticalLayerType << std::endl;
			criticalLayerTypeData = name_criticalLayerType;
		}
	}

	// level 3
	if(iter_normalizationLayerType)
	{
		Gtk::TreeModel::Row row_normalizationLayerType = *iter_normalizationLayerType;
	 	if(row_normalizationLayerType)
		{
			int id_normalizationLayerType = row_normalizationLayerType[column_normalizationLayerType.m_col_id];
			Glib::ustring name_normalizationLayerType = row_normalizationLayerType[column_normalizationLayerType.m_col_name];
//			std::cout << " ID=" << id_normalizationLayerType << ", name=" << name_normalizationLayerType << std::endl;
			normalizationLayerTypeData = name_normalizationLayerType;
		}
	}

	// level 4
	if(iter_lossLayerType)
	{
		Gtk::TreeModel::Row row_lossLayerType = *iter_lossLayerType;
	 	if(row_lossLayerType)
		{
			int id_lossLayerType = row_lossLayerType[column_lossLayerType.m_col_id];
			Glib::ustring name_lossLayerType = row_lossLayerType[column_lossLayerType.m_col_name];
//			std::cout << " ID=" << id_lossLayerType << ", name=" << name_lossLayerType << std::endl;
			lossLayerTypeData = name_lossLayerType;
		}
	}

	// level 5
	if(iter_extraLayerType)
	{
		Gtk::TreeModel::Row row_extraLayerType = *iter_extraLayerType;
	 	if(row_extraLayerType)
		{
			int id_extraLayerType = row_extraLayerType[column_extraLayerType.m_col_id];
			Glib::ustring name_extraLayerType = row_extraLayerType[column_extraLayerType.m_col_name];
//			std::cout << " ID=" << id_extraLayerType << ", name=" << name_extraLayerType << std::endl;
			extraLayerTypeData = name_extraLayerType;
		}
	}
	
	else
		std::cout << "invalid iter" << std::endl;
}

