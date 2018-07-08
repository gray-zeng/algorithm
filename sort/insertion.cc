/*
 * @Author: zengqinxiong 
 * @Date: 2018-07-01 11:42:24 
 * @Last Modified by: zengqionxiong
 * @Last Modified time: 2018-07-08 15:17:13
 */
#include <iostream>
#include "../util/array.h"
using namespace std;

/**
 * @brief 插入排序：遍历数组，每次都构造顺序数列，然后将下一元素插入到该顺序数列中
 *        一般复杂度：n^2/2，最好情况是顺序数组，只需要n次比较
 * 
 * @param array 
 * @param n 
 */
void insertion(int *array, int n)
{
    for (int i = 1; i < n; i++)
    {
        // 比较构建好的子数列，堆积的信息比较多
        for (int j = i; j > 0 && *(array + j) < *(array + j - 1); j--)
        {
            int tmp = *(array + j);
            *(array + j) = *(array + j - 1);
            *(array + j - 1) = tmp;
        }
    }
}

int main(int argc, char const *argv[])
{
    int *p = randArr(6);
    print(p, 6);

    insertion(p, 6);

    print(p, 6);

    return 0;
}
