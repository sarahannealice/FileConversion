//
// Created by sarah on 2023-01-27.
//
#include <iostream>
#include <fstream>
#include <string>
#include <regex>

#include "../inc/conversion.h"

using namespace std;

int convertFile(string filePath, string fileDest) {
    regex chevronLeft ("[<]");
    regex chevronRight ("[>]");
    char check;
    string myLine;
    string conversion;

    ifstream oldFile (filePath);
    ofstream newFile (fileDest);

    if (oldFile.is_open()) {//checks if file is open
        newFile << "<PRE>" << endl;

        while (oldFile) {//while loop to read entire file -- equivalent to myFile.good()
            getline(oldFile, myLine);//pipes content into stream

            //f statement to check symbols to replace
            if (regex_search(myLine, chevronLeft)) {
                newFile << regex_replace(myLine, chevronLeft, "\\&lt;") << endl;
            } else if (regex_search(myLine, chevronRight)) {
                newFile << regex_replace(myLine, chevronRight, "\\&gt") <<  endl;
            } else {
                newFile << myLine << endl;
            }
        }
        newFile << "</PRE>" << endl;

    } else {//to catch if the file can't be opened
        cout << "couldn't open file\n";
        return 1;
    }

    return 0;
}//end readFile method