#include "test.hpp"

int main()
{
    try
    {
        Sorts_test();
    }
    catch(char *er)
    {
        std::cout << er << '\n';
    }
    
    Seq_test();
    
}


