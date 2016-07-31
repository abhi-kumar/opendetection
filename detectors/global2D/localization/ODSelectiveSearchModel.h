#ifndef OPENDETECTION_SELECTIVESEARCHMODEL_H
#define OPENDETECTION_SELECTIVESEARCHMODEL_H

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

using namespace std;
using namespace cv;


namespace od
{
	namespace g2d
	{
		class ODSelectiveSearchModel: public ODDetector2D
		{
			public:
				void setLabel(int l);
				void setBoundaries(int ix, int iy, int ax, int ay);
				int label;
				int min_x;
				int max_x;
				int min_y;
				int max_y;
				int size;
				Mat xx_hist, xy_hist, yy_hist, orientation_image_hist,differential_excitation_hist, color_hist;
				vector <int> neighbors;
				bool validity;
						


				void init();
				ODDetections2D *detectOmni(ODSceneImage *scene);
      				ODDetections *detect(ODSceneImage *scene);
				ODSelectiveSearchModel(std::string const &trained_data_location_ = ""):ODDetector2D(trained_data_location_){}
		};

		Mat get_hess_hist_xx(Mat regionMask, int histSize, float hist_range_min, float hist_range_max);
		Mat get_hess_hist_xy(Mat regionMask, int histSize, float hist_range_min, float hist_range_max);
		Mat get_hess_hist_yy(Mat regionMask, int histSize, float hist_range_min, float hist_range_max);
		Mat get_orientation_hist(Mat regionMask, int histSize, float hist_range_min, float hist_range_max);
		Mat get_diff_exci_hist(Mat regionMask, int histSize, float hist_range_min, float hist_range_max);
		void refineRegions(vector < vector <int> > sp, int total_masks, ODSelectiveSearchModel regions[], int min_height, int min_width);
		void createModel(vector < vector <int> > sp, int total_masks, Mat grayMask, ODSelectiveSearchModel regions[], int histSize, float hist_range_min, float hist_range_max);
		bool checkNeighbors(ODSelectiveSearchModel a, ODSelectiveSearchModel b);
		vector < vector <int> > findNeighbors(ODSelectiveSearchModel regions[], int total_masks, Mat regionMask, vector < vector <int> > sp);
		float calcSimilarities(ODSelectiveSearchModel a, ODSelectiveSearchModel b, float spSize);
		void mergeRegions(int value, ODSelectiveSearchModel regions[], vector < vector <int> > sp_neighbors, Mat grayMask, vector < vector <int> > sp, int minRegionSize, int histSize, float hist_range_min, float hist_range_max);
		bool checkRounds(int totals, ODSelectiveSearchModel regions[], int numRounds);
		vector < vector <int> > extractROIs(int total_masks, ODSelectiveSearchModel regions[], int numRounds, float spSize, vector < vector <int> > sp, Mat img, Mat gray_mask, int minRegionSize, int histSize, float hist_range_min, float hist_range_max);
	}
}



#endif //OPENDETECTION_ODSELECTIVESEARCHMODEL_H
