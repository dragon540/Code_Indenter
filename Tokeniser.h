//
// Created by shobhit on 24/6/23.
//

#ifndef SOURCECODE_INDENTER_TOKENISER_H
#define SOURCECODE_INDENTER_TOKENISER_H

#include <map>
#include <list>
#include <string>

// preprocessor keyword
#define PRE_PR_KW 1
// preprocessor value
#define PRE_PR_VAL 2
// data type
#define DATA_TYPE 3
// identifier(variable name, etc)
#define IDEN 4
// parenthesis - (, ), [, ]
#define L_PAR 5
#define R_PAR 6
// curly braces
#define OPEN_CURLY 7
#define CLOSE_CURLY 8
// conditions - if, else, while, for, do, switch
#define COND 9
// comparator - <, >, <=, >=, ==, !=
#define COMP 10
// literal - "abcd", 8, 'c', 9.7
#define LITERAL 11

class Token {
public:
    std::string value;
    int attribute;
};
class Tokeniser {
    std::list<Token> tokenTable;
    //std::map<std::string, int> tokenTable;
    // <std::string word, int attribute>

public:
    // takes specific words as input
    // and tokenise
    // and adds it to tokenTable list
    void tokenise(std::string word);

    void printAllToken();

    std::list<Token> retTokenTable(std::string original_filePath);

private:
    bool isStringInQuotes(std::string word);
    bool isStringHeaderVal(std::string word);
};


#endif //SOURCECODE_INDENTER_TOKENISER_H
