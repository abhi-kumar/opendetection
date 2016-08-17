GSoC 2016 Blog - Abhishek {#gsoc2016_blog_abhishek}
====
[TOC]

CNN based object localization and recognition for openDetection library  {#gsoc2016_blog_abhishek1}
====

  - [Link to Proposal](https://summerofcode.withgoogle.com/serve/6621875723567104/) 


  - [Link to working branch](https://github.com/abhi-kumar/opendetection/tree/cnn_cpu_gpu)


General Description  {#general_description}
===

The following blog has been modified to accompany the entire GSOC project duration. The code, commits and examples explained in this blog is related to the commits that have been made to the branch cnn_cpu_gpu as mentioned in this [link](https://github.com/abhi-kumar/opendetection/tree/cnn_cpu_gpu). The set of commits to other temporary branches and the commits with unsuccessful builds from the same have been corrected and put into the mentioned branch with a set of around 20 commits. On the whole, the entire project has been mentioned here as a project report.

The set of other branches, for reference purposes can be found here: [link](https://github.com/abhi-kumar/opendetection/tree/master)

The project started with the first basic task of making the repository compile on a cpu platform. Examples of Mnist Classifier, custom cnn caffe solver maker, etc were added. After the availability of a gpu based system, the corresponding work was translated to that system. Later the work was combined and new additions like AAM classifier, custom trainer, segnet classifier, annotator, selective search localization, etc, were added. The upcoming part of the blog emphasizes on the important commits made, including all the successful commits to one unified single branch in a cronological order. This branch was specifically created to explain the work done in the GSOC period. It also includes the usage and explanation of the examples for user feasibility. The earlier blog posts have been pushed as later sections. Link to commits to other branches (all already combined and pushed to cnn_cpu_gpu branch and explained below) are also mentioned at the end for reference.

Note: The following commits were not the only ones, a set of commits have been combined and stated here, to facilitate clear explanation and organization.

Commit 1  {#commit1}
===
This commit, [link to commit: First attempt to make cpu and gpu repos together](https://github.com/abhi-kumar/opendetection/commit/245f821631452de18aaad13bab3e1f8fd7f333a4), was issued to resolve the earlier problem faced while compiling the library. Earlier, even with the option of WITH_GPU=OFF in cmake, the library fetched for cuda and gpu based files in the system. To resolve the following changes were applied. 

The task was to take a flag from CMakeLists files into the source codes in order proper management of inclusion of libraries, thus, in CmakeLists.txt files, \code{.txt}
if (WITH_GPU) #This is the cmake option variable
	target_compile_definitions("${LIB_NAME}" PUBLIC WITH_GPU=${WITH_GPU})
endif()
\endcode, was added. The flag WITH_GPU now was translated into the source codes. This was done to files, detectors/global3D/CMakeLists.txt, and common/CMakeLists.txt. 

This particular flag, WITH_GPU was taken into four set of files, common/utils/ODFeatureDetector2D.cpp, common/utils/ODFeatureDetector2D.h, detectors/local2D/detection/simple_ransac_detection/RobustMatcher.cpp and detectors/local2D/detection/simple_ransac_detection/RobustMatcher.h.  Herein, for example, cuda variable declaration, involvement of gpu based variables, and inclusion of cuda libraries were put inside the flag WITH_GPU, eg, \code{.txt}
#if(WITH_GPU)
	cv::Ptr<cv::cuda::DescriptorMatcher> matcher_gpu_;
#endif
\endcode

The third change was to include the linking libraries in CMakeLists.txt files of specific gpu based libraries with the cmake option WITH_GPU option. The library linkage siftgpu in the file detectors/global3D/CMakeLists.txt, was modified to \code{.txt}
if(WITH_GPU)
	set(SUBSYS_DEPS ${SUBSYS_DEPS} siftgpu)
endif()
\endcode. 

The library then compiled successfully on my laptop(cpu system) as well as my PC(Nvidia 980 TI based gpu system). 

Happy Coding!!!!


Commit 2 {#commit2}
===

This commit, [link to commit:CNN_CPU branch successfully added](https://github.com/abhi-kumar/opendetection/commit/3c4a12b5711e84f2145851b526ab2e84d9127889), was issued to add cnn-caffe based applications, only for cpu based systems, for now. The commit shows 42055 files changes, its because Mnist image dataset was added in order to introduce the object classifier trainer in the commit. Its a combination of set of commits made earler, put here together for better explanation of each of them. The links to these frangmented commits are also mentioned here.

To better understand neural networks, please refer to [ARTIFICIAL NEURAL NETWORKS AND THE MAGIC BEHIND – INTRODUCTORY CHAPTER](https://abhishek4273.com/2015/11/01/artificial-neural-networks-and-the-magic-behind-introductory-chapter/)

To get into the working of mathematics behind neural networks, please refer to [ARTIFICIAL NEURAL NETWORKS AND THE MAGIC BEHIND – CHAPTER 1](https://abhishek4273.com/2015/11/04/artificial-neural-networks-and-the-magic-behind-chapter-1/)

To understand as to how every part of caffe works, please refer to [ANN: CHAPTER 3. DEEP LEARNING USING CAFFE-PYTHON](https://abhishek4273.com/2016/02/07/ann-chapter-3-deep-learning-using-caffe-python/).


2.1)Enabling caffe inclusion, commit 2.1 {#commit2_first_change}
---

The first change, [link to the fragmented part commit](https://github.com/abhi-kumar/opendetection/commit/166b6426acbc3253ee53d09a8ce240d3739c8762), to enable the compilation of based codes, the file, cmake/od_mandatory_dependency.cmake, was changed. Herein, caffe library was made as a mandatory dependency and the libraries and include directories were added. 


2.2)Adding cnn based classifier, commit 2.2 {#commit2_second_change}
---

The next part, was to add a cnn based classifier, based on caffe library, to the opendetection source. The [fragmented commit: Commit for Mnist Classification Example Using Caffe Library](https://github.com/abhi-kumar/opendetection/commit/166b6426acbc3253ee53d09a8ce240d3739c8762), involved additions of 7 code source files, 1 trained binary file and 5 sample test images.

2.2.1) Enabling cpu gpu mode switch {#commit2_second_change_1}
---

The file, detectors/global2D/CMakeLists.txt, was added the following lines \code{.txt}
ADD_DEFINITIONS(
	-std=c++11 
	${Caffe_DEFINITIONS}
)
\endcode
This was to make sure that, while invoking caffe, the mode can be specified without compilation errors.

2.2.2) Classification base class {#commit2_second_change_2}
---

The base class for cnn based classification, is ODConvClassification, and is introduced with two new files, detectors/global2D/detection/ODConvClassification.h and detectors/global2D/detection/ODConvClassification.cpp.

Lets talk about the codes in these files.

It involves the inclusion of following opendetection libraries
\code{.h}
#include "common/pipeline/ODDetector.h"
#include "common/pipeline/ODScene.h"
#include "common/utils/utils.h"
#include "common/utils/ODFeatureDetector2D.h" 
\endcode
The ODDetector.h is included in order to make sure that the ODConvolutionClassification is a derivative of ODDetector class.

Opencv library
\code{.h}
#include <opencv2/opencv.hpp>
\endcode
is added to make sure that image loading and saving is done using the Mat constructor

A set of general c++ header are also added
\code{.h}
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
\endcode

Three header files from caffe library are added in order to make sure that caffe library can be succesfully included. 
\code{.h}
#include "caffe/caffe.hpp"
#include "caffe/util/io.hpp"
#include "caffe/blob.hpp"
\endcode

Under the namespace od::g2d, the class at this stage had the following public variables, see comments in code.
\code{.cpp}
string weightModelFileLoaction;		// Stores the trained weight caffemodel's location
string networkFileLocation;		// Stores the network prototxt file's location
string imageFileLocation; 		// Stores the test image's location
Datum strucBlob;			// A structure to load the test image
BlobProto protoBlob;			// Medium for conversion
vector<Blob<float>*> inputBlob;		// Modified structure to be given to caffe network 
\endcode

\n 
At this stage, the classifier had 8 functions which were created for classification purpose, and the 4 functions which had to be included because the base class had them as abstract.

**Function1**
\code{.cpp}
void ODConvClassification::setWeightModelFileLocation(string location)
{
	ODConvClassification::weightModelFileLoaction = location;
}
\endcode
It is for taking the weight caffemodel's location from user and storing in the string weightModelFileLoaction.

 
**Function2**
\code{.cpp}
void ODConvClassification::setNetworkModelFileLocation(string location)
{
	networkFileLocation = location;
}
\endcode
It is for taking the network prototxt file's location from user and storing in the string networkFileLocation.


**Function3**
\code{.cpp}
void ODConvClassification::setImageFileLocation(string location)
{
	imageFileLocation = location;
}
\endcode 
It is for taking the test_image file's location from user and storing in the string imageFileLocation.


**Function 4, 5 and 6**
\code{.cpp}
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
\endcode
These are retrieving the the three variables, weightModelFileLoaction, networkFileLocation and imageFileLocation.

**Function 7**
The function, setTestBlob, is one of the very important functions. It takes the image and converts it into the format required by the caffe library. It takes three inputs, 
  - numChannels: Number of channels in image. If grayscale image it has to be 1, else if the image is in RGB or HSV format, then it has to be 3.
  - imgHeight: Height to which it should be resized to fit into the caffe network.
  - imgWidth: Width to which it should be resized to fit into the caffe network.

\code{.cpp}
if (!ReadImageToDatum(imageFileLocation, numChannels, imgHeight, imgWidth, &strucBlob)) 
{
	cout << "Image File Not Found" << endl;
	exit(0);
} 
\endcode

This particular section, makes sure that the image is converted to datum format, more details on [datum](https://github.com/BVLC/caffe/wiki/The-Datum-Object)

Next,
\code{.cpp}
Blob<float>* dataBlob = new Blob<float>(1, strucBlob.channels(), strucBlob.height(), strucBlob.width());
\endcode
Herein, a new blob, [link to understand blob](http://caffe.berkeleyvision.org/tutorial/net_layer_blob.html), is created. This is the blob which will hold the input image in format reuired by caffe.

Now,
\code{.cpp}
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
\endcode
In this last section, the temporary structure, protoBlob, takes input image and converts into the reuired format with assigned dimensions, which is forwaded to dataBlob and in turn, finally, pushed into inputBlob structure vector.


**Function 8**
This is the function which takes the inputBlob, invokes a caffe network and pushes the inputBlob into the caffe network for classification.

\code{.cpp}
Caffe::set_mode(Caffe::CPU);
\endcode
This particular part sets mode as cpu mode, which was later changed by keeping it as a option. In later commits somewhere, it was modified in a way that when gpu is detected use gpu mode.

\code{.cpp}
Net<float>  net(networkFileLocation, TEST);
net.CopyTrainedLayersFrom(weightModelFileLoaction); 
\endcode
The first line creates the network, and the nest loads the trained weights into it.

\code{.cpp}
const vector<Blob<float>*>& result =  net.Forward(inputBlob, &type);
\endcode
This particular line is what makes the network compute the result. A set of predictions for each class, in case of mnist 10 classes, is obtained. The one with highest probability is what the classifier states as the most propable class of the object in the image. This is obtained using the following section of code

\code{.cpp}
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
\endcode

This ends the base file additions for this commit


2.2.3) Mnist Classification Example {#commit2_second_change_3}
---

An example which takes use of the functions stated above in this commit is included, examples/objectdetector/od_cnn_mnist_classification.cpp.
It takes data from folder examples/objectdetector/Mnist_Classify. This folder has a network file, a trained weight file, and 5 test images.

The cpp file has the following components,

\code{.cpp}
#include "detectors/global2D/detection/ODConvClassification.h"
#include "common/utils/ODFrameGenerator.h"
#include "common/pipeline/ObjectDetector.h"
#include "common/pipeline/ODDetection.h"
#include <iostream>
#include <fstream>
\endcode
These are the libraries included in the code, of which the first one is the most important one.

The rest of the code is explained in the comments(inside code) below
\code{.cpp}
od::g2d::ODConvClassification *mnist_classifier = new od::g2d::ODConvClassification("");	//Create object of class ODConvClassification
mnist_classifier->setWeightModelFileLocation(argv[1]);						//Set location for trained wieghts file
mnist_classifier->setNetworkModelFileLocation(argv[2]);						//Set location for nework structure file 
mnist_classifier->setImageFileLocation(argv[3]);						//Set location for test image file
mnist_classifier->setTestBlob(1,28,28);								//Convert image to caffe required format and dimensions 28,28 and grayscale input
mnist_classifier->classify();									//Invoke the classifier
\endcode


This code has a help function,
\code{.cpp}
void help()
{
	cout << endl << "Usage: ./examples/objectdetector/od_cnn_mnist_classification <path to weight caffemodel file> <path to network file> <path to image file>" << endl;
	cout << endl << "Example: ./examples/objectdetector/od_cnn_mnist_classification ../examples/objectdetector/Mnist_Classify/mnist.caffemodel ../examples/objectdetector/Mnist_Classify/lenet.prototxt ../examples/objectdetector/Mnist_Classify/3.png" << endl << endl;
	exit(0);
}
\endcode
This is for the cases when user puts in wrong command to invoke the classifier.

Example: Mentioned is classification of 

@image html 3.png

with the function
\code{.sh}
./examples/objectdetector/od_cnn_mnist_classification ../examples/objectdetector/Mnist_Classify/mnist.caffemodel ../examples/objectdetector/Mnist_Classify/lenet.prototxt ../examples/objectdetector/Mnist_Classify/3.png
\endcode

and the result is shown in the terminal in the image below as
"****** OUTPUT *******
classified image is digit 4"

@image html Example_For_Documentation.png 


Happy Coding!!!

2.2.4) Adding cnn based classifier: Features and benefits  {#commit2_second_change_4}
---

**1)Usually the caffe is invoked using a python wrapper, this is the first time any open source library will be having a c++ based classifier**

**2)It makes use of the caffe data convertor in c++ format, so that opendetection user may load image in either opencv Mat format or just point to image's location**

**3)User just needs to point a network file, trained weights and a test image, and the classification result can be obtained using the mentioned examples**


2.3)Adding cnn based trainer, commit 2.3 {#commit2_third_change}
---

Here, the goal was to add a cnn based trainer, based on caffe library, to the opendetection source. The [fragmented commit: Commit for Mnist Training Example Using Caffe Library](https://github.com/abhi-kumar/opendetection/commit/1adb044f5bc10b3a29d190273d86527e0e4d1f53), involved additions of 3 code source files and 42000 training images (Mnist Dataset), a link file to these images with labels, a training etwork file and a solver file.

2.3.1)Training Base Class {#commit2_third_change_1}
---

At this stage, two files were introduced, detectors/global2D/training/ODConvTrainer.cpp and detectors/global2D/training/ODConvTrainer.h

In the header file,

\code{.h}
#include "common/pipeline/ODTrainer.h"
#include "common/utils/utils.h"
\endcode
these headers were used to make sure that the training class ODConvTrainer is derived from public elements of ODTrainer.

Opencv library
\code{.h}
#include <opencv2/opencv.hpp>
\endcode
is added to make sure that image loading and saving is done using the Mat constructor

A set of general c++ header are also added
\code{.h}
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
\endcode

Three header files from caffe library are added in order to make sure that caffe library can be succesfully included. 
\code{.h}
#include "caffe/caffe.hpp"
#include "caffe/util/io.hpp"
#include "caffe/blob.hpp"
#include "caffe/solver.hpp"
#include "caffe/sgd_solvers.hpp"
\endcode
Tha last two files have been used to invoke the solver properties and run the trainer from caffe library.

At this stage the class had only one variable
\code{.cpp}
string solverLocation;
\endcode which stores the location pointing towards the solver file.

**Function1**

\code{.cpp}
void ODConvTrainer::setSolverLocation(string location)
{
	ODConvTrainer::solverLocation = location;	
}
\endcode
Sets the variable solverLocation.

**Function2**
\code{.cpp}
void ODConvTrainer::startTraining()
{
	Caffe::set_mode(Caffe::CPU);
	SGDSolver<float> s(solverLocation);
	s.Solve();
}
\endcode
this function is the sole of this simple trainer. The first line sets the mode, in later commits mode is decided on the basis of the system specifications and user commands. The next line creates a caffe solver, [link to understand solver](http://caffe.berkeleyvision.org/tutorial/solver.html) and the last line starts the training.

2.3.2)Mnist Training Example{#commit2_third_change_2}
---

The file added for this is: examples/objectdetector/od_cnn_train_mnist_simple.cpp

\code{.cpp}
od::g2d::ODConvTrainer *mnist_trainer = new od::g2d::ODConvTrainer("","");
mnist_trainer->setSolverLocation(argv[1]);
mnist_trainer->startTraining();
\endcode
The above code is self explanatory. The trained weights are saved into a location as stated in the solver file.


2.4)Introducing a custom solver, commit 2.4 {#commit2_fourth_change}
---

This commit, [fragmented commit: Commit for Mnist Training Example Using Caffe Library With Customized Solver](https://github.com/abhi-kumar/opendetection/commit/6777c6cdc39289d4abe443d4cc564fb25135148b), to enable the user to create a solver file, as required in caffe library format, so that user may make the file using a graphical user interface rather than writing the entire text.

This particular commit had changes added or additions made to 9 files. The most crucial one was to add gtkmm library files to the source. GTKMM, [link to understand gtkmm](http://www.gtkmm.org/en/), is a library for involvement of gui based applications. We decided to move with GUI inclusion because, to make user handle solver file in an effective way, a set of 19 parameters had to be handled. If it were upto the c++ arguments to facilitate these 19 parameters, the outcome would have been a very cumbersome application. Also, not all parameters were to be added to the solver always, so a GUI appeared to be the most feasible option from the user's end. 

To install gtkmm use the following command,
\code{.sh}
sudo apt-get install libglib2.0-dev libatk1.0* libpango1.0-dev libcairo2-dev gdk-pixbuf2.0-0 libsigc++-2.0-dev libgtk-3-dev libcairomm-1.0-dev libpangomm-1.4-dev libatkmm-1.6-dev libgtkmm-3.0-dev
\endcode

2.4.1)How the GTKMM library was introduced {#commit2_fourth_change_1}
---

This involved making changes to the cmake/od_mandatory_dependency.cmake file.

This,
\code{.cmake}
set(GTKMM_INCLUDE_DIRS_3 -pthread /usr/include/gtkmm-3.0 /usr/lib/x86_64-linux-gnu/gtkmm-3.0/include /usr/include/atkmm-1.6 /usr/include/giomm-2.4 /usr/lib/x86_64-linux-gnu/giomm-2.4/include /usr/include/pangomm-1.4 /usr/lib/x86_64-linux-gnu/pangomm-1.4/include /usr/include/gtk-3.0 /usr/include/cairomm-1.0 /usr/lib/x86_64-linux-gnu/cairomm-1.0/include /usr/include/gdk-pixbuf-2.0 /usr/include/gtk-3.0/unix-print /usr/include/gdkmm-3.0 /usr/lib/x86_64-linux-gnu/gdkmm-3.0/include /usr/include/atk-1.0 /usr/include/glibmm-2.4 /usr/lib/x86_64-linux-gnu/glibmm-2.4/include /usr/include/glib-2.0 /usr/lib/x86_64-linux-gnu/glib-2.0/include /usr/include/sigc++-2.0 /usr/lib/x86_64-linux-gnu/sigc++-2.0/include /usr/include/pango-1.0 /usr/include/cairo /usr/include/pixman-1 /usr/include/freetype2 /usr/include/libpng12 /usr/include/at-spi2-atk/2.0 /usr/include/gio-unix-2.0/ /usr/include/harfbuzz)
\endcode
created a link to the header files involved with GTKMM

and,
\code{.cmake}
set(GTKMM_LIBRARIES_3 gtkmm-3.0 atkmm-1.6 gdkmm-3.0 giomm-2.4 pangomm-1.4 gtk-3 glibmm-2.4 cairomm-1.0 gdk-3 atk-1.0 gio-2.0 pangocairo-1.0 gdk_pixbuf-2.0 cairo-gobject pango-1.0 cairo sigc-2.0 gobject-2.0 glib-2.0)
\endcode
created a link to the .so library files required for proper compilation. These two variables where used whenever reuired in other cmakelists files.

2.4.2) Custom Solver base class and usage details for every parameter/entry in the gui{#commit2_fourth_change_2}
---

The base class named, SolverProperties, was introduced using two files,  detectors/global2D/training/solver.cpp and  detectors/global2D/training/solver.h. 

The header file takes in the following headers from gtkmm library
\code{.cpp}
#include <gtkmm/grid.h>
#include <gtkmm/entry.h>
#include <gtkmm/button.h>
#include <gtkmm/radiobutton.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/window.h>
#include <gtkmm/scrolledwindow.h>
\endcode

  - grid.h to make sure the elements, eg., buttons, display windows, text boxes etc, lie on a particular place even with differential resolutions of user's systems
  - entry.h for textboxes
  - button.h for buttons
  - radiobutton.h for radio type buttons
  - messagedialog.h for invoking warning or user oriented messages on completion of events
  - window.h as the base class to invoke a window based application
  - scrollwindow.h to make sure that the window created can be scrolled either ways.

The gui has a total of
  - 23 buttons
  - 19 text box entries
  - 17 labels
  - 28 radio buttons grouped into 9 groups
  - 21 string (here ustring) variables

**Initializing the elements, i.e., the buttons, text boxes, labels, and radio buttons**

In the cpp file, these are initialized accroding to the following rules
  - Like any object initalization, these are done just after the mentioning the constructor and before writing the matter of the constructor.
  - for button, nameOfButton("Text to print on the button")
  - for text boxes, nameOfTextBox()
  - for labels, nameOfLabel("")
  - for radioButton, nameOfButton("Text to print on the button")
and it is done as shown below
\code{.cpp}
SolverProperties::SolverProperties(): 
	label_solverFileName(""),
	button_solverFileName("Update"),
	text_solverFileName(),
	label_trainNetworkFileType(""),
	rbutton_trainNetworkFileType_net("net"), rbutton_trainNetworkFileType_tt("train_net"),
	label_trainNetworkFileName(""),
	button_trainNetworkFileName("Update"),
	text_trainNetworkFileName(),
	label_enableTestNet(""),
	rbutton_enableTestNet_no("No"), rbutton_enableTestNet_yes("Yes"),
	label_testNetworkFileName(""),
	button_testNetworkFileName("Update"),
	text_testNetworkFileName(),
	label_enableValidationParameters(""),
	rbutton_enableValidationParameters_no("No"), rbutton_enableValidationParameters_yes("Yes"),
	label_testIter(""),
	button_testIter("Update"),
	text_testIter(),
	label_testInterval(""),
	button_testInterval("Update"),
	text_testInterval(),
	label_enableAverageLoss(""),
	rbutton_enableAverageLoss_no("No"), rbutton_enableAverageLoss_yes("Yes"),
	label_averageLoss(""),
	button_averageLoss("Update"),
	text_averageLoss(),
	label_enableRandomSample(""),
	rbutton_enableRandomSample_no("No"), rbutton_enableRandomSample_yes("Yes"),
	label_randomSample(""),
	button_randomSample("Update"),
	text_randomSample(),
	label_display(""),
	button_display("Update"),
	text_display(),
	label_enableDebugInfo(""),
	rbutton_enableDebugInfo_no("No"), rbutton_enableDebugInfo_yes("Yes"),
	button_debugInfo("Update"),
	label_snapshot(""),
	button_snapshot("Update"),
	text_snapshot(),
	label_enableTestComputeLoss(""),
	rbutton_enableTestComputeLoss_no("No"), rbutton_enableTestComputeLoss_yes("Yes"),
	button_testComputeLoss("Update"),
	label_snapshotPrefix(""),
	button_snapshotPrefix("Update"),
	text_snapshotPrefix(),
	label_maxIter(""),
	button_maxIter("Update"),
	text_maxIter(),
	label_type(""),
	button_type("Update"),
	rbutton_typeSGD_yes("SGD"), rbutton_typeAdadelta_yes("AdaDelta"), rbutton_typeAdagrad_yes("AdaGrad"), rbutton_typeAdam_yes("Adam"),
	rbutton_typeRMSProp_yes("RMSProp"), rbutton_typeNesterov_yes("Nesterov"),
	label_learningRatePolicy(""),
	button_learningRatePolicy("Update"),
	rbutton_learningRatePolicyFixed_yes("fixed"), rbutton_learningRatePolicyExp_yes("exp"), rbutton_learningRatePolicyStep_yes("step"),
	rbutton_learningRatePolicyInv_yes("inv"), rbutton_learningRatePolicyMultistep_yes("multistep"), 
	rbutton_learningRatePolicyPoly_yes("poly"), rbutton_learningRatePolicySigmoid_yes("sigmoid"),
	label_baseLearningRate(""),
	button_baseLearningRate("Update"),
	text_baseLearningRate(),
	label_gamma(""),
	button_gamma("Update"),
	text_gamma(),
	label_power(""),
	button_power("Update"),
	text_power(),
	label_stepSize(""),
	button_stepSize("Update"),
	text_stepSize(),
	label_stepSizeValue(""),
	button_stepSizeValue("Update"),
	text_stepSizeValue(),
	label_weightDecay(""),
	button_weightDecay("Update"),
	text_weightDecay(),
	label_momentum(""),
	button_momentum("Update"),
	text_momentum(),
	button_saveFile("Save File")
{
	//Constructor code starts from here
\endcode

**Invoking the Grid**

The grids for putting the elemets was invoked using the following code snippet
\code{.cpp}
set_title("Solver");
set_border_width(10);
add(m_sw1);
m_grid1.set_column_spacing (10);
m_grid1.set_row_spacing (50);
\endcode

  - The fist line sets the title for the window
  - Border width is added in second line to make sure that no element is hidden over boundaries
  - Line 4 and 5 set the spacing between the elements
  - line 3 adds m_sw1, this m_sw1 is nothing but a scrollwindow

This scroll window is added to the window. This scroll window takes the grid, m_grid1 into the scrollwindow at the end of the constructor as
\code{.cpp}
m_sw1.add(m_grid1);
m_sw1.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
//	m_grid1.show();
show_all_children();
m_sw1.show();
\endcode
where, all the children of the grid are shown with the end line causing the scrolls to show up.


**Example Entry1: Name and location of the file to be created**

This entry asks user to give a proper name, with relative location( from build folder), of the solver file to be saved. This entry looks like the one mentioned in the red colored box in the image below:

@image html solver_1.png

This involves a label 
\code{.cpp}
label_solverFileName.set_text("1) Give a proper name to the solver file: ");	//set label text
label_solverFileName.set_line_wrap();						
label_solverFileName.set_justify(Gtk::JUSTIFY_FILL);
m_grid1.attach(label_solverFileName,0,0,2,1);					//set position of the element into the grid
label_solverFileName.show();
\endcode

followed by a text entry, this entry has an initial text "../examples/objectdetector/Mnist_Train/solverCustom1.prototxt". The folder Mnist_Train is already created in the source, hence, as a sample a pointer to the location, the text there points to the folder. solverCustom1.prototxt is the name of the file that will be created.
\code{.cpp}
text_solverFileName.set_max_length(100);							//set max length of the text
text_solverFileName.set_text("../examples/objectdetector/Mnist_Train/solverCustom1.prototxt");	//set initial text
text_solverFileName.select_region(0, text_solverFileName.get_text_length());		
m_grid1.attach(text_solverFileName,2,0,5,1);							//set position of the element into the grid
text_solverFileName.show();
\endcode

This is later followed by a button, to update the output file location and name. Once the location and name are updated in the text box, the button needs to be pressed. After pressing the button a messagebox appears stating the outcome. How the button works is stated in the section 2.4.3. 
\code{.cpp}
button_solverFileName.signal_clicked().connect(sigc::bind<Glib::ustring>(
             sigc::mem_fun(*this, &SolverProperties::on_button_clicked), "solverFileName"));	//link the button to a function with a key, here the key is "solverFileName"
m_grid1.attach(button_solverFileName,7,0,1,1);
button_solverFileName.show();
\endcode


**Entry2: Type of network link**

There exsists two types of links
  - net: this is to be selected when training and validation details are put into a same prototxt file
  - train_net: this is to be selected when the training parameters and validation parameters are put into two different prototxt files

It can be seen in the red rectangular section box in the image below

@image html solver_2.png

This entry has two elements, first is the label,
\code{.cpp}
label_trainNetworkFileType.set_text("2)Select type of training network file type.\nUsually trese exists two types,\nfirst adds validation and training in the same file,\nWhile other adds them in two different files");
label_trainNetworkFileType.set_line_wrap();
label_trainNetworkFileType.set_justify(Gtk::JUSTIFY_FILL);
m_grid1.attach(label_trainNetworkFileType,0,1,2,1);
label_trainNetworkFileType.show();
\endcode

and a set of two radio buttons to select the two types of links
\code{.cpp}
Gtk::RadioButton::Group group = rbutton_trainNetworkFileType_net.get_group();		//set a group
rbutton_trainNetworkFileType_tt.set_group(group);					// add other buttons to this group
rbutton_trainNetworkFileType_net.set_active();						//set one of them as active
m_grid1.attach(rbutton_trainNetworkFileType_net,2,1,1,1);
rbutton_trainNetworkFileType_net.show();
m_grid1.attach(rbutton_trainNetworkFileType_tt,3,1,1,1);
rbutton_trainNetworkFileType_tt.show();
\endcode

\n 
**Example Entry 2.1: Add the location of the network file**

This entry asks user to give a proper name, with relative location( from build folder), of the network/training cnn architecture file on which training has to be done. This entry looks like the one mentioned in the red colored box in the image below:

@image html solver_3.png

It has three fields

a label,
\code{.cpp}
label_trainNetworkFileName.set_text("2.1) net: or train_net:\n(Parameter Details: Give location of \nthe net file or the train_net file) ");
label_trainNetworkFileName.set_line_wrap();
label_trainNetworkFileName.set_justify(Gtk::JUSTIFY_FILL);
m_grid1.attach(label_trainNetworkFileName,0,2,2,1);
label_trainNetworkFileName.show();
\endcode

a text entry element,
\code{.cpp}	
text_trainNetworkFileName.set_max_length(500);
text_trainNetworkFileName.set_text("../examples/objectdetector/Mnist_Train/train1.prototxt");
text_trainNetworkFileName.select_region(0, text_solverFileName.get_text_length());
m_grid1.attach(text_trainNetworkFileName,2,2,5,1);	
text_trainNetworkFileName.show();	
\endcode

and an update button to update the text added/removed/changed in the the text box next to it. After pressing the button a messagebox appears stating the outcome. How the button works is stated in the section 2.4.3. 
\code{.cpp}
button_trainNetworkFileName.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &SolverProperties::on_button_clicked), "trainNetworkFileName"));	////link the button to a function with a key, here the key is "trainNetworkFileName"
m_grid1.attach(button_trainNetworkFileName,7,2,1,1);
button_trainNetworkFileName.show();
\endcode

\n 
**Example Entry 3: Selecting to whether add a test net file separately, and if yes pointing location of the file**

This entry is for the purpose when, a separate test/validation net is to be added. It is observed in the solver gui as in the red box stated in the image below

@image html solver_4.png

It has five elements, two labels, one text file, one radio button group and a final button to update the location

\code{.cpp}
label_enableTestNet.set_text("3) Enable Test Network Parameter:\n(Enable only with using \"train_net\" parameter.)");
label_enableTestNet.set_line_wrap();
label_enableTestNet.set_justify(Gtk::JUSTIFY_FILL);
m_grid1.attach(label_enableTestNet,0,3,2,1);
label_enableTestNet.show();

Gtk::RadioButton::Group group2 = rbutton_enableTestNet_no.get_group();
rbutton_enableTestNet_yes.set_group(group2);
rbutton_enableTestNet_no.set_active();
m_grid1.attach(rbutton_enableTestNet_no,2,3,1,1);
rbutton_enableTestNet_no.show();
m_grid1.attach(rbutton_enableTestNet_yes,3,3,1,1);
rbutton_enableTestNet_yes.show();

label_testNetworkFileName.set_text("3.1) test_net:");
label_testNetworkFileName.set_line_wrap();
label_testNetworkFileName.set_justify(Gtk::JUSTIFY_FILL);
m_grid1.attach(label_testNetworkFileName,4,3,1,1);
label_testNetworkFileName.show();
	
text_testNetworkFileName.set_max_length(500);
text_testNetworkFileName.set_text("../examples/objectdetector/Mnist_Train/test1.prototxt");
text_testNetworkFileName.select_region(0, text_testNetworkFileName.get_text_length());
m_grid1.attach(text_testNetworkFileName,5,3,3,1);	
text_testNetworkFileName.show();	

button_testNetworkFileName.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &SolverProperties::on_button_clicked), "testNetworkFileName"));
m_grid1.attach(button_testNetworkFileName,8,3,1,1);
button_testNetworkFileName.show();
\endcode


\n 

**Thus the rest of the entries are planned and coded. Whenever a parameter is set to be enabled as "no", its presense is commented in the output text file**

\n 
2.4.3)Pressing the buttons in the solver creator{#commit2_fourth_change_3}
---

**Example when a file name or parameter has to be saved**

When "Update", next to filename textbox, is pressed the following happens,

\code{.cpp}
solverFileName = text_solverFileName.get_text();
std::cout << "Solver File Name set as: " << solverFileName << std::endl;
Gtk::MessageDialog dialog(*this, "FileName Updated");
		dialog.set_secondary_text("New name and location: " + solverFileName);
dialog.run();
\endcode

The first line, saves the name into a string variable and the next lines prompt the user about the update

\n 
**Example when the entire file is saved**

When "Save File" button is pressed, a string is created in the format required by caffe solver file. All elements which are enabled are uncommented and the rest are set as commented. This string is pushed into a text file as mentioned by the user.

The code which does this is shown below,

\code{.cpp}
if(rbutton_enableTestNet_yes.get_active() == 1 and rbutton_trainNetworkFileType_net.get_active() == 1)
{
	Gtk::MessageDialog dialog(*this, "\"test_net\" parameter not required");
	dialog.set_secondary_text("\"test_net\" parameter is only required when \"train_net\" parameter is specified");
	dialog.run();
}
else if(rbutton_enableTestNet_yes.get_active() == 1 and rbutton_enableValidationParameters_no.get_active() == 1)
{
	Gtk::MessageDialog dialog(*this, "Validation parameters required");
	dialog.set_secondary_text("Validation parameters are required when \"test_net\" parameter is specified.");
	dialog.run();
}
else
{
	solverFileName = text_solverFileName.get_text();
	trainNetworkFileName = text_trainNetworkFileName.get_text();
	testNetworkFileName = text_testNetworkFileName.get_text();
	testIter = text_testIter.get_text();
	testInterval = text_testInterval.get_text();
	averageLoss = text_averageLoss.get_text();
	randomSample = text_randomSample.get_text();
	display = text_display.get_text();
	snapshot = text_snapshot.get_text();
	snapshotPrefix = text_snapshotPrefix.get_text();
	maxIter = text_maxIter.get_text();
	baseLearningRate = text_baseLearningRate.get_text();
	gamma = text_gamma.get_text();
	power = text_power.get_text();
	stepSize = text_stepSize.get_text();
	stepSizeValue = text_stepSizeValue.get_text();
	weightDecay = text_weightDecay.get_text();
	momentum = text_momentum.get_text();

	if(rbutton_enableDebugInfo_yes.get_active())
		debugInfo = "1";
	else if(rbutton_enableDebugInfo_no.get_active())
		debugInfo = "0";

	if(rbutton_enableTestComputeLoss_yes.get_active())
		testComputeLoss = "1";
	else if(rbutton_enableTestComputeLoss_no.get_active())
		testComputeLoss = "0";

	if(rbutton_typeSGD_yes.get_active())
		type = "1";
	else if(rbutton_typeAdadelta_yes.get_active())
		type = "AdaDelta";
	else if(rbutton_typeAdagrad_yes.get_active())
		type = "AdaGrad";
	else if(rbutton_typeAdam_yes.get_active())
		type = "Adam";
	else if(rbutton_typeRMSProp_yes.get_active())
		type = "RMSProp";
	else if(rbutton_typeNesterov_yes.get_active())
		type = "Nesterov";

	if(rbutton_learningRatePolicyFixed_yes.get_active())
		learningRatePolicy = "fixed";
	else if(rbutton_learningRatePolicyExp_yes.get_active())
		learningRatePolicy = "exp";
	else if(rbutton_learningRatePolicyStep_yes.get_active())
		learningRatePolicy = "step";
	else if(rbutton_learningRatePolicyInv_yes.get_active())
		learningRatePolicy = "inv";
	else if(rbutton_learningRatePolicyMultistep_yes.get_active())
		learningRatePolicy = "multistep";
	else if(rbutton_learningRatePolicyPoly_yes.get_active())
		learningRatePolicy = "poly";
	else if(rbutton_learningRatePolicySigmoid_yes.get_active())
		learningRatePolicy = "sigmoid";

	std::ofstream myfile;
	myfile.open(solverFileName);
	myfile << "#File generated using OpenDetection" << std::endl;
	myfile.close();
	myfile.open(solverFileName);
	if(!myfile)
	{
		Gtk::MessageDialog dialog(*this, "File Could not be Created");
		dialog.set_secondary_text("Make sure the destination exists or the file is writable");
		dialog.run();
	}
	std::cout << "Solver File Name saved as: " << solverFileName << std::endl;
	

	if(rbutton_trainNetworkFileType_net.get_active() == 1)
		myfile << "net: " << "\"" << trainNetworkFileName << "\"" << std::endl;
	else if(rbutton_trainNetworkFileType_tt.get_active() == 1)
		myfile << "train_net: " << "\"" << trainNetworkFileName << "\"" << std::endl;

	if(rbutton_enableTestNet_yes.get_active() == 1)
		myfile << "test_net: " << "\"" << testNetworkFileName << "\"" << std::endl;
	else if(rbutton_enableTestNet_no.get_active() == 1)
		myfile << "#test_net: " << "\"" << testNetworkFileName << "\"" << std::endl;

	if(rbutton_enableValidationParameters_yes.get_active() == 1)
	{
		myfile << "test_iter: " << testIter << std::endl;
		myfile << "test_interval: " << testInterval << std::endl;
	}
	else if(rbutton_enableValidationParameters_no.get_active() == 1)
	{
		myfile << "#test_iter: " << testIter << std::endl;
		myfile << "#test_interval: " << testInterval << std::endl;
	}

	if(rbutton_enableAverageLoss_yes.get_active() == 1)
		myfile << "average_loss: " << averageLoss << std::endl;
	else if(rbutton_enableAverageLoss_no.get_active() == 1)
		myfile << "#average_loss: " << averageLoss << std::endl;

	if(rbutton_enableRandomSample_yes.get_active() == 1)
		myfile << "random_seed: " << randomSample << std::endl;
	else if(rbutton_enableRandomSample_no.get_active() == 1)
		myfile << "#random_seed: " << randomSample << std::endl;

	
	myfile << "display: " << display << std::endl;
	myfile << "debug_info: " << debugInfo << std::endl;
	myfile << "snapshot: " << snapshot << std::endl;
	myfile << "test_compute_loss: " << testComputeLoss << std::endl;
	myfile << "snapshot_prefix: " << "\"" << snapshotPrefix << "\"" << std::endl;
	myfile << "max_iter: " << maxIter << std::endl;
	myfile << "type: " << "\"" << type << "\"" << std::endl;
	
	myfile << "lr_policy: " << "\"" << learningRatePolicy << "\"" << std::endl;
	myfile << "base_lr: " << baseLearningRate << std::endl;
	myfile << "gamma: " << gamma << std::endl;
	myfile << "power: " << power << std::endl;
	myfile << "stepsize: " << stepSize << std::endl;	
	myfile << "stepvalue: " << stepSizeValue << std::endl;
	
	myfile << "weight_decay: " << weightDecay << std::endl;
	myfile << "momentum: " << momentum << std::endl;


	myfile.close();
}
\endcode

2.4.4) Calling the solverProperties class from ODConvTrainer and the corresponding mnist curtom solver example{#commit2_fourth_change_4}
---

The solverProperties class object was called in detectors/global2D/training/ODConvTrainer.cpp file. This was done using the code 
\code{.cpp}
void ODConvTrainer::setSolverProperties(int argc, char *argv[])
{
	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
	SolverProperties solverProperties;
	solverProperties.set_default_geometry (10000, 10000);
	app->run(solverProperties);
	ODConvTrainer::solverLocation = solverProperties.solverFileName;
}
\endcode
The above code invoked the gtkmm solver window and in turn was used by the file examples/objectdetector/od_cnn_mnist_train_customSolver.cpp, where a ODTrainer object called the function mentioned above, the snippet from examples/objectdetector/od_cnn_mnist_train_customSolver.cpp is below,
\code{.cpp}
od::g2d::ODConvTrainer *mnist_trainer = new od::g2d::ODConvTrainer("","");
mnist_trainer->setSolverProperties(argc,argv);
mnist_trainer->startTraining();
\endcode

\n 
2.4.5)Features of solver creator{#commit2_fourth_change_5}
---

**1) The above code promts the user if any mistake is made from user-end.**

**2) Pressing update button every time may be time consuming, hence the latest commits involve the fact that without pressing the buttons the parameters cab ne edited**

**3) The main function of the update buttons after every parameter is make sure that, for future developments, if the intermediate parameters are to be accessed, the current version enables it.**

**4) Not many open source libraries had this functionality**


\n 
2.5) Network creator first version, commit 2.5{#commit2_fifth}
---

In this commit, network creator was added, based on gtkmm and caffe library, to the opendetection source. The [fragmented commit: Custom network designer added part1](https://github.com/abhi-kumar/opendetection/commit/768364812b6c30c2f27b6f768fec1366a9cb0885), involved additions of 15 code source files.

To understand each layer in caffe, please refer to [blog post here](https://abhishek4273.com/2016/02/07/ann-chapter-3-deep-learning-using-caffe-python/)

The major class, networkCreator, was introduced into files detectors/global2D/training/network.h and detectors/global2D/training/network.cpp. 

As mentioned earlier, it is clear as to how to initialize, place and show elements like buttons, radiobuttons, labels, and text-boxes. Herein a new elemet is introduced, dropDownBox.

2.5.1) Current Features to the {#commit2_fifth_change_1}
---

a) The activation category includes the following activation layers
  - Absolute Value (AbsVal) Layer
  - Exponential (Exp) Layer
  - Log Layer
  - Power Layer
  - Parameterized rectified linear unit (PReLU) Layer
  - Rectified linear unit (ReLU) Layer
  - Sigmoid Layer
  - Hyperbolic tangent (TanH) Layer

b) The critical category includes the most crucial layers
  - Accuracy Layer
  - Convolution Layer
  - Deconvolution layer
  - Dropout Layer
  - InnerProduct (Fully Connected) Layer
  - Pooling Layer
  - Softmax classification Layer
c) The weight initializers include the following options
  - Constant
  - Uniform
  - Gaussian
  - Positive Unit Ball
  - Xavier
  - MSRA
  - Bilinear
d) One more important feature included is that user can display the layers and simultaneously during the display delete the layers at the end.

 
2.5.2) How to introduce a dropdown menu example{#commit2_fifth_change_2}
---

In the header file, example, in network.h the following was added, please refer comments in the code below
\code{.cpp}
Gtk::ComboBox 		combo_activationLayerType;				//Box to hold all the drop boxes
class ModelColumns : public Gtk::TreeModel::ColumnRecord
{
	public:
		ModelColumns(){ add(m_col_id); add(m_col_name); add(m_col_extra);}
		Gtk::TreeModelColumn<int> m_col_id;				//Id to every drop down list
		Gtk::TreeModelColumn<Glib::ustring> m_col_name;			//Name to every drop down list
		Gtk::TreeModelColumn<Glib::ustring> m_col_extra;		//Extra details to every drop down list
};
ModelColumns 			column_activationLayerType;
Gtk::CellRendererText		cell_activationLayerType;
Glib::RefPtr<Gtk::ListStore> 	ref_activationLayerType;
\endcode

Similarly, for all other layer types comboCoxes, modelColumns etc were added into the code.

Now, in the cpp file, example, in network.cpp the following was added, please refer comments in the code below
\code{.cpp}
ref_activationLayerType = Gtk::ListStore::create(column_activationLayerType);		//create an object for list
combo_activationLayerType.set_model(ref_activationLayerType);				//add list to combobox

//First item in list
Gtk::TreeModel::Row row_activationLayerType = *(ref_activationLayerType->append());
row_activationLayerType[column_activationLayerType.m_col_id] = 1;
row_activationLayerType[column_activationLayerType.m_col_name] = "AbsVal";
row_activationLayerType[column_activationLayerType.m_col_extra] = "Absolute Value Layer";
combo_activationLayerType.set_active(row_activationLayerType);

//Second item in list
row_activationLayerType = *(ref_activationLayerType->append());
row_activationLayerType[column_activationLayerType.m_col_id] = 2;
row_activationLayerType[column_activationLayerType.m_col_name] = "Exp";
row_activationLayerType[column_activationLayerType.m_col_extra] = "Exponential Layer";

//Attach list items to combobox
combo_activationLayerType.pack_start(column_activationLayerType.m_col_id);
combo_activationLayerType.pack_start(column_activationLayerType.m_col_name);
combo_activationLayerType.set_cell_data_func(cell_activationLayerType,  sigc::mem_fun(*this, &NetworkCreator::on_cell_data_extra));
combo_activationLayerType.pack_start(cell_activationLayerType);
	
//Attach combobox to grid
m_grid1.attach(combo_activationLayerType,2,1,2,1);
combo_activationLayerType.signal_changed().connect( sigc::mem_fun(*this, &NetworkCreator::on_combo_changed) );
\endcode

Thus rest of the thisngs can be added.

The color to the listbox is added into the detectors/global2D/training/mainWindow.h file. The snippet below is added to the function on_cell_data_extra()

\code{.cpp}
auto row_activationLayerType = *iter;
const Glib::ustring extra_activationLayerType = row_activationLayerType[column_activationLayerType.m_col_extra];
if(extra_activationLayerType.empty())
	cell_activationLayerType.property_text() = "(none)";
else
	cell_activationLayerType.property_text() = "-" + extra_activationLayerType + "-";
cell_activationLayerType.property_foreground() = "green"; 
\endcode

The main function here, when combo is changed, data stored in the variables are updated using the on_combo_changed() function. The following is the code snippet

\code{.cpp}
Gtk::TreeModel::iterator iter_activationLayerType = combo_activationLayerType.get_active();
if(iter_activationLayerType)
{
	Gtk::TreeModel::Row row_activationLayerType = *iter_activationLayerType;
	if(row_activationLayerType)
	{
		int id_activationLayerType = row_activationLayerType[column_activationLayerType.m_col_id];
		Glib::ustring name_activationLayerType = row_activationLayerType[column_activationLayerType.m_col_name];
//			std::cout << " ID=" << id_activationLayerType << ", name=" << name_activationLayerType << std::endl;
		activationLayerTypeData = name_activationLayerType;
	}
}
\endcode 


2.5.3) Idea of multiple windows{#commit2_fifth_change_3}
---

For every drop down comboBox, one selected, and clicked the button next to it, a new window is opened. It as done usinf the functions

\code{.cpp}
void showWindow_main();
void showWindow_activationLayerType(Glib::ustring data);
void showWindow_displayWindow();
void showWindow_criticalLayerType(Glib::ustring data);
void showWindow_normalizationLayerType(Glib::ustring data);
void showWindow_lossLayerType(Glib::ustring data);
void showWindow_extraLayerType(Glib::ustring data);
\endcode

Each of these functions has an argument "data", this argument refers to the type of layer that needs to be appended. Each of these functions are placed into a different file, activationWindow.h, lossWindow.h, mainWindow.h, criticalWindow.h, normalizationWindow.h and extraWindow.h. And with regards to the argument "data", different elemts are shown on window. Say, when TanH is the argument, different elements are shown as to when Sigmoid is the argument.

2.5.4) Displaying network and deleting layer at the end{#commit2_fifth_change_4}
---

When the layers are appended into the network, displaying it is a necessity to make sure if everythig is proper or not. The code at displayWindow.h, inside the function showWindow_displayWindow(), enables the display. 

\code{.cpp}
void NetworkCreator::showWindow_displayWindow()
{
	remove();
	set_title("Display Entire Network");
	set_border_width(10);
	add(box_fullCnnLayerMatter);
	buffer_fullCnnLayerMatter->set_text(fullCnnLayerMatter);
	textView_fullCnnLayerMatter.set_buffer(buffer_fullCnnLayerMatter);
	show_all_children();
}
\endcode

Herein, the variable fullCnnLayerMatter gets updated everytime before display using a node from detectors/global2D/training/node.h. This file implements a linked list, which whenever a layer is added, adds a node to the list.

The structre of the node is as follows
\code{.cpp}
struct Node {
	Glib::ustring data;
	Node* nextLayer;
};
\endcode

If no layer has been added before, the list is initialized using,
\code{.cpp}
void initializeLayer(struct Node *headLayer, Glib::ustring data)
{
	headLayer->data = data;
	headLayer->nextLayer = NULL;
}

If list has been initialised, next upcoming layers are appended using,
\code{.cpp}
void appendLayer(struct Node *headLayer, Glib::ustring data)
{
	Node *newLayer = new Node;
	newLayer->data = data;
	newLayer->nextLayer = NULL;

	Node *currentLayer = headLayer;
	while(currentLayer)
	{
		if(currentLayer->nextLayer == NULL)
		{
			currentLayer->nextLayer = newLayer;
			return;
		}
		currentLayer = currentLayer->nextLayer;
	}
}
\endcode

The network's last layer can be deleted, with the button "Delete Layer" in the display window, with the base function as,
\code{.cpp}
bool deleteLayer(struct Node **headLayer, Node *deleteLayer) 
{
	Node *currentLayer = *headLayer;
	if(deleteLayer == *headLayer)
	{
		*headLayer = currentLayer->nextLayer;
		delete deleteLayer;
		return true;
	}
	
	while(currentLayer)
	{
		if(currentLayer->nextLayer == deleteLayer)
		{
			currentLayer->nextLayer = deleteLayer->nextLayer;
			delete deleteLayer;
			return true;
		}
		currentLayer = currentLayer->nextLayer;
	}
	return false;
}
\endcode


Any layer properties can be searched using the folowwing search function,
\code{.cpp}
struct Node *searchLayer(struct Node *headLayer, Glib::ustring data)
{
	Node *currentLayer = headLayer;
	while(currentLayer)
	{
		if(currentLayer->data == data) 
		{
			return currentLayer;
		}
		currentLayer = currentLayer->nextLayer;
	}
	std::cout << "No Layer " << data << " in the CNN." << std::endl;
}
\endcode

As mentioned earlier, when the network is to be displayed, the variable fullCnnLayerMatter,  is updated, using the following function,
\code{.cpp}
Glib::ustring displayCNN(struct Node *headLayer)
{
	Node *cnn = headLayer;
	Glib::ustring fullCnnLayerMatter = "";
	while(cnn)
	{
//		std::cout << cnn->data << std::endl;
		fullCnnLayerMatter += cnn->data;
		cnn = cnn->nextLayer;
	}
//	std::cout << std::endl;
//	std::cout << std::endl;
	return fullCnnLayerMatter;
}
\endcode

\n 
2.6) Network creator second version, commit 2.6{#commit2_sixth}
---

In this commit, network creator was appended with Normalization layer properties, based on gtkmm and caffe library, to the opendetection source. The [fragmented commit: Added Normalization layers in the customised trainer](https://github.com/abhi-kumar/opendetection/commit/c99ec1a7c8a5b913a50d62ceecbfea59fb8222a1), involved additions/changes of 3 code source files.

It had three Normalization layer options involved,
  - Batch Normalization (BatchNorm) Layer
  - Local Response Normalization (LRN) Layer
  - Multivariate Response Normalization (MVN) Layer


\n
2.7) Selective search based object locatization version 1, commit 2.7{#commit2_seventh}
---

In this commit, slective serach based object localization, based on opencv library, was added to the opendetection source. The [fragmented commit: Selective Search Beta Version Added](https://github.com/abhi-kumar/opendetection/commit/eebfee93d4fc82296d38dbb0e54d0a9a6e9f94fa), involved additions/changes of 21 code source files.
 

To understand the selective search based object localization algorithm, please refer to [link here](http://koen.me/research/selectivesearch/)

The algo, when put simply, involves,
  - Graph based image segmentation
  - Finding different features of the all the segmented parts
  - Finding closeness between the features of the neighboring parts
  - Merging the closest parts and continuing futher till the algorithm is breaked.


2.7.1) Graph based image segmentation{#commit2_seventh_change_1}
---

With proper permission (conversation through mails) from the author P. Felzenszwalb(pff@ai.mit.edu) the code from [link](http://cs.brown.edu/~pff/segment/) was adopted and slightly modified in order to get the results as per the requirement of the algorithm.

This part involves 10 major code files, all adopted from the same link mentioned above
  - detectors/global2D/localization/convolve.h
  - detectors/global2D/localization/disjoint-set.h
  - detectors/global2D/localization/filter.h
  - detectors/global2D/localization/image.h
  - detectors/global2D/localization/imconv.h
  - detectors/global2D/localization/imutil.h
  - detectors/global2D/localization/misc.h
  - detectors/global2D/localization/pnmfile.h
  - detectors/global2D/localization/segment-graph.h
  - detectors/global2D/localization/segment-image.h


2.7.2) Selective Search Base class{#commit2_seventh_change_2}
---

The class ODSelectiveSearchBase, detectors/global2D/localization/ODSelectiveSearchBase.cpp and detectors/global2D/localization/ODSelectiveSearchBase.h, derived over the public elements of ODDetector2D, has a set of very important functions, 
  - acuiring the image
  - preprocessing the image
  - using the 10 major code files mentioned above in a customized way to segment the image and extract the clustered components.

The header file has the following variables,
\code{.cpp}
Mat img, cluster, outputImg, sp_preProcessed, gray_mask;
int inputImageHeight;
int inputImageWidth;
int total_masks;
vector < vector <int> > sp;		//container for the cluster 
\endcode

In this class, the image is aquired using the following snippet from the .cpp file,
\code{.cpp}
void ODSelectiveSearchBase::acquireImages(string imageLocation, int imgWidth, int imgHeight)
{
	inputImageHeight = imgHeight;
	inputImageWidth = imgWidth;
	img = imread(imageLocation,1);
	resize(img, img, Size(imgWidth,imgHeight));
	cluster = imread(imageLocation,1);
	resize(cluster, cluster, Size(imgWidth,imgHeight));
	outputImg = imread(imageLocation,1);
	resize(outputImg, outputImg, Size(imgWidth,imgHeight));
	}
\endcode


The preprocessing is done using,
\code{.cpp}
Mat ODSelectiveSearchBase::preProcessImg(Mat image)
{
	vector<Mat> channels; 
	Mat img_hist_equalized;
	cvtColor(image, img_hist_equalized, CV_BGR2YCrCb); 
	split(img_hist_equalized,channels); 
	equalizeHist(channels[0], channels[0]); 
	merge(channels,img_hist_equalized);
	cvtColor(img_hist_equalized, img_hist_equalized, CV_YCrCb2BGR);
	return img_hist_equalized;
}
\endcode
Herein, the preprocessing is done as
  - conversion of BGR image to YCrCb
  - first channel, the one with the intensity is eualized
  - reconversion of eualized YCrCb image to BGR color type


This is followed by graph based image segmentation by the function, 
\code{.cpp}
vector < vector <int> > ODSelectiveSearchBase::getSuperPixels(Mat im, int &totalMasks, float Sigma, float K, float Min_size, string imageLocation)
\endcode


Image is first segmented,
\code{.cpp}
string img_location = imageLocation + "img.ppm";
imwrite(img_location, im);
float sigma = Sigma;
float k = K;
int min_size = Min_size;
image<rgb> *input = loadPPM(img_location.c_str());
int num_ccs; 
image<rgb> *seg = segment_image(input, sigma, k, min_size, &num_ccs);
image<uchar> *gr = imageRGBtoGRAY(seg);
int num = imRef(seg,0,0).r;
\endcode
Herein, the image after preprocessing, is stored in ".ppm" format as the segmentation code only prefers image in that format. Image is then segmented using the segment_image function and to find the number of segments, num, it is converted to grayscale and the number of colors there then represent the number of segments.


The next step is to create a list of those segments. It is not often possible to create an uchar grayscale image mask with opencv here, because, opencv supports color version from 0 to 255 and in most cases the segments are greater than 255. Thus, we first store, every pixel's value in the previous rgb image with the pixel's location into a text file named "segmented.txt".
\code{.cpp}
ofstream myfile;
myfile.open("segmented.txt");
for(int R = 0; R < seg->height(); R++)
{
	for(int C = 0; C < seg->width(); C++)
	{
		int numR, numG, numB, numGr;
		numR = imRef(seg,C,R).r;
		numG = imRef(seg,C,R).g;
		numB = imRef(seg,C,R).b;
		numGr = imRef(gr,C,R);
		myfile << numR << " " << numG << " " << numB << " " << numGr << endl;
	}
}
string output_location = "../images/img.ppm";
savePPM(seg, output_location.c_str());
myfile.close();
\endcode


Now the task was to create a uniform label for each segment, something like, first segment as 1, second as 2 and so on and this was carries out using,
\code{.cpp}
vector< vector <int> > mem;
mem.resize(num, std::vector<int>(3, 0));
vector <int> val;
val.resize(num, 0);
int insertion_mem_index = 1;

for(int i = 0; i < num; i++)
{
	infile >> R >> G >> B >> GR;
	if(i==0)
	{
		mem[i][0] = R;
		mem[i][1] = G;
		mem[i][2] = B;
		val[i] = maskValue;
		mask[H][W] = val[0];
	}
	else
	{
		vector <int> query = {R, G, B};
		vector <vector <int> > ::iterator it;
		auto pos =find(mem.begin(),mem.end(),query);
		if(pos != mem.end())
		{
			mask[H][W] = val[pos-mem.begin()];
		}
		else
		{
			mem[insertion_mem_index][0] = R;
			mem[insertion_mem_index][1] = G;
			mem[insertion_mem_index][2] = B;
			maskValue++;
			insertion_mem_index++;
			val[insertion_mem_index] = maskValue;
			mask[H][W] = maskValue;				
		}
	}
	W = W + 1;
	if(W==im.cols)
	{
		H = H + 1;
		W = 0;
	}
}

totalMasks = maskValue;
return mask;
\endcode


\n 
2.7.3) Selective Search Model class and example of selective search based localization{#commit2_seventh_change_3}
---

These introduced files, detectors/global2D/localization/ODSelectiveSearchModel.cpp and detectors/global2D/localization/ODSelectiveSearchModel.h, have the following responsibilities(not in order)
  - calculating histogram of the different features
  - finding neighbors for each of the clustered region
  - finding similarities( or closure distance) between two regions based on the histogram of different features
  - merging the closest regions
  - removing very small and very big clusters
  - adding ROIs to images based on merged regions


The functions will make more sense with a side by side explanation of the file /examples/objectdetector/od_localize_selective_search.cpp, which specifies an example of selective search based localization of objects.

This selective search has a set of 13 parameters which drive the entire algo here. The example's first part includes the base class,
\code{.cpp}
od::g2d::ODSelectiveSearchBase ss;
string imageLocation = "../examples/objectdetector/Localization_Images/";	//Para 1
string imageName = "sample1.png";						// Para 1.1
int imgWidth = 640;							//Para 2
int imgHeight = 480;							//Para 3
string im = imageLocation + imageName;	
ss.acquireImages(im, imgWidth, imgHeight);

ss.sp_preProcessed = ss.preProcessImg(ss.img);

float sigma = 0.5;							//Para 4
float k = 580;								//Para 5
int min_size = 50;							//Para 6
ss.sp = ss.getSuperPixels(ss.sp_preProcessed, ss.total_masks, sigma, k, min_size, imageLocation);
\endcode


Parameter 1 : Image file location, this is important because all the temporary files created will also be stored here

Parameter 1.1 : Image file name ( **make sure you don't name image as img.png or img.ppm** )

Parameter 2 : Height to which it has to be resized

Parameter 3 : Width to which it has to be resized

The functions acquireImages and preProcessImg have been discussed earlier.

Parameters 4,5,6 : These will be more specifically understood once selective search algorithm paper is read [here](http://koen.me/research/selectivesearch/)

getSuperPixels function mentioned above, as stated there too, is for clustering. 

The next part comes as creation of the model class object,
\code{.cpp}
od::g2d::ODSelectiveSearchModel regions[ss.total_masks];
int min_height = 20;							//Para 7
int min_width = 20;							//Para 8
od::g2d::refineRegions(ss.sp, ss.total_masks, regions, min_height, min_width);
float spSize = ss.sp.size() * ss.sp[0].size();
\endcode

Instead of creating a single object, an object is created for every clustered object in the form of array of objects. 

Parameter 7 : Any clustered region with a pixels size of less this height is not considered

Parameter 8 : Any clustered region with a pixels size of less this width is not considered 

This, discarding of the regions is carried out using the functions refineRegions,
\code{.cpp}
void refineRegions(vector < vector <int> > sp, int total_masks, ODSelectiveSearchModel regions[], int min_height, int min_width)
{
	for (int i = 0; i < total_masks; i++)
	{
		regions[i].setLabel(i);
		regions[i].min_x = 100000;
		regions[i].min_y = 100000;
		regions[i].max_x = -1;
		regions[i].max_y = -1;
	}
	for (int r = 0; r < sp.size(); r++)
	{
		for(int c = 0; c < sp[0].size(); c++)
		{
			regions[sp[r][c]].size++;
			if(regions[sp[r][c]].min_x > c)
				regions[sp[r][c]].min_x = c;
			if(regions[sp[r][c]].min_y > r)
				regions[sp[r][c]].min_y = r;
			if(regions[sp[r][c]].max_x < c)
				regions[sp[r][c]].max_x = c;
			if(regions[sp[r][c]].max_y < r)
				regions[sp[r][c]].max_y = r;
		}
	}
	for (int i = 0; i < total_masks; i++)
	{
		if((regions[i].max_x - regions[i].min_x > min_width) and (regions[i].max_y - regions[i].min_y > min_height))
			regions[i].validity = true;
		else
			regions[i].validity = false;
	}
}
\endcode
Another purpose of this function is to find the boundaries on these irregulary shaped clustered regions. The functions finds the minimum and maximum x and y pixel coordinates of each region


Next step is to find histogram of features of each of the regions,
\code{.cpp}
int histSize = 25;							//Para 9
float hist_range_min = 1;							//Para 10
float hist_range_max = 255;						//Para 11
od::g2d::createModel(ss.sp, ss.total_masks, ss.gray_mask, regions, histSize, hist_range_min, hist_range_max);
\endcode

Parameter 9: Size of the bin in the histogram of features

Parameter 10 and 11: Range of values to be considered while calculating the histogram

The function createModel is designed to find the histogram matrices,
\code{.cpp}
void createModel(vector < vector <int> > sp, int total_masks, Mat grayMask, ODSelectiveSearchModel regions[], int histSize, float hist_range_min, float hist_range_max)
{
	Mat regionMask = grayMask.clone();
	for (int i = 0; i < total_masks; i++)
	{
		regionMask = grayMask.clone();
		for (int r = 0; r < sp.size(); r++)
		{
			for(int c = 0; c < sp[0].size(); c++)
			{
				if(sp[r][c] != i)
					regionMask.at<uchar>(r,c) = 0;
			}
		}
		if(regions[i].size<200)
			regions[i].validity = false;
		//Hessian Matrix
		regions[i].xx_hist = get_hess_hist_xx(regionMask, histSize, hist_range_min, hist_range_max);
		regions[i].xy_hist = get_hess_hist_xy(regionMask, histSize, hist_range_min, hist_range_max);
		regions[i].yy_hist = get_hess_hist_yy(regionMask, histSize, hist_range_min, hist_range_max);
		//orientation Matrix
		regions[i].orientation_image_hist = get_orientation_hist(regionMask, histSize, hist_range_min, hist_range_max);
		//Differential Excitation Matrix
		regions[i].differential_excitation_hist = get_diff_exci_hist(regionMask, histSize, hist_range_min, hist_range_max);
		//Color Histogram
		float range[] = { hist_range_min, hist_range_max } ;
		const float* histRange = { range };
		bool uniform = true; bool accumulate = false;
		calcHist(&grayMask, 1, 0, Mat(), regions[i].color_hist, 1, &histSize, &histRange, uniform, accumulate );
	}
}
\endcode

**Note: There's an hidden parameter here, which decides the region's validity. It works on the conception that every region should have atleast a certain number of pixels, here 200. This number can be manipulated if needed**

Four matrices are calculated:
  - [Hessian Matrix](http://mathworld.wolfram.com/Hessian.html)
  - [Orientation Matrix](http://www.ee.oulu.fi/~jiechen/paper/TPAMI2009-WLD.pdf)
  - [Differential Excitation Matrix](http://www.ee.oulu.fi/~jiechen/paper/TPAMI2009-WLD.pdf)
  - Color Histogram Matrix

Hessian Matrix is calculated in xx, xy and yy type double differentiations, the matrices used are ( in same order),
\code{.cpp}
kernel_filter_1 = (Mat_<double>(7,7) << 1.57130243e-04, 7.17839338e-04, 0, -1.76805171e-03, 0, 7.17839338e-04, 1.57130243e-04,
								1.91423823e-03, 8.74507340e-03, 0, -2.15392793e-02, 0, 8.74507340e-03, 1.91423823e-03,
								8.57902057e-03, 3.91926999e-02, 0, -9.65323526e-02, 0, 3.91926999e-02, 8.57902057e-03,
								1.41444137e-02, 6.46178379e-02, 0, -1.59154943e-01, 0, 6.46178379e-02, 1.41444137e-02,
								8.57902057e-03, 3.91926999e-02, 0, -9.65323526e-02, 0, 3.91926999e-02, 8.57902057e-03,
								1.91423823e-03, 8.74507340e-03, 0, -2.15392793e-02, 0, 8.74507340e-03, 1.91423823e-03,
								1.57130243e-04, 7.17839338e-04, 0, -1.76805171e-03, 0, 7.17839338e-04, 1.57130243e-04
						);

 
kernel_filter_2 = (Mat_<double>(7,7) << 0.00017677, 0.00143568, 0.00321713, 0, -0.00321713, -0.00143568, -0.00017677,
								0.00143568, 0.0116601, 0.02612847, 0, -0.02612847, -0.0116601, -0.00143568,
								0.00321713, 0.02612847, 0.05854983, 0, -0.05854983, -0.02612847, -0.00321713,
								0, 0, 0, 0, 0, 0, 0,
								-0.00321713, -0.02612847, -0.05854983, 0, 0.05854983, 0.02612847, 0.00321713,
								-0.00143568, -0.0116601, -0.02612847, 0, 0.02612847, 0.0116601, 0.00143568,
								-0.00017677, -0.00143568, -0.00321713, 0, 0.00321713, 0.00143568, 0.00017677
						  ); 


kernel_filter_3 = (Mat_<double>(7,7) << 
				1.57130243e-04, 1.91423823e-03, 8.57902057e-03, 1.41444137e-02, 8.57902057e-03, 1.91423823e-03, 1.57130243e-04,
				7.17839338e-04, 8.74507340e-03, 3.91926999e-02, 6.46178379e-02, 3.91926999e-02, 8.74507340e-03, 7.17839338e-04,
				0.00000000e+00, 0.00000000e+00, 0.00000000e+00, 0.00000000e+00, 0.00000000e+00, 0.00000000e+00, 0.00000000e+00,
				-1.76805171e-03, -2.15392793e-02, -9.65323526e-02, -1.59154943e-01, -9.65323526e-02, -2.15392793e-02, -1.76805171e-03,
				0.00000000e+00, 0.00000000e+00, 0.00000000e+00, 0.00000000e+00, 0.00000000e+00, 0.00000000e+00, 0.00000000e+00,
				7.17839338e-04, 8.74507340e-03, 3.91926999e-02, 6.46178379e-02, 3.91926999e-02, 8.74507340e-03, 7.17839338e-04,
				1.57130243e-04, 1.91423823e-03, 8.57902057e-03, 1.41444137e-02, 8.57902057e-03, 1.91423823e-03, 1.57130243e-04
						  );
\endcode


The Orientation matrix is calculated as,
\code{.cpp}
Mat get_orientation_hist(Mat regionMask, int histSize, float hist_range_min, float hist_range_max)
{
	Mat kernel_filter_1(3,3, CV_32FC1,1);
	kernel_filter_1 = (Mat_<double>(3,3) << 1, 1, 1, 1, -8, 1, 1, 1, 1);
	Mat kernel_filter_2(3,3, CV_32FC1,1);
	kernel_filter_2 = (Mat_<double>(3,3) << 0,0,0,0,1,0,0,0,0);
	Mat kernel_filter_3(3,3, CV_32FC1,1);
	kernel_filter_3 = (Mat_<double>(3,3) << 1,2,1,0,0,0,-1,-2,-1);
	Mat kernel_filter_4(3,3, CV_32FC1,1);
	kernel_filter_4 = (Mat_<double>(3,3) << 1,0,-1,2,0,-2,1,0,-1);
	Mat image_filtered_v1;
	Mat image_filtered_v2;
	Mat image_filtered_v3;	
	Mat image_filtered_v4;
	int temp30;	
	//filtering
	filter2D(regionMask, image_filtered_v1, -1, kernel_filter_1,Point(-1,-1), 0,BORDER_DEFAULT );
	filter2D(regionMask, image_filtered_v2, -1, kernel_filter_2,Point(-1,-1), 0,BORDER_DEFAULT );
	filter2D(regionMask, image_filtered_v3, -1, kernel_filter_3,Point(-1,-1), 0,BORDER_DEFAULT );
	filter2D(regionMask, image_filtered_v4, -1, kernel_filter_4,Point(-1,-1), 0,BORDER_DEFAULT );

	//Orientation New
	float temp_5;
	float temp_6;
	float temp_7_theta;
	float temp_8_theta_dash;
	int temp_9_theta_dash_quantized;
	float quantized_1[12] = {0,1,2,3,4,5,6,7,8,9,10,11};
	int quantized_count_1 = 0;
	float orientation_image_matrix[regionMask.rows][regionMask.cols];
	Mat orientation_image = regionMask.clone();
	for(int r = 0; r < regionMask.rows; r++)
	{
		for(int c = 0; c < regionMask.cols; c++)
		{
			orientation_image_matrix[r][c] = 0;
		}
	}
	for(int r = 0; r < regionMask.rows; r++)
	{
		for(int c = 0; c < regionMask.cols; c++)
		{
			temp_5 = image_filtered_v3.at<schar>(r,c);
			temp_6 = image_filtered_v4.at<schar>(r,c);
			if(temp_6 != 0 && temp_5 != 0)
			{
				temp_7_theta = atan(temp_5/temp_6);
			}
			else if(temp_6 == 0 && temp_5 > 0)
			{
				temp_7_theta = M_PI/2;
			}
			else if(temp_6 == 0 && temp_5 < 0)
			{
				temp_7_theta = -M_PI/2;
			}
			else if(temp_6 == 0 && temp_5 == 0)
			{
				temp_7_theta = 0;
			}
			else if(temp_6 != 0 && temp_5 == 0)
			{
				temp_7_theta = 0;
			}			

			if(temp_5 >= 0 && temp_6 >= 0)
			{
				temp_8_theta_dash = temp_7_theta;
			}
			else if(temp_5 < 0 && temp_6 >= 0)
			{
				temp_8_theta_dash = temp_7_theta + M_PI;
			}
			else if(temp_5 < 0 && temp_6 < 0)
			{
				temp_8_theta_dash = temp_7_theta + M_PI;
			}
			else if(temp_5 >= 0 && temp_6 < 0)
			{
				temp_8_theta_dash = temp_7_theta + 2*M_PI;
			}
			temp_9_theta_dash_quantized = floor((temp_8_theta_dash*11)/(2*M_PI));
			orientation_image_matrix[r][c] = temp_9_theta_dash_quantized;
			orientation_image.at<uchar>(r,c) = temp_9_theta_dash_quantized; 
		}
	}
/*	for(int r = 0; r < img.rows; r++)
	{
		for(int c = 0; c < img.cols; c++)
		{
			cout << orientation_image_matrix[r][c] << " ";
		}
		cout << endl;
	}
*/
	float range[] = { hist_range_min, hist_range_max } ;
	const float* histRange = { range };
	bool uniform = true; bool accumulate = false;
	Mat orientation_image_hist;

	/// Compute the histograms:
	calcHist( &orientation_image, 1, 0, Mat(), orientation_image_hist, 1, &histSize, &histRange, uniform, accumulate );
	return orientation_image_hist;
}
\endcode


The differential excitation matrix is calculated as,
\code{.cpp}
Mat get_diff_exci_hist(Mat regionMask, int histSize, float hist_range_min, float hist_range_max)
{
	Mat kernel_filter_1(3,3, CV_32FC1,1);
	kernel_filter_1 = (Mat_<double>(3,3) << 1, 1, 1, 1, -8, 1, 1, 1, 1);
	Mat kernel_filter_2(3,3, CV_32FC1,1);
	kernel_filter_2 = (Mat_<double>(3,3) << 0,0,0,0,1,0,0,0,0);
	Mat kernel_filter_3(3,3, CV_32FC1,1);
	kernel_filter_3 = (Mat_<double>(3,3) << 1,2,1,0,0,0,-1,-2,-1);
	Mat kernel_filter_4(3,3, CV_32FC1,1);
	kernel_filter_4 = (Mat_<double>(3,3) << 1,0,-1,2,0,-2,1,0,-1);
	Mat image_filtered_v1;
	Mat image_filtered_v2;
	Mat image_filtered_v3;	
	Mat image_filtered_v4;
	int temp30;	
	//filtering
	filter2D(regionMask, image_filtered_v1, -1, kernel_filter_1,Point(-1,-1), 0,BORDER_DEFAULT );
	filter2D(regionMask, image_filtered_v2, -1, kernel_filter_2,Point(-1,-1), 0,BORDER_DEFAULT );
	filter2D(regionMask, image_filtered_v3, -1, kernel_filter_3,Point(-1,-1), 0,BORDER_DEFAULT );
	filter2D(regionMask, image_filtered_v4, -1, kernel_filter_4,Point(-1,-1), 0,BORDER_DEFAULT );

	//Differential Excitation New
	float temp_1;
	float temp_2;
	float temp_3_alpha;
	float temp_4_quantized_alpha;
	int quantized[8] = {0,1,2,3,4,5,6,7};
	int quantized_count = 0;
	int differential_excitation_image_matrix[regionMask.rows][regionMask.cols];
	Mat differential_excitation_image = regionMask.clone();

	for(int r = 0; r < regionMask.rows; r++)
	{
		for(int c = 0; c < regionMask.cols; c++)
		{
			differential_excitation_image_matrix[r][c] = 0;
		}
	}
	for(int r = 0; r < regionMask.rows; r++)
	{
		for(int c = 0; c < regionMask.cols; c++)
		{
			temp_1 = image_filtered_v1.at<schar>(r,c);
			temp_2 = image_filtered_v2.at<schar>(r,c);
			if(temp_2 != 0)
			{
				temp_3_alpha = atan(temp_1/temp_2);
			}
			else if(temp_2 == 0 && temp_1 > 0)
			{
				temp_3_alpha = M_PI/2;
			}
			else if(temp_2 == 0 && temp_1 < 0)
			{
				temp_3_alpha = -M_PI/2;
			}
			else if(temp_2 == 0 && temp_1 == 0)
			{
				temp_3_alpha = 0;
			}
			temp_4_quantized_alpha = floor(((temp_3_alpha + M_PI/2)/M_PI)*7);
			differential_excitation_image_matrix[r][c] = temp_4_quantized_alpha;
			differential_excitation_image.at<uchar>(r,c) = temp_4_quantized_alpha;
		}
	}
/*	for(int r = 0; r < img.rows; r++)
	{
		for(int c = 0; c < img.cols; c++)
		{
			cout << differential_excitation_image_matrix[r][c] << " ";
		}
		cout << endl;
	}
*/
	float range[] = { hist_range_min, hist_range_max } ;
	const float* histRange = { range };
	bool uniform = true; bool accumulate = false;
	Mat differential_excitation_hist;

	/// Compute the histograms:
	calcHist( &differential_excitation_image, 1, 0, Mat(), differential_excitation_hist, 1, &histSize, &histRange, uniform, accumulate );
	return differential_excitation_hist;
}
\endcode


And the color histogram is calculated as,
\code{.cpp}
calcHist(&grayMask, 1, 0, Mat(), regions[i].color_hist, 1, &histSize, &histRange, uniform, accumulate );
\endcode


After this the major function, extractRois is called,
\code{.cpp}
int numRounds = ss.total_masks/2;					//Para 12
int minRegionSize = 200;						//Para 13
vector < vector <int> > pts = od::g2d::extractROIs(ss.total_masks, regions, numRounds, spSize, ss.sp, ss.img, ss.gray_mask, minRegionSize, histSize, hist_range_min, hist_range_max);
\endcode

The Parameter numRounds indirectly manipulates the number of ROIs to be found in direct proportion.

The function extractROI starts with a loop,
\code{.cpp}
while(checkRounds(totals, regions, numRounds) and value > 0)
\endcode

This checkRounds function is,
\code{.cpp}
bool checkRounds(int totals, ODSelectiveSearchModel regions[], int numRounds)
{
	int num = 0;
	for(int i = 0; i < totals; i++)
	{
		if(regions[i].validity == false)
		{
			num++;
		}
	}
//	cout << "num = " << num << endl;
	if(num > numRounds)
		return true;
	else
		return false;
}
\endcode
It functions in two way,
  - Checks whether numRounds limits is reached or not
  - A round is considered only when its validity is false, i.e., if number of rounds with validy false reach numRounds limit then code is stopped


Every loop inside extractRoi goes through,
\code{.cpp}
vector < vector <int> > sp_neighbors = findNeighbors(regions, total_masks, img, sp);
vector <float> similarities;
for(int i=0; i<sp_neighbors.size(); i++)
{

	float sim = calcSimilarities(regions[sp_neighbors[i][0]],regions[sp_neighbors[i][1]], spSize); 	
//			cout << i << "    " << sp_neighbors[i][0] << " " << sp_neighbors[i][1] << "    " << sim << endl;
	similarities.push_back(sim);
}

//finding closest two regions
value = min_element(similarities.begin(), similarities.end()) - similarities.begin();
//		cout << "in here" << endl;

//merging
mergeRegions(value, regions, sp_neighbors, gray_mask, sp, minRegionSize, histSize, hist_range_min, hist_range_max);
//		cout << "value = " << value << endl;
for(int i = 0; i < total_masks; i++)
{
	if(regions[i].validity == true)
	{
		vector <int> temp;
		temp.push_back(regions[i].min_x);
		temp.push_back(regions[i].min_y);			
		temp.push_back(regions[i].max_x);
		temp.push_back(regions[i].max_y);
		pts.push_back(temp);
//			rectangle(outputImg, Point(regions[i].min_x, regions[i].min_y), Point(regions[i].max_x, regions[i].max_y), Scalar(0, 0, 255));
	}
}
\endcode


The first line, with the fuction, findNeighbors(),
\code{.cpp}
bool checkNeighbors(ODSelectiveSearchModel a, ODSelectiveSearchModel b)
{
	if( 
		((a.min_x < b.min_x) and (b.min_x < a.max_x) and (a.min_y < b.min_y) and (b.min_y < a.max_y))
		or
		((a.min_x < b.max_x) and (b.max_x < a.max_x) and (a.min_y < b.max_y) and (b.max_y < a.max_y)) 
		or
		((a.min_x < b.min_x) and (b.min_x < a.max_x) and (a.min_y < b.max_y) and (b.max_y < a.max_y)) 
		or
		((a.min_x < b.max_x) and (b.min_x < a.max_x) and (a.min_y < b.max_y) and (b.max_y < a.max_y))
	)
	{

		return true;
	}

	return false;
}

vector < vector <int> > findNeighbors(ODSelectiveSearchModel regions[], int total_masks, Mat regionMask, vector < vector <int> > sp)
{
	vector < vector <int> > neighbors;
	vector <int> rows;
	rows.push_back(0);
	rows.push_back(0);
	int num = 0;
	for(int i = 1; i < total_masks-1; i++)
	{
		for(int j = i+1; j < i+20; j++)
		{
			if(j<total_masks-2)
			{
				if(checkNeighbors(regions[i], regions[j]) and regions[i].validity == true and regions[j].validity == true)
				{	
					rows[0] = i;
					rows[1] = j;
					neighbors.push_back(rows);
				}
			}
		}
	}
	return neighbors;
}
\endcode
For every region, its just next region is foundout and then it is stored as a pair in vector neighbors.


Then, in the loop, 
\code{.cpp}
vector <float> similarities;
for(int i=0; i<sp_neighbors.size(); i++)
{

	float sim = calcSimilarities(regions[sp_neighbors[i][0]],regions[sp_neighbors[i][1]], spSize); 	
//			cout << i << "    " << sp_neighbors[i][0] << " " << sp_neighbors[i][1] << "    " << sim << endl;
	similarities.push_back(sim);
}
\endcode
For every region, similarities are calculated for every neighbor using the function below,
\code{.cpp}
float calcSimilarities(ODSelectiveSearchModel a, ODSelectiveSearchModel b, float spSize)
{
	double sim = 0.0;
	sim += compareHist( a.xx_hist, b.xx_hist, 1);	
	sim += compareHist( a.xy_hist, b.xy_hist, 1);	
	sim += compareHist( a.yy_hist, b.yy_hist, 1);	
	sim += compareHist( a.orientation_image_hist, b.orientation_image_hist, 1);	
	sim += compareHist( a.differential_excitation_hist, b.differential_excitation_hist, 1);	
	sim += compareHist( a.color_hist, b.color_hist, 1);
	sim += 100 * ((a.size + b.size)/spSize);
	double bbsize = ((max(a.max_x, b.max_x) - min(a.min_x, b.min_x))* (max(a.max_y, b.max_y) - min(a.min_y, b.min_y)) );
	sim += 100*((bbsize - a.size - b.size) / spSize);
	return sim;
}
\endcode

Two regions are close if the similarity measure is less.
\code{.cpp}
value = min_element(similarities.begin(), similarities.end()) - similarities.begin();
\endcode

The region with closest( minimum) value are then merged,
\code{.cpp}
void mergeRegions(int value, ODSelectiveSearchModel regions[], vector < vector <int> > sp_neighbors, Mat grayMask, vector < vector <int> > sp, int minRegionSize, int histSize, float hist_range_min, float hist_range_max)
{

	regions[sp_neighbors[value][0]].validity = true;
	regions[sp_neighbors[value][1]].validity = false;
	regions[sp_neighbors[value][0]].min_x = min(regions[sp_neighbors[value][0]].min_x, regions[sp_neighbors[value][1]].min_x);
	regions[sp_neighbors[value][0]].max_y = max(regions[sp_neighbors[value][0]].max_y, regions[sp_neighbors[value][1]].max_y);
	regions[sp_neighbors[value][0]].min_x = min(regions[sp_neighbors[value][0]].min_x, regions[sp_neighbors[value][1]].min_x);
	regions[sp_neighbors[value][0]].max_y = max(regions[sp_neighbors[value][0]].max_y, regions[sp_neighbors[value][1]].max_y);
	regions[sp_neighbors[value][0]].size = regions[sp_neighbors[value][0]].size + regions[sp_neighbors[value][1]].size;

	Mat regionMask = grayMask.clone();
	int i = sp_neighbors[value][0];
	for (int r = 0; r < sp.size(); r++)
	{
		for(int c = 0; c < sp[0].size(); c++)
		{
			if(sp[r][c] != i)
				regionMask.at<uchar>(r,c) = 0;
		}
	}
	if(regions[i].size<minRegionSize)
		regions[i].validity = false;
//	cout << i << " hessian " << regionMask.channels() << endl;
	//Hessian Matrix
	regions[i].xx_hist = get_hess_hist_xx(regionMask, histSize, hist_range_min, hist_range_max);
	regions[i].xy_hist = get_hess_hist_xy(regionMask, histSize, hist_range_min, hist_range_max);
	regions[i].yy_hist = get_hess_hist_yy(regionMask, histSize, hist_range_min, hist_range_max);

//	cout << i << " orien" << endl;
	//orientation Matrix
	regions[i].orientation_image_hist = get_orientation_hist(regionMask, histSize, hist_range_min, hist_range_max);

//	cout << i << " diff" << endl;
	//Differential Excitation Matrix
	regions[i].differential_excitation_hist = get_diff_exci_hist(regionMask, histSize, hist_range_min, hist_range_max);

//	cout << i << " color" << endl;
	//Color Histogram
	float range[] = { hist_range_min, hist_range_max } ;
	const float* histRange = { range };
	bool uniform = true; bool accumulate = false;
	calcHist(&grayMask, 1, 0, Mat(), regions[i].color_hist, 1, &histSize, &histRange, uniform, accumulate );
}
\endcode

Thus this merging, calculating features, and scanning for new neighbors is continued till while loop continues. The result( all ROIs) is stored in file region_of_interests.txt in the folder example/objectdetector/Localization_Images

**This selective search algo takes around 20-25 seconds to calculate bounding boxes with the parameters set in the example**

Happy Coding!!! 


\n 
Commit 3 {#commit3}
===

This commit, [link to commit:CNN_GPU branch added successfully](https://github.com/abhi-kumar/opendetection/commit/10dea203378cb5c2ae16ca25552e423422e33690), was issued to add cnn-caffe based applications, for gpu based systems along with cpu based systems,. The commit had changes into 17 files, of which we have talked about most of them in previous commit documentation. Its a combination of set of commits made earler, put here together for better explanation of each of them. 

The major addition was to implement mode selector on the basis of mode of compilation of library,
\code{.cpp}
#if(WITH_GPU)
Caffe::SetDevice(0);
Caffe::set_mode(Caffe::GPU);
#else
Caffe::set_mode(Caffe::CPU);
#endif
\endcode

Thus this commit was essential to make sure the library compiled on both cpu and gpu based systems.

Happy Coding!!!


\n 
Commit 4 {#commit4}
===

This commit, [link to commit:Modified examples by removing framegenerator header](examples/objectdetector/od_cnn_mnist_classification.cpp), was issued to make sure caffe libraries and vtk libraries didn't clash while running examples on gpu based systems. The commit had changes into 4 files.

In all the files, the line which included,
\code{.cpp}
#include "common/utils/ODFrameGenerator.h"
\endcode

was erased out, and the issue was marked resolved.

Happy Coding!!!


\n 
Commit 5 {#commit5}
===

This commit, [link to commit:Updated Network Design will all essential Layers](https://github.com/abhi-kumar/opendetection/commit/484df2ce77c0104b96f47178c7cf5c43d30c8efd), was issued to complete all the elements left out in the version 1 of ther network-creator.

**The new layers added were**

1) Loss Layers:
  - Hinge Loss Layer
  - Contrastive Loss Layer
  - Eucledean Loss Layer
  - Multinomial Logistig Loss Layer
  - Sigmoid Cross Entropy Loss Layer

2) Data and Extra Layers:
  - Maximum Argument (ArgMAx) Layer
  - Binomial Normal Log Likelihood (BNLL) Layer
  - Element wise operation (Eltwise) Layer
  - Image Data Layer
  - LMDB/LEVELDB Data Layer

These additions almost included all the required layers in caffe, the left out HDF Data layer was added later.

Happy Coding!!!


\n 
Commit 6 {#commit6}
===

This commit, [link to commit:AAM Classification example added](https://github.com/abhi-kumar/opendetection/commit/20d1fbf8abc00fcaad2c6067240e2eea758f7cdd), was issued to add one of my personal researches. This commit included a prediction of Active Appearance Mocel Points on face using Convolutional Neural Networks. Very few works exist on this end, and hence the purpose behind taking up the research. This is a very crude and preliminary model of the research, just for the young users to be encouraged as to the extent to which cnn may work and how opendetection algorithm would help facilitate the same.

To understand AAM facial points, please refer [link](http://arxiv.org/abs/1410.1037)

The dataset was obtained from [link](https://www.kaggle.com/c/facial-keypoints-detection/data)

The dataset was trained on the network,
\code{.prototxt}
name: "multiple_output"
input: "data"
input_shape {
  dim: 1
  dim: 3
  dim: 96
  dim: 96
}
layer {
  name: "conv1"
  type: "Convolution"
  bottom: "data"
  top: "conv1"
  param {
    lr_mult: 1
  }
  param {
    lr_mult: 2
  }
  convolution_param {
    num_output: 32
    pad: 2
    kernel_size: 5
    stride: 1
    weight_filler {
      type: "gaussian"
      std: 0.01
    }
    bias_filler {
      type: "constant"
    }
  }
}
layer {
  name: "pool1"
  type: "Pooling"
  bottom: "conv1"
  top: "pool1"
  pooling_param {
    pool: MAX
    kernel_size: 3
    stride: 2
  }
}
layer {
  name: "relu1"
  type: "ReLU"
  bottom: "pool1"
  top: "pool1"
}
layer {
  name: "norm1"
  type: "LRN"
  bottom: "pool1"
  top: "norm1"
  lrn_param {
    local_size: 3
    alpha: 5e-05
    beta: 0.75
    norm_region: WITHIN_CHANNEL
  }
}
layer {
  name: "conv2"
  type: "Convolution"
  bottom: "norm1"
  top: "conv2"
  param {
    lr_mult: 1
  }
  param {
    lr_mult: 2
  }
  convolution_param {
    num_output: 32
    pad: 2
    kernel_size: 5
    stride: 1
     weight_filler {
      type: "gaussian"
      std: 0.01
    }
    bias_filler {
      type: "constant"
    }
  }
}
layer {
  name: "relu2"
  type: "ReLU"
  bottom: "conv2"
  top: "conv2"
}
layer {
  name: "pool2"
  type: "Pooling"
  bottom: "conv2"
  top: "pool2"
  pooling_param {
    pool: AVE
    kernel_size: 3
    stride: 2
  }
}
layer {
  name: "norm2"
  type: "LRN"
  bottom: "pool2"
  top: "norm2"
  lrn_param {
    local_size: 3
    alpha: 5e-05
    beta: 0.75
    norm_region: WITHIN_CHANNEL
  }
}
layer {
  name: "conv3"
  type: "Convolution"
  bottom: "norm2"
  top: "conv3"
  convolution_param {
    num_output: 64
    pad: 2
    kernel_size: 5
    stride: 1
     weight_filler {
      type: "gaussian"
      std: 0.01
    }
    bias_filler {
      type: "constant"
    }
  }
}
layer {
  name: "relu3"
  type: "ReLU"
  bottom: "conv3"
  top: "conv3"
}
layer {
  name: "pool3"
  type: "Pooling"
  bottom: "conv3"
  top: "pool3"
  pooling_param {
    pool: AVE
    kernel_size: 3
    stride: 2
  }
}
layer {
  name: "ip1"
  type: "InnerProduct"
  bottom: "pool3"
  top: "ip1"
  param {
    lr_mult: 1
    decay_mult: 250
  }
  param {
    lr_mult: 2
    decay_mult: 0
  }
  inner_product_param {
    num_output: 900
     weight_filler {
      type: "gaussian"
      std: 0.01
    }
    bias_filler {
      type: "constant"
    }
  }
}
layer {
  name: "ip2"
  type: "InnerProduct"
  bottom: "ip1"
  top: "ip2"
  param {
    lr_mult: 1
    decay_mult: 250
  }
  param {
    lr_mult: 2
    decay_mult: 0
  }
  inner_product_param {
    num_output: 30
     weight_filler {
      type: "gaussian"
      std: 0.01
    }
    bias_filler {
      type: "constant"
    }
  }
}
# ----------------------------------------------------------------
# ----------------- Multi-label Loss Function  -------------------
# ----------------------------------------------------------------
layer {
  name: "prob"
  type: "Sigmoid"
  bottom: "ip2"
  top: "prob"
}
\endcode


**Here When cpp version based elements of caffe library were used, the output produced extremely deviant results from the one obtained using python wrapper of caffe**

The cpp version add the following function into detectors/global2D/detection/ODConvClassification.cpp,
\code{.cpp}
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
	Blob<float>* output_layer = net.output_blobs()[0];
	const float* begin = output_layer->cpu_data();
	const float* end = begin + output_layer->channels();
	return std::vector<float>(begin, end);
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
//			net_m.Forward();   # for newer versions of caffe
	Blob<float>* output_layer = net_m.output_blobs()[0];
	const float* begin = output_layer->cpu_data();
	const float* end = begin + output_layer->channels();
	return std::vector<float>(begin, end);
}
\endcode 


**The issue was that irrespective of the input, the output remained same. This issues still unresolved**


As a temporary resolt, the following python wrapper was called,
\code{.cpp}
import numpy as np
import caffe
import sys
import cv2

if(sys.argv[5] == "gpu"):
	caffe.set_mode_gpu()
	caffe.set_device(0)
else:
	caffe.set_mode_cpu()


net = caffe.Net(sys.argv[1], sys.argv[2], caffe.TEST)

transformer = caffe.io.Transformer({'data': net.blobs['data'].data.shape})
transformer.set_transpose('data',(2,0,1))

img = caffe.io.load_image (sys.argv[3])
net.blobs['data'].data[...] = transformer.preprocess('data', img)

out = net.forward ()
predicts = out['prob']

print "Predicted label:"
predicts = predicts*255
print predicts[0]

img = cv2.imread(sys.argv[3])
f = open(sys.argv[4],'w')
for i in range(15):
	x = (predicts[0][2*i])
	y = (predicts[0][2*i+1])
	x = int(x)
	y = int(y)
	cv2.circle(img, (x,y), 1, (255,255,255), 2, 8, 0)
	stringVal = str(x) + " " + str(y)
	f.write(stringVal)
	f.write('\n')

cv2.imshow("img", img)
cv2.waitKey(0)
\endcode

This wrapper code was called from the function of ODConvClassification,
\code{.cpp}
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
\endcode
The calling was done using system() function.

The example, examples/objectdetector/od_cnn_aam_classification_python_mode.cpp, like the mnist classify example has user help option present. The detected points are posted to a file "output.txt", which is stored in the folder, examples/objectdetector/AAM_Classify.


Happy Coding!!!


\n 
Commit 7 {#commit7}
===

This commit, [link to commit:Annotator Version 1 Added](https://github.com/abhi-kumar/opendetection/commit/e4c931112f1047a8f81695d30f1f81620eb54f67), was issued in order to introduce a image annotation tool. Annotation tool is supposed to be very important part of object detection. Almost every cnn based object detection training and classification involves annotation of the datatset. If it is included in the library itself then the users work of fetching annotator from outside would be cleared off.


7.1) Features and usage of the version 1 of the annotator {#commit7_first}
---

The features and some usage points involved are:
  - User may load a single image from a location using the "Select the image location" button or the user may point towards a complete image dataset folder.
  - Even if the user points to a dataset folder, there exists an option of choosing an image from some another location while the annotation process is still on.
  - Even if user selects a single image, the user may load more single images without changing the type of annotation.
  - The first type of annotation facility is, annotating one bounding box per image.
  - The second, annotating and cropping one bounding box per image.
  - The third one, annotating multiple bounding boxes per image, with attached labels.
  - If a user makes mistake in annotation, the annotation can be reset too.


**Note: Every image that is loaded, is resized to 640x480 dimensions, but the output file has points of the bounding boxes as the original image size**


The output files generated in the three cases have annotation details as,
  - First case, every line in the output text file has a image name followed by four points x1 y2 x2 y2, first two representing top left coordinate of the box and the last two representing bottom right coordinates of the box.
  - Second case, every line in the output text file has a image name followed by four points x1 y2 x2 y2, first two representing top left coordinate of the box and the last two representing bottom right coordinates of the box. The cropped images are stored in the same folder as the original image, with name, <original_image_name>_cropped.<extension_of_the_original_image> 
  - Third case, every line in the output text file has a image name followed by a lebel and then the four points x1 y2 x2 y2, first two representing top left coordinate of the box and the last two representing bottom right coordinates of the box. If there are multiple bounding boxes, then after image name there is a label, then four points, followed another label, and the corresponding four points and so on.

To select any of these cases, select the image/dataset and then press the "Load the image" button.


**First case usage**
  - Select the image or the dataset folder.
  - Press the "Load the image" button. 
  - To create any roi, first left click on top left point of the supposed roi and then right click on the bottom right point of the supposed roi. A green rectangular box will appear.
  - Now, if its not the one you meant it, please click "Reset Markings" Button and repoint the new roi.
  - If the ROI is fine, press "Select the ROI" button.
  - Now, load another image or save the file.


**Second case usage**
  - Select the image or the dataset folder.
  - Press the "Load the image" button. 
  - To create any roi, first left click on top left point of the supposed roi and then right click on the bottom right point of the supposed roi. A green rectangular box will appear.
  - Now, if its not the one you meant it, please click "Reset Markings" Button and repoint the new roi.
  - If the ROI is fine, press "Select the ROI" button.
  - Now, load another image or save the file.


**Third case usage**
  - Select the image or the dataset folder.
  - Press the "Load the image" button. 
  - To create any roi, first left click on top left point of the supposed roi and then right click on the bottom right point of the supposed roi. A green rectangular box will appear.
  - Now, if its not the one you meant it, please click "Reset Markings" Button and repoint the new roi.
  - If the ROI is fine, please type an **integer** label in the text box and press "Select the ROI" button.
  - Now, you may draw another roi, or load another image, save the file. 


**Note: In the third case, the one with multiple ROIs per image, if a boundix box is selected for an image and you are trying to make another and press the reset button, the selected roi will not be deleted. Any selected roi cannot be deleted as of now.**

 
\n 
7.2) Annotation base class {#commit7_second}
---

The base class for the annotator tool is "annotation" presented in the files detectors/global2D/annotation/ODAnnotation.cpp and detectors/global2D/annotation/ODAnnotation.h. It has already been stated as to how the base elements, buttons, text boxes, labels, grids, dropdown menus, etc are implemented. In this commit, for the annotator, the new stuffs were mouse_click_event and selecting folder/file. The view showing rectangular ROIs and croppings are done using OpenCV libraries.

**Mouse Click Events**

The on_vbutton_pree function from the file detectors/global2D/annotation/ODAnnotation_imageLoadWindow.h sums up the mouse events,
\code{.cpp}
bool annotation::on_button_press_event(GdkEventButton *event)
{
	// Check if the event is a left button click.
	if (event->button == 1)
	{
		// Memorize pointer position
		lastXMouse=event->x;
		lastYMouse=event->y;
		xPressed=event->x;
		yPressed=event->y;
		// Start moving the view
		moveFlag=true;
		// Event has been handled
		cout << lastXMouse << " " << lastYMouse << endl;

		return true;
	} 
	// Check if the event is a right button click.
	if(event->button == 3)
	{
		// Memorize mouse coordinates
		lastXMouse=event->x;
		lastYMouse=event->y;
		xReleased=event->x;
		yReleased=event->y;
		createVisualROI(xPressed-10, yPressed-35, xReleased-10, yReleased-35);
		// Display the popup menu
//		m_Menu_Popup.popup(event->button, event->time);
		// The event has been handled.
		return true;
	}
	return false;
}
\endcode


**Selecting a file/folder**

With gtkmm, a file chooser can be created using the function below,
\code{.cpp}
Gtk::FileChooserDialog dialog("Please choose a file",Gtk::FILE_CHOOSER_ACTION_OPEN);
dialog.set_transient_for(*this);

//Add response buttons the the dialog:
dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
dialog.add_button("_Open", Gtk::RESPONSE_OK);

//Add filters, so that only certain file types can be selected:
Glib::RefPtr<Gtk::FileFilter> filter_any = Gtk::FileFilter::create();
filter_any->set_name("Any files");
filter_any->add_pattern("*");
dialog.add_filter(filter_any);

Glib::RefPtr<Gtk::FileFilter> filter_text = Gtk::FileFilter::create();
filter_text->set_name("Text files");
filter_text->add_mime_type("text/plain");
dialog.add_filter(filter_text);

Glib::RefPtr<Gtk::FileFilter> filter_cpp = Gtk::FileFilter::create();
filter_cpp->set_name("C/C++ files");
filter_cpp->add_mime_type("text/x-c");
filter_cpp->add_mime_type("text/x-c++");
filter_cpp->add_mime_type("text/x-c-header");
dialog.add_filter(filter_cpp);



//Show the dialog and wait for a user response:
int result = dialog.run();

//Handle the response:
switch(result)
{
	case(Gtk::RESPONSE_OK):
	{
		// The user selected a file
		std::cout << "Open clicked." << std::endl;
		filename = dialog.get_filename();
		std::cout << "File selected: " <<  filename << std::endl;
		break;
	}
	case(Gtk::RESPONSE_CANCEL):
	{
		// The user clicked cancel
		std::cout << "Cancel clicked." << std::endl;
		break;
	}
	default:
	{
		// The user closed the dialog box
		std::cout << "Unexpected button clicked." << std::endl;
		break;
	}
}
\endcode

A similar code can be used to select a folder, with a slight change in the event as shown below,
\code{.cpp}
Gtk::FileChooserDialog dialog("Please choose a file",Gtk::FILE_CHOOSER_ACTION_SELECT_FOLDER);
\endcode

\n 
7.3)Upper Annotator Class {#commit7_third}
---

The ODAnnotator Class invokes the gtkmm object of class annotation, from files detectors/global2D/annotation/ODAnnotator.cpp and detectors/global2D/annotation/ODAnnotator.h. This ODAnnotator class is derived from public elements of ODTrainer class. The invoking is done as,

\code{.cpp}
void ODAnnotator::startAnnotator(int argc, char *argv[])
{
	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
	annotation Annotation;
	Annotation.set_default_geometry (10000, 10000);
	app->run(Annotation);
}
\endcode

The object of ODAnnotator class is created in the example, examples/objectdetector/od_image_annotator.cpp.




\n 
Commit 8 {#commit8}
===

This commit, [link to commit:HDF5 Layer added to network creator](https://github.com/abhi-kumar/opendetection/commit/872cd3271d0d372437155eece729f757abec157f), was issued to add HDF5 data layer to the network creator. Many researchers have the habit of using data in HDF5 format and is currently supported by the caffe library. The commit mentioned changes in two files and this layer was added to the extraLayer type layers.


\n 
Commit 9 {#commit9}
===

This commit, [link to commit:Saving mode added to network-creator](https://github.com/abhi-kumar/opendetection/commit/3001f4f920d36e9fd4b52870aa50e144406bb121), was issued to rectify the issue that, while saving the layers from network creator, nothing was being actually written to the file. The commit marked changes in one file, detectors/global2D/training/network.cpp.

The following was added to the function where button which saved the file was pressed,
\code{.cpp}
for(int i = 0; i < numLayers; i++)
{
	myfile << fullCnnLayers[i]; 
}
\endcode


\n 
Commit 10 {#commit10}
===

This commit, [link to commit:Delete a particular layer, earlier it was only last layer to be deleted](https://github.com/abhi-kumar/opendetection/commit/2d23a32ca381de52b53bcf6c5bff6fa741763ed5), was issued to rectify the issue that, the network creator only facilitated deletion of only the latest created layer. It caused difficulties such that a user who might want to delete the second layer had to technically delete the entire network. Thus, this commit, with changes in 6 files resolved the issue.

\n 
10.1) How to delete a particular layer in network creator {#commit10_first}
---

This can be done, while displaying the network in the display window, below the textview there will be a dropdown list. The list has the name of the layers that have been pushed into the network. Select the layer, and press the button "Delete Selected Layer". Immediate changes will appear on the display window text view space.

The dropdown list is designed in a way that its dynamic to the situation. Once the layer is deleted, its presence from the dropdown list also vanishes,
\code{.cpp}
ref_currentLayers->clear();
combo_currentLayers.set_model(ref_currentLayers);
Gtk::TreeModel::Row row_currentLayers = *(ref_currentLayers->append());
row_currentLayers[column_currentLayers.m_col_id] = 0;
row_currentLayers[column_currentLayers.m_col_name] = "Layers";
row_currentLayers[column_currentLayers.m_col_extra] = "All Layers";
combo_currentLayers.set_active(row_currentLayers);
for(int i = 0; i < numLayers; i++)
{
	Gtk::TreeModel::Row row_currentLayers = *(ref_currentLayers->append());
	row_currentLayers[column_currentLayers.m_col_id] = i + 1;
	row_currentLayers[column_currentLayers.m_col_name] = fullCnnLayersName[i];
}
\endcode
The dynamic nature is obtained by the code snippet above added to the file detectors/global2D/training/displayWindow.h.

The pointer and the handle to select a particular layer, append to network, delete particular layers has been brought down by,
\code{.cpp}
struct Node {
  	Glib::ustring data;
	Glib::ustring name;
  	Node* nextLayer;
};
\endcode
adding the name section, a type of id, to each layer. Thus all the functions, involving the linkedlist in the file detectors/global2D/training/node.h had to be simultaneously changed.


 
\n 
Commit 11 {#commit11}
===

This commit, [link to commit:Now layers in network creator can be inserted in between layers too](https://github.com/abhi-kumar/opendetection/commit/5407fce78a474d06e22277ec7c185f432ee389bf), was issued to add a new important feature to the network creator. It is quite common while experimenting with cnn that, researchers want to insert a layer in betweem two layers, thus to enable this feature four files have been modified in this commit.

11.1) Using the feature of adding layers in between already created layers in network creator{#commit11_first}
---

The pointer to unique id/name had already been created in the previous commit. To make use of this feature, on the display window, select the layer after which you want a new layer. Then press "Add Layer after Selected Layer" button. Then as normal, select a layer and add it.

**Make sure that only one layer is added**


\n 
Commit 12 {#commit12}
===

This commit, [link to commit:Multiple cropper from same image with labels added](https://github.com/abhi-kumar/opendetection/commit/2472314cb8881afdded02023be1529eaf3a984c9), was issued to add a new important feature to the Annotator. 


12.1) Cropping multiple sections from same image{#commit12_first}
---

With a total of around 200 additions to 4 code source files, this feature would enable user to extract multiple rectangular ROIs from the same same with an attached label with each cropping
  - Select the image or the dataset folder.
  - Press the "Load the image" button. 
  - To create any roi, first left click on top left point of the supposed roi and then right click on the bottom right point of the supposed roi. A green rectangular box will appear.
  - Now, if its not the one you meant it, please click "Reset Markings" Button and repoint the new roi.
  - If the ROI is fine, please type an **integer** label in the text box and press "Select the ROI" button.
  - Now, you may draw another roi, or load another image, save the file.
  - Once the file is saved, the cropped images will be saved in the same forlder as the original image with name as <original_image_name>_cropped_<label>_<unique_serial_id>.<extension_of_the_original_image> 


\n 
Commit 13 {#commit13}
===

This commit, [link to commit:With the rectangular boxes demo on images corresponding labels will also be shown](https://github.com/abhi-kumar/opendetection/commit/6ba8bf4dd640e965cfd75d026d5feb2a8aab03a6), was issued to add a new important feature to the Annotator. While annotating with labels on a single image, to enable easeness to the user, labels would also appear with the selected ROIs. This was made possible with 
\code{.cpp}
std::string text = text_annotationLabel.get_text();
int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;
double fontScale = 1;
int thickness = 2;  
cv::Point textOrg(x1, y1);
cv::putText(img, text, textOrg, fontFace, fontScale, Scalar(0,0,255), thickness,8);
\endcode
the above snippet in the file detectors/global2D/annotation/ODAnnotation_imageLoadWindow.h, and a few other changes two other files.


\n 
Commit 14 {#commit14}
===

This commit, [link to commit:Segnet classifier python version added](https://github.com/abhi-kumar/opendetection/commit/147823e1d082f45fa41ef38f3718a5843c55465c), was issued to introduce a link to segnet library, a derivative of caffe library. This would allow segnet library users to attach it to opendetection in way as done with caffe library.

To get a better understanding of segnet please refer to [link here](http://mi.eng.cam.ac.uk/projects/segnet/)

This commit shows a python wrapper based example of segmenting an image using Segnet. The trained model, network file, and the image dataset have been incorporated from [link here](http://mi.eng.cam.ac.uk/projects/segnet/tutorial.html)

The reason behind putting a python wrapper code into play is the same issue we had while adding AAM classifier (methioned above the blog). The issue is left unresolved.

The python wrapper is called from ODConvClassification class,
\code{.cpp}
void ODConvClassification::runSegnetBasedClassifierPythonMode()
{
	string mode = "";
	#if(WITH_GPU)
	mode = "gpu";
	#else
	mode = "cpu";
	#endif
	string cmd = "python ../examples/objectdetector/Segnet_Classify/test.py " + segnetLocation + " " + networkFileLocation + " " + weightModelFileLoaction + " " + imageFileLocation + " " + imageGroundTruthFileLocation + " " + colorLocation + " " + mode;
	system(cmd.c_str());
}
\endcode

And the python wrapper is test.py in the folder, examples/objectdetector/Segnet_Classify. This is untimately called out from the file examples/objectdetector/od_cnn_segnet_classification_python_mode.cpp like the amm classifier example.


\n 
Commit 15 {#commit15}
===

This commit, [link to commit:New feature to annotator: Mask(Segnet), or say non-rectangular roi based annotation with attached labels](https://github.com/abhi-kumar/opendetection/commit/5927b27eb28f329b491b539accf75fe3958d127b), was issued to add a new feature to the Annotator.


15.1) Non rectangualr ROI with label using annotator{#commit15_first}
---

In segnet, and many other places, annotating an object might require a non rectangular ROI to be marked up. This commit enables the user to mark multiple non rectangular ROIs over an image with attached labels.
  - Select the image or the dataset folder.
  - Press the "Load the image" button. 
  - To create any roi, Click on the points needed only with left click.
  - Now, if its not the one you meant it, please click "Reset Markings" Button and repoint the new roi.
  - If the ROI is fine, please type an **integer** label in the text box and press "Select the ROI" button. A gree color marking covering the region and passing through the points you have selected will appear.
  - Now, you may draw another roi, or load another image, save the file. 
  - The output of this file will be saved as filename, followed by an unique id to the ROI, label of the roi, set of points in the roi, then again another id, its label and the points and so on.

This was made feasible with around 300 additions to 4 source code files.


\n 
Commits 16, 17 and 18 {#commit16_17_18}
===

These commits, were made to add popup messages whenever any event is occured, or user does an error while using thr GUIs, Solver Maker, Network Creator and Annotator.

The links to commits:
  - [Commit 16: User oriented message boxes added to solver maker](https://github.com/abhi-kumar/opendetection/commit/c21845efa5ccd3db74e1922173a3383e11418d5c)
  - [Commit 17: User oriented popups added to network creator](https://github.com/abhi-kumar/opendetection/commit/27193588f1b64e100e7154a752f543dc353f834d)
  - [Commit 18: Added user oriented popups to Annotator](https://github.com/abhi-kumar/opendetection/commit/0997d5b3a54763541c8478116c0263a7e60c40b7)


\n 
Commit 19{#commit19}
===

Gsoc Documentation added: [Commit 19: ]()



\n
Older sections of the blog{#oldBlog}
===


CNN based object localization and recognition for openDetection library  {#gsoc2016_blog_abhishek1}
---

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
---

The classification example added to the library involves usage of caffe library. The modalities and usage of the libraries can be studied at

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
---

This particular inclusion presents a simple trainer in a most crude and easy way possible. The major requirements of CNN training using caffe are
  - Solver file
  - Training Network file
  - Image Dataset and a pointer to the Dataset


The classification example added to the library involves usage of caffe library. The modalities and usage of the libraries can be studied at

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


Training a classifier for digits in Mnist Library using CNN. Part 2 {#target2_1}
---

This commit consists of the same simple trainer from previous commit, except for the fact that it involves a graphical user interface to select solver parameters,The classification exampled added to the library involves usage of caffe library. The modalities and usage of the libraries can be studied at

  - [Caffe Library](http://caffe.berkeleyvision.org/)
  - [Using Caffe Library](https://abhishek4273.com/2016/02/07/ann-chapter-3-deep-learning-using-caffe-python/)
  - [Branch of OpenDetection for the below classifier](https://github.com/abhi-kumar/opendetection/tree/cnn_cpu)
  - [GTKMM](http://www.gtkmm.org/en/)

Installing GTKMM Required: In the terminal of ubuntu, type the following
@code  sudo apt-get install libglib2.0-dev libatk1.0* libpango1.0-dev libcairo2-dev gdk-pixbuf2.0-0 libsigc++-2.0-dev libgtk-3-dev libcairomm-1.0-dev libpangomm-1.4-dev libatkmm-1.6-dev libgtkmm-3.0-dev @endcode

**Usage**

From the build folder invoke:

./examples/objectdetector/od_cnn_mnist_train_customSolver

Note:
  - The path to the solver, train network, snapshot have to be set inside examples/objectdetector/Mnist_Train folder for this alpha version.
  - The GUI has a update button for every parameter. It is not necessary to press each one of them. They have been included for future, eg., when only one parameter from an existing solver need to be updated. This functionality has not been added
  - After changing the parameters, press the "Save" button and then close the window using the "x" on the top just like closing any window in Ubuntu. A custom exit has not been added yet. 


**Next up will be a updates and additions to the GUI.**
  - Adding a provision: if a solver file exists and the user wants to change only one parameters, it can be done
  - Creation of CNN network using a simple GUI

Happy Coding!!!!



