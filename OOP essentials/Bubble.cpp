/*
Napiši program koji definira klasu Bubble. 
Klasa treba sadržavati atribute boja i radijus, konstruktor, metodu za izračun obujma mjehurića te metodu koja na temelju obujma vraća odgovarajući radijus. 
Potrebno je preopteretiti operatore +, -, == i <<. Operator + spaja dva mjehurića u novi, određuje mu boju većeg obujma i računa novi radijus. 
Operator - vraća razliku obujmova, a boja ostaje od prvog mjehurića. 
Operator == uspoređuje mjehuriće po boji i radijusu, dok se operator << koristi za ispis. 
U glavnoj funkciji demonstrirati rad operatora.
*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Bubble {
public:
    string boja;
    double radijus;

    Bubble() = default;

    Bubble(string _boja, double _radijus) : boja(_boja), radijus(_radijus) {}

    double Obujam() const {
        //V = 4/3 * r * r * r * PI
        return (4.0 / 3.0) * radijus * radijus * radijus * 3.14;
    }

    double Radijus(double obujam) const {
        double izraz;
        izraz = (3 * obujam) / (4 * 3.14);
        return pow(izraz, 1.0 / 3);
    }

    Bubble operator + (const Bubble &b1) {
        double novObujam = this->Obujam() + b1.Obujam();
        string novaBoja = (this->Obujam() >= b1.Obujam() ? this->boja : b1.boja);
        return Bubble(novaBoja, Radijus(novObujam));
    }

    Bubble operator - (const Bubble &b) {
        double novObujam = this->Obujam() - b.Obujam();
        string novaBoja = this->boja;
        return Bubble(novaBoja, Radijus(novObujam));
    }

};

ostream& operator << (ostream& izlaz, const Bubble& b) {
    izlaz << b.boja << ": " << b.radijus << endl;
    return izlaz;
}

bool operator == (const Bubble& b1, const Bubble& b2) {
    if (b1.boja == b2.boja && abs(b1.radijus - b2.radijus) <= 0.0001) return 1;
    else return 0;
}



int main()
{
    Bubble a("blue", 10.4);
    Bubble b("red", 7.2);
    Bubble c("green", 18.8);

    Bubble x = a + b; //nastat će novi bubble obujma 6275.27
    cout << x; //blue: 11.44
    Bubble y = x + c;
    cout << y; //green: 20.12

    Bubble z = y - x;
    cout << z; //green: 18.8

    if (z == c)
        cout << "OK" << endl; //OK
    return 0;
}

