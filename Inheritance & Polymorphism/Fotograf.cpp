/*
Napisati program koji demonstrira nasljeđivanje i polimorfizam.
Potrebno je definirati apstraktnu klasu s barem jednom virtualnom metodom, te iz nje izvesti dvije konkretne klase koje različito implementiraju istu metodu. U glavnom programu kreirati objekte izvedenih klasa, pohraniti ih u zajedničku kolekciju, pozivati metode polimorfno te na kraju izračunati prosječnu vrijednost nekog svojstva.
*/

#include <iostream>
#include <vector>

using namespace std;

class Fotografija {
public:
    string opis;
    double cijena;
    int kolicina;

    Fotografija(string _opis, double _cijena, int _kolicina): opis(_opis), cijena(_cijena), kolicina(_kolicina) {}

};

class Fotograf {
public:
    string ime;

    Fotograf(string _ime) : ime(_ime) {}

    virtual ~Fotograf() {
        cout << "Destruktor fotografa!" << endl;
    }

    virtual void OpisFotografa() {
        cout << "Ovo je fotograf: " << ime << endl;
    }

    virtual double UkupnaCijena(const Fotografija& f) {
        return f.kolicina * f.cijena;
    }

};

class SamostalniFotograf :public Fotograf {
public:
    SamostalniFotograf(string _ime) : Fotograf(_ime) {}

    ~SamostalniFotograf() override {
        cout << "Destruktor samostalnog fotografa!" << endl;
    }

    void OpisFotografa() override {
        cout << "Ovo je samostalni fotograf: " << ime << endl;
    }

    double UkupnaCijena(const Fotografija& f) override{
        return f.cijena * f.kolicina;
    }

};

class FotografAgencije :public Fotograf {
public:
    FotografAgencije(string _ime) : Fotograf(_ime) {};

    ~FotografAgencije() {
        cout << "Destrktor fotografa agencije!" << endl;
    }

    void OpisFotografa() override {
        cout << "Ovo je fotograf agencije:" << ime << endl;
    }

    double UkupnaCijena(const Fotografija& f) override {
        return f.kolicina * f.cijena * 0.75;
    }

};

double ukupnaCijenalzradjenihFotografija(const vector<Fotograf*>&fotografi, const Fotografija& f) {
    double suma = 0;
    for (int i = 0; i < fotografi.size(); i++) {
        suma += fotografi[i]->UkupnaCijena(f);
    }
    return suma / fotografi.size();
}



int main()
{
    Fotografija foto1("Portret", 10.0, 20); // 20 kom po 10kn

    Fotograf* f1 = new SamostalniFotograf("Ivan");
    Fotograf* f2 = new FotografAgencije("Ana");

    FotografAgencije f3("Leon");
    Fotograf* f4 = &f3;

    vector<Fotograf*> fotografi = { f1, f2 };

    for (int i = 0; i < fotografi.size(); i++) {
        fotografi[i]->OpisFotografa();
        cout << endl;
    }

    cout << "Ukupna cijena fotografija je " << ukupnaCijenalzradjenihFotografija(fotografi, foto1) << endl;

    for (int i = 0; i < fotografi.size(); i++) {
        delete fotografi[i];
    }
    return 0;
}


