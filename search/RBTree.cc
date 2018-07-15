/*
 * @Author: zengqinxiong 
 * @Date: 2018-07-14 22:23:25 
 * @Last Modified by: zengqionxiong
 * @Last Modified time: 2018-07-15 16:10:22
 */

#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int value;
    bool isRed;
    Node* left;
    Node* right;
};

Node* create(int val)
{
    Node *node = new Node;
    node->value = val;
    node->isRed = false;
    node->left = node->right = NULL;
    return node;
}

bool isRed(Node* node)
{
    return node != NULL && node->isRed;
}

bool isBlack(Node* node)
{
    return node == NULL || !node->isRed;
}

void reversal(Node* node)
{
    if (node == NULL) return;
    node->isRed = !node->isRed;
}

void setChild(Node* parent, Node* child)
{
    if (parent == NULL) return;
    if (child->value > parent->value)
    {
        parent->right = child;
    }
    else
    {
        parent->left = child;
    }
}

Node* rotateRight(Node* parent)
{
    Node *mid = parent->left;
    parent->left = mid->right;
    mid->right = parent;
    mid->isRed = false;
    parent->isRed = true;
    return mid;
}

Node* rotateLeft(Node* parent)
{
    Node *child = parent->right;
    parent->right = child->left;
    child->left = parent;
    child->isRed = parent->isRed;
    parent->isRed = true;
    return child;
}

void traverse(Node* root)
{
    if (root == NULL) return;
    if (root->isRed)
    {
        cout << root->value << "\tred" << endl;
    }
    else {
        cout << root->value << "\tblack" << endl;
    }
    traverse(root->left);
    traverse(root->right);
}


/**
 * @brief 非递归式的查找
 * 
 * @param root 
 * @param val 
 * @return Node* 
 */
Node* find(Node* root, int val)
{
    Node *current = root;
    while (true)
    {
        if (current == NULL) return NULL;
        if (current->value == val) return current;
        if (val > current->value)
        {
            current = current->right;
        } 
        {
            current = current->left;
        }
    }
    return NULL;
}

/**
 * @brief 插入节点：使用循环方式
 * 
 * @param root 
 * @param val 
 * @return Node* 
 */
Node* insert(Node* root, int val)
{
    if (root == NULL) return create(val);
    // 找到要插入的地方
    Node *current = root;
    Node *node = create(val);
    node->isRed = true;
    stack<Node*> nodeList;
    nodeList.push(NULL);
    nodeList.push(current);
    while (true)
    {
        if (val < current->value) 
        {
            if (current->left == NULL)
            {
                current->left = node;
                break;
            }
            else 
            {
                current = current->left;
            }
        }
        else 
        {
            if (current->right == NULL)
            {
                current->right = node;
                break;
            }
            else 
            {
                current = current->right;
            } 
        }
        nodeList.push(current);
    }
    // 调整
    Node *currentParent, *parentParent;
    do
    {
        current = nodeList.top();
        nodeList.pop();
        currentParent = nodeList.top();
        // 从插入的父节点开始冒泡处理
        // case 1:两个子节点都是红色
        if (isRed(current->left) && isRed(current->right))
        {
            // if (val == 8) cout << "case 1" << endl;
            reversal(current->left);
            reversal(current->right);
            reversal(current);
        }
        // case 2:右节点为红
        else if (!isRed(current->left) && isRed(current->right))
        {
            // if (val == 8) cout << "case 2" << endl;
            // 左旋转
            current = rotateLeft(current);
            setChild(currentParent, current);
            nodeList.push(current);
        }
        // case 3:父节点与左节点为红
        else if (currentParent != NULL && isRed(current) && isRed(current->left))
        {
            // if (val == 8) cout << "case 3" << endl;
            // 右旋转
            current = rotateRight(currentParent);
            nodeList.pop();
            parentParent = nodeList.top();
            setChild(parentParent, current);
            nodeList.push(current);
        }
    } while(!nodeList.empty() && currentParent != NULL);
    // 根节点标记为黑
    current->isRed = false;
    return current;
}

/**
 * @brief 删除指定节点,todo 今晚操作
 * 
 * @param root 
 * @param val 
 */
void remove(Node* root, int val)
{
    if (root == NULL) return;
    Node* current = root;
    Node* delNode = NULL;
    stack<Node*> nodeList;
    nodeList.push(NULL);
    nodeList.push(current);
    while (delNode != NULL && current != NULL)
    {
        if (current->value == val)
        {
            delNode = current;
        }
        if (val > current->value)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
        nodeList.push(current);
    }
    if (delNode == NULL) return;
    // 开始还原
    Node *currentParent, *parentParent; 
    do
    {
        current = nodeList.top();
        nodeList.pop();
    } 
    while (!nodeList.empty());
}

int main(int argc, char const *argv[])
{
    Node *root = create(10);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 1);
    root = insert(root, 9);
    root = insert(root, 8);
    traverse(root);
    return 0;
}
