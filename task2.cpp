#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <string>
using namespace std;

//DOMENIU: MAKE-UP
//CLASE: RUJ, FOND DE TEN, PALETA FARDURI

class Ruj {
public:
	string numeBrand;
	float pret;
	bool esteWaterproof;
	const int anFabricatie;
	static int puncteBonus;
	char* categorie;
	int nrNuante;
	string* nuanteDisponibile;

	Ruj():anFabricatie(2024) {
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

	static void modificaPuncteBonus(int puncteBonusNou) {
		if (puncteBonus > 0) {
			Ruj::puncteBonus = puncteBonusNou;
		}
	}
};
int Ruj::puncteBonus = 20;

class FondDeTen {
public:
	string numeBrand;
	int SPF;
	float durataRezistentaH;
	bool esteWaterproof;
	const int anFabricatie;
	static int puncteBonus;
	int nrTipuri;
	string* denumireTip;
	float* pretTip;

	FondDeTen() :anFabricatie(2024) {
		this->numeBrand = "Rimmel London";
		this->SPF = 50;
		this->durataRezistentaH = 12.5;
		this->esteWaterproof = false;
		this->nrTipuri = 0;
		this->denumireTip = NULL;
		this->pretTip = NULL;
	}

	FondDeTen(string numeBrand, int SPF, bool esteWaterproof) :anFabricatie(2022) {
		this->numeBrand = numeBrand;
		this->SPF = SPF;
		this->durataRezistentaH = 6.5;
		this->esteWaterproof = false;
		this->nrTipuri = 0;
		this->denumireTip = NULL;
		this->pretTip = NULL;
	}

	FondDeTen(string numeBrand, int SPF, float durataRezistentaH, bool esteWaterproof, int anFabricatie, int nrTipuri, string* denumireTip, float* pretTip) :anFabricatie(anFabricatie) {
		this->numeBrand = numeBrand;
		this->SPF = SPF;
		this->durataRezistentaH = durataRezistentaH;
		this->esteWaterproof = esteWaterproof;
		this->nrTipuri = nrTipuri;
		this->denumireTip = new string[this->nrTipuri];
		this->pretTip = new float[this->nrTipuri];
		for (int i = 0; i < this->nrTipuri; i++) {
			this->denumireTip[i] = denumireTip[i];
			this->pretTip[i] = pretTip[i];
		}
	}

	static void adaugaPuncteBonus(int puncteBonusAdaugate) {
		puncteBonus += puncteBonusAdaugate;
	}
	
};
int FondDeTen::puncteBonus = 50;

class PaletaFarduri {
public:
	string numeBrand;
	float pret;
	const int anFabricatie;
	static int puncteBonus;
	int nrCulori;
	string* denumireCulori;

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
	static void stergePuncteBonus(int puncteBonusDeSters) {
		puncteBonus -= puncteBonusDeSters;
	}

};
int PaletaFarduri::puncteBonus = 30;


//FUNCTIA MAIN

int main() {
	cout << "RUJURI:" << endl << endl;
	Ruj r1;
	cout << "Numele brandului: " << r1.numeBrand << endl;
	cout << "Pretul rujului: " << r1.pret << endl;
	cout << "Este waterproof? ( 1 - DA, 0 - NU ): " << r1.esteWaterproof << endl;
	cout << "Anul fabricatiei: " << r1.anFabricatie << endl;
	cout << "Tipul rujului: " << r1.categorie << endl;
	cout << "Nr nuante: " << r1.nrNuante << endl;
	cout << " Nuantele disponibile: " << endl;
	for (int i = 0; i < r1.nrNuante; i++) {
		cout << r1.nuanteDisponibile[i] << endl;
	}
	cout << "Punctele bonus inainte de modificare: " << r1.puncteBonus << endl;
	Ruj::modificaPuncteBonus(25);
	cout << "Punctele bonus dupa modificare: " << r1.puncteBonus << endl;
	cout << endl<<endl;

	Ruj r2("NYX", 39.99, true);
	cout << "Numele brandului: " << r2.numeBrand << endl;
	cout << "Pretul rujului : " << r2.pret << endl;
	cout << "Este waterproof? (1-DA; 2-NU): " << r2.esteWaterproof << endl;
	cout << "Anul fabricatiei: " << r2.anFabricatie << endl;
	cout << "Tipul rujului: " << r2.categorie << endl;
	cout << "Nr nuante: " << r2.nrNuante << endl;
	cout << "Nuantele disponibile: " << endl;
	for (int i = 0; i < r2.nrNuante; i++) {
		cout << r2.nuanteDisponibile[i] << endl;
	}
	cout << "Punctele bonus inainte de modificare: " << r2.puncteBonus << endl;
	Ruj::modificaPuncteBonus(15);
	cout << "Punctele bonus dupa modificare: " << r2.puncteBonus << endl;
	cout << endl << endl;

	string culori3[] = { "Rosu", "Roz", "Mov", "Nude" };
	Ruj r3("Essence", 19.99, false, 2024, "Matt", 4, culori3);
	cout << "Numele brandului: " << r3.numeBrand << endl;
	cout << "Pretul rujului : " << r3.pret << endl;
	cout << "Este waterproof? (1-DA; 2-NU): " << r3.esteWaterproof << endl;
	cout << "Anul fabricatiei: " << r3.anFabricatie << endl;
	cout << "Tipul rujului: " << r3.categorie << endl;
	cout << "Nr nuante: " << r3.nrNuante << endl;
	cout << "Nuantele disponibile: " << endl;
	for (int i = 0; i < r3.nrNuante; i++) {
		cout << r3.nuanteDisponibile[i] << endl;
	}
	cout << "Punctele bonus inainte de modificare: " << r3.puncteBonus << endl;
	Ruj::modificaPuncteBonus(10);
	cout << "Punctele bonus dupa modificare: " << r3.puncteBonus << endl;
	cout << endl << endl;

	cout << "FONDURI DE TEN: " << endl << endl;
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
	cout << "Puncte bonus inainte de adaugare: " << f1.puncteBonus << endl;
	FondDeTen::adaugaPuncteBonus(10);
	cout << "Puncte bonus dupa adaugare: " << f1.puncteBonus << endl;
	cout << endl << endl;

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
	cout << "Puncte bonus inainte de adaugare: " << f2.puncteBonus << endl;
	FondDeTen::adaugaPuncteBonus(5);
	cout << "Puncte bonus dupa adaugare: " << f2.puncteBonus << endl;
	cout << endl << endl;

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
	}
	cout << "Puncte bonus inainte de adaugare: " << f3.puncteBonus << endl;
	FondDeTen::adaugaPuncteBonus(50);
	cout << "Puncte bonus dupa adaugare: " << f3.puncteBonus << endl;
	cout << endl << endl;

