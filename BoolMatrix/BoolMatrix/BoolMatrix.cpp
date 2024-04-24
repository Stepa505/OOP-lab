#include "BoolMatrix.h"
#include <iostream>
#include<assert.h>
#include <string.h>

BoolMatrix::BoolMatrix() {
	m_rows = 1;
	m_columns = 8;
	m_bool = new BoolVector[m_rows];
	BoolVector vector(m_columns, 1);
	m_bool[0] = vector;
}

BoolMatrix::BoolMatrix(int rows, int columns, bool value) {
	m_rows = rows;
	m_columns = columns;
	m_bool = new BoolVector[m_rows];
	BoolVector vector(value, m_columns);
	for (int i = 0; i < m_rows; i++) {
		m_bool[i] = vector;
	}
}

BoolMatrix::BoolMatrix(char** matrix, int rows) {
	assert(rows > 0);
	m_columns = strlen(matrix[0]);
	m_rows = rows;
	m_bool = new BoolVector[m_rows];
	for (int i = 0; i < m_rows; i++) {
		m_bool[i] = BoolVector(matrix[i]);
	}
}

BoolMatrix::BoolMatrix(const BoolMatrix& other) 
	:m_rows(other.m_rows),
	m_columns(other.m_columns)
{
	for (int i = 0; i < m_rows; i++) {
		m_bool[i] = other.m_bool[i];
	}
}

BoolMatrix::~BoolMatrix() {
	delete[] m_bool;
}

int BoolMatrix::getRows() {
	return m_rows;
}

int BoolMatrix::getColumns() {
	return m_columns;
}

void BoolMatrix::swap(BoolMatrix& other) {
	std::swap(m_rows, other.m_rows);
	std::swap(m_columns, other.m_columns);
	std::swap(m_bool, other.m_bool);
}

int BoolMatrix::weight() {
	int w = 0;
	for (int i = 0; i < m_rows; i++) {
		w += m_bool[i].Weight();
	}
	return w;
}

BoolVector BoolMatrix::conjuctionRows() {
	BoolVector vector(m_bool[0]);
	for (int i = 1; i < m_rows; i++) {
		vector &= m_bool[i];
	}
	return vector;
}

BoolVector BoolMatrix::disjunctionRows() {
	BoolVector vector(m_bool[0]);
	for (int i = 1; i < m_rows; i++) {
		vector |= m_bool[i];
	}
	return vector;
}

int BoolMatrix::rowWeight(int row) {
	assert(row >= 0 && row < m_rows);
	return m_bool[row].Weight();
}

void BoolMatrix::elementInverse(int row, int column) {
	assert(row >= 0 && row < m_rows && column >= 0 && column < m_columns);
	m_bool[row].InverseIndex(column);
}

void BoolMatrix::inverseInRange(int row, int column, int k) {
	assert(row >= 0 && row < m_rows && column >= 0 && column < m_columns && (k + column) <= m_columns);
	for (int i = column; i < k; i++) {
		m_bool[row].InverseIndex(i);
	}
}

void BoolMatrix::set0Element(int row, int column) {
	m_bool[row].Set0(column / m_bool[row].Lenght(), column % m_bool[row].Lenght());
}

void BoolMatrix::set1Element(int row, int column) {
	m_bool[row].Set1(column / m_bool[row].Lenght(), column % m_bool[row].Lenght());
}

void BoolMatrix::set0InRange(int row, int column, int k) {
	m_bool[row].Set0InRange(column, column + k - 1);
}

void BoolMatrix::set1InRange(int row, int column, int k) {
	m_bool[row].Set1InRange(column, column + k - 1);
}

BoolVector& BoolMatrix::operator [](const int i) {
	assert(i >= 0 && i < m_rows);
	return m_bool[i];
}

const BoolVector& BoolMatrix::operator [](const int i) const{
	assert(i >= 0 && i < m_rows);
	return m_bool[i];
}

BoolMatrix BoolMatrix::operator =(const BoolMatrix& other) {
	if (m_bool == other.m_bool) {
		return *this;
	}
	if (m_rows != other.m_rows) {
		m_rows = other.m_rows;
		delete[] m_bool;
		m_bool = new BoolVector[m_rows];
	}
	m_columns = other.m_columns;
	for (int i = 0; i < m_rows; i++) {
		m_bool[i] = other.m_bool[i];
	}
	return *this;
}

BoolMatrix BoolMatrix::operator &(const BoolMatrix& other) const{
	assert(m_rows == other.m_rows && m_columns == other.m_columns);
	BoolMatrix matrix(*this);
	for (int i = 0; i < m_rows; i++) {
		matrix.m_bool[i] &= other.m_bool[i];
	}
	return matrix;
}

BoolMatrix BoolMatrix::operator &=(const BoolMatrix& other) {
	assert(m_rows == other.m_rows && m_columns == other.m_columns);
	for (int i = 0; i < m_rows; i++) {
		m_bool[i] &= other.m_bool[i];
	}
	return *this;
}

BoolMatrix BoolMatrix::operator |(const BoolMatrix & other) const {
	assert(m_rows == other.m_rows && m_columns == other.m_columns);
	BoolMatrix matrix(*this);
	for (int i = 0; i < m_rows; i++) {
		matrix.m_bool[i] |= other.m_bool[i];
	}
	return matrix;
}

BoolMatrix BoolMatrix::operator |=(const BoolMatrix& other) {
	assert(m_rows == other.m_rows && m_columns == other.m_columns);
	for (int i = 0; i < m_rows; i++) {
		m_bool[i] |= other.m_bool[i];
	}
	return *this;
}

BoolMatrix BoolMatrix::operator ^(const BoolMatrix& other) const {
	assert(m_rows == other.m_rows && m_columns == other.m_columns);
	BoolMatrix matrix(*this);
	for (int i = 0; i < m_rows; i++) {
		matrix.m_bool[i] ^= other.m_bool[i];
	}
	return matrix;
}

BoolMatrix BoolMatrix::operator ^=(const BoolMatrix& other) {
	assert(m_rows == other.m_rows && m_columns == other.m_columns);
	for (int i = 0; i < m_rows; i++) {
		m_bool[i] ^= other.m_bool[i];
	}
	return *this;
}

BoolMatrix BoolMatrix::operator ~() const {
	BoolMatrix matrix(*this);
	for (int i = 0; i < m_rows; i++) {
		matrix.m_bool[i] = ~m_bool[i];
	}
	return matrix;
}

std::istream& operator >>(std::istream& stream, BoolMatrix& matrix)
{
	for (int i = 0; i < matrix.getRows(); i++)
	{
		stream >> matrix[i];
	}
	return stream;
}

std::ostream& operator <<(std::ostream& stream, BoolMatrix& matrix)
{
	for (int i = 0; i < matrix.getRows(); i++)
	{
		stream << matrix[i];
	}
	return stream;
}