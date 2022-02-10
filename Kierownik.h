#pragma once
#include "Napis.h"
#include "Pracownik.h"

class Kierownik : public Pracownik
{
private:
	Napis m_NazwaDzialu;
	int m_nLiczbaPracownikow;

public:
	Kierownik(Napis nazwa = "", int liczba = 0);
	Kierownik(const Kierownik & wzor);

	virtual void WypiszDane() ;
	virtual Pracownik* KopiaObiektu() ;

	Kierownik & operator=(const Kierownik & wzor);
	bool operator==(const Kierownik & wzor);

	friend std::ostream & operator<<(std::ostream wy, const Kierownik & s);
	friend std::istream & operator>>(std::istream we, Kierownik & s);
};