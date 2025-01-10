#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <string>
#include<fstream>
using namespace std;

//DOMENIU: MAKE-UP
//CLASE: RUJ, FOND DE TEN, PALETA FARDURI

class Ruj {
private:
	string numeBrand;
	float pret;
	bool esteWaterproof;
	const int anFabricatie;
	static int puncteBonus;
	char* categorie;
	int nrNuante;
	string* nuanteDisponibile;

public:
	Ruj() :anFabricatie(2024) {
		this->numeBrand = "Huda Beauty";
		this->pret = 130.5;
		this->esteWaterproof = true;
		this->categorie = new char[strlen("Gloss") + 1];
		strcpy(this->categorie, "Gloss");
		this->nrNuante = 0;
		this->nuanteDisponibile = NULL;
	}

	Ruj(string numeBrand, float pret, bool esteWaterproof) :anFabricatie(2023) {
		this->numeBrand = numeBrand;
		this->pret = pret;
		this->esteWaterproof = esteWaterproof;
		this->categorie = new char[strlen("Matt") + 1];
		strcpy(this->categorie, "Matt");
		this->nrNuante = 0;
		this->nuanteDisponibile = NULL;
	}

	Ruj(string numeBrand, float pret, bool esteWaterproof, int anFabricatie, const char* categorie, int nrNuante, string* nuanteDisponibile) :anFabricatie(2024) {
		this->numeBrand = numeBrand;
		this->pret = pret;
		this->esteWaterproof = esteWaterproof;
		this->categorie = new char[strlen(categorie) + 1];
		strcpy(this->categorie, categorie);
		this->nrNuante = nrNuante;
		this->nuanteDisponibile = new string[this->nrNuante];
		for (int i = 0; i < nrNuante; i++) {
			this->nuanteDisponibile[i] = nuanteDisponibile[i];
		}
	}

	//DESTRUCTOR
	~Ruj() {
		if (this->categorie != NULL) {
			delete[]this->categorie;
		}
		
		if (this->nuanteDisponibile != NULL) {
			delete[]this->nuanteDisponibile;
		}
	}
	
	//CONSTRUCTORUL DE COPIERE
	Ruj(const Ruj& obj) :anFabricatie(obj.anFabricatie) {
		this->numeBrand = obj.numeBrand;
		this->pret = obj.pret;
		this->esteWaterproof = obj.esteWaterproof;
		this->categorie = new char[strlen(obj.categorie) + 1];
		strcpy(this->categorie, obj.categorie);
		this->nrNuante = obj.nrNuante;
		this->nuanteDisponibile = new string[obj.nrNuante];
		for (int i = 0; i < this->nrNuante; i++) {
			this->nuanteDisponibile[i] = obj.nuanteDisponibile[i];
		}
	}
	
	//GETTERI
	string getNumeBrand() {
		return this->numeBrand;
	}
	float getPret() {
		return this->pret;
	}
	bool getEsteWaterproof() {
		return this->esteWaterproof;
	}
	const int getAnFabricatie() {
		return this->anFabricatie;
	}
	char* getCategorie() {
		return this->categorie;
	}
	int getNrNuante() {
		return this->nrNuante;
	}
	string* getNuanteDisponibile() {
		return this->nuanteDisponibile;
	}
	static int getPuncteBonus() {
		return Ruj::puncteBonus;
	}

	//SETTERI
	void setNumeBrand(string numeNouBrand) {
		this->numeBrand = numeNouBrand;
	}
	void setPret(float pretNou) {
		this->pret = pretNou;
	}
	void setEsteWaterproof(bool esteWaterproofNou) {
		this->esteWaterproof = esteWaterproofNou;
	}
	void setCategorie(const char* categorieNoua) {
		if (this->categorie != NULL) {
			delete[]this->categorie;
		}
		this->categorie = new char[strlen(categorieNoua) + 1];
		strcpy(this->categorie, categorieNoua);
	}
	void setNuante(int nrNouNuante, string* nuanteNoiDisponibile) {
		if (this->nuanteDisponibile != NULL) {
			delete[]this->nuanteDisponibile;
		}
		this->nrNuante = nrNouNuante;
		this->nuanteDisponibile = new string[this->nrNuante];
		for (int i = 0; i < this->nrNuante; i++) {
			this->nuanteDisponibile[i] = nuanteNoiDisponibile[i];
		}

	}
	static void setPuncteBonus(int puncteBonusNou) {
		Ruj::puncteBonus = puncteBonusNou;
	}

