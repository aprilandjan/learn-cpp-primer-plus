//
// Created by May on 2019/5/14.
//

#include "iterator.h"
#include <iterator>
// provide cin, cout
#include <iostream>
//  provide vector<T>
#include <vector>
#include <algorithm>

void use_iterator_copy() {
    using namespace std;

    int cats[10] = {6, 8, 2, 1, 5, 0, 9, 3, 7, 4};

    vector<int> dice(10);
    //  copy is provided by 'algorithm' ?
    // http://www.cplusplus.com/reference/algorithm/copy/
    copy(cats, cats + 10, dice.begin());

    cout << "Let the dice be cast!\n";

    //  create ostream iterator
    ostream_iterator<int, char> out_iter(cout, " ");
    //  copy vector to output
    copy(dice.begin(), dice.end(), out_iter);
    cout << "\n";

    //  reverse output
    cout << "use reverse iterator:\n";
    copy(dice.rbegin(), dice.rend(), out_iter);
    cout << "\n";

    vector<int>::reverse_iterator ri;
    for(ri = dice.rbegin(); ri != dice.rend(); ++ri) {
        cout << *ri << " ";
    }
    cout << endl;
}

void output(const std::string & s) {
    std::cout << s << " ";
}


void use_iterator_insert() {
    using namespace std;

    string s1[4] = {
            "Monday",
            "Tuesday",
            "Wednesday",
            "Thursday",
    };

    string s2[2] = {
            "Even",
            "Odd",
    };

    string s3[2] = {
            "Male",
            "Female",
    };

    vector<string> words(4);

    //  copy is provided by 'algorithm'
    copy(s1, s1 + 4, words.begin());
    //  for_each is also provided by 'algorithm'
    //  arr.forEach in javascript
    for_each(words.begin(), words.end(), output);
    //  normal 'mon', 'tue', 'wed', 'thur'
    cout << endl;

    //  create a temp back_insert_iterator object from 'words'
    //  insert at the **back**
    copy(s2, s2 + 2, back_insert_iterator<vector<string>>(words));
    for_each(words.begin(), words.end(), output);
    //
    cout << endl;

    //  temp insert_iterator
    //  insert at the "beginning"
    copy(s3, s3 + 2, insert_iterator<vector<string>>(words, words.begin() + 0));
    for_each(words.begin(), words.end(), output);
    cout << endl;
}
