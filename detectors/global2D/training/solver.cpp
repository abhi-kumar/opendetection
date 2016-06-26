#include "solver.h"
#include <iostream>
#include <fstream>

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
	set_title("Solver");
	set_border_width(10);
	add(m_sw1);
	m_grid1.set_column_spacing (10);
	m_grid1.set_row_spacing (50);
	
	//level0

	label_solverFileName.set_text("1) Give a proper name to the solver file: ");
	label_solverFileName.set_line_wrap();
	label_solverFileName.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_solverFileName,0,0,2,1);
	label_solverFileName.show();

	text_solverFileName.set_max_length(100);
	text_solverFileName.set_text("../examples/objectdetector/Mnist_Train/solverCustom1.prototxt");
	text_solverFileName.select_region(0, text_solverFileName.get_text_length());
	m_grid1.attach(text_solverFileName,2,0,5,1);	
	text_solverFileName.show();

	button_solverFileName.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &SolverProperties::on_button_clicked), "solverFileName"));
	m_grid1.attach(button_solverFileName,7,0,1,1);
	button_solverFileName.show();

	//level1

	label_trainNetworkFileType.set_text("2)Select type of training network file type.\nUsually these exists two types,\nfirst adds validation and training in the same file,\nWhile other adds them in two different files");
	label_trainNetworkFileType.set_line_wrap();
	label_trainNetworkFileType.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_trainNetworkFileType,0,1,2,1);
	label_trainNetworkFileType.show();

	Gtk::RadioButton::Group group = rbutton_trainNetworkFileType_net.get_group();
 	rbutton_trainNetworkFileType_tt.set_group(group);
	rbutton_trainNetworkFileType_net.set_active();
	m_grid1.attach(rbutton_trainNetworkFileType_net,2,1,1,1);
	rbutton_trainNetworkFileType_net.show();
	m_grid1.attach(rbutton_trainNetworkFileType_tt,3,1,1,1);
	rbutton_trainNetworkFileType_tt.show();

	//level2
	
	label_trainNetworkFileName.set_text("2.1) net: or train_net:\n(Parameter Details: Give location of \nthe net file or the train_net file) ");
	label_trainNetworkFileName.set_line_wrap();
	label_trainNetworkFileName.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_trainNetworkFileName,0,2,2,1);
	label_trainNetworkFileName.show();
	
	text_trainNetworkFileName.set_max_length(500);
	text_trainNetworkFileName.set_text("../examples/objectdetector/Mnist_Train/train1.prototxt");
	text_trainNetworkFileName.select_region(0, text_solverFileName.get_text_length());
	m_grid1.attach(text_trainNetworkFileName,2,2,5,1);	
	text_trainNetworkFileName.show();	

	button_trainNetworkFileName.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &SolverProperties::on_button_clicked), "trainNetworkFileName"));
	m_grid1.attach(button_trainNetworkFileName,7,2,1,1);
	button_trainNetworkFileName.show();

	//level3
	
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


	//level4

	label_enableValidationParameters.set_text("4) Enable Validation(test) phase Parameters:\nParameters are \"test_iter\" and \"test_interval\"");
	label_enableValidationParameters.set_line_wrap();
	label_enableValidationParameters.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_enableValidationParameters,0,4,2,1);
	label_enableValidationParameters.show();

	Gtk::RadioButton::Group group3 = rbutton_enableValidationParameters_no.get_group();
 	rbutton_enableValidationParameters_yes.set_group(group3);
	rbutton_enableValidationParameters_no.set_active();
	m_grid1.attach(rbutton_enableValidationParameters_no,2,4,1,1);
	rbutton_enableValidationParameters_no.show();
	m_grid1.attach(rbutton_enableValidationParameters_yes,3,4,1,1);
	rbutton_enableValidationParameters_yes.show();

	//level 5
	
	label_testIter.set_text("4.1) test_iter:\n(Set number of iterations during validation phase)");
	label_testIter.set_line_wrap();
	label_testIter.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_testIter,0,5,2,1);
	label_testIter.show();
	
	text_testIter.set_max_length(100);
	text_testIter.set_text("100");
	text_testIter.select_region(0, text_testNetworkFileName.get_text_length());
	m_grid1.attach(text_testIter,2,5,1,1);	
	text_testIter.show();	

	button_testIter.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &SolverProperties::on_button_clicked), "testIter"));
	m_grid1.attach(button_testIter,3,5,1,1);
	button_testIter.show();


	//level 6

	label_testInterval.set_text("4.2) test_interval:\n(Specifies that after a set of mentioned training iterations,\na validation phase is initiated)");
	label_testInterval.set_line_wrap();
	label_testInterval.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_testInterval,0,6,2,1);
	label_testInterval.show();
	
	text_testInterval.set_max_length(100);
	text_testInterval.set_text("100");
	text_testInterval.select_region(0, text_testNetworkFileName.get_text_length());
	m_grid1.attach(text_testInterval,2,6,1,1);	
	text_testInterval.show();	

	button_testInterval.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &SolverProperties::on_button_clicked), "testInterval"));
	m_grid1.attach(button_testInterval,3,6,1,1);
	button_testInterval.show();

	//level 7

	label_enableAverageLoss.set_text("5) Enable \"average_loss\" parameter: ");
	label_enableAverageLoss.set_line_wrap();
	label_enableAverageLoss.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_enableAverageLoss,0,7,2,1);
	label_enableAverageLoss.show();

	Gtk::RadioButton::Group group4 = rbutton_enableAverageLoss_no.get_group();
 	rbutton_enableAverageLoss_yes.set_group(group4);
	rbutton_enableAverageLoss_no.set_active();
	m_grid1.attach(rbutton_enableAverageLoss_no,2,7,1,1);
	rbutton_enableAverageLoss_no.show();
	m_grid1.attach(rbutton_enableAverageLoss_yes,3,7,1,1);
	rbutton_enableAverageLoss_yes.show();

	label_averageLoss.set_text("average_loss:");
	label_averageLoss.set_line_wrap();
	label_averageLoss.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_averageLoss,4,7,1,1);
	label_averageLoss.show();
	
	text_averageLoss.set_max_length(100);
	text_averageLoss.set_text("1.0");
	text_averageLoss.select_region(0, text_averageLoss.get_text_length());
	m_grid1.attach(text_averageLoss,5,7,1,1);	
	text_averageLoss.show();	

	button_averageLoss.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &SolverProperties::on_button_clicked), "averageLoss"));
	m_grid1.attach(button_averageLoss,6,7,1,1);
	button_averageLoss.show();

	
	//level 8

	label_enableRandomSample.set_text("6) Enable \"random_seed\" parameter: ");
	label_enableRandomSample.set_line_wrap();
	label_enableRandomSample.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_enableRandomSample,0,8,2,1);
	label_enableRandomSample.show();

	Gtk::RadioButton::Group group5 = rbutton_enableRandomSample_no.get_group();
 	rbutton_enableRandomSample_yes.set_group(group5);
	rbutton_enableRandomSample_no.set_active();
	m_grid1.attach(rbutton_enableRandomSample_no,2,8,1,1);
	rbutton_enableRandomSample_no.show();
	m_grid1.attach(rbutton_enableRandomSample_yes,3,8,1,1);
	rbutton_enableRandomSample_yes.show();

	label_randomSample.set_text("random_seed:");
	label_randomSample.set_line_wrap();
	label_randomSample.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_randomSample,4,8,1,1);
	label_randomSample.show();
	
	text_randomSample.set_max_length(100);
	text_randomSample.set_text("1");
	text_randomSample.select_region(0, text_randomSample.get_text_length());
	m_grid1.attach(text_randomSample,5,8,1,1);	
	text_randomSample.show();	

	button_randomSample.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &SolverProperties::on_button_clicked), "randomSample"));
	m_grid1.attach(button_randomSample,6,8,1,1);
	button_randomSample.show();

	//label 9
	
	label_display.set_text("7)display:\n(Used to diplay output afer every specified number of iterations)");
	label_display.set_line_wrap();
	label_display.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_display,0,9,2,1);
	label_display.show();
	
	text_display.set_max_length(100);
	text_display.set_text("100");
	text_display.select_region(0, text_display.get_text_length());
	m_grid1.attach(text_display,2,9,1,1);	
	text_display.show();	

	button_display.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &SolverProperties::on_button_clicked), "display"));
	m_grid1.attach(button_display,3,9,1,1);
	button_display.show();


	//level 10	

	label_enableDebugInfo.set_text("8) Enable \"debug_info\" parameter:\n(Used to see every step in training,\nsuitable for resolving bugs");
	label_enableDebugInfo.set_line_wrap();
	label_enableDebugInfo.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_enableDebugInfo,0,10,2,1);
	label_enableDebugInfo.show();

	Gtk::RadioButton::Group group6 = rbutton_enableDebugInfo_no.get_group();
 	rbutton_enableDebugInfo_yes.set_group(group6);
	rbutton_enableDebugInfo_no.set_active();
	m_grid1.attach(rbutton_enableDebugInfo_no,2,10,1,1);
	rbutton_enableDebugInfo_no.show();
	m_grid1.attach(rbutton_enableDebugInfo_yes,3,10,1,1);
	rbutton_enableDebugInfo_yes.show();

	button_debugInfo.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &SolverProperties::on_button_clicked), "debugInfo"));
	m_grid1.attach(button_debugInfo,4,10,1,1);
	button_debugInfo.show();

	//level 11

	label_snapshot.set_text("9)snapshot:\n(Used to save trained weights afer every specified number of iterations)");
	label_snapshot.set_line_wrap();
	label_snapshot.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_snapshot,0,11,2,1);
	label_snapshot.show();
	
	text_snapshot.set_max_length(100);
	text_snapshot.set_text("100");
	text_snapshot.select_region(0, text_snapshot.get_text_length());
	m_grid1.attach(text_snapshot,2,11,1,1);	
	text_snapshot.show();	

	button_snapshot.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &SolverProperties::on_button_clicked), "snapshot"));
	m_grid1.attach(button_snapshot,3,11,1,1);
	button_snapshot.show();

	
	//level 12

	label_enableTestComputeLoss.set_text("8) Enable \"test_compute_loss\" parameter:\n(Set as 1 when needed to calculate loss in validation phase");
	label_enableTestComputeLoss.set_line_wrap();
	label_enableTestComputeLoss.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_enableTestComputeLoss,0,12,2,1);
	label_enableTestComputeLoss.show();

	Gtk::RadioButton::Group group7 = rbutton_enableTestComputeLoss_no.get_group();
 	rbutton_enableTestComputeLoss_yes.set_group(group7);
	rbutton_enableTestComputeLoss_no.set_active();
	m_grid1.attach(rbutton_enableTestComputeLoss_no,2,12,1,1);
	rbutton_enableTestComputeLoss_no.show();
	m_grid1.attach(rbutton_enableTestComputeLoss_yes,3,12,1,1);
	rbutton_enableTestComputeLoss_yes.show();

	button_testComputeLoss.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &SolverProperties::on_button_clicked), "testComputeLoss"));
	m_grid1.attach(button_testComputeLoss,4,12,1,1);
	button_testComputeLoss.show();

	//level 13
	
	label_snapshotPrefix.set_text("10)snapshot_prefix:\n(Provide prefix string to save the weights.\nProvide path to the saved weights.)");
	label_snapshotPrefix.set_line_wrap();
	label_snapshotPrefix.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_snapshotPrefix,0,13,2,1);
	label_snapshotPrefix.show();
	
	text_snapshotPrefix.set_max_length(500);
	text_snapshotPrefix.set_text("../examples/objectdetector/Mnist_Train/sample_prefix");
	text_snapshotPrefix.select_region(0, text_snapshotPrefix.get_text_length());
	m_grid1.attach(text_snapshotPrefix,2,13,5,1);	
	text_snapshotPrefix.show();	

	button_snapshotPrefix.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &SolverProperties::on_button_clicked), "snapshotPrefix"));
	m_grid1.attach(button_snapshotPrefix,7,13,1,1);
	button_snapshotPrefix.show();

	

	//level 14
	
	label_maxIter.set_text("11)max_iter:\n(Provide maximum number of iteratios to be performed");
	label_maxIter.set_line_wrap();
	label_maxIter.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_maxIter,0,14,2,1);
	label_maxIter.show();
	
	text_maxIter.set_max_length(100);
	text_maxIter.set_text("10000");
	text_maxIter.select_region(0, text_maxIter.get_text_length());
	m_grid1.attach(text_maxIter,2,14,1,1);	
	text_maxIter.show();	

	button_maxIter.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &SolverProperties::on_button_clicked), "maxIter"));
	m_grid1.attach(button_maxIter,3,14,1,1);
	button_maxIter.show();

	
	//level 15

	label_type.set_text("12)type:\n(Select Type of Solver");
	label_type.set_line_wrap();
	label_type.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_type,0,15,2,1);
	label_type.show();
	
	Gtk::RadioButton::Group group8 = rbutton_typeSGD_yes.get_group();
 	rbutton_typeAdadelta_yes.set_group(group8);
	rbutton_typeAdagrad_yes.set_group(group8);
	rbutton_typeAdam_yes.set_group(group8);
	rbutton_typeRMSProp_yes.set_group(group8);
	rbutton_typeNesterov_yes.set_group(group8);
	rbutton_typeSGD_yes.set_active();
	m_grid1.attach(rbutton_typeSGD_yes,2,15,1,1);
	rbutton_typeSGD_yes.show();
	m_grid1.attach(rbutton_typeAdadelta_yes,3,15,1,1);
	rbutton_typeAdadelta_yes.show();
	m_grid1.attach(rbutton_typeAdagrad_yes,4,15,1,1);
	rbutton_typeAdagrad_yes.show();
	m_grid1.attach(rbutton_typeAdam_yes,5,15,1,1);
	rbutton_typeAdam_yes.show();
	m_grid1.attach(rbutton_typeRMSProp_yes,6,15,1,1);
	rbutton_typeRMSProp_yes.show();
	m_grid1.attach(rbutton_typeNesterov_yes,7,15,1,1);
	rbutton_typeNesterov_yes.show();

	button_type.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &SolverProperties::on_button_clicked), "type"));
	m_grid1.attach(button_type,8,15,1,1);
	button_type.show();

	//level 16
	
	label_learningRatePolicy.set_text("13)lr_policy:\n(Set learning rate policy");
	label_learningRatePolicy.set_line_wrap();
	label_learningRatePolicy.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_learningRatePolicy,0,16,2,1);
	label_learningRatePolicy.show();
	
	Gtk::RadioButton::Group group9 = rbutton_learningRatePolicyFixed_yes.get_group();
 	rbutton_learningRatePolicyExp_yes.set_group(group9);
	rbutton_learningRatePolicyStep_yes.set_group(group9);
	rbutton_learningRatePolicyInv_yes.set_group(group9);
	rbutton_learningRatePolicyMultistep_yes.set_group(group9);
	rbutton_learningRatePolicyPoly_yes.set_group(group9);
	rbutton_learningRatePolicySigmoid_yes.set_group(group9);
	rbutton_learningRatePolicyFixed_yes.set_active();
	m_grid1.attach(rbutton_learningRatePolicyFixed_yes,2,16,1,1);
	rbutton_learningRatePolicyFixed_yes.show();
	m_grid1.attach(rbutton_learningRatePolicyExp_yes,3,16,1,1);
	rbutton_learningRatePolicyExp_yes.show();
	m_grid1.attach(rbutton_learningRatePolicyStep_yes,4,16,1,1);
	rbutton_learningRatePolicyStep_yes.show();
	m_grid1.attach(rbutton_learningRatePolicyInv_yes,5,16,1,1);
	rbutton_learningRatePolicyInv_yes.show();
	m_grid1.attach(rbutton_learningRatePolicyMultistep_yes,6,16,1,1);
	rbutton_learningRatePolicyMultistep_yes.show();
	m_grid1.attach(rbutton_learningRatePolicyPoly_yes,7,16,1,1);
	rbutton_learningRatePolicyPoly_yes.show();
	m_grid1.attach(rbutton_learningRatePolicySigmoid_yes,8,16,1,1);
	rbutton_learningRatePolicySigmoid_yes.show();

	button_learningRatePolicy.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &SolverProperties::on_button_clicked), "learningRatePolicy"));
	m_grid1.attach(button_learningRatePolicy,9,16,1,1);
	button_learningRatePolicy.show();

	//level 17

	label_baseLearningRate.set_text("11)base_lr:\n(Set initial learning rate");
	label_baseLearningRate.set_line_wrap();
	label_baseLearningRate.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_baseLearningRate,0,17,2,1);
	label_baseLearningRate.show();
	
	text_baseLearningRate.set_max_length(100);
	text_baseLearningRate.set_text("0.01");
	text_baseLearningRate.select_region(0, text_baseLearningRate.get_text_length());
	m_grid1.attach(text_baseLearningRate,2,17,1,1);	
	text_baseLearningRate.show();	

	button_baseLearningRate.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &SolverProperties::on_button_clicked), "baseLearningRate"));
	m_grid1.attach(button_baseLearningRate,3,17,1,1);
	button_baseLearningRate.show();

	//level 18

	label_gamma.set_text("14)gamma:\n(Set gamma value. Used in learning rate policies)");
	label_gamma.set_line_wrap();
	label_gamma.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_gamma,0,18,2,1);
	label_gamma.show();
	
	text_gamma.set_max_length(100);
	text_gamma.set_text("0.0001");
	text_gamma.select_region(0, text_gamma.get_text_length());
	m_grid1.attach(text_gamma,2,18,1,1);	
	text_gamma.show();	

	button_gamma.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &SolverProperties::on_button_clicked), "gamma"));
	m_grid1.attach(button_gamma,3,18,1,1);
	button_gamma.show();
	

	//level 19

	label_power.set_text("15)power:\n(Set power value. Used in learning rate policies)");
	label_power.set_line_wrap();
	label_power.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_power,0,19,2,1);
	label_power.show();
	
	text_power.set_max_length(100);
	text_power.set_text("0.75");
	text_power.select_region(0, text_power.get_text_length());
	m_grid1.attach(text_power,2,19,1,1);	
	text_power.show();	

	button_power.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &SolverProperties::on_button_clicked), "power"));
	m_grid1.attach(button_power,3,19,1,1);
	button_power.show();


	//level 20

	label_stepSize.set_text("16)stepsize:\n(Set stepSize. Used in learning rate policies)");
	label_stepSize.set_line_wrap();
	label_stepSize.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_stepSize,0,20,2,1);
	label_stepSize.show();
	
	text_stepSize.set_max_length(100);
	text_stepSize.set_text("100");
	text_stepSize.select_region(0, text_stepSize.get_text_length());
	m_grid1.attach(text_stepSize,2,20,1,1);	
	text_stepSize.show();	

	button_stepSize.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &SolverProperties::on_button_clicked), "stepSize"));
	m_grid1.attach(button_stepSize,3,20,1,1);
	button_stepSize.show();


	//level 21

	label_stepSizeValue.set_text("17)stepvalue:\n(Set stepvalue. Used in learning rate policu \"multistep\")");
	label_stepSizeValue.set_line_wrap();
	label_stepSizeValue.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_stepSizeValue,0,21,2,1);
	label_stepSizeValue.show();
	
	text_stepSizeValue.set_max_length(100);
	text_stepSizeValue.set_text("100");
	text_stepSizeValue.select_region(0, text_stepSizeValue.get_text_length());
	m_grid1.attach(text_stepSizeValue,2,21,1,1);	
	text_stepSizeValue.show();	

	button_stepSizeValue.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &SolverProperties::on_button_clicked), "stepSizeValue"));
	m_grid1.attach(button_stepSizeValue,3,21,1,1);
	button_stepSizeValue.show();	

	//level 22
	
	label_weightDecay.set_text("18)weight_decay:");
	label_weightDecay.set_line_wrap();
	label_weightDecay.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_weightDecay,0,22,2,1);
	label_weightDecay.show();
	
	text_weightDecay.set_max_length(100);
	text_weightDecay.set_text("0.0005");
	text_weightDecay.select_region(0, text_weightDecay.get_text_length());
	m_grid1.attach(text_weightDecay,2,22,1,1);	
	text_weightDecay.show();	

	button_weightDecay.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &SolverProperties::on_button_clicked), "weightDecay"));
	m_grid1.attach(button_weightDecay,3,22,1,1);
	button_weightDecay.show();

	//level 23

	label_momentum.set_text("19)momentum:");
	label_momentum.set_line_wrap();
	label_momentum.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_momentum,0,23,2,1);
	label_momentum.show();
	
	text_momentum.set_max_length(100);
	text_momentum.set_text("0.9");
	text_momentum.select_region(0, text_momentum.get_text_length());
	m_grid1.attach(text_momentum,2,23,1,1);	
	text_momentum.show();	

	button_momentum.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &SolverProperties::on_button_clicked), "momentum"));
	m_grid1.attach(button_momentum,3,23,1,1);
	button_momentum.show();



	button_saveFile.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &SolverProperties::on_button_clicked), "saveFile"));
	m_grid1.attach(button_saveFile,0,24,2,1);
	button_saveFile.show();
	
	
	
	m_sw1.add(m_grid1);
	m_sw1.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
