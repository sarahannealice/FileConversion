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
    string myLine;
    string conversion;

    ifstream myFile (filePath);

    if (myFile.is_open()) {//checks if file is open
        while (myFile) {//while loop to read entire file -- equivalent to myFile.good()
            getline(myFile, myLine);//pipes content into stream

            if (regex_search(myLine, chevronLeft)) {
                cout << regex_replace(myLine, chevronLeft, "\\&lt;") << endl;
            } else if (regex_search(myLine, chevronRight)) {
                cout << regex_replace(myLine, chevronRight, "\\&gt") <<  endl;
            } else {
                cout << myLine << endl;
            }
        }
    } else {//to catch if the file can't be opened
        cout << "couldn't open file\n";
        return 1;
    }

    return 0;
}//end readFile method