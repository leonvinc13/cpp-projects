/*
Napiši program koji definira klasu Razlomak s brojnim operatorima.
Klasa treba imati konstruktore, operator dodjele, operator množenja, prefiksni operator ++, unarni minus i pretvorbu u int. 
Treba omogućiti i ispis razlomka, kao i zbrajanje cijelog broja i razlomka. 
U glavnoj funkciji ispitati sve operatore i prikazati rezultate.
*/

#include <iostream>

using namespace std;

class Razlomak {
public:
    int brojnik, nazivnik;

    Razlomak() = default;

    Razlomak(int _brojnik, int _nazivnik) : brojnik(_brojnik), nazivnik(_nazivnik) {};

    Razlomak(Razlomak r1, Razlomak r2) {
        brojnik = r1.brojnik * r2.nazivnik;
        nazivnik = r1.nazivnik * r2.brojnik;
    }

    Razlomak& operator = (int _brojnik) {
        brojnik = _brojnik;
        nazivnik = 1;
        return *this;
    }

    Razlomak operator * (const Razlomak &r) {
        return Razlomak(brojnik * r.brojnik, nazivnik * r.nazivnik);
    }

    Razlomak& operator ++() {
        brojnik = brojnik + nazivnik;
        nazivnik = nazivnik;
        return *this;
    }

    Razlomak operator - () {
        return Razlomak(-brojnik, nazivnik);
    }

    operator int() {
        return brojnik / nazivnik;
    }
};

ostream& operator << (ostream& izlaz, const Razlomak& r) {
    izlaz << r.brojnik << '/' << r.nazivnik;
    return izlaz;
}

Razlomak operator + (const int &broj, const Razlomak& r) {
    return Razlomak(r.nazivnik * broj + r.brojnik, r.nazivnik);
}



int main()
{
    Razlomak r1(2, 3), r2;
    r2 = 2; // 2/1
    cout << r2 << endl;
    cout << r1 * r2 << endl;  // 4/3
    cout << 2 + ++r2 << endl; // 5/1

    cout << r1 << endl; // 2/3
    cout << -r2 << endl; // -3/1

    Razlomak dvostruki(r2, r1);
    cout << (int)dvostruki << endl; // 4
    return 0;

}


