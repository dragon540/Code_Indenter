//
// Created by shobhit on 25/6/23.
//

#include <list>
#include <string>
#include <fstream>
#include <iostream>
#include "FileIO.h"

std::list<std::string> FileIO::removeEmptyElemFromList(std::list<std::string> lt) {
    std::list<std::string> new_lt;
    std::list<std::string> :: iterator it;
    it = lt.begin();
    while(it != lt.end()) {
        if( (!it->empty()) && (int)(*it)[0] != 0) {
            new_lt.push_front(*it);
        }
        it++;
    }
    return new_lt;
}

std::list<std::string> FileIO::removeLinebreakFromElements(std::list<std::string> lt) {
    std::list<std::string> :: iterator it;
    it = lt.begin();
    while(it != lt.end()) {
        std::string temp = *it;
        int len = temp.length();
        //std::cout << len << std::endl;
        //std::cout << (int)temp[len-1] << std::endl;
        if( temp[len-1] == 0) {
            //std::cout << "this word has linebreak = " << temp << std::endl;
            std::string new_temp = "";
            for(unsigned int idx = 0; idx<len-1; idx++) {
                new_temp += temp[idx];
            }
            *it = new_temp;
        }
        it++;
    }
    return lt;
}

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
    wordTable = removeEmptyElemFromList(wordTable);
    wordTable = removeLinebreakFromElements(wordTable);

    return wordTable;
}

std::list<std::string> FileIO::readIndWordFromFile(std::string filePath) {
    std::list<std::string> wordTable = readWordFromFile(filePath);
    std::list<std::string> :: iterator it;
    it = wordTable.begin();
    while(it != wordTable.end()) {
        if((*it)[it->length()-1] == ';') {
            std::cout << "abcd" << std::endl;
            std::string temp = "";

            for(unsigned int idx=0; idx<it->length()-1; idx++)
                temp += (*it)[idx];

            *it = temp;
            wordTable.insert(++it, ";");
            it--;
        }
        it++;
    }
    return wordTable;
}