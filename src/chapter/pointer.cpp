//
// Created by May on 2018/1/7.
//

#include "pointer.h"
#include <iostream>
#include <cstring>

struct inflatable
{
    char name[20];
    float volumn;
    double price;
};

int newstruct () {
    using namespace std;
    //  allocate memory
    inflatable * ps = new inflatable;
    cout << "enter the name of the item:";
    cin.get(ps -> name, 20);
    cout << "enter the volumn:";
    cin >> (*ps).volumn;
    cout << "enter the price:";
    cin >> ps -> price;
    cout << "the item is as followed:";
    cout << "name = " << ps -> name << endl;
    cout << "volumn =" << (*ps).volumn << endl;
    cout << "price = " << (*ps).price << endl;

    return 0;
}

int delete_new () {
    using namespace std;
    char * name;
    name = getname();
    cout << name << " at " << (int *) name << endl;
    delete [] name;

    name = getname();
    cout << name << " at " << (int *) name << endl;
    delete [] name;

    return 0;
}

char * getname() {
    using namespace std;
    //  temp storage for input values
    char temp[80];
    cout << "enter last name:";
    cin >> temp;
    char * pn = new char[strlen(temp) + 1];
    strcpy(pn, temp);
    return pn;
}

int pointer () {
    using namespace std;

    int var = 6;
    //  声明一个指向 int 的指针
    int * p_var;
    //  指针地址设定为
    p_var = &var;

    //  output two values
    cout << "value : var = " << var << endl;
    cout << "* p_var = " << *p_var << endl;

    //  output two address
    cout << "address var = " << &var << endl;
    cout << "address p_var = " << p_var << endl;

    //  use pointer to change value
    *p_var = *p_var + 1;
    cout << "after +1, var = " << var << endl;

    //  pointer set to address
    int addressVal = 5;
    int * p_add = &addressVal;
    cout << "Val of addressVal = " << addressVal;
    cout << "; Address of addressVal = " << &addressVal << endl;
    cout << "Val of *p_add = " << *p_add << ", val of p_add = " << p_add << endl;

    return 0;
}

int use_new () {
    using namespace std;
    int nights= 1001;
    //  申请一个 int 类型的地址
    int * pt = new int;
    //  给这个地址处赋值1001
    *pt = 1001;

    cout << "nights = " << nights << endl;
    cout << nights << "location = " << & nights << endl;

    cout << "int value = " << *pt << "; location = " << pt << endl;

    double * pd = new double;
    *pd = 10011002.0;
    cout << "double value = " << *pd << "; location = " << pd << endl;

    cout << "size of pt = " << sizeof(pt) << endl;
    cout << "size of *pt = " << sizeof(*pt) << endl;

    cout << "size of pd = " << sizeof(pd) << endl;
    cout << "size of *pd = " << sizeof(*pd) << endl;

    // sizeof a address: 4 byte = 32bit

    delete pd;
    cout << "after delete, *pd = " << *pd << endl;

    // array with new

    double *p3 = new double[3];
    //  用起来和普通ARRAY没什么区别...
    p3[0] = 0.1;
    p3[1] = 0.2;
    p3[2] = 0.3;

    cout << "p3[1] is " << p3[1] << endl;
    p3 = p3 + 1;
    cout << "now p3[1] is " << p3[1] << endl;

    p3 = p3 - 1;
    delete [] p3;
    cout << "after delete, p3[1]" << p3[0] << endl;

    return 0;
}

int address_pointers () {
    using namespace std;
    double wages[3] = {10000.0, 20000.1, 30000.2};
    short stacks[3] = {3, 2, 1};

    //  数值直接就是地址了
    double *pw = wages;
    //  或者是数组首元素地址
    short *ps = &stacks[0];

    cout << "size of double = " << sizeof(double) << " bytes" << endl;

    cout << "pw = " << pw << ", *pw = " << *pw << endl;
    pw = pw + 1;
    //  数组指针+1，相当于加了8 BYTE
    cout << "after + 1, pw = " << pw << ", *pw = " << *pw << endl;

    //  直接打印出了地址
    cout << stacks << ", " << &stacks << endl;
    cout << ps << endl;


    return 0;
}

int ptrstr () {
    using namespace std;
    char animal[20] = "bear";
    const char * bird = "wren";
    char * ps;

    cout << animal << " and " << bird << "\n";
    cout << *ps << endl; // uninitialized values
    cout << "input a kind of animal:";
    cin >> animal;
    ps = animal;
    cout << ps << "!\n";

    cout << "before using strcpy(): \n";
    cout << animal << " at " << (int *) animal << endl;
    cout << ps << " at " << (int *) ps << endl;

    //  new address
    ps = new char[strlen(animal) + 1];
    //  copy value to the newly created address
    strcpy(ps, animal);
    cout << "after using strcpy(): \n";
    cout << animal << " at " << (int *) animal << endl;
    cout << ps << " at " << (int *) ps << endl;
    delete [] ps;

    return 0;
}
