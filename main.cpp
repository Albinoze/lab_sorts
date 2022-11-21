#include <iostream>
#include <fstream>
#include <ctime>
#include "arraySequence.hpp"
#include <map>
#include <string.h>
#include <ctime>

double TimeMeasure_s(DynamicArraySequence<int> *seq, int len);
double TimeMeasure_b(DynamicArraySequence<int> *seq, int len);

DynamicArraySequence<int> *Sequence_generator(int counter);


int main(int argc, char *argv[])
{
    map <string, int> sorts = {{"bubble", 0}, {"shell", 0}};
    int elements = 1001;
    int step = 50;

    try
    {
        for (int i = 0; i < argc; i++)
        {
            if (argv[i][0] == '-')
            {
                if (strcmp("-bl", argv[i]) == 0)
                    sorts["bubble"] = 1;

                else if (strcmp(argv[i], "-sh") == 0)
                    sorts["shell"] = 1;

                else if(strcmp(argv[i], "-el") == 0)
                {
                    elements  = std::stoi(argv[i+1]);
                    i++;
                }

                else if(strcmp(argv[i], "-st") == 0)
                {
                    step = std::stoi(argv[i+1]);
                    i++;
                }

                else 
                    throw "No matching command";
            }
        }
    }
    catch(const char *error)
    {
        std::cout << error << '\n';
    }
    
    ofstream shellR;
    ofstream bubbleR;
    ofstream shellS;
    ofstream bubbleS;

    std::cout << "step " << step << " el " << elements << std::endl;

    shellR.open("venv/shell_sort_random_data.txt");
    shellS.open("venv/shell_sort_sorted_data.txt");
    bubbleR.open("venv/bubble_sort_random_data.txt");
    bubbleS.open("venv/bubble_sort_sorted_data.txt");


//random sequence
    DynamicArraySequence<int> *seq = Sequence_generator(elements);
    
    for (int counter = step; counter < elements; counter += step)
    {
        std:cout << counter << std::endl;
        try
        {
            if (sorts["shell"] == 1)
            {
                DynamicArraySequence<int> *_seq =  new DynamicArraySequence<int>(*seq);

                double elapsed = TimeMeasure_s(_seq, counter);

                shellR << counter << ' ' << elapsed << std::endl;
            }

            if (sorts["bubble"] == 1)
            {
                DynamicArraySequence<int> *_seq = new DynamicArraySequence<int>(*seq);

                double elapsed = TimeMeasure_b(_seq, counter);

                bubbleR<< counter << ' ' << elapsed << std::endl;
            }
        }
        catch(const char* err)
        {
            std::cout <<  err << '\n';
        }
    }

//sorted sequence
    DynamicArraySequence<int> *seqS = new DynamicArraySequence<int>();

    for (int i = 0; i < elements; i++)
    {
        seqS->Append(i);
    }

    for (int counter = step; counter < elements; counter += step)
    {
        std::cout << counter << std::endl;

        try
        {
            if (sorts["shell"] == 1)
            {
                DynamicArraySequence<int> *_seq =  new DynamicArraySequence<int>(*seqS);
                
                double elapsed = TimeMeasure_s(_seq, counter);

                shellS << counter << ' ' << elapsed << std::endl;
            }

            if (sorts["bubble"] == 1)
            {
                DynamicArraySequence<int> *_seq = new DynamicArraySequence<int>(*seqS);
                
                double elapsed = TimeMeasure_b(_seq, counter);

                bubbleS << counter << ' ' << elapsed << std::endl;
            }
        }
        catch(const char* err)
        {
            std::cout <<  err << '\n';
        }
    }

    if (sorts["shell"] == 1)
    {
        shellR.close();
        shellS.close();
    }
    if (sorts["bubble"] == 1)
    {
        bubbleR.close();
        bubbleS.close();
    }

    system("python3 venv/graphics_builder.py");

    shellR.open("venv/shell_sort_random_data.txt");
    shellS.open("venv/shell_sort_sorted_data.txt");
    bubbleR.open("venv/bubble_sort_random_data.txt");
    bubbleS.open("venv/bubble_sort_sorted_data.txt");

    shellR.close();
    shellS.close();
    bubbleR.close();
    bubbleS.close();
}



DynamicArraySequence<int> *Sequence_generator(int counter)
{
    srand(time(NULL));
    DynamicArraySequence<int> *seq = new DynamicArraySequence<int>();
    srand(time(NULL));

    for (int i = 0; i < counter; i++)
    {
        seq->Append(rand() % 100000);
    }
    return seq;
}

double TimeMeasure_s(DynamicArraySequence<int> *seq, int len)
{
    clock_t begin, end;
    double elapsed;

    begin = clock();
    seq->ShellSort(seq, len);
    end = clock();
    elapsed = double(end - begin)/CLOCKS_PER_SEC;

    return elapsed;
}

double TimeMeasure_b(DynamicArraySequence<int> *seq, int len)
{
    clock_t begin, end;
    double elapsed;

    begin = clock();
    seq->BubbleSort(seq, len);
    end = clock();
    elapsed = double(end - begin)/CLOCKS_PER_SEC;
    
    return elapsed;
}