/*Modelirati rad biblioteke i članova koji posuđuju knjige.

Napraviti klase:
Knjiga – sadrži naziv, autora i godinu izdanja.
Clan – sadrži ime, prezime i listu posuđenih knjiga. Ima metodu za dodavanje više knjiga odjednom.
Biblioteka – sadrži ime i listu članova. Ima metodu StatistikaBiblioteke koja analizira više biblioteka i vraća:
	broj članova koji su posudili više od jedne knjige
	godinu izdanja najstarije posuđene knjige.

U main funkciji:
	kreirati nekoliko knjiga i članova
	dodati knjige članovima
	kreirati barem dvije biblioteke s različitim članovima
	pozvati funkciju StatistikaBiblioteke nad svim bibliotekama
	ispisati broj članova s više od jedne knjige i godinu najstarije posuđene knjige.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Knjiga {
public:
	string naziv;
	string autor;
	int god_izdanja;

	Knjiga(string _naziv, string _autor, int _godizdanja) : naziv(_naziv), autor(_autor), god_izdanja(_godizdanja) {};
};

class Clan {
public:
	string ime;
	string prezime;
	vector<Knjiga> posudeneknjige;

	Clan() {};

	Clan(string _ime, string _prezime) : ime(_ime), prezime(_prezime) {};

	void dodajKnjige(vector<Knjiga>knjige) {
		for (int i = 0; i < knjige.size(); i++) {
			posudeneknjige.push_back(knjige[i]);
		}
	}
};

class Biblioteka {
public:
	string ime;
	vector<Clan> clanovi;

	Biblioteka(string _ime, vector<Clan>_clanovi) :ime(_ime), clanovi(_clanovi) {};

	void StatistikaBiblioteke(const vector<Biblioteka> &biblioteke, int *vise, int *najstarija) {
		*najstarija = 3000;
		*vise = 0;
		for (int i = 0; i < biblioteke.size(); i++) {
			for (int j = 0; j < biblioteke[i].clanovi.size(); j++) {
				if (biblioteke[i].clanovi[j].posudeneknjige.size() > 1) {
					(*vise)++;
				}
				for (int u = 0; u < biblioteke[i].clanovi[j].posudeneknjige.size(); u++) {
					if (biblioteke[i].clanovi[j].posudeneknjige[u].god_izdanja < *najstarija) {
						*najstarija = biblioteke[i].clanovi[j].posudeneknjige[u].god_izdanja;
					}
				}
			}
		}

	}
};

int main() {
	int najstariji, vise;
	Clan clan1("Tina", "Pavlovic");
	Clan clan2("Leon", "Vincelj");
	vector<Knjiga> knjige = { Knjiga("Na Drini cuprija", "Ivo Andric", 1945), Knjiga("1984", "George Orwell", 1949) };
	vector<Knjiga> knjige2 = { Knjiga("Harry Potter", "J.L.Rowling", 1933) };
	clan1.dodajKnjige(knjige);
	clan2.dodajKnjige(knjige2);
	Biblioteka biblioteka1("HK Zagreb", vector<Clan>{clan1});
	Biblioteka biblioteka2("HK Krapina", vector<Clan>{clan2});
	biblioteka1.StatistikaBiblioteke(vector<Biblioteka>{biblioteka1, biblioteka2}, &vise, &najstariji);
	cout << "Vise knjiga je posudilo " << vise << " ljudi." << endl;
	cout << "Najstarija knjiga je iz " << najstariji << " godine." << endl;
	return 0;
}