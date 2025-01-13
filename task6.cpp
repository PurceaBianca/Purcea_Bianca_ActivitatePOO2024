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

//RELATIA HAS-A 
class Sephora {
	string adresa;
	int nrRujuri;
	Ruj* vectorRujuri;
	int nrPaleteFarduri;
	PaletaFarduri* vectorPaleteFarduri;

public:
	Sephora() {
		this->adresa = "Necunoscuta";
		this->nrRujuri = 0;
		this->vectorRujuri = NULL;
		this->nrPaleteFarduri = 0;
		this->vectorPaleteFarduri = NULL;
	}

	Sephora(string adresa, int nrRujuri, Ruj* vectorRujuri, int nrPaleteFarduri, PaletaFarduri* vectorPaleteFarduri) {
		this->adresa = adresa;
		this->nrRujuri = nrRujuri;
		this->vectorRujuri = new Ruj[this->nrRujuri];
		for (int i = 0; i < this->nrRujuri; i++) {
			this->vectorRujuri[i] = vectorRujuri[i];
		}
		this->nrPaleteFarduri = nrPaleteFarduri;
		this->vectorPaleteFarduri = new PaletaFarduri[this->nrPaleteFarduri];
		for (int i = 0; i < this->nrPaleteFarduri; i++) {
			this->vectorPaleteFarduri[i] = vectorPaleteFarduri[i];
		}
	}

	string getAdresa() {
		return this->adresa;
	}
	int getNrRujuri() {
		return this->nrRujuri;
	}
	Ruj* getVectorRujuri() {
		return this->vectorRujuri;
	}
	int getNrPaleteFarduri() {
		return this->nrPaleteFarduri;
	}
	PaletaFarduri* getVectorPaleteFarduri() {
		return this->vectorPaleteFarduri;
	}

	void setAdresa(string adresaNoua) {
		this->adresa = adresaNoua;
	}
	void setRujuri(int nrNouRujuri, Ruj* vectorNouRujuri) {
		if (this->vectorRujuri != NULL) {
			delete[]this->vectorRujuri;
		}
		this->nrRujuri = nrNouRujuri;
		this->vectorRujuri = new Ruj[this->nrRujuri];
		for (int i = 0; i < this->nrRujuri; i++) {
			this->vectorRujuri[i] = vectorNouRujuri[i];
		}
	}
	void setPalete(int nrNouPaleteFarduri, PaletaFarduri* vectorNouPaleteFarduri) {
		if (this->vectorPaleteFarduri != NULL) {
			delete[]this->vectorPaleteFarduri;
		}
		this->nrPaleteFarduri = nrNouPaleteFarduri;
		this->vectorPaleteFarduri = new PaletaFarduri[this->nrPaleteFarduri];
		for (int i = 0; i < this->nrPaleteFarduri; i++) {
			this->vectorPaleteFarduri[i] = vectorNouPaleteFarduri[i];
		}
	}

	Sephora(const Sephora& obj) {
		this->adresa = obj.adresa;
		this->nrRujuri = obj.nrRujuri;
		this->vectorRujuri = new Ruj[this->nrRujuri];
		for (int i = 0; i < this->nrRujuri; i++) {
			this->vectorRujuri[i] = obj.vectorRujuri[i];
		}
		this->nrPaleteFarduri = obj.nrPaleteFarduri;
		this->vectorPaleteFarduri = new PaletaFarduri[this->nrPaleteFarduri];
		for (int i = 0; i < this->nrPaleteFarduri; i++) {
			this->vectorPaleteFarduri[i] = obj.vectorPaleteFarduri[i];
		}
	}

