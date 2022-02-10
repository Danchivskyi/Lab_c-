#include <iostream>
#include "Kierownik.h"

Kierownik::Kierownik(Napis nazwa, int liczba) : m_NazwaDzialu(nazwa), m_nLiczbaPracownikow(liczba)
{
}

Kierownik::Kierownik(const Kierownik & wzor)
{
	m_NazwaDzialu.Ustaw(wzor.m_NazwaDzialu.Zwroc());
	m_nLiczbaPracownikow = wzor.m_nLiczbaPracownikow;
}

void Kierownik::WypiszDane()
{
	std::cout << m_NazwaDzialu << " " << m_nLiczbaPracownikow;
}

Pracownik * Kierownik::KopiaObiektu()
{
	return new Kierownik(m_NazwaDzialu, m_nLiczbaPracownikow);
}

Kierownik & Kierownik::operator=(const Kierownik & wzor)
{
	if (&wzor != this) {
		this->m_NazwaDzialu = wzor.m_NazwaDzialu;
		this->m_nLiczbaPracownikow = wzor.m_nLiczbaPracownikow;
	}

	return *this;
}

bool Kierownik::operator==(const Kierownik & wzor)
{
	return wzor.m_NazwaDzialu.SprawdzNapis(m_NazwaDzialu.Zwroc()) && wzor.m_nLiczbaPracownikow == m_nLiczbaPracownikow;
}

std::ostream & operator<<(std::ostream wy, const Kierownik & s)
{
	return wy << s.m_NazwaDzialu << " " << s.m_nLiczbaPracownikow;
}

std::istream & operator >> (std::istream we, Kierownik & s)
{
	return we >> s.m_NazwaDzialu >> s.m_nLiczbaPracownikow;
}