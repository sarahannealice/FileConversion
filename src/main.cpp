#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
//    cout << "Hello, World!" << endl;

    //---TO DO---//
    //1. ask for user input (file path to read)
    //2. validate user input
    //3. read file content
    //4. replace < > chevrons with &lt; &gt; respectively
    //5. add <PRE> and </PRE> to the beginning and end of the file respectively
    //6. write to new file with .html extension

    string myLine;

    ifstream myFile (R"(C:\Users\sarah\Desktop\sarah\nscc\winter 2023\PROG2100\test.txt)");

    if (myFile.is_open()) {//checks if file is open
        while (myFile) {//while loop to read entire file -- equivalent to myFile.good()
            getline(myFile, myLine);//pipes content into stream
            cout << myLine << endl;//pipes content to standard output
        }
    } else {//to catch if the file can't be opened
        cout << myLine << "couldn't open file\n";
    }

    return 0;
}
