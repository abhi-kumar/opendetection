/*
Author: Abhishek Kumar Annamraju
Release Date: 01/06/2016
*/

#include "ODConvClassification.h"

using namespace caffe;
using namespace std;
using namespace cv;

namespace od
{
	namespace g2d
	{
		
		void ODConvClassification::setWeightModelFileLocation(string location)
		{
			ODConvClassification::weightModelFileLoaction = location;
		}

		void ODConvClassification::setNetworkModelFileLocation(string location)
		{
			networkFileLocation = location;
		}

		void ODConvClassification::setImageFileLocation(string location)
		{
			imageFileLocation = location;
		}	
		
		string ODConvClassification::getWeightModelFileLocation()
		{
			cout << "Weight Model File Location = " << weightModelFileLoaction << endl;
			return weightModelFileLoaction;
		}
		
		string ODConvClassification::getNetworkModelFileLocation()
		{
			cout << "Network Model File Location = " << networkFileLocation << endl;
			return networkFileLocation;
		}
		
		string ODConvClassification::getImageFileLocation()
		{
			cout << "Image File Location = " << imageFileLocation << endl;
			return imageFileLocation;
		}

		void ODConvClassification::setTestBlob(int numChannels, int imgHeight, int imgWidth)
		{
			if (!ReadImageToDatum(imageFileLocation, numChannels, imgHeight, imgWidth, &strucBlob)) 
			{
				cout << "Image File Not Found" << endl;
				exit(0);
			}
			Blob<float>* dataBlob = new Blob<float>(1, strucBlob.channels(), strucBlob.height(), strucBlob.width());
			
			
			protoBlob.set_num(1);
			protoBlob.set_channels(strucBlob.channels());
			protoBlob.set_height(strucBlob.height());
			protoBlob.set_width(strucBlob.width());
			const int data_size = strucBlob.channels() * strucBlob.height() * strucBlob.width();
			int sizeStrucBlob = std::max<int>(strucBlob.data().size(), strucBlob.float_data_size());
			for (int i = 0; i < sizeStrucBlob; ++i) 
			{
				protoBlob.add_data(0.);
			}
			const string& data = strucBlob.data();
			if (data.size() != 0) 
			{
				for (int i = 0; i < sizeStrucBlob; ++i)
				{
					protoBlob.set_data(i, protoBlob.data(i) + (uint8_t)data[i]);
				}
			}

			dataBlob->FromProto(protoBlob);
			inputBlob.push_back(dataBlob);
			
		}

		void ODConvClassification::classify()
		{
			Caffe::SetDevice(0);
			Caffe::set_mode(Caffe::GPU);
			Net<float>  net(networkFileLocation, TEST);
			net.CopyTrainedLayersFrom(weightModelFileLoaction); 
			
			float type = 0.0;
			const vector<Blob<float>*>& result =  net.Forward(inputBlob, &type);
			float max = 0;
			float max_i = 0;
			for (int i = 0; i < 10; ++i)
			{
				float value = result[0]->cpu_data()[i];
				if (max < value)
				{
				max = value;
				max_i = i;
				}
			}
			cout << endl << endl << "****** OUTPUT *******" << endl;
			cout << "classified image is digit " << max_i << endl << endl;
		}

		void ODConvClassification::init()
		{
		}

		ODDetections2D *ODConvClassification::detectOmni(ODSceneImage *scene)
    		{
			ODDetections2D *detections = new ODDetections2D;
			return detections;
		}

		ODDetections *ODConvClassification::detect(ODSceneImage *scene)
		{
			ODDetections *detections = new ODDetections;
			return detections;		
		}
		
	
						
	}
}
