#include "ODAnnotation.h"

void annotation::showWindow_main()
{
	storage = 0;
	storageROILocation.clear();
	storageROILocationCurrent.clear();
	storageFileName.clear();
	imageFileNames.clear();
	widthMultiplier.clear();
	heightMultiplier.clear();
	currentWindow = "mainWindow";
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
