#pragma once

class Fraction {
public:
	Fraction() = default;

	Fraction(const int numerator, const int denominator);

	~Fraction() = default;

	void print() const;

	void input();

	int getNumerator();

	int getDenominator();

	void setNumerator(const int value);

	void setDenominator(const int value);

	Fraction Add(const Fraction& k) const;

	Fraction Sub(const Fraction& k) const;

	Fraction Multi(const Fraction& k) const;

	Fraction Div(const Fraction& k) const;

	Fraction Exp(const int n);

	Fraction reduction();

	Fraction reverse()const;

	int GCD();

	Fraction double_to_Fraction(const double& number, const int& ndp);

	bool operator == (const Fraction& other) const;

	bool operator != (const Fraction& other) const;

	bool operator < (const Fraction& other)const;

	bool operator > (const Fraction& other)const;

	Fraction operator +(const Fraction& other)const;

	Fraction operator -(const Fraction& other)const;

	Fraction operator *(const Fraction& other)const;

	Fraction operator /(const Fraction& other)const;

	Fraction operator =(const Fraction& other);
private:
	int m_numerator = 0;

	int m_denominator = 1;
};
