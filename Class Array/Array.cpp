#ifndef ARRAY_TEMPLATE_LABS
#define ARRAY_TEMPLATE_LABS
#include "Array.h"
#include <assert.h>
#include <iostream>
#include <stdio.h>
template<typename ItemType>
Array<ItemType>::Array(const int size, const ItemType& value) {
	if (size < 0) {
		std::cerr << "Array::Array: size is negative, invert... \n";
		m_size = -m_size;
	}
	else m_size = size;
	
	m_array = new ItemType[size];

	for (int i = 0; i < m_size; i++) m_array[i] = value;
}

template<typename ItemType>
Array<ItemType>::Array(const Array& other)
	:m_size(other.m_size)
{
	m_array = new ItemType[m_size];

	for (int i = 0; i < m_size; i++) m_array[i] = other.m_array[i];
}

template<typename ItemType>
Array<ItemType>::Array(Array&& other) {
	Swap(other);
}

template<typename ItemType>
Array<ItemType>::~Array() {
	delete[] m_array;
}

template<typename ItemType>
void Array<ItemType>::Sort() {
	for (int s = (m_size / 2) + 1; s > 0; s /= 2) {
		for (int i = s; i < m_size; ++i) {
			for (int j = i - s; j >= 0 && m_array[j] > m_array[j + s]; j -= s) {
				ItemType temp = m_array[j];
				m_array[j] = m_array[j + s];
				m_array[j + s] = temp;
			}
		}
	}
}

template<typename ItemType>
void Array<ItemType>::Swap(Array& other){
	std::swap(m_size, other.m_size);
	std::swap(m_array, other.m_array);
}

template<typename ItemType>
int Array<ItemType>::Size() const{
	return m_size;
}

template<typename ItemType>
void Array<ItemType>::Resize(const int size) {
	Array tmp;
	tmp.m_size = size;
	for (int i = 0; i < m_size; i++) {
		tmp.m_array[i] = m_array[i];
	}
	swap(tmp);
	delete[] tmp;
	return *this;
}

template<typename ItemType>
int Array<ItemType>::Find(const ItemType& value) const {
	int k = -1;
	for (int i = 0; i < m_size; i++) {
		if (m_array[i] == value) {
			k = i;
			break;
		}
	}
	return k;
}

template<typename ItemType>
bool Array<ItemType>::DeleteElementValue(const ItemType& value) {
	Array arr(m_size - 1);
	int i = 0, k = 0;
	for (int j = 0; j < m_size; j++) {
		if (m_array[j]==value){
			for (; m_array[i] != value; i++) arr.m_array[i] = m_array[i];
			k++;
			for (; i < m_size; i++) arr.m_array[i] = m_array[i + 1];
		}
	}
	if (k == 0) return false;
	else {
		Swap(arr);
		return true;
	}
}

template<typename ItemType>
bool Array<ItemType>::DeleteElementIndex(const int& index) {
	if (index < 0 || index >= m_size) return false;
	Array arr(m_size - 1);
	int i = 0;
	for (; i < index; i++) arr.m_array[i] = m_array[i];
	for (; i < m_size; i++) arr.m_array[i] = m_array[i + 1];//в условии m_size-1 т.к. будет заход за рамки дальше в приравнивание
	Swap(arr);
	return true;
}

template<typename ItemType>
bool Array<ItemType>::DeleteAllValue(const ItemType& value) {
	if (m_size = 0) {
		return true;
	}
	else {
		Array tmp(0);
		swap(tmp);
		delete[] tmp;
		return true;
	}
}

template<typename ItemType>
bool Array<ItemType>::InsertValue(const int index, const ItemType& value) {
	if (index < 0 || index > m_size) return false;
	Array arr(m_size + 1);
	int i = 0;
	for (; i < index; i++) arr.m_array[i] = m_array[i];
	arr.m_array[i] = value;
	for (; i < m_size; i++) arr.m_array[i + 1] = m_array[i];
	Swap(arr);
	return true;
}

