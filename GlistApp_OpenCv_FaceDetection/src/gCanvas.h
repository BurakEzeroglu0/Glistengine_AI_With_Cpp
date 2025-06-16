 /*
 * gCanvas.h
 *
 *  Created on: May 6, 2020
 *      Author: noyan
 */

#ifndef GCANVAS_H_
#define GCANVAS_H_

#include "gBaseCanvas.h"
#include "gApp.h"
#include "gImage.h"
#include "gipOpenCV.h"
#include "gGUIFrame.h"
#include "gGUISizer.h"
#include "gGUIPanel.h"
#include "gGUITextbox.h"
#include "gGUIButton.h"
#include "gGUISurface.h"


class gCanvas : public gBaseCanvas {
public:
	gCanvas(gApp* root);
	virtual ~gCanvas();

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void charPressed(unsigned int codepoint);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseScrolled(int x, int y);
	void mouseEntered();
	void mouseExited();
	void windowResized(int w, int h);
	void onGuiEvent(int guiObjectId, int eventType, std::string value1 = "", std::string value2 = "");

	void showNotify();
	void hideNotify();

private:
	gApp* root;
	gImage logo;
	gipOpenCV cv;
	gImage familyimage;
	std::vector<cv::Rect> rects;  // rectangle

	gGUIFrame mainframe;
	gGUISizer mainsizer;

	gGUIPanel bottompanel;
	gGUISizer bottomsizer;
	gGUITextbox bottomtextbox;
	gGUIButton browsebutton;
	gGUIButton detectbutton;

	gGUIPanel toppanel;
	gGUISizer topsizer;
	gGUISurface topsurface;

	static const int patternnum = 2;
	std::string filterpatterns[patternnum];
	gImage image;


};

#endif /* GCANVAS_H_ */
