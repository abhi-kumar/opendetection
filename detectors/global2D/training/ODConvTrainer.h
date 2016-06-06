#ifndef OPENDETECTION_ODCONVTRAINER_H
#define OPENDETECTION_ODCONVTRAINER_H


#include "common/pipeline/ODTrainer.h"
#include "common/utils/utils.h"
#include <opencv2/opencv.hpp>

#include <cstring>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include "caffe/caffe.hpp"
#include "caffe/util/io.hpp"
#include "caffe/blob.hpp"
#include "caffe/solver.hpp"
#include "caffe/sgd_solvers.hpp"

#include "solver.h"

using namespace caffe;
using namespace std;
using namespace cv;

namespace od
{
	namespace g2d
	{
		class ODConvTrainer : public ODTrainer
		{
			public:
				ODConvTrainer(std::string const &training_input_location_ = "", std::string const &trained_data_location_ = ""):ODTrainer(training_input_location_, trained_data_location_){}

				int train();
				void init(){}
				void setSolverLocation(string location);
				void setSolverProperties(int argc, char *argv[]);
				void startTraining();

			private:
				string solverLocation;
		};
	}
}


#endif //OPENDETECTION_ODCONVTRAINER_H
