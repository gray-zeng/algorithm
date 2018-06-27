/*
 * @Author: zengqinxiong
 * @Date: 2018-06-27 22:53:26 
 * @Last Modified by: mikey.zhaopeng
 * @Last Modified time: 2018-06-27 23:01:48
 */
#include <iostream>
using namespace std;

struct node 
{
    int data;
    node *next;
};

int length(node *head)
{
    int n = 0;
    node *p = head;
    while (p != NULL) {
        p = p->next;
        n ++;
    }
    return n;
}

int main(int argc, char const *argv[])
{


    return 0;
}
