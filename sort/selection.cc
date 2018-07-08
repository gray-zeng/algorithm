/*
 * @Author: zengqinxiong 
 * @Date: 2018-07-01 11:30:36 
 * @Last Modified by: zengqionxiong
 * @Last Modified time: 2018-07-01 11:58:01
 */
#include <iostream>
using namespace std;

/**
 * @brief 插入排序，遍历数组每次找到最小的值，然后同之前的值做交换
 *        复杂度为n^2/2f，可以认为和冒泡类似，只是选择排序不需要进行这么多次的交换
 * 
 * @param array 
 * @param n 
 */
void selection(int *array, int n)
{
    int minIndex,tmpVal;
    for (int i = 0; i < n; i++)
    {
        // 找到最小的值
        minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (*(array + j) < *(array + minIndex))
            {
                minIndex = j;
            }
        }
        // 交换
        tmpVal = *(array + i);
        *(array + i) = *(array + minIndex);
        *(array + minIndex) = tmpVal;
    }
}

int main(int argc, char const *argv[])
{
    int array[4] = {3,2,4,1};
    int *p = array;
    selection(p, 4);

    for (int i = 0; i < 4; i++)
    {
        cout << *(p + i) << endl;
    }
    return 0;
}
