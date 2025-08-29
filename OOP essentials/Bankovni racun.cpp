/*
U ovom zadatku potrebno je izraditi program u programskom jeziku C++ koji simulira osnovne operacije bankovnog računa. Program koristi objektno orijentirani pristup te se implementira klasa BankovniRacun.

Klasa BankovniRacun sadrži podatke o vlasniku računa i trenutnom stanju. Potrebno je implementirati konstruktor koji inicijalizira te podatke te metode za uplatu i isplatu novca.

Metoda uplati povećava stanje računa za uneseni iznos, dok metoda isplati smanjuje stanje. Ako se unese negativan iznos ili ako se traži isplata većeg iznosa od trenutnog stanja, potrebno je generirati iznimku. Metode trebaju vraćati referencu na objekt, kako bi se omogućio ulančani poziv metoda.

U glavnom programu (main) potrebno je kreirati jedan bankovni račun, izvršiti nekoliko uplata i isplata te obraditi sve potencijalne pogreške korištenjem try-catch blokova. Na kraju se ispisuje trenutno stanje računa.
*/

#include <iostream>

using namespace std;

class BankovniRacun {
public:
    string vlasnik;
    double stanje;

    BankovniRacun(string _vlasnik, double _stanje) : vlasnik(_vlasnik), stanje(_stanje) {}

    BankovniRacun& uplati(double iznos) {
        if (iznos < 0) {
            throw "Neispravan iznos za uplatu";
        }
        stanje += iznos;
        return *this;
    }

    BankovniRacun& isplati(double iznos) {
        if (iznos < 0) {
            throw "Neispravan iznos za isplatu";
        }
        if (iznos > stanje) {
            throw "Nedovoljno sredstava na racunu";
        }
        stanje -= iznos;
        return *this;
    }

};

int main() {
    BankovniRacun r1("Leon", 1200);
    try {
        r1.uplati(200);
        r1.isplati(300);
        r1.uplati(-100);
        r1.isplati(2000);
    }
    catch (const char* e) {
        cout << "Greska: " << e << endl;
    }
    catch (...) {
        cout << "Nepoznata greska!" << endl;
    }

    cout << "Stanje na racunu: " << r1.stanje << endl;
}
