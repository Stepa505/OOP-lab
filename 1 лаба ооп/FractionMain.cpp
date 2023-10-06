#include "Fraction.h"
#include <iostream>

int main() {
	Fraction c;
	c.input();
	Fraction a(c.getNumerator(), c.getDenominator());
	a.print();
	std::cout << a.Exp(3).getNumerator() << " / " << a.Exp(3).getDenominator() << std::endl;
	std::cout << c.Exp(-3).getNumerator() << " / " << c.Exp(-3).getDenominator() << std::endl;
	std::cout << c.GCD();


}