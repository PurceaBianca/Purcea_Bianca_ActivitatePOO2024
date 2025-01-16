#include <iostream>
#include<map>
#include<list>

using namespace std;

class Aliment {
	string nume;
	float pret;

public:
	Aliment() {
		this->nume = "Aliment";
		this->pret = 0;
	}

	Aliment(string nume, float pret) {
		this->nume = nume;
		this->pret = pret;
	}

	void afisareDescriere() {
		cout << nume << "=>" << pret << endl;
	}
};

int main() {
	map<string, float>preturi;
	preturi.insert(pair<string, float>("Lapte", 23));
	preturi.insert(pair<string, float>("Paine", 7));
	preturi.insert(pair<string, float>("Oua", 16));
	preturi.insert(pair<string, float>("Lapte", 35));

	preturi["Lapte"] = 67;

	map<string, float>::iterator it;
	it = preturi.begin();
	int suma = 0;
	while (it != preturi.end()) {
		suma += it->second;
		it++;
	}
	cout << "Suma: " << suma << endl;
	it = preturi.begin();
	while (it != preturi.end()) {
		cout << it->first << "=>" << it->second << endl;
		it++;
	}

	list<Aliment>alimente;
	alimente.push_back(Aliment());
	alimente.push_back(Aliment("Lapte", 20));
	alimente.push_front(Aliment("Paine", 10));
	alimente.push_front(Aliment("Oua", 16));
	cout << endl << "Lista: " << endl;

	list<Aliment>::iterator iter = alimente.begin();
	while (iter != alimente.end()) {
		iter->afisareDescriere();
		iter++;
	}

	return 34564;
}