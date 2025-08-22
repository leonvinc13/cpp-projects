/*
Napraviti klasu Racunalo koja sadrži naziv, procesor i memoriju.
Napraviti klasu Ucionica koja sadrži broj računala i polje pokazivača na objekte tipa Racunalo.
U konstruktoru klase Ucionica dinamički alocirati polje računala i inicijalizirati sva računala istim vrijednostima.
U destruktoru osloboditi memoriju.
Definirati kopirni konstruktor koji radi duboku kopiju.
Definirati operator pridruživanja (kopiranje) koji radi duboku kopiju.
Definirati konstruktor prijenosa koji preuzima polje iz privremenog objekta.
Definirati operator pridruživanja (prijenos) koji preuzima polje iz privremenog objekta.
U funkciji main demonstrirati rad svih konstruktora i operatora pridruživanja.
*/

#include <iostream>
#include <vector>

using namespace std;

class Racunalo {
public:
    string naziv, procesor, memorija;
};

class Ucionica {
public:
	int brRacunala = 0;
    Racunalo *racunalo;

	~Ucionica(){
		delete[] racunalo;
	}

	Ucionica(int _broj_racunala, string _naziv, string _procesor, string _memorija) {
		brRacunala = _broj_racunala;
		racunalo = new Racunalo[brRacunala];
		for (int i = 0; i < brRacunala; i++) {
			racunalo[i].naziv = _naziv;
			racunalo[i].procesor = _procesor;
			racunalo[i].memorija = _memorija;
		}
	}

	Ucionica(const Ucionica& u) {
		brRacunala = u.brRacunala;
		racunalo = new Racunalo[u.brRacunala];
		for (int i = 0; i < u.brRacunala; i++) {
			racunalo[i].naziv = u.racunalo[i].naziv;
			racunalo[i].procesor = u.racunalo[i].procesor;
			racunalo[i].memorija = u.racunalo[i].memorija;
		}
	}

	Ucionica& operator = (const Ucionica& u) {
		if (this != &u) {
			delete[] racunalo;
			brRacunala = u.brRacunala;
			racunalo = new Racunalo[u.brRacunala];
			for (int i = 0; i < u.brRacunala; i++) {
				racunalo[i].naziv = u.racunalo[i].naziv;
				racunalo[i].procesor = u.racunalo[i].procesor;
				racunalo[i].memorija = u.racunalo[i].memorija;
			}
		}
		return *this;
	}

	Ucionica(Ucionica&& privremeni) {
		brRacunala = privremeni.brRacunala;
		racunalo = privremeni.racunalo;
		privremeni.racunalo = NULL;
		privremeni.brRacunala = 0;
	}

	Ucionica& operator =(Ucionica&& privremeni) {
		delete[] racunalo;
		racunalo = privremeni.racunalo;
		brRacunala = privremeni.brRacunala;
		privremeni.racunalo = NULL;
		privremeni.brRacunala = 0;
		return *this;
	}
};

int main()
{
	// Učionica 'A' s 15 računala istih specifikacija
	Ucionica A(15, "Koncar", "Intel I5", "4 GB");
	// Učionica B ima također 15 računala istih specifikacija kao i učionica 'A'
	Ucionica B = A;
	cout << B.brRacunala << endl; // 15
	// Računala iz učionice 'C' se prenose u  učionicu 'B'
	Ucionica C = move(B);
	cout << B.brRacunala << endl; // 0
	// Privremena ucionica se zatvara i njena racunala se prenose u ucionicu 'B'
	B = Ucionica(15, "Dell", "Intel I7", "8 GB");
	return 0;

}


