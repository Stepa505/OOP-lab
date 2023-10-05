#pragma once

class Array {
public:
	Array(const int size = 10, const int value = 0);
	Array(const Array &other);
	Array(Array&& other);
	~Array();
	
	void print() const;

	int size() const;

	void find(const int element);

	void swap(Array& other);

	int &operator[](const int index);

	const int& operator[](const int index) const;

	Array &operator=(const Array &other);
	
	Array operator+(const Array& other) const;

	Array& operator+=(const Array& other);

	

private:
	int* m_array = nullptr;

	int m_size = 0;
};