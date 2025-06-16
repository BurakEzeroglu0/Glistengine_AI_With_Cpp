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

void gCanvas::pointers() {

	hangiresim = 0;
	int sayi1 = 2;
	int sayi2 = 3.2f;
	int toplam = topla(sayi1, sayi2);
	gLogi("Toplam") << toplam;
	int toplam2 = topla(9);
	gLogi("Toplam2") << toplam2;

	for (int sira = 0; sira < 4; ++sira) {
		resim1[sira].loadImage("00" + gToStr(sira) + ".png");     // deðiþken isimlerini birbirinden ayýrdýk. [] index verdik.
	}

}

void gCanvas::setup() {
	logo.loadImage("glistengine_logo.png");

		//DEGISKEN TIPLERI
		int a = 10;                       //  int deðiþkeni.
		gLogi("gCanvas") << "a:" << a;

		float b = 3.25f;					// double deðiþkeni.
		gLogi("gCanvas") << "b:" << b;

		std::string c = "Enes";            // string deðiþkeni.
		gLogi("gCanvas") << "c:" << c;

		bool d = true;						// bool deðiþkeni.    true = 1 ,  false = 0,
		gLogi("gCanvas") << "d:" << d;

		std::string isim = "Arkil";
		std::string soyisim = "Dikicioglu";
		gLogi("gCanvas") << isim  << " " << soyisim;

		short e = 10;
		gLogi("gCanvas") << "e:" << e;
		long f = 10;
		gLogi("gCanvas") << "f:" << f;
		long long g = 10;
		gLogi("gCanvas") << "g:" << g;
		double h = 3.25;
		gLogi("gCanvas") << "h:" << h;
		char k = 'A';
		gLogi("gCanvas") << "k:" << k;
		gLogi("gCanvas") << "int size:" << sizeof(int);
		gLogi("gCanvas") << "int size:" << sizeof(float);
		gLogi("gCanvas") << "int size:" << sizeof(std::string);
		gLogi("gCanvas") << "int size:" << sizeof(bool);
		gLogi("gCanvas") << "int size:" << sizeof(short);
		gLogi("gCanvas") << "int size:" << sizeof(long);
		gLogi("gCanvas") << "int size:" << sizeof(long long);
		gLogi("gCanvas") << "int size:" << sizeof(double);
		gLogi("gCanvas") << "int size:" << sizeof(char);

		//SINIFLAR VE FONKSIYONLAR
		logaMerhabaYazdir();
		logaYazdir("Merhaba C++!");
		std::string l = "Merhaba Cpp!";
		logaYazdir(l);
		logaYazdir("Uyari", "Bilgisayar kapanacak!");
		int m = toplamiHesapla(4, 7);
		gLogi("gCanvas") << "m:" << m;
		gLogi("gCanvas") << "3 + 5 = " << toplamiHesapla(3, 5);
		int n = va.toplamiHesapla(5, 8);
		gLogi("gCanvas") << "n:" << n;
		gLogi("gCanvas") << "3 + 5 = " << va.toplamiHesapla(3, 5);
		int o = va.carpimiHesapla(5, 7);
		gLogi("gCanvas") << "o:" << o;
		int p = va.karesiniHesapla(5);
		gLogi("gCanvas") << "p:" << p;
		float q = va.karekokunuHesapla(11);
		gLogi("gCanvas") << "q:" << q;
		int x = va.farkiniHesapla(9, 19);
		gLogi("gCanvas") << "x:" << x;

		//POÝNTERLER

		int s = 10;
		gLogi("gCanvas") << "s adres:" << &s;   // deðiþkenin ram de kaydedildiði yerin adresi.
		//Adreslerin yerini kaydeden deðiþkenin adý pointer dir.
		int* sptr = &s;   //sptr uyduruk bir isim biz koyduk.
		//pointer tipinden dðiþken orijinal kýsma "*" konur.
		gLogi("gCanvas") << "sprt: " << sptr;
		//pointer den kayýtlý adresi alma nasýl yapýlýr?
		int t = *sptr;  //Kayýtlý adres alma.
		gLogi("gCanvas") << "t: " << t;
		*sptr = 15;   // sptr de kayýtlý deðeri deðiþtirdik.
		gLogi("gCanvas") << "s: " << s;
		std::string v = va.cumleyiOlustur("Burak", 25);
		gLogi("gCanvas") << "v: " << v;
		int w = 15;
		int y = 17;
		int z = va.toplamiHesapla(&w, &y);
		gLogi("gCanvas") << "z: " << z;
		std::string aa = "Noyan";
		std::string ab = "Culum";
		std::string ac = va.tamIsmiOlustur(&aa, &ab);
		gLogi("gCanvas") << "ac: " << ac;

		//DÝZÝLER VE DÖNGÜLER
		int ogrenciadedi = 4;
		std::string ogrenciismi[ogrenciadedi];   //4 eleman sayýsýdýr.
		ogrenciismi[0] = "Ahmet";
		ogrenciismi[1] = "Mehmet";
		ogrenciismi[2] = "Ayse";
		ogrenciismi[3] = "Fatma";
		gLogi("gCanvas") << "2 Nolu öðrencinin ismi:" << ogrenciismi[2];
		int ogrenciyasi[] = {14, 15, 16, 17};
		gLogi("gCanvas") << "2 Nolu öðrencinin yaþý:" << ogrenciyasi[2];
		for(int i = 0; i < ogrenciadedi; i++) {
			gLogi("gCanvas") << i << " Nolu Öðrenci Ýsmi:" << ogrenciismi[i];
		}
		int ad = va.toplamiHesapla(ogrenciyasi, ogrenciadedi);
		gLogi("gCanvas") << "ad: " << ad;
		int ogrenciadedi2 = 5;
		int ogrenciyasi2[] = {18, 19, 20, 21, 22};
		int ae = va.toplamlarinFarkiniHesapla(ogrenciyasi, ogrenciadedi, ogrenciyasi2, ogrenciadedi2);
		gLogi("gCanvas") << "ae: " << ae;
		hangiresim = 0;
		int sayi1 = 2;
		int sayi2 = 3.2f;
		int toplam = topla(sayi1, sayi2);
		gLogi("Toplam") << toplam;
		int toplam2 = topla(9);
		gLogi("Toplam2") << toplam2;

		for (int sira = 0; sira < 4; ++sira) {
				//resim1[sira].loadImage("00" + gToStr(sira) + ".png");     // deðiþken isimlerini birbirinden ayýrdýk. [] index verdik.
		}

		std::vector<int> af = {6, 9, 7, 4, 2};
		gLogi("gCanvas") << "af2:" << af[2];
		gLogi("gCanvas") << "afsize:" << af.size();
		int ag = va.toplamiHesapla(af);
		gLogi("gCanvas") << "ag:" << ag;
		float ah = va.ortalamayiHesapla(af);
		gLogi("gCanvas") << "ah:" << ah;

		std::vector<int> musteriadedi = {22000, 28000, 36000, 36000, 45000, 53000};
		std::vector<int> satismiktari = {50000, 58000, 64000, 74000, 74000, 79000};

		gLogi("gCanvas") << "musteriadedi toplam:" << va.toplamiHesapla(musteriadedi);
		gLogi("gCanvas") << "satismiktari toplam:" << va.toplamiHesapla(satismiktari);
		gLogi("gCanvas") << "musteriadedi ortalama:" << va.ortalamayiHesapla(musteriadedi);
		gLogi("gCanvas") << "satismiktari ortalama:" << va.ortalamayiHesapla(satismiktari);
		gLogi("gCanvas") << "musteriadedi modu:" << va.modHesapla(musteriadedi);
		gLogi("gCanvas") << "satismiktari modu:" << va.modHesapla(satismiktari);
		gLogi("gCanvas") << "musteriadedi medyani:" << va.medyanHesapla(musteriadedi);
		gLogi("gCanvas") << "satismiktari medyani:" << va.medyanHesapla(satismiktari);
		gLogi("gCanvas") << "musteriadedi varyansi:" << va.varyansHesapla(musteriadedi);
		gLogi("gCanvas") << "satismiktari varyansi:" << va.varyansHesapla(satismiktari);
		gLogi("gCanvas") << "musteriadedi standarsapmasi:" << va.standartSapmaHesapla(musteriadedi);
		gLogi("gCanvas") << "satismiktari standartsapmasi:" << va.standartSapmaHesapla(satismiktari);
		gLogi("gCanvas") << "egimhesabi:" << va.egimHesapla(musteriadedi, satismiktari);
		gLogi("gCanvas") << "sabithesabi:" << va.sabitHesapla(musteriadedi, satismiktari);

		std::vector<int> dizi1 = {11,12,13,14};
		std::vector<int> dizi2 = {15,12,13,14};
		gLogi("gCanvas") << "ortalama: " << va.toplamlarinOrtalamasi(dizi1,dizi2);
}

