#include <iostream>

#include "Tokeniser.h"
#include "FileIO.h"
#include "Rewrite.h"

#include <list>
#include <string>

int main() {
    Rewrite rw;
    rw.fileRewrite("/home/shobhit/Desktop/SourceCode_Indenter/src_example/ex.c",
                   "/home/shobhit/Desktop/SourceCode_Indenter/OP_src_example/OPex.c");
    return 0;
}
