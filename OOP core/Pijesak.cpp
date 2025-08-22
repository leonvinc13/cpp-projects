/*
Napraviti klasu Zrno koja sadrži boju i promjer.
Napraviti klasu Pijesak koja ima količinu i polje pokazivača na objekte tipa Zrno.
U konstruktoru klase Pijesak dinamički alocirati polje zrna.
U destruktoru osloboditi zauzetu memoriju.
Definirati kopirni konstruktor koji radi duboku kopiju.
Definirati operator pridruživanja (kopiranje) koji radi duboku kopiju.
Definirati konstruktor prijenosa koji preuzima podatke iz privremenog objekta.
Definirati operator pridruživanja (prijenos) koji preuzima podatke iz privremenog objekta.
U funkciji main demonstrirati rad svih konstruktora i operatora pridruživanja.
*/

#include <iostream>
#include <string>
using namespace std;

class Zrno {
public:
    string boja;
    float promjer;
};
class Pijesak {
public:
    int kolicina;
    Zrno* zrno;
    Pijesak() = default;
    Pijesak(int _kolicina) : kolicina(_kolicina) {
        // dinamički alocirajte polje 'zrno'
        zrno = new Zrno[kolicina];
    }
    ~Pijesak() {
        // ?
        delete[] zrno;
    }

    Pijesak(const Pijesak &p) {
        zrno = new Zrno[p.kolicina];
        for (int i = 0; i < p.kolicina; i++) {
            zrno[i].boja = p.zrno[i].boja;
            zrno[i].promjer = p.zrno[i].promjer;
        }
        kolicina = p.kolicina;
        cout << "kopirni konstruktor\n";
    }

    Pijesak& operator = (const Pijesak& p) {
        if (this != &p) {
            delete[] zrno;
            zrno = new Zrno[p.kolicina];
            for (int i = 0; i < p.kolicina; i++) {
                zrno[i].boja = p.zrno[i].boja;
                zrno[i].promjer = p.zrno[i].promjer;
            }
            kolicina = p.kolicina;
            cout << "operator pridruzivanja (kopiranje)\n";
        }
        return *this;
    }

    Pijesak(Pijesak&& privremeni) {
        zrno = privremeni.zrno;
        privremeni.zrno = NULL;
        kolicina = privremeni.kolicina;
        cout << "konstruktor prijenosa\n";
    }

    Pijesak& operator = (Pijesak&& privremeni) {
        if (this != &privremeni) {
            delete[] zrno;
            zrno = privremeni.zrno;
            privremeni.zrno = NULL;
            kolicina = privremeni.kolicina;
            cout << "operator pridruzivanja (prijenos)\n";
        }
        return *this;
    }
};
int main() {
    Pijesak igraliste(1000000);
    cout << "Na igralistu ima " << igraliste.kolicina << " zrna pijeska!\n";

    // Demonstrirajte pozive oba konstruktora i oba operatora pridruživanja
    Pijesak p1 = igraliste; // kopirni konstruktor
    cout << "Na igralistu ima " << p1.kolicina << " zrna pijeska!\n";

    Pijesak p2(0);
    p2 = p1;  // operator pridruzivanja (kopiranje)
    cout << "Na igralistu ima " << p2.kolicina << " zrna pijeska!\n";

    Pijesak p3 = move(Pijesak(500000)); // konstruktor prijenosa
    cout << "Na igralistu ima " << p3.kolicina << " zrna pijeska!\n";

    Pijesak p4(0);
    p4 = Pijesak(500000); // operator pridruzivanja (prijenos)
    cout << "Na igralistu ima " << p4.kolicina << " zrna pijeska!\n";
    return 0;
}