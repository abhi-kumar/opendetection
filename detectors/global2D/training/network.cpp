#include "network.h"
#include "mainWindow.h"
#include "activationWindow.h"
#include "displayWindow.h"
#include "criticalWindow.h"
#include "normalizationWindow.h"
#include "lossWindow.h"
#include "extraWindow.h"
#include "node.h"

struct Node *newHead;
struct Node *headLayer = new Node;

NetworkCreator::NetworkCreator(): 
	label_networkFileName(""),
	button_networkFileName("Update"),
	text_networkFileName(),

	button_activationLayerType("Append Activation Layer"),
	label_activationLayerType(""),

	button_criticalLayerType("Append Crtitical Layer"),
	label_criticalLayerType(""),
	
	label_normalizationLayerType(""),

	label_lossLayerType(""),

	label_extraLayerType(""),

	button_setActivationParameters("Add This Layer"),
	button_addMoreLayer("Add More Layers"),
	text_activationLayerTop(),
	text_activationLayerBottom(),
	text_activationLayerName(),
	text_activationLayerType(),
	text_activationLayerScale(),
	text_activationLayerShift(),
	text_activationLayerBase(),
	text_activationLayerNegativeSlope(),
	label_activationLayerTop(""),
	label_activationLayerBottom(""),
	label_activationLayerName(""),
	label_activationLayerScale(""),
	label_activationLayerShift(""),
	label_activationLayerBase(""),
	label_activationLayerNegativeSlope(""),

	button_setCriticalParameters("Add This Layer"),
	button_addMoreLayer2("Add more Layers"),
	label_criticalLayerTop(""),
	label_criticalLayerBottom1(""),
	label_criticalLayerBottom2(""),
	label_criticalLayerName(""),
	label_criticalLayerFilterLr(""),
	label_criticalLayerFilterDm(""),
	label_criticalLayerBiasLr(""),
	label_criticalLayerBiasDm(""),
	label_criticalLayerNumOutput(""),
	label_criticalLayerKernelW(""),
	label_criticalLayerKernelH(""),
	label_criticalLayerStrideW(""),
	label_criticalLayerStrideH(""),
	label_criticalLayerPadW(""),
	label_criticalLayerPadH(""),
	label_criticalLayerWeightFiller(""),
	label_criticalLayerWeightFillerConstantValue(""),
	label_criticalLayerWeightFillerUniformMin(""),
	label_criticalLayerWeightFillerUniformMax(""),
	label_criticalLayerWeightFillerGaussianMean(""),
	label_criticalLayerWeightFillerGaussianStd(""),
	label_criticalLayerWeightFillerXavierVariance(""),
	label_criticalLayerWeightFillerMSRAVariance(""),
	label_criticalLayerDropoutRatio(""),
	label_criticalLayerPool(""),
	text_criticalLayerTop(),
	text_criticalLayerBottom1(),
	text_criticalLayerBottom2(),
	text_criticalLayerName(),
	text_criticalLayerFilterLr(),
	text_criticalLayerFilterDm(),
	text_criticalLayerBiasLr(),
	text_criticalLayerBiasDm(),
	text_criticalLayerNumOutput(),
	text_criticalLayerKernelW(),
	text_criticalLayerKernelH(),
	text_criticalLayerStrideW(),
	text_criticalLayerStrideH(),
	text_criticalLayerPadW(),
	text_criticalLayerPadH(),
	text_criticalLayerWeightFillerConstantValue(),
	text_criticalLayerWeightFillerUniformMin(),
	text_criticalLayerWeightFillerUniformMax(),
	text_criticalLayerWeightFillerGaussianMean(),
	text_criticalLayerWeightFillerGaussianStd(),
	text_criticalLayerDropoutRatio(),
	rbutton_criticalLayerWeightFillerConstant("Constant"), rbutton_criticalLayerWeightFillerUniform("Uniform"),
	rbutton_criticalLayerWeightGaussian("Gaussian"), rbutton_criticalLayerWeightFillerPositiveUnitBall("Positive Unit Ball"),
	rbutton_criticalLayerWeightFillerXavier("Xavier"), rbutton_criticalLayerWeightFillerMSRA("MSRA"),
	rbutton_criticalLayerWeightFillerBilinear("Bilinear"),
	rbutton_criticalLayerWeightFillerXavierIn("FAN_IN"), rbutton_criticalLayerWeightFillerXavierOut("FAN_OUT"),
	rbutton_criticalLayerWeightFillerXavierAvg("AVERAGE"),
	rbutton_criticalLayerWeightFillerMSRAIn("FAN_IN"), rbutton_criticalLayerWeightFillerMSRAOut("FAN_OUT"),
	rbutton_criticalLayerWeightFillerMSRAAvg("AVERAGE"),
	rbutton_criticalLayerPoolMax("MAX"), rbutton_criticalLayerPoolAve("AVE"), 

	button_normalizationLayerType("Append Normalization Layer"),
	button_lossLayerType("Add Loss Layer"),
	button_extraLayerType("Append Layer"),
	button_addMoreLayer3("Add More Layers"),
	button_addMoreLayer4("Add More Layers"),
	button_addMoreLayer5("Add More Layers"),
	title_normalizationLayerType(""),
	title_lossLayerType(""),
	title_extraLayerType(""),

	button_displayCnnLayers("Display the Network"),
	button_editMore("Add more layers"),
	box_fullCnnLayerMatter(Gtk::ORIENTATION_VERTICAL),
	button_deleteLayerAtEnd("Delete Layer at the end"),
	button_saveFile("Save File")
{
	numLayers = 0;
	set_title("Network Creator");
	set_border_width(10);
	add(m_sw1);
	m_grid1.set_column_spacing (10);
	m_grid1.set_row_spacing (50);
	
	//level 0

	label_networkFileName.set_text("1) Give a proper name to the Network file: ");
	label_networkFileName.set_line_wrap();
	label_networkFileName.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_networkFileName,0,0,2,1);
	label_networkFileName.show();

	text_networkFileName.set_max_length(100);
	text_networkFileName.set_text("../examples/objectdetector/Mnist_Train/custom_network_design.prototxt");
	text_networkFileName.select_region(0, text_networkFileName.get_text_length());
	m_grid1.attach(text_networkFileName,2,0,1,1);	
	text_networkFileName.show();


	button_networkFileName.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &NetworkCreator::on_button_clicked), "networkFileName"));
	m_grid1.attach(button_networkFileName,3,0,1,1);
	button_networkFileName.show();

	//level 1
	
	label_activationLayerType.set_text("1) Select activation layer:\n(Append activation layer as next layer) ");
	label_activationLayerType.set_line_wrap();
	label_activationLayerType.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_activationLayerType,0,1,2,1);
	label_activationLayerType.show();

	ref_activationLayerType = Gtk::ListStore::create(column_activationLayerType);
  	combo_activationLayerType.set_model(ref_activationLayerType);

	Gtk::TreeModel::Row row_activationLayerType = *(ref_activationLayerType->append());
	row_activationLayerType[column_activationLayerType.m_col_id] = 1;
	row_activationLayerType[column_activationLayerType.m_col_name] = "AbsVal";
	row_activationLayerType[column_activationLayerType.m_col_extra] = "Absolute Value Layer";
	combo_activationLayerType.set_active(row_activationLayerType);

	row_activationLayerType = *(ref_activationLayerType->append());
	row_activationLayerType[column_activationLayerType.m_col_id] = 2;
	row_activationLayerType[column_activationLayerType.m_col_name] = "Exp";
	row_activationLayerType[column_activationLayerType.m_col_extra] = "Exponential Layer";


	row_activationLayerType = *(ref_activationLayerType->append());
	row_activationLayerType[column_activationLayerType.m_col_id] = 3;
	row_activationLayerType[column_activationLayerType.m_col_name] = "Log";
	row_activationLayerType[column_activationLayerType.m_col_extra] = "Log Layer";

	row_activationLayerType = *(ref_activationLayerType->append());
	row_activationLayerType[column_activationLayerType.m_col_id] = 4;
	row_activationLayerType[column_activationLayerType.m_col_name] = "Power";
	row_activationLayerType[column_activationLayerType.m_col_extra] = "Power Layer";

	row_activationLayerType = *(ref_activationLayerType->append());
	row_activationLayerType[column_activationLayerType.m_col_id] = 5;
	row_activationLayerType[column_activationLayerType.m_col_name] = "PReLU";
	row_activationLayerType[column_activationLayerType.m_col_extra] = "PReLU Layer";

	row_activationLayerType = *(ref_activationLayerType->append());
	row_activationLayerType[column_activationLayerType.m_col_id] = 6;
	row_activationLayerType[column_activationLayerType.m_col_name] = "ReLU";
	row_activationLayerType[column_activationLayerType.m_col_extra] = "ReLU Layer";

	row_activationLayerType = *(ref_activationLayerType->append());
	row_activationLayerType[column_activationLayerType.m_col_id] = 7;
	row_activationLayerType[column_activationLayerType.m_col_name] = "Sigmoid";
	row_activationLayerType[column_activationLayerType.m_col_extra] = "Sigmoid Layer";

	row_activationLayerType = *(ref_activationLayerType->append());
	row_activationLayerType[column_activationLayerType.m_col_id] = 8;
	row_activationLayerType[column_activationLayerType.m_col_name] = "TanH";
	row_activationLayerType[column_activationLayerType.m_col_extra] = "Hyperbolic tangent Layer";

	combo_activationLayerType.pack_start(column_activationLayerType.m_col_id);
	combo_activationLayerType.pack_start(column_activationLayerType.m_col_name);
	combo_activationLayerType.set_cell_data_func(cell_activationLayerType,  sigc::mem_fun(*this, &NetworkCreator::on_cell_data_extra));
	combo_activationLayerType.pack_start(cell_activationLayerType);
	
	m_grid1.attach(combo_activationLayerType,2,1,2,1);
	combo_activationLayerType.signal_changed().connect( sigc::mem_fun(*this, &NetworkCreator::on_combo_changed) );

	button_activationLayerType.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &NetworkCreator::on_button_clicked), "activationLayerType"));
	m_grid1.attach(button_activationLayerType,4,1,1,1);
	button_activationLayerType.show();


	// level 2	

	label_criticalLayerType.set_text("2) Select Critical Layer:\n(Append critical layer as next layer) ");
	label_criticalLayerType.set_line_wrap();
	label_criticalLayerType.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_criticalLayerType,0,2,2,1);
	label_criticalLayerType.show();

	ref_criticalLayerType = Gtk::ListStore::create(column_criticalLayerType);
  	combo_criticalLayerType.set_model(ref_criticalLayerType);

	Gtk::TreeModel::Row row_criticalLayerType = *(ref_criticalLayerType->append());
	row_criticalLayerType[column_criticalLayerType.m_col_id] = 1;
	row_criticalLayerType[column_criticalLayerType.m_col_name] = "Accuracy";
	row_criticalLayerType[column_criticalLayerType.m_col_extra] = "Accuracy Layer (Validation phase)";
	combo_criticalLayerType.set_active(row_criticalLayerType);

	row_criticalLayerType = *(ref_criticalLayerType->append());
	row_criticalLayerType[column_criticalLayerType.m_col_id] = 2;
	row_criticalLayerType[column_criticalLayerType.m_col_name] = "Concat";
	row_criticalLayerType[column_criticalLayerType.m_col_extra] = "Concatenation Layer";

	row_criticalLayerType = *(ref_criticalLayerType->append());
	row_criticalLayerType[column_criticalLayerType.m_col_id] = 3;
	row_criticalLayerType[column_criticalLayerType.m_col_name] = "Convolution";
	row_criticalLayerType[column_criticalLayerType.m_col_extra] = "Convolution Layer";

	row_criticalLayerType = *(ref_criticalLayerType->append());
	row_criticalLayerType[column_criticalLayerType.m_col_id] = 4;
	row_criticalLayerType[column_criticalLayerType.m_col_name] = "Deconvolution";
	row_criticalLayerType[column_criticalLayerType.m_col_extra] = "De-Convolution Layer";

	row_criticalLayerType = *(ref_criticalLayerType->append());
	row_criticalLayerType[column_criticalLayerType.m_col_id] = 5;
	row_criticalLayerType[column_criticalLayerType.m_col_name] = "Dropout";
	row_criticalLayerType[column_criticalLayerType.m_col_extra] = "Dropout Layer";

	row_criticalLayerType = *(ref_criticalLayerType->append());
	row_criticalLayerType[column_criticalLayerType.m_col_id] = 6;
	row_criticalLayerType[column_criticalLayerType.m_col_name] = "InnerProduct";
	row_criticalLayerType[column_criticalLayerType.m_col_extra] = "Inner Product (Fully Connected) Layer";

	row_criticalLayerType = *(ref_criticalLayerType->append());
	row_criticalLayerType[column_criticalLayerType.m_col_id] = 7;
	row_criticalLayerType[column_criticalLayerType.m_col_name] = "Pooling";
	row_criticalLayerType[column_criticalLayerType.m_col_extra] = "Pooling Layer";

	row_criticalLayerType = *(ref_criticalLayerType->append());
	row_criticalLayerType[column_criticalLayerType.m_col_id] = 8;
	row_criticalLayerType[column_criticalLayerType.m_col_name] = "Softmax";
	row_criticalLayerType[column_criticalLayerType.m_col_extra] = "Softmax Classification Layer";

	combo_criticalLayerType.pack_start(column_criticalLayerType.m_col_id);
	combo_criticalLayerType.pack_start(column_criticalLayerType.m_col_name);
	combo_criticalLayerType.set_cell_data_func(cell_criticalLayerType,  sigc::mem_fun(*this, &NetworkCreator::on_cell_data_extra));
	combo_criticalLayerType.pack_start(cell_criticalLayerType);
	
	m_grid1.attach(combo_criticalLayerType,2,2,2,1);
	combo_criticalLayerType.signal_changed().connect( sigc::mem_fun(*this, &NetworkCreator::on_combo_changed) );

	button_criticalLayerType.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &NetworkCreator::on_button_clicked), "criticalLayerType"));
	m_grid1.attach(button_criticalLayerType,4,2,1,1);
	button_criticalLayerType.show();

	//level 3

	label_normalizationLayerType.set_text("3) Select Normalization Layer:\n(Append normalization layer as loss layer) ");
	label_normalizationLayerType.set_line_wrap();
	label_normalizationLayerType.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_normalizationLayerType,0,3,2,1);
	label_normalizationLayerType.show();

	ref_normalizationLayerType = Gtk::ListStore::create(column_normalizationLayerType);
  	combo_normalizationLayerType.set_model(ref_normalizationLayerType);

	Gtk::TreeModel::Row row_normalizationLayerType = *(ref_normalizationLayerType->append());
	row_normalizationLayerType[column_normalizationLayerType.m_col_id] = 1;
	row_normalizationLayerType[column_normalizationLayerType.m_col_name] = "BatchNorm";
	row_normalizationLayerType[column_criticalLayerType.m_col_extra] = "Batch Normalization Layer";
	combo_normalizationLayerType.set_active(row_normalizationLayerType);

	row_normalizationLayerType = *(ref_normalizationLayerType->append());
	row_normalizationLayerType[column_normalizationLayerType.m_col_id] = 2;
	row_normalizationLayerType[column_normalizationLayerType.m_col_name] = "LRN";
	row_normalizationLayerType[column_normalizationLayerType.m_col_extra] = "Local Response Normalization Layer";

	row_normalizationLayerType = *(ref_normalizationLayerType->append());
	row_normalizationLayerType[column_normalizationLayerType.m_col_id] = 3;
	row_normalizationLayerType[column_normalizationLayerType.m_col_name] = "MVN";
	row_normalizationLayerType[column_normalizationLayerType.m_col_extra] = "Multi Variate Normalization Layer";

	combo_normalizationLayerType.pack_start(column_normalizationLayerType.m_col_id);
	combo_normalizationLayerType.pack_start(column_normalizationLayerType.m_col_name);
	combo_normalizationLayerType.set_cell_data_func(cell_normalizationLayerType,  sigc::mem_fun(*this, &NetworkCreator::on_cell_data_extra));
	combo_normalizationLayerType.pack_start(cell_normalizationLayerType);
	
	m_grid1.attach(combo_normalizationLayerType,2,3,2,1);
	combo_normalizationLayerType.signal_changed().connect( sigc::mem_fun(*this, &NetworkCreator::on_combo_changed) );

	button_normalizationLayerType.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &NetworkCreator::on_button_clicked), "normalizationLayerType"));
	m_grid1.attach(button_normalizationLayerType,4,3,1,1);
	button_normalizationLayerType.show();

	//level 4

	label_lossLayerType.set_text("4) Select Loss Layer:\n(Append loss layer as next layer) ");
	label_lossLayerType.set_line_wrap();
	label_lossLayerType.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_lossLayerType,0,4,2,1);
	label_lossLayerType.show();

	ref_lossLayerType = Gtk::ListStore::create(column_lossLayerType);
  	combo_lossLayerType.set_model(ref_lossLayerType);

	Gtk::TreeModel::Row row_lossLayerType = *(ref_lossLayerType->append());
	row_lossLayerType[column_lossLayerType.m_col_id] = 1;
	row_lossLayerType[column_lossLayerType.m_col_name] = "SoftmaxWithLoss";
	row_lossLayerType[column_lossLayerType.m_col_extra] = "Loss Layer with softmax activation";
	combo_lossLayerType.set_active(row_lossLayerType);

	row_lossLayerType = *(ref_lossLayerType->append());
	row_lossLayerType[column_lossLayerType.m_col_id] = 2;
	row_lossLayerType[column_lossLayerType.m_col_name] = "HingeLoss";
	row_lossLayerType[column_lossLayerType.m_col_extra] = "Hinge Loss Layer";

	row_lossLayerType = *(ref_lossLayerType->append());
	row_lossLayerType[column_lossLayerType.m_col_id] = 3;
	row_lossLayerType[column_lossLayerType.m_col_name] = "ContrastiveLoss";
	row_lossLayerType[column_lossLayerType.m_col_extra] = "Contrastive Loss Layer";

	row_lossLayerType = *(ref_lossLayerType->append());
	row_lossLayerType[column_lossLayerType.m_col_id] = 4;
	row_lossLayerType[column_lossLayerType.m_col_name] = "EuclideanLoss";
	row_lossLayerType[column_lossLayerType.m_col_extra] = "Euclidean Loss Layer";

	row_lossLayerType = *(ref_lossLayerType->append());
	row_lossLayerType[column_lossLayerType.m_col_id] = 5;
	row_lossLayerType[column_lossLayerType.m_col_name] = "InfogainLoss";
	row_lossLayerType[column_lossLayerType.m_col_extra] = "Infogain Loss Layer";

	row_lossLayerType = *(ref_lossLayerType->append());
	row_lossLayerType[column_lossLayerType.m_col_id] = 6;
	row_lossLayerType[column_lossLayerType.m_col_name] = "MultinomialLogisticLoss";
	row_lossLayerType[column_lossLayerType.m_col_extra] = "Multinomial Logistic Loss Layer";

	row_lossLayerType = *(ref_lossLayerType->append());
	row_lossLayerType[column_lossLayerType.m_col_id] = 7;
	row_lossLayerType[column_lossLayerType.m_col_name] = "EuclideanLoss";
	row_lossLayerType[column_lossLayerType.m_col_extra] = "Euclidean Loss Layer";

	row_lossLayerType = *(ref_lossLayerType->append());
	row_lossLayerType[column_lossLayerType.m_col_id] = 8;
	row_lossLayerType[column_lossLayerType.m_col_name] = "SigmoidCrossEntropyLoss";
	row_lossLayerType[column_lossLayerType.m_col_extra] = "Sigmoid Cross Entropy Loss Layer";

	combo_lossLayerType.pack_start(column_lossLayerType.m_col_id);
	combo_lossLayerType.pack_start(column_lossLayerType.m_col_name);
	combo_lossLayerType.set_cell_data_func(cell_lossLayerType,  sigc::mem_fun(*this, &NetworkCreator::on_cell_data_extra));
	combo_lossLayerType.pack_start(cell_lossLayerType);
	
	m_grid1.attach(combo_lossLayerType,2,4,2,1);
	combo_lossLayerType.signal_changed().connect( sigc::mem_fun(*this, &NetworkCreator::on_combo_changed) );

	button_lossLayerType.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &NetworkCreator::on_button_clicked), "lossLayerType"));
	m_grid1.attach(button_lossLayerType,4,4,1,1);
	button_lossLayerType.show();

	
	//level 5

	label_extraLayerType.set_text("6) A few extra layers:\n(Append these layer as next layer) ");
	label_extraLayerType.set_line_wrap();
	label_extraLayerType.set_justify(Gtk::JUSTIFY_FILL);
	m_grid1.attach(label_extraLayerType,0,5,2,1);
	label_extraLayerType.show();

	ref_extraLayerType = Gtk::ListStore::create(column_extraLayerType);
  	combo_extraLayerType.set_model(ref_extraLayerType);

	Gtk::TreeModel::Row row_extraLayerType = *(ref_extraLayerType->append());
	row_extraLayerType[column_extraLayerType.m_col_id] = 1;
	row_extraLayerType[column_extraLayerType.m_col_name] = "ArgMax";
	row_extraLayerType[column_extraLayerType.m_col_extra] = "Maximum Argument Layer";
	combo_extraLayerType.set_active(row_extraLayerType);

	row_extraLayerType = *(ref_extraLayerType->append());
	row_extraLayerType[column_extraLayerType.m_col_id] = 2;
	row_extraLayerType[column_extraLayerType.m_col_name] = "BNLL";
	row_extraLayerType[column_extraLayerType.m_col_extra] = "Binomial Normal Log Likelihood Layer";

	row_extraLayerType = *(ref_extraLayerType->append());
	row_extraLayerType[column_extraLayerType.m_col_id] = 3;
	row_extraLayerType[column_extraLayerType.m_col_name] = "Eltwise";
	row_extraLayerType[column_extraLayerType.m_col_extra] = "Element Wise Operation Layer";

	row_extraLayerType = *(ref_extraLayerType->append());
	row_extraLayerType[column_extraLayerType.m_col_id] = 4;
	row_extraLayerType[column_extraLayerType.m_col_name] = "Eltwise";
	row_extraLayerType[column_extraLayerType.m_col_extra] = "Element Wise Operation Layer";

	combo_extraLayerType.pack_start(column_extraLayerType.m_col_id);
	combo_extraLayerType.pack_start(column_extraLayerType.m_col_name);
	combo_extraLayerType.set_cell_data_func(cell_extraLayerType,  sigc::mem_fun(*this, &NetworkCreator::on_cell_data_extra));
	combo_extraLayerType.pack_start(cell_extraLayerType);
	
	m_grid1.attach(combo_extraLayerType,2,5,2,1);
	combo_extraLayerType.signal_changed().connect( sigc::mem_fun(*this, &NetworkCreator::on_combo_changed) );

	button_extraLayerType.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &NetworkCreator::on_button_clicked), "extraLayerType"));
	m_grid1.attach(button_extraLayerType,4,5,1,1);
	button_extraLayerType.show();

	button_displayCnnLayers.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &NetworkCreator::on_button_clicked), "displayCnnLayers"));
	m_grid1.attach(button_displayCnnLayers,0,6,2,1);
	button_displayCnnLayers.show();

	button_saveFile.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &NetworkCreator::on_button_clicked), "saveFile"));
	m_grid1.attach(button_saveFile,0,7,2,1);
	button_saveFile.show();
	
	
	
	m_sw1.add(m_grid1);
	m_sw1.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