//	m_grid1.show();
	show_all_children();
	m_sw1.show();		
}

SolverProperties::~SolverProperties()
{
}

void SolverProperties::on_button_clicked(Glib::ustring data)
{
	if(data == "solverFileName")
	{
		solverFileName = text_solverFileName.get_text();
		std::cout << "Solver File Name set as: " << solverFileName << std::endl;
	}
	else if(data == "trainNetworkFileName")
	{
		trainNetworkFileName = text_trainNetworkFileName.get_text();
		std::cout << "Train Network File Name set as: " << trainNetworkFileName << std::endl;	
	}
	else if(data == "testNetworkFileName")
	{
		testNetworkFileName = text_testNetworkFileName.get_text();
		std::cout << "Test Network File Name set as: " << testNetworkFileName << std::endl;
		if(rbutton_enableTestNet_yes.get_active() == 1 and rbutton_trainNetworkFileType_net.get_active() == 1)
		{
			Gtk::MessageDialog dialog(*this, "\"test_net\" parameter not required");
			dialog.set_secondary_text("\"test_net\" parameter is only required when \"train_net\" parameter is specified");
			dialog.run();
		}
	}
	else if(data == "testIter")
	{
		testIter = text_testIter.get_text();
		std::cout << "Validation(test) Phase iterations set as: " << testIter << std::endl;
		if((rbutton_enableTestNet_yes.get_active() == 1 and rbutton_enableValidationParameters_no.get_active() == 1))
		{
			Gtk::MessageDialog dialog(*this, "Validation parameters required");
			dialog.set_secondary_text("Validation parameters are required when \"test_net\" parameter is specified.");
			dialog.run();
		}
		else if(rbutton_enableValidationParameters_no.get_active() == 1)
		{
			Gtk::MessageDialog dialog(*this, "Enable Validation Parameters");
			dialog.set_secondary_text("Validation parameters can be updated only after enabling them");
			dialog.run();
		}
	}
	else if(data == "testInterval")
	{
		testInterval = text_testInterval.get_text();
		std::cout << "Validation(test) Phase iterations set as: " << testInterval << std::endl;
		if((rbutton_enableTestNet_yes.get_active() == 1 and rbutton_enableValidationParameters_no.get_active() == 1))
		{
			Gtk::MessageDialog dialog(*this, "Validation parameters required");
			dialog.set_secondary_text("Validation parameters are required when \"test_net\" parameter is specified.");
			dialog.run();
		}
		else if(rbutton_enableValidationParameters_no.get_active() == 1)
		{
			Gtk::MessageDialog dialog(*this, "Enable Validation Parameters");
			dialog.set_secondary_text("Validation parameters can be updated only after enabling them");
			dialog.run();
		}
	}
	else if(data == "averageLoss")
	{
		averageLoss = text_averageLoss.get_text();
		std::cout << "Average Loss set as: " << averageLoss << std::endl;
		if(rbutton_enableAverageLoss_no.get_active() == 1)
		{
			Gtk::MessageDialog dialog(*this, "Enable Average Loss Parameter");
			dialog.set_secondary_text("Average Loss Parameter can be updated only after enabling it");
			dialog.run();
		}
	}
	else if(data == "randomSample")
	{
		randomSample = text_randomSample.get_text();
		std::cout << "Random Sample Parameters set as: " << randomSample << std::endl;
		if(rbutton_enableRandomSample_no.get_active() == 1)
		{
			Gtk::MessageDialog dialog(*this, "Enable Random Sample Parameter");
			dialog.set_secondary_text("Random Sample Parameter can be updated only after enabling it");
			dialog.run();
		}
	}
	else if(data == "display")
	{
		display = text_display.get_text();
		std::cout << "Display after every: " << display << " iterations" << std::endl;	
	}
	else if(data == "debugInfo")
	{
		if(rbutton_enableDebugInfo_yes.get_active())
			debugInfo = "1";
		else if(rbutton_enableDebugInfo_no.get_active())
			debugInfo = "0";
		std::cout << "Debug Information: " << debugInfo << std::endl;	
	}
	else if(data == "snapshot")
	{
		snapshot = text_snapshot.get_text();
		std::cout << "Snapshot saved after every: " << snapshot << " iterations" << std::endl;	
	}
	else if(data == "testComputeLoss")
	{
		if(rbutton_enableTestComputeLoss_yes.get_active())
			testComputeLoss = "1";
		else if(rbutton_enableTestComputeLoss_no.get_active())
			testComputeLoss = "0";
		std::cout << "Compute Loss in Validation Phase: " << testComputeLoss << std::endl;	
	}
	else if(data == "snapshotPrefix")
	{
		snapshotPrefix = text_snapshotPrefix.get_text();
		std::cout << "Snapshot saved with prefix: " << snapshotPrefix << std::endl;	
	}
	else if(data == "maxIter")
	{
		maxIter = text_maxIter.get_text();
		std::cout << "Maximum iterations set as: " << maxIter << std::endl;	
	}
	else if(data == "type")
	{
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
		std::cout << "Solver Type Set as: " << type << std::endl;	
	}
	else if(data == "learningRatePolicy")
	{
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

		std::cout << "Learning rate policy is set as: " << learningRatePolicy << std::endl;
	}
	else if(data == "baseLearningRate")
	{
		baseLearningRate = text_baseLearningRate.get_text();
		std::cout << "Initial learning rate set as: " << baseLearningRate << std::endl;	
	}
	else if(data == "gamma")
	{
		gamma = text_gamma.get_text();
		std::cout << "Gamma set as: " << gamma << std::endl;	
	}
	else if(data == "power")
	{
		power = text_power.get_text();
		std::cout << "Power set as: " << power << std::endl;	
	}
	else if(data == "stepSize")
	{
		stepSize = text_stepSize.get_text();
		std::cout << "stepSize set as: " << stepSize << std::endl;	
	}
	else if(data == "stepSizeValue")
	{
		stepSizeValue = text_stepSizeValue.get_text();
		std::cout << "stepSizeValue set as: " << stepSizeValue << std::endl;	
	}
	else if(data == "weightDecay")
	{
		weightDecay = text_weightDecay.get_text();
		std::cout << "weightDecay set as: " << weightDecay << std::endl;	
	}
	else if(data == "momentum")
	{
		momentum = text_momentum.get_text();
		std::cout << "momentum set as: " << momentum << std::endl;	
	}
	else if(data == "saveFile")
	{

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
	}		
	
}