	//FUNCTIE
	friend ostream& operator<<(ostream& out,const Ruj& obj) {
		out << "Numele brandului: " << obj.numeBrand << endl;
		out << "Pretul rujului: " << obj.pret << endl;
		out << "Este waterproof? ( 1 - DA, 0 - NU ): " << obj.esteWaterproof << endl;
		out << "Anul fabricatiei: " << obj.anFabricatie << endl;
		out << "Punctele bonus: " << obj.puncteBonus << endl;
		out << "Tipul rujului: " << obj.categorie << endl;
		out << "Nr nuante: " << obj.nrNuante << endl;
		out << " Nuantele disponibile: " << endl;
		for (int i = 0; i < obj.nrNuante; i++) {
			out << obj.nuanteDisponibile[i] << endl;
		}
		return out;
	}

};
int Ruj::puncteBonus = 20;

//class FondDeTen {
//public:
//	string numeBrand;
//	int SPF;
//	float durataRezistentaH;
//	bool esteWaterproof;
//	const int anFabricatie;
//	static int puncteBonus;
//	int nrTipuri;
//	string* denumireTip;
//	float* pretTip;
//
//	FondDeTen() :anFabricatie(2024) {
//		this->numeBrand = "Rimmel London";
//		this->SPF = 50;
//		this->durataRezistentaH = 12.5;
//		this->esteWaterproof = false;
//		this->nrTipuri = 0;
//		this->denumireTip = NULL;
//		this->pretTip = NULL;
//	}
//
//	FondDeTen(string numeBrand, int SPF, bool esteWaterproof) :anFabricatie(2022) {
//		this->numeBrand = numeBrand;
//		this->SPF = SPF;
//		this->durataRezistentaH = 6.5;
//		this->esteWaterproof = false;
//		this->nrTipuri = 0;
//		this->denumireTip = NULL;
//		this->pretTip = NULL;
//	}
//
//	FondDeTen(string numeBrand, int SPF, float durataRezistentaH, bool esteWaterproof, int anFabricatie, int nrTipuri, string* denumireTip, float* pretTip) :anFabricatie(anFabricatie) {
//		this->numeBrand = numeBrand;
//		this->SPF = SPF;
//		this->durataRezistentaH = durataRezistentaH;
//		this->esteWaterproof = esteWaterproof;
//		this->nrTipuri = nrTipuri;
//		this->denumireTip = new string[this->nrTipuri];
//		this->pretTip = new float[this->nrTipuri];
//		for (int i = 0; i < this->nrTipuri; i++) {
//			this->denumireTip[i] = denumireTip[i];
//			this->pretTip[i] = pretTip[i];
//		}
//	}
//
//};
//int FondDeTen::puncteBonus = 50;

class PaletaFarduri {
private:
	string numeBrand;
	float pret;
	const int anFabricatie;
	static int puncteBonus;
	int nrCulori;
	string* denumireCulori;

public:
	PaletaFarduri() :anFabricatie(2023) {
		this->numeBrand = "Anastasia BH";
		this->pret = 315.5;
		int nrCulori = 0;
		this->denumireCulori = NULL;
	}

	PaletaFarduri(string numeBrand) :anFabricatie(2022) {
		this->numeBrand = numeBrand;
		this->pret = 49.99;
		this->nrCulori = 0;
		this->denumireCulori = NULL;
	}

	PaletaFarduri(string numeBrand, float pret, int anFabricatie, int nrCulori, string* denumireCulori) :anFabricatie(anFabricatie) {
		this->numeBrand = numeBrand;
		this->pret = pret;
		this->nrCulori = nrCulori;
		this->denumireCulori = new string[this->nrCulori];
		for (int i = 0; i < this->nrCulori; i++) {
			this->denumireCulori[i] = denumireCulori[i];
		}
	}
	
	//DESTRUCTOR
	~PaletaFarduri() {
		if (this->denumireCulori != NULL) {
			delete[]this->denumireCulori;
		}
	}

	//CONSTRUCTORUL DE COPIERE
	PaletaFarduri(const PaletaFarduri& obj):anFabricatie(obj.anFabricatie) {
		this->numeBrand = obj.numeBrand;
		this->pret = obj.pret;
		this->nrCulori = obj.nrCulori;
		this->denumireCulori = new string[this->nrCulori];
		for (int i = 0; i < this->nrCulori; i++) {
			this->denumireCulori[i] = obj.denumireCulori[i];
		}
	}
	
