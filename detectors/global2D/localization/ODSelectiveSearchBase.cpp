#include "ODSelectiveSearchBase.h"

using namespace std;
using namespace cv;

namespace od
{
	namespace g2d
	{
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

		vector < vector <int> > ODSelectiveSearchBase::getSuperPixels(Mat im, int &totalMasks, float Sigma, float K, float Min_size, string imageLocation)
		{
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

			int H = 0;
			int W = 0;
			num = im.rows*im.cols;
			vector< vector <int> > mask;
			mask.resize(im.rows, std::vector<int>(im.cols, 0));
			int maskValue = 0;
			int v = 0;

			ifstream infile;
			infile.open("segmented.txt");
			int R,G,B,GR;
	
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
		}


		void ODSelectiveSearchBase::init()
		{
		}

		ODDetections2D *ODSelectiveSearchBase::detectOmni(ODSceneImage *scene)
    		{
			ODDetections2D *detections = new ODDetections2D;
			return detections;
		}

		ODDetections *ODSelectiveSearchBase::detect(ODSceneImage *scene)
		{
			ODDetections *detections = new ODDetections;
			return detections;		
		}

	}
}
		
