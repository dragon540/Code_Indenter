//
// Created by shobhit on 12/7/23.
//

#include "Rewrite.h"
#include "Tokeniser.h"

#include <string>
#include <fstream>

std::string Rewrite::ret_nTab(unsigned int tab_length) {
    std::string n_tab = "";
    while(tab_length--) {
        n_tab += "\t";
    }
    return n_tab;
}

std::string Rewrite :: formattedWriteOnString(std::string original_srcFilePath) {
    std::string temp_formattedString = "";
    Tokeniser t = Tokeniser();
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
                temp_formattedString += it->value;
                temp_formattedString += "\n";
                break;
            case 3:
                temp_formattedString += ret_nTab(n_tab);
                temp_formattedString += it->value;
                temp_formattedString += " ";
                break;
            case 4:
                if(temp_formattedString[temp_formattedString.length()-1] == '\n')
                    temp_formattedString += ret_nTab(n_tab);

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
            case 7:
                temp_formattedString += it->value;
                temp_formattedString += "\n";
                n_tab++;
                break;
            case 8:
                n_tab--;
                temp_formattedString += "\n";
                temp_formattedString += ret_nTab(n_tab);
                temp_formattedString += it->value;
                break;
            case 12:
                temp_formattedString += it->value;
                //std::list<Token> :: iterator back_it_toReadCloseBracket;
                //back_it_toReadCloseBracket = it;
                unsigned long formattedStrLen = temp_formattedString.length();
                formattedStrLen--;
                while(formattedStrLen > 0) {
                    //std::string tempStr = back_it_toReadCloseBracket->value;
                    //int tempStrLen = tempStr.length();
                    if(temp_formattedString[formattedStrLen] == '(') {
                        temp_formattedString += " ";
                        break;
                    }
                    else if(temp_formattedString[formattedStrLen] == ')' ||
                    formattedStrLen==1) {
                        temp_formattedString += "\n";
                        break;
                    }
                    formattedStrLen--;
                }
                break;
        }
        //temp_formattedString += "";
        it++;
    }
    return temp_formattedString;

}
void Rewrite::fileRewrite(std::string src_filePath, std::string dest_filePath) {
    std::ofstream dest_filestream;
    dest_filestream.open(dest_filePath, std::ios::out);

    std::string temp_fmtStr = formattedWriteOnString(src_filePath);

    dest_filestream << temp_fmtStr << std::endl;

}