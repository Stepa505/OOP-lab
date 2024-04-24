#pragma once
#include"/OOP-lab/BoolVector/BoolVector.h"
#include <iostream>

class BoolMatrix
{
public:
	BoolMatrix();

	BoolMatrix(int rows, int columns, bool value);

	BoolMatrix(char** matrix, int rows);

	BoolMatrix(const BoolMatrix& other);

	~BoolMatrix();

	int getRows();

	int getColumns();

	void swap(BoolMatrix& other);

	int weight();

	BoolVector conjuctionRows();

	BoolVector disjunctionRows();

	int rowWeight(int row);

	void elementInverse(int row, int column);

	void inverseInRange(int row, int column, int k);

	void set0Element(int row, int column);

	void set1Element(int row, int column);

	void set0InRange(int row, int column, int k);

	void set1InRange(int row, int column, int k);

	BoolMatrix operator =(const BoolMatrix& other);

	const BoolVector& operator [](const int i) const;

	BoolVector& operator [](const int i);

	BoolMatrix operator &(const BoolMatrix& other) const;

	BoolMatrix operator &= (const BoolMatrix& other);

	BoolMatrix operator |(const BoolMatrix& other) const;

	BoolMatrix operator |=(const BoolMatrix& other);

	BoolMatrix operator ^(const BoolMatrix& other) const;

	BoolMatrix operator ^=(const BoolMatrix& other);

	BoolMatrix operator ~() const;

private:

	int m_rows;

	int m_columns;

	BoolVector* m_bool;

};

std::istream& operator >>(std::istream& stream, BoolMatrix& matrix);

std::ostream& operator <<(std::ostream& stream, const BoolMatrix& matrix);

