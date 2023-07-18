//
// Created by shobhit on 12/7/23.
//

#ifndef SOURCECODE_INDENTER_REWRITE_H
#define SOURCECODE_INDENTER_REWRITE_H

#include <string>

#include "Tokeniser.h"
#include "FileIO.h"

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

class Rewrite {
//private:
public:
    std::string ret_nTab(unsigned int tab_length);
    std::string formattedWriteOnString(std::string original_srcFilePath);
//public:
    void fileRewrite(std::string filePath);
};


#endif //SOURCECODE_INDENTER_REWRITE_H
