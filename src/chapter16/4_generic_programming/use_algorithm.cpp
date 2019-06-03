//
// Created by May on 2019/6/3.
//

#include "use_algorithm.h"
#include <iostream>
#include <string>
#include <algorithm>

void string_sort() {
    using namespace std;
    string letters;
    cout << "Enter the letter group('quit' to quit): ";
    while(cin >> letters && letters != "quit") {
        cout << "Permutation of " << letters << ": ";
        //  string also implies STL interfaces, has begin(), end(), etc
        //  in-place algorithm
        sort(letters.begin(), letters.end());
        cout << letters << endl;

        int c = 1;
        int l = 1;
        while(l <= letters.size()) {
            c *= l;
            l++;
        }
        // FIXME: same letter doesn't sort differently
        cout << "\nPossible sorts: " << c << " types, as follow:\n";
        cout << 0 << "\t" << letters << endl;

        int i = 1;
        //  next_permutation: try to sort range[] in another type
        //  so this will output all kinds of order of input string
        while(next_permutation(letters.begin(), letters.end())) {
            cout << i << "\t" << letters << endl;
            i++;
        }
        cout << "\nEnter next sequence: ";
    }

    cout << "Finish...\n";
}
