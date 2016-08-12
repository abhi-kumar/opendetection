#include "ODAnnotator.h"

using namespace std;
using namespace cv;

namespace od
{
	namespace g2d
	{
		int ODAnnotator::train()
		{
			return 1;
		}
		void ODAnnotator::startAnnotator(int argc, char *argv[])
		{
			auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
			annotation Annotation;
			Annotation.set_default_geometry (10000, 10000);
			app->run(Annotation);
		}
	}
}			
