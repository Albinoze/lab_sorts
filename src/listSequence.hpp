#pragma once
#include <iostream>
#include "sequence.hpp"
#include "linkedList.hpp"
using namespace std;

template<typename T>
class LinkedListSequence : public Sequence<T>
{
private:
    LinkedList<T> *_list;

public :
    LinkedListSequence(const T* items, int count);
    LinkedListSequence();
    LinkedListSequence(const LinkedListSequence <T> &list);
    ~LinkedListSequence();

    T GetFirst() override;
    T GetLast() override;
    int GetSize() const override;

    T &operator[](int index) const override;

    void Append(T item) override;
    void Prepend(T item) override;
    void PopBack() override;
    void PopFront() override;
    void InsertAt(T item, int index) override;
    void Out() override;

    Sequence<T> *Concat(Sequence <T> *sequence) const override;
    Sequence<T> *GetSubsequence(int startIndex, int endIndex) const override;
};

template<typename T>
LinkedListSequence<T>::LinkedListSequence()
{
  _list = new LinkedList<T>();
}

template<typename T>
LinkedListSequence<T>::LinkedListSequence(const T *items, int count)
{
  _list = new LinkedList<T>;
  _list = &LinkedList<T>(items, count);
}

template<typename T>
LinkedListSequence<T>::LinkedListSequence (const LinkedListSequence <T> &list)
{
    this->_list = new LinkedList<T>(*list._list);
}

template<typename T>
LinkedListSequence<T>::~LinkedListSequence()
{
  delete _list;
}

template<typename T>
 T LinkedListSequence<T>::GetFirst()
{
    return _list->GetFirst();
}

template<typename T>
T LinkedListSequence<T>::GetLast()
{
    return _list->GetLast();
}

template<typename T>
int LinkedListSequence<T>::GetSize() const
{
    return _list->GetSize();
}

template<typename T>
void LinkedListSequence<T>::Append(T item)
{
    return _list->Append(item);
}

template<typename T>
void LinkedListSequence<T>::Prepend(T item)
{
    return _list->Prepend(item);
}

template<typename T>
void LinkedListSequence<T>::PopBack()
{
    return _list->PopBack();
}

template<typename T>
void LinkedListSequence<T>::PopFront()
{
    return _list->PopFront();
}

template<typename T>
void LinkedListSequence<T>::InsertAt(T item, int index)
{
    return _list->InsertAt(item, index);
}

template<typename T>
Sequence<T> *LinkedListSequence<T>::Concat(Sequence<T> *sequence) const
{
    LinkedListSequence<T> *list = (LinkedListSequence<T> *) sequence;
    LinkedListSequence<T> *newList = new LinkedListSequence<T>(*this);
    (*newList->_list) += (*list->_list);

    return newList;
}

template<typename T>
Sequence<T> *LinkedListSequence<T>::GetSubsequence(int startIndex, int endIndex) const 
{
    LinkedListSequence<T> *newList = new LinkedListSequence<T>;
    delete newList->_list;
    newList->_list = new LinkedList<T>(*this->_list, startIndex, endIndex+1);
    return (Sequence<T>*)newList;
}

template<typename T>
void LinkedListSequence<T>::Out()
{
    _list->Out();
}

template<typename T>
T &LinkedListSequence<T>::operator[](int index) const
{
    return (*_list)[index];
}
