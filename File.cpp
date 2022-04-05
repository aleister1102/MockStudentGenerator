#include "include/File.h"

/**
 * Reads a CSV file and returns a vector of vectors of strings
 *
 * @param fileName the name of the file to be read
 *
 * @return A vector of vectors of strings.
 */
vector<vector<string>> File::readCSV(string fileName)
{
    vector<vector<string>> parsedStrings;

    _input.open(fileName, ios::in);

    if (!_input)
    {
        cout << "File is not found!\n";
        return parsedStrings;
    }

    string reader;
    getline(_input, reader);

    while (!_input.eof())
    {
        getline(_input, reader);
        vector<string> parsedString = String::parseString(reader, ",");
        parsedStrings.push_back(parsedString);
    }

    _input.close();
    return parsedStrings;
}

/**
 * Reads a text file and returns a vector of strings
 * 
 * @param fileName the name of the file to be read.
 * 
 * @return A vector of strings.
 */
vector<string> File::readTXT(string fileName)
{
    vector<string> strings;

    _input.open(fileName, ios::in);

    if (!_input)
    {
        cout << "File is not found!\n";
        return strings;
    }

    string reader;
    while (!_input.eof())
    {
        getline(_input, reader);
        strings.push_back(reader);
    }

    _input.close();
    return strings;
}