#include "arraySequence.hpp"
#include "listSequence.hpp"
#include <iostream>

void Seq_Empty()
{
    DynamicArraySequence<int> arr = DynamicArraySequence<int>();
    if (arr.GetSize() == 0)
        std::cout << "OK\n";
    else 
        std::cout << "Empty sequence error\n";
}

void Seq_Add()
{
    DynamicArraySequence<int> arr = DynamicArraySequence<int>();
    arr.Append(0);

    if ((arr.GetSize() == 1) && (arr[0] == 0))
        std::cout << "OK\n";

    else 
        std::cout << "Add error\n";
}

void Seq_Pop()
{
    DynamicArraySequence<int> arr = DynamicArraySequence<int>();
    arr.Append(0);
    arr.PopBack();
    if (arr.GetSize() == 0)
        std::cout << "OK\n";

    else 
        std::cout << "Pop error\n";
}

void Seq_Acces()
{
    DynamicArraySequence<int> arr = DynamicArraySequence<int>();
    arr.Append(0);
    arr.Append(1);
    if ((arr.GetSize() == 2) &&(arr[0] == 0) && (arr[1] == 1))
        std::cout << "OK\n";

    else 
        std::cout << "Acces error\n";
}

void Seq_Find()
{
    DynamicArraySequence<int> arr0 = DynamicArraySequence<int>();
    arr0.Append(1);

    DynamicArraySequence<int> arr = DynamicArraySequence<int>();
    for (int i = 0; i < 10; i++)
        arr.Append(i);

    if ((arr.Find(&arr0, 0) == 1) && (arr.Find(&arr0, 5) == -1))
        std::cout << "OK\n";

    else 
        std::cout << "Find error\n";
}

/*void S_BSort()
{
    DynamicArraySequence<int> *arr = new DynamicArraySequence<int>();
    arr->Append(2);
    arr->Append(1);
    arr->Append(0);
    arr->BubbleSort(arr);
    for (int i = 0; i < 3; i ++)
    {
        if (arr->operator[](i) != i)
        {
            std::cout << "Bubble sort error\n";
            return;
        }
        
    }

    std::cout << "OK\n";
}*/

void S_SSort()
{
    LinkedListSequence<int> *arr = new LinkedListSequence<int>();
    arr->Append(2);
    //arr->Append(1);
    //arr->Append(0);
    arr->ShellSort(arr);
    /*for (int i = 0; i < 3; i ++)
    {
        if (arr->operator[](i) != i)
        {
            std::cout << "Bubble sort error\n";
            return;
        }
        
    }
*/
    std::cout << "OK\n";
}

void Seq_test()
{
    Seq_Empty();
    Seq_Acces();
    Seq_Add();
    Seq_Find();
    Seq_Pop();
}

void Sorts_test()
{
   // S_BSort();
    S_SSort();
}