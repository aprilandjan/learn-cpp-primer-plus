//
// Created by May on 2019/6/20.
//

#include "use_file_stream.h"
#include <iostream>
#include <fstream>
#include <string>

void basic_file_stream() {
    using namespace std;
    string filename;

    cout << "Enter name of the new file:\n";
    cin >> filename;

    //  c_str: c-style string, i.e. the char*
    cout << "\nYour filename: " << filename << "(" << filename.c_str() << ")\n";

    //  create file
    ofstream fout(filename.c_str());

    //  write to file
    fout << "Something Bad Happened...\n";

    float num;
    cout << "Enter your secret num:\n";
    cin >> num;
    fout << "Your secret num is: " << num << endl;
    fout.close();

    //  create another fstream
    ifstream fin(filename.c_str());
    cout << "Content in file " << filename << "\n";
    char ch;
    while(fin.get(ch)) {    //  read util EOF
        cout << ch; //  output to screen
    }

    cout << "\n";
    fin.close();
}