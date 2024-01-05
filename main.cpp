#include <iostream>
#include <fstream> // used for access to the file input and output classes, ifstream and ofstream

using namespace std;
int main() {

    ifstream fin("input.txt"); // creates an input file stream to the file "input.txt"
    if(fin) // ensures the file input stream is opened correctly
    {
        string aWord; // creates a variable to store each word we read in from the file.
        while(!fin.eof()) // ensures we haven't reached the end of file (eof)
        {
            fin >> aWord; // read the word from the file;
            cout << aWord << " "; // print each word to the screen followed by a space
        }
    }
    else
    {
        cout << "Unable to open file" <<endl;
    }
    return 0;
}

/*
 *
 * 1. Modify the above code to read in the data line-by-line instead of word-by-word.
 *
 * 2. Use a function to read in the data from the file and return it as a string.
 */