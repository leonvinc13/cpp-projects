/*
Potrebno je implementirati klasu Zaposlenik koja sadrži ime, prezime i starost.
Potrebno je implementirati get i set metode za sve atribute.
Potrebno je implementirati konstruktor i destruktor.

Zatim je potrebno implementirati klasu Firma koja sadrži naziv, OIB, adresu i kolekciju zaposlenika.
Naziv firme mora sadržavati barem 5 znakova.
OIB mora sadržavati točno 11 znamenki.
Potrebno je implementirati više načina dodavanja zaposlenika, prijenosom vrijednosti, referencom i pokazivačem.
Potrebno je implementirati metodu za ispis svih zaposlenika.

Potrebno je implementirati metode za pronalaženje zaposlenika po imenu i prezimenu.
Prva metoda vraća objekt po vrijednosti.
Druga metoda vraća pokazivač na pronađenog zaposlenika.
Treća metoda vraća referencu na pronađenog zaposlenika.

U funkciji main demonstrirati rad svih funkcionalnosti.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Zaposlenik {
private:
    string ime, prezime;
    int starost;
public:
    void setIme(string _ime) {
        ime = _ime;
    }

    string getIme() {
        return ime;
    }

    void setPrezime(string _prezime) {
        prezime = _prezime;
    }

    string getPrezime() {
        return prezime;
    }

    void setStarost(int _starost) {
        starost = _starost;
    }

    int getStarost() {
        return starost;
    }

    Zaposlenik(string _ime, string _prezime, int _starost)
        : ime(_ime), prezime(_prezime), starost(_starost) {
        cout << "Zaposlenik constructor called" << endl;
    }

    ~Zaposlenik() {
        cout << "Zaposlenik destructor called" << endl;
    }
};

class Firma {
private:
    string naziv, oib, adresa;
    vector<Zaposlenik> zaposlenici;
public:
    void setNaziv(const string &_naziv) {
        if (_naziv.size() >= 5) {
            naziv = _naziv;
        }
        else {
            cout << "Naziv mora sadržavati barem 5 znakova." << endl;
        }
    }

    void setOib(const string &_oib) {
        bool ispravno = true;
        for (int i = 0; i < _oib.size(); i++) {
            if (!isdigit(_oib[i])) {
                ispravno = false;
            }
        }
        if (_oib.size() == 11 && ispravno == true) {
            oib = _oib;
        }
        else {
            cout << "OIB se mora sastojati od 11 znamenaka" << endl;
        }
    }

    void setAdresa(const string& _adresa) {
        adresa = _adresa;
    }

    string getNaziv() {
        return naziv;
    }

    string getOib() {
        return oib;
    }

    string getAdresa() {
        return adresa;
    }

    void dodajZaposlenika1(Zaposlenik z);

    void dodajZaposlenika2(Zaposlenik& z);

    void dodajZaposlenika3(Zaposlenik* z);

    void ispisSvihZaposlenika() {
        for (int i = 0; i < zaposlenici.size(); i++) {
            cout << i + 1 << ". " << zaposlenici[i].getIme() << " " << zaposlenici[i].getPrezime() << " " << zaposlenici[i].getStarost() << endl;
        }
    }

    Zaposlenik nadjiZaposlenika1(string ime, string prezime);

    Zaposlenik* nadjiZaposlenika2(string ime, string prezime);

    Zaposlenik& nadjiZaposlenika3(string ime, string prezime);
};


void Firma::dodajZaposlenika1(Zaposlenik z) {
    zaposlenici.push_back(z);
}



void Firma::dodajZaposlenika2(Zaposlenik& z) {
    zaposlenici.push_back(z); 
}


void Firma::dodajZaposlenika3(Zaposlenik* z) {
    zaposlenici.push_back(*z); 
}


Zaposlenik Firma::nadjiZaposlenika1(string ime, string prezime) {
    for (int i = 0; i < zaposlenici.size(); i++) {
        if (zaposlenici[i].getIme() == ime && zaposlenici[i].getPrezime() == prezime) {
            return zaposlenici[i];
        }
    }
    cout << "Zaposlenik nije pronađen!" << endl;
    return Zaposlenik("", "", 0);  
}

Zaposlenik* Firma::nadjiZaposlenika2(string ime, string prezime) {
    for (int i = 0; i < zaposlenici.size(); i++) {
        if (zaposlenici[i].getIme() == ime && zaposlenici[i].getPrezime() == prezime) {
            return &zaposlenici[i];  
        }
    }
    return nullptr;  
}

Zaposlenik& Firma::nadjiZaposlenika3(string ime, string prezime) {
    for (int i = 0; i < zaposlenici.size(); i++) {
        if (zaposlenici[i].getIme() == ime && zaposlenici[i].getPrezime() == prezime) {
            return zaposlenici[i];  
        }
    }
    cout << "Zaposlenik nije pronaden!" << endl;
    Zaposlenik prazni("","",0);  
    return prazni;
}


int main()
{
    Firma firma;
    firma.setNaziv("TechCorp");
    firma.setOib("12345678901");
    firma.setAdresa("Zagreb, Ulica 1");

    Zaposlenik z1("Marko", "Markovic", 20); 
    Zaposlenik z2("Ana", "Anic", 35); 
    Zaposlenik z3("Ivan", "Ivic", 19); 

    firma.dodajZaposlenika1(z1);  
    firma.dodajZaposlenika2(z2);  
    firma.dodajZaposlenika3(&z3);  

    cout << "Svi zaposlenici:" << endl;
    firma.ispisSvihZaposlenika();

    Zaposlenik z4 = firma.nadjiZaposlenika1(z1.getIme(), z1.getPrezime());
    z4.setIme("Mirko");
    z4.setStarost(24);
    cout << endl << "Nakon izmjene preko nadjiZaposlenika1:" << endl;
    firma.ispisSvihZaposlenika();

    Zaposlenik* z5 = firma.nadjiZaposlenika2(z2.getIme(), z2.getPrezime());
    if (z5 != nullptr) {
        z5->setPrezime("Kovacic");
        z5->setStarost(65);
    }
    cout << endl << "Nakon izmjene preko nadjiZaposlenika2:" << endl;
    firma.ispisSvihZaposlenika();

    Zaposlenik& z6 = firma.nadjiZaposlenika3(z3.getIme(), z3.getPrezime());
    z6.setPrezime("Ivanovic");  
    cout << endl << "Nakon izmjene preko nadjiZaposlenika3:" << endl;
    firma.ispisSvihZaposlenika();

    return 0;
}

