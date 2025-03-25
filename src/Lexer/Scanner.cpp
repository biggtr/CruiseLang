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

const char& Scanner::Advance()
{
    return m_SourceCode[m_CurrentCharIndex++];
}

bool Scanner::Match(const char& expected)
{
    if(AtTheEnd()) return false;
    if(m_SourceCode[m_CurrentCharIndex] != expected) return false;

    m_CurrentCharIndex++;
    return true;
}
const char Scanner::Peek()
{
    if(AtTheEnd()) return '\0';
    return m_SourceCode[m_CurrentCharIndex];
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
        const char& currentChar = Advance();
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
            case '!': 
                      AddToken(Match('=') ? TokenType::BANG_EQUAL : TokenType::BANG);
                      break;
            case '=':
                      AddToken(Match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL);
                      break;
            case '>':
                      AddToken(Match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER);
                      break;
            case '<':
                      AddToken(Match('=') ? TokenType::LESS_EQUAL : TokenType::LESS);
                      break;
            case '/':
                      if(Match('/'))
                      {
                          while(Peek() != '\n' && !AtTheEnd()) Advance();
                      }
                      else 
                      {
                          AddToken(TokenType::SLASH);
                      }

            default:
                      Logger::Error("UnSupported Symbol" + std::string(1, currentChar), m_CurrentLine, 1);
                      break;
        
        }
    }
    if(Logger::GetInstance().HasErrors())
    {
        Logger::GetInstance().PrintMessages();
    }
}
