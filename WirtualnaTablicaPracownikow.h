#pragma once
#include "Pracownik.h"

class WirtualnaTablicaPracownikow
{
private:
	Pracownik ** tablica;
	int m_nLiczbaPracownikow;
	int m_nRozmiarTablicy;

public:
	WirtualnaTablicaPracownikow(int roz);
	WirtualnaTablicaPracownikow();

	void Dodaj(const Pracownik & p);
	void Usun(const Pracownik & wzorzec);
	void WypiszPracownikow() const;
	const Pracownik* Szukaj(const char* nazwisko, const char * imie);
};

