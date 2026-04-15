#pragma once
#include <cstddef>
template<typename T>
class Array {
private:
    T* arr;
    size_t length;
    size_t newCapacity;
public:
    Array();
    ~Array();
    Array(size_t length, T initnum={});
    Array& operator=(const Array& o);
    size_t size()const;
    bool empty()const;
    size_t capacity()const;
    void push_back(T e);
    void pop_back();
    T& front();
    T& back();
    T& operator[](size_t index);
    void insert(size_t index, T e);
    void erase(size_t index, T e);
    void clear();
    T* data();
    T& at(size_t index);
    void resize(size_t length, T e);
    void assize(size_t length, T e);
    void reserve(size_t newCapacity);
};