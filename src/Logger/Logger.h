#include <iostream>
#include <string>
#include <vector>

enum class LogType
{
    WARNING,
    INFO,
    ERROR
};

struct LogMessage
{
    LogType LogType;
    std::string Message;
    size_t Line;
    size_t Column;
};

class Logger
{

public:

    static Logger& GetInstance(bool useColors = true);
    
    static void Error(const std::string& msg, size_t line, size_t column);
    static void Warning(const std::string& msg, size_t line, size_t column);
    static void Info(const std::string& msg, size_t line, size_t column);

    bool HasErrors() const;
    void PrintMessages() const;
    void Clear();
private: 
    Logger(bool useColors)
    {
        m_UseColors = useColors;
    }
    void Log(LogType logType, const std::string msg, size_t line, size_t column);

private:
    static constexpr const char* RED = "\033[1;31m";
    static constexpr const char* YELLOW = "\033[1;33m";
    static constexpr const char* CYAN = "\033[1;36m";
    static constexpr const char* RESET = "\033[0m";

    bool m_UseColors;
    std::vector<LogMessage> m_Messages;
};
