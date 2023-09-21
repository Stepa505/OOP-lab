#include "Fraction.h"
#include <iostream>
#include <string>
void Fraction::PrintFract()const
{
	std::cout << m_numerator << "/" << m_denominator << std::endl;
}

Fraction Fraction::Add(const Fraction& k)const
{
	Fraction res;
	res.m_numerator = m_numerator * k.m_denominator + k.m_numerator * m_denominator;
	res.m_denominator = m_denominator * k.m_denominator;
	return res;
}

Fraction Fraction::Subtractions(const Fraction& k)const
{
	Fraction res;
	res.m_numerator = m_numerator * k.m_denominator - k.m_numerator * m_denominator;
	res.m_denominator = m_denominator * k.m_denominator;
	return res;
}

Fraction Fraction::Multipliction(const Fraction& k)const
{
	Fraction res;
	res.m_numerator = m_numerator * k.m_numerator;
	res.m_denominator = m_denominator * k.m_denominator;
	return res;
}

Fraction Fraction::Division(const Fraction& k)const
{
	Fraction res;
	res.m_numerator = m_numerator * k.m_denominator;
	res.m_denominator = m_denominator * k.m_numerator;
	return res;
}

Fraction::Fraction()
{
	m_numerator = 1;
	m_denominator = 1;
}

Fraction::Fraction(int numerator, int denominator){
	: m_numerator(numerator)
{

	if (denominator == 0)
	{
		std::cerr << "Fraction::Fraction: error: denominator is 0, result will be numerator/1.\n";
	}
	else
	{
		m_denominator = denominator;
	}
	if (denominator < 0)
	{
		m_denominator *= -1;
		m_numerator *= -1;
	}

}

int Fraction::getNumerator()const
{
	return m_numerator;
}

int Fraction::getDenominator()const
{
	return m_denominator;
}

void Fraction::setNumerator(const int value)
{
	m_numerator = value;
}

void Fraction::setDenominator(int value)
{
	if (value == 0)
	{
		std::cout << "Fraction::Fraction: error: denominator is 0, result will be numerator/1.";
		m_denominator = 1;
	}
	else {
		m_denominator = value;
	}
}

bool Fraction:: operator == (const Fraction other)
{
	return(m_numerator == other.m_numerator && m_denominator == other.m_denominator);
}

bool Fraction:: operator != (const Fraction other)
{
	return !operator == (other);
}