//
// Created by May on 2018/8/6.
//

#include "7_arr_func_3.h"
#include "iostream"
const int MAX = 5;
int fill_array(double[], int);
void show_array(const double[], int);
void revalue(double, double[], int);

int arr_func_3 () {
    using namespace std;
    //  double type array
    double properties[MAX];

    int size = fill_array(properties, MAX);
    if (size <= 0) {
        return -1;
    }
    cout << "Enter revaluation factor: ";
    double factor;
    //  try to write cin into variable factor
    while(!(cin >> factor))
    {
        //  if failed to write into it...
        cin.clear();
        while (cin.get() != '\n') {
            //  if input is not '\n', then continue;
            continue;
        }
        //  else, echo not valid
        cout << "Not valid input, Please enter a number: ";
    }
    revalue(factor, properties, size);
    show_array(properties, size);

}

int fill_array (double ar[], int limit)
{
    using namespace std;
    double temp;
    int i;
    for (i = 0; i < limit; i++)
    {
        cout << "Enter value # " << (i + 1) << ":";
        cin >> temp;
        if (!cin) {
            cin.clear();
            //  if \n, just skip
            while(cin.get() != '\n')
            {
                continue;
            }
            cout << "Bad input; input process terminated.\n";
            break;
        }
        else if (temp < 0)
        {
            // if value is less than 0
            break;
        }
        //  write into array
        ar[i] = temp;
    }

    //  return the actual input numbers
    return i;
}

void show_array (const double ar[], int n)
{
    using namespace std;
    for (int i = 0; i < n; i++)
    {
        cout << "Property #" << (i + 1) << " : $";
        cout << ar[i] << endl;
    }
}

void revalue (double ratio, double ar[], int n)
{
    for (int i = 0; i < n; i++) {
        ar[i] *= ratio;
    }
}