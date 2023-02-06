#include <iostream>
#include <fstream>
#include <string>
#include <regex>

#include "../inc/conversion.h"

using namespace std;

//custom exception, name inspired by betty boop
class MyCustomException : public exception {
public:
    string oop() {
        return "oops! an error has occurred, one of both files do not exist\n"
               "please check that the input file path is correct";
    }
};

int main() {
    //variables
    string filePath;
    string fileDest;
    int result;
    char ch;
    bool  validPath = false;

    //file path regex
    regex checkFilePath(".?:(\\\\[a-zA-Z 0-9()]*)*.[a-zA-Z]*.(cpp)"); // https://stackoverflow.com/a/15710561
    regex checkFileDest(".?:(\\\\[a-zA-Z 0-9()]*)*.[a-zA-Z]*.(html)");

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
        if (regex_match(filePath, checkFilePath) && regex_match(fileDest, checkFileDest)) {
            ifstream oldFile;
            ofstream newFile;

            //check if file exists
            try {
                (oldFile.open (filePath));
                (newFile.open(fileDest));

                result = convertFile(filePath, fileDest);
            } catch (MyCustomException& betty) {//'&' is to catch by reference. suggested by clion
                cout << betty.oop();
            } catch (exception& e) {
            } catch (...) {
                cout << "unknown error occurred" << endl;
            }

            //check if file closed properly
            try {
                (oldFile.close());
                (newFile.close());
            } catch (exception& e) {//library
                cout << "there has been an error caught by this library exception\n"
                        "one or both files seem to have not closed properly" << endl;
            } catch (...) {
            cout << "unknown error occurred" << endl;
            }

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
