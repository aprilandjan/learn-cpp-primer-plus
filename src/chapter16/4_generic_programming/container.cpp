//
// Created by May on 2019/5/25.
//

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include "container.h"

void output(int n) {
    std::cout << n << " ";
}

void use_container_list() {
    using namespace std;

    //  list: 双向链表
    list<int> one(5, 2);

    int stuff[5] = {1, 2, 4, 6, 8};

    //  define an empty list
    list<int> two;
    two.insert(two.begin(), stuff, stuff + 5);

    int more[6] = {6, 66, 666, 6666, 66666, 666666};

    //  copy constructor
    list<int> three(two);
    three.insert(three.end(), more, more + 6);

    cout << "List One:\n";
    for_each(one.begin(), one.end(), output);
    cout << endl;

    cout << "List Two:\n";
    for_each(two.begin(), two.end(), output);
    cout << endl;

    cout << "List Three:\n";
    for_each(three.begin(), three.end(), output);
    cout << endl;

    //  remove all occurrence of 2
    three.remove(2);
    cout << "List Three without 2:\n";
    for_each(three.begin(), three.end(), output);
    cout << endl;

    //  insert 'one' at 'three' begin
    three.splice(three.begin(), one);
    cout << "List Three after splice:\n";
    for_each(three.begin(), three.end(), output);
    cout << endl;

    //  'one' will be empty
    cout << "List One after be spliced:\n";
    for_each(one.begin(), one.end(), output);
    cout << endl;

    //  similar to _.unique, but just siblings
    three.unique();
    cout << "List Three after unique:\n";
    for_each(three.begin(), three.end(), output);
    cout << endl;

    //  numeric ascending sort. still in unique
    three.sort();
    cout << "List Three after sort, still in unique:\n";
    for_each(three.begin(), three.end(), output);
    cout << endl;

    two.sort();
    three.merge(two);

    //  still in sorted, really weird...
    cout << "List Three after merge 'two', still in sorted:\n";
    for_each(three.begin(), three.end(), output);
    cout << endl;
}