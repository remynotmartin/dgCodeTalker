#include <iostream>
#include "../../libs/namegen/include/namegen.hpp"

const char* file1 = "../data/prefixes";
const char* file2 = "../data/suffixes";

int main() {
    int prefixCount = 0,
        suffixCount = 0;
    rem::checkFileOpen(file1);
    rem::checkFileOpen(file2);
    rem::countEntries(file1, prefixCount);
    rem::countEntries(file2, suffixCount);
    std::string prefixArray[prefixCount],
                suffixArray[suffixCount];
    rem::clearArray (prefixArray, prefixCount);
    rem::clearArray (suffixArray, suffixCount);
    rem::populateArray(file1, prefixCount, prefixArray);
    rem::populateArray(file2, suffixCount, suffixArray);
    rem::generateCodename(prefixArray, suffixArray, prefixCount, suffixCount);
    return 0;
}
