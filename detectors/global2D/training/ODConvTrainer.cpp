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
		
		void ODConvTrainer::startTraining()
		{
			Caffe::set_mode(Caffe::CPU);
			SGDSolver<float> s(solverLocation);
			s.Solve();
		}
	}
}
