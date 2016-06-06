
GSoC 2016 Blog - Abhishek {#gsoc2016_blog_abhishek}
====
[TOC]

CNN based object localization and recognition for openDetection library  {#gsoc2016_blog_abhishek1}
====

  - [Link to Proposal](https://storage.googleapis.com/summerofcode-prod.appspot.com/gsoc/core_project/doc/1458909012_ProposalGSoC16.pdf?Expires=1463646545&GoogleAccessId=summerofcode-prod%40appspot.gserviceaccount.com&Signature=u8ENsakhMhWcA16h57rY8BzZ9M1NoUOxmRRUSJfSaEjJc%2Fce%2FoknY4K3%2FuQTJI3r0kuJF2P5WcwKYNOJd8zkIo6YDtbqQ5Be%2Bz1jXTbfsUGpN7UvQwElqKlAcAVcKxMPq1KkNpJFzPQhm8tDl9wYyFzoSnV1kLgpBMesbWV3vggt12PFo8IYkbpD4esd%2B9kHK64iNG5AykTJzL0CrMQcPK1a4WLrzBcgS8Dp2z327Ri8W1BtRC1SF4pveEmd6daAuRK3zfVkq8B7NNsvvk7x3QM2lg9WTlrFyTzDNOkp0k0cByusZ5fvZ20eQHbqmsKM8skE7XT0fX98xoiED8bauA%3D%3D) - [Link to GSoC2016 Project Page](https://summerofcode.withgoogle.com/projects/#5234791976796160)
    

**About me**

I am a final year engineering student from India, pursuing Electrical and Electronics Engineering at Bits-Pilani Goa Campus. Since my first year at the college, I have been interested in the fields of Computer Vision, Machine Learning and Artificial Intelligence. I have completed my undergraduate thesis at Research and Division Labs of Tata Elxsi Pvt Ltd, on the topic "Scene-understanding and object classification using neural networks for autonomous robot navigation". Over the tenure of engineering in the past three and a half years I have worked over a few projects, 

  - Using Weber Local Descriptors to match forensics sketeches with their image counterparts
  - Implementing a new course, on biomedical image processing, which is supposed to be added to the college's academic curriculum
  - Vehicle detection and tracking
  - Analysing haar-cascades on face detection application

**Project**

The project is revolved over integrating object detection and classification module using Convolutional Neural Networks. The following shows the basic components of the work to be completed during the term of Google Summer Of Code, 2016

  - Implement a way to invoke Caffe open source library from the OpenDetection module with a user-friendly code based way ( this will include a tinge of GUI support for instant access)
  - Implement open source guidance and codes for state-of-the art object localization problems(hypothesis generation) specifically based on selective-search and convolutional neural network (CNN) approaches. 
  - Adding a ground-truth annotation tool to the module with a graphical-user-interface support. 
  - Implementing short, but effective modules like mixed-pooling, recurrent networks to the Convolutional Neural Networks Training dependent on the invoked caffe library. 
  - Adding context based learning CNNs. 
  - Adding user-interface to train and test CNN based classifiers and object detectors.
  - Adding documentation for the above

All the completed and on-going work will be explained in detail here, as the process moves forward.

Happy Coding!!!!


Classification of digits in Mnist Library using CNN {#target1}
====

The classification exampled added to the library involves usage of caffe library. The modalities and usage of the libraries can be studied at

  - [Caffe Library](http://caffe.berkeleyvision.org/)
  - [Using Caffe Library](https://abhishek4273.com/2016/02/07/ann-chapter-3-deep-learning-using-caffe-python/)
  - [Branch of OpenDetection for the below classifier](https://github.com/abhi-kumar/opendetection/tree/cnn_cpu)


This example involves inclusion of three new files:

  - "opendetection/examples/objectdetector/od_cnn_mnist_classification.cpp"
  - "opendetection/detectors/global2D/detection/ODConvClassification.cpp"
  - "opendetection/detectors/global2D/detection/ODConvClassification.h"

The Classification example has been implemented over the ODDetector2D class. The new ODConvClassification class inherits from the abstract class ODDetector2D under the namespace od::g2d. LEts go over each file briefly.

**ODConvClassification.h & ODConvClassification.cpp files**

The file involves inclusion of the following headers.
@code 
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
@endcode

The first set involves the basic C++ headers, while the last three headers are from the caffe library. The namespaces are
  - caffe for Caffe Modules
  - std for C++ Standard Modules
  - cv for C++ OpenCV Modules

The variables involved are as follows
@code
string weightModelFileLoaction;
string networkFileLocation;
string imageFileLocation; 
Datum strucBlob;
BlobProto protoBlob;
vector<Blob<float>*> inputBlob;
@endcode

  - "weightModelFileLoaction" stores the location of the trained weight caffemodel file.
  - "networkFileLocation" stores the location of the CNN network file.
  - "imageFileLocation" stores the location of the image to be classified.
  - "strucBlob" keeps the details of the blob structure of the image to be compiled.
  - "protoBlob" creates an initial storage for the input image to be converted from image file to Caffe Blob named "inputBlob"

Lets go through the functions involved in the process.
  - @code
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
    @endcode
    These functions are uite self explanatory. The first three functions are being used to get the location of the reuired files, while the rest are to retrieve these locations.

  - @code void ODConvClassification::setTestBlob(int numChannels, int imgHeight, int imgWidth) @endcode This function takes an input image and converts into a suitable format for caffe libraries. @code
			if (!ReadImageToDatum(imageFileLocation, numChannels, imgHeight, imgWidth, &strucBlob)) 
			{
				cout << "Image File Not Found" << endl;
				exit(0);
			}
			Blob<float>* dataBlob = new Blob<float>(1, strucBlob.channels(), strucBlob.height(), strucBlob.width());    
    @endcode This snippet reads the image, and creates a structure to save the input image as a blob.@code
			if (data.size() != 0) 
			{
				for (int i = 0; i < sizeStrucBlob; ++i)
				{
					protoBlob.set_data(i, protoBlob.data(i) + (uint8_t)data[i]);
				}
			}

			dataBlob->FromProto(protoBlob);
			inputBlob.push_back(dataBlob);
    @endcode The snippet mentioned above converts the image from the initial(".png") format to the blob format required by the caffe library.

  - The net is initailized with the network parameters and trained weights using the following snippet. @code
			Caffe::set_mode(Caffe::CPU);
			Net<float>  net(networkFileLocation, TEST);
			net.CopyTrainedLayersFrom(weightModelFileLoaction); @endcode And the net is asked to move forward and present the probaility using the following snippet. @code
const vector<Blob<float>*>& result =  net.Forward(inputBlob, &type); @endcode This output vector, "result", contains the probabilities for each of the classes, The class with the maximum probobiility or score is the classified class.

**The CMake Changes**

The od_mandatory_dependency.cmake file has been added a new line @code find_package( Caffe REQUIRED) @endcode And thus the inclusion of caffe include directory and caffe libraries. In the CMakeLists.txt file from detectors/global2D directory, the following snippet is added @code
ADD_DEFINITIONS(
    -std=c++11 
	${Caffe_DEFINITIONS}
)
@endcode This has been done to enable mode choice of caffe runtime, i.e., CPU or GPU, and in this example CPU.


**Usage**

The example can be invoked using the following command: (From the build folder)

./examples/objectdetector/od_cnn_mnist_classification ../examples/objectdetector/Mnist_Classify/mnist.caffemodel ../examples/objectdetector/Mnist_Classify/lenet.prototxt ../examples/objectdetector/Mnist_Classify/1.png

The example as shown above takes 3 arguments, the locations of the weight file, network file and the image.

**Next up will be a simple CNN trainer example.**

Happy Coding!!!! 


Training a classifier for digits in Mnist Library using CNN. Part 1 {#target2}
====

This particular inclusion presents a simple trainer in a most crude and easy way possible. The major requirements of CNN training using caffe are
  - Solver file
  - Training Network file
  - Image Dataset and a pointer to the Dataset


The classification exampled added to the library involves usage of caffe library. The modalities and usage of the libraries can be studied at

  - [Caffe Library](http://caffe.berkeleyvision.org/)
  - [Using Caffe Library](https://abhishek4273.com/2016/02/07/ann-chapter-3-deep-learning-using-caffe-python/)
  - [Branch of OpenDetection for the below classifier](https://github.com/abhi-kumar/opendetection/tree/cnn_cpu)


This example involves inclusion of three new files:

  - "opendetection/examples/objectdetector/od_cnn_mnist_train_simple.cpp"
  - "opendetection/detectors/global2D/training/ODConvTrainer.cpp"
  - "opendetection/detectors/global2D/training/ODConvTrainer.h"

**Invoking Training module of caffe**

These lines invoke the trainer: 
@code
			Caffe::set_mode(Caffe::CPU);
			SGDSolver<float> s(solverLocation);
			s.Solve();
@endcode

This snippet points to solver file, the solver file points to the network file. This network file points to the file which in turn points to the dataset.


**Usage**

The example can be invoked using the following command: (From the build folder)

./examples/objectdetector/od_cnn_mnist_train_simple ../examples/objectdetector/Mnist_Train/solver1.prototxt

The only argument to be given is the solver file.

**Next up will be a simple CNN trainer example with a graphical user interface for the solver file.**

Happy Coding!!!! 
