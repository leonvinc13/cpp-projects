/*
Napraviti klasu Osoba koja sadrži ime, prezime i godinu rođenja.
U metodi setIme i setPrezime automatski formatirati prvi znak velikim slovom, a ostale malim slovima.
U metodi setGodine provjeriti da godina nije manja od 1900; ako jest, postaviti godinu na 1900 i ispisati poruku upozorenja.
Napraviti funkciju koja prima vektor osoba i vraća najstariju osobu.
U funkciji main unijeti 5 osoba od korisnika, pohraniti ih u vektor i ispisati ime, prezime i godinu rođenja najstarije osobe.
*/

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

string formatirajNaziv(string naziv) {
    if (!naziv.empty()) {
        naziv[0] = toupper(naziv[0]);
        for (int i = 1; i < naziv.size(); i++) {
            naziv[i] = tolower(naziv[i]);
        }
    }
    return naziv;
}

class Osoba {
private:
    string ime, prezime;
    int godina_rod;
public:
    void setIme(const string& _ime) {
        ime = formatirajNaziv(_ime);
    }

    string getIme() const {
        return ime;
    }

    void setPrezime(const string& _prezime) {
        prezime = formatirajNaziv(_prezime);
    }

    string getPrezime() const {
        return prezime;
    }

    void setGodine(int godina) {
        if (godina >= 1900) {
            godina_rod = godina;
        }
        else {
            cout << "Godina rođenja mora biti veća od 1900. Postavljena na 1900.\n";
            godina_rod = 1900;
        }
    }

    int getGodine() const {
        return godina_rod;
    }
};

Osoba najstarijaOsoba(const vector<Osoba>& osobe) {
    if (osobe.empty()) return Osoba();

    int indeks = 0;
    for (int i = 1; i < osobe.size(); i++) {
        if (osobe[i].getGodine() < osobe[indeks].getGodine()) {
            indeks = i;
        }
    }
    return osobe[indeks];
}

int main() {
    vector<Osoba> osobe;
    for (int i = 0; i < 5; i++) {
        string ime, prezime;
        int godina;
        cout << "Unesi ime, prezime i godinu rođenja za osobu " << i + 1 << ": ";
        cin >> ime >> prezime >> godina;

        Osoba o;
        o.setIme(ime);
        o.setPrezime(prezime);
        o.setGodine(godina);

        osobe.push_back(o);
    }

    Osoba najstariji = najstarijaOsoba(osobe);

    cout << "\nNajstarija osoba je: "
        << najstariji.getIme() << " "
        << najstariji.getPrezime() << " ("
        << najstariji.getGodine() << ")" << endl;

    return 0;
}
