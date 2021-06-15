#include <string>
#include <map>
using namespace std;

enum TT
{
    NUMBER      = 0,
    PLUS        = 1,
    MINUS       = 2,
    TIMES       = 3,
    DIVIDE      = 4,
    POWER       = 5,
    LPAREN      = 6,
    RPAREN      = 7
};

class Token
{
    public:
        TT type;
        string value;

        Token(TT tokenID, string VALUE)
        {
            type = tokenID;
            value = VALUE;
        }

        operator string () const
        {
            return "string cast workin!";
        }

        friend ostream& operator<<(std::ostream&, const Token&);
};

ostream& operator<<(ostream& os, const Token& token)
{
    string type;
    switch (token.type)
    {
        case 0: type = "NUMBER"; break;
        case 1: type = "PLUS"; break;
        case 2: type = "MINUS"; break;
        case 3: type = "TIMES"; break;
        case 4: type = "DIVIDE"; break;
        case 5: type = "POWER"; break;
        case 6: type = "LPAREN"; break;
        case 7: type = "RPAREN"; break;
    }
    if (token.value == "")
    {
        os << "(" + type + ")";
    }
    else
    {
        os << "(" + type + ":" << token.value << ")";
    }
    
    return os;
}
