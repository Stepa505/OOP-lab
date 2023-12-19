#pragma once
#include <iostream>
#include <assert.h>

class BoolVector
{
public:
	using UI = unsigned int;

	using UC = unsigned char;

	class BoolRank;

	BoolVector();

	BoolVector(const bool value = false, const UI lenght = 0);

	BoolVector(BoolVector& other);

	BoolVector(const char* vector);

	~BoolVector();

	int Lenght();

	void Swap(BoolVector& other);

	void Inverse();

	void Set1();

	void Set0();

	void Set1InRange();

	void Set0InRange();

	void Set1All();

	void Set0All();

	void InverseIndex();

	int Weight();

	const BoolVector::BoolRank operator [](const int& index) const;

	BoolVector::BoolRank operator [](const int& index);

	BoolVector operator &(const BoolVector& other) const;

	BoolVector operator &=(const BoolVector& other);

	BoolVector operator |(const BoolVector& other) const;

	BoolVector operator |=(const BoolVector& other);

	BoolVector operator ^(const BoolVector& other) const;

	BoolVector operator ^=(const BoolVector& other);

	BoolVector operator =(const BoolVector& other);

	BoolVector operator ~() const;

	BoolVector operator >>(const int& shift) const;

	BoolVector operator <<(const int& shift) const;

	BoolVector operator >>=(const int& shift);

	BoolVector operator >>=(const int& shift);

	bool operator ==(const BoolVector& other) const;

	bool operator !=(const BoolVector& other) const;

	bool operator >=(const BoolVector& other) const;

	bool operator <=(const BoolVector& other) const;

	bool operator >(const BoolVector& other) const;

	bool operator <(const BoolVector& other) const;

	friend std::ostream& operator <<(std::ostream& stream, const BoolVector& vector);

private:
	UI m_lenght = 0;

	UI m_cellsCount = 0;

	uint8_t m_insignificantRankCount = 0;

	UC* m_cells = nullptr;

	static const uint8_t m_cellSize = 8;

};

class BoolVector::BoolRank
{
public:

private:
};

std::istream& operator >>(std::istream& stream, const BoolVector& vector);

