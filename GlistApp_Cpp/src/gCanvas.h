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
#include "veriAnalizi.h"


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

private:
	gApp* root;
	gImage logo;
	void logaMerhabaYazdir();
	void logaYazdir(std::string mesaj);
	void logaYazdir(std::string etiket, std::string mesaj);
	int toplamiHesapla(int rakam1, int rakam2);
	veriAnalizi va;
	void pointers();
	//27-11-2024
	int topla(int sayi1, int sayi2);
	float topla(float sayi1, float sayi2);
	float topla(int sayi1, float sayi2 = 10);   //göndermen gerek ama göndermezsen ben 10 kabul edicem demek istiyor.
	float ortalama(float sayi1, float sayi2);
	void programiKapat(int x, int y);
	gImage resim1[4];
	int hangiresim;
};

#endif /* GCANVAS_H_ */
