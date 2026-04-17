#pragma once
#include <cstddef>
#include<stdexcept>
template<typename T>
class Array {
private:
	T* arr;
	size_t length;
	size_t newCapacity;
public:
	Array();
	~Array();
	Array(size_t length, T initnum = {});
	Array(const Array& o);
	const Array& operator=(const Array& o);
	size_t size()const;
	bool empty()const;
	size_t capacity()const;
	void push_back(const T& e);
	void pop_back();
	T& front();
	T& back();
	T& operator[](size_t index);
	void insert(size_t index, const T& e);
	void erase(size_t index);
	void clear();
	const T* data();
	T& at(size_t index);
	void resize(size_t length, T e);
	void assign(size_t length, T e);
	void reserve(size_t newCapacity);
};

template<typename T>
Array<T>::Array(size_t length, T initnum) {
	arr = new T[length];
	newCapacity = length;
	this->length = length;
	for (int i = 0; i < length; i++) {
		arr[i] = initnum;
	}
}

template<typename T>
Array<T>::Array() :Array(0) {
	reserve(10);
};

template<typename T>
Array<T>::Array(const Array& o) {
	delete[] arr;
	arr = new T[o.capacity()];
	for (int i = 0; i < o.size(); i++) {
		arr[i] = o[i];
	}
	arr.newCapacity = o.capacity();
	arr.length = o.size();
}

template<typename T>
Array<T>::~Array() {
	delete[] arr;
	length = 0;
	newCapacity = 0;
}


template<typename T>
const Array<T>& Array<T>::operator=(const Array<T>& o) {
	delete[] arr;
	arr = new T[o.capacity()];
	for (int i = 0; i < o.size(); i++) {
		arr[i] = o[i];
	}
	arr.newCapacity = o.capacity();
	arr.length = o.size();
	return *this;
}

template<typename T>
void Array<T>::reserve(size_t newCapacity) {
	T* temp = new T[newCapacity];
	for (int i = 0; i < length; i++) {
		temp[i] = arr[i];
	}
	this->newCapacity = newCapacity;
	delete[] arr;
	arr = temp;
}

template<typename T>
void Array<T>::resize(size_t length, T e) {
	if (length < this->length) {
		this->length = length;
	}
	else if (length > this->length) {
		reserve(2 * length);
		for (int i = this->length; i < length; i++) {
			arr[i] = e;
		}
		this->length = length;
	}
}

template<typename T>
void Array<T>::assign(size_t length, T initnum) {
	reserve(length);
	this->length = length;
	for (int i = 0; i < length; i++) {
		arr[i] = initnum;
	}
}

template<typename T>
T& Array<T>::operator[](size_t index) {
	return arr[index];
}

template<typename T>
T& Array<T>::front() {
	return arr[0];
}

template<typename T>
T& Array<T>::back() {
	return arr[length - 1];
}

template<typename T>
size_t Array<T>::size() const {
	return length;
}

template<typename T>
size_t Array<T>::capacity() const {
	return newCapacity;
}

template<typename T>
bool Array<T>::empty()const {
	return length == 0;
}

template<typename T>
void Array<T>::clear() {
	length = 0;
}


template<typename T>
const T* Array<T>::data() {
	return arr;
}

template<typename T>
T& Array<T>::at(size_t index) {
	if (index >= length) {
		throw std::out_of_range("Index out of bounds");
	}
	return arr[index];
}

template<typename T>
void Array<T>::push_back(const T& e) {
	if (length >= newCapacity) {
		reserve(newCapacity * 2);
	}
	arr[length++] = e;
}


template<typename T>
void Array<T>::pop_back() {
	if (empty()) {
		throw std::out_of_range("Array is empty");
	}
	length--;
}


template<typename T>
void Array<T>::insert(size_t index, const T& e) {
	if (index > length) {
		throw std::out_of_range("Index out of bounds");
	}
	if (length >= newCapacity) {
		reserve(newCapacity * 2);
	}
	for (int i = length; i > index; --i) {
		data[i] = data[i - 1];
	}
	arr[index] = e;
	++length;
}


template<typename T>
void Array<T>::erase(size_t index) {
	if (index >= length) {
		throw std::out_of_range("Index out of bounds");
	}
	for (int i = index; i < length - 1; ++i) {
		arr[i] = arr[i + 1];
	}
	--length;
}