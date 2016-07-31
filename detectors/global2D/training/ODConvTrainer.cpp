#include "ODConvTrainer.h"

using namespace caffe;
using namespace std;
using namespace cv;

namespace od
{
	namespace g2d
	{
		int ODConvTrainer::train()
		{
			return 1;
		}
		
		void ODConvTrainer::setSolverLocation(string location)
		{
			ODConvTrainer::solverLocation = location;	
		}
		
		void ODConvTrainer::setSolverProperties(int argc, char *argv[])
		{
			auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
			SolverProperties solverProperties;
			solverProperties.set_default_geometry (10000, 10000);
			app->run(solverProperties);
			ODConvTrainer::solverLocation = solverProperties.solverFileName;
		}

		void ODConvTrainer::startTraining()
		{
			Caffe::set_mode(Caffe::CPU);
			SGDSolver<float> s(solverLocation);
			s.Solve();
		}

		
	}
}
