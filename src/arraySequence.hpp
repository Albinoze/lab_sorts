#pragma once
#include "dynamicArray.hpp"
#include "sequence.hpp"
using namespace std;

template<typename T>
class DynamicArraySequence : public Sequence<T>
{
private :
    DynamicArray<T> *_array = nullptr;
    int _size = 0;
public :
    DynamicArraySequence();
    DynamicArraySequence(int count);
    DynamicArraySequence(const T* items, int count);
    DynamicArraySequence(const DynamicArraySequence <T>& array);
    ~DynamicArraySequence();

    T GetFirst() override;
    T GetLast() override;
    int GetSize() const override; 

    void Append(T item) override;
    void Prepend(T item) override;
    void PopFront() override;
    void PopBack() override;
    void InsertAt(T item, int index) override;
    void Out() override;

    Sequence<T> *Concat(Sequence <T> *array) const override;
    Sequence<T> *GetSubsequence(int startIndex, int endIndex) const override;

    T &operator[](int index) const override;
};

template <typename T>
DynamicArraySequence<T>::~DynamicArraySequence()
{
    delete _array;
}

template <typename T>
DynamicArraySequence<T>::DynamicArraySequence()
{
    _array = new DynamicArray<T>();
    _size = 0;
}

template <typename T>
DynamicArraySequence<T>::DynamicArraySequence(int count)
{
    _array = new DynamicArray<T>(count);
    _size = count;
}

template <typename T>
DynamicArraySequence<T>::DynamicArraySequence(const T *items, int count)
{
    _array = new DynamicArray<T>(items, count);
    _size = count;
}

template <typename T>
DynamicArraySequence<T>::DynamicArraySequence(const DynamicArraySequence<T>& array)
{
    _array = new DynamicArray<T>(*array._array);
    _size = array._size;
}

template <typename T>
T DynamicArraySequence<T>::GetFirst()
{
    return _array->Get(0);
}

template <typename T>
T DynamicArraySequence<T>::GetLast()
{
    return _array->Get(GetSize()-1);
}

template <typename T>
int DynamicArraySequence<T>::GetSize() const
{
    return _array->GetSize();
}

template <typename T>
void DynamicArraySequence<T>::Append(T item)
{
    _size++;
    _array->Append(item);
}

template <typename T>
void DynamicArraySequence<T>::Prepend(T item)
{
    _size++;
    _array->Prepend(item);
}

template <typename T>
void DynamicArraySequence<T>::PopFront()
{
    DynamicArray<T> *tmp = new DynamicArray<T>(*_array, 1, _size - 1);
    delete _array;
    _size--;
    _array = tmp;   
}

template <typename T>
void DynamicArraySequence<T>::PopBack()
{
  _array->Resize(_size-1);
  _size--;
}

template <typename T>
void DynamicArraySequence<T>::InsertAt(T item, int index)
{
    _array->InsertAt(item, index);
}

template <typename T>
void DynamicArraySequence<T>::Out()
{
    _array->Out();
}

template <typename T>
T &DynamicArraySequence<T>::operator[](int index) const
{
    if (index < 0 || index >= _size)
    {
        throw std::out_of_range("Index is out of range(operator)");
    }

    return (*this->_array)[index];
}

template <typename T>
Sequence<T> *DynamicArraySequence<T>::GetSubsequence(int startIndex, int endIndex) const
{
    if ((startIndex < 0) || (endIndex < startIndex) || (endIndex >= _size))
    {
        throw std::out_of_range("Indices are out of range");
    }

    DynamicArraySequence<T> *ret = new DynamicArraySequence<T>();
    ret->_array->Resize(endIndex - startIndex + 1);

    for (int i = startIndex, j = 0; i <= endIndex; i++, j++)
    {
        (*ret->_array)[j] = (*this->_array)[i];
    }

    ret->_size = endIndex - startIndex + 1;
    return ret;
}

template <typename T>
Sequence<T> *DynamicArraySequence<T>::Concat(Sequence <T> *array) const
{
    DynamicArraySequence<T> *typecastedArray = (DynamicArraySequence<T> *)array;
    DynamicArraySequence<T> *ret = new DynamicArraySequence<T>(_size + typecastedArray->_size);
    for (int i = 0; i < _size; i++)
    {
        (*ret->_array)[i] = (*this->_array)[i];
    }
  
    for (int i = 0; i < typecastedArray->_size; i++)
    {
        (*ret->_array)[i + this->_size] = (*typecastedArray->_array)[i]; 
    }

    ret->_size = this->_size + typecastedArray->_size;

    return ret;
}