//	m_grid1.show();
	show_all_children();
	m_sw1.show();	

	
	//Activation Window
	button_setActivationParameters.signal_clicked().connect(sigc::bind<Glib::ustring>(
		      sigc::mem_fun(*this, &NetworkCreator::on_button_clicked), "setActivationParameters"));
	m_grid_activationLayerType.attach(button_setActivationParameters,0,7,2,1);
	
	button_addMoreLayer.signal_clicked().connect(sigc::bind<Glib::ustring>(
		      sigc::mem_fun(*this, &NetworkCreator::on_button_clicked), "addMoreLayer"));
	m_grid_activationLayerType.attach(button_addMoreLayer,2,7,1,1);

	label_activationLayerBottom.set_text("Bottom Layer Name: ");
	label_activationLayerBottom.set_line_wrap();
	label_activationLayerBottom.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_activationLayerType.attach(label_activationLayerBottom,0,1,2,1);
	label_activationLayerBottom.show();

	text_activationLayerBottom.set_max_length(100);
	text_activationLayerBottom.set_text("");
	text_activationLayerBottom.select_region(0, text_activationLayerBottom.get_text_length());
	m_grid_activationLayerType.attach(text_activationLayerBottom,2,1,1,1);	
	text_activationLayerBottom.show();

	label_activationLayerTop.set_text("Top Layer Name: ");
	label_activationLayerTop.set_line_wrap();
	label_activationLayerTop.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_activationLayerType.attach(label_activationLayerTop,0,2,2,1);
	label_activationLayerTop.show();

	text_activationLayerTop.set_max_length(100);
	text_activationLayerTop.set_text("");
	text_activationLayerTop.select_region(0, text_activationLayerTop.get_text_length());
	m_grid_activationLayerType.attach(text_activationLayerTop,2,2,1,1);	
	text_activationLayerTop.show();

	label_activationLayerName.set_text("Current Layer Name: ");
	label_activationLayerName.set_line_wrap();
	label_activationLayerName.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_activationLayerType.attach(label_activationLayerName,0,3,2,1);
	label_activationLayerName.show();

	text_activationLayerName.set_max_length(100);
	text_activationLayerName.set_text("");
	text_activationLayerName.select_region(0, text_activationLayerName.get_text_length());
	m_grid_activationLayerType.attach(text_activationLayerName,2,3,1,1);	
	text_activationLayerName.show();

	label_activationLayerScale.set_text("Layer Parameter Scale: ");
	label_activationLayerScale.set_line_wrap();
	label_activationLayerScale.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_activationLayerType.attach(label_activationLayerScale,0,4,2,1);
	label_activationLayerScale.show();

	text_activationLayerScale.set_max_length(100);
	text_activationLayerScale.set_text("1");
	text_activationLayerScale.select_region(0, text_activationLayerScale.get_text_length());
	m_grid_activationLayerType.attach(text_activationLayerScale,2,4,1,1);	
	text_activationLayerScale.show();

	label_activationLayerShift.set_text("Layer Parameter Shift: ");
	label_activationLayerShift.set_line_wrap();
	label_activationLayerShift.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_activationLayerType.attach(label_activationLayerShift,0,5,2,1);
	label_activationLayerShift.show();

	text_activationLayerShift.set_max_length(100);
	text_activationLayerShift.set_text("0");
	text_activationLayerShift.select_region(0, text_activationLayerShift.get_text_length());
	m_grid_activationLayerType.attach(text_activationLayerShift,2,5,1,1);	
	text_activationLayerShift.show();

	label_activationLayerBase.set_text("Layer Parameter Base: ");
	label_activationLayerBase.set_line_wrap();
	label_activationLayerBase.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_activationLayerType.attach(label_activationLayerBase,0,6,2,1);
	label_activationLayerBase.show();

	text_activationLayerBase.set_max_length(100);
	text_activationLayerBase.set_text("-1");
	text_activationLayerBase.select_region(0, text_activationLayerBase.get_text_length());
	m_grid_activationLayerType.attach(text_activationLayerBase,2,6,1,1);	
	text_activationLayerBase.show();

	label_activationLayerNegativeSlope.set_text("Relu Param Negative Slope: ");
	label_activationLayerNegativeSlope.set_line_wrap();
	label_activationLayerNegativeSlope.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_activationLayerType.attach(label_activationLayerNegativeSlope,0,4,2,1);
	label_activationLayerNegativeSlope.show();

	text_activationLayerNegativeSlope.set_max_length(100);
	text_activationLayerNegativeSlope.set_text("0");
	text_activationLayerNegativeSlope.select_region(0, text_activationLayerNegativeSlope.get_text_length());
	m_grid_activationLayerType.attach(text_activationLayerNegativeSlope,2,4,1,1);	
	text_activationLayerNegativeSlope.show();

	title_activationLayerType.set_text("Set the Properties of Activation Layer type: ");
	title_activationLayerType.set_line_wrap();
	title_activationLayerType.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_activationLayerType.attach(title_activationLayerType,0,0,2,1);
	title_activationLayerType.show();

	m_sw_activationLayerType.add(m_grid_activationLayerType);


	//Critical Layer Window
	title_criticalLayerType.set_text("Set the Properties of Critical Layer type: ");
	title_criticalLayerType.set_line_wrap();
	title_criticalLayerType.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_criticalLayerType.attach(title_criticalLayerType,0,0,2,1);
	title_criticalLayerType.show();

	button_setCriticalParameters.signal_clicked().connect(sigc::bind<Glib::ustring>(
		      sigc::mem_fun(*this, &NetworkCreator::on_button_clicked), "setCriticalParameters"));
	m_grid_criticalLayerType.attach(button_setCriticalParameters,0,25,2,1);
	button_addMoreLayer2.signal_clicked().connect(sigc::bind<Glib::ustring>(
		      sigc::mem_fun(*this, &NetworkCreator::on_button_clicked), "addMoreLayer2"));
	m_grid_criticalLayerType.attach(button_addMoreLayer2,2,25,1,1);

	label_criticalLayerBottom1.set_text("Bottom1 Layer Name: ");
	label_criticalLayerBottom1.set_line_wrap();
	label_criticalLayerBottom1.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_criticalLayerType.attach(label_criticalLayerBottom1,0,1,2,1);
	label_criticalLayerBottom1.show();

	text_criticalLayerBottom1.set_max_length(100);
	text_criticalLayerBottom1.set_text("");
	text_criticalLayerBottom1.select_region(0, text_criticalLayerBottom1.get_text_length());
	m_grid_criticalLayerType.attach(text_criticalLayerBottom1,2,1,1,1);	
	text_criticalLayerBottom1.show();

	label_criticalLayerBottom2.set_text("Bottom2 Layer Name: ");
	label_criticalLayerBottom2.set_line_wrap();
	label_criticalLayerBottom2.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_criticalLayerType.attach(label_criticalLayerBottom2,0,2,2,1);
	label_criticalLayerBottom2.show();

	text_criticalLayerBottom2.set_max_length(100);
	text_criticalLayerBottom2.set_text("");
	text_criticalLayerBottom2.select_region(0, text_criticalLayerBottom2.get_text_length());
	m_grid_criticalLayerType.attach(text_criticalLayerBottom2,2,2,1,1);	
	text_criticalLayerBottom2.show();

	label_criticalLayerTop.set_text("Top Layer Name: ");
	label_criticalLayerTop.set_line_wrap();
	label_criticalLayerTop.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_criticalLayerType.attach(label_criticalLayerTop,0,3,2,1);
	label_criticalLayerTop.show();

	text_criticalLayerTop.set_max_length(100);
	text_criticalLayerTop.set_text("");
	text_criticalLayerTop.select_region(0, text_criticalLayerTop.get_text_length());
	m_grid_criticalLayerType.attach(text_criticalLayerTop,2,3,1,1);	
	text_criticalLayerTop.show();

	label_criticalLayerName.set_text("Current Layer Name: ");
	label_criticalLayerName.set_line_wrap();
	label_criticalLayerName.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_criticalLayerType.attach(label_criticalLayerName,0,4,2,1);
	label_criticalLayerName.show();

	text_criticalLayerName.set_max_length(100);
	text_criticalLayerName.set_text("");
	text_criticalLayerName.select_region(0, text_criticalLayerName.get_text_length());
	m_grid_criticalLayerType.attach(text_criticalLayerName,2,4,1,1);	
	text_criticalLayerName.show();

	label_criticalLayerFilterLr.set_text("Set filter lr_mult:\n(Leave unchanged if not needed) ");
	label_criticalLayerFilterLr.set_line_wrap();
	label_criticalLayerFilterLr.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_criticalLayerType.attach(label_criticalLayerFilterLr,0,5,2,1);
	label_criticalLayerFilterLr.show();

	text_criticalLayerFilterLr.set_max_length(100);
	text_criticalLayerFilterLr.set_text("1");
	text_criticalLayerFilterLr.select_region(0, text_criticalLayerFilterLr.get_text_length());
	m_grid_criticalLayerType.attach(text_criticalLayerFilterLr,2,5,1,1);	
	text_criticalLayerFilterLr.show();

	label_criticalLayerFilterDm.set_text("Set filter decay_mult:\n(Leave unchanged if not needed) ");
	label_criticalLayerFilterDm.set_line_wrap();
	label_criticalLayerFilterDm.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_criticalLayerType.attach(label_criticalLayerFilterDm,0,6,2,1);
	label_criticalLayerFilterDm.show();

	text_criticalLayerFilterDm.set_max_length(100);
	text_criticalLayerFilterDm.set_text("1");
	text_criticalLayerFilterDm.select_region(0, text_criticalLayerFilterDm.get_text_length());
	m_grid_criticalLayerType.attach(text_criticalLayerFilterDm,2,6,1,1);	
	text_criticalLayerFilterDm.show();

	label_criticalLayerBiasLr.set_text("Set bias lr_mult:\n(Leave unchanged if not needed) ");
	label_criticalLayerBiasLr.set_line_wrap();
	label_criticalLayerBiasLr.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_criticalLayerType.attach(label_criticalLayerBiasLr,0,7,2,1);
	label_criticalLayerBiasLr.show();

	text_criticalLayerBiasLr.set_max_length(100);
	text_criticalLayerBiasLr.set_text("2");
	text_criticalLayerBiasLr.select_region(0, text_criticalLayerBiasLr.get_text_length());
	m_grid_criticalLayerType.attach(text_criticalLayerBiasLr,2,7,1,1);	
	text_criticalLayerBiasLr.show();

	label_criticalLayerBiasDm.set_text("Set bias decay_mult:\n(Leave unchanged if not needed) ");
	label_criticalLayerBiasDm.set_line_wrap();
	label_criticalLayerBiasDm.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_criticalLayerType.attach(label_criticalLayerBiasDm,0,8,2,1);
	label_criticalLayerBiasDm.show();

	text_criticalLayerBiasDm.set_max_length(100);
	text_criticalLayerBiasDm.set_text("0");
	text_criticalLayerBiasDm.select_region(0, text_criticalLayerBiasDm.get_text_length());
	m_grid_criticalLayerType.attach(text_criticalLayerBiasDm,2,8,1,1);	
	text_criticalLayerBiasDm.show();

	label_criticalLayerNumOutput.set_text("Set param num_output: ");
	label_criticalLayerNumOutput.set_line_wrap();
	label_criticalLayerNumOutput.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_criticalLayerType.attach(label_criticalLayerNumOutput,0,9,2,1);
	label_criticalLayerNumOutput.show();

	text_criticalLayerNumOutput.set_max_length(100);
	text_criticalLayerNumOutput.set_text("64");
	text_criticalLayerNumOutput.select_region(0, text_criticalLayerNumOutput.get_text_length());
	m_grid_criticalLayerType.attach(text_criticalLayerNumOutput,2,9,1,1);	
	text_criticalLayerNumOutput.show();

	label_criticalLayerKernelW.set_text("Set param kernel_w: ");
	label_criticalLayerKernelW.set_line_wrap();
	label_criticalLayerKernelW.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_criticalLayerType.attach(label_criticalLayerKernelW,0,10,2,1);
	label_criticalLayerKernelW.show();

	text_criticalLayerKernelW.set_max_length(100);
	text_criticalLayerKernelW.set_text("3");
	text_criticalLayerKernelW.select_region(0, text_criticalLayerKernelW.get_text_length());
	m_grid_criticalLayerType.attach(text_criticalLayerKernelW,2,10,1,1);	
	text_criticalLayerKernelW.show();

	label_criticalLayerKernelH.set_text("Set param kernel_h: ");
	label_criticalLayerKernelH.set_line_wrap();
	label_criticalLayerKernelH.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_criticalLayerType.attach(label_criticalLayerKernelH,0,11,2,1);
	label_criticalLayerKernelH.show();

	text_criticalLayerKernelH.set_max_length(100);
	text_criticalLayerKernelH.set_text("3");
	text_criticalLayerKernelH.select_region(0, text_criticalLayerKernelH.get_text_length());
	m_grid_criticalLayerType.attach(text_criticalLayerKernelH,2,11,1,1);	
	text_criticalLayerKernelH.show();

	label_criticalLayerStrideW.set_text("Set param stride_w: ");
	label_criticalLayerStrideW.set_line_wrap();
	label_criticalLayerStrideW.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_criticalLayerType.attach(label_criticalLayerStrideW,0,12,2,1);
	label_criticalLayerStrideW.show();

	text_criticalLayerStrideW.set_max_length(100);
	text_criticalLayerStrideW.set_text("1");
	text_criticalLayerStrideW.select_region(0, text_criticalLayerStrideW.get_text_length());
	m_grid_criticalLayerType.attach(text_criticalLayerStrideW,2,12,1,1);	
	text_criticalLayerStrideW.show();

	label_criticalLayerStrideH.set_text("Set param stride_h: ");
	label_criticalLayerStrideH.set_line_wrap();
	label_criticalLayerStrideH.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_criticalLayerType.attach(label_criticalLayerStrideH,0,13,2,1);
	label_criticalLayerStrideH.show();

	text_criticalLayerStrideH.set_max_length(100);
	text_criticalLayerStrideH.set_text("1");
	text_criticalLayerStrideH.select_region(0, text_criticalLayerStrideH.get_text_length());
	m_grid_criticalLayerType.attach(text_criticalLayerStrideH,2,13,1,1);	
	text_criticalLayerStrideH.show();

	label_criticalLayerPadW.set_text("Set param pad_w: ");
	label_criticalLayerPadW.set_line_wrap();
	label_criticalLayerPadW.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_criticalLayerType.attach(label_criticalLayerPadW,0,14,2,1);
	label_criticalLayerPadW.show();

	text_criticalLayerPadW.set_max_length(100);
	text_criticalLayerPadW.set_text("1");
	text_criticalLayerPadW.select_region(0, text_criticalLayerPadW.get_text_length());
	m_grid_criticalLayerType.attach(text_criticalLayerPadW,2,14,1,1);	
	text_criticalLayerPadW.show();

	label_criticalLayerPadH.set_text("Set param pad_h: ");
	label_criticalLayerPadH.set_line_wrap();
	label_criticalLayerPadH.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_criticalLayerType.attach(label_criticalLayerPadH,0,15,2,1);
	label_criticalLayerPadH.show();

	text_criticalLayerPadH.set_max_length(100);
	text_criticalLayerPadH.set_text("1");
	text_criticalLayerPadH.select_region(0, text_criticalLayerPadH.get_text_length());
	m_grid_criticalLayerType.attach(text_criticalLayerPadH,2,15,1,1);	
	text_criticalLayerPadH.show();

	label_criticalLayerWeightFiller.set_text("Set Weight Filler : ");
	label_criticalLayerWeightFiller.set_line_wrap();
	label_criticalLayerWeightFiller.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_criticalLayerType.attach(label_criticalLayerWeightFiller,0,16,2,1);
	label_criticalLayerWeightFiller.show();

	Gtk::RadioButton::Group group1 = rbutton_criticalLayerWeightFillerConstant.get_group();
 	rbutton_criticalLayerWeightFillerUniform.set_group(group1);
 	rbutton_criticalLayerWeightGaussian.set_group(group1);
 	rbutton_criticalLayerWeightFillerPositiveUnitBall.set_group(group1);
 	rbutton_criticalLayerWeightFillerXavier.set_group(group1);
 	rbutton_criticalLayerWeightFillerMSRA.set_group(group1);
 	rbutton_criticalLayerWeightFillerBilinear.set_group(group1);
	rbutton_criticalLayerWeightFillerConstant.set_active();
	m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerConstant,2,16,1,1);
	rbutton_criticalLayerWeightFillerConstant.show();
	m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerUniform,2,17,1,1);
	rbutton_criticalLayerWeightFillerUniform.show();
	m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightGaussian,2,18,1,1);
	rbutton_criticalLayerWeightGaussian.show();
	m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerPositiveUnitBall,2,19,1,1);
	rbutton_criticalLayerWeightFillerPositiveUnitBall.show();
	m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerXavier,2,20,1,1);
	rbutton_criticalLayerWeightFillerXavier.show();
	m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerMSRA,2,21,1,1);
	rbutton_criticalLayerWeightFillerMSRA.show();
	m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerBilinear,2,22,1,1);
	rbutton_criticalLayerWeightFillerBilinear.show();

	label_criticalLayerWeightFillerConstantValue.set_text("value: ");
	label_criticalLayerWeightFillerConstantValue.set_line_wrap();
	label_criticalLayerWeightFillerConstantValue.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_criticalLayerType.attach(label_criticalLayerWeightFillerConstantValue,4,16,1,1);
	label_criticalLayerWeightFillerConstantValue.show();

	text_criticalLayerWeightFillerConstantValue.set_max_length(100);
	text_criticalLayerWeightFillerConstantValue.set_text("0.5");
	text_criticalLayerWeightFillerConstantValue.select_region(0, text_criticalLayerWeightFillerConstantValue.get_text_length());
	m_grid_criticalLayerType.attach(text_criticalLayerWeightFillerConstantValue,5,16,1,1);	
	text_criticalLayerWeightFillerConstantValue.show();

	label_criticalLayerWeightFillerUniformMin.set_text("min: ");
	label_criticalLayerWeightFillerUniformMin.set_line_wrap();
	label_criticalLayerWeightFillerUniformMin.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_criticalLayerType.attach(label_criticalLayerWeightFillerUniformMin,4,17,1,1);
	label_criticalLayerWeightFillerUniformMin.show();

	text_criticalLayerWeightFillerUniformMin.set_max_length(100);
	text_criticalLayerWeightFillerUniformMin.set_text("0");
	text_criticalLayerWeightFillerUniformMin.select_region(0, text_criticalLayerWeightFillerUniformMin.get_text_length());
	m_grid_criticalLayerType.attach(text_criticalLayerWeightFillerUniformMin,5,17,1,1);	
	text_criticalLayerWeightFillerUniformMin.show();

	label_criticalLayerWeightFillerUniformMax.set_text("max: ");
	label_criticalLayerWeightFillerUniformMax.set_line_wrap();
	label_criticalLayerWeightFillerUniformMax.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_criticalLayerType.attach(label_criticalLayerWeightFillerUniformMax,6,17,1,1);
	label_criticalLayerWeightFillerUniformMax.show();

	text_criticalLayerWeightFillerUniformMax.set_max_length(100);
	text_criticalLayerWeightFillerUniformMax.set_text("1");
	text_criticalLayerWeightFillerUniformMax.select_region(0, text_criticalLayerWeightFillerUniformMax.get_text_length());
	m_grid_criticalLayerType.attach(text_criticalLayerWeightFillerUniformMax,7,17,1,1);	
	text_criticalLayerWeightFillerUniformMax.show();				

	label_criticalLayerWeightFillerGaussianMean.set_text("mean: ");
	label_criticalLayerWeightFillerGaussianMean.set_line_wrap();
	label_criticalLayerWeightFillerGaussianMean.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_criticalLayerType.attach(label_criticalLayerWeightFillerGaussianMean,4,18,1,1);
	label_criticalLayerWeightFillerGaussianMean.show();

	text_criticalLayerWeightFillerGaussianMean.set_max_length(100);
	text_criticalLayerWeightFillerGaussianMean.set_text("0");
	text_criticalLayerWeightFillerGaussianMean.select_region(0, text_criticalLayerWeightFillerGaussianMean.get_text_length());
	m_grid_criticalLayerType.attach(text_criticalLayerWeightFillerGaussianMean,5,18,1,1);	
	text_criticalLayerWeightFillerGaussianMean.show();

	label_criticalLayerWeightFillerGaussianStd.set_text("std: ");
	label_criticalLayerWeightFillerGaussianStd.set_line_wrap();
	label_criticalLayerWeightFillerGaussianStd.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_criticalLayerType.attach(label_criticalLayerWeightFillerGaussianStd,6,18,1,1);
	label_criticalLayerWeightFillerGaussianStd.show();

	text_criticalLayerWeightFillerGaussianStd.set_max_length(100);
	text_criticalLayerWeightFillerGaussianStd.set_text("0.1");
	text_criticalLayerWeightFillerGaussianStd.select_region(0, text_criticalLayerWeightFillerGaussianStd.get_text_length());
	m_grid_criticalLayerType.attach(text_criticalLayerWeightFillerGaussianStd,7,18,1,1);	
	text_criticalLayerWeightFillerGaussianStd.show();

	label_criticalLayerWeightFillerXavierVariance.set_text("variance_norm: ");
	label_criticalLayerWeightFillerXavierVariance.set_line_wrap();
	label_criticalLayerWeightFillerXavierVariance.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_criticalLayerType.attach(label_criticalLayerWeightFillerXavierVariance,4,20,1,1);
	label_criticalLayerWeightFillerXavierVariance.show();

	Gtk::RadioButton::Group group2 = rbutton_criticalLayerWeightFillerXavierIn.get_group();
 	rbutton_criticalLayerWeightFillerXavierOut.set_group(group2);
 	rbutton_criticalLayerWeightFillerXavierAvg.set_group(group2);
 	rbutton_criticalLayerWeightFillerXavierIn.set_active();
	m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerXavierIn,5,20,1,1);
	rbutton_criticalLayerWeightFillerXavierIn.show();
	m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerXavierOut,6,20,1,1);
	rbutton_criticalLayerWeightFillerXavierOut.show();
	m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerXavierAvg,7,20,1,1);
	rbutton_criticalLayerWeightFillerXavierAvg.show();

	label_criticalLayerWeightFillerMSRAVariance.set_text("variance_norm: ");
	label_criticalLayerWeightFillerMSRAVariance.set_line_wrap();
	label_criticalLayerWeightFillerMSRAVariance.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_criticalLayerType.attach(label_criticalLayerWeightFillerMSRAVariance,4,21,1,1);
	label_criticalLayerWeightFillerMSRAVariance.show();

	Gtk::RadioButton::Group group3 = rbutton_criticalLayerWeightFillerMSRAIn.get_group();
 	rbutton_criticalLayerWeightFillerMSRAOut.set_group(group3);
 	rbutton_criticalLayerWeightFillerMSRAAvg.set_group(group3);
 	rbutton_criticalLayerWeightFillerMSRAIn.set_active();
	m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerMSRAIn,5,21,1,1);
	rbutton_criticalLayerWeightFillerMSRAIn.show();
	m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerMSRAOut,6,21,1,1);
	rbutton_criticalLayerWeightFillerMSRAOut.show();
	m_grid_criticalLayerType.attach(rbutton_criticalLayerWeightFillerMSRAAvg,7,21,1,1);
	rbutton_criticalLayerWeightFillerMSRAAvg.show();

	label_criticalLayerDropoutRatio.set_text("Set Dropout Ratio: ");
	label_criticalLayerDropoutRatio.set_line_wrap();
	label_criticalLayerDropoutRatio.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_criticalLayerType.attach(label_criticalLayerDropoutRatio,0,22,2,1);
	label_criticalLayerDropoutRatio.show();

	text_criticalLayerDropoutRatio.set_max_length(100);
	text_criticalLayerDropoutRatio.set_text("0.5");
	text_criticalLayerDropoutRatio.select_region(0, text_criticalLayerDropoutRatio.get_text_length());
	m_grid_criticalLayerType.attach(text_criticalLayerDropoutRatio,2,22,1,1);	
	text_criticalLayerDropoutRatio.show();
	
	label_criticalLayerPool.set_text("Set Pool Type: ");
	label_criticalLayerPool.set_line_wrap();
	label_criticalLayerPool.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_criticalLayerType.attach(label_criticalLayerPool,0,23,2,1);
	label_criticalLayerPool.show();
	
	Gtk::RadioButton::Group group4 = rbutton_criticalLayerPoolMax.get_group();
 	rbutton_criticalLayerPoolAve.set_group(group4);
 	rbutton_criticalLayerPoolMax.set_active();
	m_grid_criticalLayerType.attach(rbutton_criticalLayerPoolMax,2,23,1,1);
	rbutton_criticalLayerPoolMax.show();
	m_grid_criticalLayerType.attach(rbutton_criticalLayerPoolAve,3,23,1,1);
	rbutton_criticalLayerPoolAve.show();
	
	label_criticalLayerBias.set_text("Set bias value: ");
	label_criticalLayerBias.set_line_wrap();
	label_criticalLayerBias.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_criticalLayerType.attach(label_criticalLayerBias,0,24,2,1);
	label_criticalLayerBias.show();

	text_criticalLayerBias.set_max_length(100);
	text_criticalLayerBias.set_text("0.1");
	text_criticalLayerBias.select_region(0, text_criticalLayerBias.get_text_length());
	m_grid_criticalLayerType.attach(text_criticalLayerBias,2,24,1,1);	
	text_criticalLayerBias.show();

	m_sw_criticalLayerType.add(m_grid_criticalLayerType);


	//Normalization Layer Window
	title_normalizationLayerType.set_text("Will be updated soon");
	title_normalizationLayerType.set_line_wrap();
	title_normalizationLayerType.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_normalizationLayerType.attach(title_normalizationLayerType,0,0,2,1);
	title_normalizationLayerType.show();

	button_addMoreLayer3.signal_clicked().connect(sigc::bind<Glib::ustring>(
		      sigc::mem_fun(*this, &NetworkCreator::on_button_clicked), "addMoreLayer3"));
	m_grid_normalizationLayerType.attach(button_addMoreLayer3,0,2,1,1);

	m_sw_normalizationLayerType.add(m_grid_normalizationLayerType);


	//Loss Layer Window
	title_lossLayerType.set_text("Will be updated soon");
	title_lossLayerType.set_line_wrap();
	title_lossLayerType.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_lossLayerType.attach(title_lossLayerType,0,0,2,1);
	title_lossLayerType.show();

	button_addMoreLayer4.signal_clicked().connect(sigc::bind<Glib::ustring>(
		      sigc::mem_fun(*this, &NetworkCreator::on_button_clicked), "addMoreLayer4"));
	m_grid_lossLayerType.attach(button_addMoreLayer4,0,2,1,1);

	m_sw_lossLayerType.add(m_grid_lossLayerType);


	//Extra Layer Window
	title_extraLayerType.set_text("Will be updated soon");
	title_extraLayerType.set_line_wrap();
	title_extraLayerType.set_justify(Gtk::JUSTIFY_FILL);
	m_grid_extraLayerType.attach(title_extraLayerType,0,0,2,1);
	title_extraLayerType.show();

	button_addMoreLayer5.signal_clicked().connect(sigc::bind<Glib::ustring>(
		      sigc::mem_fun(*this, &NetworkCreator::on_button_clicked), "addMoreLayer5"));
	m_grid_extraLayerType.attach(button_addMoreLayer5,0,2,1,1);

	m_sw_extraLayerType.add(m_grid_extraLayerType);

	//Display Window

	set_title("Activation Layer");
	set_border_width(10);
