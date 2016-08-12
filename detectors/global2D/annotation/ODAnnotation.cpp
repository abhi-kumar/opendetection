#include "ODAnnotation.h"
#include "ODAnnotation_mainWindow.h"
#include "ODAnnotation_imageLoadWindow.h"

annotation::annotation(): 
	button_selectImageFileName("Select The Image Location"),
	button_loadImage("Load the image"),
	button_loadAnotherImage("Load Next Image from a different location"),
	rbutton_markBB("Mark Single Bounding Box Points"), rbutton_cropBB("Mark Single Boing Box Points and Crop"),
	rbutton_markBBWithLabel("Mark Multiple Bounding Boxes' Points with attached class labels"),
	label_annotationType(""),
	text_outputFile(),
	label_outputFile(""),
	button_resetMarkings("Reset Markings"),
	button_loadMainWindow("Load Main Window"),
	button_selectRoi("Select the ROI"),
	button_saveMarked("Save the ROI details of all images into the stated file"),
	button_saveCropMarked("Save the ROI details with of all images into the stated file and crop the ROI and save"),
	button_resetMarkingsCurrent("Reset the current Marking"),
	button_selectRoiCurrent("Select the roi with mentioned label"),
	button_saveMarkedMultiple("Save the ROI details with labels of all images into the stated file"),
	text_annotationLabel(),
	label_annotationLabel(""),
	button_selectDatasetFolder("Select the Dataset Folder"),
	button_loadNextImage("Load Next Image from same folder"),

	button_quit("Quit")
{
	storage = 0;
	imagesInFolder = 0;
	currentWindow = "mainWindow";
	set_title("Annotator");
	set_border_width(10);
	add(m_sw1);
	m_grid1.set_column_spacing (10);
	m_grid1.set_row_spacing (50);

	
	button_selectImageFileName.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &annotation::on_button_clicked), "selectImageFileName"));
	m_grid1.attach(button_selectImageFileName,0,1,2,1);
	button_selectImageFileName.show();

	button_selectDatasetFolder.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &annotation::on_button_clicked), "selectDatasetFolder"));
	m_grid1.attach(button_selectDatasetFolder,2,1,1,1);
	button_selectDatasetFolder.show();

	Gtk::RadioButton::Group group1 = rbutton_markBB.get_group();
	rbutton_cropBB.set_group(group1);
	rbutton_markBBWithLabel.set_group(group1);
 	rbutton_markBB.set_active();
	m_grid1.attach(rbutton_markBB,0,2,1,1);
	rbutton_markBB.show();
	m_grid1.attach(rbutton_cropBB,2,2,1,1);
	rbutton_cropBB.show();
	m_grid1.attach(rbutton_markBBWithLabel,4,2,1,1);
	rbutton_markBBWithLabel.show();

	button_loadImage.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &annotation::on_button_clicked), "loadImage"));
	m_grid1.attach(button_loadImage,0,3,1,1);
	button_loadImage.show();