	Sephora& operator=(const Sephora& obj) {
		if (this != &obj) {
			if (this->vectorRujuri != NULL) {
				delete[]this->vectorRujuri;
			}
			if (this->vectorPaleteFarduri != NULL) {
				delete[]this->vectorPaleteFarduri;
			}
			this->adresa = obj.adresa;
			this->nrRujuri = obj.nrRujuri;
			this->vectorRujuri = new Ruj[this->nrRujuri];
			for (int i = 0; i < this->nrRujuri; i++) {
				this->vectorRujuri[i] = obj.vectorRujuri[i];
			}
			this->nrPaleteFarduri = obj.nrPaleteFarduri;
			this->vectorPaleteFarduri = new PaletaFarduri[this->nrPaleteFarduri];
			for (int i = 0; i < this->nrPaleteFarduri; i++) {
				this->vectorPaleteFarduri[i] = obj.vectorPaleteFarduri[i];
			}
		}
		return*this;
	}

	~Sephora() {
		if (this->vectorRujuri != NULL) {
			delete[]this->vectorRujuri;
		}
		if (this->vectorPaleteFarduri != NULL) {
			delete[]this->vectorPaleteFarduri;
		}
	}

	//operator <<
	friend ostream& operator<<(ostream& out,const Sephora& obj) {
		out << "Adresa: " << obj.adresa<<endl;
		out << "Nr rujuri: " << obj.nrRujuri<<endl;
		out << "Rujuri: " << endl;
		for (int i = 0; i < obj.nrRujuri; i++) {
			out << obj.vectorRujuri[i]<<endl;
		}
		out << "Nr palete farduri: " << obj.nrPaleteFarduri << endl;
		for (int i = 0; i < obj.nrPaleteFarduri; i++) {
			out << obj.vectorPaleteFarduri[i] << endl;
		}
		return out;
	}

	//operator -= 
	//eliminam un ruj
	Sephora& operator-=(int pozitie) {
		Sephora copie=*this;
		if (this->vectorRujuri != NULL) {
			delete[]this->vectorRujuri;
		}
		this->nrRujuri--;
		this->vectorRujuri = new Ruj[this->nrRujuri];
		for (int i = 0; i < pozitie; i++) {
			this->vectorRujuri[i] = copie.vectorRujuri[i];
		}
		for (int i = pozitie + 1; i < copie.nrRujuri; i++) {
			this->vectorRujuri[i - 1] = copie.vectorRujuri[i];
		}
		return*this;
	}

