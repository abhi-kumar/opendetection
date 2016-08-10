
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
#include <algorithm>
#include <iosfwd>
#include <memory>
#include <string>
#include <utility>
#include <vector>


using namespace caffe;
using namespace std;
using namespace cv;
using std::string;

namespace od
{
	namespace g2d
	{
		class ODConvClassification : public ODDetector2D
		{
			public:		
				//Initialization
				void init();
				ODDetections2D *detectOmni(ODSceneImage *scene);
      				ODDetections *detect(ODSceneImage *scene);
				ODConvClassification(std::string const &trained_data_location_ = ""):ODDetector2D(trained_data_location_){}
				void setWeightModelFileLocation(string location);
				void setNetworkModelFileLocation(string location);
				void setImageFileLocation(string location);
				void setOutputFileLocation(string location);
				string getWeightModelFileLocation();
				string getNetworkModelFileLocation();
				string getImageFileLocation();

				
				//Single class classification		
				void setTestBlob(int numChannels, int imgHeight, int imgWidth);				
				void classify();
				std::vector<float> classifyMultiLabel();
        			string weightModelFileLoaction;
				string networkFileLocation;
				string imageFileLocation; 
				string outputFileLocation; 
				Datum strucBlob;
				BlobProto protoBlob;
				vector<Blob<float>*> inputBlob;

				

				//Multiclass classification . Note: Code Partially taken from caffe library
				std::vector<float> runMultiClassClassifier();
				void runMultiClassClassifierPythonMode();
				std::vector<float> Predict(const cv::Mat& img);
				void WrapInputLayer(std::vector<cv::Mat>* input_channels); 
			
			private:
				cv::Size input_geometry_;
				int num_channels_;

		};	
	}
}


#endif //OPENDETECTION_ODCONVCLASSIFICATION_H