/*
	Gtk::RadioButton::Group group1 = rbutton_extraLayerLMDB.get_group();
	rbutton_extraLayerLEVELDB.set_group(group15);
 	rbutton_extraLayerLMDB.set_active();
	m_grid_extraLayerType.attach(rbutton_extraLayerLMDB,2,16,1,1);
	rbutton_extraLayerLMDB.show();
	m_grid_extraLayerType.attach(rbutton_extraLayerLEVELDB,3,16,1,1);
	rbutton_extraLayerLEVELDB.show();
*/
	button_quit.signal_pressed().connect(sigc::mem_fun(*this,&annotation::close));
	m_grid1.attach(button_quit,0,10,1,1);



	//imageLoadWindow

	button_loadMainWindow.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &annotation::on_button_clicked), "loadMainWindow"));
	m_grid_imageLoad.attach(button_loadMainWindow,0,10,1,1);
	button_resetMarkings.show();

	m_grid_imageLoad.attach(image,0,1,1,1);
	
	
	
	label_annotationType.set_text("Annotion Type: Selecting Single Bounding Box");
	label_annotationType.set_line_wrap();
	label_annotationType.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_imageLoad.attach(label_annotationType,0,0,2,1);
	label_annotationType.show();

	button_resetMarkings.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &annotation::on_button_clicked), "resetMarkings"));
	m_grid_imageLoad.attach(button_resetMarkings,0,3,1,1);
	button_resetMarkings.show();

	button_resetMarkingsCurrent.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &annotation::on_button_clicked), "resetMarkingsCurrent"));
	m_grid_imageLoad.attach(button_resetMarkingsCurrent,0,3,1,1);
	button_resetMarkingsCurrent.show();

	button_selectRoi.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &annotation::on_button_clicked), "selectRoi"));
	m_grid_imageLoad.attach(button_selectRoi,0,4,1,1);
	button_selectRoi.show();

	label_annotationLabel.set_text("Give a label to ROI: ");
	label_annotationLabel.set_line_wrap();
	label_annotationLabel.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_imageLoad.attach(label_annotationLabel,0,4,1,1);
	label_annotationLabel.show();
		

	text_annotationLabel.set_max_length(100);
	text_annotationLabel.set_text("0");
	text_annotationLabel.select_region(0, text_annotationLabel.get_text_length());
	m_grid_imageLoad.attach(text_annotationLabel,1,4,1,1);	
	text_annotationLabel.show();

	button_selectRoiCurrent.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &annotation::on_button_clicked), "selectRoiCurrent"));
	m_grid_imageLoad.attach(button_selectRoiCurrent,2,4,1,1);
	button_selectRoiCurrent.show();

	button_loadAnotherImage.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &annotation::on_button_clicked), "loadAnotherImage"));
	m_grid_imageLoad.attach(button_loadAnotherImage,0,5,2,1);
	button_loadMainWindow.show();
	
	button_loadNextImage.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &annotation::on_button_clicked), "loadNextImage"));
	m_grid_imageLoad.attach(button_loadNextImage,2,5,1,1);
	button_loadNextImage.show();

	label_outputFile.set_text("OutPut Text File Name: ");
	label_outputFile.set_line_wrap();
	label_outputFile.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_imageLoad.attach(label_outputFile,0,6,1,1);
	label_outputFile.show();
		

	text_outputFile.set_max_length(100);
	text_outputFile.set_text("../examples/objectdetector/Annotation/output.txt");
	text_outputFile.select_region(0, text_outputFile.get_text_length());
	m_grid_imageLoad.attach(text_outputFile,1,6,1,1);	
	text_outputFile.show();

	button_saveMarked.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &annotation::on_button_clicked), "saveMarked"));
	m_grid_imageLoad.attach(button_saveMarked,2,6,1,1);
	button_saveMarked.show();

	button_saveCropMarked.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &annotation::on_button_clicked), "saveCropMarked"));
	m_grid_imageLoad.attach(button_saveCropMarked,2,6,2,1);
	button_saveCropMarked.show();

	button_saveMarkedMultiple.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &annotation::on_button_clicked), "saveMarkedMultiple"));
	m_grid_imageLoad.attach(button_saveMarkedMultiple,2,6,1,1);
	button_saveMarkedMultiple.show();

	m_sw_imageLoad.add(m_grid_imageLoad);

	m_sw1.add(m_grid1);
	m_sw1.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
//	m_grid1.show();
	show_all_children();
	m_sw1.show();

}

annotation::~annotation()
{}

