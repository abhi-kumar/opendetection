/*
Author: Abhishek Kumar Annamraju
Release Date: 01/06/2016
*/


#ifndef OPENDETECTION_ODCONVCLASSIFICATION_H
#define OPENDETECTION_ODCONVCLASSIFICATION_H

#include "common/pipeline/ODDetector.h"
#include "common/pipeline/ODScene.h"
#include "common/utils/utils.h"
#include "common/utils/ODFeatureDetector2D.h"


#include <opencv2/opencv.hpp>

#include <cstring>
#include <cstdlib>
#include <vector>

#include <string>
#include <iostream>
#include <stdio.h>
#include "caffe/caffe.hpp"
#include "caffe/util/io.hpp"
#include "caffe/blob.hpp"

using namespace caffe;
using namespace std;
using namespace cv;

namespace od
{
	namespace g2d
	{
		class ODConvClassification : public ODDetector2D
		{
			public:				
				void setWeightModelFileLocation(string location);
				void setNetworkModelFileLocation(string location);
				void setImageFileLocation(string location);
				string getWeightModelFileLocation();
				string getNetworkModelFileLocation();
				string getImageFileLocation();
				void setTestBlob(int numChannels, int imgHeight, int imgWidth);				
				void classify();

				void init();
				ODDetections2D *detectOmni(ODSceneImage *scene);
      				ODDetections *detect(ODSceneImage *scene);
				ODConvClassification(std::string const &trained_data_location_ = ""):ODDetector2D(trained_data_location_){}
        			

				string weightModelFileLoaction;
				string networkFileLocation;
				string imageFileLocation; 
				Datum strucBlob;
				BlobProto protoBlob;
				vector<Blob<float>*> inputBlob;

		};	
	}
}


#endif //OPENDETECTION_ODCONVCLASSIFICATION_H
