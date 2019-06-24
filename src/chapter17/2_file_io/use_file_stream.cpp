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

struct planet {
    char name[20];
    double population;
    double gravity;
};

const char * filename = "planets.dat";

void binary_file() {
    struct planet {
        char name[20];
        double population;
        double gravity;
    };

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

void random_access() {
    using namespace std;

    planet p;
    cout << fixed;

    //  show file content
    //  using fstream, which can used to input & output
    fstream fs;
    fs.open(filename, ios_base::binary | ios_base::in | ios_base::out);

    //  count data lines
    int lines = 0;
    if (fs.is_open()) {
        //  set to beginning of the file
        fs.seekg(0);
        cout << "Here are the current contents of " << filename << ":\n";
        while(fs.read((char *) &p, sizeof p)) {
            lines++;
            cout << lines << ": ";
            cout << setw(20) << p.name << ": "
                 << setprecision(0) << setw(12) << p.population
                 << setprecision(2) << setw(6) << p.gravity
                 << endl;

        }
        if (fs.eof()) {
            fs.clear(); // clear eof flag for latter usage
        } else {
            cerr << "Error in reading " << filename << "...\n";
            exit(EXIT_FAILURE);
        }
    } else {
        cerr << "Error when open file " << filename << "...\n";
        exit(EXIT_FAILURE);
    }

    //  modify one record line
    cout << "Enter the record number you want to modify:\n";
    long line;
    cin >> line;
    eatline();

    if (line < 1 || line > lines) {
        cerr << "Invalid record number. valid range is: [1, " << lines << "].\n";
        exit(EXIT_FAILURE);
    }

    //  calc where to read
    streampos place = (line - 1)  * sizeof p;
    fs.seekg(place);
    if (fs.fail()) {
        cerr << "Error when seek at position " << place << "...\n";
        exit(EXIT_FAILURE);
    }

    fs.read((char *) &p, sizeof p);
    cout << "You select:\n";
    cout << line << ": ";
    cout << setw(20) << p.name << ": "
         << setprecision(0) << setw(12) << p.population
         << setprecision(2) << setw(6) << p.gravity
         << endl;

    if (fs.eof()) {
        fs.clear();
    }

    cout << "Enter planet name:\n";
    cin.get(p.name, 20);
    eatline();
    cout << "Enter planet population:\n";
    cin >> p.population;
    cout << "Enter planet gravity:\n";
    cin >> p.gravity;
    eatline();
    //  move file output place to target place
    fs.seekp(place);
    //  turn p1 address to char*
    fs.write((char *) &p, sizeof p) << flush;
    if (fs.fail()) {
        cerr << "Error when attemted write...\n";
        exit(EXIT_FAILURE);
    }

    //  show modified content
    lines = 0;
    fs.seekg(0);
    cout << "After modification:\n";
    while(fs.read((char *) &p, sizeof p)) {
        lines++;
        cout << lines << ": ";
        cout << setw(20) << p.name << ": "
             << setprecision(0) << setw(12) << p.population
             << setprecision(2) << setw(6) << p.gravity
             << endl;

    }

    fs.close();
    cout << "finish...\n";
}