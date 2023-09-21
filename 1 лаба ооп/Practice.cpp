#include "Fraction.h"
#include <iostream>

int main() {
	Fraction m, n, s;
	m.numerator = 5;
	m.denominator = 10;
	n.numerator = 2;
	n.denominator = 3;
	s = n.sum(m);
	s.print();
	s = n.sub(m);
	s.print();
}