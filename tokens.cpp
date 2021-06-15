#pragma once
#include <string>

enum TT  // Remeber to add to operator<< cast
{
    INT     ,
    FLOAT   ,
    PLUS    ,
    MINUS   ,
    TIMES   ,
    DIVIDE  ,
    POW   ,
    LPAREN  ,
    RPAREN  ,
    ERROR
};

class Token
{
    public:
        TT type;
        std::string value;

        Token()
        {
            type = ERROR;
            value = "";
        }

        Token(TT tokenID, std::string VALUE)
        {
            type = tokenID;
            value = VALUE;
        }

        Token(TT tokenID)
        {
            type = tokenID;
            value = "";
        }

        friend std::ostream& operator<<(std::ostream&, const Token&);
};

std::ostream& operator<<(std::ostream& os, const Token& token)
{
    std::string type;
    switch (token.type)
    {
        case 0: type = "INT"; break;
        case 1: type = "FLOAT"; break;
        case 2: type = "PLUS"; break;
        case 3: type = "MINUS"; break;
        case 4: type = "TIMES"; break;
        case 5: type = "DIVIDE"; break;
        case 6: type = "POWER"; break;
        case 7: type = "LPAREN"; break;
        case 8: type = "RPAREN"; break;
        case 9: type = "ERROR"; break;
    }
    if (token.value == "")
    {
        os << "[" + type + "]";
    }
    else
    {
        os << "[" + type + ":" << token.value << "]";
    }
    
    return os;
}
