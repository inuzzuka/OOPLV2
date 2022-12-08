#include "Skup.h"
#include <iostream>
using namespace std;

Skup::~Skup()
{
	if (nizElemenata != 0)
		delete[] nizElemenata;
}

void Skup::IzbaciDuplikat()
{
	for (int i = 0; i < brojElemenata;i++)
	{
		for (int j = i + 1;j < brojElemenata;j++)
		{
			if (nizElemenata[i].getRealni() == nizElemenata[j].getRealni() && nizElemenata[i].getImaginarni() == nizElemenata[j].getImaginarni())
			{
				for (int k = j;k < brojElemenata - 1;k++)
				{
					nizElemenata[k] = nizElemenata[k + 1];;
				}
				brojElemenata--;
				j--;
			}
		}
	}
}

void Skup::Upit(double realni, double imaginarni)
{
	int provera = 0;
	for (int i = 0;i < brojElemenata - 1;i++)
	{
		if (realni == nizElemenata[i].getRealni() && imaginarni == nizElemenata[i].getImaginarni())
			provera = 1;
	}
	if (provera)
		cout << "Postoji." << endl;
	else
		cout << "Ne postoji." << endl;
}

void Skup::UcitajElemente()
{
	cout << "Unesi elemente: " << endl;
	for (int i = 0; i < brojElemenata; i++)
	{
		cin >> nizElemenata[i];
	}
}

void Skup::SortirajNerastuci()
{
	Complex pom;
	for (int i = 0; i < brojElemenata - 1;i++)
	{
		for (int j = 0; j < brojElemenata - 1;j++)
		{
			if (j>=i)
			{
				pom = nizElemenata[i];
				nizElemenata[i] = nizElemenata[j];
				nizElemenata[j] = pom;

			}
		}
	}
}

void Skup::PrikaziElemente()
{
	cout << "Elementi skupa: ";
	for (int i = 0; i < brojElemenata; i++)
		cout << nizElemenata[i] << " ";
}

Skup* Skup::Razlika(Skup& obj)
{
	int k = 0;
	int provera = 0;
	int n = this->brojElemenata < obj.brojElemenata ? this->brojElemenata : obj.brojElemenata; //da sam napisala u normalnom obliku, bilo bi "n undefined"
	Skup* Novi;
	Novi = new Skup(n);
	for (int i = 0; i < this->brojElemenata;i++)
	{
		provera = 0;
		for (int j = 0;j < obj.brojElemenata;j++)
			if (this->nizElemenata[i] == obj.nizElemenata[j])
				provera++;
		if (provera == 0)
		{
			Novi->nizElemenata[k] = this->nizElemenata[i];
			k++;
		}
	}
	Novi->brojElemenata = k;
	return Novi;
}

Skup* Skup::Unija(const Skup& obj)
{
	int n = this->brojElemenata + obj.brojElemenata;
	Skup* Novi;
	Novi = new Skup(n);
	for (int i = 0;this->brojElemenata;i++)
		Novi->nizElemenata[i] = this->nizElemenata[i];
	for (int i = 0; i < obj.brojElemenata;i++)
		Novi->nizElemenata[i + this->brojElemenata] = obj.nizElemenata[i];
	return Novi;
}

Skup* Skup::Presek(const Skup& obj)
{
	int n = this->brojElemenata < obj.brojElemenata ? this->brojElemenata : obj.brojElemenata;
	Skup* Novi;
	Novi = new Skup(n);
	int provera = 0;
	int k = 0;
	for (int i = 0; i < this->brojElemenata;i++)
	{
		provera = 0;
		for (int j = 0; j < obj.brojElemenata;j++)
			if (this->nizElemenata[i] == obj.nizElemenata[j])
				provera++;
		if (provera != 0)
		{
			Novi->nizElemenata[k] = this->nizElemenata[i];
			k++;
		}
	}
	Novi->brojElemenata = k;
	return Novi;
}

Skup& Skup::operator = (const Skup& obj)
{
	if (this != &obj)
	{
		this->brojElemenata = obj.brojElemenata;
		nizElemenata = new Complex[brojElemenata];
		for (int i = 0; i < brojElemenata; i++)
			nizElemenata[i] = obj.nizElemenata[i];
	}
	return *this;
}

istream& operator >> (istream& ulaz, Skup& cc)
{
	ulaz >> cc.brojElemenata;
	for (int i = 0; i < cc.brojElemenata; i++)
		ulaz >> cc.nizElemenata[i];
	return ulaz;
}

ostream& operator << (ostream& izlaz, Skup& cc)
{
	izlaz << cc.brojElemenata << endl;
	for (int i = 0;i < cc.brojElemenata;i++)
		izlaz << cc.nizElemenata[i];
	return izlaz;
}
