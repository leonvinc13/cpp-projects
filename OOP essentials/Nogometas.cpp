/*
U ovom zadatku potrebno je izraditi program u programskom jeziku C++ koji simulira sustav za praćenje nogometaša, utakmica i klubova. Program se temelji na objektno orijentiranom pristupu te koristi više povezanih klasa.

Potrebno je implementirati klasu Nogometaš koja sadrži podatke o imenu, godini rođenja i broju golova. Klasa treba sadržavati konstruktore, destruktor, set i get metode, statičke varijable za praćenje ukupnog broja nogometaša i golova te metode za računanje prosjeka postignutih golova.

Zatim se izrađuje klasa Utakmica koja čuva podatke o datumu, protivniku i broju postignutih golova. Klasa treba omogućiti dodavanje golova te vraćanje reference na objekt.

Treća klasa je Klub, koja sadrži listu utakmica i listu nogometaša. Potrebno je implementirati konstruktor, destruktor, copy konstruktor, move konstruktor, operator dodjele, kao i metode za dodavanje utakmica i nogometaša u klub.

Na razini cijelog programa implementira se funkcija usporedba koja omogućuje sortiranje nogometaša prema broju golova. U glavnom programu (main) potrebno je kreirati nekoliko utakmica i nogometaša, dodati ih u klub te ispisati sortiranu listu nogometaša.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Utakmica {
public:
    string datum, protivnik;
    Utakmica(string _datum, string _protivnik) :datum(_datum), protivnik(_protivnik) {}
};

class Nogometas {
private:
    string ime;
    int god_rod, golovi;
public:
    vector<Utakmica>utakmice;
    static int broj_nogometasa;
    static int broj_golova;

    void setIme(string _ime) {
        ime = _ime;
    }
    void setGodina(int _god) {
        if (_god >= 1977 && _god <= 2006) {
            god_rod = _god;
        }
        else cout << "Netočna godina";
    }
    void setGolovi(int _golovi) {
        golovi = _golovi;
    }

    string getIme() {
        return ime;
    }
    int getGodina() {
        return god_rod;
    }
    int getGolovi() {
        return golovi;
    }

    Nogometas() = default;

    Nogometas(string _ime, int _godina, int _golovi) : ime(_ime), god_rod(_godina), golovi(_golovi) {
        broj_nogometasa++;
        broj_golova += _golovi;
    }

    Nogometas(string _ime, int _godina, int _golovi, const vector<Utakmica> &_utakmice)
        : ime(_ime), god_rod(_godina), golovi(_golovi), utakmice(_utakmice) {
        broj_nogometasa++;
        broj_golova += _golovi;
    }

    static double prosjekPostignutihGolova() {
        return (double)broj_golova / broj_nogometasa;
    }

    Nogometas& dodaj(Utakmica utakmica) {
        utakmice.push_back(utakmica);
        return *this;
    }

    void dodaj2(const vector<Utakmica>& _utakmice) {
        for (int i = 0; i < _utakmice.size(); i++) {
            utakmice.push_back(_utakmice[i]);
        }
    }
};

namespace HNL {
    class  Klub {
    public:
        vector<Nogometas*>nogometasi;

        Klub() = default;

        ~Klub() {
            for (int i = 0; i < nogometasi.size(); i++) {
                delete nogometasi[i];
            }
            nogometasi.clear();
        }

        Klub(Klub&& privremeni) {
            for (int i = 0; i < privremeni.nogometasi.size(); i++) {
                nogometasi.push_back(privremeni.nogometasi[i]);
                privremeni.nogometasi[i] = NULL;
            }
        }

        Klub& operator = (const Klub& k) {
            if (this != &k) {
                for (int i = 0; i < nogometasi.size(); i++) {
                    delete nogometasi[i];
                }
                nogometasi.clear();
                for (int i = 0; i < k.nogometasi.size(); i++) {
                    nogometasi.push_back(new Nogometas);
                    *nogometasi[i] = *k.nogometasi[i];
                }
            }
            return *this;
        }
    };
};

bool usporedba(Nogometas a, Nogometas b) {
    if (a.getGolovi() != b.getGolovi()) 
        return a.getGolovi() > b.getGolovi(); 
    else 
        return a.getGodina() < b.getGodina(); 
}

int Nogometas::broj_nogometasa = 0;
int Nogometas::broj_golova = 0;

int main()
{
    vector <Nogometas> nogometasi = { Nogometas("Josip",1999,8),Nogometas("Ivan",1992,33),Nogometas("Petar",1996,8) };

    Nogometas igrac("Luka Modric", 1985, 23, {
        Utakmica("2023-09-12", "Francuska"),
        Utakmica("2023-10-05", "Njemačka"),
        Utakmica("2024-03-22", "Italija")
        });
    nogometasi.push_back(igrac);
    sort(nogometasi.begin(), nogometasi.end(), usporedba);
    for (auto n : nogometasi) {
        cout << n.getIme() << " (" << n.getGodina() << ") - " << n.getGolovi() << " golova" << endl;
    }
    cout << endl << Nogometas::prosjekPostignutihGolova() << endl;

    HNL::Klub A = move(HNL::Klub());
    return 0;
}


