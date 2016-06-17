#include "network.h"

void NetworkCreator::showWindow_displayWindow()
{
	remove();
	set_title("Display Entire Network");
	set_border_width(10);
	add(box_fullCnnLayerMatter);
	buffer_fullCnnLayerMatter->set_text(fullCnnLayerMatter);
	textView_fullCnnLayerMatter.set_buffer(buffer_fullCnnLayerMatter);
	show_all_children();
}


