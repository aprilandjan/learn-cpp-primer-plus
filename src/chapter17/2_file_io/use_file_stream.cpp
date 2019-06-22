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
#include <iomanip>

/**
 * count word as executable
 * @param argc argument count
 * @param argv argument values
 */
void word_count(int argc, char * argv[]) {
    using namespace std;

//    argc = 2;
//    char *f1 = "justify";
//    char *f2 = "number.txt";
//    char *f3 = "tobuy.txt";
//    argv = {
//            &f1,
//    };

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

#include <iomanip> //  provide setw

//  read until met '\n'
void eatline() {
    while (std::cin.get() != '\n')
        continue;
}

void binary_file() {
    struct planet {
        char name[20];
        double population;
        double gravity;
    };

    const char * filename = "planets.dat";

    using namespace std;
    planet p1;
    cout << fixed << right;

    //  input from filestream
    ifstream fin;
    //  read as input
    fin.open(filename, ios_base::in | ios_base::binary);

    if (fin.is_open()) {
        //  file exist, read content
        cout << "content of file " << filename << ":\n";
        while(fin.read((char *) &p1, sizeof p1)) {
            cout << setw(20) << p1.name << ": "
                << setprecision(0) << setw(12) << p1.population
                << setprecision(2) << setw(6) << p1.gravity
                << endl;
        }
        fin.close();
    }

    //  output to filestream, append & binary
    ofstream fout(filename, ios_base::out | ios_base::binary | ios_base::app);
    if (!fout.is_open()) {
        cerr << "Cannot open " << filename << "...\n";
        exit(EXIT_FAILURE);
    }

    cout << "Enter planet name(blank line to quit):\n";
    //  get 20 char from cin
    cin.get(p1.name, 20);
    //  get empty char
    while(p1.name[0] != '\0') {
        eatline();
        cout << "Enter planet population: ";
        cin >> p1.population;
        cout << "Enter planet gravity: ";
        cin >> p1.gravity;
        eatline();
        //  turn p1 address to char*
        fout.write((char *) &p1, sizeof p1);
        cout << "Enter planet name(blank line to quit):\n";
        cin.get(p1.name, 20);
    }
    //  must close the output stream, otherwise the content not showing in following program
    fout.close();

    //  show modified
    fin.clear();
    fin.open(filename, ios_base::in | ios_base::binary);
    if (fin.is_open()) {
        cout << "content of file " << filename << " after modification:\n";
        while(fin.read((char *) &p1, sizeof p1)) {
            cout << setw(20) << p1.name << ": "
                 << setprecision(0) << setw(12) << p1.population
                 << setprecision(2) << setw(6) << p1.gravity
                 << endl;
        }
        fin.close();
    }

    cout << "\n";
}