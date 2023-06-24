#include <iostream>

#include "Tokeniser.h"

int main() {

    Tokeniser tok;
    tok.tokenise("int");
    //tok.tokenise("main");
    tok.tokenise("(");
    tok.tokenise(")");
    tok.tokenise("{");

    tok.printAllToken();

    return 0;
}