	cout << "PALETE DE FARDURI: " << endl << endl;
	PaletaFarduri p1;
	cout << "Numele brandului: " << p1.numeBrand << endl;
	cout << "Pretul: " << p1.pret << endl;
	cout << "Anul fabricatiei: " << p1.anFabricatie << endl;
	cout << "Numarul culorilor din paleta: " << p1.nrCulori << endl;
	cout << "Culorile din paleta: " << endl;
	for (int i = 0; i < p1.nrCulori; i++) {
		cout << p1.denumireCulori[i] << endl;
	}
	cout << "Punctele bonus inainte de stergere: " << p1.puncteBonus << endl;
	PaletaFarduri::stergePuncteBonus(5);
	cout << "Punctele bonus dupa stergere: " << p1.puncteBonus << endl;
	cout << endl << endl;

	PaletaFarduri p2("NYX");
	cout << "Numele brandului: " << p2.numeBrand << endl;
	cout << "Pretul: " << p2.pret << endl;
	cout << "Anul fabricatiei: " << p2.anFabricatie << endl;
	cout << "Numarul culorilor din paleta: " << p2.nrCulori << endl;
	cout << "Culorile din paleta: " << endl;
	for (int i = 0; i < p2.nrCulori; i++) {
		cout << p2.denumireCulori[i] << endl;
	}
	cout << "Punctele bonus inainte de stergere: " << p2.puncteBonus << endl;
	PaletaFarduri::stergePuncteBonus(5);
	cout << "Punctele bonus dupa stergere: " << p2.puncteBonus << endl;
	cout << endl << endl;

	string culoripaleta1[] = { "Roz","Mov","Portocaliu","Galben","Verde","Albastru","Negru","Gri" };
	PaletaFarduri p3("Too Faced", 249.99, 2024, 8, culoripaleta1);
	cout << "Numele brandului: " << p3.numeBrand << endl;
	cout << "Pretul: " << p3.pret << endl;
	cout << "Anul fabricatiei: " << p3.anFabricatie << endl;
	cout << "Numarul culorilor din paleta: " << p3.nrCulori << endl;
	cout << "Culorile din paleta: " << endl;
	for (int i = 0; i < p3.nrCulori; i++) {
		cout << p3.denumireCulori[i] << endl;
	}
	cout << "Punctele bonus inainte de stergere: " << p3.puncteBonus << endl;
	PaletaFarduri::stergePuncteBonus(5);
	cout << "Punctele bonus dupa stergere: " << p3.puncteBonus << endl;
	cout << endl << endl;
}