#include "WirtualnaTablicaPracownikow.h"

WirtualnaTablicaPracownikow::WirtualnaTablicaPracownikow(int roz)
{
	m_nRozmiarTablicy = roz;
	m_nLiczbaPracownikow = 0;
	tablica = new Pracownik*[m_nRozmiarTablicy];
}

WirtualnaTablicaPracownikow::WirtualnaTablicaPracownikow()
{
	for (int i = 0; i < m_nRozmiarTablicy; i++) {
		delete[] tablica[i];
	}
	delete[] tablica;
}

void WirtualnaTablicaPracownikow::Dodaj(const Pracownik & p)
{
	int i;
	for (i = 0; i < m_nLiczbaPracownikow; i++) {
		if (tablica[i]->Porownaj(p) == 0) {
			return;
		}
		if (tablica[i]->Porownaj(p) > 0) {
			for (int j = ++m_nLiczbaPracownikow; j > i; j--) {
				*tablica[j] = *tablica[j - 1];
			}
			tablica[i] = new Pracownik(p);

			return;
		}
	}
	tablica[i] = new Pracownik(p);
	m_nLiczbaPracownikow++;
}

void WirtualnaTablicaPracownikow::Usun(const Pracownik & wzorzec)
{
}

void WirtualnaTablicaPracownikow::WypiszPracownikow() const
{
}

const Pracownik * WirtualnaTablicaPracownikow::Szukaj(const char * nazwisko, const char * imie)
{
	return nullptr;
}
