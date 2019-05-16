//
// Created by May on 2019/5/14.
//

#include "iterator.h"
#include <iterator>
// provide cin, cout
#include <iostream>
//  provide vector<T>
#include <vector>

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
