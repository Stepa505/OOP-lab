#include "BoolVector.h"
#include<iostream>
#include<assert.h>
#include<stdint.h>
#include<string.h>
#include<string>

BoolVector::BoolVector() {
	m_lenght = 8;
	m_cellCount = 1;
	m_cells = new Cell[m_cellCount]; //массив байтовых значений элементов
	m_cells[0] = false; //клетка состоит из всех нулей
}

BoolVector::BoolVector(const bool value, const int lenght) {
	assert(lenght >= 0);
	m_lenght = lenght;
	m_cellCount = lenght / m_cellSize + bool(lenght % m_cellSize)/*если остаток есть то добавит одну клетку*/;
	m_insignificantRankCount = (m_cellCount * m_cellSize) - lenght;
	m_cells = new Cell[m_cellCount];
	uint8_t mask = 0;
	if (value) mask = ~mask;
	for (int i = 0; i < m_cellCount; i++) {
		m_cells[i] = mask;
	}
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] >> m_insignificantRankCount;
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] << m_insignificantRankCount;
}

BoolVector::BoolVector(BoolVector& other) 
	:m_lenght(other.m_lenght)
{
	m_cellCount = other.m_cellCount;
	m_cells = new Cell[m_cellCount];
	m_insignificantRankCount = (m_cellCount * m_cellSize) - m_lenght;
	for (int i = 0; i < m_cellCount; i++) {
		m_cells[i] = other.m_cells[i];
	}
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] >> m_insignificantRankCount;
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] << m_insignificantRankCount;
}

BoolVector::BoolVector(const char* str) {
	m_lenght = strlen(str);
	m_cellCount = m_lenght / m_cellSize + bool(m_lenght % m_cellSize);
	m_insignificantRankCount = (m_cellCount * m_cellSize) - m_lenght;
	m_cells = new Cell[m_cellCount];
	for (int i = 0; i < m_lenght; i++) {
		if (str[i] == '1') {
			Set1(i / m_cellSize, i % m_cellSize);
		}
		else {
			Set0(i / m_cellSize, i % m_cellSize);
		}
	}
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] >> m_insignificantRankCount;
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] << m_insignificantRankCount;
}

BoolVector::~BoolVector() {
	delete[] m_cells;
}

BoolVector::BoolRank::BoolRank(Cell* cell, const int& maskoffset) {
	m_cell = cell;
	m_mask = m_mask >> maskoffset;
}

void BoolVector::Set1(const int cell, const int cell_pos) {
	assert(cell >= 0 && cell < m_cellCount && cell_pos < m_cellSize);
	uint8_t mask = 1; //uint8_t - беззнаковый целосичленый тип размеровм 8 бит, соотвествующий Cell
	mask = mask << 7;
	mask = mask >> cell_pos;
	m_cells[cell] = m_cells[cell] | mask; //| - оператор включающего ИЛИ: 0|0 = 0, в противном случае 1
}

void BoolVector::Set0(const int cell, const int cell_pos) {
	assert(cell >= 0 && cell < m_cellCount && cell_pos < m_cellSize);
	uint8_t mask = 1;
	mask = mask << 7;
	mask = mask >> cell_pos;
	m_cells[cell] = m_cells[cell] & ~mask; //& - побитовое И: 1&1 = 1, в противеном случае 0
}

void BoolVector::Swap(BoolVector& other) {
	std::swap(m_lenght, other.m_lenght);
	std::swap(m_cellCount, other.m_cellCount);
	std::swap(m_insignificantRankCount, other.m_insignificantRankCount);
	std::swap(m_cells, other.m_cells);
}

void BoolVector::Print() {
	uint8_t mask = 1;
	//mask = mask << 7;
	for (int i = m_cellCount - 1; i >= 0 ; i--) {
		for (int j = m_cellSize - 1; j >= 0; j--) {
			std::cout << bool(m_cells[i] & mask);
			mask = mask << 1;
		}
		mask = 1;
		//mask = mask << 7;
	}
}

int BoolVector::Lenght() {
	return m_lenght;
}

void BoolVector::Inverse() {
	uint8_t mask = 0;
	mask = ~mask; //mask = 11111111
	for (int i = 0; i < m_cellCount; i++) {
		m_cells[i] = m_cells[i] ^ mask; //^ - оператор исключающего ИЛИ: 1^0 = 1, в противном случае 0
	}
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] >> m_insignificantRankCount;
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] << m_insignificantRankCount;
}

