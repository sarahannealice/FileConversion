//
// Created by sarah on 2023-01-27.
//
#include <iostream>
#include <fstream>
#include <string>
#include <regex>

#include "../inc/conversion.h"

using namespace std;

int readFile(string filePath, string fileDest) {
    regex chevronLeft ("[<]");
    regex chevronRight ("[>]");
    char checkChar;
    string myLine;
    string conversion;
    int counter = 1;

    //hardcoded filePath
//    ifstream myFile (R"("C:\Users\sarah\Desktop\sarah\nscc\winter2023\PROG2100\test.txt")");
    ifstream myFile (filePath);

    if (myFile.is_open()) {//checks if file is open
        while (myFile) {//while loop to read entire file -- equivalent to myFile.good()
            getline(myFile, myLine);//pipes content into stream

            if (regex_search(myLine, chevronLeft)) {
                cout << regex_replace(myLine, chevronLeft, "\\&lt;") << endl;
            } else if (regex_search(myLine, chevronRight)) {
                cout << regex_replace(myLine, chevronRight, "\\&gt") <<  endl;
            } else if (myLine != EOF){
                cout << myLine << endl;
            }

            //checks char, writes/replaces to destination file
            //**want to come back and try this method at a later time**
//            while (myFile >> noskipws >> checkChar) {//source https://stackoverflow.com/a/12240035
//                if (checkChar == '<') {
//                    cout << checkChar;
//                    cout << " *this is a left chevron* ";
//                } else if (checkChar == '>') {
//                    cout << " *this is a right chevron* ";
//                }
//            }

//            cout << "count#" << counter << ": " + myLine << endl;//pipes content to standard output
//            counter++;
        }
    } else {//to catch if the file can't be opened
        cout << myLine << "couldn't open file\n";
    }

    return 0;
}//end readFile method

int writeFile(string filePath, string fileDest) {

    return 0;
}//end writeFile method