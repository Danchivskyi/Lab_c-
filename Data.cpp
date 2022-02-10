#define max(a, b) (a) > (b) ? (a) : (b)
#define min(a, b) (a) < (b) ? (a) : (b)

#include "Data.h"
#include <iostream>

Data::Data(int d, int m, int r)
	: m_nDzien(d)
	, m_nMiesiac(m)
	, m_nRok(r)
{
}

Data::~Data()
{
}

void Data::Ustaw(int d, int m, int r)
{
	m_nDzien = d;
	m_nMiesiac = m;
	m_nRok = r;
	Koryguj();
}

int Data::Dzien() const
{
	return m_nDzien;
}

int Data::Miesiac() const
{
	return m_nMiesiac;
}

int Data::Rok() const
{
	return m_nRok;
}

void Data::Koryguj()
{
	int d = m_nDzien;
	int m = m_nMiesiac;
	int r = m_nRok;

	m = max(1, min(12, m));

	if (m == 2) { //Luty
		d = max(1, min((r % 4 == 0 && (r % 400 == 0 || r % 100 != 0)) ? 28 : 29, d));
	}
	else if(m <= 7) {//Do lipca
		d = max(1, min(m % 2 == 0 ? 30 : 31, d));
	}
	else {//Od sierpnia
		d = max(1, min((m - 7) % 2 == 0 ? 30 : 31, d));
	}

	m_nDzien = d;
	m_nMiesiac = m;
	m_nRok = r;
}

int Data::Porownaj(Data wzor) const
{
	if (m_nRok > wzor.Rok()) {
		return 1;
	}
	else if (m_nRok == wzor.Rok()) {
		if (m_nMiesiac > wzor.Miesiac()) {
			return 1;
		}
		else if (m_nMiesiac == wzor.Miesiac()) {
			if (m_nDzien > wzor.Dzien()) {
				return 1;
			}
			else if(m_nDzien < wzor.Dzien()) {
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

std::ostream & operator<<(std::ostream & wy, const Data & d) {
	return wy << d.Dzien() << " " << d.Miesiac() << " " << d.Rok();
}

std::istream & operator>>(std::istream & we, Data & wzor) {
	int d, m, r;
	we >> d >> m >> r;
	wzor.Ustaw(d, m, r);
	return we;
}
