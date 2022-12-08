#include "Complex.h"
#include <iostream>
using namespace std;

void Complex::Unos()
{
	cin >> this->realni;
	cout << " ";
	cin >> this->imaginarni;
}
void Complex::Stampanje()
{
	cout << this->realni;
	cout << " ";
	cout << this->imaginarni;
}
istream& operator >> (istream& ulaz, Complex& pisanje)
{
	ulaz >> pisanje.realni >> pisanje.imaginarni;
	return ulaz;
}
ostream& operator << (ostream& izlaz, Complex& pisanje)
{
	izlaz << pisanje.realni << pisanje.imaginarni;
	izlaz << endl;
	return izlaz;
}
Complex Complex::Sabiranje(Complex& obj)
{
	Complex s;
	s.realni = this->realni + obj.realni;
	s.imaginarni = this->imaginarni + obj.imaginarni;
	return s;
}
Complex Complex::operator=(Complex& obj)
{
	if (this != &obj)
	{
		this->realni = obj.realni;
		this->imaginarni = obj.imaginarni;
	}
	return *this;
}
bool Complex::operator==(Complex& pisanje)
{
	if (this->realni == pisanje.realni && this->imaginarni == pisanje.imaginarni)
	{
		return true;
	}
	else
		return false;
}