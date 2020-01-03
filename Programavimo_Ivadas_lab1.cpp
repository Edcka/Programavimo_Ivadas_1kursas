// Programavimo_Ivadas_lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
;/*3. Turime duomenų apie įmones tekstinį failą (įmonės pavadinimas, įmonės kodas, PVM mokėtojo kodas,
 įmonės adresas, direktoriaus vardas pavardė, metinė apyvarta). Parašyti programą, kuri leistų naudotojui 
 naudotis faile esančia informacija – 
 rasti informaciją apie norimą įmonę, pridėti naują įmonę, redaguoti pasirinktos įmonės informaciją.*/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdint.h>

using namespace std;

/*Struktura, skirta Imonei ir jos duomenims*/
struct Imone {
	string pavadinimas;
	string addr;
	string dir_var_pav;
	string kodas;
	string pvm;
	string apyvarta;
	Imone* next = NULL;
};


/*Funkcija skirta prideti nauja imone i sarasa, kuri isjungiant programa bus perrasoma i faila su pakitimais*/
void Prideti(Imone*& tail, string pav,string addr,
	string direct,string kodas, string pvm, string apyvarta) {
	Imone* temp = new Imone;
	temp->pavadinimas = pav;
	temp->addr = addr; ;
	temp->dir_var_pav = direct;
	temp->kodas = kodas;
	temp->pvm = pvm;
	temp->apyvarta = apyvarta;

	tail->next = temp;
	tail = temp;
}
/*Funkcija skirta irasyti Imone struktura i faila, programoje naudojama, isvesti visa sarasa i faila*/
void irasytiIfaila(ofstream& offFile, Imone *&tail) {

	offFile << tail->pavadinimas <<"\n";
	offFile << tail->addr << "\n";
	offFile << tail->dir_var_pav << "\n";
	offFile << tail->kodas << "\n";
	offFile << tail->pvm << "\n";
	offFile << tail->apyvarta << "\n";
}

/*Funckija skirta isvesti Imone strukturos informacija*/
void Rodyti(Imone*& temp) {

	cout << temp->pavadinimas << "\n";
	cout << temp->kodas << "\n";
	cout << temp->addr << "\n";
	cout << temp->dir_var_pav << "\n";
	cout << temp->pvm << "\n";
	cout << temp->apyvarta << "\n";
	cout << endl;
}

/*Funkcija skirta isvesti i ekrana visas sarase esancias imones*/
void RodytiVisus(Imone*& head) {
	Imone* temp = new Imone;
	temp = head;
	while (temp != NULL) {

		Rodyti(temp);
		temp = temp->next;
	}
}

/*Funkcija skirta rasti Imone ir isvesti ja i ekrana*/
void Rodyti(Imone *&head, string pavadinimas ) {

	Imone* temp = new Imone;
	temp = head;
	while (temp != NULL) {
		if (temp->pavadinimas.compare(pavadinimas)) {
			Rodyti(temp);
			break;
		}
		else temp = head->next;
	}
}
/*Si funkcija yra redagavimo meniu, kuriame atliekamos redagavimo funkcijos*/
void redMeniu(Imone*& redaguojama) {
	int pasirinkimas;
	cout << "Iveskite skaiciu kuri norite redaguoti" << endl;
	Rodyti(redaguojama);
	cout << "1-6 Imones info" << endl;
	cout << "7 Atsaukti" << endl;

	do {
		cin >> pasirinkimas;

		switch (pasirinkimas)
		{
		case 1:
		
			cout << "Iveskite pavadinima: ";
			getline(cin >> ws, redaguojama->pavadinimas);
			cout << endl;
			break;
		
		case 2:
		
			cout << "Iveskite imones koda: ";
			cin >> redaguojama->kodas;
			cout << endl;
			break;
		
		case 3:
		
			cout << "Iveskite adresa: ";
			getline(cin >>ws,redaguojama->addr);
			cout << endl;
			break;
		
		case 4:
		
			cout << "Iveskite direktoriaus vardas ir pavarde: ";
			getline(cin >> ws,redaguojama->dir_var_pav);
			cout << endl;
			break;
		
		case 5:
		
			cout << "Iveskite pvm koda: ";
			cin >> redaguojama->pvm;
			cout << endl;
			break;
		
		case 6:
		
			cout << "Iveskite apyvarta: ";
			cin >> redaguojama->apyvarta;
			cout << endl;
			break;

		}
	}
 while (pasirinkimas != 7);
}
/*Si funkcija suranda Imone kuria vartotojas nori redaguoti ir naudoja redagavimo meniu, kai ja randa*/
void Redaguoti(Imone*& head,
	string pavadinimas) {

	Imone* temp = new Imone;
	temp = head;
	while (temp != NULL) {
		if (head->pavadinimas.compare(pavadinimas) == 0) {
			redMeniu(head);
			break;
		}
		else if (temp->next->pavadinimas.compare(pavadinimas) == 0) {
			redMeniu(temp->next);
			break;
		}
		else if(temp->next == NULL) {
			cout << "Tokia imone nerasta \n";
			break;
		}
		temp = temp->next;

	}
}





int main()
{
	/*Kintamieji naudojami pirmam ir paskutiniui nariui sarase */
	Imone* head = new Imone;
	Imone* tail = new Imone;

	head = NULL;
	ifstream inFile;
	ofstream offFile;
	/*Ciklas kuris nuskaito visa sarasa is failo ir suveda i sarasa*/
	inFile.open("Imoniu_informacija.txt");
	if (inFile.is_open()) {
		while (!inFile.eof()) {
			Imone* temp = new Imone;
			getline(inFile, temp->pavadinimas);
			getline(inFile, temp->addr);
			getline(inFile, temp->dir_var_pav);
			getline(inFile, temp->kodas);
			getline(inFile, temp->pvm);
			getline(inFile, temp->apyvarta);

			if (head == NULL) {
				head = temp;
				tail = temp;
			}
			else {
				tail->next = temp;
				tail = temp;
			}
		}
	}
	/*Kintamieji meniu manipuliacijai*/
	int pasirinkimas;
	string pav,addr, direct, kodas, pvm, apyvarta;
	
	/*Meniu*/
	do {

		cout << "1. Ispausdinti visas imones\n";
		cout << "2. Surasti imone\n";
		cout << "3. Prideti imone\n";
		cout << "4. Readaguoti imone\n";
		cout << "5. Iseiti\n";

		cin >> pasirinkimas;
		switch (pasirinkimas)
		{
		case 1:
			RodytiVisus(head);
			break;
		case 2:
			cout << "Iveskite ieskomos imones pavadinima : ";
			getline(cin >>ws,pav);
			Rodyti(head,pav);
			break;

		case 3:
			cout << "Iveskite imones pavadinima, adresa, direktoriu, imones koda, pvm koda ir apyvarta :";
			getline(cin >> ws, pav);
			getline(cin >> ws, addr);
			getline(cin >> ws, direct);
			cin >> kodas;
			cin >> pvm;
			cin>> apyvarta;
			Prideti(tail, pav, addr, direct, kodas, pvm, apyvarta);
			break;

		case 4:
			cout << "Iveskite imones pavadinima kuria norite readaguoti : ";
			getline(cin >> ws, pav);
			Redaguoti(head, pav);
			break;
		}
		} while (pasirinkimas != 5);

		/*uzdarius programa, visas sarasas yra surasoma i faila su visais pakitimais*/
		inFile.close();
		offFile.open("Imoniu_informacija.txt");
		while (head != NULL) {
			irasytiIfaila(offFile, head);
			head = head->next;
		}
		offFile.close();
		return 0;
	
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
