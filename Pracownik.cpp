#include "Pracownik.h"
#include <time.h>
#include <iostream>


Pracownik::Pracownik(const char* im, const char* naz, int dzien, int miesiac, int rok) : m_nIDZatrudnienia((int) time(NULL))
{
	Imie(im);
	Nazwisko(naz);
	DataUrodzenia(dzien, miesiac, rok);
}

Pracownik::Pracownik(const Pracownik & wzor) :
	Pracownik(wzor.Imie(), wzor.Nazwisko(), wzor.DataUrodzenia().Dzien(), wzor.DataUrodzenia().Miesiac(), wzor.DataUrodzenia().Rok())
{
}

Pracownik::~Pracownik()
{
}

const char * Pracownik::Imie() const
{
	return m_Imie.Zwroc();
}

const char * Pracownik::Nazwisko() const
{
	return m_Naziwsko.Zwroc();
}

const Data Pracownik::DataUrodzenia() const
{
	return m_DataUrodzenia;
}

void Pracownik::Imie(const char * nowe_imie)
{
	m_Imie.Ustaw(nowe_imie);
}

void Pracownik::Nazwisko(const char * nowe_nazwisko)
{
	m_Naziwsko.Ustaw(nowe_nazwisko);
}

void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok)
{
	m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}

int Pracownik::SprawdzImie(const char * por_imie) const
{
	return m_Imie.SprawdzNapis(por_imie);
}

int Pracownik::SprawdzNazwisko(const char * por_nazwisko) const
{
	return m_Naziwsko.SprawdzNapis(por_nazwisko);
}

int Pracownik::SprawdzDate(const Data & data_urodzenia) const
{
	return m_DataUrodzenia.Porownaj(data_urodzenia);
}

int Pracownik::Porownaj(const Pracownik& wzorzec) const
{
	int sprImie = m_Imie.SprawdzNapis(wzorzec.Imie());
	int sprNazwisko = m_Naziwsko.SprawdzNapis(wzorzec.Nazwisko());
	int sprData = m_DataUrodzenia.Porownaj(wzorzec.DataUrodzenia());

	if (sprNazwisko > 0) {
		return 1;
	}
	else if (sprNazwisko == 0) {
		if (sprImie > 0) {
			return 1;
		}
		else if (sprImie == 0) {
			if (sprData > 0) {
				return 1;
			}
			else if (sprData < 0) {
				return -1;
			}
		}
		else {
			return -1;
		}
	}
	else {
		return -1;
	}

	return 0;
}

Pracownik & Pracownik::operator=(const Pracownik & wzor)
{
	if (&wzor != this) {
		this->Imie(wzor.Imie());
		this->Nazwisko(wzor.Nazwisko());
		this->DataUrodzenia(wzor.DataUrodzenia().Dzien(), wzor.DataUrodzenia().Miesiac(), wzor.DataUrodzenia().Rok());
	}
	return *this;
}

const bool & Pracownik::operator==(const Pracownik & wzor) const
{
	return Porownaj(wzor) == 0;
}

std::ostream & operator<<(std::ostream & wy, const Pracownik & p)
{
	return wy << "Imie: " << p.Imie() << "\tNazwisko: " << p.Nazwisko() << "\tData urodzenia: " << p.DataUrodzenia() << std::endl;
}

std::istream & operator>>(std::istream & we, Pracownik & p)
{
	return we >> p.m_Imie >> p.m_Naziwsko >> p.m_DataUrodzenia;
}
