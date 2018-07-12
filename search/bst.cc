/*
 * @Author: zengqinxiong 
 * @Date: 2018-07-10 23:21:11 
 * @Last Modified by: zengqionxiong
 * @Last Modified time: 2018-07-10 23:59:21
 */
#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int value;
    Node* left;
    Node* right;
};

Node *create(int val)
{
    Node *node = new Node;
    node->value = val;
    node->left = node->right = NULL;
    return node;
}

Node* moveLeft(Node* right, Node* left)
{
    if (right == NULL) return left;
    Node* current = right;
    while (current->left != NULL)
    {
        current = current->left;
    }
    current->left = left;
    return right;
}

Node* moveRight(Node* left, Node* right)
{
    if (left == NULL) return right;
    Node* current = left;
    while (current->right != NULL)
    {
        current = current->right;
    }
    current->right = right;
    return left;
}

void insert(Node *root, int val)
{
    if (root == NULL) return;
    if (val < root->value)
    {
        if (root->left == NULL)
        {
            Node *node = create(val);
            root->left = node;
        }
        else 
        {
            insert(root->left, val);
        }
    }
    else {
        if (root->right == NULL)
        {
            Node *node = create(val);
            root->right = node;
        }
        else 
        {
            insert(root->right, val);
        }
    }
}

Node* find(Node *root, int val)
{
    if (root == NULL) return root;
    if (root->value == val) return root;
    if (val > root->value)
    {
        return find(root->right, val);
    }
    else
    {
        return find(root->left, val);
    }
}

/**
 * @brief 删除节点
 * 
 * @param root 
 * @param val 
 * @return Node* 
 */
Node* del(Node *root, int val)
{
    if (root == NULL) return root;
    // 删除根节点
    if (root->value == val)
    {
        // 空了任一一边的子树
        if (root->left == NULL) return root->right;
        if (root->right == NULL) return root->left;
        // 将左子树插到右子树的最小侧
        return moveLeft(root->right, root->left);
    }
    // 左子树命中
    else if (root->left != NULL && root->left->value == val)
    {
        root->left = moveLeft(root->left->right, root->left->left);
    }
    // 右子树命中 
    else if (root->right != NULL && root->right->value == val)
    {
        root->right = moveRight(root->right->left, root->right->right);
    }
    else {
        if (val > root->value) 
        {
            del(root->right, val);
        }
        else {
            del(root->left, val);
        }
    }
    return root;
}

/**
 * @brief 删除最值 其实可以依靠上面的del来做删除
 * 
 * @param root 
 * @param val 
 * @return Node* 
 */
Node* delMin(Node *root, int val)
{
    if (root == NULL) return root;
    if (root->left == NULL) return root->right;
    Node *parent = root;
    Node *node = root->left;
    // 遍历到左子树节点为空
    while (node->left != NULL) 
    {
        parent = node;
        node = node->left;
    }
    if (node->right)
    {
        parent->left = node->right;
    }
    else
    {
        parent->left = NULL;
    }
    return root;
}

/**
 * @brief 三种版本的递归实现
 * 
 * @param root 
 * @param type 
 */
void traverse(Node *root, unsigned int type)
{
    if (root == NULL) return;
    switch(type)
    {
        // 前序遍历:根节点->左子树->右子树
        case 2:
            cout << root->value << endl;
            traverse(root->left, type);
            traverse(root->right, type);
            break;
        // 后序遍历:左子树->右子树->根节点
        case 1:
            traverse(root->left, type);
            traverse(root->right, type);
            cout << root->value << endl;
            break;
        // 中序遍历:左子树->根节点->右子树
        default:
            traverse(root->left, type);
            cout << root->value << endl;
            traverse(root->right, type);
    }
}

/**
 * @brief 求节点数量
 * 
 * @param root 
 * @return int 
 */
int size(Node *root)
{
    if (root == NULL) return 0;
    return 1 + size(root->left) + size(root->right);
}

/**
 * @brief 求二叉树的最大深度
 * 
 * @param root 
 * @return unsigned 
 */
unsigned height(Node *root)
{
    if (root == NULL) return 0;
    // 递归版本
    // int left = height(root->left);
    // int right = height(root->right);
    // if (left > right)
    // {
    //     return left + 1;
    // }
    // else
    // {
    //     return right + 1;
    // }
    // 非递归版本 使用层级遍历，从根节点往下走
    int n = 0;
    queue<Node*> q1;
    queue<Node*> q2;
    q1.push(root->left);
    q1.push(root->right);
    while (!q1.empty())
    {
        n++;
        while (!q1.empty())
        {
            Node *next = q1.front();
            q1.pop();
            if (next != NULL)
            {
                q2.push(next->left);
                q2.push(next->right);
            }
        }
        q1 = q2;
        q2 = queue<Node*>();
    }
    return n;
}

int main(int argc, char const *argv[])
{
    Node *root = new Node;
    root->value = 10;
    root->left = root->right = NULL;
    insert(root, 1);
    insert(root, 3);
    insert(root, 12);
    // del(root, 3);
    traverse(root, 2);
    // cout << size(root) << endl;
    cout << height(root) << endl;
    return 0;
}
