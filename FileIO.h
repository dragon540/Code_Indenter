//
// Created by shobhit on 25/6/23.
//

#ifndef SOURCECODE_INDENTER_FILEIO_H
#define SOURCECODE_INDENTER_FILEIO_H

#include <list>
#include <string>

class FileIO {
public:
    std::list<std::string> readLineFromFile(std::string filePath);
    std::list<std::string>readWordFromFile(std::string filePath);
};


#endif //SOURCECODE_INDENTER_FILEIO_H
