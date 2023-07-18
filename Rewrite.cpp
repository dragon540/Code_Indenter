//
// Created by shobhit on 12/7/23.
//

#include "Rewrite.h"
#include "Tokeniser.h"

#include <string>

std::string Rewrite::ret_nTab(unsigned int tab_length) {
    std::string n_tab = "";
    while(tab_length--) {
        n_tab += "\\t";
    }
    return n_tab;
}

std::string Rewrite :: formattedWriteOnString(std::string original_srcFilePath) {
    std::string temp_formattedString = "";
    Tokeniser t;
    std::list<Token> temp_tokenTable = t.retTokenTable(original_srcFilePath);
    std::list<Token> :: iterator it;
    it = temp_tokenTable.begin();

    unsigned int n_tab = 0;
    while(it != temp_tokenTable.end()) {
        switch(it->attribute) {
            case 1:
                temp_formattedString += ret_nTab(n_tab);
                temp_formattedString += it->value;
                temp_formattedString += " ";
                break;
            case 2:
                break;
            case 3:
                temp_formattedString += ret_nTab(n_tab);
                temp_formattedString += it->value;
                temp_formattedString += " ";
                break;
            case 4:
                temp_formattedString += it->value;
                temp_formattedString += " ";
                break;
            case 5:
                temp_formattedString += it->value;
                temp_formattedString += "\n";
                n_tab++;
                break;
            case 6:
                temp_formattedString += ret_nTab(n_tab);
                temp_formattedString += it->value;
                temp_formattedString += "\n";
                n_tab--;
                break;

        }
        //temp_formattedString += " ";
        it++;
    }
    return temp_formattedString;

}
/**void Rewrite::fileRewrite(std::string filePath) {
    // tokenise table of words
    Tokeniser tok;

    std::list<Token> :: iterator it;
    it =
}**/
