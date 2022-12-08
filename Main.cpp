#include <iostream>
#include <fstream>
#include "Complex.h"
#include "Skup.h"

using namespace std;

int main()
{
	Skup Oop(5);
	Skup Oop1(3);
	Skup Oop2(2);
	Skup* Oop3;

	ifstream input("Ulaz.txt");
	if (input.good())
	{
		input >> Oop;
		input.close();
		cout << Oop;
	}
	ofstream output("Izlaz.txt");
	if (output.good())
	{
		output << Oop;
		output.close();
	}

	cin >> Oop1;
	cin >> Oop2;

	Oop3 = Oop1.Razlika(Oop2);
	cout << *Oop3;

	Oop3 = Oop1.Unija(Oop2);
	cout << Oop3;

	Oop3 = Oop1.Presek(Oop2);
	cout << Oop3;
}