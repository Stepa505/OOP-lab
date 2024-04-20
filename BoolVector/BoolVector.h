#pragma once
#include <iostream>
#include<stdint.h>

class BoolVector
{
public:

	using Cell = unsigned char; //байтовое представление символов

	class BoolRank;

	void Print();   

	BoolVector();

	BoolVector(const bool value = false, const int lenght = 0);

	BoolVector(BoolVector& other);

	BoolVector(const char* str);

	~BoolVector();

	int Lenght();

	void Swap(BoolVector& other);

	void Inverse();

	void Set1(const int cell, const int cell_pos);

	void Set0(const int cell, const int cell_pos);

	void Set1InRange(const int cell_left, const int cell_right);

	void Set0InRange(const int cell_left, const int cell_right);

	void Set1All();

	void Set0All();

	void InverseIndex(const int& index);

	int Weight();

	const BoolVector::BoolRank operator [](const int& index) const;

	BoolVector::BoolRank operator [](const int& index);

	BoolVector operator &(const BoolVector& other) ;

	BoolVector operator &=(const BoolVector& other);

	BoolVector operator |(const BoolVector& other);

	BoolVector operator |=(const BoolVector& other);

	BoolVector operator ^(const BoolVector& other);

	BoolVector operator ^=(const BoolVector& other);

	BoolVector operator =(const BoolVector& other);

	BoolVector operator ~();

	BoolVector operator >>(const int& shift);

	BoolVector operator <<(const int& shift);

	BoolVector operator >>=(const int& shift);

	BoolVector operator <<=(const int& shift);

	bool operator ==(const BoolVector& other) const;

	bool operator !=(const BoolVector& other) const;

	bool operator >=(const BoolVector& other) const;

	bool operator <=(const BoolVector& other) const;

	bool operator >(const BoolVector& other) const;

	bool operator <(const BoolVector& other) const;

	friend std::ostream& operator <<(std::ostream& stream, const BoolVector& vector);
private:
	int m_lenght = 0;

	int m_cellCount = 0;

	uint8_t m_insignificantRankCount = 0;

	Cell* m_cells = nullptr;

	static const uint8_t m_cellSize = 8;
};

class BoolVector::BoolRank
{
public:
	BoolRank(Cell* cell, const int& maskoffset);

	BoolRank& operator=(const BoolRank& other);

	BoolRank& operator=(const bool value);

	operator bool() const;
private:
	uint8_t* m_cell = nullptr;

	uint8_t m_mask = 1 << 7;
};

std::istream& operator >>(std::istream& stream, BoolVector& vector);