void BoolVector::Set1InRange(const int left_border, const int right_border) {
	assert(left_border >= 0 && right_border < m_lenght);
	for (int i = left_border; i < right_border; i++) {
		Set1(i / m_cellSize, i % m_cellSize);
	}
}

void BoolVector::Set0InRange(const int left_border, const int right_border) {
	assert(left_border >= 0 && right_border < m_lenght);
	for (int i = left_border; i < right_border; i++) {
		Set0(i / m_cellSize, i % m_cellSize);
	}
}

void BoolVector::Set1All() {
	Set1(0, m_lenght);
}

void BoolVector::Set0All() {
	Set0(0, m_lenght);
}

void BoolVector::InverseIndex(const int& index) {
	uint8_t mask = 1;
	mask = mask << 7;
	mask = mask >> (index % m_cellSize);
	const int cell = index / m_cellSize;
	m_cells[cell] = m_cells[cell] ^ mask;
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] >> m_insignificantRankCount;
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] << m_insignificantRankCount;
}

int BoolVector::Weight() {
	uint8_t mask = 1;
	int weight = 0;
	int cells = (m_lenght / m_cellSize) + 1;
	for (int i = 0; i < cells; i++) {
		for (int j = 0; j < m_cellSize; j++) {
			if (m_cells[i] & mask) {
				weight++;
			}
			mask = mask << 1;
		}
		mask = 1;
	}
	return weight;
}

BoolVector BoolVector::operator &(const BoolVector& other) {
	assert(m_lenght == other.m_lenght);
	BoolVector vector(*this);
	const int cells = m_lenght / m_cellSize;
	for (int i = 0; i < cells; i++) {
		vector.m_cells[i] = m_cells[i] & other.m_cells[i];
	}
	return vector;
}

BoolVector BoolVector::operator &=(const BoolVector& other) {
	assert(m_lenght == other.m_lenght);
	const int cells = m_lenght / m_cellSize;
	for (int i = 0; i < cells; i++) {
		m_cells[i] = m_cells[i] & other.m_cells[i];
	}
	return *this;
}

BoolVector BoolVector::operator |=(const BoolVector& other) {
	assert(m_lenght == other.m_lenght);
	const int cells = m_lenght / m_cellSize;
	for (int i = 0; i < cells; i++) {
		m_cells[i] = m_cells[i] | other.m_cells[i];
	}
	return *this;
}

BoolVector BoolVector::operator |(const BoolVector& other) {
	assert(m_lenght == other.m_lenght);
	BoolVector vector(*this);
	const int cells = m_lenght / m_cellSize;
	for (int i = 0; i < cells; i++) {
		vector.m_cells[i] = m_cells[i] | other.m_cells[i];
	}
	return vector;
}

BoolVector BoolVector::operator ^(const BoolVector& other) {
	assert(m_lenght == other.m_lenght);
	BoolVector vector(*this);
	const int cells = m_lenght / m_cellSize;
	for (int i = 0; i < cells; i++) {
		vector.m_cells[i] = m_cells[i] ^ other.m_cells[i];
	}
	return vector;
}

BoolVector BoolVector::operator ^=(const BoolVector& other) {
	assert(m_lenght == other.m_lenght);
	const int cells = m_lenght / m_cellSize;
	for (int i = 0; i < cells; i++) {
		m_cells[i] = m_cells[i] ^ other.m_cells[i];
	}
	return *this;
}

BoolVector BoolVector::operator ~() {
	BoolVector Vector(*this);
	Vector.Inverse();
	return Vector;
}

BoolVector BoolVector::operator =(const BoolVector& other) {
	if (m_lenght != other.m_lenght) {
		delete[] m_cells;
		m_lenght = other.m_lenght;
		m_cells = new Cell[m_lenght];
	}
	if (m_cellCount != other.m_cellCount) m_cellCount = other.m_cellCount;
	if (m_insignificantRankCount != other.m_insignificantRankCount) m_insignificantRankCount = other.m_insignificantRankCount;
	for (int i = 0; i < m_cellCount; i++) m_cells[i] = other.m_cells[i];
	return *this;
}

const BoolVector::BoolRank BoolVector:: operator [](const int& index) const {
	assert(index >= 0 && index < m_lenght);
	return const BoolRank(m_cells + index / m_cellSize, index % m_cellSize);
}

