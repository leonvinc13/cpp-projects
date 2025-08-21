/*
Modelirati život u stambenim zgradama.
Napraviti klase Stanar, Stan i Zgrada: 
Stanar sadrži ime i starost.
Stan sadrži broj stana i listu stanara, te metodu za dodavanje novih stanara.
Zgrada sadrži adresu i listu stanova.
Implementirati funkciju AnalizaZgrada koja prima listu zgrada i preko pokazivača vraća:
broj stanova u kojima živi samo jedan stanar (samci)
starost najstarijeg stanara u svim zgradama.
U main funkciji:
kreirati nekoliko stanara i stanova
složiti ih u jednu ili više zgrada
pozvati funkciju AnalizaZgrada i ispisati rezultate.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>

using namespace std;

class Stanar {
public:
    string ime;
    int starost;

    Stanar(string _ime, int _starost) : ime(_ime), starost(_starost) {}
};

class Stan {
public:
    int broj;
    vector<Stanar> stanari;

    Stan() {}
    Stan(int _broj, vector<Stanar> _stanari) : broj(_broj), stanari(_stanari) {}

    void DodajStanare(vector<Stanar> _stanari);
};

void Stan::DodajStanare(vector<Stanar> _stanari) {
    for (int i = 0; i < _stanari.size(); i++) {
        stanari.push_back(_stanari[i]);
    }
}

class Zgrada {
public:
    string adresa;
    vector<Stan> stanovi;

    Zgrada(string _adresa, vector<Stan> _stanovi) : adresa(_adresa), stanovi(_stanovi) {}
};

void AnalizaZgrada(vector <Zgrada> zgrade, int* samci, int* najstariji) {
    *najstariji = 0;
    *samci = 0;
    int max = 0;
    for (int i = 0; i < zgrade.size(); i++) {
        for (int j = 0; j < zgrade[i].stanovi.size(); j++) {
            if (zgrade[i].stanovi[j].stanari.size() == 1) {
                (*samci)++;
            }
            for (int k = 0; k < zgrade[i].stanovi[j].stanari.size(); k++) {
                if (zgrade[i].stanovi[j].stanari[k].starost > *najstariji) {
                    *najstariji = zgrade[i].stanovi[j].stanari[k].starost;
                }
            }
        }
    }
}

int main() {
    // Kreiramo stan
    Stan stan1(1, { Stanar("Ante", 30), Stanar("Ivica", 25) });
    Stan stan2(2, { Stanar("Leon Vincelj", 19) }); // Samac

    // Kreiramo zgradu
    Zgrada zgrada1("Ravninsko 118", { stan1, stan2 });

    // Zgrada vektor
    vector<Zgrada> zgrade = { zgrada1 };

    // Analiza
    int samci = 0, najstariji = 0;
    AnalizaZgrada(zgrade, &samci, &najstariji);

    cout << "Broj stanova sa samcima: " << samci << endl;
    cout << "Najstariji stanar ima: " << najstariji << " godina" << endl;

    return 0;
}
