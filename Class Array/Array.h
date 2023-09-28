#pragma once

class Array {
public:
	Array(const int size = 10, const int value = 0);
	Array(const Array &other);
	~Array();
	
	void print() const;

	int size() const;

	void find(const int element);

	int &operator[](const int index);

	const int& operator[](const int index) const;

	Array &operator=(const Array &other);
private:
	int* m_array = nullptr;
	int m_size = 0;
};