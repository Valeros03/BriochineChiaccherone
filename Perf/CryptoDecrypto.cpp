#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <fstream>

int Crypt() {

	std::string str;
	std::vector<int> chiavi;
	int temp = 0;

	std::cout << "Inserisci la stringa\n";

	std::getline(std::cin >> std::ws, str);
	std::cout << "\n\n";
	char* charStr = new char[str.size() + 1];
	std::copy(str.begin(), str.end(), charStr);
	char* v = new char[str.size() + 1];
	char* ord = new char[str.size() + 1];
	std::copy(str.begin(), str.end(), ord);

	v[str.length()] = '\0';
	charStr[str.length()] = '\0';
	ord[str.length()] = '\0';

	int* unic = new int[str.length() + 1];
	std::cout << str.length() << std::endl;
	unsigned long asciiSeed = 0;
	for (int i = 0; i < str.length(); i++) {

		asciiSeed += ord[i];

	}

	for (int i = 0; i < str.length(); i++) {
		unic[i] = 0;
	}

	srand(str.length()*asciiSeed);
	for (int i = 0; i < str.length(); i++) {


		while (unic[temp - 1] != 0) {
			temp = rand() % str.length() + 1;
		}

		unic[temp - 1] = 1;

		v[i] = ord[temp - 1];
		charStr[i] = ord[temp - 1];
		charStr[temp - 1] = v[i];

	}
	


	srand(str.length() + 371);
	for (int i = 0; i < str.length(); i++) {
		int a = rand() % 5 + 1;
		
		v[i] = v[i] + a;
	}


	std::cout << v << std::endl;

	return 1;
}

int Decrypt() {

	std::string str;
	std::vector<int> chiavi;
	int temp = 0;

	std::cout << "Inserisci la stringa\n";
	std::getline(std::cin >> std::ws, str);
	
	char* charStr = new char[str.size() + 1];
	std::copy(str.begin(), str.end(), charStr);
	char* v = new char[str.size() + 1];
	char* ord = new char[str.size() + 1];

	v[str.length()] = '\0';
	charStr[str.length()] = '\0';
	ord[str.length()] = '\0';

	int* unic = new int[str.length()];

	for (int i = 0; i < str.length(); i++) {
		unic[i] = 0;
	}

	std::cout << str.length() << std::endl;

	srand(str.length()+371);
	for (int i = 0; i < str.length(); i++) {
		int a = rand() % 5 + 1;
		charStr[i] = charStr[i] - a;
		ord[i] = charStr[i];

	}

	unsigned long asciiSeed = 0;
	for (int i = 0; i < str.length(); i++) {

		asciiSeed += ord[i];

	}

	srand(str.length()*asciiSeed);
	for (int i = 0; i < str.length(); i++) {
		while (unic[temp - 1] != 0) {

			temp = rand() % str.length() + 1;
		}

		unic[temp - 1] = 1;
		chiavi.push_back(temp);
	}

	for (int i = 0; i < str.length(); i++) {

		temp = chiavi[i];

		v[temp - 1] = ord[i];
		charStr[temp - 1] = ord[i];
		charStr[i] = v[temp - 1];

	}
	std::cout << v << "\n";

	system("Pause");
	return 1;
}

int main() {
	short c = 0;
	bool use = true;
	while (use) {
		std::cout << "Selezionare la modalita crypt(1), decrypt(2), Esci(3): ";
		std::cin >> c;
		
		switch (c) {
		case 1:
			system("cls");
			Crypt();
			break;
		case 2:
			system("cls");
			Decrypt();
			break;
		case 3:
			use = false;
			break;
		default :
			std::cout << "inserire un numero tra 1,2,3\n";
		}

	}

}
