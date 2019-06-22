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

#include <cstdlib> // for exit()

/**
 * count word as executable
 * @param argc argument count
 * @param argv argument values
 */
void word_count(int argc, char * argv[]) {
    using namespace std;

    argc = 2;
    char *f1 = "justify";
    char *f2 = "number.txt";
    char *f3 = "tobuy.txt";
    argv = {
            &f1,
    };

    //  no arguments
    if (argc == 1) {
        cerr << "Usage: " << argv[0] << " filenames[s]\n";
        exit(EXIT_FAILURE);
    }
    cout << "ok, processing...\n";
//    getchar();

    ifstream fin;
    long count;
    long total = 0;
    char ch;

    //  iterate through args as filename
    for(int idx = 1; idx < argc; idx++) {
//        auto filename = argv[idx];
        char *filename = argv[idx];

        fin.open(filename);
        if (!fin.is_open()) {
            cerr << "Cannot open " << filename << endl;
            fin.clear();
            continue;
        }
        count = 0;
        //  read file
        while(fin.get(ch)) {
            count++;
        }
        cout << count << " characters in " << filename << endl;
        total += count;
        fin.clear();
        fin.close();
    }

    cout << total << " characters in all files\n";
}