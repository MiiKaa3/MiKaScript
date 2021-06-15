#include <iostream>
#include <vector>
#include <string>
#include "lexer.cpp"
#include "tokens.cpp"

class Shell
{
    private:
        Lexer lexer;
        std::string command;
    public:
        int run()
        {
            // Set up
            std::cout << "MiKaScript>>> ";
            std::getline(std::cin, command);

            // Special Commands
            // TODO: Make these commands builtin functions
            if (command == "exit")
            {
                return 1;
            }

            // Lexer -> Create Tokens
            lexer.recieve(command);
            std::vector<Token> tokens = lexer.tokenize(command);
            
            // Do Stuff with Tokens
            for (Token x : tokens)
                    std::cout << x << " ";
            std::cout << std::endl;

            // Clean Up
            lexer.reset();

            return 0;
        }
};
