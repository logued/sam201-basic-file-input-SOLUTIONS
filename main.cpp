#include <iostream>         // Jan 206
#include <fstream> // used for access to the classes,
                    // input file stream - ifstream and
                    // output file stream - ofstream

/*
 * Demonstrates reading text from a file in two ways:
 * 1. word by word
 * 2. line by line
 */
using namespace std;

// function prototypes
void read_word_by_word(ifstream &);  // note the reference type "&"
void read_line_by_line(ifstream &);

int main() {

    ifstream inputStream("input.txt");   // creates an input file stream object based on the file "input.txt"

    if ( inputStream.is_open() )     // file opened successfully?
    {
        cout << "\nWord at a time:" << endl;
        read_word_by_word(inputStream);   // call a function to read words from the stream and print them
        // the input file stream "ifs" is passed by reference
    } else {
        cout << "Unable to open file" << endl;
    }
    inputStream.close();    // close the file

    // Start again by opening file and reading line-by-line
    //
    inputStream.open("input.txt");      // open the file again, and starts at beginning

    if ( inputStream.is_open() ) {                           cout << "\nLine at a time:" << endl;
        read_line_by_line(inputStream);// pass a reference to the input file stream
    } else {
        cout << "Unable to open file" << endl;
    }
    inputStream.close();    // close the file

    return 0;
}

/**
 * Reads words from the input stream, one at a time, and outputs each one.
 * The words are delimited (seperated) by whitespace (i.e. spaces or tabs)
 *
 * @param in - reference to an Input File Stream
 */
void read_word_by_word(ifstream &in) {  // ifs is a reference to an input file stream
    string word;
    while ( !in.eof() ) {        // while not at the end of the file
        in >> word;            // extract a word from the stream into the variable 'word'(as a string)
        cout << word << "\n";    // print out the word to the screen followed by a space
    }
}

/**
 * Read text from an input stream line-by-line and print each line.
 * @param in - reference to an Input File Stream object
 */
void read_line_by_line(ifstream& in) {
    string line;
    while (getline(in, line))     // while not at end of file, read a full line of text
    {
        cout << line << "\n";   // print the line to the screen followed by a space
    }
}