template<typename ItemType>
ItemType Array<ItemType>::Max() const{
	ItemType max = m_array[0];
	for (int i = 1; i < m_size; i++) {
		if (m_array[i] > max) max = m_array[i];
	}
	return max;
}

template<typename ItemType>
ItemType Array<ItemType>::Min() const {
	ItemType min = m_array[0];
		for (int i = 1; i < m_size; i++) {
			if (m_array[i] < min) min = m_array[i];
		}
	return min;
}

template<typename ItemType>
bool Array<ItemType>:: operator ==(const Array& other) const {
	int k = 0;
	if (m_size == other.m_size) {
		for (int i = 0; i < m_size; i++) {
			if (m_array[i] == other.m_array[i]) k++;
		}
	}
	if (k != m_size) return false;
	else return true;
}

template<typename ItemType>
bool Array<ItemType>:: operator !=(const Array& other) const {
	int k = 0;
	if (m_size != other.m_size) {
		for (int i = 0; i < m_size; i++) {
			if (m_array[i] != other.m_array[i]) k++;
		}
	}
	if (k != m_size) return false;
	else return true;
}

template<typename ItemType>
const ItemType& Array<ItemType>:: operator [] (const int& index) const {
	assert(index >= 0 && index < m_size);
	return m_array[index];
}

template<typename ItemType>
ItemType& Array<ItemType>:: operator [] (const int& index) {
	assert(index >= 0 && index < m_size);
	return m_array[index];
}

template<typename ItemType>
Array<ItemType>& Array<ItemType>:: operator = (const Array& other) {
	if (this == &other) return *this;
	if (m_size != other.m_size) {
		delete[] m_array;
		m_size = other.m_size;
		m_array = new ItemType[m_size];
	}
	for (int i = 0; i < m_size; i++) {
		m_array[i] = other.m_array[i];
	}
	return *this;
}

template<typename ItemType>
Array<ItemType> Array<ItemType>:: operator + (const Array& other) const {
	Array result(m_size + other.m_size);
	int i = m_size + other.m_size - 1;
	for (; i > other.m_size - 1; i--) {
		result.m_array[i] = m_array[i - other.m_size];
	}
	for (; i > -1; i--) {
		result.m_array[i] = other.m_array[i];
	}
	return result;
}

template<typename ItemType>
Array<ItemType> Array<ItemType>:: operator + (const ItemType& value) {
	Array result(m_size + 1);
	for (int i = 0; i < m_size; i++) {
		result.m_array[i] = m_array[i];
	}
	result[m_size] = value;
	return result;
}

template<typename ItemType>
Array<ItemType>& Array<ItemType>:: operator += (const Array& other) {
	*this = *this + other;
	return *this;
}

template<typename ItemType>
Array<ItemType>& Array<ItemType>:: operator += (const ItemType& value) {
	*this = *this + value;
	return *this;
}

template <typename ItemType>
std::ostream& operator<<(std::ostream& stream, const Array<ItemType>& arr) {
	stream << "[";
	for (int i = 0; i < arr.Size() - 1; ++i)
	{
		std::cout << arr[i] << ",";
	}
	std::cout << arr[arr.Size() - 1] << "]\n";
	return stream;
}

template <typename ItemType>
std::istream& operator>>(std::istream& stream, Array<ItemType>& arr) {
	for (int i = 0; i < arr.Size(); ++i)
	{
		stream >> arr[i];
	}
	return stream;
}

template <typename ItemType>
template<typename IT, typename AT>
Array<ItemType>::TmpIterator<IT, AT>::TmpIterator(AT* array, int pos) 
	:m_pos(pos),
	m_array(array)
{
}

template <typename ItemType>
template<typename IT, typename AT>
IT& Array<ItemType>::TmpIterator<IT, AT>::operator*() {
	return m_array->operator[](m_pos);
}

