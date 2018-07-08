/*
 * @Author: zengqinxiong 
 * @Date: 2018-07-01 15:58:59 
 * @Last Modified by: zengqionxiong
 * @Last Modified time: 2018-07-08 15:29:18
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

void swap(int* arr, int i, int j)
{
    int tmp = *(arr + i);
    *(arr + i) = *(arr + j);
    *(arr + j) = tmp;
}

bool isLess(int* arr, int i, int j)
{
    return *(arr + i) < *(arr + j); 
}

bool isGreater(int *arr, int i, int j)
{
    return !isLess(arr, i, j);
}