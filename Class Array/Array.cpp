#include <assert.h>
#include <iostream>
#include <stdio.h>
#include "Array.h"

Array::Array(const int size, const int value) {
	if (size < 0) {
		std::cerr << "Array::Array: size is negative, invert...\n";
		m_size = -size;

	}
	else {
		m_size = size;
	}

	m_array = new int[m_size];

	for (int i = 0; i < m_size; i++) {
		m_array[i] = value;
	}
}

Array::Array(const Array& other) 
	: m_size(other.m_size)
{
	m_array = new int[m_size];

	for (int i = 0; i < m_size; ++i) {
		m_array[i] = other.m_array[i];
	}
}

Array::~Array() {
	delete[] m_array;
}

void Array::print() const{
	std::cout << '[';
	for (int i = 0; i < m_size - 1; ++i) {
		std::cout << m_array[i] << ",";
	}
	std::cout << m_array[m_size - 1] << "]";
}

int Array::size() const {
	return m_size;
}

void Array::find(const int element) {
	for (int i = 0; i < m_size; i++) {
		if (m_array[i] == element) {
			std::cout << i << ' ' << m_array[i] << std::endl;
			break;
		}
	}
}

int& Array::operator[](const int index) {
	assert(index >= 0 && index < m_size);
	return m_array[index];
}

const int& Array::operator[](const int index) const{
	assert(index >= 0 && index < m_size);
	return m_array[index];
}

Array &Array::operator=(const Array& other) {
	if (this == &other) {
		return *this;
	}

	if (m_size != other.m_size) {
		m_size = other.m_size;
		delete[] m_array;
		m_array = new int[m_size];
	}

	for (int i = 0; i < m_size; ++i) {
		m_array[i] = other.m_array[i];
	}

	return *this;
}