	//operator>>
	friend istream& operator>>(istream& in, Sephora& obj) {
		if (obj.vectorRujuri != NULL) {
			delete[]obj.vectorRujuri;
		}
		if (obj.vectorPaleteFarduri != NULL) {
			delete[]obj.vectorPaleteFarduri;
		}
		cout << "Adresa: "<<endl;
		in >> obj.adresa;
		cout << "Nr rujuri: " << endl;
		in >> obj.nrRujuri;
		obj.vectorRujuri = new Ruj[obj.nrRujuri];
		cout << "Rujuri: " << endl;
		for (int i = 0; i < obj.nrRujuri; i++) {
			in >> obj.vectorRujuri[i];
		}
		cout << endl;
		cout << "Nr palete: " << endl;
		in >> obj.nrPaleteFarduri;
		obj.vectorPaleteFarduri = new PaletaFarduri[obj.nrPaleteFarduri];
		cout << "palete farduri: " << endl;
		for (int i = 0; i < obj.nrPaleteFarduri; i++) {
			in >> obj.vectorPaleteFarduri[i];
		}
		cout << endl;
		return in;
	}
};


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

	//cout<< " ------------- SEPHORA ---------------------- " <<endl<<endl;
	Sephora s1;
	cout << "Adresa: " << s1.getAdresa() << endl;
	cout << "Nr rujuri: " << s1.getNrRujuri() << endl;
	cout << "Rujuri: " << endl;
	for (int i = 0; i < s1.getNrRujuri(); i++) {
		cout << s1.getVectorRujuri()[i] << endl<<endl;
	}
	cout << "Nr palete farduri: " << s1.getNrPaleteFarduri()<<endl;
	cout << "Palete Farduri: " << endl;
	for (int i = 0; i < s1.getNrPaleteFarduri(); i++) {
		cout << s1.getVectorPaleteFarduri()[i] << endl << endl;
	}
	cout << endl << endl;

	Ruj vectorRujuri2[] = { r2,r3 };
	PaletaFarduri vectorPalete2[] = { p2,p3 };
	Sephora s2("Bucuresti Afi Palace Cotroceni", 2, vectorRujuri2, 2, vectorPalete2);
	cout << "Adresa: " << s2.getAdresa() << endl;
	cout << "Nr rujuri: " << s2.getNrRujuri() << endl;
	cout << "Rujuri: " << endl;
	for (int i = 0; i < s2.getNrRujuri(); i++) {
		cout << s2.getVectorRujuri()[i] << endl << endl;
	}
	cout << "Nr palete farduri: " << s2.getNrPaleteFarduri()<<endl;
	cout << "Palete Farduri: " << endl;
	for (int i = 0; i < s2.getNrPaleteFarduri(); i++) {
		cout << s2.getVectorPaleteFarduri()[i] << endl << endl;
	}

	cout << "----------------------SETTERI : ---------------- " << endl;
	s1.setAdresa("Bucuresti ParkLake");
	Ruj vectorRujuri1[] = { r1, r2, r3 };
	PaletaFarduri vectorPalete1[] = { p1,p2,p3 };
	s1.setRujuri(3, vectorRujuri1);
	s1.setPalete(3, vectorPalete1);
	cout << "Adresa: " << s1.getAdresa() << endl;
	cout << "Nr rujuri: " << s1.getNrRujuri() << endl;
	cout << "Rujuri: " << endl;
	for (int i = 0; i < s1.getNrRujuri(); i++) {
		cout << s1.getVectorRujuri()[i] << endl << endl;
	}
	cout << "Nr palete farduri: " << s1.getNrPaleteFarduri() << endl;
	cout << "Palete Farduri: " << endl;
	for (int i = 0; i < s1.getNrPaleteFarduri(); i++) {
		cout << s1.getVectorPaleteFarduri()[i] << endl << endl;
	}
	cout << endl << endl;

	cout << " ------------------ constructorul de copiere ------------" << endl;
	Sephora s3(s1);
	cout << "Obiectul nou creat: " << endl;
	cout << "Adresa: " << s3.getAdresa() << endl;
	cout << "Nr rujuri: " << s3.getNrRujuri() << endl;
	cout << "Rujuri: " << endl;
	for (int i = 0; i < s3.getNrRujuri(); i++) {
		cout << s3.getVectorRujuri()[i] << endl << endl;
	}
	cout << "Nr palete farduri: " << s3.getNrPaleteFarduri() << endl;
	cout << "Palete Farduri: " << endl;
	for (int i = 0; i < s3.getNrPaleteFarduri(); i++) {
		cout << s3.getVectorPaleteFarduri()[i] << endl << endl;
	}
	cout << endl << endl;

	cout << "---------------- operatorul = ------------------------ " << endl;
	s2 = s3;
	cout << " OBIECTUL S2 NOU MODIFICAT DUPA S3: " << endl;
	cout << "Adresa: " << s2.getAdresa() << endl;
	cout << "Nr rujuri: " << s2.getNrRujuri() << endl;
	cout << "Rujuri: " << endl;
	for (int i = 0; i < s2.getNrRujuri(); i++) {
		cout << s2.getVectorRujuri()[i] << endl << endl;
	}
	cout << "Nr palete farduri: " << s2.getNrPaleteFarduri() << endl;
	cout << "Palete Farduri: " << endl;
	for (int i = 0; i < s2.getNrPaleteFarduri(); i++) {
		cout << s2.getVectorPaleteFarduri()[i] << endl << endl;
	}

	//op <<
	cout << s1;

	//op -=
	cout << (s1 -= 2);

	//op >>
	cin >> s1;
}