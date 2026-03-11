#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Class that handles compression and decompression
class FileCompressor
{
public:

    // Compress file using simple Run-Length Encoding
    void compressFile(string inputFile, string outputFile)
    {
        ifstream inFile(inputFile);   // open file to read
        ofstream outFile(outputFile); // open file to write compressed data

        if (!inFile || !outFile)
        {
            cout << "Error opening file." << endl;
            return;
        }

        char prevChar, currentChar;
        int count = 1;

        // read first character
        inFile.get(prevChar);

        // read rest of file
        while (inFile.get(currentChar))
        {
            if (currentChar == prevChar)
            {
                count++; // same character -> increase count
            }
            else
            {
                // write character and its count
                outFile << prevChar << count;

                prevChar = currentChar;
                count = 1;
            }
        }

        // write last character group
        outFile << prevChar << count;

        cout << "File compressed successfully." << endl;

        inFile.close();
        outFile.close();
    }

    // Decompress the compressed file
    void decompressFile(string inputFile, string outputFile)
    {
        ifstream inFile(inputFile);   // open compressed file
        ofstream outFile(outputFile); // file to write original data

        if (!inFile || !outFile)
        {
            cout << "Error opening file." << endl;
            return;
        }

        char character;
        int count;

        // read character and count from compressed file
        while (inFile >> character >> count)
        {
            // write the character count times
            for (int i = 0; i < count; i++)
            {
                outFile << character;
            }
        }

        cout << "File decompressed successfully." << endl;

        inFile.close();
        outFile.close();
    }
};

int main()
{
    int choice;
    string inputFile, outputFile;

    // create object of class
    FileCompressor compressor;

    cout << "---- File Compression System ----" << endl;
    cout << "1. Compress File" << endl;
    cout << "2. Decompress File" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter input file name: ";
    cin >> inputFile;

    cout << "Enter output file name: ";
    cin >> outputFile;

    if (choice == 1)
    {
        compressor.compressFile(inputFile, outputFile);
    }
    else if (choice == 2)
    {
        compressor.decompressFile(inputFile, outputFile);
    }
    else
    {
        cout << "Invalid choice." << endl;
    }

    return 0;
}