int gCanvas::toplamiHesapla(int rakam1, int rakam2) {
	int toplam = rakam1 + rakam2;
	return toplam;
}

void gCanvas::logaYazdir(std::string etiket, std::string mesaj) {
	gLogi(etiket) << mesaj;
}

void gCanvas::logaYazdir(std::string mesaj) {
	gLogi("gCanvas") << mesaj;
}

void gCanvas::logaMerhabaYazdir() {
	gLogi("gCanvas") << "Merhaba!";
}

void gCanvas::update() {
}

void gCanvas::draw() {
	//resim1[hangiresim].draw(0+(hangiresim * 400), 0+(hangiresim * 400));
}

void gCanvas::keyPressed(int key) {
//	gLogi("gCanvas") << "keyPressed:" << key;
	//if(key == 65)hangiresim = 1;
}

void gCanvas::keyReleased(int key) {
//	gLogi("gCanvas") << "keyReleased:" << key;
	//if(key == 65)hangiresim = 0;
}

void gCanvas::charPressed(unsigned int codepoint) {
//	gLogi("gCanvas") << "charPressed:" << gCodepointToStr(codepoint);
}

void gCanvas::mouseMoved(int x, int y) {
	//gLogi("gCanvas") << "mouseMoved" << ", x:" << x << ", y:" << y;
}

