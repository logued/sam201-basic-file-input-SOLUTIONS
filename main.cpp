#include <iostream>
#include <fstream> // used for access to the file input and output classes, ifstream and ofstream

using namespace std;

// function prototypes
void read_word_by_word(ifstream&);  // note the reference type "&"
void read_line_by_line(ifstream&);

int main() {

    ifstream fin("input.txt");  // creates an input file stream to the file "input.txt"
    if(fin)                     // ensures the file input stream is opened correctly
    {
        cout << "\nWord at a time:" << endl;
        read_word_by_word( fin );// creates a variable to store each word we read in from the file.
    }
    else
    {
        cout << "Unable to open file" <<endl;
    }
    fin.close();    // close the file

    fin.open("input.txt");      // open the file again
    // now read file line by line
   if(fin)                     // ensures the file input stream is opened correctly
    {
       cout << "\nLine at a time:" << endl;
        read_line_by_line( fin );// creates a variable to store each word we read in from the file.
    }
    else
    {
        cout << "Unable to open file" <<endl;
    }
    fin.close();    // close the file


    return 0;
}

void read_word_by_word(ifstream & ifstream1 ) {
    string aWord;
    while(!ifstream1.eof())     // while not at end of file
    {
        ifstream1 >> aWord;     // read a word from the stream into variable
        cout << aWord << " ";   // print each word to the screen followed by a space
    }
}

void read_line_by_line(ifstream & ifstream1 ) {
    string line;
    while( getline(ifstream1,line) )     // while not at end of file, read a line
    {
        cout << line << " ";   // print each word to the screen followed by a space
    }
}

/*
 *
 * 1. Modify the above code to read in the data line-by-line instead of word-by-word.
 *
 * 2. Use a function to read in the data from the file and return it as a string.
 */