#ifndef GTKMM_EXAMPLE_SOLVER_H
#define GTKMM_EXAMPLE_SOLVER_H

#include <gtkmm/grid.h>
#include <gtkmm/entry.h>
#include <gtkmm/button.h>
#include <gtkmm/radiobutton.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/window.h>
#include <gtkmm/scrolledwindow.h>

class SolverProperties : public Gtk::Window
{
	public:
		SolverProperties();
		virtual ~SolverProperties();
		Glib::ustring solverFileName;

	protected:
		void on_button_clicked(Glib::ustring data);

		// Child widgets:
		Gtk::Grid m_grid1;
		Gtk::ScrolledWindow m_sw1;
		Gtk::Button	 	button_solverFileName, 
					button_trainNetworkFileName,	
					button_testNetworkFileName,
					button_testIter,
					button_testInterval,
					button_averageLoss,
					button_randomSample,
					button_display,		
					button_snapshot,
					button_debugInfo,
					button_testComputeLoss,
					button_snapshotPrefix,
					button_maxIter,
					button_type,
					button_learningRatePolicy,
					button_baseLearningRate,
					button_gamma,
					button_power,
					button_stepSize,
					button_stepSizeValue,
					button_weightDecay,
					button_momentum,
					button_saveFile;
		Gtk::Entry 		text_solverFileName,
					text_trainNetworkFileName,
					text_testNetworkFileName,
					text_testIter,
					text_testInterval,
					text_averageLoss,
					text_randomSample,
					text_display,
					text_snapshot,
					text_snapshotPrefix,
					text_maxIter,
					text_learningRatePolicy,
					text_baseLearningRate,
					text_gamma,
					text_power,
					text_stepSize,
					text_stepSizeValue,
					text_weightDecay,
					text_momentum;
		Gtk::Label 		label_solverFileName,
					label_trainNetworkFileType,
					label_trainNetworkFileName,
					label_enableTestNet,
					label_testNetworkFileName,
					label_enableValidationParameters,
					label_testIter,
					label_testInterval,
					label_enableAverageLoss,
					label_averageLoss,
					label_enableRandomSample,
					label_randomSample,
					label_display,
					label_enableDebugInfo,
					label_snapshot,
					label_enableTestComputeLoss,
					label_snapshotPrefix,
					label_maxIter,
					label_type,
					label_learningRatePolicy,
					label_baseLearningRate,
					label_gamma,
					label_power,
					label_stepSize,
					label_stepSizeValue,
					label_weightDecay,
					label_momentum;
		Gtk::RadioButton	rbutton_trainNetworkFileType_net, rbutton_trainNetworkFileType_tt,
					rbutton_enableTestNet_no, rbutton_enableTestNet_yes,
					rbutton_enableValidationParameters_no, rbutton_enableValidationParameters_yes,
					rbutton_enableAverageLoss_no, rbutton_enableAverageLoss_yes,
					rbutton_enableRandomSample_no, rbutton_enableRandomSample_yes,
					rbutton_enableDebugInfo_no, rbutton_enableDebugInfo_yes,
					rbutton_enableTestComputeLoss_no, rbutton_enableTestComputeLoss_yes,
					rbutton_typeSGD_yes, rbutton_typeAdadelta_yes, rbutton_typeAdagrad_yes, rbutton_typeAdam_yes,
					rbutton_typeRMSProp_yes, rbutton_typeNesterov_yes,
					rbutton_learningRatePolicyFixed_yes, rbutton_learningRatePolicyExp_yes,
					rbutton_learningRatePolicyStep_yes, rbutton_learningRatePolicyInv_yes,
					rbutton_learningRatePolicyMultistep_yes, rbutton_learningRatePolicyPoly_yes,
					rbutton_learningRatePolicySigmoid_yes;

	private:
		
		Glib::ustring trainNetworkFileName;
		Glib::ustring testNetworkFileName;
		Glib::ustring testIter;
		Glib::ustring testInterval;
		Glib::ustring averageLoss;
		Glib::ustring randomSample;
		Glib::ustring display;
		Glib::ustring debugInfo;
		Glib::ustring snapshot;
		Glib::ustring testComputeLoss;
		Glib::ustring snapshotPrefix;
		Glib::ustring maxIter;
		Glib::ustring type;
		Glib::ustring learningRatePolicy;
		Glib::ustring baseLearningRate;
		Glib::ustring gamma;
		Glib::ustring power;
		Glib::ustring stepSize;
		Glib::ustring stepSizeValue;
		Glib::ustring weightDecay;
		Glib::ustring momentum;	
};

#endif // GTKMM_EXAMPLE_SOLVER_H
