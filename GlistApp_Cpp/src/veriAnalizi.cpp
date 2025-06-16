/*
 * veriAnalizi.cpp
 *
 *  Created on: 5 Kas 2024
 *      Author: Arkýl
 */

#include "veriAnalizi.h"


veriAnalizi::veriAnalizi() {
}

veriAnalizi::~veriAnalizi() {
}

int veriAnalizi::toplamiHesapla(int rakam1, int rakam2) {
	int toplam = rakam1 + rakam2;
	return toplam;
}

int veriAnalizi::carpimiHesapla(int rakam1, int rakam2) {
	int carpim = rakam1 * rakam2;
	return carpim;
}

int veriAnalizi::karesiniHesapla(int rakam) {
	int karesi = rakam * rakam;
	return karesi;
}

float veriAnalizi::karekokunuHesapla(int rakam) {
	float karekok = sqrt(rakam);
	return karekok;
}

int veriAnalizi::farkiniHesapla(int rakam1, int rakam2) {
	int farki = rakam1 - rakam2;
	return abs(farki);                 // abs mutlak deðer fonksiyonudur.
}
std::string veriAnalizi::cumleyiOlustur(std::string isim, int yas) {
	std::string cumle = isim + " " + gToStr(yas) + "Yasindadir";
	return cumle;
}

int veriAnalizi::toplamiHesapla(int* rakamptr1, int* rakamptr2) {
	int toplam = *rakamptr1 + *rakamptr2;
	return toplam;
}

std::string veriAnalizi::tamIsmiOlustur(std::string *isimp, std::string *soyisimp) {
		std::string tamisim = *isimp + " " + *soyisimp;
		return tamisim;
}

int veriAnalizi::toplamiHesapla(int *rakamlar, int rakamAdedi) {
	int toplam = 0;
	for(int i = 0; i < rakamAdedi; i++) {
		toplam += rakamlar[i];
	}
	return toplam;
}

int veriAnalizi::toplamlarinFarkiniHesapla(int *rakamlar1, int rakamAdedi1, int *rakamlar2, int rakamAdedi2) {
	int toplam1 = toplamiHesapla(rakamlar1, rakamAdedi1);
	int toplam2 = toplamiHesapla(rakamlar2, rakamAdedi2);
	int sonuc = toplam1 - toplam2;
	return abs(sonuc);
}

int veriAnalizi::toplamiHesapla(std::vector<int> rakamlar) {
	int toplam = 0;
	for(int i = 0; i < rakamlar.size(); i++) {
		toplam += rakamlar[i];
	}
	return toplam;
}

float veriAnalizi::ortalamayiHesapla(std::vector<int> rakamlar) {
	int toplam = toplamiHesapla(rakamlar);
	float ortalama = (float)toplam / (float)rakamlar.size();
	return ortalama;
}

int veriAnalizi::modHesapla(std::vector<int> rakamlar) {
	int maxtekrar = 1;
	int maxpozisyon = 0;
	for(int i = 0; i < rakamlar.size(); i++) {
		int tekrar = 0;
		for(int rakam : rakamlar) {
			if(rakamlar[i] == rakam) {
				tekrar++;
			}
		}
		if(tekrar - 1 >= maxtekrar) {
			maxtekrar = tekrar;
			maxpozisyon = i;
		}
	}
	return rakamlar[maxpozisyon];
}

float veriAnalizi::medyanHesapla(std::vector<int> rakamlar) {
	sort(rakamlar.begin(), rakamlar.end());
	int m = rakamlar.size();
	if(m % 2 == 0) {
		return (rakamlar[m / 2 - 1] + rakamlar[m / 2]) / 2.0f;
	} else {
		return (float)rakamlar[m / 2];
	}

}

float veriAnalizi::varyansHesapla(std::vector<int> rakamlar) {
	float ortalama = ortalamayiHesapla(rakamlar);
	float farklartoplami = 0;
	for(int i = 0; i < rakamlar.size(); i++) {
		farklartoplami += std::pow(rakamlar[i] - ortalama, 2);
	}
	return farklartoplami /= (rakamlar.size() - 1);
}

float veriAnalizi::standartSapmaHesapla(std::vector<int> rakamlar) {
	float standartsapma = std::sqrt(varyansHesapla(rakamlar));
	return standartsapma;
}

float veriAnalizi::egimHesapla(std::vector<int> vectorX, std::vector<int> vectorY) {
	int n = vectorX.size();
	float meanx = ortalamayiHesapla(vectorX);
	float meany = ortalamayiHesapla(vectorY);
	float stdx = standartSapmaHesapla(vectorX);
	float stdy = standartSapmaHesapla(vectorY);
	float toplam = 0.0f;
	for(int i = 0; i < n; i++) {
		toplam += ((vectorX[i] - meanx) / stdx) * ((vectorY[i] - meany) / stdy);
	}
	toplam = toplam / (n - 1);
	float egim = toplam * stdy / stdx;
	return egim;
}

float veriAnalizi::sabitHesapla(std::vector<int> vectorX, std::vector<int> vectorY) {
	float meanx = ortalamayiHesapla(vectorX);
	float meany = ortalamayiHesapla(vectorY);
	float slope = egimHesapla(vectorX, vectorY);
	float constant = meany - (slope * meanx);
	return constant;
}

float veriAnalizi::toplamlarinOrtalamasi(std::vector<int> toplam1,
		std::vector<int> toplam2) {
	float sonuc1 = toplamiHesapla(toplam1);
	float sonuc2 = toplamiHesapla(toplam2);
	return (sonuc1 + sonuc2) / (toplam1.size() + toplam2.size());
}




