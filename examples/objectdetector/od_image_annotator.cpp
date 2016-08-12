#include "detectors/global2D/annotation/ODAnnotator.h"
#include "common/utils/ODFrameGenerator.h"

#include "common/pipeline/ObjectDetector.h"
#include "common/pipeline/ODDetection.h"
using namespace od;
using namespace std;

int main (int argc, char *argv[])
{
	argc = 1;
	od::g2d::ODAnnotator *annotator = new od::g2d::ODAnnotator("","");
	annotator->startAnnotator(argc,argv);
	return 0;
}
