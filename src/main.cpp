#include <iostream>
#include <fstream>
#include <string>
#include <regex>

#include "../inc/conversion.h"

using namespace std;

int main() {
//    cout << "Hello, World!" << endl;

    //---TO DO---//
    //1. replace < > chevrons with &lt; &gt; respectively
    //**above needs to be altered to replace both on same line
    //2. add try catch statements
    //3. add to validation to tell them what's wrong

    //variables
    string filePath;
    string fileDest;
    int result;
    char ch;
    bool  validPath = false;

    //file path regex
    regex checkFilePath(".?:(\\\\[a-zA-Z 0-9()]*)*.[a-zA-Z]*.(txt)"); // https://stackoverflow.com/a/15710561

    cout << "Input the absolute file path for the desired file to be converted: ";
    getline(cin, filePath);
    cout << "Input the absolute file path for the desired file destination: ";
    getline(cin, fileDest);

    //validate filePath/fileDest
    while (!validPath) {
        if (filePath.length() == 0) {
            cout << "please input an absolute file path to read from: ";
            getline(cin, filePath);
        } else if (fileDest.length() == 0) {
            cout << "please input an absolute file path to write to: ";
            getline(cin, fileDest);
        }
        if (regex_match(filePath, checkFilePath)) {
            ifstream myFile;
            myFile.open (filePath);
            //send to file I/O method
            cout << "that's a valid path" << endl;

            //check if file exists
            try {
                (myFile);
            } catch (exception& e) {
                cout << "file could not be located" << endl;
            }

            result = convertFile(filePath, fileDest);

            if(result == 0) {
                cout << endl << "conversion complete" << endl;
            } else {
                cout << endl << "conversion unsuccessful" << endl;
            }
            break;
        } else {
            cout << endl << "That file path is invalid. Input a valid absolute file path: " << endl;
            getline(cin, filePath);
        }
    }//end while loop


    return 0;
}//end main method
