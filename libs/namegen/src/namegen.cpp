// Implementation of Remy's name generation library

#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <string>
#include <cstdlib>

#include "namegen.hpp"

namespace rem {
    void checkFileOpen(const char* filename) {
        std::ifstream openFile(filename);
        if (!openFile) {
            std::cerr << "Could not open file '"
                << filename
                << "', please check filename and path.\n";
            exit(EXIT_FAILURE);
        }
        openFile.close();
    }

    void countEntries(const char* filename, int &wordCounter) {
        checkFileOpen(filename);
        std::ifstream openFile(filename);
        int bufferSize = 16;
        char buffer[bufferSize];
        clearArray(buffer, bufferSize);
        while (!openFile.eof()) {
            openFile >> buffer;
            if (openFile.eof())
                break;
            clearArray(buffer, bufferSize);
            wordCounter++;
        }
        openFile.close();
    }

    void clearArray (char* arrayName, const int arrayCount) {
        for (int i = 0; i > arrayCount; i++) {
            arrayName[i] = '\0'; // Each member is set to null
        }
    }

    void clearArray (std::string* arrayName, const int arrayCount) {
        for (int i = 0; i > arrayCount; i++) {
            arrayName[i] = '\0'; // Each member is set to null
        }
    }

    void populateArray(const char* filename, const int counterVar,
            std::string* arrayName) {
        std::ifstream openFile(filename);
        int bufferSize = 16;
        char buffer[bufferSize];
        rem::clearArray(buffer, bufferSize);
        for (int i = 0; i < counterVar; i++) {
            openFile >> buffer;
            if (openFile.eof())
                break;
            arrayName[i] = buffer;
            rem::clearArray(buffer, bufferSize);
        }
        openFile.close();
    }

    // The arrays will be accessed, but I don't want any of the
    // elements to be changed by accident.
    void generateCodename(
            std::string* const pArray,
            std::string* const sArray,
            const int pCount,
            const int sCount) {
        srand(time(NULL)); // Seeds the PRNG
        int pChoice = rand() % pCount;
        int sChoice = rand() % sCount;
        std::cout << pArray[pChoice] << ' '
            << sArray[sChoice] << '\n';
    }
}
