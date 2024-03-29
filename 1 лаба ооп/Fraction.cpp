﻿#include <iostream>
#include <string>
#include <assert.h>
#include <stdio.h>
#include "Fraction.h"

Fraction::Fraction(const int numerator, const int denominator)
	: m_numerator(numerator) {

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
	std::cout << m_numerator << '/' << m_denominator << std::endl;
}

void Fraction::input() {
	std::cout << "Enter the fraction: ";
	std::cin >> m_numerator;
	std::cout << "/";
	std::cin >> m_denominator;
	while (m_denominator == 0) {
		std::cerr << "Denominator can`t be zero! Please, enter a vallid denominator: ";
		std::cin >> m_denominator;

	}
}

int Fraction::getNumerator() {
	return m_numerator;
}

int Fraction::getDenominator() {
	return m_denominator;
}

void Fraction::setNumerator(const int value) {
	m_numerator = value;
}

void Fraction::setDenominator(const int value) {
	if (value == 0)
	{
		std::cerr << "Fraction::Fraction: error: denominator is 0, result will be numerator/1.";
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
	c.m_denominator = m_denominator * k.m_denominator;
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

bool Fraction::operator == (const Fraction& other) const {
	return(m_numerator == other.m_numerator && m_denominator == other.m_denominator);
}

bool Fraction::operator != (const Fraction& other) const {
	return !operator == (other);
}

bool Fraction::operator < (const Fraction& other)const {
	return((m_numerator * other.m_denominator) < (other.m_numerator * m_denominator));
}

bool Fraction::operator > (const Fraction& other)const {
	return((m_numerator * other.m_denominator) > (other.m_numerator * m_denominator));
}

Fraction Fraction::operator +(const Fraction& other)const {
	return Add(other);
}

Fraction Fraction::operator -(const Fraction& other)const {
	return Sub(other);
}

Fraction Fraction::operator *(const Fraction& other)const {
	return Multi(other);
}

Fraction Fraction::operator /(const Fraction& other)const {
	return Div(other);
}

//����������� �����
Fraction Fraction::Exp(const int n) {
	Fraction c;
	int a = m_numerator, b = m_denominator;
	c.m_numerator = m_numerator;
	c.m_denominator = m_denominator;
	if (n > 0) {
		for (int i = 1; i < n; i++) {
			c.m_numerator *= a;
			c.m_denominator *= b;
		}
	}
	else if (n < 0) {
		c.m_numerator = b;
		c.m_denominator = a;
		int m = -n;
		for (int i = 1; i < m; i++) {
			c.m_denominator *= a;
		}
	}
	return c;
}

int Fraction::GCD() {
	if (m_numerator == 0) return 1;
	while (m_numerator != m_denominator) {
		if (m_numerator > m_denominator) m_numerator -= m_denominator;
		else m_denominator -= m_numerator;
	}
	if (m_numerator > m_denominator) return m_denominator;
	else return m_numerator;
}

Fraction Fraction::reduction() {
	Fraction c;
	c.m_numerator = m_numerator;
	c.m_denominator = m_denominator;
	m_numerator = m_numerator / c.GCD();
	m_denominator = m_denominator / c.GCD();
	return *this;
}

//����������� �����
Fraction Fraction::reverse() const {
	Fraction c;
	c.m_numerator = m_denominator;
	c.m_denominator = m_numerator;
	return c;
}

Fraction Fraction::operator =(const Fraction& other) {
	if (m_numerator == other.m_numerator && m_denominator == other.m_denominator) return *this;
	m_numerator = other.m_numerator;
	m_denominator = other.m_denominator;
	return *this;
}

Fraction Fraction::double_to_Fraction(const double& number,const int& ndp) {
	m_denominator = 1;
	for (int i = 1; i <= ndp; i++) {
		m_denominator *= 10;
	}
	m_numerator = int(number*m_denominator);
	return *this;
}