void annotation::on_button_clicked(Glib::ustring data)
{
	if(data == "selectImageFileName" or data == "loadAnotherImage")
	{
		if(data == "selectImageFileName")
			file_folder = "file";
		// Create the dialog box FileChooser
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
		if(data == "loadAnotherImage")
			loadOriginalImage(filename, 1);
	}
	else if(data == "selectDatasetFolder")
	{
		file_folder = "folder";
		// Create the dialog box FileChooser
		Gtk::FileChooserDialog dialog("Please choose a file",Gtk::FILE_CHOOSER_ACTION_SELECT_FOLDER);
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
				foldername = dialog.get_filename();
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
		if(data == "loadAnotherImage")
			loadOriginalImage(filename, 1);
	}
	else if(data == "loadNextImage")
	{
		if(imagesInFolder > 0)
		{
			filename = imageFileNames[--imagesInFolder];
			loadOriginalImage(filename, 1);
		}
	}
	else if(data == "loadImage")
	{
		showWindow_imageLoad(filename);
	}
	else if(data == "loadMainWindow")
	{
		showWindow_main();
	}
	else if(data == "resetMarkings")
	{
		loadOriginalImage(filename, 0);
	}
	else if(data == "resetMarkingsCurrent")
	{
		loadOriginalImageWithSavedMarkings(filename, storageROILocationCurrent, 0);
	}
	else if(data == "selectRoi")
	{
		vector<int> temp;
		temp.push_back(xPressed-10);
		temp.push_back(yPressed-35);
		temp.push_back(xReleased-10);
		temp.push_back(yReleased-35);

		storageROILocation.push_back(temp);
		storageFileName.push_back(filename);	
		storage++;
		loadOriginalImage(filename, 1);	
	}
	else if(data == "selectRoiCurrent")
	{
		vector<int> temp;
		std::string label = text_annotationLabel.get_text();
		int Result; 
		istringstream convert(label);
		if ( !(convert >> Result) )
			Result = 0;
		temp.push_back(Result);
		temp.push_back(xPressed-10);
		temp.push_back(yPressed-35);
		temp.push_back(xReleased-10);
		temp.push_back(yReleased-35);
		storageROILocationCurrent.push_back(temp);
		storageFileName.push_back(filename);
		storage++;
		loadOriginalImageWithSavedMarkings(filename, storageROILocationCurrent, 1);
		
	}
	else if(data == "saveMarked")
	{
		ofstream myfile;
		myfile.open(text_outputFile.get_text());
		for(int i = 0; i < storage; i++)
		{
			myfile << storageFileName[i] << " " << int(storageROILocation[i][0]*widthMultiplier[i]) << " " << int(storageROILocation[i][1]*heightMultiplier[i]) << " " << int(storageROILocation[i][2]*widthMultiplier[i]) << " " << int(storageROILocation[i][3]*heightMultiplier[i]) << endl;
		}
		Gtk::MessageDialog dialog(*this, "Message");
 		dialog.set_secondary_text("The details have been saved into the file " + text_outputFile.get_text());

  		dialog.run();
	}
	else if(data == "saveMarkedMultiple")
	{
		ofstream myfile;
		myfile.open(text_outputFile.get_text());
		std::string tempFileName = storageFileName[0];
		
		for(int i = 0; i < storage; i++)
		{
			if(i == 0)
			{
				myfile << storageFileName[i] << " " << storageROILocationCurrent[i][0] << " " << int(storageROILocationCurrent[i][1]*widthMultiplier[i]) << " " << int(storageROILocationCurrent[i][2]*heightMultiplier[i]) << " " << int(storageROILocationCurrent[i][3]*widthMultiplier[i]) << " " << int(storageROILocationCurrent[i][4]*heightMultiplier[i]) << " ";
			}
			else
			{	
				if(tempFileName == storageFileName[i])
				{
					myfile << storageROILocationCurrent[i][0] << " " << int(storageROILocationCurrent[i][1]*widthMultiplier[i]) << " " << int(storageROILocationCurrent[i][2]*heightMultiplier[i]) << " " << int(storageROILocationCurrent[i][3]*widthMultiplier[i]) << " " << int(storageROILocationCurrent[i][4]*heightMultiplier[i]) << " ";
				}
				else
				{
					myfile << endl;
					myfile << storageFileName[i] << " " << storageROILocationCurrent[i][0] << " " << int(storageROILocationCurrent[i][1]*widthMultiplier[i]) << " " << int(storageROILocationCurrent[i][2]*heightMultiplier[i]) << " " << int(storageROILocationCurrent[i][3]*widthMultiplier[i]) << " " << int(storageROILocationCurrent[i][4]*heightMultiplier[i]) << " ";
					tempFileName = storageFileName[i];
				}
			}
		}
		Gtk::MessageDialog dialog(*this, "Message");
 		dialog.set_secondary_text("The details have been saved into the file " + text_outputFile.get_text());

  		dialog.run();
	}
	else if(data == "saveCropMarked")
	{
		ofstream myfile;
		myfile.open(text_outputFile.get_text());
		for(int i = 0; i < storage; i++)
		{
			myfile << storageFileName[i] << " " << int(storageROILocation[i][0]*widthMultiplier[i]) << " " << int(storageROILocation[i][1]*heightMultiplier[i]) << " " << int(storageROILocation[i][2]*widthMultiplier[i]) << " " << int(storageROILocation[i][3]*heightMultiplier[i]) << endl;
			std::string str2 = storageFileName[i].substr (0,storageFileName[i].length()-4);
			str2 += "_cropped.png";
			cv::Rect roi(int(storageROILocation[i][0]*widthMultiplier[i]), int(storageROILocation[i][1]*heightMultiplier[i]), int(storageROILocation[i][2]*widthMultiplier[i]) - int(storageROILocation[i][0]*widthMultiplier[i]), int(storageROILocation[i][3]*heightMultiplier[i]) - int(storageROILocation[i][1]*heightMultiplier[i]));
			Mat img = imread(storageFileName[i],1);
			cv::Mat image_roi = img(roi);
			imwrite(str2, image_roi);
		}
		
//Create the cv::Mat with the ROI you need, where "image" is the cv::Mat you want to extract the ROI from
		
		Gtk::MessageDialog dialog(*this, "Message");
 		dialog.set_secondary_text("The details have been saved into the file " + text_outputFile.get_text() + " and the cropped images have been saved");

//  		dialog.run();
	}
}
