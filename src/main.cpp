#include <stdio.h>
#include <string>
#include "Lexer/Scanner.h"

int main()
{

    printf("Starting..!\n");
    const std::string sourceCode = "$ -+1";
    Scanner ourScanner = Scanner(sourceCode);
    return 0;
}
