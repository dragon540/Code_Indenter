//
// Created by shobhit on 25/6/23.
//

#ifndef SOURCECODE_INDENTER_FILEIO_H
#define SOURCECODE_INDENTER_FILEIO_H

#include <list>
#include <string>

class FileIO {
public:
    // takes a list of std::string in argument and returns a list after removing all the empty elements
    // of the original list
    std::list<std::string> removeEmptyElemFromList(std::list<std::string> lt);

    // takes a file path in argument and returns a list of std::string
    // which contains individual lines from the file
    std::list<std::string> readLineFromFile(std::string filePath);

    // takes a file path in argument and returns a list of std::string
    // which contains individual word from the file
    // it uses "std::list<std::string> readLineFromFile(std::string filePath)" internally
    std::list<std::string> readWordFromFile(std::string filePath);
};


#endif //SOURCECODE_INDENTER_FILEIO_H