void gCanvas::mouseDragged(int x, int y, int button) {
	//gLogi("gCanvas") << "mouseDragged" << ", x:" << x << ", y:" << y << ", b:" << button;
	//int rakam;
}

void gCanvas::mousePressed(int x, int y, int button) {
	//gLogi("gCanvas") << "mousePressed" << ", x:" << x << ", y:" << y << ", b:" << button;
	//int rakam = 5;
}

void gCanvas::mouseReleased(int x, int y, int button) {
	//gLogi("gCanvas") << "mouseReleased" << ", button:" << button;
	//programiKapat(x, y);
}

void gCanvas::mouseScrolled(int x, int y) {
	//gLogi("gCanvas") << "mouseScrolled" << ", x:" << x << ", y:" << y;
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

int gCanvas::topla(int sayi1, int sayi2) {
	gLogi("topla0") << (sayi1 + sayi2);
	return sayi1 + sayi2;
}

float gCanvas::topla(float sayi1, float sayi2) {
	gLogi("topla1") << (sayi1 + sayi2);
	return sayi1 + sayi2;
}

float gCanvas::topla(int sayi1, float sayi2) {
	gLogi("topla2") << (sayi1 + sayi2);
	return sayi1 + sayi2;
}

float gCanvas::ortalama(float sayi1, float sayi2) {
	return(sayi1 + sayi2) / 2;
}

void gCanvas::programiKapat(int x, int y) {
	exit(0);         // exit fonksiyonu kapat demek.  0 ise sorunsuz þekilde kapatýldý demek.
}
