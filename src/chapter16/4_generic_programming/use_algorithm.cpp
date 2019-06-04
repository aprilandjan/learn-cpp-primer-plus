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

#include <list>

void showInt(int i) {
    std::cout << i <<  ' ';
}

void try_list_remove()  {
    using namespace std;

    const int LIMIT = 10;
    int arr[LIMIT] = {1, 3, 5, 7, 9, 8, 6, 4, 2, 0};
    list<int> la(arr, arr + LIMIT);
    list<int> lb(la);

    cout << "Original list:\nla:\t";
    for_each(la.begin(), la.end(), showInt);
    cout << endl;

    //  member function will adjust size automatically
    la.remove(4);
    cout << "After remove through member function remove():\n";
    cout << "la:\t";
    for_each(la.begin(), la.end(), showInt);
    cout << endl << endl;

    list<int>::iterator last;
    //  STL remove won't adjust size
    //  FIXME: seems remove 0 not working?
    last = remove(lb.begin(), lb.end(), 1);
    cout << "After remove through STL function remove():\n";
    cout << "lb:\t";
    for_each(lb.begin(), lb.end(), showInt);
    cout << endl << endl;

    //  delete a range
    lb.erase(last, lb.end());
    cout << "After erase:\n";
    cout << "lb:\t";
    for_each(lb.begin(), lb.end(), showInt);
    cout << endl << endl;
}