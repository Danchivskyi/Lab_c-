#include "Data.h"
#include "Napis.h"
#include "Pracownik.h"
#include "TablicaPracownik.h"
#include <conio.h>
#include <iostream>
#include <string.h>

int main() {
	TablicaPracownik tablica;
	Pracownik p;
	Napis imie, nazwisko;
	Data data;
	while (1) {
		system("cls");
		std::cout << "To jest super zaawansowany program." << std::endl;
		std::cout << "Co potrzebujesz?" << std::endl;
		std::cout << "1 - Dodaj pracownika\n2 - Usunac pracownika\n3 - Wyswietlic pracownikow\n4 - Znalezc pracownika\n5 - Mam tylko date urodzenia...\n6 - Zapisz do pliku\n7 - Wczytaj z pliku" << std::endl;
		int a;
		std::cin >> a;
		const Pracownik *p2;
		switch (a) {
		case 1:
			std::cout << "Imie Nazwisko Data_Urodzenia: ";
			std::cin >> p;
			tablica.Dodaj(p);
			break;
		case 2:
			std::cout << "Imie Nazwisko Data_Urodzenia: ";
			std::cin >> p;
			tablica.Usun(p);
			break;
		case 3:
			tablica.WypiszPracownikow();
			break;
		case 4:
			std::cout << "Imie: ";
			std::cin >> imie;
			std::cout << "Nazwisko: ";
			std::cin >> nazwisko;
			if ((p2 = tablica.Szukaj(nazwisko.Zwroc(), imie.Zwroc())) != nullptr) {
				std::cout << *p2;
			}
			break;
		case 5:
			std::cout << "Data_Urodzenia: ";
			std::cin >> data;
			if ((p2 = tablica.Szukaj(data)) != nullptr) {
				std::cout << *p2;
			}
			break;
		case 6:
			tablica.ZapiszDoPliku();
			break;
		case 7:
			tablica.WczytajZPliku();
			break;
		}
		std::cin >> a;
	}

	system("pause");
}