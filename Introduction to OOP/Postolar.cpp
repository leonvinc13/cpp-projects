/*
Modelirati rad postolara koji prima narudžbe za izradu cipela.
Napraviti klase:
Cipela – ima veličinu (broj), materijal i boju.
Narudzba – sadrži ime naručitelja i listu cipela, te metodu za dodavanje novih cipela.
Postolar – vodi evidenciju o svim narudžbama i omogućava:
	preuzimanje narudžbe (računanje ukupne cijene)
	ispis svih narudžbi i njihovih detalja.

Pravila za cijenu:
Cijena izrade jedne cipele računa se tako da se veličina cipele pomnoži s 10.5.
Ukupna cijena narudžbe je zbroj cijena svih cipela u toj narudžbi.

U main funkciji:
kreirati postolara
dodati barem dvije narudžbe s više cipela
ispisati cijenu svake narudžbe
na kraju ispisati popis svih narudžbi (ime naručitelja i detalji cipela).
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Cipela {
public:
	int velicina;
	string materijal;
	string boja;

    Cipela(int _velicina, string _materijal, string _boja) : velicina(_velicina), materijal(_materijal), boja(_boja) {}
};

class Narudzba {
public:
    string narucitelj;
    vector <Cipela> cipela;

    Narudzba() {}

    Narudzba(string _narucitelj) : narucitelj(_narucitelj) {}

    void dodajCipelu(Cipela c) {
        cipela.push_back(c);
    }
};

class Postolar {
public:
    vector<Narudzba> narudba;

    double preuzmiNarudzbu(Narudzba n) {
        double cijena = 0;
        narudba.push_back(n);
        for (int i = 0; i < n.cipela.size(); i++) {
            cijena += n.cipela[i].velicina * 10.5;
        }
        return cijena;
    }

    void ispisiNarudzbe() {
        cout << endl << "Popis narudbi: " << endl;
        for (int i = 0; i < narudba.size(); i++) {
            cout << "Narudba " << i + 1 << ":" << endl << "Narucitelj: " << narudba[i].narucitelj;
            for (int j = 0; j < narudba[i].cipela.size(); j++) {
                cout << endl <<"Velicina: "<< narudba[i].cipela[j].velicina << ", " << "Materijal: " << narudba[i].cipela[j].materijal << ", " << "Boja: " << narudba[i].cipela[j].boja;
            }
            cout << endl << endl;
        }
    }
};


int main()
{
    Postolar p;
    Narudzba n1;
    n1.narucitelj = "Susjed Mirko";
    //Cipela ima broj (velicinu), materijal i boju
    n1.dodajCipelu(Cipela(47, "Sky", "plava"));
    n1.dodajCipelu(Cipela(44, "Platno", "zelena"));
    //Cijena izrade jedne cipele se racuna na nacin da se velicina (broj cipele) pomnozi sa 10.5
    double c1 = p.preuzmiNarudzbu(n1);
    cout << "Ukupna cijena 1. narudzbe je " << c1 << endl;
    Narudzba n2("Barica");
    n2.dodajCipelu(Cipela(43, "Koza", "crna"));
    double c2 = p.preuzmiNarudzbu(n2);
    cout << "Ukupna cijena 2. narudzbe je " << c2 << endl;
    //Ispisuje sve narudzbe
    //Za svaku narudzbu ispisuje tko je narucitelj, te popis svih cipela koje su narucene
    p.ispisiNarudzbe();
    return 0;
}

