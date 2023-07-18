#include <iostream>

#include "Tokeniser.h"
#include "FileIO.h"
#include "Rewrite.h"

#include <list>
#include <string>

int main() {

    //Tokeniser tok;
    //tok.tokenise("int");
    //tok.tokenise("main");
    //tok.tokenise("(");
    //tok.tokenise(")");
    //tok.tokenise("{");

    //tok.printAllToken();

    //file func check
    /**FileIO fio;
    std::list<std::string> f = fio.readWordFromFile("/home/shobhit/Desktop/SourceCode_Indenter/src_example/ex.c");

    std::list<std::string> :: reverse_iterator rev_it;
    rev_it = f.rbegin();
    while(rev_it != f.rend()) {
        std::cout << "value = " << *rev_it << " length = " << rev_it->length() << std::endl;
        rev_it++;
    }
    std::cout << f.size() << std::endl;

    std::cout << std::endl;***/

    /**Tokeniser t;
    std::list<Token> tt = t.retTokenTable("/home/shobhit/Desktop/SourceCode_Indenter/src_example/ex.c");

    std::list<Token> :: iterator it;
    it = tt.begin();
    while(it != tt.end()) {
        std::cout << it->value << " - " << it->attribute << std::endl;
        it++;
    }**/

    Rewrite rw;
    std::string text = rw.formattedWriteOnString("/home/shobhit/Desktop/SourceCode_Indenter/src_example/ex.c");
    std::cout << text << std::endl;

    return 0;
}
