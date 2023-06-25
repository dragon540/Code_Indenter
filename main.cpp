#include <iostream>

#include "Tokeniser.h"
#include "FileIO.h"

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
    FileIO fio;
    std::list<std::string> f = fio.readWordFromFile("/home/shobhit/Desktop/chef_goes_left_right_left.c");

    //fio.readWordFromFile("/home/shobhit/Desktop/Plan.txt");

    std::list<std::string> :: reverse_iterator rev_it;
    rev_it = f.rbegin();
    while(rev_it != f.rend()) {
        std::cout << *rev_it << std::endl;
        std::cout << rev_it->length() << std::endl;
        rev_it++;
    }
    std::cout << f.size() << std::endl;

    std::cout << std::endl;
    return 0;
}
