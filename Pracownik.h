#pragma once
#include <iostream>
#include "Napis.h"
#include "Data.h"

class Pracownik
{
public:
	Pracownik(const char* im = "", const char* naz = "", int dzien = 1, int miesiac = 1, int rok = 2000);
	Pracownik(const Pracownik & wzor);
	~Pracownik();
private:
	Napis m_Imie;
	Napis m_Naziwsko;
	Data m_DataUrodzenia;
	const int m_nIDZatrudnienia;
public:
	const char* Imie() const;
	const char* Nazwisko() const;
	const Data DataUrodzenia() const;
	void Imie(const char* nowe_imie);
	void Nazwisko(const char* nowe_nazwisko);
	void DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok);
	int SprawdzImie(const char* por_imie) const;
	int SprawdzNazwisko(const char* por_nazwisko) const;
	int SprawdzDate(const Data& data_urodzenia) const;
	int Porownaj(const Pracownik& wzorzec) const;

	Pracownik & operator=(const Pracownik & wzor);
	const bool & operator==(const Pracownik & wzor) const;

	friend std::ostream & operator<<(std::ostream & wy, const Pracownik & p);
	friend std::istream & operator>>(std::istream & we, Pracownik & p);
};