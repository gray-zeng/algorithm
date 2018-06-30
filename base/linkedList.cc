/*
 * @Author: zengqinxiong
 * @Date: 2018-06-27 22:53:26 
 * @Last Modified by: zengqionxiong
 * @Last Modified time: 2018-06-30 20:22:40
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
    while (p != NULL && (n == 0 || p != head)) 
    {
        p = p->next;
        n ++;
    }
    return n;
}

void append(node *head, int data)
{
    // 判断head是否null
    node *p = head;
    while (p->next != NULL)
    {
        p = p->next;   
    }
    node *append = new node;
    append->data = data;
    append->next = NULL;
    p->next = append;
}

int main(int argc, char const *argv[])
{

    node *head = new node;
    head->data = 1;
    head->next = NULL;

    cout << length(head) << endl;

    append(head, 2);
    cout << length(head) << endl;

    // 测试环
    head->next->next = head;
    cout << length(head) << endl;

    return 0;
}
