#include <iostream>
#include <string>
#include "lexer.cpp"
using namespace std;

class Shell
{
    private:
        Lexer lexer;
        string command;
    public:
        int run()
        {
            cout << "MiKaScript>>> ";
            getline(cin, command);

            if (command == "exit")
            {
                return 1;
            }

            lexer.recieve(command);
            lexer.print();

            return 0;
        }
};
