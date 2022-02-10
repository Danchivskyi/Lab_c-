#pragma once
#include <iostream>

class Data
{
public:
	Data(int d = 1, int m = 1, int r = 2000);
	~Data();
private:
	int m_nDzien;
	int m_nMiesiac;
	int m_nRok;
	void Koryguj();
public:
	void Ustaw(int d, int m, int r);
	int Dzien() const;
	int Miesiac() const;
	int Rok() const;
	int Porownaj(Data wzor) const;

	friend std::ostream & operator<<(std::ostream & wy, const Data &d);
	friend std::istream & operator>>(std::istream & we, Data &d);
};