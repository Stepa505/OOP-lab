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

Array::Array(Array&& other) {
	swap(other);
}

Array::~Array() {
	delete[] m_array;
}

void Array::swap(Array& other) {
	std::swap(m_size, other.m_size);
	std::swap(m_array, other.m_array);
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

void Array::resize(const int size) {
	if (size < 0)
	{
		std::cerr << "Array::Array: size is negative, invert... \n";
		m_size = -size;
	}

	Array res(size);
	int count = std::min(m_size, size);

	for (int i = 0; i < count; ++i)
	{
		res.m_array[i] = m_array[i];
	}

	res.swap(*this);
}

int Array::find(const int element) {
	for (int i = 0; i < m_size; i++) {
		if (m_array[i] == element) {
			//std::cout << i << ' ' << m_array[i] << std::endl;
			return i;
			break;
		}
		else if (i == m_size - 1) return -1;
	}
}

bool Array::del_el_value(int n){
	int i = this->find(n);
	if (i == -1)
		return false;
	else
		this->del_el_index(i);
	return true;
}

bool Array::del_el_index(int i) {
	if (i >= m_size || i < 0)
		return false;
	for (int j = i; i < m_size - 1; j++)
		m_array[i] = m_array[i + 1];
	this->resize(m_size - 1);
	return true;
}

bool Array::insert_value(int i, const int& value) {
	if (i >= m_size || i < 0)
		return false;
	this->resize(m_size + 1);
	for (int j = m_size - 2; j >= i; j--)
		m_array[i + 1] = m_array[i];
	m_array[i + 1] = value;
	return true;
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

std::ostream& operator<<(std::ostream& stream, const Array& arr){
	stream << "[";
	for (int i = 0; i < arr.size() - 1; ++i)
	{
		std::cout << arr[i] << ",";
	}
	std::cout << arr[arr.size() - 1] << "]" << std::endl;
	return stream;
}

std::istream& operator>>(std::istream& stream, Array& arr){
	for (int i = 0; i < arr.size(); ++i)
	{
		stream >> arr[i];
	}
	return stream;
}