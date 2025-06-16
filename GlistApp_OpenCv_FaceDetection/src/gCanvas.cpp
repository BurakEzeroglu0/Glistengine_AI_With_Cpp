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
	// logo.loadImage("glistengine_logo.png");
/*
	familyimage.loadImage("family03.jpg");
	rects = cv.objectDetection(&familyimage, gGetFilesDir() + "haarcascade_frontalcatface.xml");
*/

	root->getAppManager()->getGUIManager()->setCurrentFrame(&mainframe);
	mainframe.setSizer(&mainsizer);
	mainsizer.setSize(2, 1);
	float lineprs[2] = {0.9f, 0.1f};
	mainsizer.setLineProportions(lineprs);
	mainsizer.enableBorders(true);

	mainsizer.setControl(1, 0, &bottompanel);
	bottompanel.setSizer(&bottomsizer);
	bottomsizer.setSize(1, 4);
	float colprs[4] = {0.01f, 0.81f, 0.09f, 0.09f};
	bottomsizer.setColumnProportions(colprs);
	bottomsizer.enableBorders(true);
	bottomsizer.setControl(0, 1, &bottomtextbox);
	bottomsizer.setControl(0, 2, &browsebutton);
	bottomsizer.setControl(0, 3, &detectbutton);
	bottompanel.setTitle("Select Image");
	browsebutton.setTitle("Browse");
	detectbutton.setTitle("Detect");
	bottomtextbox.setText(gGetImagesDir());

	mainsizer.setControl(0, 0, &toppanel);
	toppanel.setSizer(&topsizer);
	topsizer.setSize(1, 1);
	topsizer.setControl(0, 0, &topsurface);
	toppanel.setTitle("Face Detection");

}

void gCanvas::onGuiEvent(int guiObjectId, int eventType, std::string value1, std::string value2 ){
	if(guiObjectId == browsebutton.getId() && eventType == G_GUIEVENT_BUTTONRELEASED){
		std::string path = bottomtextbox.getText();
		if(path == "") return;

		filterpatterns[0] = "*.jpg";
		filterpatterns[1] = "*.png";
		std::string imagepath = gShowOpenFileDialog("Select Image", gGetImagesDir() , patternnum, filterpatterns, "image files", false);
		bottomtextbox.setText(imagepath);
		topsurface.clear();
		image.load(imagepath);
		topsurface.addImage(0, 0, image.getWidth(), image.getHeight(), &image);

	} else if(guiObjectId == detectbutton.getId() && eventType == G_GUIEVENT_BUTTONRELEASED) {
		rects = cv.objectDetection(&image, gGetFilesDir() + "haarcascade_frontalcatface.xml");
		for(int i = 0; i < rects.size(); i++){
			topsurface.addRectangle(rects[i].x, rects[i].y, rects[i].width, rects[i].height, false, gColor(1.0f, 1.0f, 0.0f));
		}
	}
}

void gCanvas::update() {
}

void gCanvas::draw() {
/*
	setColor(255, 255, 255);
	logo.draw((getWidth() - logo.getWidth()) / 2, (getHeight() - logo.getHeight()) / 2);

	familyimage.draw(0, 0);  // Ekranda yazýlýcak kordinatlar
	setColor(255, 255, 0);
	for(int i = 0; i < rects.size(); i++){
		gDrawRectangle(rects[i].x, rects[i].y, rects[i].width, rects[i].height, false);
	}
*/
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

