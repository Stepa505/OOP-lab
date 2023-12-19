#include "BoolVector.h"
#include<iostream>
#include<assert.h>
#include<stdint.h>
#include<string.h>
#include<string>

BoolVector::BoolVector() {
	m_lenght = 8;
	m_cellCount = 1;
	m_cells = new UC[m_cellCount];
	m_cells[0] = false;
}

BoolVector::BoolVector(const bool value, const UI lenght) {
	assert(lenght >= 0);
	m_lenght = lenght;
	m_cellCount = lenght / 8 + bool(lenght % 8);
	m_insignificantRankCount = (m_cellCount * m_cellSize) - lenght;
	m_cells = new UC[m_cellCount];
	uint8_t mask = 0;
	if (value) mask = ~mask;
	for (int i = 0; i < m_cellCount; i++) m_cells[i] = mask;
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] >> m_insignificantRankCount;
	m_cells[m_cellCount - 1] = m_cells[m_cellCount - 1] << m_insignificantRankCount;
}

BoolVector::BoolVector(BoolVector& other) 
	:m_lenght(other.m_lenght)
{
	m_cellCount = other.m_cellCount;
	m_cells = new UC[m_cellCount];
	m_insignificantRankCount = (m_cellCount * m_cellSize) - m_lenght;
	for (int i = 0; i < m_cellCount; i++) m_cells[i] = other.m_cells[i];
}

BoolVector::BoolVector(const char* str) {

}

BoolVector::~BoolVector() {
	delete[] m_cells;
}

//
//BoolVector::BoolVector(const char* str) {
//
//}

void BoolVector::Set1(const int cell, const int cell_pos) {
	assert(cell >= 0 || cell < m_cellCount || cell_pos < m_cellSize);
	uint8_t mask = 1;
	mask = mask << 7 - cell_pos;
	m_cells[cell] = m_cells[cell] | mask;
}

void BoolVector::Set0(const int cell, const int cell_pos) {
	assert(cell >= 0 || cell < m_cellCount || cell_pos < m_cellSize);
	uint8_t mask = 1;
	mask = mask << 7 - cell_pos;
	m_cells[cell] = m_cells[cell] & ~mask;
}

void BoolVector::Swap(BoolVector& other) {
	std::swap(m_lenght, other.m_lenght);
	std::swap(m_cellCount, other.m_cellCount);
	std::swap(m_insignificantRankCount, other.m_insignificantRankCount);
	std::swap(m_cells, other.m_cells);
}

void BoolVector::Print() {
	uint8_t mask = 1;
	for (int i = 0; i < m_cellCount; i++) {
		for (int j = 0; j < m_cellSize; j++) {
			std::cout << bool(m_cells[i] & mask);
			mask = mask << 1;
		}
		mask = 1;
	}
}

int BoolVector::Lenght() {
	return m_lenght;
}

void BoolVector::Inverse() {
	uint8_t mask = 1;
	for (int i = 0; i < m_cellCount; i++) {
		for (int j = 0; j < m_cellSize; j++) {
			m_cells[i] = ~m_cells[i] & mask;
			mask = mask << 1;
		}
		mask = 1;
	}
}

void BoolVector::Set1(const int cell_left, const int cell_right) {
	assert(cell_left >= 0 || cell_right < m_cellCount);
	int range = cell_right - cell_left;
	for (int i = cell_left - 1; i < cell_right; i++) {
		Set1(i / m_cellSize, i % m_cellSize);
	}
}

void BoolVector::Set0(const int cell_left, const int cell_right) {
	assert(cell_left >= 0 || cell_right < m_cellCount);
	int range = cell_right - cell_left;
	for (int i = cell_left - 1; i < cell_right; i++) {
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
	mask = mask << 7 - index % m_cellSize;
	const int cell = index / m_cellSize;
	m_cells[cell] = ~mask & m_cells[cell];
}

int BoolVector::Weight() {
	uint8_t mask = 1;
	int weight = 0;
	const int cells = m_lenght / m_cellSize;
	for (int i = 0; i < cells; i++) {
		for (int j = 0; j < m_cellSize; j++) {
			if (m_cells[i] & mask) weight++;
			mask = mask << 1;
		}
		mask = 1;
	}
	return weight;


}