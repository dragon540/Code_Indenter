//
// Created by shobhit on 25/6/23.
//

#include <list>
#include <string>
#include <fstream>
#include <iostream>
#include "FileIO.h"

std::list<std::string> FileIO::readLineFromFile(std::string filePath) {
    std::list<std::string> lineTable;

    std::string line;
    std::fstream curr_file (filePath);

    if(curr_file.is_open()) {
        while(getline(curr_file, line)) {
            lineTable.push_front(line);
        }
        curr_file.close();
    }
    return lineTable;
}

std::list<std::string> FileIO::readWordFromFile(std::string filePath) {
    // stores individual words
    std::list<std::string> wordTable;

    std::list<std::string> temp_linetable = readLineFromFile(filePath);
    std::list<std::string>::reverse_iterator rev_it;
    rev_it = temp_linetable.rbegin();
    while( rev_it != temp_linetable.rend() ) {
         std::string line = *rev_it;
         std::string temp_word = "";
         for(unsigned int str_idx = 0; str_idx <= line.length() ; str_idx++) {
             if( (line[str_idx] != ' ') && (line[str_idx] != '\t' && (line[str_idx] != '\n')) ) {
                 temp_word.push_back(line[str_idx]);
             }
             else if(line[str_idx] == ' ') {
                 wordTable.push_front(temp_word);
                 temp_word = "";
             }
             if(str_idx == line.length()) {
                 wordTable.push_front(temp_word);
                 temp_word = "";
             }
         }
         rev_it++;
    }
    /***
    // remove empty elemts from list
    std::list<std::string> :: iterator it;
    it = wordTable.begin();
    while(it != wordTable.end()) {
        std::cout << *it << std::endl;
        //if(it->length() == 0)
          //  wordTable.erase(it);
        it++;
    }***/
    return wordTable;
}