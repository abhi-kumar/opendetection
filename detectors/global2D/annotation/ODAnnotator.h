#ifndef OPENDETECTION_ODANNOTATOR_H
#define OPENDETECTION_ODANNOTATOR_H


#include "common/pipeline/ODTrainer.h"
#include "common/utils/utils.h"
#include <iostream>
#include <stdio.h>

#include "ODAnnotation.h"

using namespace std;
using namespace cv;

namespace od
{
	namespace g2d
	{
		class ODAnnotator : public ODTrainer
		{
			public:
				ODAnnotator(std::string const &training_input_location_ = "", std::string const &trained_data_location_ = ""):ODTrainer(training_input_location_, trained_data_location_){}

				int train();
				void init(){}
				void startAnnotator(int argc, char *argv[]);
		};
	}
}

#endif
