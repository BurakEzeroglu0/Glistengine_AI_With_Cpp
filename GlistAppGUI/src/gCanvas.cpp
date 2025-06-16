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
	//logo.loadImage("glistengine_logo.png");
	mainframeSetup();
	menubarSetup();
	toolbarSetup();
	statusbarSetup();
	solpanelSetup();
	ortapanelSetup();
	sagpanelSetup();
}

void gCanvas::ortapanelSetup() {
	ortapanelsizer.setSize(2, 1);
	ortapanelsizer.enableBorders(true);
	ortapanel.setSizer(&ortapanelsizer);
	mainframesizer.setControl(0, 1, &ortapanel);
	ortapanelsizer.enableResizing(true);
	ortapanel.setTitle("Orta Panel");
	ortapanel.showTitle(true);
	grid.setGrid(20, 20);
	ortapanelsizer.setControl(0, 0, &grid);
	ortapanelsizer.setControl(1, 0, &linegraph);
	linegraph.addLine();
	linegraph.addPointToLine(0, 1.5f, 1.0f);
	linegraph.addPointToLine(0, 2.5f, 0.5f);
	linegraph.addPointToLine(0, 3.5f, 2.0f);

}

void gCanvas::sagpanelSetup() {
	sagpanelsizer.setSize(6, 1);
	sagpanelsizer.enableBorders(true);
	sagpanel.setSizer(&sagpanelsizer);
	mainframesizer.setControl(0, 2, &sagpanel);
	sagpanelsizer.enableResizing(true);
	sagpanel.setTitle("Sag Panel");
	sagpanel.showTitle(true);

	//gGUIBitmap* imageBitmap = new gGUIBitmap();
	sagpanelsizer.setControl(0, 0, &bitmap);
	bitmap.loadImage("/glistengine_logo.png");

}

void gCanvas::solpanelSetup() {
	solpanelsizer.setSize(6, 1);
	solpanelsizer.enableBorders(true);
	solpanel.setSizer(&solpanelsizer);
	mainframesizer.setControl(0, 0, &solpanel);
	solpanelsizer.enableResizing(true);
	solpanel.setTitle("Project Explorer");
	solpanel.showTitle(true);
	//panel button
	solpanelsizer.setControl(0, 0, &panelbutton);
	panelbutton.setTitle("button");
	yedek.set(1.0f, 0.0f, 0.0f);
	panelbutton.setButtonColor (&yedek);
	panelbutton.setPressedButtonColor(gColor::BLACK);
	solpanelsizer.setControl(1, 0, &droplist);
	element[0].title = "xyz";
	element[1].title = "xyz1";
	element[2].title = "xyz2";
	element[3].title = "xyz3";
	element[4].title = "xyz4";
	element[5].title = "xyz5";
	element[6].title = "xyz6";
	element[7].title = "xyz7";
	element[8].title = "xyz8";
	element[9].title = "xyz9";
	for (int sira = 0; sira < 10; ++sira) {
		droplist.addElement(&element[sira]);
	}
	droplist.setParentFrame(&mainframe);
	droplist.enableScrollbars(true, true);
	float satirboyutu[] = {0.1f, 0.3f, 0.2f, 0.1f, 0.1f, 0.1f
	};
	solpanelsizer.setLineProportions(satirboyutu);
	solpanelsizer.setControl(4, 0, &textbox);
	textbox.setText("text");
	solpanelsizer.setControl(2, 0, &listbox);
	listbox.addData("ekle");
	listbox.addData("ekle1");
	listbox.addData("ekle2");
	listbox.addData("ekle3");
	listbox.addData("ekle4");
	listbox.addData("ekle5");
	listbox.addData("ekle6");
	listbox.addData("ekle7");
	listbox.addData("ekle8");
	listbox.enableScrollbars(true, true);
}

void gCanvas::update() {
}

void gCanvas::draw() {
	logo.draw((getWidth() - logo.getWidth()) / 2, (getHeight() - logo.getHeight()) / 2);
}

void gCanvas::keyPressed(int key) {
	//gLogi("gCanvas") << "keyPressed:" << key;  downvote 264
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

void gCanvas::mainframeSetup() {
	//olustudugumuz frame'i kullanacak
	root->getAppManager()->getGUIManager()->setCurrentFrame(&mainframe);
	//main framein ayar dosyası
	mainframesizer.setSize(1, 3);
	mainframe.setSizer(&mainframesizer);
	mainframesizer.enableBorders(true);
	//sutunlara manual boyut
	float sutunboyutu[] = {
			0.2f, 0.6f, 0.2f
	};
	mainframesizer.setColumnProportions(sutunboyutu);
	mainframesizer.enableResizing(true);

	//root->getAppManager()->getGUIManager()->setTheme(gGUIManager::GUITHEME_MODERN);
}

void gCanvas::menubarSetup() {
	//menubari mainframe entegre ettik
	mainframe.setMenuBar(&menubar);
	//menu items
	menubar.addChild("file");
	menubar.addChild("edit");

	//file members
	gGUIMenuItem* fileitem = menubar.getChild(FILE);
	fileitem->addChild("new");
	fileitem->addChild("open");
	fileitem->addChild("exit");

	//edit members
	gGUIMenuItem* edititem = menubar.getChild(EDIT);
	edititem->addChild("cut");
	edititem->addChild("copy");
	edititem->addChild("paste");

}

void gCanvas::toolbarSetup() {
	toolbarsizer.setSize(1, 10);
	toolbarsizer.enableBorders(true);
	toolbar.setSizer(&toolbarsizer);
	mainframe.addToolBar(&toolbar);
	toolbarsizer.setRootApp(root);

	float sutunboyutu[] = {
			0.02f, 0.02f, 0.02f, 0.02f, 0.02f, 0.02f, 0.02f, 0.02f, 0.02f, 0.02f
	};
	toolbarsizer.setColumnProportions(sutunboyutu);

	//toolbar button
	tb1.setImage(gGUIResources::ICON_FILE);
	toolbarsizer.setControl(0, 0, &tb1);
	tb2.setImage(gGUIResources::ICON_FOLDER);
	toolbarsizer.setControl(0, 1, &tb2);
	tb3.setImage(gGUIResources::ICON_HELP);
	toolbarsizer.setControl(0, 2, &tb3);

	tb1.setButtonColor(gColor(165, 140, 90));
	tb2.setButtonColor(gColor(165, 140, 90));
	tb3.setButtonColor(gColor(165, 140, 90));
}

void gCanvas::statusbarSetup() {
	mainframe.setStatusBar(&statusbar);
	statusbar.setText(0, "deneme2");
}

void gCanvas::onGuiEvent(int guiObjectId, int eventType, std::string value1, std::string value2) {
	if(guiObjectId == panelbutton.getId() && eventType == G_GUIEVENT_BUTTONRELEASED) {
		//gLogi("event") << eventType;
		exit(0);
	}
}
