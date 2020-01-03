// Bankomatas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <array>

using namespace std;

int main()
{	
		int norimasuma, kiekliko;

	cout << "Kokia pinigu suma norite pasiimti:" << endl;
	cin >> norimasuma;

	if (norimasuma >= 100) {
		cout << "Isduoti, kupiuru: " << norimasuma / 100 << " po 100" << endl;
	}

	kiekliko = norimasuma % 100;

	if (kiekliko >= 50) {

		cout << "Isduoti, kupiuru: " << kiekliko / 50 << " po 50" << endl;

		kiekliko = kiekliko % 50;

		if (kiekliko > 20) {
			cout << "Isduoti, kupiuru: " << kiekliko / 20 << " po 20" << endl;
		}

		kiekliko = kiekliko % 20;

		if (kiekliko < 20 && kiekliko>0) {
			cout << "Isduotine negalime " << kiekliko << endl;
		}


	}
	else
	{
		if (kiekliko >= 20) {
			cout << "Isduoti, kupiuru: " << kiekliko / 20 << " po 20" << endl;
		}

		kiekliko = kiekliko % 20;

		if (kiekliko < 20 && kiekliko>0) {
			cout << "Isduotine negalima " << kiekliko << endl;
		}

	}
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
