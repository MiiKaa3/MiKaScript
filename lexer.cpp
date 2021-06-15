#include <iostream>
#include <string>
using namespace std;

class Lexer
{
    private:
        string command;
        int idx = -1;
        char currChar;
    public:
        void recieve(string rec)
        {
            command = rec;
        }

        void print()
        {
            cout << command << endl;
        }

        void advance()
        {
            idx++;
            read();
        }

        void read()
        {
            currChar = command[idx];
        }
};
