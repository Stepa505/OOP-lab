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

BoolVector::BoolVector(const char* value) {

}

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