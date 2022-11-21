#pragma once

template <typename T>
class LinkedList
{
private :
  class List
    {
    public:
        T data;
        List *next;
    };

    List *head = nullptr;
    List *tail = nullptr;

    int _size = 0;
public :
    LinkedList();
    LinkedList(const T *items, int size);
    LinkedList(const LinkedList<T> &list);
    LinkedList(const LinkedList<T> &list, int startIndex, int endIndex);
    ~LinkedList();

    void Append(T item);
    void Prepend(T item);
    void PopBack();
    void PopFront();
    void InsertAt(int index, T item);
    void Out();

    T Get(int index) const;
    T GetLast();
    T GetFirst();

    int GetSize();
    T &operator[](int index) const;

    LinkedList<T>* GetSubList(int startIndex, int endIndex);

    LinkedList<T> operator+=(const LinkedList<T> &list);
    LinkedList<T> operator+(const LinkedList<T> &list) const;

};

template <typename T>
LinkedList<T>::LinkedList()
{
    _size = 0;
    return;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  while (_size!= 0)
    {
      PopBack();
    }
}

template <typename T>
LinkedList<T>::LinkedList(const T *items, int size)
{
    for (int i = 0; i < _size; i++)
    {
        Append(items[i]);
    }
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &list)
{
    List *curFromList = list.head;
    for (int i = 0; i < list._size; i++)
    {
        Append(curFromList->data);
        curFromList = curFromList->next;
    }
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &list, int startIndex, int endIndex)
{
    if ((startIndex < 0) || (endIndex < startIndex) || (startIndex >= list._size))
    {
        throw "InvalidStartIndex";
    }

    if (endIndex < 0) 
    {
        throw "InvalidEndIndex";
    }

    List *cur = list.head;

    for (int i = 0; i < startIndex; i++)
    {
        cur = cur->next;
    }

    for (int i = startIndex; i < endIndex; i++)
    {
        Append(cur->data);
        cur = cur->next;
    } 
}

template <typename T>
int LinkedList<T>::GetSize()
{
    return _size;
}


template <typename T>
void LinkedList<T>::Append(T item)
{
    _size++;

    if (head == nullptr)
    {
        head = new List;
        tail = head;
        head->data = item;
        return;
    }

    tail->next = new List;
    tail  = tail->next;
    tail->data = item;
    tail->next = nullptr;

}

template <typename T>
void LinkedList<T>::Prepend(T item)
{
    _size++;

    if (head == nullptr)
    {
        head = new List;
        tail = head;
        head->data = item;
        return;
    }

    List *tmp = new List;
    tmp->data = item;
    tmp->next = head;
    head = tmp;
}

template <typename T>
void LinkedList<T>::PopBack()
{
    if (tail == nullptr)
    {
      throw std::runtime_error("calling PopBack() in LinkedList with zero elements");
    }

    if (_size == 1)
    {
      delete tail;
      tail = nullptr;
      head = nullptr;
    }
    else
    {    
      List *cur = head;
 //     std::cout<<"size " << _size <<std::endl;
      for (int i = 0; i < _size - 2; i++)
        {
  //        std::cout<<i<<std::endl;
          cur = cur->next;
        }
      delete tail;
      tail = cur;
      tail->next = nullptr;
    }
    _size--;
}


template <typename T>
void LinkedList<T>::PopFront()
{
    _size--;

    if (head == nullptr) return;
    List *cur = head;
    head = head->next;
    if (head == nullptr) tail = head;
    delete cur;
    return;
}

template <typename T>
void LinkedList<T>::InsertAt(int index, T item)
{
    if ((index < 0) || (index >= _size))
    {
        throw "IndexOutOfRange";
    }

    _size++;

    List *cur = head;
    for (int i = 0; i < index; i++)
    {
        cur = cur->next;
    }

    List *tmp = new List;
    tmp->data = item;

    tmp->next = cur->next;
    cur->next = tmp;
    return;
}

template <typename T>
T LinkedList<T>::GetFirst()
{
    return head->data;
}

template <typename T>
T LinkedList<T>::GetLast()
{
    return tail->data;
}

template <typename T>
T LinkedList<T>::Get(int index) const
{
    if ((index < 0) || (index >= _size))
    {
        throw "IndexOutOfRange";
    }
    List *cur = head;
    for (int i = 0; i < index; i++)
    {
        cur = cur->next;
    }
    return cur->data;
}

template <typename T>
LinkedList<T>* LinkedList<T>::GetSubList(int startIndex, int endIndex)
{
    LinkedList<T> res = new LinkedList(this, startIndex, endIndex);
    return  res;
}

template <typename T>
LinkedList<T> LinkedList<T>::operator+=(const LinkedList<T> &list)
{
    List *curFromList = list.head;
    for (int i = 0; i < list._size; i++)
    {
        Append(curFromList->data);
        curFromList = curFromList->next;
    }

    return (*this);  
}

template <typename T>
LinkedList<T> LinkedList<T>::operator+(const LinkedList<T> &list) const
{
    LinkedList<T> newList = (*this);
    newList += list;
    return newList;
}

template <typename T>
void LinkedList<T>::Out()
{
    List *cur = head;
    for (int i = 0; i < _size; i++)
    {
        std::cout << cur->data << " ";
        cur = cur->next;
    }
    std::cout << "\n";
}

template <typename T>
T &LinkedList<T>::operator[](int index) const
{
    if ((index < 0) || (index >= _size))
    {
        throw "IndexOutOfRange";
    }
    List *cur = head;
    for (int i = 0; i < index; i++)
    {
        cur = cur->next;
    }
    return cur->data;
}
