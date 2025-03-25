#include <string>
#include <vector>
#include "Token.h"
class Scanner
{

private:
    bool AtTheEnd();
    bool Match(const char& expected);
    const char& Advance(); // const char is safe here cuz m_SourceCode outlives the reference
    const char Peek();
    
    void AddToken(TokenType type);
    void AddToken(TokenType type, const std::string& lexeme);

public:
    Scanner(const std::string& sourceCode);
    ~Scanner(){};

    void ScanToken();

private:
    std::string m_SourceCode;
    std::vector<Token*> m_Tokens;
    size_t m_CurrentCharIndex;
    size_t m_CurrentLine;
};
