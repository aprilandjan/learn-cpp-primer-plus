//
// Created by May on 2018/4/12.
//
#include <iostream>
#include <fstream>
#include "15_outfile.h"

//using namespace std;

int outfile () {
    using namespace std;

    char automobile[50];
    int year;
    double a_price;
    double b_price;

    ofstream outputFile;
    outputFile.open("carinfo.txt");

    cout << "Enter the make and model of automobiles:\n";
    cin.getline(automobile, 50);
    cout << "Enter the model year:\n";
    cin >> year;
    cout << "Enter the original asking price:\n";
    cin >> a_price;
    b_price = 0.913 * a_price;

    //  display what inputs

    cout << fixed;
    cout.precision(2);
    cout.setf(ios_base::showpoint);

    cout << "Make and model:" << automobile << endl;
    cout << "year:" << year << endl;
    cout << "Was asking $" << a_price << endl;
    cout << "Now asking $" << b_price << endl;

    //  write into file
    outputFile << fixed;
    outputFile.precision(2);
    outputFile.setf(ios_base::showpoint);

    outputFile << "Make and model:" << automobile << endl;
    outputFile << "year:" << year << endl;
    outputFile << "Was asking $" << a_price << endl;
    outputFile << "Now asking $" << b_price << endl;

    outputFile.close();

    return 0;
}