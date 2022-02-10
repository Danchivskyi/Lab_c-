#pragma once
#include <iostream>
#include "Pracownik.h"

class TablicaPracownik
{
private:
	Pracownik m_pTablica[20];
	int m_nLiczbaPracownikow;

public:
	TablicaPracownik();
	~TablicaPracownik();
	void Dodaj(const Pracownik& p);
	void Usun(const Pracownik& wzorzec);
	void WypiszPracownikow() const;
	const Pracownik* Szukaj(const char* nazwisko, const char* imie) const;
	const Pracownik* Szukaj(const Data & data_urodzenia) const;

	void ZapiszDoPliku() const;
	void WczytajZPliku();
};

