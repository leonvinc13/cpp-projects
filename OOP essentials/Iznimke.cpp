/*
Napiši program koji koristi klasu za izvođenje osnovnih aritmetičkih operacija.
Klasa treba imati dva cijela broja i znak operacije. Treba omogućiti računanje zbrajanja, oduzimanja, množenja i dijeljenja.
U slučaju dijeljenja s nulom potrebno je baciti izuzetak tipa short. U slučaju overflowa potrebno je baciti izuzetak
tipa const char*. U glavnoj funkciji treba učitati dva broja, ispisati rezultate svih operacija i obraditi eventualne izuzetke.
*/

#include <iostream>

using namespace std;

class Operacija {
public:
    short prvi, drugi;
    char operacija;

    Operacija(short a, short b, char _operacija) : prvi(a), drugi(b), operacija(_operacija) {}

    short rezultat() {
        short res;
        if (operacija == '/') {
            if (drugi == 0) {
                throw prvi;
            }
        }
        else if (operacija == '+') res = prvi + drugi;
        else if (operacija == '-') res = prvi - drugi;
        else if (operacija == '*') res = prvi * drugi;
        else if (operacija == '/') res = prvi / drugi;
        if (prvi > 0 && drugi > 0 && res < 0)
            throw "Integer overflow!";
        return res;
    }
};

int main()
{
    short a, b;
    cin >> a >> b;
    try {
        cout << Operacija(a, b, '+').rezultat() << endl;
        cout << Operacija(a, b, '-').rezultat() << endl;
        cout << Operacija(a, b, '*').rezultat() << endl;
        cout << Operacija(a, b, '/').rezultat() << endl;
    }
    catch (short n) {
        cout << "Broj " << n << " se ne moze dijeliti s 0!\n";
    }
    catch (const char* s) {
        cout << s;
    }
    return 0;

}
