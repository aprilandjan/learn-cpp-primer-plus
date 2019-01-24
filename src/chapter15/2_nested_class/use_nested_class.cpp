//
// Created by May on 2019/1/17.
//

#include "use_nested_class.h"
#include "QueueTemplate.h"
#include <iostream>
//#include <string>

void use_nested_class() {
    using namespace L15_2;
    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;

    QueueTemplate<string> str_list(5);
    string temp;

    while(!str_list.is_full()) {
        cout << "Please enter your name. you will be served in the order of arrival.\nname: ";
        getline(cin, temp);
        str_list.enqueue(temp);
    }

    cout << "The queue is full. Processing now...\n";

    while(!str_list.is_empty()) {
        //  why "temp" here is needed? just want to shift the array...
        str_list.dequeue(temp);
        //  just to output it?...
        cout << "Now processing " << temp << "...\n";
    }

//    QueueTemplate<string> copy(str_list);
}
