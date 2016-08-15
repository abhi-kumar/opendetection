#include "detectors/global2D/detection/ODConvClassification.h"

#include "common/pipeline/ObjectDetector.h"
#include "common/pipeline/ODDetection.h"
#include <iostream>
#include <fstream>

using namespace od;
using namespace std;

void help();

int main(int argc, char **argv)
{
	if (argc != 7) 
	{
		help();	
	}
	od::g2d::ODConvClassification *segnet_classifier = new od::g2d::ODConvClassification("");
	segnet_classifier->setWeightModelFileLocation(argv[1]);
	segnet_classifier->setNetworkModelFileLocation(argv[2]);
	segnet_classifier->setImageFileLocation(argv[3]);
	segnet_classifier->setImageGroundTruthFileLocation(argv[4]);
	segnet_classifier->setColorLocation(argv[5]);
	segnet_classifier->setSegnetLocation(argv[6]);
	for( int i = 1; i < argc; i++)
	{
		string check = argv[i];
		if(i == 1)
		{
			size_t found = check.find(".caffemodel");
			if(found > check.length())
			{
				cout << endl << "First argument should be caffe weight caffemodel file" << endl;
				help();
			}
		}
		else if(i==2)
		{
			size_t found = check.find(".prototxt");
			if(found > check.length())
			{
				cout << endl << "Second argument should be caffe network prototxt file" << endl;
				help();
			}
			
		}
		ifstream ifs;
		ifs.open(check.c_str());
		if(!ifs)
		{
			cout << endl << "File not found: " << check << endl;
			help();
		}
	}
	
	segnet_classifier->runSegnetBasedClassifierPythonMode();
	return 0;
}

void help()
{
	cout << endl << "Usage: ./examples/objectdetector/od_cnn_segnet_classification_python_mode <path to weight caffemodel file> <path to network file> <path to image file> <path to image ground truth file> <path to color file> <path to segnet caffe installation/compilation location>" << endl;
	cout << endl << "Example: ./examples/objectdetector/od_cnn_segnet_classification_python_mode ../examples/objectdetector/Segnet_Classify/segnet.caffemodel ../examples/objectdetector/Segnet_Classify/segnet.prototxt ../examples/objectdetector/Segnet_Classify/test_image.png ../examples/objectdetector/Segnet_Classify/test_image_gt.png ../examples/objectdetector/Segnet_Classify/color.png /home/abhi/Desktop/GSOC/target7/caffe-segnet-segnet-cleaned/" << endl << endl;
	exit(0);
}
