#include "Fraction.h"
#include <iostream>

Fraction Fraction::sum(Fraction const b) {
	Fraction c;
	c.numerator = numerator * b.denominator + b.numerator * denominator;
	c.denominator = denominator * b.denominator;
	return c;
}

void Fraction::print() {
	std :: cout << numerator << "/" << denominator;
}

Fraction Fraction::sub(Fraction a) {
	Fraction c;
	c.numerator = numerator * a.denominator - a.numerator * denominator;
	c.denominator = denominator * a.denominator;
	return c;
}