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
#include "gGUIFrame.h"
#include "gGUISizer.h"
#include "gGUIMenubar.h"
#include "gGUIToolbar.h"
#include "gGUIToolbarButton.h"
#include "gGUIStatusBar.h"
#include "gGUIPanel.h"
#include "gGUIButton.h"
#include "gGUIDropdownList.h"
#include "gGUIGrid.h"
#include "gGUILineGraph.h"
#include "gGUITextbox.h"
#include "gGUIListbox.h"
#include "gGUIBitmap.h"

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

	void showNotify();
	void hideNotify();

	void onGuiEvent(int guiObjectId, int eventType, std::string value1 = "", std::string value2 = "");


private:
	gApp* root;
	gImage logo;
	//mainframe
	gGUIFrame mainframe;
	gGUISizer mainframesizer;
	void mainframeSetup();

	//menubar
	static const int FILE = 0, EDIT = 1;
	gGUIMenubar menubar;
	void menubarSetup();

	//toolbar
	gGUIToolbar toolbar;
	void toolbarSetup();

	//sizer
	gGUISizer toolbarsizer;
	gGUIToolbarButton tb1;
	gGUIToolbarButton tb2;
	gGUIToolbarButton tb3;

	//statbar
	gGUIStatusBar statusbar;
	void statusbarSetup();

	//sol panel
	gGUIPanel solpanel;
	gGUISizer solpanelsizer;
	void solpanelSetup();

	//orta panel
	gGUIPanel ortapanel;
	gGUISizer ortapanelsizer;
	void ortapanelSetup();

	//sag panel
	gGUIPanel sagpanel;
	gGUISizer sagpanelsizer;
	void sagpanelSetup();

	gGUIButton panelbutton;
	gColor yedek;
	gGUIDropdownList droplist;
	gGUITreelist::Element element[10];

	gGUIGrid grid;
	gGUILineGraph linegraph;
	gGUITextbox textbox;
	gGUIListbox listbox;
	gGUIBitmap bitmap;


};

#endif /* GCANVAS_H_ */
