#include <stdio.h>
#include <string>
#include "Lexer/Scanner.h"

int main()
{

    printf("Starting..!\n");
    const std::string sourceCode = "int addTwoInts()";
    Scanner ourScanner = Scanner(sourceCode);
    return 0;
}
