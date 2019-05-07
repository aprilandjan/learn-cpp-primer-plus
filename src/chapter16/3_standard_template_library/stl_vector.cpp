//
// Created by May on 2019/5/7.
//

#include "stl_vector.h"
#include <iostream>
#include <string>
#include <vector>

void use_stl_vector () {
    using std::vector;
    using std::cout;
    using std::cin;
    using std::string;

    const int NUM = 5;

    //  similar like typescript: var arr: Array<number>;
    vector<int> ratings(NUM);
    vector<string> titles(NUM);

    cout << "Do the following:\nEnter " << NUM << " book titles and your ratings(0-10).\n";

    int i;
    for(i = 0; i < NUM; i++) {
        cout << "Enter title #" << i + 1 << ":\n";
        getline(cin, titles[i]);
        cout << "Enter your ratings (0-10):\n";
        cin >> ratings[i];
        cin.get();
    }

    cout << "Done. You entered the following:\n";
    cout << "Rating\tBook\n";
    for(i = 0; i < NUM; i++) {
        cout << ratings[i] << "\t" << titles[i] << "\n";
    }
}