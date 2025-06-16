/*
* gCanvas.cpp
*
*  Created on: May 6, 2020
*      Author: noyan
*/


#include "gCanvas.h"


gCanvas::gCanvas(gApp* root) : gBaseCanvas(root) {
	this->root = root;
}

gCanvas::~gCanvas() {
}

void gCanvas::setup() {
	logo.loadImage("glistengine_logo.png");

	ai.loadDatasetFile("airfoil_self_noise.csv", ';',true);
	Tensor<std::string, 1> scaling_inputs_method(ai.getDataset()->get_input_columns_number());
	Tensor<std::string, 1> scaling_targets_method(ai.getDataset()->get_target_columns_number());
	scaling_inputs_method.setConstant("MeanStandardDeviation");
	scaling_targets_method.setConstant("MeanStandardDeviation");
	Tensor<gipOpenNN::Descriptives, 1> input_descriptives = ai.getDataset()->scale_input_variables(scaling_inputs_method);
	Tensor<gipOpenNN::Descriptives, 1> target_descriptives = ai.getDataset()->scale_target_variables(scaling_targets_method);

	ai.createNeuralNetwork(gipOpenNN::NeuralNetwork::ProjectType::Approximation, std::vector<int>{12, 12});
	gLogi("gCanvas") << "Layers:" << ai.getNeuralNetwork()->get_layers_names();
	gLogi("gCanvas") << "Neuron nums:" << ai.getNeuralNetwork()->get_layers_neurons_numbers();
	//gLogi("gCanvas") << "Neuron num0:" << ai.getNeuralNetwork()->get_scaling_layer_pointer()->get_neurons_number();
	ai.getNeuralNetwork()->get_scaling_layer_pointer()->set_descriptives(input_descriptives);
	ai.getNeuralNetwork()->get_unscaling_layer_pointer()->set_descriptives(target_descriptives);
	ai.getNeuralNetwork()->get_scaling_layer_pointer()->set_scaling_methods(scaling_inputs_method);
	ai.getNeuralNetwork()->get_unscaling_layer_pointer()->set_unscaling_methods(scaling_targets_method);

	ai.getTrainingStrategy()->set_optimization_method(gipOpenNN::TrainingStrategy::OptimizationMethod::CONJUGATE_GRADIENT);
	ai.getTrainingStrategy()->set_maximum_epochs_number(10000);
	ai.performTraining();

	Tensor<float, 2> inputs(2, 5);
	inputs.setValues({{6300, 15.6, 0.1016, 39.6, 0.0528487}, {1000, 4, 0.2286, 39.6, 0.00473801}});
	Tensor<float, 2> outputs = ai.calculateOutputs(inputs);
	gLogi("gCanvas") << "outputs: " << outputs;
	// sampleno:336, 1503
	// Orijinal: 104.204, 129.969
	// 124.637, 124.637
	// QN, 12: 105.115, 128.916
	// QN, 24: 105.373, 128.978
	// QN, 12-12: 105.087, 129.928
	// CG, 12-12: 104.755, 130.137
}

void gCanvas::update() {
}

void gCanvas::draw() {
	logo.draw((getWidth() - logo.getWidth()) / 2, (getHeight() - logo.getHeight()) / 2);
}

void gCanvas::keyPressed(int key) {
//	gLogi("gCanvas") << "keyPressed:" << key;
}

void gCanvas::keyReleased(int key) {
//	gLogi("gCanvas") << "keyReleased:" << key;
}

void gCanvas::charPressed(unsigned int codepoint) {
//	gLogi("gCanvas") << "charPressed:" << gCodepointToStr(codepoint);
}

void gCanvas::mouseMoved(int x, int y) {
//	gLogi("gCanvas") << "mouseMoved" << ", x:" << x << ", y:" << y;
}

void gCanvas::mouseDragged(int x, int y, int button) {
//	gLogi("gCanvas") << "mouseDragged" << ", x:" << x << ", y:" << y << ", b:" << button;
}

void gCanvas::mousePressed(int x, int y, int button) {
//	gLogi("gCanvas") << "mousePressed" << ", x:" << x << ", y:" << y << ", b:" << button;
}

void gCanvas::mouseReleased(int x, int y, int button) {
//	gLogi("gCanvas") << "mouseReleased" << ", button:" << button;
}

void gCanvas::mouseScrolled(int x, int y) {
//	gLogi("gCanvas") << "mouseScrolled" << ", x:" << x << ", y:" << y;
}

void gCanvas::mouseEntered() {

}

void gCanvas::mouseExited() {

}

void gCanvas::windowResized(int w, int h) {

}

void gCanvas::showNotify() {

}

void gCanvas::hideNotify() {

}

