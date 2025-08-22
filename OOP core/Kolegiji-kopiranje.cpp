/*
Napraviti klasu Student s atributima ime, jmbag i broj bodova.
Napraviti klasu Kolegij koja sadrži listu studenata.
Implementirati dodavanje studenta u kolegij.
Implementirati konstruktor kopije s dubokim kopiranjem.
Implementirati operator dodjele s dubokim kopiranjem.
Implementirati operator dodjele s prijenosom.
Testirati sve funkcionalnosti u glavnom programu.
*/

#include <iostream>
#include <vector>

using namespace std;

class Student {
public:
	string ime, jmbag;
	int brojBodova = 0;
	Student() = default;
	Student(string _ime, string _jmbag) : ime(_ime), jmbag(_jmbag) {}
};

class Kolegij {
public:
	vector<Student*>student;
	
	void dodaj(Student* s) {
		student.push_back(s);
	}

	Kolegij() = default;

	~Kolegij() {
		for (int i = 0; i < student.size(); i++) {
			delete student[i];
		}
	}

	Kolegij(const Kolegij &k) {
		for (int i = 0; i < k.student.size(); i++) {
			//student.push_back(new Student(k.student[i]->ime, k.student[i]->jmbag));
			student.push_back(new Student);
			*student[i] = *k.student[i];
			student[i]->brojBodova = k.student[i]->brojBodova;
		}
	}

	Kolegij& operator = (const Kolegij& k) {
		if (this != &k) {
			for (int i = 0; i < student.size(); i++) {
				delete student[i];
			}
			student.clear();
			for (int i = 0; i < k.student.size(); i++) {
				student.push_back(new Student(k.student[i]->ime, k.student[i]->jmbag));
				student[i]->brojBodova = k.student[i]->brojBodova;
			}
		}
		return* this;
	}

	Kolegij& operator = (Kolegij &&privremeni){
		for (int i = 0; i < student.size(); i++) {
			delete student[i];
		}
		student.clear();
		for (int i = 0; i < privremeni.student.size(); i++) {
			student.push_back(privremeni.student[i]);
			privremeni.student[i] = NULL;
		}
		return *this;
	}
};

int main() {
	Kolegij OOP;
	OOP.dodaj(new Student("Ante Antic", "02460123456"));
	OOP.dodaj(new Student("Ivica Ivic", "02460567890"));

	Kolegij OOP2 = OOP;
	OOP.student[0]->brojBodova = 10;
	OOP2.student[0]->brojBodova = 20;
	cout << OOP.student[0]->brojBodova << endl; // 10
	cout << OOP2.student[0]->brojBodova << endl; // 20

	Kolegij Java;
	Java = OOP2;
	OOP2.student[0]->brojBodova = 10;
	Java.student[0]->brojBodova = 20;
	cout << OOP2.student[0]->brojBodova << endl; // 10
	cout << Java.student[0]->brojBodova << endl; // 20

	Kolegij Matematika;
	Matematika = Kolegij();
	return 0;
}



