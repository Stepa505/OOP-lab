#pragma once

class Fraction {
public:
	int numerator;
	int denominator;
	Fraction sum(Fraction const b);
	void print();
	Fraction sub(Fraction const a);
};