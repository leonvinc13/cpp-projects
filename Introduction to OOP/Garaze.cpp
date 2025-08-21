/*
Potrebno je modelirati rad biblioteke. Klasa Knjiga sadrži naziv, autora i godinu izdanja. Klasa Član sadrži ime, prezime i listu posuđenih knjiga te metodu za dodavanje knjiga. Klasa Biblioteka sadrži ime i listu članova te metodu StatistikaBiblioteke koja računa koliko je članova posudilo više od jedne knjige i koja je najstarija posuđena knjiga. U glavnom programu potrebno je kreirati nekoliko knjiga, dodati ih članovima, kreirati barem dvije biblioteke i ispisati rezultate statistike.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Kljuc {
public:
    string ime, prezime;
};

class Garaza {
public:
    int sirina;
    int duljina;
    double cijena;
    string lokacija;
    vector <Kljuc> kljucevi;

    Garaza() {}

    Garaza(int _sirina, int _duljina, double _cijena, string _lokacija) : sirina(_sirina), duljina(_duljina), cijena(_cijena), lokacija(_lokacija) {}

    void dodajKljuc(Kljuc kljuc) {
        kljucevi.push_back(kljuc);
    }
};

int main()
{
    int N, M;
    cout << "Unesite broj garaza (N): ";
    cin >> N;
    vector <Garaza> garaza(N);
    for (int i = 0; i < N; i++) {
        string lokacija, broj;
        cout << "Unesite velicinu, lokaciju i cijenu za " << i + 1 << ". garazu:" << endl;
        cin >> garaza[i].sirina >> garaza[i].duljina;
        cin >> lokacija >> broj;
        cin >> garaza[i].cijena;
        garaza[i].lokacija = lokacija + " " + broj;
    }
    cout << "Unesite broj kljuceva (M): ";
    cin >> M;
    Kljuc kljuc;
    int broj_garaze;
    for (int i = 0; i < M; i++) {
        cout << "Unesite redni broj garaze kojoj pripada " << i + 1 << ". kljuc: ";
        cin >> broj_garaze;
        cout << "Unesite ime vlasnika kljuca: ";
        cin >> kljuc.ime >> kljuc.prezime;
        garaza[broj_garaze - 1].dodajKljuc(kljuc);
    }
    cout << endl << "Ispis garaza i kljuceva:" << endl;
    for (int i = 0; i < N; i++) {
        cout << i + 1 << ". " << garaza[i].lokacija << " " << garaza[i].sirina << "x" << garaza[i].duljina << " - kljucevi: ";
        for (int j = 0; j < garaza[i].kljucevi.size(); j++) {
            cout << garaza[i].kljucevi[j].ime << " " << garaza[i].kljucevi[j].prezime;
            if (j != garaza[i].kljucevi.size() - 1) {
                cout << ", ";
            }
        }    
        cout << endl;
    }
    return 0;
}
