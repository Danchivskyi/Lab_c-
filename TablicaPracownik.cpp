#include <fstream>
#include "TablicaPracownik.h"

TablicaPracownik::TablicaPracownik() : m_nLiczbaPracownikow(0)
{
}

TablicaPracownik::~TablicaPracownik()
{
}

void TablicaPracownik::Dodaj(const Pracownik & p)
{
	int i;
	for (i = 0; i < m_nLiczbaPracownikow; i++) {
		if (m_pTablica[i].Porownaj(p) == 0) {
			return;
		}
		if (m_pTablica[i].Porownaj(p) > 0) {
			for (int j = ++m_nLiczbaPracownikow; j > i; j--) {
				m_pTablica[j] = m_pTablica[j - 1];
			}
			m_pTablica[i] = p;
			
			return;
		}
	}
	m_pTablica[i] = p;
	m_nLiczbaPracownikow++;
}

void TablicaPracownik::Usun(const Pracownik & wzorzec)
{
	for (int i = 0; i < m_nLiczbaPracownikow; i++) {
		if (m_pTablica[i].Porownaj(wzorzec) == 0) {
			for (i++; i < m_nLiczbaPracownikow; i++) {
				m_pTablica[i - 1] = m_pTablica[i];
			}
			m_nLiczbaPracownikow--;
			return;
		}
	}
}

void TablicaPracownik::WypiszPracownikow() const
{
	for (int i = 0; i < m_nLiczbaPracownikow; i++) {
		std::cout << m_pTablica[i];
	}
}

const Pracownik * TablicaPracownik::Szukaj(const char * nazwisko, const char * imie) const
{
	for (int i = 0; i < m_nLiczbaPracownikow; i++) {
		if (m_pTablica[i].SprawdzImie(imie) == 0 && m_pTablica[i].SprawdzNazwisko(nazwisko) == 0) {
			return &m_pTablica[i];
		}
	}
	return nullptr;
}

const Pracownik * TablicaPracownik::Szukaj(const Data & data_urodzenia) const
{
	for (int i = 0; i < m_nLiczbaPracownikow; i++) {
		if (m_pTablica[i].SprawdzDate(data_urodzenia) == 0) {
			return &m_pTablica[i];
		}
	}
	return nullptr;
}

void TablicaPracownik::ZapiszDoPliku() const
{
	std::ofstream plik;
	plik.open("tablicaPracownikow.txt");
	if (plik.good()) {
		for (int i = 0; i < m_nLiczbaPracownikow; i++) {
			Pracownik p = m_pTablica[i];
			plik << p.Imie() << " " << p.Nazwisko() << " " << p.DataUrodzenia() << std::endl;
		}
	}
	plik.close();
}

void TablicaPracownik::WczytajZPliku()
{
	std::ifstream plik;
	plik.open("tablicaPracownikow.txt");
	if (plik.good()) {
		do {
			char imie[100], nazwisko[100];
			int dzien, miesiac, rok;
			char endl;
			plik >> imie >> nazwisko >> dzien >> miesiac >> rok >> endl;
			Dodaj(Pracownik(imie, nazwisko, dzien, miesiac, rok));
		} while (!plik.eof());
	}
	plik.close();
}
