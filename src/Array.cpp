#include"Array.h"
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
Array<T>::Array() :Array(10) {};

template<typename T>
void Array<T>::reserve(size_t newCapacity) {
	T* temp = new T[2*newCapacity];
	for (int i = 0; i < length; i++) {
		temp[i] = arr[i];
	}
	this->newCapacity = 2 * newCapacity;
	arr = temp;
}


