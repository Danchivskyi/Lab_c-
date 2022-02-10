#include "Napis.h"
#include <iostream>
#include <string>

Napis::Napis(const char* nap)
{
	Ustaw(nap);
}

Napis::Napis(const Napis & wzor)
{
	Ustaw(wzor.m_pszNapis);
}

Napis::~Napis()
{
	delete[] m_pszNapis;
}

const char* Napis::Zwroc() const
{
	return m_pszNapis;
}

void Napis::Ustaw(const char * nowy_napis)
{
	m_nDl = strlen(nowy_napis);
	m_pszNapis = new char[m_nDl + 1];
	strcpy_s(m_pszNapis, m_nDl + 1, nowy_napis);
}

int Napis::SprawdzNapis(const char * por_napis) const
{
	return strcmp(m_pszNapis, por_napis);
}

Napis & Napis::operator=(const Napis & wzor)  {
	if (&wzor != this) {
		wzor.~Napis();
		this->Ustaw(wzor.m_pszNapis);
	}
	return *this;
}

bool Napis::operator==(const Napis & wzor) const {
	return SprawdzNapis(wzor.m_pszNapis) == 0;
}

std::ostream & operator<<(std::ostream & wy, const Napis & p) {
	return wy << p.m_pszNapis;
}

std::istream & operator>>(std::istream & we, Napis & p)
{
	char tekst[40];
	std::cin >> tekst;
	p.Ustaw(tekst);
	return we;
}
