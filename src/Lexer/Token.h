#include <string>
enum class TokenType
{
    //Single Character Tokens
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE, 
    DOT, COMMA, MINUS, PLUS, SEMICOLON, SLASH, STAR,

    //One or two Character Tokens
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,

    //Literals
    IDENTIFIER, STRING, NUMBER,

    //Keywords
    AND, OR, CLASS, FOR, WHILE, FUN, 
    FALSE, TRUE, VAR, RETURN, SUPER, THIS,
};

class Token
{

private: 
    TokenType m_type;
    std::string m_lexeme;
    unsigned int m_line;

public:
    Token(TokenType tokenType, const std::string& lexeme, unsigned int line)
        : m_type(tokenType), m_lexeme(lexeme), m_line(line)
    {

    }
    ~Token(){};

    TokenType GetType() const { return m_type; }
    const std::string& GetLexeme() const { return m_lexeme; }
    unsigned int GetLine() const { return m_line; }

};
