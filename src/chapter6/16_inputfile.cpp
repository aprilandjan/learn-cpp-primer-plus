//
// Created by May on 2018/7/24.
//

#include <iostream>
#include "fstream"

//  support for 'exit()'
#include "cstdlib"

const int SIZE = 60;

int inputfile () {
    using namespace std;
    char filename[SIZE];

    //  declare a input file instance
    ifstream inFile;

    //  ask for filename
    cout << "Enter name of data file:";
    cin.getline(filename, SIZE);

    //  open file
    inFile.open(filename);
    if (!inFile.is_open()) {
        cout << "Could not open the file " << filename << endl;
        cout << "exit..." << endl;
        exit(EXIT_FAILURE);
    }

    double value;
    double sum = 0.0;
    int count = 0;

    //  read value from file
    inFile >> value;
    //  read util reading available
    while(inFile.good()) {
        ++count;
        sum += value;
        inFile >> value;
    }
    if (inFile.eof()) {
        cout << "End of file reached." << endl;
    }
    else if (inFile.fail()) {
        cout << "Input terminated by data mismatching.\n";
    } else {
        cout << "terminated by unknown reason\n";
    }
    if (count == 0) {
        cout << "No data processed\n";
    }
    else {
        cout << "Item read: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << sum / count << endl;
    }
    inFile.close();
    return 0;

}