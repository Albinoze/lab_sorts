#pragma once

#include <stdexcept>
#include <iostream>

template <typename T>
class DynamicArray
{
private : 
    T* _storage = nullptr;
    int _size;
    int _allocedSize;
    void Init(int size);
public :
    DynamicArray(const T *items, int size);
    DynamicArray(const DynamicArray<T> &items, int startIndex, int endIndex);
    DynamicArray(int size);
    DynamicArray(const DynamicArray<T> &dynamicArray);
    DynamicArray();

    ~DynamicArray();

    int GetSize() const;
    void Append(T item);
    void Prepend(T item);
    void InsertAt(T item, int index);
    void Resize(int newsize);
    void Set(int index, T item);
    void Out();

    T Get(int index);

    T &operator[](int index);
};

template <typename T>
void DynamicArray<T> :: Init(int size)
{
    if (size == 0)
    {
        _size = 0;
        _allocedSize = 0;
        return;
    }

    if (size < 0)
    {
        throw std::bad_array_new_length();
    }

    _size = size;
    _storage = new T[_size];
    _allocedSize = _size;
}

template <typename T>
DynamicArray<T> :: DynamicArray(int size)
{
    Init(size);
}

template <typename T>
DynamicArray<T> :: DynamicArray(const DynamicArray<T> &dynamicArray)
{
    int size = dynamicArray.GetSize();
    Init(size);
    for (int i = 0; i < size; i++)
    {
        _storage[i] = dynamicArray._storage[i];
    }
}

template <typename T>
DynamicArray<T> :: DynamicArray()
{
    Init(0);
}

template <typename T>
DynamicArray<T> :: DynamicArray(const T *items, int size)
{
    Init(size);
    for (int i = 0; i < size; i++)
    {
        _storage[i] = items[i];
    }
}

template <typename T>
DynamicArray<T> :: DynamicArray(const DynamicArray<T> &items, int startIndex, int endIndex)
{
    if ((startIndex < 0) || (startIndex > endIndex) || (endIndex < 0))
    {
        throw "IndexOutOfRange";
    }
    _size = endIndex - startIndex + 1;
    Init(_size);
    for (int i = 0; i < _size; i++)
    {
        _storage[i] = items._storage[startIndex + i];
    }

}

template <typename T>
DynamicArray<T> :: ~DynamicArray()
{
    delete [] _storage;
}

template <typename T>
int DynamicArray<T> :: GetSize() const
{
    return _size;
}

template <typename T>
void DynamicArray<T> :: Resize(int newsize)
{
    if (newsize == 0)
    {
        if (_size != 0)
        {
            delete [] _storage;
        }
        _size = 0;
        return;
    }

    if (newsize < 0)
    {
        throw "InvalidLenght";
    }
    if (_allocedSize == 0) _allocedSize = 1;
    while (_allocedSize < newsize)
    {
        _allocedSize *= 2;
    }

    if (_allocedSize < newsize)  _allocedSize = newsize;
    T *newArr = new T[_allocedSize];

    for(int i = 0; i < _size; i ++)
    {
        if (i < _size) newArr[i] = _storage[i];
        else newArr[i] = 0;
    }

    _size = newsize;
    if (_storage != nullptr)
      delete [] _storage;
    _storage  = newArr;
    return;
}

template <typename T>
T DynamicArray<T> :: Get(int index)
{
    if (index >= _size)
    {
        throw "IndexOutOfRange";
    }
    return _storage[index];
}

template <typename T>
void DynamicArray<T> :: Set(int index, T item)
{
    if (index >= _size)
    {
        throw "IndexOutOfRange";
    }
    _storage[index] = item;
    return;
}

template <typename T>
void DynamicArray<T> :: Out()
{
    for (int i = 0; i < _size; i++)
    {
        std::cout << _storage[i] << " ";
    }
    std::cout << std::endl;
    return;
}

template <typename T>
void DynamicArray<T> :: Append(T item)
{
    Resize(_size+1);
    _storage[_size-1] = item;
}

template <typename T>
void DynamicArray<T> :: Prepend(T item)
{
    Resize(_size+1);
    for (int i = _size-1; i > 1; i--)
    {
        _storage[i] = _storage[i-1];
    }
    _storage[0] = item;
}

template <typename T>
void DynamicArray<T> :: InsertAt(T item, int index)
{
    if (index == 0)
    {
        Prepend(item);
        return;
    }
    if (index == _size - 1)
    {
        Append(item);
        return;
    }
    Resize(_size+1);
    for (int i = _size - 1; i > index; i--)
    {
        _storage[i] = _storage[i-1];
    }
    _storage[index] = item;
}

template <typename T>
T &DynamicArray<T>::operator[](int index)
{
    if (index < 0 || index >= _size)
    {
        throw std::out_of_range("Index is out of range" );
    }
    return _storage[index];
}