BoolVector::BoolRank BoolVector::operator [](const int& index) {
	assert(index >= 0 && index < m_lenght);
	return BoolRank(m_cells + index / m_cellSize, index % m_cellSize);
}

BoolVector::BoolRank& BoolVector::BoolRank::operator=(const BoolRank& other) {
	operator=((bool)other); //*this присваеватся буловое значение элемента, на который указывает other
	return *this;
}

BoolVector::BoolRank& BoolVector::BoolRank::operator=(const bool value) {
	if (value == 0)
		(*m_cell) &= ~m_mask;
	else
		(*m_cell) |= m_mask;
	return *this;
}

BoolVector::BoolRank::operator bool() const {
	if (*m_cell & m_mask)
		return true;
	else
		return false;
}

BoolVector BoolVector::operator >>(const int& shift) {
	BoolVector tmp(this);
	for (int i = 0; i < shift; i++) {
		tmp[i + shift] = tmp[i];
		tmp[i] = 0;
	}
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] >> m_insignificantRankCount;
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] << m_insignificantRankCount;
	return tmp;
}

BoolVector BoolVector::operator <<(const int& shift) {
	BoolVector tmp(this);
	for (int i = m_lenght - 1; i > shift; i--) {
		tmp[i - shift] = tmp[i];
		tmp[i] = 0;
	}
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] >> m_insignificantRankCount;
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] << m_insignificantRankCount;
	return tmp;
}

BoolVector BoolVector::operator >>=(const int& shift) {
	*this = *this >> shift;
	return *this;
}

BoolVector BoolVector::operator <<=(const int& shift) {
	*this = *this << shift;
	return *this;
}

bool BoolVector::operator ==(const BoolVector& other) const {
	assert(m_cellSize == other.m_cellSize);
	if (m_lenght != other.m_lenght) {
		return false;
	}
	else {
		for (int i = 0; i < m_cellCount; i++) {
			if (m_cells[i] != other.m_cells[i]) {
				return false;
			}
		}
	}
	return true;
}

bool BoolVector::operator !=(const BoolVector& other) const {
	assert(m_cellSize == other.m_cellSize);
	if (m_lenght != other.m_lenght) {
		return true;
	}
	else {
		for (int i = 0; i < m_cellCount; i++) {
			if(m_cells[i] != other.m_cells[i]){
				return true;
			}
		}
	}
	return false;
}

bool BoolVector::operator <=(const BoolVector& other) const {
	assert(m_cellSize == other.m_cellSize);
	for (int i = m_cellCount - 1; i >= 0; i--) {
		if (m_cells[i] > other.m_cells[i]) {
			return false;
		}
	}
	return true;
}

bool BoolVector::operator >=(const BoolVector& other) const {
	assert(m_cellSize == other.m_cellSize);
	for (int i = m_cellCount - 1; i >= 0; i--) {
		if (m_cells[i] < other.m_cells[i]) {
			return false;
		}
	}
	return true;
}

bool BoolVector::operator <(const BoolVector& other) const {
	assert(m_cellSize == other.m_cellSize);
	for (int i = m_cellCount - 1; i >= 0; i--) {
		if (m_cells[i] < other.m_cells[i]) {
			return true;
		}
	}
	return false;
}

bool BoolVector::operator >(const BoolVector& other) const {
	assert(m_cellSize == other.m_cellSize);
	for (int i = m_cellCount - 1; i >= 0; i--) {
		if (m_cells[i] > other.m_cells[i]) {
			return true;
		}
	}
	return false;
}

std::ostream& operator <<(std::ostream& stream, const BoolVector& vector)
{
	stream << "[";
	for (int j = 0; j < vector.m_lenght + vector.m_insignificantRankCount; j++)
	{
		if (j % 8 == 0 && j != 0)
			stream << "][";
		stream << (bool)vector[j] << " ";
	}
	stream << "]" << std::endl;
	return stream;
}

std::istream& operator >>(std::istream& stream, BoolVector& vector)
{
	char* str = new char[vector.Lenght()];
	for (int i = 0; i < vector.Lenght(); i++)
	{
		stream >> str[i];
		if (str[i] != '0') {
			vector[i] = 1;
		}
		else {
			vector[i] = 0;
		}
	}
	delete[]str;
	return stream;
}
 
