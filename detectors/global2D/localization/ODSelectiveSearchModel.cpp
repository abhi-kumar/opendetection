#include "ODSelectiveSearchModel.h"

using namespace std;
using namespace cv;

namespace od
{
	namespace g2d
	{
		void ODSelectiveSearchModel::setLabel(int l)
		{
			label = l;
		}

		void ODSelectiveSearchModel::init()
		{
		}

		ODDetections2D *ODSelectiveSearchModel::detectOmni(ODSceneImage *scene)
    		{
			ODDetections2D *detections = new ODDetections2D;
			return detections;
		}

		ODDetections *ODSelectiveSearchModel::detect(ODSceneImage *scene)
		{
			ODDetections *detections = new ODDetections;
			return detections;		
		}

		Mat get_hess_hist_xx(Mat regionMask, int histSize, float hist_range_min, float hist_range_max)
		{
			Mat kernel_filter_1(7,7, CV_32FC1,1);
			kernel_filter_1 = (Mat_<double>(7,7) << 1.57130243e-04, 7.17839338e-04, 0, -1.76805171e-03, 0, 7.17839338e-04, 1.57130243e-04,
								1.91423823e-03, 8.74507340e-03, 0, -2.15392793e-02, 0, 8.74507340e-03, 1.91423823e-03,
								8.57902057e-03, 3.91926999e-02, 0, -9.65323526e-02, 0, 3.91926999e-02, 8.57902057e-03,
								1.41444137e-02, 6.46178379e-02, 0, -1.59154943e-01, 0, 6.46178379e-02, 1.41444137e-02,
								8.57902057e-03, 3.91926999e-02, 0, -9.65323526e-02, 0, 3.91926999e-02, 8.57902057e-03,
								1.91423823e-03, 8.74507340e-03, 0, -2.15392793e-02, 0, 8.74507340e-03, 1.91423823e-03,
								1.57130243e-04, 7.17839338e-04, 0, -1.76805171e-03, 0, 7.17839338e-04, 1.57130243e-04
						);
			Mat image_filtered_xx;
			filter2D(regionMask, image_filtered_xx, -1, kernel_filter_1,Point(-1,-1), 0,BORDER_DEFAULT );
			Mat xx_hist;
			float range[] = { hist_range_min, hist_range_max } ;
			const float* histRange = { range };
			bool uniform = true; bool accumulate = false;
			calcHist( &image_filtered_xx, 1, 0, Mat(), xx_hist, 1, &histSize, &histRange, uniform, accumulate );
			return xx_hist;
		}

		Mat get_hess_hist_xy(Mat regionMask, int histSize, float hist_range_min, float hist_range_max)
		{
			Mat kernel_filter_2(7,7, CV_32FC1,1);
			kernel_filter_2 = (Mat_<double>(7,7) << 0.00017677, 0.00143568, 0.00321713, 0, -0.00321713, -0.00143568, -0.00017677,
								0.00143568, 0.0116601, 0.02612847, 0, -0.02612847, -0.0116601, -0.00143568,
								0.00321713, 0.02612847, 0.05854983, 0, -0.05854983, -0.02612847, -0.00321713,
								0, 0, 0, 0, 0, 0, 0,
								-0.00321713, -0.02612847, -0.05854983, 0, 0.05854983, 0.02612847, 0.00321713,
								-0.00143568, -0.0116601, -0.02612847, 0, 0.02612847, 0.0116601, 0.00143568,
								-0.00017677, -0.00143568, -0.00321713, 0, 0.00321713, 0.00143568, 0.00017677
						  );   
			Mat image_filtered_xy;
			filter2D(regionMask, image_filtered_xy, -1, kernel_filter_2,Point(-1,-1), 0,BORDER_DEFAULT );
			Mat xy_hist;
			float range[] = { hist_range_min, hist_range_max } ;
			const float* histRange = { range };
			bool uniform = true; bool accumulate = false;
			calcHist( &image_filtered_xy, 1, 0, Mat(), xy_hist, 1, &histSize, &histRange, uniform, accumulate );
			return xy_hist;
		}



		Mat get_hess_hist_yy(Mat regionMask, int histSize, float hist_range_min, float hist_range_max)
		{
			Mat kernel_filter_3(7,7, CV_32FC1,1);
			kernel_filter_3 = (Mat_<double>(7,7) << 
				1.57130243e-04, 1.91423823e-03, 8.57902057e-03, 1.41444137e-02, 8.57902057e-03, 1.91423823e-03, 1.57130243e-04,
				7.17839338e-04, 8.74507340e-03, 3.91926999e-02, 6.46178379e-02, 3.91926999e-02, 8.74507340e-03, 7.17839338e-04,
				0.00000000e+00, 0.00000000e+00, 0.00000000e+00, 0.00000000e+00, 0.00000000e+00, 0.00000000e+00, 0.00000000e+00,
				-1.76805171e-03, -2.15392793e-02, -9.65323526e-02, -1.59154943e-01, -9.65323526e-02, -2.15392793e-02, -1.76805171e-03,
				0.00000000e+00, 0.00000000e+00, 0.00000000e+00, 0.00000000e+00, 0.00000000e+00, 0.00000000e+00, 0.00000000e+00,
				7.17839338e-04, 8.74507340e-03, 3.91926999e-02, 6.46178379e-02, 3.91926999e-02, 8.74507340e-03, 7.17839338e-04,
				1.57130243e-04, 1.91423823e-03, 8.57902057e-03, 1.41444137e-02, 8.57902057e-03, 1.91423823e-03, 1.57130243e-04
						  );
			Mat image_filtered_yy;
			filter2D(regionMask, image_filtered_yy, -1, kernel_filter_3,Point(-1,-1), 0,BORDER_DEFAULT );
			Mat yy_hist;
			float range[] = { hist_range_min, hist_range_max } ;
			const float* histRange = { range };
			bool uniform = true; bool accumulate = false;

			calcHist( &image_filtered_yy, 1, 0, Mat(), yy_hist, 1, &histSize, &histRange, uniform, accumulate );
			return yy_hist;
		}

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



