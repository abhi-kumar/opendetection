#include "ODAnnotation.h"

void annotation::showWindow_imageLoad(Glib::ustring data)
{
	Mat img = imread(filename, 1);
	imwrite("../examples/objectdetector/Annotation/temp.png", img);
	currentWindow = "imageLoadWindow";
	remove();
	set_title("Image Window");
	set_border_width(10);
	add(m_sw_imageLoad);
	m_grid_imageLoad.set_column_spacing (10);
	m_grid_imageLoad.set_row_spacing (10);

	if(rbutton_markBB.get_active() == 1)
	{
		label_annotationType.set_text("Annotion Type: Selecting Single Bounding Box");
	}
	else if(rbutton_cropBB.get_active() == 1)
	{
		label_annotationType.set_text("Annotion Type: Cropping Single Bounding Box");
	}
	else if(rbutton_markBBWithLabel.get_active() == 1)
	{
		label_annotationType.set_text("Annotion Type: Selecting Multiple Bounding Boxes and labelling them");
	}

	label_annotationType.set_line_wrap();
	label_annotationType.set_justify(Gtk::JUSTIFY_FILL);
//	m_grid_imageLoad.attach(label_annotationType,0,0,2,1);
	label_annotationType.show();

	
	if(rbutton_markBB.get_active() == 1 and file_folder == "file")
	{
		
		label_outputFile.hide();
		text_outputFile.hide();
		button_resetMarkings.hide();
		button_selectRoi.hide();
		button_saveMarked.hide();
		button_loadAnotherImage.hide();
		button_saveCropMarked.hide();
		button_resetMarkingsCurrent.hide();
		button_selectRoiCurrent.hide();
		label_annotationLabel.hide();
		text_annotationLabel.hide();
		button_saveMarkedMultiple.hide();
		button_loadNextImage.hide();

		loadOriginalImage(data, 1);
		button_resetMarkings.show();
		button_selectRoi.show();
		button_loadAnotherImage.show();

		label_outputFile.set_text("OutPut Text File Name: ");
		label_outputFile.set_line_wrap();
		label_outputFile.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_imageLoad.attach(label_outputFile,0,2,2,1);
		label_outputFile.show();
		

		text_outputFile.set_max_length(100);
		text_outputFile.set_text("../examples/objectdetector/Annotation/output.txt");
		text_outputFile.select_region(0, text_outputFile.get_text_length());
//		m_grid_imageLoad.attach(text_outputFile,2,2,1,1);	
		text_outputFile.show();
		
		button_saveMarked.show();
		
	}
	else if(rbutton_cropBB.get_active() == 1 and file_folder == "file")
	{
		label_outputFile.hide();
		text_outputFile.hide();
		button_resetMarkings.hide();
		button_selectRoi.hide();
		button_saveMarked.hide();
		button_loadAnotherImage.hide();
		button_saveCropMarked.hide();
		button_resetMarkingsCurrent.hide();
		button_selectRoiCurrent.hide();
		label_annotationLabel.hide();
		text_annotationLabel.hide();
		button_saveMarkedMultiple.hide();
		button_loadNextImage.hide();


		loadOriginalImage(data, 1);
		button_resetMarkings.show();
		button_selectRoi.show();
		button_loadAnotherImage.show();

		label_outputFile.set_text("OutPut Text File Name: ");
		label_outputFile.set_line_wrap();
		label_outputFile.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_imageLoad.attach(label_outputFile,0,2,2,1);
		label_outputFile.show();
		

		text_outputFile.set_max_length(100);
		text_outputFile.set_text("../examples/objectdetector/Annotation/output.txt");
		text_outputFile.select_region(0, text_outputFile.get_text_length());
//		m_grid_imageLoad.attach(text_outputFile,2,2,1,1);	
		text_outputFile.show();
		
		button_saveCropMarked.show();
	}
	else if(rbutton_markBBWithLabel.get_active() == 1 and file_folder == "file")
	{
		label_outputFile.hide();
		text_outputFile.hide();
		button_resetMarkings.hide();
		button_selectRoi.hide();
		button_saveMarked.hide();
		button_saveCropMarked.hide();
		button_loadAnotherImage.hide();
		button_resetMarkingsCurrent.hide();
		button_selectRoiCurrent.hide();
		label_annotationLabel.hide();
		text_annotationLabel.hide();
		button_saveMarkedMultiple.hide();
		button_loadNextImage.hide();

		loadOriginalImage(data, 1);
		button_resetMarkingsCurrent.show();
	
		label_annotationLabel.set_text("Give a label to ROI: ");
		label_annotationLabel.set_line_wrap();
		label_annotationLabel.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_imageLoad.attach(label_annotationLabel,0,4,2,1);
		label_annotationLabel.show();
		

		text_annotationLabel.set_max_length(100);
		text_annotationLabel.set_text("0");
		text_annotationLabel.select_region(0, text_annotationLabel.get_text_length());
//		m_grid_imageLoad.attach(text_outputFile,2,4,1,1);	
		text_annotationLabel.show();
		
		button_selectRoiCurrent.show();
		button_loadAnotherImage.show();

		label_outputFile.set_text("OutPut Text File Name: ");
		label_outputFile.set_line_wrap();
		label_outputFile.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_imageLoad.attach(label_outputFile,0,2,2,1);
		label_outputFile.show();
		

		text_outputFile.set_max_length(100);
		text_outputFile.set_text("../examples/objectdetector/Annotation/output.txt");
		text_outputFile.select_region(0, text_outputFile.get_text_length());
//		m_grid_imageLoad.attach(text_outputFile,2,2,1,1);	
		text_outputFile.show();
		
		button_saveMarkedMultiple.show();

		
	}
	else if(rbutton_markBB.get_active() == 1 and file_folder == "folder")
	{
		label_outputFile.hide();
		text_outputFile.hide();
		button_resetMarkings.hide();
		button_selectRoi.hide();
		button_saveMarked.hide();
		button_loadAnotherImage.hide();
		button_saveCropMarked.hide();
		button_resetMarkingsCurrent.hide();
		button_selectRoiCurrent.hide();
		label_annotationLabel.hide();
		text_annotationLabel.hide();
		button_saveMarkedMultiple.hide();
		button_loadNextImage.hide();

		
		DIR *dpdf;
		struct dirent *epdf;

		dpdf = opendir(foldername.c_str());
		if (dpdf != NULL)
		{
			while (epdf = readdir(dpdf))
			{
				string val = epdf->d_name;
				if(val.length() > 3)
				{
					string fName = foldername + "/" + epdf->d_name;
					cout << fName << endl; 
					imageFileNames.push_back(fName); 
					imagesInFolder++;
				}
		   	}
		}
		filename = imageFileNames[--imagesInFolder];
		loadOriginalImage(filename, 1);

		button_resetMarkings.show();
		button_selectRoi.show();
		button_loadNextImage.show();

		button_loadAnotherImage.show();

		label_outputFile.set_text("OutPut Text File Name: ");
		label_outputFile.set_line_wrap();
		label_outputFile.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_imageLoad.attach(label_outputFile,0,2,2,1);
		label_outputFile.show();
		

		text_outputFile.set_max_length(100);
		text_outputFile.set_text("../examples/objectdetector/Annotation/output.txt");
		text_outputFile.select_region(0, text_outputFile.get_text_length());
//		m_grid_imageLoad.attach(text_outputFile,2,2,1,1);	
		text_outputFile.show();
		
		button_saveMarked.show();
	}
	else if(rbutton_cropBB.get_active() == 1 and file_folder == "folder")
	{
		label_outputFile.hide();
		text_outputFile.hide();
		button_resetMarkings.hide();
		button_selectRoi.hide();
		button_saveMarked.hide();
		button_loadAnotherImage.hide();
		button_saveCropMarked.hide();
		button_resetMarkingsCurrent.hide();
		button_selectRoiCurrent.hide();
		label_annotationLabel.hide();
		text_annotationLabel.hide();
		button_saveMarkedMultiple.hide();
		button_loadNextImage.hide();

		
		DIR *dpdf;
		struct dirent *epdf;

		dpdf = opendir(foldername.c_str());
		if (dpdf != NULL)
		{
			while (epdf = readdir(dpdf))
			{
				string val = epdf->d_name;
				if(val.length() > 3)
				{
					string fName = foldername + "/" + epdf->d_name;
					cout << fName << endl; 
					imageFileNames.push_back(fName); 
					imagesInFolder++;
				}
		   	}
		}
		filename = imageFileNames[--imagesInFolder];
		loadOriginalImage(filename, 1);

		button_resetMarkings.show();
		button_selectRoi.show();
		button_loadNextImage.show();

		button_loadAnotherImage.show();

		label_outputFile.set_text("OutPut Text File Name: ");
		label_outputFile.set_line_wrap();
		label_outputFile.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_imageLoad.attach(label_outputFile,0,2,2,1);
		label_outputFile.show();
		

		text_outputFile.set_max_length(100);
		text_outputFile.set_text("../examples/objectdetector/Annotation/output.txt");
		text_outputFile.select_region(0, text_outputFile.get_text_length());
//		m_grid_imageLoad.attach(text_outputFile,2,2,1,1);	
		text_outputFile.show();

		button_saveCropMarked.show();

	}
	else if(rbutton_markBBWithLabel.get_active() == 1 and file_folder == "folder")
	{
		label_outputFile.hide();
		text_outputFile.hide();
		button_resetMarkings.hide();
		button_selectRoi.hide();
		button_saveMarked.hide();
		button_loadAnotherImage.hide();
		button_saveCropMarked.hide();
		button_resetMarkingsCurrent.hide();
		button_selectRoiCurrent.hide();
		label_annotationLabel.hide();
		text_annotationLabel.hide();
		button_saveMarkedMultiple.hide();
		button_loadNextImage.hide();

		
		DIR *dpdf;
		struct dirent *epdf;

		dpdf = opendir(foldername.c_str());
		if (dpdf != NULL)
		{
			while (epdf = readdir(dpdf))
			{
				string val = epdf->d_name;
				if(val.length() > 3)
				{
					string fName = foldername + "/" + epdf->d_name;
					cout << fName << endl; 
					imageFileNames.push_back(fName); 
					imagesInFolder++;
				}
		   	}
		}
		filename = imageFileNames[--imagesInFolder];
		loadOriginalImage(filename, 1);

		button_resetMarkingsCurrent.show();
	
		label_annotationLabel.set_text("Give a label to ROI: ");
		label_annotationLabel.set_line_wrap();
		label_annotationLabel.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_imageLoad.attach(label_annotationLabel,0,4,2,1);
		label_annotationLabel.show();
		

		text_annotationLabel.set_max_length(100);
		text_annotationLabel.set_text("0");
		text_annotationLabel.select_region(0, text_annotationLabel.get_text_length());
//		m_grid_imageLoad.attach(text_outputFile,2,4,1,1);	
		text_annotationLabel.show();
		
		button_selectRoiCurrent.show();
		button_loadAnotherImage.show();
		button_loadNextImage.show();

		label_outputFile.set_text("OutPut Text File Name: ");
		label_outputFile.set_line_wrap();
		label_outputFile.set_justify(Gtk::JUSTIFY_FILL);
//		m_grid_imageLoad.attach(label_outputFile,0,2,2,1);
		label_outputFile.show();
		

		text_outputFile.set_max_length(100);
		text_outputFile.set_text("../examples/objectdetector/Annotation/output.txt");
		text_outputFile.select_region(0, text_outputFile.get_text_length());
//		m_grid_imageLoad.attach(text_outputFile,2,2,1,1);	
		text_outputFile.show();
		
		button_saveMarkedMultiple.show();
	}
	else
	{
		label_outputFile.hide();
		text_outputFile.hide();
		button_resetMarkings.hide();
		button_selectRoi.hide();
		button_saveMarked.hide();
		button_loadAnotherImage.hide();
		button_saveCropMarked.hide();
		button_resetMarkingsCurrent.hide();
		button_selectRoiCurrent.hide();
		label_annotationLabel.hide();
		text_annotationLabel.hide();
		button_saveMarkedMultiple.hide();
		button_loadNextImage.hide();
	}

		
	
	button_loadMainWindow.show();	
	
	
	m_sw_imageLoad.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
	m_grid_imageLoad.show();
//	show_all_children();
	m_sw_imageLoad.show();
}


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
		if(currentWindow == "imageLoadWindow")
		{
//			std::cout << lastXMouse - 10 << " " << lastYMouse - 10 << std::endl;
			createDot(lastXMouse-10, lastYMouse-35);
		}
		return true;
	}

	// Check if the event is a right button click.
	if(event->button == 4)
	{
		// Memorize mouse coordinates
		lastXMouse=event->x;
		lastYMouse=event->y;
		xReleased=event->x;
		yReleased=event->y;
		if(currentWindow == "imageLoadWindow")
		{
			createVisualROI(xPressed-10, yPressed-35, xReleased-10, yReleased-35);
		}
		// Display the popup menu
//		m_Menu_Popup.popup(event->button, event->time);
		// The event has been handled.
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

void annotation::createDot(int x, int y)
{
	Mat img = imread("../examples/objectdetector/Annotation/temp_resized_dotted.png", 1);
	circle(img, Point(x,y), 3, Scalar(255,0,0), 3, 8, 0 );
	imwrite("../examples/objectdetector/Annotation/temp_resized_dotted.png", img);
	image.set("../examples/objectdetector/Annotation/temp_resized_dotted.png");
	image.show();
}

void annotation::createVisualROI(int x1, int y1, int x2, int y2)
{
	Mat img = imread("../examples/objectdetector/Annotation/temp_resized_dotted.png", 1);
	rectangle(img, Point(x1,y1), Point(x2,y2), Scalar(0,255,0), 3, 8, 0 );
	imwrite("../examples/objectdetector/Annotation/temp_resized_dotted.png", img);
	image.set("../examples/objectdetector/Annotation/temp_resized_dotted.png");
	image.show();
}

void annotation::loadOriginalImage(std::string data, bool st)
{
	Mat img = imread(data, 1);
	int c = img.cols;
	int r = img.rows;
	float wTemp, hTemp;
	if(img.rows > 480 or img.cols > 640)
	{
		cv::resize(img, img, Size(640,480));
		wTemp = (float)c/640.0;
		hTemp = (float)r/480.0;			
	}
	if(st)
	{
		widthMultiplier.push_back(wTemp);
		heightMultiplier.push_back(hTemp);
	}
	imwrite("../examples/objectdetector/Annotation/temp_resized.png", img);
	imwrite("../examples/objectdetector/Annotation/temp_resized_dotted.png", img);
	image.set("../examples/objectdetector/Annotation/temp_resized.png");
	image.show();
}

void annotation::loadOriginalImageWithSavedMarkings(std::string data, vector< vector < int > > roi, bool st)
{
	Mat img = imread(data, 1);
	int c = img.cols;
	int r = img.rows;
	float wTemp, hTemp;
	if(img.rows > 480 or img.cols > 640)
	{
		cv::resize(img, img, Size(640,480));
		wTemp = (float)c/640.0;
		hTemp = (float)r/480.0;			
	}
	if(st)
	{
		widthMultiplier.push_back(wTemp);
		heightMultiplier.push_back(hTemp);
	}
	imwrite("../examples/objectdetector/Annotation/temp_resized.png", img);
	for(int i = 0; i < roi.size(); i++)
	{
		if(storageFileName[i] == data)
			rectangle(img, Point(roi[i][1],roi[i][2]), Point(roi[i][3],roi[i][4]), Scalar(0,255,0), 3, 8, 0 );
	}
	imwrite("../examples/objectdetector/Annotation/temp_resized_dotted.png", img);
	image.set("../examples/objectdetector/Annotation/temp_resized_dotted.png");
	image.show();
}