//	add(box_fullCnnLayerMatter);
	m_sw_fullCnnLayerMatter.add(textView_fullCnnLayerMatter);
	m_sw_fullCnnLayerMatter.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
	box_fullCnnLayerMatter.pack_start(m_sw_fullCnnLayerMatter);
	button_editMore.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &NetworkCreator::on_button_clicked), "editMore"));
	button_deleteLayerAtEnd.signal_clicked().connect(sigc::bind<Glib::ustring>(
              sigc::mem_fun(*this, &NetworkCreator::on_button_clicked), "deleteLayerAtEnd"));
	box_fullCnnLayerMatter.pack_start(buttonBox_fullCnnLayerMatter, Gtk::PACK_SHRINK);	
	buttonBox_fullCnnLayerMatter.pack_start(button_editMore, Gtk::PACK_SHRINK);
	buttonBox_fullCnnLayerMatter.pack_start(button_deleteLayerAtEnd, Gtk::PACK_SHRINK);
	buttonBox_fullCnnLayerMatter.set_border_width(5);
	buttonBox_fullCnnLayerMatter.set_spacing(5);
	buttonBox_fullCnnLayerMatter.set_layout(Gtk::BUTTONBOX_END);
	buffer_fullCnnLayerMatter = Gtk::TextBuffer::create();
}

