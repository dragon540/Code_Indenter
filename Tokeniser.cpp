//
// Created by shobhit on 24/6/23.
//
#include <iostream>

#include "Tokeniser.h"

void Tokeniser::tokenise(std::string word) {
    Token t;
    t.value = word;

    if( (word == "#include") || (word == "#define") ) {
        t.attribute = PRE_PR_KW;
        tokenTable.push_front(t);
    }
    else if( (word == "int") || (word == "short") || (word == "long") || (word == "double") || (word == "float")
    || (word == "char")) {
        t.attribute = DATA_TYPE;
        tokenTable.push_front(t);
    }
    else if( (word == "(") || (word == "[")) {
        t.attribute = L_PAR;
        tokenTable.push_front(t);
    }
    else if( (word == ")") || (word == "]")) {
        t.attribute = R_PAR;
        tokenTable.push_front(t);
    }
    else if( word == "{" ) {
        t.attribute = OPEN_CURLY;
        tokenTable.push_front(t);
    }
    else if( word == "}" ) {
        t.attribute = CLOSE_CURLY;
        tokenTable.push_front(t);
    }
    else if( (word == "if") || (word == "else") || (word == "while") || (word == "do") || (word == "for")
             || (word == "switch")) {
        t.attribute = COND;
        tokenTable.push_front(t);
    }
    else if( (word == ">") || (word == "<") || (word == ">=") || (word == "<=") || (word == "==")
             || (word == "!=")) {
        t.attribute = COMP;
        tokenTable.push_front(t);
    }
    else {
        t.attribute = IDEN;
        tokenTable.push_front(t);
    }
    // few other cases are still left
}

// prints token from token table in original order in which it was inserted
void Tokeniser::printAllToken() {
    std::list<Token> :: reverse_iterator it;
    it = tokenTable.rbegin();
    while(it != tokenTable.rend() ) {
        std::cout << it->value << " : " << it->attribute << std::endl;
        it++;
    }
}