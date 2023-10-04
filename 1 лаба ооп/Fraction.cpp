#include <iostream>
#include <string>
#include <assert.h>
#include <stdio.h>
#include "Fraction.h"

Fraction::Fraction()
{
	m_numerator = 1;
	m_denominator = 1;
}

Fraction::Fraction(const int numerator,const int denominator)
	: m_numerator(numerator){

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

void Fraction::print() const {

}

void Fraction::input() {
	std::cout << "Enter the fraction: ";
	std::cin >> m_numerator;
	std::cout << "/";
	std::cin >> m_denominator;
	while (m_denominator == 0) {
		std::cout << ("Denominator can`t be zero! Please, enter a vallid denominator: ");
		std::cin >> m_denominator;

	}
}

int Fraction::getNumerator() {
	return m_numerator;
}

int Fraction::getDenominator() {
	return m_denominator;
}

void Fraction::setNumerator(const int value){
	m_numerator = value;
}

void Fraction::setDenominator(const int value) {
	if (value == 0)
	{
		std::cout << "Fraction::Fraction: error: denominator is 0, result will be numerator/1.";
		m_denominator = 1;
	}
	else {
		m_denominator = value;
	}
}

Fraction Fraction::Add(const Fraction& k) const {
	Fraction c;
	c.m_numerator = m_numerator * k.m_denominator + k.m_numerator * m_denominator;
	c.m_denominator = m_denominator * k.m_denominator;
	return c;
}

Fraction Fraction::Sub(const Fraction& k) const {
	Fraction c;
	c.m_numerator = m_numerator * k.m_denominator - k.m_numerator * m_denominator;
	c.m_denominator = m_denominator * k.m_denominator;
	return c;
}

Fraction Fraction::Multi(const Fraction& k) const {
	Fraction c;
	c.m_numerator = m_numerator * k.m_numerator;
	c.m_denominator = m_denominator * f.m_denominator;
	return c;
}

Fraction Fraction::Div(const Fraction& k) const {
	Fraction c;
	if (k.m_numerator == 0)
	{
		std::cerr << "the division operation is not possible because the numerator is 0. Result will be second farction" << std::endl;
		return k;
	}
	c.m_numerator = m_numerator * k.m_denominator;
	c.m_denominator = m_denominator * k.m_numerator;
	return c;
}

bool Fraction::operator == (const Fraction other) const {
	return(m_numerator == other.m_numerator && m_denominator == other.m_denominator);
}

bool Fraction::operator != (const Fraction other) const {
	return !operator == (other);
}

bool Fraction::operator < (const Fraction other)const {
	return((m_numerator * other.m_denominator) < (other.m_numerator * m_denominator));
}

bool Fraction::operator > (const Fraction other)const {
	return((m_numerator * other.m_denominator) > (other.m_numerator * m_denominator));
}

Fraction Fraction::operator +(const Fraction other)const {
	return Add(other);
}

Fraction Fraction::operator -(const Fraction other)const {
	return Sub(other);
}

Fraction Fraction::operator *(const Fraction other)const {
	return Multi(other);
}

Fraction Fraction::operator /(const Fraction other)const {
	return Div(other);
}

Fraction Fraction::Exp(const int n) const{
	Fraction c;
	int a = c.m_numerator, b = c.m_denominator;
	if (n > 0) {
		for (int i = 0; i < n; i++) {
			c.m_numerator *= a;
			c.m_denominator *= b;
		}
	}
	else if (n < 0) {
		c.m_numerator = b;
		c.m_denominator = a;
		for (int i = 0; i < n; i++) {
			c.m_denominator *= a;
		}
	}
	return c;
}


