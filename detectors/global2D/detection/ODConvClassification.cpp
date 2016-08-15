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
	
		void ODConvClassification::setOutputFileLocation(string location)
		{
			outputFileLocation = location;
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
			#if(WITH_GPU)
			Caffe::SetDevice(0);
			Caffe::set_mode(Caffe::GPU);
			#else
			Caffe::set_mode(Caffe::CPU);
			#endif
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

		std::vector<float> ODConvClassification::classifyMultiLabel()
		{
			#if(WITH_GPU)
			Caffe::SetDevice(0);
			Caffe::set_mode(Caffe::GPU);
			#else
			Caffe::set_mode(Caffe::CPU);
			#endif
			Net<float>  net(networkFileLocation, TEST);
			net.CopyTrainedLayersFrom(weightModelFileLoaction); 
			
			float type = 0.0;
			const vector<Blob<float>*>& result =  net.Forward(inputBlob, &type);
			cout << endl << "****** OUTPUT *******" << endl;
/*			cout << "The AAM points are " << endl;
			cout << net.output_blobs()[0] << endl;
			for (int i = 0; i < 15; i++)
			{
				cout << result[0]->cpu_data()[2*i]*255 << " " << result[0]->cpu_data()[2*i+1]*255 << " ";
			}
			cout << endl;
*/
			Blob<float>* output_layer = net.output_blobs()[0];
			const float* begin = output_layer->cpu_data();
			const float* end = begin + output_layer->channels();
			return std::vector<float>(begin, end);
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

		std::vector<float> ODConvClassification::runMultiClassClassifier()
		{
			#if(WITH_GPU)
			Caffe::SetDevice(0);
			Caffe::set_mode(Caffe::GPU);
			#else
			Caffe::set_mode(Caffe::CPU);
			#endif
			/* Load the network. */
			Net<float>  net_m(networkFileLocation, TEST);
			net_m.CopyTrainedLayersFrom(weightModelFileLoaction);
			Blob<float>* input_layer = net_m.input_blobs()[0];
			num_channels_ = input_layer->channels();
			input_geometry_ = cv::Size(input_layer->width(), input_layer->height());
			input_layer->Reshape(1, num_channels_,
				       input_geometry_.height, input_geometry_.width);
			net_m.Reshape();
			std::vector<cv::Mat> input_channels;

			int width = input_layer->width();
			int height = input_layer->height();
			float* input_data = input_layer->mutable_cpu_data();
			for (int i = 0; i < input_layer->channels(); ++i) 
			{
				cv::Mat channel(height, width, CV_32FC1, input_data);
				input_channels.push_back(channel);
				input_data += width * height;
			}


//			net_m.Forward();
			Blob<float>* output_layer = net_m.output_blobs()[0];
			const float* begin = output_layer->cpu_data();
			const float* end = begin + output_layer->channels();
			return std::vector<float>(begin, end);
		}

		void ODConvClassification::runMultiClassClassifierPythonMode()
		{
			string mode = "";
			#if(WITH_GPU)
			mode = "gpu";
			#else
			mode = "cpu";
			#endif
			string cmd = "python ../examples/objectdetector/AAM_Classify/classify.py " + networkFileLocation + " " + weightModelFileLoaction + " " + imageFileLocation + " " + outputFileLocation + " " + mode;
			system(cmd.c_str());

		}	

		void ODConvClassification::setSegnetLocation(string location)
		{
			segnetLocation = location;
		}
		void ODConvClassification::setImageGroundTruthFileLocation(string location)
		{
			imageGroundTruthFileLocation = location;
		}
		void ODConvClassification::setColorLocation(string location)
		{
			colorLocation = location;
		}
		void ODConvClassification::runSegnetBasedClassifierPythonMode()
		{
			string mode = "";
			#if(WITH_GPU)
			mode = "gpu";
			#else
			mode = "cpu";
			#endif
//			string segnet_location = argv[1];
//			string model_file   = argv[2];
//			string trained_file = argv[3];
//			string test_image = argv[4];
//			string test_image_gt = argv[5];
//			string color = argv[6];
//			string mode = argv[7];
			string cmd = "python ../examples/objectdetector/Segnet_Classify/test.py " + segnetLocation + " " + networkFileLocation + " " + weightModelFileLoaction + " " + imageFileLocation + " " + imageGroundTruthFileLocation + " " + colorLocation + " " + mode;
			system(cmd.c_str());
		}	
/*
		std::vector<float> ODConvClassification::Predict(const cv::Mat& img)
		{
			Blob<float>* input_layer = net_m.input_blobs()[0];
			input_layer->Reshape(1, num_channels_,
				       input_geometry_.height, input_geometry_.width);
			net_m.Reshape();

			std::vector<cv::Mat> input_channels;
			WrapInputLayer(&input_channels);
			net_m.Forward();
			Blob<float>* output_layer = net_m.output_blobs()[0];
			const float* begin = output_layer->cpu_data();
			const float* end = begin + output_layer->channels();
			return std::vector<float>(begin, end);
		}

		void ODConvClassification::WrapInputLayer(std::vector<cv::Mat>* input_channels) 
		{
			Blob<float>* input_layer = net_m.input_blobs()[0];

			int width = input_layer->width();
			int height = input_layer->height();
			float* input_data = input_layer->mutable_cpu_data();
			for (int i = 0; i < input_layer->channels(); ++i) 
			{
				cv::Mat channel(height, width, CV_32FC1, input_data);
				input_channels->push_back(channel);
				input_data += width * height;
			}
		}
*/		
	
						
	}
}
