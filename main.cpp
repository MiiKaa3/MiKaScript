#include <iostream>
#include <string>
#include "shell.cpp"
using namespace std;

int main()
{
    Shell shell;
    int res;

    while (1)
    {
        res = shell.run();
        
        if (res == 1)
        {
            break;
        }
    }

    return 0;
}