	//GETTERI
	string getNumeBrand() {
		return this->numeBrand;
	}
	float getPret() {
		return this->pret;
	}
	const int getAnFabricatie() {
		return this->anFabricatie;
	}
	static int getPuncteBonus() {
		return PaletaFarduri::puncteBonus;
	}
	int getNrCulori() {
		return this->nrCulori;
	}
	string* getDenumireCulori() {
		return this->denumireCulori;
	}

	//SETTERI
	void setNumeBrand(string numeNouBrand) {
		this->numeBrand = numeNouBrand;
	}
	void setPret(float pretNou) {
		this->pret = pretNou;
	}
	static void setPuncteBonus(int puncteBonusNou) {
		PaletaFarduri::puncteBonus = puncteBonusNou;
	}
	void setCulori(int nrNouCulori, string* denumireCuloriNoi) {
		if (this->denumireCulori != NULL) {
			delete[]this->denumireCulori;
		}
		this->nrCulori = nrNouCulori;
		this->denumireCulori = new string[this->nrCulori];
		for (int i = 0; i < this->nrCulori; i++) {
			this->denumireCulori[i] = denumireCuloriNoi[i];
		}
	}

	friend ostream& operator<<(ostream& out, const PaletaFarduri& obj) {
		out << "Numele brandului: " << obj.numeBrand << endl;
		out << "Pretul: " << obj.pret << endl;
		out << "Anul fabricatiei: " << obj.anFabricatie << endl;
		out << "Punctele bonus: " << obj.puncteBonus << endl;
		out << "Numarul culorilor din paleta: " << obj.nrCulori << endl;
		out << "Culorile din paleta: " << endl;
		for (int i = 0; i < obj.nrCulori; i++) {
			out << obj.denumireCulori[i] << endl << endl;
		}
		return out;
	}
};
int PaletaFarduri::puncteBonus = 30;


//FUNCTIA MAIN

