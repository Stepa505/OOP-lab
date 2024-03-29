#pragma once
#include <iostream>
#include<stdint.h>

class BoolVector
{
public:
	using UI = unsigned int;

	using UC = unsigned char;

	class BoolRank;

	void Print();   

	BoolVector();

	BoolVector(const bool value = false, const UI lenght = 0);

	BoolVector(BoolVector& other);

	BoolVector(const char* str);

	~BoolVector();

	int Lenght();

	void Swap(BoolVector& other);

	void Inverse();

	void Set1(const UI cell, const UI cell_pos);

	void Set0(const UI cell, const UI cell_pos);

	void Set1InRange(const UI cell_left, const UI cell_right);

	void Set0InRange(const UI cell_left, const UI cell_right);

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
	UI m_lenght = 0;

	UI m_cellCount = 0;

	uint8_t m_insignificantRankCount = 0;

	UC* m_cells = nullptr;

	static const uint8_t m_cellSize = 8;
};

class BoolVector::BoolRank
{
public:
	BoolRank(UC* cell, const int maskoffset);

	~BoolRank();

	BoolRank& operator=(const BoolRank& other);

	BoolRank& operator=(const bool value);

	operator bool() const;

	//bool operator==(BoolRank& other)const;

	//bool operator==(const bool value)const;

	//bool operator~()const;

	//bool operator&(const bool value)const;

	//bool operator|(const bool value)const;

	//bool operator^(const bool vale)const;
private:
	uint8_t* m_cell = nullptr;

	uint8_t m_mask = 1 << 7;
};

std::istream& operator >>(std::istream& stream, const BoolVector& vector);

