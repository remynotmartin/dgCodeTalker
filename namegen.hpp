// Interface for Remy's name generation library

#ifndef NAME_GEN
#define NAME_GEN

#include <string>

namespace rem {
    void checkFileOpen(const char*);
    void countEntries(const char*, int&, const char*);
    void clearArray (char*, const int);
    void clearArray (std::string*, const int);
    void populateArray(const char*, const int, std::string*);
    void generateCodename(std::string* const, std::string* const,
            const int, const int);
}

#endif
