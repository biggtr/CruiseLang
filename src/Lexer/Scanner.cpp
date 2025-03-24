#include "Scanner.h"
#include "../Logger/Logger.h"

Scanner::Scanner(const std::string& sourceCode)
        : m_SourceCode(sourceCode), m_CurrentCharIndex(0)
    {
        ScanToken();
    }
bool Scanner::AtTheEnd()
{
    return m_CurrentCharIndex > m_SourceCode.size() ? true : false;
}
void Scanner::AddToken(TokenType type, const std::string& lexeme)
{
    m_Tokens.push_back(new Token(type, lexeme, 3)); // passing hardcoded value for testing i should send the line member variable
}
void Scanner::AddToken(TokenType type)
{
    std::string lexeme = "the Acual value of the lexeme"; // construct the lexeme here from the start of the character to the currentCharIndex
    AddToken(type, lexeme);
}
void Scanner::ScanToken()
{
    while(!AtTheEnd())
    {
        //process the source code and create tokens
        printf("%c", m_SourceCode[m_CurrentCharIndex]);
        char currentChar = m_SourceCode[m_CurrentCharIndex];
        switch (currentChar) 
        {
            case '(': AddToken(TokenType::LEFT_PAREN); break;
            case ')': AddToken(TokenType::RIGHT_PAREN); break;
            case '{': AddToken(TokenType::LEFT_BRACE); break;
            case '}': AddToken(TokenType::RIGHT_BRACE); break;
            case ',': AddToken(TokenType::COMMA); break;
            case '.': AddToken(TokenType::DOT); break;
            case '-': AddToken(TokenType::MINUS); break;
            case '+': AddToken(TokenType::PLUS); break;
            case ';': AddToken(TokenType::SEMICOLON); break;
            case '*': AddToken(TokenType::STAR); break; 
            default:
                      Logger::Error("UnSupported Symbol" + std::string(1, currentChar), m_CurrentLine, 1);
                      break;
        
        }
        m_CurrentCharIndex++;
    }
    if(Logger::GetInstance().HasErrors())
    {
        Logger::GetInstance().PrintMessages();
    }
}
