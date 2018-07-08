/*
 * @Author: zengqinxiong 
 * @Date: 2018-07-08 17:31:57 
 * @Last Modified by: zengqionxiong
 * @Last Modified time: 2018-07-08 20:02:23
 */
#include "../util/array.h"
#include <stack>
#include <iostream>

int partition(int* array, int lo, int hi)
{
    int guard = *(array + lo);
    int i = lo, j = hi + 1;
    while (true)
    {
        // 这样必须保证guard不是最大的，通用做法是刚开始排序的时候把最大的元素放在最右边
        // while (guard < *(array + --j));
        // while (guard > *(array + ++i)); 
        while (guard < *(array + --j)) if (j == lo) break;
        while (guard > *(array + ++i)) if (i == hi) break;
        if(i >= j) break;
        swap(array, i, j);
    }

    swap(array, lo, j);
    // cout << j << ":" << *(array + j) << endl;
    // print(array, 10);
    return j;
}

void quick(int* array, int lo, int hi)
{
    if (hi <= lo) return;
    int j = partition(array, lo, hi);
    quick(array, lo, j - 1);
    quick(array, j + 1, hi);
}

/**
 * @brief 使用堆来保存尾递归信息，将递归优化为循环
 * 
 * @param array 
 * @param lo 
 * @param hi 
 */
void quickStack(int* array, int lo, int hi)
{
    stack<int> s;
    s.push(lo);
    s.push(hi);
    while(!s.empty())
    {
        hi = s.top();
        s.pop();
        lo = s.top();
        s.pop();
        if (hi <= lo) continue;
        int j = partition(array, lo, hi);
        // 优先解决掉小数组，减少循环链
        if (j-lo > hi-j) 
        {
            s.push(lo);
            s.push(j - 1);
            s.push(j + 1);
            s.push(hi);
        }
        else
        {
            s.push(j+1);
            s.push(hi);
            s.push(lo);
            s.push(j-1);
        }
    }
}

/**
 * @brief 三向切分快速归并排序，用于优化在有很多重复元素时的快排的对比
 * 
 * @param array 
 * @param lo 
 * @param hi 
 */
void quick3way(int* array, int lo, int hi)
{
    if (hi <= lo) return;
    int lt = lo, i = lo + 1, gt = hi;
    int guard = *(array + lo);
    while (i <= gt)
    {
        if (*(array + i) == guard)
        {
            i++;
        } 
        else if (*(array + i) < guard)
        {
            swap(array, i++, lt++);
        }
        else {
            swap(array, i, gt--);   
        }
    }
    quick3way(array, lo, lt - 1);
    quick3way(array, gt + 1, hi);
}

int main(int argc, char const *argv[])
{
    int *array = randArr(10);
    *(array + 0) = 20;
    print(array, 10);
    // quick3way(array, 0, 9);
    // quick(array, 0, 9);
    quickStack(array, 0, 9);
    print(array, 10);
    return 0;
}
