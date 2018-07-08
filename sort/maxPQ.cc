/*
 * @Author: zengqinxiong 
 * @Date: 2018-07-08 20:02:45 
 * @Last Modified by: zengqionxiong
 * @Last Modified time: 2018-07-08 20:49:09
 */
#include "../util/array.h"
#include <queue>
#include <iostream>
using namespace std;

void priorityQueueSort()
{
    priority_queue<int> q;
    int* array = randArr(10);
    for(int i = 0; i < 10; i++)
    {
        q.push(*(array + i));
    }
    for (int i = 0; i<10; i++)
    {
        cout << q.top() << endl;
        q.pop();
    }
}


void insert(int* pq, int v)
{
    *(pq + *(pq) + 1) = v;
    *(pq) = *(pq) + 1;
    int index = *(pq);
    // 进行上浮操作
    while (index > 1 && isLess(pq, index/2, index))
    {
        swap(pq, index, index / 2);
        index = index / 2;
    }
}

int delMax(int* pq)
{
    int max = *(pq + 1);
    *(pq + 1) = *(pq + *(pq));
    *(pq + *(pq)) = 0;
    *(pq) = *(pq) - 1;
    int index = 1;
    // 进行下沉操作
    while (index * 2 <= *(pq))
    {
        int child = index * 2;
        if (isLess(pq, index, child));
        else if (isLess(pq, index, child + 1)) child += 1;
        else break;
        swap(pq, index, child);
        index = child;
    }
    return max;
}

/**
 * @brief 基本思路就是构造二叉堆，使用二叉堆的天然属性进行排序
 * 
 */
void testPQ()
{
    int *pq = new int[10];
    *(pq) = 0;
    
    int* array = randArr(10);
    for (int i = 0; i < 10; i++)
    {
        insert(pq, *(array + i));
    }
    for (int i = 0; i < 10; i++)
    {
        cout << delMax(pq) << endl;
    }
}

int main(int argc, char const *argv[])
{
    
    testPQ();
    return 0;
}
