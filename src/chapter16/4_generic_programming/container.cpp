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

#include <set>

void use_container_set() {
    using namespace std;

    const int N = 6;
    string s1[N] = {
            "Mon",
            "Tue",
            "Wed",
            "Thur",
            "Mon",
            "Sat",
    };

    string s2[N] = {
            "Jan",
            "Feb",
            "March",
            "Mon",
            "May",
            "April"
    };

    set<string> A(s1, s1 + N);
    set<string> B(s2, s2 + N);

    //  a set will automatically unique its members
    ostream_iterator<string, char> out(cout, " ");
    cout << "Set A: ";
    copy(A.begin(), A.end(), out);
    cout << endl;

    cout << "Set B: ";
    copy(B.begin(), B.end(), out);
    cout << endl;

    //  provide by 'algorithm'
    //  again, make member unique
    cout << "Union of A and B:\n";
    set_union(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;

    //  exact same as concepts in math
    cout << "Intersection of A and B:\n";
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;

    //  A diff B, B diff A, not same
    cout << "Difference of A and B:\n";
    set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;

    cout << "Difference of B and A:\n";
    set_difference(B.begin(), B.end(), A.begin(), A.end(), out);
    cout << endl;

    cout << endl;

    set<string> C;
    cout << "Set C:\n";
    //  use 'insert_iterator' to make copy into insert
    set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string>>(C, C.begin()));
    copy(C.begin(), C.end(), out);
    cout << endl << endl;

    string s3("Gruuuu");
    C.insert(s3);
    cout << "Set C after insertion:\n";
    copy(C.begin(), C.end(), out);
    cout << endl << endl;

    //  output closed interval [a, b]
    cout << "Showing a range:\n";
    copy(C.lower_bound("Gruuuu"), C.upper_bound("May"), out);
    cout << endl;
}