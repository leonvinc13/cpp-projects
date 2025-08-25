/*
Napišite apstraktnu klasu Racunalo koja sadrži atribut za operacijski sustav, konstruktor, virtualni destruktor i čistu virtualnu funkciju getVrsta(). Zatim izvedite klase Tablet i Laptop koje implementiraju funkciju getVrsta(). Kreirajte funkciju AnalizaUcionice koja prima vektor pokazivača na objekte tipa Racunalo i određuje broj tableta, broj laptopa te broj računala s operacijskim sustavima Android, Windows i Linux. U glavnom programu kreirajte nekoliko objekata tipa Tablet i Laptop, pohranite ih u vektor, pozovite funkciju analize i ispišite rezultate.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//ne možeš napraviti objekt te klase direktno
class Racunalo {
protected:
    string os;  
public:
    Racunalo(string operacijskiSustav) : os(operacijskiSustav) {}

    //ako izbrišeš objekt izvedene klase preko pokazivača na baznu klasu, bez virtualnog destruktora, pozvat će se samo destruktor bazne klase
    virtual ~Racunalo() {}

    string getOS() const {
        return os;
    }

    //čista virtualna funkcija
    //svatko tko nasljeđuje ovu klasu MORA definirati ovu funkciju
    virtual string getVrsta() const = 0;  
};


class Tablet : public Racunalo {
public:
    //poziva konstruktor bazne klase i prosljeđivanje parametara baznom konstruktoru
    Tablet(string operacijskiSustav) : Racunalo(operacijskiSustav) {}

    string getVrsta() const override {
        return "Tablet";
    }
};


class Laptop : public Racunalo {
public:
    Laptop(string operacijskiSustav) : Racunalo(operacijskiSustav) {}

    string getVrsta() const override {
        return "Laptop";
    }
};


void AnalizaUcionice(const vector<Racunalo*>& ucionica, int* brTableta, int* brLaptopa,
    int* brAndroida, int* brWindowsa, int* brLinuxa) {

    *brTableta = 0;
    *brLaptopa = 0;
    *brAndroida = 0;
    *brWindowsa = 0;
    *brLinuxa = 0;

    for (int i = 0; i < ucionica.size(); i++) {
        if (ucionica[i]->getVrsta() == "Laptop") (*brLaptopa)++;
        else if (ucionica[i]->getVrsta() == "Tablet") (*brTableta)++;

        if (ucionica[i]->getOS() == "Android") (*brAndroida)++;
        else if (ucionica[i]->getOS() == "Windows") (*brWindowsa)++;
        else if (ucionica[i]->getOS() == "Linux") (*brLinuxa)++;
    }

}



int main() {
    int brTableta, brLaptopa;
    int brAndroida, brWindowsa, brLinuxa;

    Tablet Acer("Android"), Prestigio("Windows");
    Laptop Dell("Linux"), IBM("Windows"), Toshiba("Windows");

    vector<Racunalo*> Ucionica1 = { &Acer, &Prestigio, &Dell, &IBM, &Toshiba };
    AnalizaUcionice(Ucionica1, &brTableta, &brLaptopa, &brAndroida, &brWindowsa, &brLinuxa);

    cout << "U ucionici se nalazi " << Ucionica1.size() << " racunala" << endl;
    cout << "Broj tablet racunala : " << brTableta << endl;
    cout << "Broj laptop racunala : " << brLaptopa << endl;
    cout << "Android OS : " << brAndroida << endl;
    cout << "Windows OS : " << brWindowsa << endl;
    cout << "Linux OS : " << brLinuxa << endl;

    return 0;
}