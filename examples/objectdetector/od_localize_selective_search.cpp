#include "detectors/global2D/localization/ODSelectiveSearchBase.h"
#include "detectors/global2D/localization/ODSelectiveSearchModel.h"
#include "common/utils/ODFrameGenerator.h"

#include "common/pipeline/ObjectDetector.h"
#include "common/pipeline/ODDetection.h"
#include <iostream>
#include <fstream>

using namespace od;
using namespace std;


int main(int argc, char **argv)
{
	clock_t tStart = clock();
	od::g2d::ODSelectiveSearchBase ss;
	string imageLocation = "../examples/objectdetector/Localization_Images/";	//Para 1
	string imageName = "sample1.png";
	int imgWidth = 640;							//Para 2
	int imgHeight = 480;							//Para 3
	string im = imageLocation + imageName;	
	ss.acquireImages(im, imgWidth, imgHeight);

	ss.sp_preProcessed = ss.preProcessImg(ss.img);

	float sigma = 0.5;							//Para 4
	float k = 580;								//Para 5
	int min_size = 50;							//Para 6
	ss.sp = ss.getSuperPixels(ss.sp_preProcessed, ss.total_masks, sigma, k, min_size, imageLocation);

	cout << "total segments= " << ss.total_masks << endl;

	cvtColor(ss.img, ss.gray_mask, CV_BGR2GRAY);

	od::g2d::ODSelectiveSearchModel regions[ss.total_masks];
	int min_height = 20;							//Para 7
	int min_width = 20;							//Para 8
	od::g2d::refineRegions(ss.sp, ss.total_masks, regions, min_height, min_width);
	float spSize = ss.sp.size() * ss.sp[0].size();

	int histSize = 25;							//Para 9
	float hist_range_min = 1;							//Para 10
	float hist_range_max = 255;						//Para 11
	od::g2d::createModel(ss.sp, ss.total_masks, ss.gray_mask, regions, histSize, hist_range_min, hist_range_max);

	int numRounds = ss.total_masks/2;					//Para 12
	int minRegionSize = 200;						//Para 13
	vector < vector <int> > pts = od::g2d::extractROIs(ss.total_masks, regions, numRounds, spSize, ss.sp, ss.img, ss.gray_mask, minRegionSize, histSize, hist_range_min, hist_range_max);
		
	ofstream myfile;
	string file_write = imageLocation + "region_of_interests.txt";
	myfile.open(file_write.c_str());
	for(int i = 0; i < pts.size(); i++)
	{
		for(int j = 0; j < pts[i].size(); j++)
		{	
			myfile << pts[i][j] << " ";
		}
		myfile << endl;
	}	
	myfile.close();
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;

}
