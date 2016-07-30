#ifndef OPENDETECTION_SELECTIVESEARCHBASE_H
#define OPENDETECTION_SELECTIVESEARCHBASE_H

#include "common/pipeline/ODDetector.h"
#include "common/pipeline/ODScene.h"
#include "common/utils/utils.h"
#include "common/utils/ODFeatureDetector2D.h"


#include <opencv2/opencv.hpp>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
# include <cstdlib>
# include <iomanip>
# include <fstream>
# include <ctime>
# include <cstring>
#include <sstream>
#include <string>
#include <time.h>

#include "image.h"
#include "misc.h"
#include "pnmfile.h"
#include "segment-image.h"

using namespace std;
using namespace cv;


namespace od
{
	namespace g2d
	{
		class ODSelectiveSearchBase: public ODDetector2D
		{
			public:
				void acquireImages(string imageLocation, int imgWidth, int imgHeight);
				Mat preProcessImg(Mat image);
				vector < vector <int> > getSuperPixels(Mat im, int &totalMasks, float Sigma, float K, float Min_size, string imageLocation);		 

				void init();
				ODDetections2D *detectOmni(ODSceneImage *scene);
      				ODDetections *detect(ODSceneImage *scene);
				ODSelectiveSearchBase(std::string const &trained_data_location_ = ""):ODDetector2D(trained_data_location_){}

				Mat img, cluster, outputImg, sp_preProcessed, gray_mask;
				int inputImageHeight;
				int inputImageWidth;
				int total_masks;
				vector < vector <int> > sp; 
		};
	}
}

#endif //OPENDETECTION_ODSELECTIVESEARCHBASE_H

