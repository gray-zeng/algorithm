/*
 * @Author: zengqinxiong 
 * @Date: 2018-06-30 19:53:23 
 * @Last Modified by: zengqionxiong
 * @Last Modified time: 2018-06-30 20:09:42
 */
#include <iostream>
using namespace std;

int fibonacci(int n)
{
    // 终止情况
    if (n <= 0) {
        return 0;
    }
    if (n == 1 || n == 2) {
        return 1;
    }
    // 递归入口
    return fibonacci(n-1) + fibonacci(n-2);
}

int fibonacciRec(int n)
{
    if (n <= 2)
    {
        return 1;
    }
    unsigned int res1 = 1, res2 = 1, tmp = 0;
    for (unsigned int i = 0; i < n - 2; i++) 
    {
        tmp = res2;
        res2 = res1 + res2;
        res1 = tmp; 
    }

    return res2;
}

int main(int argc, char const *argv[])
{
    cout << fibonacci(30) << endl;
    return 0;
}
