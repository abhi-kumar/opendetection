#ifndef GTKMM_EXAMPLE_NETWORK_H
#define GTKMM_EXAMPLE_NETWORK_H

#include <gtkmm/grid.h>
#include <gtkmm/entry.h>
#include <gtkmm/button.h>
#include <gtkmm/radiobutton.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/window.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/application.h>
#include <gtkmm/comboboxtext.h>
#include <gtkmm/liststore.h>
#include <gtkmm/textview.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>



class NetworkCreator : public Gtk::Window
{
	public:
		NetworkCreator();
		virtual ~NetworkCreator();
		

	protected:
		void on_button_clicked(Glib::ustring data);
		void on_combo_changed();
		void on_cell_data_extra(const Gtk::TreeModel::const_iterator& iter);
		void showWindow_main();
		void showWindow_activationLayerType(Glib::ustring data);
		void showWindow_displayWindow();
		void showWindow_criticalLayerType(Glib::ustring data);
		void showWindow_normalizationLayerType(Glib::ustring data);
		void showWindow_lossLayerType(Glib::ustring data);
		void showWindow_extraLayerType(Glib::ustring data);

		// Child widgets:
		Gtk::Grid 		m_grid1,
					m_grid_activationLayerType,
					m_grid_criticalLayerType,
					m_grid_normalizationLayerType,
					m_grid_lossLayerType,
					m_grid_extraLayerType;
		Gtk::ScrolledWindow 	m_sw1, 
					m_sw_activationLayerType,
					m_sw_criticalLayerType,
					m_sw_fullCnnLayerMatter,
					m_sw_normalizationLayerType,
					m_sw_lossLayerType,
					m_sw_extraLayerType;
		Gtk::Button	 	button_networkFileName,
					button_activationLayerType,
					button_addMoreLayer,
					button_setActivationParameters,
					button_displayCnnLayers,
					button_editMore,
					button_deleteLayerAtEnd,
					button_criticalLayerType,
					button_setCriticalParameters,
					button_addMoreLayer2,
					button_normalizationLayerType,
					button_lossLayerType,
					button_extraLayerType,
					button_addMoreLayer3,
					button_setNormalizationParameters,
					button_addMoreLayer4,
					button_setLossParameters,
					button_addMoreLayer5,
					button_setExtraParameters,
					button_deleteSelectedLayer,
					button_appendLayerAfter,
					button_saveFile;
		Gtk::Entry 		text_networkFileName,
					text_activationLayerTop,
					text_activationLayerBottom,
					text_activationLayerName,
					text_activationLayerType,
					text_activationLayerScale,
					text_activationLayerShift,
					text_activationLayerBase,
					text_activationLayerNegativeSlope,
					text_criticalLayerTop,
					text_criticalLayerBottom1,
					text_criticalLayerBottom2,
					text_criticalLayerName,
					text_criticalLayerFilterLr,
					text_criticalLayerFilterDm,
					text_criticalLayerBiasLr,
					text_criticalLayerBiasDm,
					text_criticalLayerNumOutput,
					text_criticalLayerKernelW,
					text_criticalLayerKernelH,
					text_criticalLayerStrideW,
					text_criticalLayerStrideH,
					text_criticalLayerPadW,
					text_criticalLayerPadH,
					text_criticalLayerWeightFillerConstantValue,
					text_criticalLayerWeightFillerUniformMin,
					text_criticalLayerWeightFillerUniformMax,
					text_criticalLayerWeightFillerGaussianMean,
					text_criticalLayerWeightFillerGaussianStd,
					text_criticalLayerDropoutRatio,
					text_criticalLayerBias,
					text_normalizationLayerTop,
					text_normalizationLayerBottom,
					text_normalizationLayerName,
					text_normalizationLayerlocalSize,
					text_normalizationLayerAlpha,
					text_normalizationLayerBeta,
					text_normalizationLayerK,
					text_normalizationLayerAcrossChannel,
					text_normalizationLayerNormalizeVariance,
					text_normalizationLayerEps,
					text_lossLayerTop,
					text_lossLayerBottom1,
					text_lossLayerBottom2,
					text_lossLayerBottom3,
					text_lossLayerName,
					text_lossLayerNormalize,
					text_extraLayerTop1,
					text_extraLayerTop2,
					text_extraLayerBottom1,
					text_extraLayerBottom2,
					text_extraLayerName,
					text_extraLayerTopK,
					text_extraLayerScale,
					text_extraLayerNewHeight,
					text_extraLayerNewWidth,
					text_extraLayerCropSize,
					text_extraLayerMeanFile,
					text_extraLayerSource,
					text_extraLayerBatchSize;
		Gtk::Label 		label_networkFileName,
					label_activationLayerType,
					label_criticalLayerType,
					label_normalizationLayerType,
					label_lossLayerType,
					label_extraLayerType,
					title_activationLayerType,
					label_activationLayerTop,
					label_activationLayerBottom,
					label_activationLayerName,
					label_activationLayerScale,
					label_activationLayerShift,
					label_activationLayerBase,
					label_activationLayerNegativeSlope,
					title_criticalLayerType,
					label_criticalLayerTop,
					label_criticalLayerBottom1,
					label_criticalLayerBottom2,
					label_criticalLayerName,
					label_criticalLayerFilterLr,
					label_criticalLayerFilterDm,
					label_criticalLayerBiasLr,
					label_criticalLayerBiasDm,
					label_criticalLayerNumOutput,
					label_criticalLayerKernelW,
					label_criticalLayerKernelH,
					label_criticalLayerStrideW,
					label_criticalLayerStrideH,
					label_criticalLayerPadW,
					label_criticalLayerPadH,
					label_criticalLayerWeightFiller,
					label_criticalLayerWeightFillerConstantValue,
					label_criticalLayerWeightFillerUniformMin,
					label_criticalLayerWeightFillerUniformMax,
					label_criticalLayerWeightFillerGaussianMean,
					label_criticalLayerWeightFillerGaussianStd,
					label_criticalLayerWeightFillerXavierVariance,
					label_criticalLayerWeightFillerMSRAVariance,
					label_criticalLayerDropoutRatio,
					label_criticalLayerPool,
					label_criticalLayerBias,
					title_normalizationLayerType,
					label_normalizationLayerTop,
					label_normalizationLayerBottom,
					label_normalizationLayerName,
					label_normalizationLayerlocalSize,
					label_normalizationLayerAlpha,
					label_normalizationLayerBeta,
					label_normalizationLayerK,
					label_normalizationLayerNormRegion,
					label_normalizationLayerAcrossChannel,
					label_normalizationLayerNormalizeVariance,
					label_normalizationLayerEps, 
					title_lossLayerType,
					title_extraLayerType,
					label_lossLayerTop,
					label_lossLayerBottom1,
					label_lossLayerBottom2,
					label_lossLayerBottom3,
					label_lossLayerName,
					label_lossLayerNormalize,
					label_lossLayerNormalization,
					label_lossLayerNorm,
					label_extraLayerTop1,
					label_extraLayerTop2,
					label_extraLayerBottom1,
					label_extraLayerBottom2,
					label_extraLayerName,
					label_extraLayerTopK,
					label_extraLayerOutMaxVal,
					label_extraLayerPhase,
					label_extraLayerScale,
					label_extraLayerNewHeight,
					label_extraLayerNewWidth,
					label_extraLayerCropSize,
					label_extraLayerMeanFile,
					label_extraLayerSource,
					label_extraLayerBatchSize,
					label_extraLayerBackend;
		Gtk::ComboBox 		combo_activationLayerType,
					combo_criticalLayerType,
					combo_normalizationLayerType,
					combo_lossLayerType,
					combo_extraLayerType,
					combo_currentLayers;
		Gtk::TextView 		textView_fullCnnLayerMatter;
		Glib::RefPtr<Gtk::TextBuffer> buffer_fullCnnLayerMatter;
		Gtk::Box 		box_fullCnnLayerMatter;
		Gtk::ButtonBox 		buttonBox_fullCnnLayerMatter;
		Gtk::RadioButton	rbutton_criticalLayerWeightFillerConstant, rbutton_criticalLayerWeightFillerUniform,
					rbutton_criticalLayerWeightGaussian, rbutton_criticalLayerWeightFillerPositiveUnitBall,
					rbutton_criticalLayerWeightFillerXavier, rbutton_criticalLayerWeightFillerMSRA,
					rbutton_criticalLayerWeightFillerBilinear,
					rbutton_criticalLayerWeightFillerXavierIn, rbutton_criticalLayerWeightFillerXavierOut,
					rbutton_criticalLayerWeightFillerXavierAvg,	
					rbutton_criticalLayerWeightFillerMSRAIn, rbutton_criticalLayerWeightFillerMSRAOut,
					rbutton_criticalLayerWeightFillerMSRAAvg,
					rbutton_criticalLayerPoolMax, rbutton_criticalLayerPoolAve,
					rbutton_normalizationLayerLRNWithin, rbutton_normalizationLayerLRNAcross,
					rbutton_lossLayerFull, rbutton_lossLayerValid, rbutton_lossLayerBatch,
					rbutton_lossLayerL1, rbutton_lossLayerL2,
					rbutton_extraLayerOutMaxValTrue, rbutton_extraLayerOutMaxValFalse,
					rbutton_extraLayerTrain, rbutton_extraLayerTest,
					rbutton_extraLayerScaleYes, rbutton_extraLayerScaleNo,
					rbutton_extraLayerNewHeightYes, rbutton_extraLayerNewHeightNo,
					rbutton_extraLayerNewWidthYes, rbutton_extraLayerNewWidthNo,
					rbutton_extraLayerCropSizeYes, rbutton_extraLayerCropSizeNo,
					rbutton_extraLayerMeanFileYes, rbutton_extraLayerMeanFileNo,
					rbutton_extraLayerLMDB, rbutton_extraLayerLEVELDB;
					


