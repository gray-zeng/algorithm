/*
 * @Author: zengqinxiong 
 * @Date: 2018-07-01 15:58:59 
 * @Last Modified by: zengqionxiong
 * @Last Modified time: 2018-07-08 15:17:23
 */
#include <iostream>
using namespace std;


void print (int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(arr + i);
        if (i == n-1) {
            cout << endl;
        } else {
            cout << ",";
        }
    }
}

int* randArr(int len)
{
    srand((unsigned)time(NULL));

    int *p = new int[len];

    for (int i = 0; i < len; i ++)
    {
        *(p + i) = rand() % len;
        // cout << arr[i] << endl;
    }

    // print(p, len);
    return p;
}