int main() {
	cout << "RUJURI:" << endl << endl;
	Ruj r1;
	cout << "Numele brandului: " << r1.getNumeBrand() << endl;
	cout << "Pretul rujului: " << r1.getPret() << endl;
	cout << "Este waterproof? ( 1 - DA, 0 - NU ): " << r1.getEsteWaterproof() << endl;
	cout << "Anul fabricatiei: " << r1.getAnFabricatie() << endl;
	cout << "Tipul rujului: " << r1.getCategorie() << endl;
	cout << "Nr nuante: " << r1.getNrNuante() << endl;
	cout << " Nuantele disponibile: " << endl;
	for (int i = 0; i < r1.getNrNuante(); i++) {
		cout << r1.getNuanteDisponibile()[i] << endl;
	}
	

	Ruj r2("NYX", 39.99, true);
	cout << "Numele brandului: " << r2.getNumeBrand() << endl;
	cout << "Pretul rujului: " << r2.getPret() << endl;
	cout << "Este waterproof? ( 1 - DA, 0 - NU ): " << r2.getEsteWaterproof() << endl;
	cout << "Anul fabricatiei: " << r2.getAnFabricatie() << endl;
	cout << "Tipul rujului: " << r2.getCategorie() << endl;
	cout << "Nr nuante: " << r2.getNrNuante() << endl;
	cout << " Nuantele disponibile: " << endl;
	for (int i = 0; i < r2.getNrNuante(); i++) {
		cout << r2.getNuanteDisponibile()[i] << endl;
	}

	string culori3[] = { "Rosu", "Roz", "Mov", "Nude" };
	Ruj r3("Essence", 19.99, false, 2024, "Matt", 4, culori3);
	cout << "Numele brandului: " << r3.getNumeBrand() << endl;
	cout << "Pretul rujului: " << r3.getPret() << endl;
	cout << "Este waterproof? ( 1 - DA, 0 - NU ): " << r3.getEsteWaterproof() << endl;
	cout << "Anul fabricatiei: " << r3.getAnFabricatie() << endl;
	cout << "Tipul rujului: " << r3.getCategorie() << endl;
	cout << "Nr nuante: " << r3.getNrNuante() << endl;
	cout << " Nuantele disponibile: " << endl;
	for (int i = 0; i < r3.getNrNuante(); i++) {
		cout << r3.getNuanteDisponibile()[i] << endl;
	}
	
	cout << endl << endl;
	cout << "Rujul r4 creat pe baza rujului r3: " << endl;
	Ruj r4(r3);
	cout << "Numele brandului: " << r4.getNumeBrand() << endl;
	cout << "Pretul rujului: " << r4.getPret() << endl;
	cout << "Este waterproof? ( 1 - DA, 0 - NU ): " << r4.getEsteWaterproof() << endl;
	cout << "Anul fabricatiei: " << r4.getAnFabricatie() << endl;
	cout << "Tipul rujului: " << r4.getCategorie() << endl;
	cout << "Nr nuante: " << r4.getNrNuante() << endl;
	cout << " Nuantele disponibile: " << endl;
	for (int i = 0; i < r4.getNrNuante(); i++) {
		cout << r4.getNuanteDisponibile()[i] << endl;
	}
	cout << endl << endl;
	cout << "obiectul r1 inainte de apelul setterilor: " << endl;
	cout << "Numele brandului: " << r1.getNumeBrand() << endl;
	cout << "Pretul rujului: " << r1.getPret() << endl;
	cout << "Este waterproof? ( 1 - DA, 0 - NU ): " << r1.getEsteWaterproof() << endl;
	cout << "Anul fabricatiei: " << r1.getAnFabricatie() << endl;
	cout << "Tipul rujului: " << r1.getCategorie() << endl;
	cout << "Nr nuante: " << r1.getNrNuante() << endl;
	cout << " Nuantele disponibile: " << endl;
	for (int i = 0; i < r1.getNrNuante(); i++) {
		cout << r1.getNuanteDisponibile()[i] << endl;
	}
	cout << "obiectul r1 dupa apelul setterilor: " << endl;
	r1.setNumeBrand("YSL");
	r1.setPret(129.99);
	r1.setEsteWaterproof(1);
	r1.setCategorie("Cremos");
	string culori1[] = { "Roz", "Rosu", "Mov", "Nude", "Visiniu" };
	r1.setNuante(5, culori1);
	cout << "Numele brandului: " << r1.getNumeBrand() << endl;
	cout << "Pretul rujului: " << r1.getPret() << endl;
	cout << "Este waterproof? ( 1 - DA, 0 - NU ): " << r1.getEsteWaterproof() << endl;
	cout << "Anul fabricatiei: " << r1.getAnFabricatie() << endl;
	cout << "Tipul rujului: " << r1.getCategorie() << endl;
	cout << "Nr nuante: " << r1.getNrNuante() << endl;
	cout << " Nuantele disponibile: " << endl;
	for (int i = 0; i < r1.getNrNuante(); i++) {
		cout << r1.getNuanteDisponibile()[i] << endl;
	}
	cout << endl << endl;

	/*cout << "FONDURI DE TEN: " << endl << endl;
	FondDeTen f1;
	cout << "Numele brandului: " << f1.numeBrand << endl;
	cout << "SPF: " << f1.SPF << endl;
	cout << "Durata rezistentei in ore: " << f1.durataRezistentaH << endl;
	cout << "Este waterproof? (1 - DA; 0 - NU): " << f1.esteWaterproof << endl;
	cout << "Anul fabricatiei: " << f1.anFabricatie << endl;
	cout << "Numar tipuri: " << f1.nrTipuri << endl;
	cout << "Tipuri: " << endl;
	for (int i = 0; i < f1.nrTipuri; i++) {
		cout << "Denumirea tipului: " << f1.denumireTip[i] << endl;
		cout << "Pretul tipului: " << f1.pretTip[i] << endl;
	}

	FondDeTen f2("MUP", 30, true);
	cout << "Numele brandului: " << f2.numeBrand << endl;
	cout << "SPF: " << f2.SPF << endl;
	cout << "Durata rezistentei in ore: " << f2.durataRezistentaH << endl;
	cout << "Este waterproof? (1 - DA; 0 - NU): " << f2.esteWaterproof << endl;
	cout << "Anul fabricatiei: " << f2.anFabricatie << endl;
	cout << "Numar tipuri: " << f2.nrTipuri << endl;
	cout << "Tipuri: " << endl;
	for (int i = 0; i < f2.nrTipuri; i++) {
		cout << "Denumirea tipului: " << f2.denumireTip[i] << endl;
		cout << "Pretul tipului: " << f2.pretTip[i] << endl;
	}

	string denumiri1[] = { "Matifiant", "Hidratant" };
	float preturi1[] = { 349.99,299.99 };
	FondDeTen f3("Estee Lauder", 25, 24, true, 2024, 2, denumiri1, preturi1);
	cout << "Numele brandului: " << f3.numeBrand << endl;
	cout << "SPF: " << f3.SPF << endl;
	cout << "Durata rezistentei in ore: " << f3.durataRezistentaH << endl;
	cout << "Este waterproof? (1 - DA; 0 - NU): " << f3.esteWaterproof << endl;
	cout << "Anul fabricatiei: " << f3.anFabricatie << endl;
	cout << "Numar tipuri: " << f3.nrTipuri << endl;
	cout << "Tipuri: " << endl;
	for (int i = 0; i < f3.nrTipuri; i++) {
		cout << "Denumirea tipului: " << f3.denumireTip[i] << endl;
		cout << "Pretul tipului: " << f3.pretTip[i] << endl;
	}*/
	

	cout << "PALETE DE FARDURI: " << endl << endl;
	PaletaFarduri p1;
	cout << "Numele brandului: " << p1.getNumeBrand() << endl;
	cout << "Pretul: " << p1.getPret() << endl;
	cout << "Anul fabricatiei: " << p1.getAnFabricatie() << endl;
	cout << "Numarul culorilor din paleta: " << p1.getNrCulori() << endl;
	cout << "Culorile din paleta: " << endl;
	for (int i = 0; i < p1.getNrCulori(); i++) {
		cout << p1.getDenumireCulori()[i] << endl;
	}

	PaletaFarduri p2("NYX");
	cout << "Numele brandului: " << p2.getNumeBrand() << endl;
	cout << "Pretul: " << p2.getPret() << endl;
	cout << "Anul fabricatiei: " << p2.getAnFabricatie() << endl;
	cout << "Numarul culorilor din paleta: " << p2.getNrCulori() << endl;
	cout << "Culorile din paleta: " << endl;
	for (int i = 0; i < p2.getNrCulori(); i++) {
		cout << p2.getDenumireCulori()[i] << endl;
	}

	string culoripaleta1[] = { "Roz","Mov","Portocaliu","Galben","Verde","Albastru","Negru","Gri" };
	PaletaFarduri p3("Too Faced", 249.99, 2024, 8, culoripaleta1);
	cout << "Numele brandului: " << p3.getNumeBrand() << endl;
	cout << "Pretul: " << p3.getPret() << endl;
	cout << "Anul fabricatiei: " << p3.getAnFabricatie() << endl;
	cout << "Numarul culorilor din paleta: " << p3.getNrCulori() << endl;
	cout << "Culorile din paleta: " << endl;
	for (int i = 0; i < p3.getNrCulori(); i++) {
		cout << p3.getDenumireCulori()[i] << endl;
	}

	PaletaFarduri p4(p3);
	cout << "Obiectul p4 construit pe baza obiectului p3:" << endl;
	cout << "Numele brandului: " << p4.getNumeBrand() << endl;
	cout << "Pretul: " << p4.getPret() << endl;
	cout << "Anul fabricatiei: " << p4.getAnFabricatie() << endl;
	cout << "Punctele bonus: " << p4.getPuncteBonus() << endl;
	cout << "Numarul culorilor din paleta: " << p4.getNrCulori() << endl;
	cout << "Culorile din paleta: " << endl;
	for (int i = 0; i < p4.getNrCulori(); i++) {
		cout << p4.getDenumireCulori()[i] << endl;
	}
	cout << endl;
	cout << "Obiectul p4 dupa apelul setterilor: " << endl;
	p4.setNumeBrand("Avon");
	p4.setPret(24.99);
	p4.setPuncteBonus(5);
	string culoripaleta4[] = { "Alb","Negru","Gri" };
	p4.setCulori(3, culoripaleta4);
	cout << "Obiectul p4 construit pe baza obiectului p3:" << endl;
	cout << "Numele brandului: " << p4.getNumeBrand() << endl;
	cout << "Pretul: " << p4.getPret() << endl;
	cout << "Anul fabricatiei: " << p4.getAnFabricatie() << endl;
	cout << "Punctele bonus: " << p4.getPuncteBonus() << endl;
	cout << "Numarul culorilor din paleta: " << p4.getNrCulori() << endl;
	cout << "Culorile din paleta: " << endl;
	for (int i = 0; i < p4.getNrCulori(); i++) {
		cout << p4.getDenumireCulori()[i] << endl;
	}

	cout << endl << endl;
	cout << "------------- APEL FUNCTII ----------------" << endl << endl;
	cout << r1;
	cout << p1;
}