		void createModel(vector < vector <int> > sp, int total_masks, Mat grayMask, ODSelectiveSearchModel regions[], int histSize, float hist_range_min, float hist_range_max)
		{
			Mat regionMask = grayMask.clone();


			for (int i = 0; i < total_masks; i++)
			{
				regionMask = grayMask.clone();
		//		cout << i << endl;
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
		//		cout << i << " hessian" << endl;
				//Hessian Matrix
				regions[i].xx_hist = get_hess_hist_xx(regionMask, histSize, hist_range_min, hist_range_max);
				regions[i].xy_hist = get_hess_hist_xy(regionMask, histSize, hist_range_min, hist_range_max);
				regions[i].yy_hist = get_hess_hist_yy(regionMask, histSize, hist_range_min, hist_range_max);
	
		//		cout << i << " orien" << endl;
				//orientation Matrix
				regions[i].orientation_image_hist = get_orientation_hist(regionMask, histSize, hist_range_min, hist_range_max);

		//		cout << i << " diff" << endl;
				//Differential Excitation Matrix
				regions[i].differential_excitation_hist = get_diff_exci_hist(regionMask, histSize, hist_range_min, hist_range_max);

		//		cout << i << " color" << endl;
				//Color Histogram
				float range[] = { hist_range_min, hist_range_max } ;
				const float* histRange = { range };
				bool uniform = true; bool accumulate = false;
				calcHist(&grayMask, 1, 0, Mat(), regions[i].color_hist, 1, &histSize, &histRange, uniform, accumulate );


			}
		}

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
			/*				cout << i << " " << j << endl;
							cout << regions[i].min_x << " " << regions[i].min_y << " " << regions[i].max_x << " " << regions[i].max_y << endl;
							cout << regions[j].min_x << " " << regions[j].min_y << " " << regions[j].max_x << " " << regions[j].max_y << endl;
							for (int r = 0; r < regionMask.rows; r++)
							{
								for(int c = 0; c < regionMask.cols; c++)
								{
									if(sp[r][c] != i)
									{
										regionMask.at<Vec3b>(r,c)[0] = 0;
										regionMask.at<Vec3b>(r,c)[1] = 0;
										regionMask.at<Vec3b>(r,c)[2] = 0;
									}
									else
									{
										regionMask.at<Vec3b>(r,c)[0] = 0;
										regionMask.at<Vec3b>(r,c)[1] = 0;
										regionMask.at<Vec3b>(r,c)[2] = 255;
									}
								}
							}
							for (int r = 0; r < regionMask.rows; r++)
							{
								for(int c = 0; c < regionMask.cols; c++)
								{
									if(sp[r][c] != j and regionMask.at<Vec3b>(r,c)[2] != 255)
									{
										regionMask.at<Vec3b>(r,c)[0] = 0;
										regionMask.at<Vec3b>(r,c)[1] = 0;
										regionMask.at<Vec3b>(r,c)[2] = 0;
									}
									else
									{
										regionMask.at<Vec3b>(r,c)[0] = 0;
										regionMask.at<Vec3b>(r,c)[1] = 255;
										regionMask.at<Vec3b>(r,c)[2] = 0;
									}
								}
							}
							imshow("regionMask", regionMask);
							waitKey(0);
			*/			
							rows[0] = i;
							rows[1] = j;
							neighbors.push_back(rows);
						}
					}
				}
			}
			return neighbors;
		}

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

		void mergeRegions(int value, ODSelectiveSearchModel regions[], vector < vector <int> > sp_neighbors, Mat grayMask, vector < vector <int> > sp, int minRegionSize, int histSize, float hist_range_min, float hist_range_max)
		{
		/*
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
		*/
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

		vector < vector <int> > extractROIs(int total_masks, ODSelectiveSearchModel regions[], int numRounds, float spSize, vector < vector <int> > sp, Mat img, Mat gray_mask, int minRegionSize, int histSize, float hist_range_min, float hist_range_max)
		{
			vector < vector <int> > pts;
			int totals = total_masks;
			int value = 10;
			while(checkRounds(totals, regions, numRounds) and value > 0)
			{
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
			}
			std::sort(pts.begin(), pts.end());
			pts.erase(std::unique(pts.begin(), pts.end()), pts.end());
			cout << "Total bounding boxes = " << pts.size() << endl;
			return pts;		
		}



	}
}


