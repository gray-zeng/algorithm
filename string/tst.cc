#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string c;
    int count;
    Node *next;
    Node *left;
    Node *right;
};


Node* create(string c)
{
    Node *node = new Node;
    node->c = c;
    node->count = 0; // 设置成默认0次数
    node->next = node->left = node->right = NULL;
    return node;
}

Node* insert(Node *root, string str)
{
    int len = str.length(), i=0;
    Node *current = root;
    do 
    {
        if (current->c == str[i])
        {
            i++;
            current = :
        }
        i++;    
    } 
    while(i< len);
    return root;
}

Node* del(Node *root, string str)
{
    for (int i=0; i<str.length(); i++)
    {
    }
    return root;
}

bool exist(Node *root, string str[])
{
    return false;
}


int main(int argc, char const *argv[])
{
    string first = "first";
    Node *root = create("f");
    insert(root, first);
    return 0;
}
