#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <string>

/*Potrebno je napisati program za praæenje bodovnog stanja studenata na odreðenom kolegiju.
Slijedeæi programski odsjeèak u nastavku napišite sve potrebne klase i metode kojima se dobije oèekivano ponašanje programskog koda.
*/
using namespace std;

class Student {
public:
	string ime;
	string jmbag;

	Student(string _ime, string _jmbag) : ime(_ime), jmbag(_jmbag) {};
};

class Bodovi {
public:
	Student student;
	int bod;

	Bodovi(Student _student, int _bod) : student(_student), bod(_bod) {};
};

class Kolegij {
public:
	string naziv;
	vector<Bodovi> OOPBodovi;

	Kolegij(string _naziv, vector<Bodovi> _OOPBodovi) : naziv(_naziv), OOPBodovi(_OOPBodovi) {};

};

bool usporedba(Bodovi a, Bodovi b) {
	return a.bod < b.bod;
}

int main() {
	vector<Bodovi> OOPBodovi{
		Bodovi(Student("Ivana Ivic", "0246002475"), 25),
		Bodovi(Student("Ivica Ivanovic", "0246005654"), 20),
		Bodovi(Student("Marko Markic", "0246004234"), 32)
	};
	Kolegij OOP("Objektno orijentirano programiranje", OOPBodovi);
	sort(OOPBodovi.begin(), OOPBodovi.end(), usporedba);
	for (int i = 0; i < OOPBodovi.size(); i++) {
		cout << OOPBodovi[i].student.ime << "\t" << OOPBodovi[i].student.jmbag << "\t" << OOPBodovi[i].bod << endl;
	}
	/* Ispišite bodove svih studenata na ‘OOP’ kolegiju sortirane po broju bodova Npr.;
	   Ivica Ivanovic  0246005654      20
	   Ivana Ivic      0246002475      25
	   Marko Markic    0246004234      32 */
	return 0;
}



