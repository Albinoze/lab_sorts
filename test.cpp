#include "test.hpp"

int main()
{
    try
    {
        Seq_test();
        Sorts_test();
    }
    catch(char *er)
    {
        std::cout << er << '\n';
    }
    
}