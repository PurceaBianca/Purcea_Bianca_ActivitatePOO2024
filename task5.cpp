// am renuntat la clasa fond de ten pentru ca am pus ft multe atribute in fiecare clasa:( si voi lucra doar cu cele 2 clase,implementand un total de 12 operatori
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
	friend ostream& operator<<(ostream& out, const Ruj& obj) {
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

	//OPERATOR =
	Ruj& operator=(const Ruj& obj) {
		if (this != &obj) {
			if (this->nuanteDisponibile != NULL) {
				delete[]this->nuanteDisponibile;
			}
		}
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
		return*this;
	}

	//OPERATOR>>
	friend istream& operator>>(istream& in, Ruj& obj) {
		if (obj.nuanteDisponibile != NULL) {
			delete[]obj.nuanteDisponibile;
		}
		cout << "Introduceti numele brandului rujului: ";
		in >> obj.numeBrand;
		cout << "Introduceti pretul rujului: ";
		in >> obj.pret;
		cout << "Este rujul waterproof? ( 1 - DA; 0 - NU ): ";
		in >> obj.esteWaterproof;
		cout << "Introduceti punctele bonus obtinute dupa cumpararea rujului: ";
		in >> obj.puncteBonus;
		cout << "Introduceti categoria din care face parte rujul: ";
		char aux[100];
		in >> aux;
		obj.categorie = new char[strlen(aux) + 1];
		strcpy(obj.categorie, aux);
		cout << "Introduceti nr nuantelor acestui ruj: ";
		in >> obj.nrNuante;
		cout << "Introduceti culorile nuantelor acestui ruj: ";
		obj.nuanteDisponibile = new string[obj.nrNuante];
		for (int i = 0; i < obj.nrNuante; i++) {
			in >> obj.nuanteDisponibile[i];
		}
		return in;
	}

	//Sa se compare 2 rujuri in functie de pret
	//OPERATORUL <=
	bool operator<=(const Ruj& obj) {
		if (this->pret <= obj.pret) {
			return 1;
		}
		else {
			return 0;
		}
	}

	//Sa se compare 2 rujuri in intregime
	//OPERATORUL ==
	bool operator==(const Ruj& obj) {
		/*string numeBrand;
		float pret;
		bool esteWaterproof;
		const int anFabricatie;
		static int puncteBonus;
		char* categorie;
		int nrNuante;
		string* nuanteDisponibile;*/
		bool ok = 1;
		if ((this->numeBrand == obj.numeBrand) && (this->pret == obj.pret) && (this->esteWaterproof == obj.esteWaterproof) && (this->anFabricatie == obj.anFabricatie) && (this->puncteBonus == obj.puncteBonus) && (strcmp(this->categorie, obj.categorie) == 0) && (this->nrNuante == obj.nrNuante)) {
			for (int i = 0; i < this->nrNuante; i++) {
				if (this->nuanteDisponibile[i] == obj.nuanteDisponibile[i]) {
				}
				else ok = 0;
			}
		}
		if (ok == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}

	//Sa se afiseze nuanta rujului de pe o anumita pozitie
	//OPERATOR []
	string operator[](int pozitie) {
		if (pozitie >= 0 && pozitie < this->nrNuante) {
			return this->nuanteDisponibile[pozitie];
		}
		else {
			return"Pozitia a fost introdusa gresit!";
		}
	}

	//Sa se calculeze totalul de puncte bonus in functie de cate rujuri cumperi
	//OPERATOR ()
	int operator()(int cantitateCumparata) {
		int totalPuncteBonus = 0;
		totalPuncteBonus = this->puncteBonus * cantitateCumparata;
		return totalPuncteBonus;
	}
};
int Ruj::puncteBonus = 20;

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
	PaletaFarduri(const PaletaFarduri& obj) :anFabricatie(obj.anFabricatie) {
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

	//OP =
	PaletaFarduri& operator=(const PaletaFarduri& obj) {
		if (this->denumireCulori != NULL) {
			delete[]this->denumireCulori;
		}
		this->numeBrand = obj.numeBrand;
		this->pret = obj.pret;
		this->nrCulori = obj.nrCulori;
		this->denumireCulori = new string[this->nrCulori];
		for (int i = 0; i < this->nrCulori; i++) {
			this->denumireCulori[i] = obj.denumireCulori[i];
		}
		return*this;
	}

	//OP >=
	//sa se compare 2 palete in functie de nr de culori
	bool operator>=(const PaletaFarduri& obj) {
		if (this->nrCulori >= obj.nrCulori) {
			return 1;
		}
		else {
			return 0;
		}
	}

	//op +=
	//adaugati o noua culoare in paleta
	PaletaFarduri& operator+=(string culoareNoua) {
		PaletaFarduri obiectCopie(*this);
		if (this->denumireCulori != NULL) {
			delete[]this->denumireCulori;
		}
		this->nrCulori++;
		this->denumireCulori = new string[this->nrCulori];
		for (int i = 0; i < obiectCopie.nrCulori; i++) {
			this->denumireCulori[i] = obiectCopie.denumireCulori[i];
		}
		this->denumireCulori[obiectCopie.nrCulori] = culoareNoua;
		return *this;
	}

	//op -=
	//stergem o culoare din paleta
	PaletaFarduri& operator-=(int pozitie) {
		PaletaFarduri obiectCopie(*this);
		if (this->denumireCulori != NULL) {
			delete[]this->denumireCulori;
		}
		this->nrCulori--;
		this->denumireCulori = new string[this->nrCulori];
		for (int i = 0; i < pozitie; i++) {
			this->denumireCulori[i] = obiectCopie.denumireCulori[i];
		}
		for (int i = pozitie + 1; i < obiectCopie.nrCulori; i++) {
			this->denumireCulori[i - 1] = obiectCopie.denumireCulori[i];
		}
		return*this;
	}

	//op cast
	//sa se calc pretul paletei fara adaos-ul standard adaugat al ambalajului de 1 leu
	operator float() {
		float pretFaraAmbalaj;
		pretFaraAmbalaj = this->pret - 1;
		return pretFaraAmbalaj;
	}

	//op ++ preincrementare
	//sa se mareasca pretul cu 1 u.m.
	PaletaFarduri& operator++() {
		this->pret++;
		return*this;
	}

	//op >>
	friend istream& operator>>(istream& in, PaletaFarduri& obj) {
		/*string numeBrand;
		float pret;
		const int anFabricatie;
		static int puncteBonus;
		int nrCulori;
		string* denumireCulori;*/
		if (obj.denumireCulori != NULL) {
			delete[]obj.denumireCulori;
		}
		cout << "Introduceti numele brandului: ";
		in >> obj.numeBrand;
		cout << "Introduceti pretul paletei: ";
		in >> obj.pret;
		cout << "Introduceti punctele bonus: ";
		in >> obj.puncteBonus;
		cout << "Introduceti nr culorilor din paleta: ";
		in >> obj.nrCulori;
		cout << "Introduceti nuantele culorilor din paleta: ";
		obj.denumireCulori = new string[obj.nrCulori];
		for (int i = 0; i < obj.nrCulori; i++) {
			in >> obj.denumireCulori[i];
		}
		return in;
	}
};
int PaletaFarduri::puncteBonus = 30;


//FUNCTIA MAIN

void main() {
	//cout << "---------RUJURI:------------" << endl << endl;
	Ruj r1;
	Ruj r2("NYX", 39.99, true);
	string culori3[] = { "Rosu", "Roz", "Mov", "Nude" };
	Ruj r3("Essence", 19.99, false, 2024, "Matt", 4, culori3);
	Ruj r4(r3);
	r1.setNumeBrand("YSL");
	r1.setPret(129.99);
	r1.setEsteWaterproof(1);
	r1.setCategorie("Cremos");
	string culori1[] = { "Roz", "Rosu", "Mov", "Nude", "Visiniu" };
	r1.setNuante(5, culori1);

	//vector ruj
	cout << "Introduceti elementele vectorului: " << endl;
	Ruj* vectorRuj = new Ruj[3];
	for (int i = 0; i < 3; i++) {
		cin >> vectorRuj[i];
	}
	for (int i = 0; i < 3; i++) {
		cout << vectorRuj[i];
	}
	delete[]vectorRuj;

	//matrice ruj
	cout << " Introduceti elementele matricei: " << endl;
	Ruj** matriceRuj = new Ruj*[2];
	for (int i = 0; i < 2; i++) {
		matriceRuj[i] = new Ruj[2];
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> matriceRuj[i][j];
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << matriceRuj[i][j];
		}
	}
	for (int i = 0; i < 2; i++) {
		delete[]matriceRuj[i];
	}
	delete[]matriceRuj;

	cout << endl << endl;

	//cout << "------------------PALETE DE FARDURI: ----------------------- " << endl << endl;
	PaletaFarduri p1;
	PaletaFarduri p2("NYX");
	string culoripaleta1[] = { "Roz","Mov","Portocaliu","Galben","Verde","Albastru","Negru","Gri" };
	PaletaFarduri p3("Too Faced", 249.99, 2024, 8, culoripaleta1);
	PaletaFarduri p4(p3);
	p4.setNumeBrand("Avon");
	p4.setPret(24.99);
	p4.setPuncteBonus(5);
	string culoripaleta4[] = { "Alb","Negru","Gri" };
	p4.setCulori(3, culoripaleta4);

	//vector paleta farduri
	cout << "Introduceti elementele vectorului: " << endl;
	PaletaFarduri* vectorPaleta = new PaletaFarduri[2];
	for (int i = 0; i < 2; i++) {
		cin >> vectorPaleta[i];
	}
	for (int i = 0; i < 2; i++) {
		cout << vectorPaleta[i];
	}
	delete[]vectorPaleta;


	//matrice paleta farduri
	cout << "Introduceti elementele matricei: " << endl;
	PaletaFarduri** matricePaleta = new PaletaFarduri * [2];
	for (int i = 0; i < 2; i++) {
		matricePaleta[i] = new PaletaFarduri[2];
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> matricePaleta[i][j];
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << matricePaleta[i][j];
		}
	}
	for (int i = 0; i < 2; i++) {
		delete[]matricePaleta[i];
	}
	delete[]matricePaleta;


	cout << endl << endl;
}