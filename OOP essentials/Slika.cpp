/*
Napiši program koji definira klasu Slika. Klasa treba imati atribut cijena i statičke članove za zbroj cijena i broj slika. 
U konstruktoru se povećava broj slika i dodaje cijena u ukupni zbroj. 
Klasa treba imati statičku metodu koja vraća prosječnu cijenu svih slika. 
U glavnoj funkciji demonstrirati rad klase.
*/

#include <iostream>

using namespace std;

class Slika {
public:
    double cijena;
    static double sumaCijena;
    static int brojSlika;

    Slika(double _cijena) : cijena(_cijena) {
        sumaCijena += cijena;
        brojSlika++;
    }

    static double ProsjecnaCijena() {
        return sumaCijena / brojSlika;
    }
};

int Slika::brojSlika = 0;
double Slika::sumaCijena = 0;

int main()
{
    Slika Slika1(2000); // 2000 eura
    Slika Slika2(3000); // 3000 eura
    Slika Slika3(1800); // 1800 eura
    cout << Slika::ProsjecnaCijena() << " eura"; // 2266.67 eura
}


