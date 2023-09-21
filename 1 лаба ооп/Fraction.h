#pragma once

class Fraction {
public:
	Fraction(const int numerator, const int denominator);
	~Fraction() = default;
	Fraction sum(Fraction const b);
	void print() const;
	Fraction sub(Fraction const a);
	int getNumerator(const int value);
	int getDenominator(int value);
	void setNumerator() const;
	void setDenominator() const;
	Fraction();
	Fraction Fracion::Add();
	Fraction Fraction::Subtractions(const Fraction& k);
	Fraction Fraction::Multipliction(const Fraction& k) const;
	Fraction Fraction::Division(const Fraction& k) const;
};