//
// Created by May on 2018/11/25.
//

#include <iostream>
#include <cctype>

#include "use_stack.h"
#include "./stack.h"

void use_stack() {
    using namespace L10_3;
    using namespace std;

    Stack st;
    char ch;
    unsigned long po;
    cout << "Please enter A to add a purchase order, \nP to process a PO, or Q to quit.\n";
    //  toupper = to upper case
    while(cin >> ch && toupper(ch) != 'Q') {
        //  接下来的一个字符是换行符，才做后面的操作
        while(cin.get() != '\n') {
            continue;
        }
        //  is alphabetic, 是否是字母
        if (!isalpha(ch)) {
            cout << '\a';
            continue;
        }
        switch(ch) {
            case 'A':
            case 'a':
                cout << "Enter a PO number to add: ";
                cin >> po;
                cout << "You entered: " << po << "\n";
                if (st.is_full()) {
                    cout << "Stack already full.\n";
                } else {
                    //  推入栈
                    st.push(po);
                }
                break;
            case 'p':
            case 'P':
                if (st.is_empty()) {
                    cout << "Stack already cleared.\n";
                } else {
                    st.pop(po);
                    cout << "Po #" << po << " processed.\n";
                }
                break;
        }
        cout << "Please enter A to add a purchase order, \nP to process a PO, or Q to quit.\n";
    }
    cout << "Bye!\n";
}