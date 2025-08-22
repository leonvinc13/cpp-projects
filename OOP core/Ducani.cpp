/*
Potrebno je implementirati klasu Proizvod koja sadrži šifru i naziv proizvoda.
Naziv proizvoda uvijek se sprema velikim slovima.
Potrebno je implementirati get i set metode za obje varijable.

Zatim je potrebno implementirati klasu Ducan koja sadrži naziv, adresu i kolekciju proizvoda.
Klasa omogućuje dodavanje proizvoda preko metode dodajProizvod.
Potrebno je implementirati konstruktor, destruktor, konstruktor kopije, operator dodjele kopijom te operator dodjele prijenosom.
Kopiranje mora biti duboko, a operator prijenosa mora preuzeti vlasništvo nad resursima.
Potrebno je implementirati i metodu ispisi koja ispisuje podatke o dućanu i njegovim proizvodima.

U funkciji main demonstrirati rad svih funkcionalnosti.
*/

#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

class Proizvod {
private:
	string sifra, naziv;

public:
	Proizvod() = default;

	Proizvod(string _sifra, string _naziv) : sifra(_sifra), naziv(_naziv) {}

	void setNaziv(string _naziv) {
		for (int i = 0; i < _naziv.size(); i++) {
			_naziv[i] = toupper(_naziv[i]);
		}
		naziv = _naziv;
	}

	string getNaziv() const {
		return naziv;
	}

	void setSifra(string _sifra) {
		sifra = _sifra;
	}

	string getSifra() const {
		return sifra;
	}
};

class Ducan {
public:
	string naziv, adresa;
	vector<Proizvod*>proizvodi;

	void dodajProizvod(string sifra, string naziv) {
		Proizvod* p = new Proizvod();
		p->setNaziv(naziv);
		p->setSifra(sifra);
		proizvodi.push_back(p);
	}

	Ducan() = default;

	Ducan(string _naziv, string _adresa) : naziv(_naziv), adresa(_adresa) {}

	~Ducan(){
		for (int i = 0; i < proizvodi.size(); i++) {
			delete proizvodi[i];
		}
		proizvodi.clear();
	}

	Ducan(const Ducan& d) {
		for (int i = 0; i < d.proizvodi.size(); i++) {
			proizvodi.push_back(new Proizvod);
			*proizvodi[i] = *d.proizvodi[i];
		}
		naziv = d.naziv;
		adresa = d.adresa;
	}

	Ducan& operator = (const Ducan& d) {
		if (this != &d) {
			for (int i = 0; i < proizvodi.size(); i++) {
				delete proizvodi[i];
			}
			proizvodi.clear();
			for (int i = 0; i < d.proizvodi.size(); i++) {
				proizvodi.push_back(new Proizvod);
				*proizvodi[i] = *d.proizvodi[i];
			}
			naziv = d.naziv;
			adresa = d.adresa;
		}
		return *this;
	}

	Ducan& operator = (Ducan &&privremeni){
		for (int i = 0; i < proizvodi.size(); i++) {
			delete proizvodi[i];
		}
		proizvodi.clear();
		for (int i = 0; i < privremeni.proizvodi.size(); i++) {
			proizvodi.push_back(privremeni.proizvodi[i]);
			privremeni.proizvodi[i] = nullptr;
		}
		privremeni.proizvodi.clear();
		naziv = privremeni.naziv;
		adresa = privremeni.adresa;
		return *this;
	}

	void ispisi() const {
		cout << "Ducan: " << naziv << ", " << adresa << endl;
		for (auto p : proizvodi) {
			cout << " - [" << p->getSifra() << "] " << p->getNaziv() << endl;
		}
	}
};

int main()
{
	Ducan d1("Konzum", "Zagreb, Ilica 1");
	d1.dodajProizvod("101", "mlijeko");
	d1.dodajProizvod("102", "kruh");

	Ducan d2 = d1;
	d2.dodajProizvod("103", "voda");

	cout << "--- d1 ---" << endl;
	d1.ispisi();
	cout << "--- d2 (kopija d1 + dodan 1 proizvod) ---" << endl;
	d2.ispisi();

	Ducan d3("Plodine", "Split, Riva 10");
	d3 = d1;
	cout << "--- d3 (operator= duboko kopiranje d1) ---" << endl;
	d3.ispisi();

	Ducan d4("Tommy", "Osijek, Europska avenija 5");
	d4 = Ducan("Lidl", "Rijeka, Korzo 15");
	d4.dodajProizvod("104", "sok");

	cout << "--- d4 (move operator) ---" << endl;
	d4.ispisi();
	return 0;
}


