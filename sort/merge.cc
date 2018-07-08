/*
 * @Author: zengqinxiong 
 * @Date: 2018-07-08 15:30:36 
 * @Last Modified by: zengqionxiong
 * @Last Modified time: 2018-07-08 16:43:31
 */
#include "../util/array.h"

void doMerge(int *array, int lo, int mid, int hi)
{
    int i = lo, j = mid + 1, k = 0;
    int aux[hi - lo];
    for (k = 0; i <= mid && j <= hi; )
    {
        if (isLess(array, i, j))
        {
            aux[k++] = *(array + i);
            i++;
        }
        else {
            aux[k++] = *(array + j);
            j++;
        }
    }
    while (i <= mid)
    {
        aux[k++] = *(array + i);
        i++;
    }
    while (j <= hi)
    {
        aux[k++] = *(array + j);
        j++;
    }
    for (int o = 0;o < k; o ++) {
        *(array + lo + o) = aux[o];
    }
}

void optimizeDoMerge(int *array, int lo , int mid, int hi)
{
    int CUTOFF = 4;
    if ((hi - lo) <= CUTOFF)
    {
        // 进行插入排序
    }
    // 有序的两个数组直接返回就好
    if (isGreater(array, mid + 1, mid))
    {
        return;
    }
    doMerge(array, lo, mid, hi);
}

/**
 * @brief 自顶向下的排序
 * 
 * @param array 
 * @param lo 
 * @param hi 
 */
void merge(int *array, int lo, int hi)
{
    if (hi <= lo) return;
    int mid = lo + (hi - lo) / 2;
    merge(array, lo, mid);
    merge(array, mid + 1, hi);
    doMerge(array, lo, mid, hi);   
}

/**
 * @brief 自下向上版本，最后一个子数组的区间比较难想明白，因为从1翻倍，都会一直小于等于步长
 * 
 * @param array 
 * @param n 
 */
void fromDownToUp(int* array, int n)
{
    for (int i = 1; i < n; i += i)
    {
        for(int j = 0; j < n - i; j+= 2*i)
        {
            int innerHi;
            if (n < j + 2*i)
            {
                innerHi = n - 1;
            }
            else {
                innerHi = j + 2*i - 1;
            }
            optimizeDoMerge(array, j, j + i - 1, innerHi);
            // doMerge(array, j, j + i - 1, innerHi);
        }
    }
}

int main(int argc, char const *argv[])
{
    int* array = randArr(10);
    print(array, 10);
    // merge(array, 0, 9);
    fromDownToUp(array, 10);
    print(array, 10);
    return 0;
}
