/*
Napišite apstraktnu klasu Osoba s atributima ime, prezime i osnovica plaće, s apstraktnim metodama izracunPlace() i ispis(), te virtualnim destruktorom. Izvedite klase Igrac i Trener.

Klasa Igrac treba imati dodatne atribute za broj golova i asistencija, metode za njihovo dodavanje, implementaciju izracunPlace() koja računa bonus prema golovima i asistencijama, te ispis() koji ispisuje podatke igrača.

Klasa Trener treba imati atribute za pobjede, remije i poraze, metode za dodavanje rezultata, implementaciju izracunPlace() koja računa bonus ili kaznu prema rezultatima te ispis() koji prikazuje omjer (W/D/L).

U glavnom programu kreirajte nekoliko objekata tipa Igrac i Trener, dodajte rezultate, pozovite metode ispis() i izracunPlace(), i prikažite informacije o njihovim plaćama.
*/

#include <iostream>

using namespace std;

class Osoba {
protected:
	string ime;
	string prezime;
	double osnovica;
public:
	Osoba(string ime, string prezime, double osnovica)
		: ime(ime), prezime(prezime), osnovica(osnovica) {}

	virtual double izracunPlace() = 0;  

	virtual void ispis() const = 0;     

	virtual ~Osoba() {}
};

class Igrac :public Osoba {
private:
	int golovi;
	int asistencije;
public:
	Igrac(string ime, string prezime, double osnovica)
		: Osoba(ime, prezime, osnovica), golovi(0), asistencije(0) {}

	void dodajGolove(int brojGolova) {
		golovi += brojGolova;
	}

	void dodajAsistencije(int brojAsistencija) {
		asistencije += brojAsistencija;
	}

	double izracunPlace() override {
		double bonus = 0;
		bonus += (golovi / 10) * 0.1 * osnovica;  
		bonus += (asistencije / 5) * 0.1 * osnovica;  
		return osnovica + bonus;
	}

	void ispis() const override {
		cout << ime << " " << prezime << " - Golova: " << golovi << ", Asistencija: " << asistencije << endl;
	}
};

class Trener : public Osoba {
private:
	int pobjede;
	int remiji;
	int porazi;
public:
	Trener(string ime, string prezime, double osnovica)
		: Osoba(ime, prezime, osnovica), pobjede(0), remiji(0), porazi(0) {}

	void dodajPobjede(int brojPobjeda) {
		pobjede += brojPobjeda;
	}

	void dodajRemi(int brojRemija) {
		remiji += brojRemija;
	}

	void dodajIzgubljene(int brojPoraza) {
		porazi += brojPoraza;
	}

	double izracunPlace() override {
		double bonus = 0;
		bonus += (pobjede / 5) * 0.1 * osnovica;  
		bonus += (remiji / 10) * 0.1 * osnovica;  
		bonus -= (porazi / 8) * 0.1 * osnovica; 
		return osnovica + bonus;
	}

	void ispis() const override {
		cout << ime << " " << prezime << " - Omjer (W/D/L): " << pobjede << " / " << remiji << " / " << porazi << endl;
	}
};

int main()
{
	Igrac i("Luka", "Modric", 100000); //Ime, prezime, osnovica plaće
	i.dodajGolove(7);
	i.dodajAsistencije(12);
	i.ispis(); //Luka Modric - golova: 7, asistencija: 12
	cout << "Placa: " << i.izracunPlace() << endl; //Placa: 120000

	Igrac i2("C", "Ronaldo", 234505);
	i2.dodajGolove(57);
	i2.dodajAsistencije(32);
	i2.ispis(); //C Ronaldo - Golova : 57, Asistencije : 32.
	cout << "Placa: " << i2.izracunPlace() << endl; //Placa : 492461

	Trener t1("Hose", "Murinjo", 143009); //Ime, prezime, osnovica plaće
	t1.dodajPobjede(88); //Dodati broj pobjeda (W)
	t1.dodajRemi(12); //Dodati broj neriješenih utakmica (D)
	t1.dodajIzgubljene(0); //Dodati broj izgubljenih (L)
	t1.ispis(); //Hose Murinjo - Omjer (W/D/L): 88 / 12 / 0
	cout << "Placa: " << t1.izracunPlace() << endl; //Placa: 400425

	t1.dodajPobjede(11);
	t1.dodajIzgubljene(47);
	t1.ispis(); //Hose Murinjo - Omjer (W/D/L): 99 / 12 / 47
	cout << "Placa: " << t1.izracunPlace() << endl; //Placa: 357523
	return 0;
}

