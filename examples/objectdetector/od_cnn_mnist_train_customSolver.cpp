#include <detectors/global2D/training/ODConvTrainer.h>
#include "detectors/global2D/detection/ODConvClassification.h"

#include "common/pipeline/ObjectDetector.h"
#include "common/pipeline/ODDetection.h"


using namespace od;
using namespace std;

int main(int argc, char *argv[])
{
	argc = 1;
	od::g2d::ODConvTrainer *mnist_trainer = new od::g2d::ODConvTrainer("","");
	mnist_trainer->setSolverProperties(argc,argv);
	mnist_trainer->startTraining();
	return 0;
}
