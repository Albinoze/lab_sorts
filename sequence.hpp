#pragma once
#include <functional>
#include <stdexcept>


template <typename T>
class Sequence
{
public :
    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual int GetSize() const = 0;

    virtual void Append(T item) = 0;
    virtual void Prepend(T item) = 0;
    virtual void PopBack() = 0;
    virtual void PopFront() = 0;
    virtual void InsertAt(T item, int index) = 0;
    virtual void Out() = 0;
    virtual Sequence<T> *Concat(Sequence <T> *sequence) const = 0;
    virtual Sequence<T> *GetSubsequence(int startIndex, int endIndex) const = 0;

    virtual T &operator[](int index) const = 0;

    int Find(Sequence<T> *sequence, int startIndex = 0) const;
    void Map(const std::function<void(T&)> &func);

    Sequence<T> *BubbleSort(Sequence<T> *_seq);
    Sequence<T> *BubbleSort(Sequence<T> *seq, int endIndex);
    Sequence<T>* BubbleSort(Sequence<T> *seq, int (*cmp)(T, T));

    Sequence<T> *ShellSort(Sequence<T> *_seq);
    Sequence<T> *ShellSort(Sequence<T> *_seq, int endIndex);
    Sequence<T> *ShellSort(Sequence<T> *seq, int (*cmp)(T, T));
    Sequence<T> *ShellSort(Sequence<T> *seq, int (*cmp)(T, T), int endIndex);

private:
    static int Comp(T a, T b)
    {
        if (a > b)
            return 1;
        else 
            return -1;
    };
};


template<class T>
int Sequence<T>::Find(Sequence<T> *sequence, int startIndex) const
{
    if (sequence->GetSize() == 0)
    {
        return -1;
    }

    for (int i = startIndex; i <= this->GetSize() - sequence->GetSize(); i++)
    {
        bool found = true;
        for (int j = 0; j < sequence->GetSize(); j++)
        {
            if (this->operator[](j + i) != sequence->operator[](j))
            {
                found = false;
                break;
            }
        }

        if (found)
        {
            return i;
        }
    }

    return -1;
}

template <typename T>
void Sequence<T>::Map(const std::function<void(T&)> &func)
{
    for (int i = 0; i < this->GetSize(); i++)
    {
        func(this->operator[](i));
    }
}



template<class T>
Sequence<T>* Sequence<T>::BubbleSort(Sequence<T> *seq)
{
    int len = seq->GetSize();
    if (len == 0)
    {
        throw "BlankSequenceError";
    }
    //Sequence<T> *seq = new Sequence<T>(*_seq);
    for(int i = 0; i < len; i++)
    {
        for (int j = 1; j < len - i; j++)
        {
            if ((seq->Comp(seq->operator[](j), seq->operator[](j-1))) < 0)
            {
                std::swap(seq->operator[](j-1), seq->operator[](j));
            }
        }
    }
    return seq;
}

template<class T>
Sequence<T>* Sequence<T>::BubbleSort(Sequence<T> *seq, int endIndex)
{
    int len = endIndex;

    if (len >= seq->GetSize())
        throw "IndexOutOfRange";

    if (len == 0)
        throw "BlankSequenceError";
    
    //Sequence<T> *seq = new Sequence<T>(*_seq);
    for(int i = 0; i < len; i++)
    {
        for (int j = 1; j < len - i; j++)
        {
            if (seq->Comp(seq->operator[](j), seq->operator[](j-1)) < 0)
            {
                std::swap(seq->operator[](j-1), seq->operator[](j));
            }
        }
    }
    return seq;
}

template<class T>
Sequence<T>* Sequence<T>::BubbleSort(Sequence<T> *seq, int (*cmp)(T, T))
{
    int len = seq->GetSize();

    if (len >= seq->GetSize())
        throw "IndexOutOfRange";

    if (len == 0)
        throw "BlankSequenceError";
    
    //Sequence<T> *seq = new Sequence<T>(*_seq);
    for(int i = 0; i < len; i++)
    {
        for (int j = 1; j < len - i; j++)
        {
            if (cmp(seq->operator[](j), seq->operator[](j-1)) < 0)
            {
                std::swap(seq->operator[](j-1), seq->operator[](j));
            }
        }
    }
    return seq;
}




template<class T>
Sequence<T>* Sequence<T>::ShellSort(Sequence<T> *seq)
{
    /*int len = seq->GetSize();
    
    for (int d = len / 2; d != 0; d /=2)
    {
        for (int i = d; i < len; i++)
        {
            int j = i;
            while (j - d > -1)
            {
                if (seq->operator[](j) < seq->operator[](j - d))
                    std :: swap(seq->operator[](j), seq->operator[](j - d));
                j -= d;
            }
        }
    }*/

    return seq->ShellSort(seq, Comp);
}

template<class T>
Sequence<T>* Sequence<T>::ShellSort(Sequence<T> *seq, int endIndex)
{
    /*int len = endIndex;

    if (len >= seq->GetSize())
        throw "IndexOutOfRange";
    
    for (int d = len / 2; d != 0; d /=2)
    {
        for (int i = d; i < len; i++)
        {
            int j = i;
            while (j - d > -1)
            {
                if (seq->operator[](j) < seq->operator[](j - d))
                    std :: swap(seq->operator[](j), seq->operator[](j - d));
                j -= d;
            }
        }
    }*/
    return seq->ShellSort(seq, Comp, endIndex);
}

template<class T>
Sequence<T>* Sequence<T>::ShellSort(Sequence<T> *seq, int (*cmp)(T, T))
{
    /*int len = seq->GetSize();

    if (len == 0)
        throw "BlanKSequenceError";
    
    for (int d = len / 2; d != 0; d /=2)
    {
        for (int i = d; i < len; i++)
        {
            int j = i;
            while (j - d > -1)
            {
                if (cmp(seq->operator[](j), seq->operator[](j - d)) < 0)
                    std :: swap(seq->operator[](j), seq->operator[](j - d));
                j -= d;
            }
        }
    }/*/
    return seq->ShellSort(seq, cmp, seq->GetSize());
}

template<class T>
Sequence<T>* Sequence<T>::ShellSort(Sequence<T> *seq, int (*cmp)(T, T), int endIndex)
{
    int len = endIndex;

    if (len > seq->GetSize())
        throw "IndexOutOfRange";

    if (len == 0)
        throw "BlanKSequenceError";
    
    for (int d = len / 2; d != 0; d /=2)
    {
        for (int i = d; i < len; i++)
        {
            int j = i;
            while (j - d > -1)
            {
                if (cmp(seq->operator[](j), seq->operator[](j - d)) < 0)
                    std :: swap(seq->operator[](j), seq->operator[](j - d));
                j -= d;
            }
        }
    }
    return seq;
}