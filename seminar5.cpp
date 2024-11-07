#include<iostream>

using namespace std;

class Cofetarie {
private:
	string nume;//
	int nrAngajati;//
	float* salarii;
	bool esteVegana;
	const int anDeschidere;
	float adaos;
	static int TVA;

public:
	Cofetarie() : adaos(30), anDeschidere(2024)
	{
		this->nume = "Delice";
		this->nrAngajati = 0;
		this->salarii = NULL;
		this->esteVegana = true;
		//this->anDeschidere = 2024;
	}
	Cofetarie(string nume, int nrAngajati, bool vegan, int an, float adaos) :anDeschidere(an) {
		this->nume = nume;
		this->nrAngajati = nrAngajati;
		this->esteVegana = vegan;
		this->adaos = adaos;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = 1000 + i * 100;
		}

	}

	Cofetarie(const Cofetarie& c) :anDeschidere(c.anDeschidere) {
		this->nume = c.nume;
		this->nrAngajati = c.nrAngajati;
		this->salarii = new float[c.nrAngajati];
		for (int i = 0; i < c.nrAngajati; i++) {
			this->salarii[i] = c.salarii[i];
		}
		this->esteVegana = c.esteVegana;
		this->adaos = c.adaos;
	}

	~Cofetarie() { //destructor
		if (this->salarii != NULL) {
			delete[]this->salarii;
		}
	}

	string getNume() {
		return this->nume;
	}

	void setNume(string nume) {
		if (nume.length() > 2) {
			this->nume = nume;
		}
	}

	int getNrAngajati() {
		return this->nrAngajati;
	}

	void setNrAngajati(int nrAngajati, float* salarii) {
		if (nrAngajati > 0) {
			this->nrAngajati = nrAngajati;
			if (this->salarii != NULL) {
				delete[]this->salarii;
			}
			this->salarii = new float[this->nrAngajati];
			for (int i = 0; i < this->nrAngajati; i++) {
				this->salarii[i] = salarii[i];
			}
		}
	}

	float* getSalarii() {
		return this->salarii;
	}

	float getSalariu(int index) {
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
	}

	void afisare() {
		cout << "Nume: " << this->nume << endl;
		cout << "Nr angajati: " << this->nrAngajati << endl;
		cout << "Are produse vegane? " << (this->esteVegana ? "DA" : "NU") << endl;
		cout << "An deschidere: " << this->anDeschidere << endl;
		cout << "Adaos: " << this->adaos << endl;
		cout << "TVA: " << this->TVA << endl << endl;
	}

	static void modificaTVA(int noulTVA) {
		if (noulTVA > 0) {
			Cofetarie::TVA = noulTVA;
		}
	}

	static int calculeazaNrTotalAngajati(int nrCofetarii, Cofetarie* vector) {
		int suma = 0;
		for (int i = 0; i < nrCofetarii; i++) {
			suma += vector[i].nrAngajati;
		}
		return suma;
	}

	Cofetarie operator=(const Cofetarie& c) {
		if (&c != this) {
			if (this->salarii != NULL) {
				delete[]this->salarii;
			}
			this->salarii = new float[this->nrAngajati];
			for (int i = 0; i < this->nrAngajati; i++) {
				this->salarii[i] = salarii[i];
			}
			this->nume = c.nume;
			this->nrAngajati = c.nrAngajati;
			this->esteVegana = c.esteVegana;
			this->adaos = c.adaos;
		}
		return *this; //obiectul de la adresa lui this
	}

	/*Cofetarie operator+(const Cofetarie& c)const {
		Cofetarie temp = *this;
		temp.nrAngajati=this->nrAngajati+c.nrAngajati;
		float*aux=new float[temp.nrAngajati]
		return temp;
	}*/

	//Cofetarie operator+(float valoare)const {
	//	Cofetarie temp = *this;
	//	for (int i = 0; i < this->nrAngajati; i++) {
	//		this->salarii[i] = salarii[i];
	//	}
	//		return temp;
	//}

	friend Cofetarie operator+(float valoare, const Cofetarie& c);
};

int Cofetarie::TVA = 9;

//Cofetarie operator+(float valoare, const Cofetarie& c) {
//	Cofetarie cofetarie = c;
//	cofetarie.salarii = valoare + c.salarii;
//	return cofetarie;
//}

void f(Cofetarie c) {

}

int main() {
	Cofetarie c;
	cout << c.getNume() << endl;
	c.setNume("");
	cout << c.getNume() << endl;
	c.setNume("alt nume");
	cout << c.getNume() << endl;
	c.setNrAngajati(4, new float[4] {2, 6, 4, 9});

	Cofetarie c2("Minimal", 3, false, 2020, 10);
	cout << c2.getSalarii()[1] << endl;
	cout << c2.getSalariu(1) << endl;

	c2.setNrAngajati(5, new float[5] {1, 2, 3, 4, 5});//de ce nu e recomandat?
	cout << c2.getSalariu(3);
	//Este recomandat sa folosim inline doar la declararea functiei, nu si la apel, pentru ca multe compilatoare
	//modifica, in mod implicit codul, generand cod inline atunci cand considera ca pot astfel sa oprimizeze.

	Cofetarie c3(c2); //construiesc c3 pe baza obiectului existent c2
	Cofetarie c4 = c2;

	c4 = c2;
	c4.operator=(c2);

	//c4 = c2 + c3;
	//c4.operatr = (c2.operator+(c3));

	//tip returnat -> cofetarie
	//nume -> operator = 
	//lista de param->this,un obiect de tipul clasei

	//c4 += c2;
	//c4.operator+=(c2);

	//c4 = c2 + 5000.0f;//cum vede comp: m2.operator+(5000.0f);

	//c4 = 5000.0f + c2;// operator+(5000.0f



}