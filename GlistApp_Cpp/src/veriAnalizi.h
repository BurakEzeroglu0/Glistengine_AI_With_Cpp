/*
 * veriAnalizi.h
 *
 *  Created on: 5 Kas 2024
 *      Author: Arkýl
 */

#ifndef SRC_VERIANALIZI_H_
#define SRC_VERIANALIZI_H_

#include "gObject.h"


class veriAnalizi : public gObject {
public:
	veriAnalizi();
	virtual ~veriAnalizi();

	int toplamiHesapla(int rakam1, int rakam2);
	int carpimiHesapla(int rakam1, int rakam2);
	int karesiniHesapla(int rakam);
	float karekokunuHesapla(int rakam);
	int farkiniHesapla(int rakam1, int rakam2);
	std::string cumleyiOlustur(std::string isim, int yas);
	int toplamiHesapla(int* rakamptr1, int* rakamptr2);
	std::string tamIsmiOlustur(std::string* isimp, std::string* soyisimp);
	int toplamiHesapla(int* rakamlar, int rakamAdedi);        //C++ dilinde diziler birer pointer dýr. (Dizinin ilk elemanýný gösteren)
	int toplamlarinFarkiniHesapla(int* rakamlar1, int rakamAdedi1, int* rakamlar2,  int rakamAdedi2);
	int toplamiHesapla(std::vector<int> rakamlar);
	float ortalamayiHesapla(std::vector<int> rakamlar);
	int modHesapla(std::vector<int> rakamlar);
	float medyanHesapla(std::vector<int> rakamlar);
	float varyansHesapla(std::vector<int> rakamlar);
	float standartSapmaHesapla(std::vector<int> rakamlar);
	float egimHesapla(std::vector<int> vectorX, std::vector<int> vectorY);
	float sabitHesapla(std::vector<int> vectorX, std::vector<int> vectorY);
	float toplamlarinOrtalamasi(std::vector<int> toplam1, std::vector<int> toplam2);

private:

};

#endif /* SRC_VERIANALIZI_H_ */
