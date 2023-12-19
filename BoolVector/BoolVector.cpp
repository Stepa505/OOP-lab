#include "BoolVector.h"
#include <iostream>
#include <assert.h>

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

