/*
Napiši klasu Knjiga koja sadrži privatne atribute naslov i autor. Potrebno je omogućiti postavljanje i dohvat vrijednosti, uz provjeru da naslov ima barem tri znaka.
Napiši klasu Knjiznica koja sadrži naziv, adresu i kolekciju knjiga. Omogući dodavanje knjige, ispis podataka te pravilno upravljanje memorijom.
Implementiraj konstruktor kopije, operator dodjele kopiranjem te operator dodjele prijenosom. Pokaži njihovo korištenje u funkciji main kroz primjere kopiranja i prijenosa.
*/

#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

class Knjiga {
private:
    string naslov, autor;

public:
    void setNaslov(string _naslov) {
        if (_naslov.size() >= 3) {
            naslov = _naslov;
        }
        else cout << "Naslov knjige treba imati minimalno 3 znaka!";
    }

    string getNaslov() const{
        return naslov;
    }

    void setAutor(string _autor) {
        autor = _autor;
    }

    string getAutor() const{
        return autor;
    }

    Knjiga() = default;
};

class Knjiznica {
public:
    string naziv, adresa;
    vector <Knjiga*> knjige;

    Knjiznica() = default;

    ~Knjiznica() {
        for (int i = 0; i < knjige.size(); i++) {
            delete  knjige[i];
        }
        knjige.clear();
    }

    void dodajKnjigu(Knjiga knjiga) {
        Knjiga *k = new Knjiga;
        k->setNaslov(knjiga.getNaslov());
        k->setAutor(knjiga.getAutor());
        knjige.push_back(k);
    }

    Knjiznica(const Knjiznica& k) {
        for (int i = 0; i < k.knjige.size(); i++) {
            knjige.push_back(new Knjiga);
            *knjige[i] = *k.knjige[i];
        }
        naziv = k.naziv;
        adresa = k.adresa;
    }

    Knjiznica& operator = (const Knjiznica& k) {
        if (this != &k) {
            for (int i = 0; i < knjige.size(); i++) {
                delete knjige[i];
            }
            knjige.clear();
            for (int i = 0; i < k.knjige.size(); i++) {
                knjige.push_back(new Knjiga);
                *knjige[i] = *k.knjige[i];
            }
            naziv = k.naziv;
            adresa = k.adresa;
        }
        return *this;
    }

    Knjiznica& operator = (Knjiznica&& privremeni) {
        for (int i = 0; i < knjige.size(); i++) {
            delete knjige[i];
        }
        knjige.clear();
        for (int i = 0; i < privremeni.knjige.size(); i++) {
            knjige.push_back(privremeni.knjige[i]);
            privremeni.knjige[i] = nullptr;
        }
        naziv = privremeni.naziv;
        adresa = privremeni.adresa;
        return *this;
    }

    void ispisi() const {
        cout << "Knjiznica: " << naziv << ", " << adresa << endl;
        for (auto k : knjige) {
            cout << " - \"" << k->getNaslov() << "\" od " << k->getAutor() << endl;
        }
    }
};

int main()
{
    Knjiznica k1;
    k1.naziv = "Opera";
    k1.adresa = "Zagreb 1";
    Knjiga knjiga1;
    knjiga1.setNaslov("Priče");
    knjiga1.setAutor("Ivica Ivić");
    k1.dodajKnjigu(knjiga1);

    Knjiznica k2 = k1;

    Knjiznica k3;
    k3 = k2;

    Knjiznica k4;
    k4 = Knjiznica();

    cout << "--- k1 ---" << endl;
    k1.ispisi();
    cout << "--- k2 (kopija k1) ---" << endl;
    k2.ispisi();
    cout << "--- k3 (dodijeljena kopija k2) ---" << endl;
    k3.ispisi();
    cout << "--- k4 (move dodjela praznog objekta) ---" << endl;
    k4.ispisi();
    return 0;
}


