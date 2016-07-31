#include "detectors/global2D/detection/ODConvClassification.h"
#include "common/utils/ODFrameGenerator.h"

#include "common/pipeline/ObjectDetector.h"
#include "common/pipeline/ODDetection.h"
#include <iostream>
#include <fstream>

using namespace od;
using namespace std;

void help();

int main(int argc, char **argv)
{
	if (argc != 4) 
	{
		help();	
	}
	od::g2d::ODConvClassification *mnist_classifier = new od::g2d::ODConvClassification("");
	mnist_classifier->setWeightModelFileLocation(argv[1]);
	mnist_classifier->setNetworkModelFileLocation(argv[2]);
	mnist_classifier->setImageFileLocation(argv[3]);
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
	string weight_file_location = mnist_classifier->getWeightModelFileLocation();
	string network_file_location = mnist_classifier->getNetworkModelFileLocation();
	string image_file_location = mnist_classifier->getImageFileLocation();

	mnist_classifier->setTestBlob(1,28,28);
	mnist_classifier->classify();

	return 0;
}

void help()
{
	cout << endl << "Usage: ./examples/objectdetector/od_cnn_mnist_classification <path to weight caffemodel file> <path to network file> <path to image file>" << endl;
	cout << endl << "Example: ./examples/objectdetector/od_cnn_mnist_classification ../examples/objectdetector/Mnist_Classify/mnist.caffemodel ../examples/objectdetector/Mnist_Classify/lenet.prototxt ../examples/objectdetector/Mnist_Classify/3.png" << endl << endl;
	exit(0);
}
