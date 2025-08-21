/*
Potrebno je modelirati rad studija i smjerova. Klasa Student sadrži ime, prezime i broj položenih ispita. Klasa Smjer sadrži naziv i listu studenata te metode za dodavanje jednog ili više studenata. Klasa Studij sadrži naziv i listu smjerova te metodu za sortiranje smjerova prema broju studenata (ako je broj jednak, sortira se po nazivu). Potrebno je implementirati funkciju AnalizaStudija koja računa prosječan broj položenih ispita svih studenata te pronalazi studij s najviše smjerova. U glavnom programu kreirati nekoliko studenata, smjerova i studija, izvršiti sortiranje i ispisati rezultate analize.
*/

#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

class Student {
public:
	string ime, prezime;
	int broj_polozenih_ispita;

	Student(string _ime, string _prezime, int _broj) : ime(_ime), prezime(_prezime), broj_polozenih_ispita(_broj) {};
};

class Smjer {
public:
	string naziv;
	vector <Student> studenti;

	Smjer() = default;

	void DodajStudenta1(Student s);

	void DodajStudenta2(const vector<Student>& _s);
};

bool usporedba(Smjer s1, Smjer s2) {
	if (s1.studenti.size() != s2.studenti.size())
		return s1.studenti.size() > s2.studenti.size(); 
	else return s1.naziv < s2.naziv; 
}

class Studij {
public:
	string naziv;
	vector <Smjer> smjerovi;

	void SortirajSmjerove() {
		sort(smjerovi.begin(), smjerovi.end(), usporedba);
	}
};

void Smjer::DodajStudenta1(Student s) {
	studenti.push_back(s);
}

void Smjer::DodajStudenta2(const vector<Student>&_s) {
	for (int i = 0; i < _s.size(); i++) {
		this->studenti.push_back(_s[i]);
	}
}

void AnalizaStudija(const vector<Studij>& _studiji, double *prosjek, string &najvise) {
	int suma = 0, br = 0;
	int max = 0;
	for (int i = 0; i < _studiji.size(); i++) {
		if (_studiji[i].smjerovi.size() > max) {
			max = _studiji[i].smjerovi.size();
			najvise = _studiji[i].naziv;
		}
		for (int j = 0; j < _studiji[i].smjerovi.size(); j++) {
			for (int k = 0; k < _studiji[i].smjerovi[j].studenti.size();k++) {
				suma += _studiji[i].smjerovi[j].studenti[k].broj_polozenih_ispita;
				br++;
			}
		}
	}
	*prosjek = suma / br;
}

int main()
{
	Smjer smjer;
	Smjer smjer2;
	smjer.naziv = "TVZ";
	smjer2.naziv = "FER";
	smjer.DodajStudenta1(Student("Ante", "Antic", 5));
	vector <Student> studenti = { Student("Ante", "Antic", 5), Student("Ana", "Anic", 8) };
	smjer2.DodajStudenta2(studenti);
	Smjer smjer3;
	smjer3.naziv = "Takav faks";
	smjer3.DodajStudenta2(studenti);
	Studij studij;
	studij.naziv = "Tehnicki studij";
	studij.smjerovi.push_back(smjer);
	studij.smjerovi.push_back(smjer2);
	studij.smjerovi.push_back(smjer3);
	Studij studij2;
	studij2.naziv = "Medicina";
	studij2.smjerovi = { smjer , smjer2 };
	vector<Studij>studiji = { studij, studij2 };
	// Sortiranje i ispis
	studij.SortirajSmjerove();

	cout << "Sortirani smjerovi:" << endl;
	for (int i = 0;i<studij.smjerovi.size();i++) {
		cout << studij.smjerovi[i].naziv << " - Broj studenata: " <<studij.smjerovi[i].studenti.size() << endl;
	}
	string najvise_smjerova;
	double prosjek;
	AnalizaStudija(studiji, &prosjek, najvise_smjerova);
	cout << "Prosjke polozenih ispita studenata je " << prosjek << endl;
	cout << "Najvise smjerova ima " << najvise_smjerova;
    return 0;
}