		//Tree model columns:
		class ModelColumns : public Gtk::TreeModel::ColumnRecord
		{
			public:
				ModelColumns(){ add(m_col_id); add(m_col_name); add(m_col_extra);}
				Gtk::TreeModelColumn<int> m_col_id;
				Gtk::TreeModelColumn<Glib::ustring> m_col_name;
				Gtk::TreeModelColumn<Glib::ustring> m_col_extra;
		};

		ModelColumns 			column_activationLayerType,
						column_criticalLayerType,
						column_normalizationLayerType,
						column_lossLayerType,
						column_extraLayerType,
						column_currentLayers;
		Gtk::CellRendererText		cell_activationLayerType,
						cell_criticalLayerType,
						cell_normalizationLayerType,
						cell_lossLayerType,
						cell_extraLayerType,
						cell_currentLayers;
		Glib::RefPtr<Gtk::ListStore> 	ref_activationLayerType,
						ref_criticalLayerType,
						ref_normalizationLayerType,
						ref_lossLayerType,
						ref_extraLayerType,
						ref_currentLayers;


	private:
		Glib::ustring 		networkFileName;
		Glib::ustring		activationLayerTypeData, activationLayerTypeMatter;
		Glib::ustring		criticalLayerTypeData, criticalLayerTypeMatter;
		Glib::ustring		normalizationLayerTypeData, normalizationLayerTypeMatter;
		Glib::ustring		lossLayerTypeData, lossLayerTypeMatter;
		Glib::ustring		extraLayerTypeData, extraLayerTypeMatter;
		int 			numLayers;
		Glib::ustring		fullCnnLayerMatter;
		std::vector<Glib::ustring>	fullCnnLayers;
		std::vector<Glib::ustring>	fullCnnLayersName;
		Glib::ustring		currentLayersName;
		bool			appendStatus;

};


#endif // GTKMM_EXAMPLE_NETWORK_H		
