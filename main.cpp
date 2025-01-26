#include <iostream>         // Jan 2025
#include <fstream> // used for access to the file input and output classes, ifstream and ofstream

/*
 * Demonstrates reading text from a file:
 * 1. word by word
 * 2. line by line
 */
using namespace std;

// function prototypes
void read_word_by_word(ifstream &);  // note the reference type "&"
void read_line_by_line(ifstream &);

int main() {

    ifstream ifs("input.txt");   // creates an input file stream object (ifs) based on the file "input.txt"

    if (ifs) {                        // if "ifs" evaluates as "true", then the file input stream has opened successfully
        cout << "\nWord at a time:" << endl;
        read_word_by_word(ifs);   // call a function to read words from the stream and print them
        // the input file stream "ifs" is passed by reference
    } else {
        cout << "Unable to open file" << endl;
    }
    ifs.close();    // close the file

    ifs.open("input.txt");      // open the file again, and starts at beginning

    if (ifs) {                    //if file has opened successfully
        cout << "\nLine at a time:" << endl;
        read_line_by_line(ifs);// pass the ifs into a function that will read its content line-by-line
    } else {
        cout << "Unable to open file" << endl;
    }
    ifs.close();    // close the file

    return 0;
}

/**
 * Reads words from the input stream, one at a time, and outputs each one.
 * The words are delimited (seperated) by whitespace (i.e. spaces or tabs)
 *
 * @param ifs - reference to an Input File Stream
 */
void read_word_by_word(ifstream &ifs) {  // ifs is a reference to an input file stream
    string word;
    while (!ifs.eof()) {        // while not at the end of the file
        ifs >> word;            // extract a word from the stream into the variable 'word'(as a string)
        cout << word << " ";    // print out the word to the screen followed by a space
    }
}

void read_line_by_line(ifstream &ifstream1) {
    string line;
    while (getline(ifstream1, line))     // while not at end of file, read a line
    {
        cout << line << " ";   // print each word to the screen followed by a space
    }
}

