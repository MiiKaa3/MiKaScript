#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
#include "tokens.cpp"

bool isSpace(char c);
bool isDigitOrPeriod(char c);
bool isDigit(char c);
bool isIdentifierChar(char c);

class Lexer
{
    private:
        std::vector<char> command;
        int idx = -1;
        char currChar = ' ';
    public:
        // Store the command in char vector
        void recieve(std::string rec)
        {
            for (char a : rec)
            {
                command.push_back(a);
            }
        }

        void advance()
        {
            idx++;
            currChar = command[idx];
        }

        Token genNum()
        {
            std::vector<char> res {currChar};
            Token Tres(INT);

            // advance();
            // while (isdigit(currChar))
            // {
            //     res.push_back(currChar);
            //     advance();
            // }

            // idx--;
            return Tres;
        }

        Token genIdentifier()
        {
            // TODO: Code will be pretty much identical to genNum()
            return Token();
        }

        // Iterate over the char vector 
        std::vector<Token> tokenize(std::string rec)
        {
            std::vector<Token> tokens;

            for (char c : command)
            {
                advance();

                if (isSpace(currChar))
                {
                    advance();
                }
                else if (isDigitOrPeriod(currChar))
                {
                    tokens.push_back(genNum());
                }
                else if (isIdentifierChar(currChar))
                {
                    tokens.push_back(genIdentifier());
                }
            }

            return tokens;
        }

        void reset()
        {   
            std::vector<char>().swap(command);
            idx = -1;
            currChar = ' ';
        }
};

bool isSpace(char c)
{
    switch(c)
    {
        case ' ':
        case '\t':
        case '\r':
        case '\n':
            return true;
        default:
            return false;
    }
}

bool isDigitOrPeriod(char c)
{
    switch (c)
    {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '.':
            return true;
        default:
            return false;
    }
}

bool isDigit(char c)
{
    switch (c)
    {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return true;
        default:
            return false;
    }
}

bool isIdentifierChar(char c)
{
    switch (c)
    {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f':
        case 'g':
        case 'h':
        case 'i':
        case 'j':
        case 'k':
        case 'l':
        case 'm':
        case 'n':
        case 'o':
        case 'p':
        case 'q':
        case 'r':
        case 's':
        case 't':
        case 'u':
        case 'v':
        case 'w':
        case 'x':
        case 'y':
        case 'z':
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
        case 'G':
        case 'H':
        case 'I':
        case 'J':
        case 'K':
        case 'L':
        case 'M':
        case 'N':
        case 'O':
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
        case 'T':
        case 'U':
        case 'V':
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
        case '_':
            return true;
        default:
            return false;
    }
}