template <typename ItemType>
template<typename IT, typename AT>
Array<ItemType>::TmpIterator<IT, AT>& Array<ItemType>::TmpIterator<IT, AT>:: operator--() {
	--m_pos;
	return *this;
}

template <typename ItemType>
template<typename IT, typename AT>
Array<ItemType>::TmpIterator<IT, AT>& Array<ItemType>::TmpIterator<IT, AT>:: operator++() {
	++m_pos;
	return *this;
}

template <typename ItemType>
template<typename IT, typename AT>
int Array<ItemType>::TmpIterator<IT, AT>::Position() const {
	return m_pos;
}

template <typename ItemType>
template<typename IT, typename AT>
bool Array<ItemType>::TmpIterator<IT, AT>::operator == (const TmpIterator& other) const {
	assert(m_array == other.m_array);
	return (m_array == other.m_array && m_pos == other.m_pos);
}

template <typename ItemType>
template<typename IT, typename AT>
bool Array<ItemType>::TmpIterator<IT, AT>::operator != (const TmpIterator& other) const {
	assert(m_array == other.m_array);
	return (m_array == other.m_array && m_pos != other.m_pos);
}

template <typename ItemType>
template<typename IT, typename AT>
bool Array<ItemType>::TmpIterator<IT, AT>::operator <= (const TmpIterator& other) const {
	assert(m_array == other.array);
	return (m_array == other.m_array && m_pos <= other.m_pos);
}

template <typename ItemType>
template<typename IT, typename AT>
bool Array<ItemType>::TmpIterator<IT, AT>::operator >= (const TmpIterator& other) const {
	assert(m_array == other.array);
	return (m_array == other.m_array && m_pos >= other.m_pos);
}

template <typename ItemType>
template<typename IT, typename AT>
bool Array<ItemType>::TmpIterator<IT, AT>::operator < (const TmpIterator& other) const {
	assert(m_array == other.array);
	return (m_array == other.m_array && m_pos < other.m_pos);
}

template <typename ItemType>
template<typename IT, typename AT>
bool Array<ItemType>::TmpIterator<IT, AT>::operator > (const TmpIterator& other) const {
	assert(m_array == other.array);
	return (m_array == other.m_array && m_pos > other.m_pos);
}

template <typename ItemType>typename
Array<ItemType>::Iterator Array<ItemType>::Begin() {
	return Iterator(this, 0);
}

template <typename ItemType>typename
Array<ItemType>::Iterator Array<ItemType>::End() {
	return Iterator(this, m_size);
}

template <typename ItemType>typename
Array<ItemType>::ConstIterator Array<ItemType>::Begin() const{
	return ConstIterator(this, 0);
}

template <typename ItemType>typename
Array<ItemType>::ConstIterator Array<ItemType>::End() const{
	return ConstIterator(this, m_size);
}

template <typename ItemType>
bool Array<ItemType>::InsertIterValue(Iterator iter, const ItemType& value) {
	if (iter.Position() > m_size || iter < Begin()) return false;
	int index = iter.Position();
	if (iter == Begin()) return this->InsertIndex(index, value);
	else if (iter == End()) {
		*this += value;
		return true;
	}
	index--;
	return this->InsertIndex(index, value);
}
template <typename ItemType>
bool Array<ItemType>::DeleteOfIteratorRange(const Iterator& left, const Iterator& right) {
	if (left.Position() < 0 || left.Position() > right.Position() || right.Position() >= m_size) return false;
	for (int i = left.Position() - 1; i <= right.Position(); i++) {
		DeleteElementIndex(i);
	}
	return true;
}

template <typename ItemType>
bool Array<ItemType>::DeleteOfIterator(const Iterator& iter) {
	if (iter.Position() < 0 || iter.Position() >= m_size) return false;
	return this->DeleteElementIndex(iter.Position());
}
#endif
