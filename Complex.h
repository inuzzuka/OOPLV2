#pragma once
#include <iostream>
using namespace std;
class Complex
{
private:
	double realni;
	double imaginarni;

public:
	Complex()
	{
		realni = 0;
		imaginarni = 0;
	} //default konstruktor

	void Unos();
	void Stampanje();

	Complex(double a, double b)
	{
		realni = a;
		imaginarni = b;
	}
	Complex(Complex& objekat);

	double getRealni()
	{
		return realni;
	}
	double getImaginarni()
	{
		return imaginarni;
	}

	friend istream& operator >> (istream& ulaz, Complex& pisanje);
	friend ostream& operator << (ostream& izlaz, Complex& pisanje);

	Complex operator = (Complex& pisanje);
	bool operator == (Complex& pisanje);

	Complex Sabiranje(Complex& obj);
};
