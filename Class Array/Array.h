#pragma once
#include<iostream>
#include<assert.h>

template <typename ItemType>
class Array {
public:
	template<typename IT, typename AT>
	class TmpIterator;
	typedef TmpIterator<ItemType, Array> Iterator;
	typedef TmpIterator<const ItemType, const Array> ConstIterator;
public:
	Array(const int size = 10, const ItemType& value = ItemType());
	Array(const Array& other);
	Array(Array&& other);
	~Array();

	void Sort();

	int Size() const;

	void Resize(const int size);

	int Find(const ItemType& value) const;

	void Swap(Array& other);

	bool DeleteElementValue(const ItemType& value);

	bool DeleteElementIndex(const int& index);

	bool InsertValue(const int index, const ItemType& value);

	bool DeleteAllValue(const ItemType& value);

	bool Delete();

	ItemType Max() const;

	ItemType Min() const;

	const ItemType& operator[](const int& index) const;

	ItemType& operator[](const int& index);

	Array& operator=(const Array& other);

	Array operator+(const Array& other) const;

	Array operator+(const ItemType& value);

	Array& operator+=(const Array& other);

	Array& operator+=(const ItemType& value);

	bool operator !=(const Array& other) const;

	bool operator ==(const Array& other) const;

	Iterator Begin();

	Iterator End();

	ConstIterator Begin()const;

	ConstIterator End()const;

	bool InsertIterValue(Iterator iter, const ItemType& value);

	bool DeleteOfIteratorRange(const Iterator& left, const Iterator& right);

	bool DeleteOfIterator(const Iterator& iter);

private:
	ItemType* m_array = nullptr;

	ItemType m_size = ItemType();
};

template <typename ItemType>
std::ostream& operator<<(std::ostream& stream, const Array<ItemType>& arr);

template <typename ItemType>
std::istream& operator>>(std::istream& stream, Array<ItemType>& arr);

template<typename ItemType>
template<typename IT, typename AT>
class Array<ItemType>::TmpIterator
{
public:
	TmpIterator(AT* array = nullptr, int pos = 0);

	IT& operator*();

	TmpIterator& operator -- ();

	TmpIterator& operator ++ ();

	int Position () const;

	bool operator ==(const TmpIterator& other)const;

	bool operator !=(const TmpIterator& other)const;

	bool operator <=(const TmpIterator& other)const;

	bool operator <(const TmpIterator& other)const;

	bool operator >=(const TmpIterator& other)const;

	bool operator >(const TmpIterator& other)const;
private:
	AT* m_array;
	int m_pos = 0;

};

#include"Array.cpp"