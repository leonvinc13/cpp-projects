/*Napišite program koji u dinamièki alocirano polje uèitava N kompleksnih brojeva te ih ispisuje sortirane po vrijednosti njihovih modula.
Kompleksni broj treba predstaviti klasom Kompleksni koja sadrži realni i imaginarni dio (realni brojevi). 
Modul kompleksnog broja je udaljenost kompleksnog broja od ishodišta i treba se raèunati globalnom funkcijom Modul. 
Za sortiranje kompleksnih brojeva napišite funkciju Sortiraj koja æe sortirati kompleksne brojeve upotrebom BubbleSort algoritma.

Primjer izvoðenja
Unesi N: 3
niz[0].re = 3
niz[0].im = -1
niz[1].re = 1
niz[1].im = 1
niz[2].re = 2
niz[2].im = -3
Z(1+1i)  Modul: 1.41421
Z(3-1i)  Modul: 3.16228
Z(2-3i)  Modul: 3.60555

Nakon što ste zadatak riješili upotrebom dinamièki alociranog polja zamijenite ga vektorom te sortirajte upotrebom funkcije std::sort (zaglavlje algorithm). Takoðer, globalnu funkciju Modul implementirajte kao metodu klase Kompleksni.
*/

#include <iostream>  
#include <cmath>
#include <algorithm> // std::sort
#include <vector> // std::vector


using namespace std;  

class Kompleksni {
public:
    double realni;
    double imaginarni;

    double Modul() {
        return sqrt(pow(realni, 2) + pow(imaginarni, 2));
    }
};

/*double Modul(Kompleksni Z) {
    return sqrt(pow(Z.realni, 2) + pow(Z.imaginarni, 2));
}*/

void sortiraj(Kompleksni* p, int n) {
    bool bilaZamjena = false;
    do {
        bilaZamjena = false;
        for (int i = 0; i < n - 1; i++) {
            if ((p[i].Modul()) > (p[i + 1].Modul())) {
                Kompleksni temp = p[i];
                p[i] = p[i + 1];
                p[i + 1] = temp;
                bilaZamjena = true;
            }
        }
    } while (bilaZamjena);
}

bool kompleksniUsporedba(Kompleksni Z1, Kompleksni Z2) {
    return Z1.Modul() < Z2.Modul();
}

int main()  
{
    int N;
    cin >> N;
    
    /*Kompleksni* niz = new Kompleksni[N];
    for (int i = 0; i < N; i++) {
        cout << "niz[" << i << "].re = ";
        cin >> niz[i].realni;
        cout << "niz[" << i << "].im = ";
        cin >> niz[i].imaginarni;
    }*/

    vector <Kompleksni> niz;
    for (int i = 0; i < N; i++) {
        Kompleksni pom;
        cout << "niz[" << niz.size() << "].re = ";
        cin >> pom.realni;
        cout << "niz[" << niz.size() << "].im = ";
        cin >> pom.imaginarni;
        niz.push_back(pom);
    }

    //sortiraj(niz, N);

    sort(niz.begin(), niz.end(), kompleksniUsporedba);

    for (int i = 0; i < N; i++)
        cout << "Z(" << niz[i].realni << ((niz[i].imaginarni < 0) ? ("") : ("+"))
        << niz[i].imaginarni << "i)\tModul: " << niz[i].Modul() << endl;

    //delete[] niz;
    return 0;  
}


