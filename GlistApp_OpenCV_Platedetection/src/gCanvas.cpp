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

	plateimage.loadImage("plate06.png");
	platerects = cv.carPlateDetection(&plateimage);

	cv.setMatData(&plateimage); // 2d tablo
	cv.setDataLanguage(gipOpenCV::LANG_ENGLISH);
	cv::Mat* croppedmat = new cv::Mat[platerects.size()];
	for(int i = 0; i < platerects.size(); i++){
		croppedmat[i] = cv.getMat()(cv::Range(platerects[i].y, platerects[i].y + platerects[i].height),
				cv::Range(platerects[i].x, platerects[i].x + platerects[i].width));
		std::string text = cv.readTextFromImage(croppedmat[i]);
		gLogi("gCanvas") << "plate: " << text;
	}
}

void gCanvas::update() {
}

void gCanvas::draw() {
	logo.draw((getWidth() - logo.getWidth()) / 2, (getHeight() - logo.getHeight()) / 2);
	plateimage.draw(0, 0);
	if(platerects.empty()) return;
	for(int i = 0; i < platerects.size(); i++){
		gDrawRectangle(platerects[i].x, platerects[i].y, platerects[i].width, platerects[i].height, false);
	}

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

