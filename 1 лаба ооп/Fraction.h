#pragma once

class Fraction {
private:
	int m_numerator = 0;

	int m_denominator = 1;
public:
	Fraction() = default;

	Fraction(const int numerator, const int denominator);

	~Fraction() = default;

	Fraction sum(Fraction const b);

	void print() const;

	void input();

	Fraction sub(Fraction const a);

	int getNumerator();

	int getDenominator();

	void setNumerator(const int value);

	void setDenominator(const int value);

	Fraction Add(const Fraction& k) const;

	Fraction Sub(const Fraction& k) const;

	Fraction Multi(const Fraction& k) const;

	Fraction Div(const Fraction& k) const;

	void reduce();

	bool operator == (const Fraction other) const;

	bool operator != (const Fraction other) const;

	bool operator < (const Fraction other)const;

	bool operator > (const Fraction other)const;

	Fraction operator +(const Fraction other)const;

	Fraction operator -(const Fraction other)const;

	Fraction operator *(const Fraction other)const;

	Fraction operator /(const Fraction other)const;

};