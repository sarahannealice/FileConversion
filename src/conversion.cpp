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

    //potential unnecessary repeated code -- ask about
    ifstream oldFile (filePath);
    ofstream newFile (fileDest);

    newFile << "<PRE>" << endl;

    //while there is a line in the file
    while (getline(oldFile, myLine)) {//https://stackoverflow.com/a/47406440
        //checks each character in the ifstream-ed line
        for (char check: myLine) {
            switch (check) {
                case '<':
                    newFile << "&lt";
                    break;
                case '>':
                    newFile << "&gt";
                    break;
                default:
                    newFile << check;
                    break;
            }
        }
        newFile << endl;
    }

    newFile << "</PRE>" << endl;

    return 0;
}//end readFile method