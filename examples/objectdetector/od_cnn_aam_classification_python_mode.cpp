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
	if (argc != 5) 
	{
		help();	
	}
	od::g2d::ODConvClassification *aam_classifier = new od::g2d::ODConvClassification("");
	aam_classifier->setWeightModelFileLocation(argv[1]);
	aam_classifier->setNetworkModelFileLocation(argv[2]);
	aam_classifier->setImageFileLocation(argv[3]);
	aam_classifier->setOutputFileLocation(argv[4]);
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
		if(i!=4)
		{
			ifs.open(check.c_str());
			if(!ifs)
			{
				cout << endl << "File not found: " << check << endl;
				help();
			}
		}
	}
	aam_classifier->runMultiClassClassifierPythonMode();

	return 0;
}

void help()
{
	cout << endl << "Usage: ./examples/objectdetector/od_cnn_aam_classification_python_mode <path to weight caffemodel file> <path to network file> <path to image file> <path to output text file>" << endl;
	cout << endl << "Example: ./examples/objectdetector/od_cnn_aam_classification_python_mode ../examples/objectdetector/AAM_Classify/aam.caffemodel ../examples/objectdetector/AAM_Classify/aam.prototxt ../examples/objectdetector/AAM_Classify/3.png ../examples/objectdetector/AAM_Classify/output.txt" << endl << endl;
	exit(0);
}
