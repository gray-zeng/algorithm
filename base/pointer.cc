#include <iostream>
using namespace std;


void swap(int *a) 
{
    int tmp = *a;
    *a = *(a + 1);
    *(a + 1) = tmp;
}

void parameter() 
{
    // 指针和数组的对比
    int arr[2] = {1, 2};
    int *pA;

    // 通过指针传入地址，修改值
    pA = arr;
    swap(pA);

    cout << arr[0] << endl;
    cout << arr[1] << endl;

}

void pointerAndArray()
{
    int var[3] = {10, 100, 200};
    int *pointer;
    for (int i = 0; i < 3; i ++)
    {
        *(pointer + i) = i * 10;
    }

    for (int i = 0; i < 3; i++)
    {
        cout << var[i] << endl;
        cout << (pointer + i) << endl;
    }
}

void pointerArray()
{
    char *names[4] = {
        "Zara Ali",
        "Hina Ali",
        "Nuha Ali",
        "Sara Ali",
    };

    for (int i = 0; i < 4; i++)
    {
        cout << names[i] << endl;
    }
}

void pointerStr()
{
    char *str = "abcd";

    for (int i = 0; i < 4; i++)
    {
        cout << *(str + i) << endl;
        // cout会自动将指针的其他内容输出出来，同时避免了溢出攻击
        // cout << (str + i) << endl;
    }
}

int main(int argc, char const *argv[])
{
    // 参数相关
    parameter();

    // 指针和数组
    try
    {
        // pointerAndArray();
    } catch (...)
    {
        // 这里是直接错误了，不是异常
        cout << "has error" << endl;
    }

    // 指针数组
    pointerArray();

    // 字符串处理
    pointerStr();

    return 0;
}