NetworkCreator::~NetworkCreator()
{
}


void NetworkCreator::on_button_clicked(Glib::ustring data)
{
	if(data == "networkFileName")
	{
		networkFileName = text_networkFileName.get_text();
		std::cout << "Network File Name set as: " << networkFileName << std::endl;
	}
	else if(data == "activationLayerType")
	{
		showWindow_activationLayerType(activationLayerTypeData);
	}
	else if(data == "addMoreLayer")
	{
		showWindow_main();
	}
	else if(data == "setActivationParameters")
	{
		activationLayerTypeMatter = "";
		if(activationLayerTypeData == "AbsVal" or activationLayerTypeData == "PReLU" or activationLayerTypeData == "Sigmoid" or activationLayerTypeData == "TanH" or activationLayerTypeData == "")
		{ 
			activationLayerTypeMatter = "layer{";
			activationLayerTypeMatter += "\n\tbottom: \"" +  text_activationLayerBottom.get_text() + "\"";
			activationLayerTypeMatter += "\n\ttop: \"" + text_activationLayerTop.get_text() + "\"";
			activationLayerTypeMatter += "\n\tname: \"" + text_activationLayerName.get_text() + "\"";
			if(activationLayerTypeData == "")
				activationLayerTypeData = "AbsVal";
			activationLayerTypeMatter += "\n\ttype: \"" + activationLayerTypeData + "\"";
			activationLayerTypeMatter += "\n}\n";
		}
		else if(activationLayerTypeData == "ReLU")
		{
			activationLayerTypeMatter = "layer{";
			activationLayerTypeMatter += "\n\tbottom: \"" +  text_activationLayerBottom.get_text() + "\"";
			activationLayerTypeMatter += "\n\ttop: \"" + text_activationLayerTop.get_text() + "\"";
			activationLayerTypeMatter += "\n\tname: \"" + text_activationLayerName.get_text() + "\"";
			activationLayerTypeMatter += "\n\ttype: \"" + activationLayerTypeData + "\"";
			activationLayerTypeMatter += "\n\trelu_param{";
			activationLayerTypeMatter += "\n\t\tnegative_slope: " + text_activationLayerNegativeSlope.get_text();
			activationLayerTypeMatter += "\n\t}";
			activationLayerTypeMatter += "\n}\n";
		}
		else if(activationLayerTypeData == "Exp" or activationLayerTypeData == "Log")
		{

			activationLayerTypeMatter = "layer{";
			activationLayerTypeMatter += "\n\tbottom: \"" +  text_activationLayerBottom.get_text() + "\"";
			activationLayerTypeMatter += "\n\ttop: \"" + text_activationLayerTop.get_text() + "\"";
			activationLayerTypeMatter += "\n\tname: \"" + text_activationLayerName.get_text() + "\"";
			activationLayerTypeMatter += "\n\ttype: \"" + activationLayerTypeData + "\"";
			if(activationLayerTypeData == "Exp")
				activationLayerTypeMatter += "\n\texp_param{";
			else if(activationLayerTypeData == "Log")
				activationLayerTypeMatter += "\n\texp_param{";
			activationLayerTypeMatter += "\n\t\tscale: " + text_activationLayerScale.get_text();
			activationLayerTypeMatter += "\n\t\tshift: " + text_activationLayerShift.get_text();
			activationLayerTypeMatter += "\n\t\tbase: " + text_activationLayerBase.get_text();
			activationLayerTypeMatter += "\n\t}";
			activationLayerTypeMatter += "\n}\n";
		}
		else if(activationLayerTypeData == "Power")
		{
			activationLayerTypeMatter = "layer{";
			activationLayerTypeMatter += "\n\tbottom: \"" +  text_activationLayerBottom.get_text() + "\"";
			activationLayerTypeMatter += "\n\ttop: \"" + text_activationLayerTop.get_text() + "\"";
			activationLayerTypeMatter += "\n\tname: \"" + text_activationLayerName.get_text() + "\"";
			activationLayerTypeMatter += "\n\ttype: \"" + data + "\"";
			activationLayerTypeMatter += "\n\tpower_param{";
			activationLayerTypeMatter += "\n\t\tscale: " + text_activationLayerScale.get_text();
			activationLayerTypeMatter += "\n\t\tshift: " + text_activationLayerShift.get_text();
			activationLayerTypeMatter += "\n\t\tpower: " + text_activationLayerBase.get_text();
			activationLayerTypeMatter += "\n\t}";
			activationLayerTypeMatter += "\n}\n";
		}


//		std::cout << activationLayerTypeMatter << std::endl;
		if(numLayers == 0)
		{
			initializeLayer(headLayer,activationLayerTypeMatter);
			numLayers++;
			fullCnnLayers.push_back(activationLayerTypeMatter);
		}
		else
		{
			appendLayer(headLayer,activationLayerTypeMatter);
			numLayers++;
			fullCnnLayers.push_back(activationLayerTypeMatter);
		}	
	}
	else if(data == "displayCnnLayers")
	{
		fullCnnLayerMatter = displayCNN(headLayer);
		showWindow_displayWindow();
	}
	else if(data == "editMore")
	{
		showWindow_main();
	}
	else if(data == "deleteLayerAtEnd")
	{
		if(numLayers>1)   //cannot delete the first created layer
		{
			Glib::ustring lastLayer = fullCnnLayers[numLayers-1];
//			std::cout << lastLayer << std:: endl;
			fullCnnLayers.pop_back();
			numLayers--;
			Node *layer = searchLayer(headLayer,lastLayer);
			if(deleteLayer(&headLayer,layer)) 
				std::cout << "numLayers = "<< numLayers << "\n";
			fullCnnLayerMatter = displayCNN(headLayer);
			showWindow_displayWindow();
		}
				
	}
	else if(data == "criticalLayerType")
	{
		showWindow_criticalLayerType(criticalLayerTypeData);
	}
	else if(data == "addMoreLayer2")
	{
		showWindow_main();
	}
	else if(data == "setCriticalParameters")
	{
		criticalLayerTypeMatter = "";
		if(criticalLayerTypeData == "")
			criticalLayerTypeData = "Accuracy";
		if(criticalLayerTypeData == "Accuracy" or criticalLayerTypeData == "Softmax")
		{
			criticalLayerTypeMatter = "layer{";
			criticalLayerTypeMatter += "\n\tbottom: \"" +  text_criticalLayerBottom1.get_text() + "\"";
			criticalLayerTypeMatter += "\n\tbottom: \"" +  text_criticalLayerBottom2.get_text() + "\"";
			criticalLayerTypeMatter += "\n\ttop: \"" + text_criticalLayerTop.get_text() + "\"";
			criticalLayerTypeMatter += "\n\tname: \"" + text_criticalLayerName.get_text() + "\"";
			criticalLayerTypeMatter += "\n\ttype: \"" + criticalLayerTypeData + "\"";
			criticalLayerTypeMatter += "\n\tinclude{";
			criticalLayerTypeMatter += "\n\t\tphase: TEST";
			criticalLayerTypeMatter += "\n\t}";
			criticalLayerTypeMatter += "\n}\n";			
		}
		else if(criticalLayerTypeData == "Convolution" or criticalLayerTypeData == "Deconvolution")
		{
			criticalLayerTypeMatter = "layer{";
			criticalLayerTypeMatter += "\n\tbottom: \"" +  text_criticalLayerBottom1.get_text() + "\"";
			criticalLayerTypeMatter += "\n\ttop: \"" + text_criticalLayerTop.get_text() + "\"";
			criticalLayerTypeMatter += "\n\tname: \"" + text_criticalLayerName.get_text() + "\"";
			criticalLayerTypeMatter += "\n\ttype: \"" + criticalLayerTypeData + "\"";
			criticalLayerTypeMatter += "\n\tparam{";
			criticalLayerTypeMatter += "\n\t\tlr_mult: " + text_criticalLayerFilterLr.get_text();
			criticalLayerTypeMatter += "\n\t\tdecay_mult: " + text_criticalLayerFilterDm.get_text();
			criticalLayerTypeMatter += "\n\t}";
			criticalLayerTypeMatter += "\n\tparam{";
			criticalLayerTypeMatter += "\n\t\tlr_mult: " + text_criticalLayerBiasLr.get_text();
			criticalLayerTypeMatter += "\n\t\tdecay_mult: " + text_criticalLayerBiasDm.get_text();
			criticalLayerTypeMatter += "\n\t}";
			criticalLayerTypeMatter += "\n\tconvolution_param{";
			criticalLayerTypeMatter += "\n\t\tnum_output: " + text_criticalLayerNumOutput.get_text();
			criticalLayerTypeMatter += "\n\t\tkernel_w: " + text_criticalLayerKernelW.get_text();
			criticalLayerTypeMatter += "\n\t\tkernel_h: " + text_criticalLayerKernelH.get_text();
			criticalLayerTypeMatter += "\n\t\tstride_w: " + text_criticalLayerStrideW.get_text();
			criticalLayerTypeMatter += "\n\t\tstride_h: " + text_criticalLayerStrideH.get_text();
			criticalLayerTypeMatter += "\n\t\tpad_w: " + text_criticalLayerPadW.get_text();
			criticalLayerTypeMatter += "\n\t\tpad_h: " + text_criticalLayerPadH.get_text();
			criticalLayerTypeMatter += "\n\t\tweight_filler{";
			if(rbutton_criticalLayerWeightFillerConstant.get_active() == 1)
			{
				criticalLayerTypeMatter += "\n\t\t\ttype: \"constant\"";
				criticalLayerTypeMatter += "\n\t\t\tvalue: " + text_criticalLayerWeightFillerConstantValue.get_text();
			}
			else if(rbutton_criticalLayerWeightFillerUniform.get_active() == 1)
			{
				criticalLayerTypeMatter += "\n\t\t\ttype: \"uniform\"";
				criticalLayerTypeMatter += "\n\t\t\tmin: " + text_criticalLayerWeightFillerUniformMin.get_text();
				criticalLayerTypeMatter += "\n\t\t\tmax: " + text_criticalLayerWeightFillerUniformMax.get_text();
			}
			else if(rbutton_criticalLayerWeightGaussian.get_active() == 1)
			{
				criticalLayerTypeMatter += "\n\t\t\ttype: \"gaussian\"";
				criticalLayerTypeMatter += "\n\t\t\tmean: " + text_criticalLayerWeightFillerGaussianMean.get_text();
				criticalLayerTypeMatter += "\n\t\t\tstd: " + text_criticalLayerWeightFillerGaussianStd.get_text();
			}
			else if(rbutton_criticalLayerWeightFillerPositiveUnitBall.get_active() == 1)
			{
				criticalLayerTypeMatter += "\n\t\t\ttype: \"positive_unitball\"";
			}
			else if(rbutton_criticalLayerWeightFillerXavier.get_active() == 1)
			{
				criticalLayerTypeMatter += "\n\t\t\ttype: \"xavier\"";
				if(rbutton_criticalLayerWeightFillerXavierIn.get_active() == 1)
					criticalLayerTypeMatter += "\n\t\t\tvariance_norm: FAN_IN";
				else if(rbutton_criticalLayerWeightFillerXavierOut.get_active() == 1)
					criticalLayerTypeMatter += "\n\t\t\tvariance_norm: FAN_OUT";
				else if(rbutton_criticalLayerWeightFillerXavierAvg.get_active() == 1)
					criticalLayerTypeMatter += "\n\t\t\tvariance_norm: AVERAGE";
			}
			else if(rbutton_criticalLayerWeightFillerMSRA.get_active() == 1)
			{
				criticalLayerTypeMatter += "\n\t\t\ttype: \"msra\"";
				if(rbutton_criticalLayerWeightFillerMSRAIn.get_active() == 1)
					criticalLayerTypeMatter += "\n\t\t\tvariance_norm: FAN_IN";
				else if(rbutton_criticalLayerWeightFillerMSRAOut.get_active() == 1)
					criticalLayerTypeMatter += "\n\t\t\tvariance_norm: FAN_OUT";
				else if(rbutton_criticalLayerWeightFillerMSRAAvg.get_active() == 1)
					criticalLayerTypeMatter += "\n\t\t\tvariance_norm: AVERAGE";
			}
			else if(rbutton_criticalLayerWeightFillerBilinear.get_active() == 1)
			{
				criticalLayerTypeMatter += "\n\t\t\ttype: \"bilinear\"";
			}
			criticalLayerTypeMatter += "\n\t\t}";
			criticalLayerTypeMatter += "\n\t\tbias_filler{";
			criticalLayerTypeMatter += "\n\t\t\ttype: \"constant\"";    //only type of filler as of now
			criticalLayerTypeMatter += "\n\t\t\tvalue: " + text_criticalLayerBias.get_text();
			criticalLayerTypeMatter += "\n\t\t}";
			criticalLayerTypeMatter += "\n\t}";
			criticalLayerTypeMatter += "\n}\n";	
				 
		}
		else if(criticalLayerTypeData == "Dropout")
		{
			criticalLayerTypeMatter = "layer{";
			criticalLayerTypeMatter += "\n\tbottom: \"" +  text_criticalLayerBottom1.get_text() + "\"";
			criticalLayerTypeMatter += "\n\ttop: \"" + text_criticalLayerTop.get_text() + "\"";
			criticalLayerTypeMatter += "\n\tname: \"" + text_criticalLayerName.get_text() + "\"";
			criticalLayerTypeMatter += "\n\ttype: \"" + criticalLayerTypeData + "\"";
			criticalLayerTypeMatter += "\n\tdropout_param{";
			criticalLayerTypeMatter += "\n\t\tdropout_ratio: " + text_criticalLayerDropoutRatio.get_text();
			criticalLayerTypeMatter += "\n\t}";
			criticalLayerTypeMatter += "\n}\n";
		}
		else if(criticalLayerTypeData == "InnerProduct")
		{
			criticalLayerTypeMatter = "layer{";
			criticalLayerTypeMatter += "\n\tbottom: \"" +  text_criticalLayerBottom1.get_text() + "\"";
			criticalLayerTypeMatter += "\n\ttop: \"" + text_criticalLayerTop.get_text() + "\"";
			criticalLayerTypeMatter += "\n\tname: \"" + text_criticalLayerName.get_text() + "\"";
			criticalLayerTypeMatter += "\n\ttype: \"" + criticalLayerTypeData + "\"";
			criticalLayerTypeMatter += "\n\tparam{";
			criticalLayerTypeMatter += "\n\t\tlr_mult: " + text_criticalLayerFilterLr.get_text();
			criticalLayerTypeMatter += "\n\t\tdecay_mult: " + text_criticalLayerFilterDm.get_text();
			criticalLayerTypeMatter += "\n\t}";
			criticalLayerTypeMatter += "\n\tparam{";
			criticalLayerTypeMatter += "\n\t\tlr_mult: " + text_criticalLayerBiasLr.get_text();
			criticalLayerTypeMatter += "\n\t\tdecay_mult: " + text_criticalLayerBiasDm.get_text();
			criticalLayerTypeMatter += "\n\t}";
			criticalLayerTypeMatter += "\n\tinner_product_param{";
			criticalLayerTypeMatter += "\n\t\tnum_output: " + text_criticalLayerNumOutput.get_text();
			criticalLayerTypeMatter += "\n\t\tweight_filler{";
			if(rbutton_criticalLayerWeightFillerConstant.get_active() == 1)
			{
				criticalLayerTypeMatter += "\n\t\t\ttype: \"constant\"";
				criticalLayerTypeMatter += "\n\t\t\tvalue: " + text_criticalLayerWeightFillerConstantValue.get_text();
			}
			else if(rbutton_criticalLayerWeightFillerUniform.get_active() == 1)
			{
				criticalLayerTypeMatter += "\n\t\t\ttype: \"uniform\"";
				criticalLayerTypeMatter += "\n\t\t\tmin: " + text_criticalLayerWeightFillerUniformMin.get_text();
				criticalLayerTypeMatter += "\n\t\t\tmax: " + text_criticalLayerWeightFillerUniformMax.get_text();
			}
			else if(rbutton_criticalLayerWeightGaussian.get_active() == 1)
			{
				criticalLayerTypeMatter += "\n\t\t\ttype: \"gaussian\"";
				criticalLayerTypeMatter += "\n\t\t\tmean: " + text_criticalLayerWeightFillerGaussianMean.get_text();
				criticalLayerTypeMatter += "\n\t\t\tstd: " + text_criticalLayerWeightFillerGaussianStd.get_text();
			}
			else if(rbutton_criticalLayerWeightFillerPositiveUnitBall.get_active() == 1)
			{
				criticalLayerTypeMatter += "\n\t\t\ttype: \"positive_unitball\"";
			}
			else if(rbutton_criticalLayerWeightFillerXavier.get_active() == 1)
			{
				criticalLayerTypeMatter += "\n\t\t\ttype: \"xavier\"";
				if(rbutton_criticalLayerWeightFillerXavierIn.get_active() == 1)
					criticalLayerTypeMatter += "\n\t\t\tvariance_norm: FAN_IN";
				else if(rbutton_criticalLayerWeightFillerXavierOut.get_active() == 1)
					criticalLayerTypeMatter += "\n\t\t\tvariance_norm: FAN_OUT";
				else if(rbutton_criticalLayerWeightFillerXavierAvg.get_active() == 1)
					criticalLayerTypeMatter += "\n\t\t\tvariance_norm: AVERAGE";
			}
			else if(rbutton_criticalLayerWeightFillerMSRA.get_active() == 1)
			{
				criticalLayerTypeMatter += "\n\t\t\ttype: \"msra\"";
				if(rbutton_criticalLayerWeightFillerMSRAIn.get_active() == 1)
					criticalLayerTypeMatter += "\n\t\t\tvariance_norm: FAN_IN";
				else if(rbutton_criticalLayerWeightFillerMSRAOut.get_active() == 1)
					criticalLayerTypeMatter += "\n\t\t\tvariance_norm: FAN_OUT";
				else if(rbutton_criticalLayerWeightFillerMSRAAvg.get_active() == 1)
					criticalLayerTypeMatter += "\n\t\t\tvariance_norm: AVERAGE";
			}
			else if(rbutton_criticalLayerWeightFillerBilinear.get_active() == 1)
			{
				criticalLayerTypeMatter += "\n\t\t\ttype: \"bilinear\"";
			}
			criticalLayerTypeMatter += "\n\t\t}";
			criticalLayerTypeMatter += "\n\t\tbias_filler{";
			criticalLayerTypeMatter += "\n\t\t\ttype: \"constant\"";    //only type of filler as of now
			criticalLayerTypeMatter += "\n\t\t\tvalue: " + text_criticalLayerBias.get_text();
			criticalLayerTypeMatter += "\n\t\t}";
			criticalLayerTypeMatter += "\n\t}";
			criticalLayerTypeMatter += "\n}\n";	
		}
		else if(criticalLayerTypeData == "Pooling")
		{
			criticalLayerTypeMatter = "layer{";
			criticalLayerTypeMatter += "\n\tbottom: \"" +  text_criticalLayerBottom1.get_text() + "\"";
			criticalLayerTypeMatter += "\n\ttop: \"" + text_criticalLayerTop.get_text() + "\"";
			criticalLayerTypeMatter += "\n\tname: \"" + text_criticalLayerName.get_text() + "\"";
			criticalLayerTypeMatter += "\n\ttype: \"" + criticalLayerTypeData + "\"";
			criticalLayerTypeMatter += "\n\tparam{";
			criticalLayerTypeMatter += "\n\t\tlr_mult: " + text_criticalLayerFilterLr.get_text();
			criticalLayerTypeMatter += "\n\t\tdecay_mult: " + text_criticalLayerFilterDm.get_text();
			criticalLayerTypeMatter += "\n\t}";
			criticalLayerTypeMatter += "\n\tparam{";
			criticalLayerTypeMatter += "\n\t\tlr_mult: " + text_criticalLayerBiasLr.get_text();
			criticalLayerTypeMatter += "\n\t\tdecay_mult: " + text_criticalLayerBiasDm.get_text();
			criticalLayerTypeMatter += "\n\t}";
			criticalLayerTypeMatter += "\n\tpooling_param{";
			criticalLayerTypeMatter += "\n\t\tnum_output: " + text_criticalLayerNumOutput.get_text();
			criticalLayerTypeMatter += "\n\t\tkernel_w: " + text_criticalLayerKernelW.get_text();
			criticalLayerTypeMatter += "\n\t\tkernel_h: " + text_criticalLayerKernelH.get_text();
			criticalLayerTypeMatter += "\n\t\tstride_w: " + text_criticalLayerStrideW.get_text();
			criticalLayerTypeMatter += "\n\t\tstride_h: " + text_criticalLayerStrideH.get_text();
			criticalLayerTypeMatter += "\n\t\tpad_w: " + text_criticalLayerPadW.get_text();
			criticalLayerTypeMatter += "\n\t\tpad_h: " + text_criticalLayerPadH.get_text();
			if(rbutton_criticalLayerPoolMax.get_active() == 1)
				criticalLayerTypeMatter += "\n\t\tpool: MAX";
			else if(rbutton_criticalLayerPoolAve.get_active() == 1)
				criticalLayerTypeMatter += "\n\t\tpool: AVE";
			criticalLayerTypeMatter += "\n\t}";
			criticalLayerTypeMatter += "\n}\n";
		}
		if(numLayers == 0)
		{
			initializeLayer(headLayer,criticalLayerTypeMatter);
			numLayers++;
			fullCnnLayers.push_back(criticalLayerTypeMatter);
		}
		else
		{
			appendLayer(headLayer,criticalLayerTypeMatter);
			numLayers++;
			fullCnnLayers.push_back(criticalLayerTypeMatter);
		}
	}
	else if(data == "normalizationLayerType")
	{
		showWindow_normalizationLayerType(normalizationLayerTypeData);
	}
	else if(data == "addMoreLayer3")
	{
		showWindow_main();
	}
	else if(data == "lossLayerType")
	{
		showWindow_lossLayerType(lossLayerTypeData);
	}
	else if(data == "addMoreLayer4")
	{
		showWindow_main();
	}
	else if(data == "extraLayerType")
	{
		showWindow_extraLayerType(extraLayerTypeData);
	}
	else if(data == "addMoreLayer5")
	{
		showWindow_main();
	}
	else if(data == "saveFile")
	{
		networkFileName = text_networkFileName.get_text();
		std::ofstream myfile;
		myfile.open(networkFileName);
		std::cout << "Network File Name saved as: " << networkFileName << std::endl;
		myfile << "#File generated using OpenDetection" << std::endl;
		myfile << fullCnnLayerMatter << std::endl;
		myfile.close();
	}
		
}


