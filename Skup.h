#pragma once
#include "Complex.h"
class Skup
{
private:
	int brojElemenata;
	Complex* nizElemenata{};
public:

	Skup()
	{
		brojElemenata = 0;
	};

	Skup(int n)
	{
		brojElemenata = n;
		nizElemenata = new Complex[brojElemenata];
	}; //konstruktor za zauzimanje prostora u memoriji

	~Skup(); //destruktor 

	inline int duzinaNiza()
	{
		return brojElemenata;
	}; //inline funkcija

	void IzbaciDuplikat(); //izbacuje duplikate..
	void Upit(double realni, double imaginarni); //ispituje da li dat element pripada nasem skupu
	void UcitajElemente(); //ucitava el. sa standardnog ulaza
	void SortirajNerastuci();
	void PrikaziElemente(); //prikazuje el. na standardni izlaz

	Skup* Razlika(Skup& obj);
	Skup* Unija(const Skup& obj);
	Skup* Presek(const Skup& obj);
	Skup& operator=(const Skup& obj);

	friend istream& operator >>(istream& ulaz, Skup& cc);
	friend ostream& operator <<(ostream& izlaz, Skup& cc);
};