/*
 * @Author: zengqinxiong 
 * @Date: 2018-07-18 22:22:35 
 * @Last Modified by: zengqionxiong
 * @Last Modified time: 2018-07-19 00:00:07
 */
#define M  249997 
#define M1 1000001 
#define M2 0xF0000000

#include <iostream>
#include <list>
using namespace std;

// BKDR Hash Function  
unsigned int BKDRHash(char*str) 
{ 
    unsigned int seed=131 ;// 31 131 1313 13131 131313 etc..  
    unsigned int hash=0 ;     
    while(*str) 
    { 
        // 这里确认不会有溢出的问题？
        hash=hash*seed+(*str++); 
    }     
    return(hash % M); 
}

class BaseMap
{
public:
    void set(int key, int val)
    {

    }
    int get(int key)
    {
        return key;
    }
    int del(int key)
    {
        return key;
    }
    bool exist(int key)
    {
        return false;
    }
protected:
    int size;
    int count;

    int hash(int key)
    {
        return key % size;
    }
};

/**
 * @brief 拉链法实现
 * 
 */
class Map:public BaseMap
{
public:
    Map()
    {
        this->size = 10;
        this->count = 0;
        this->keys = new list<int>[this->size];
        this->values = new list<int>[this->size];
        for (int i = 0; i< this->size; i++) {
            list<int> kl;
            *(this->keys + i) = kl;
            list<int> vl;
            *(this->values +i) = vl;
        }
    }
    void set(int key, int val)
    {
        cout << "set:" << key << " value=" << val << endl;
        int h = this->hash(key);
        int keyIndex = this->listIndex(*(this->keys + h), key);
        // 进行插入
        if (keyIndex == -1) {
            (*(this->keys + h)).push_back(key);
            (*(this->values + h)).push_back(key);
            cout << this->count++ << endl;
        }
        // 进行更新
        else {
            this->updateList(*(this->values + h), keyIndex, val);
        }
    }
    int get(int key)
    {
        int h = this->hash(key);
        int keyIndex = this->listIndex(*(this->keys + h), key);
        if (keyIndex == -1) {
            return -1;
        }
        else {
            list<int>::iterator iter = (*(this->values + h)).begin();
            while(keyIndex --) iter ++;
            return *(iter);
        }
    }
private:
    list<int> *keys;
    list<int> *values;
    int listIndex(list<int> l, int v)
    {
        list<int>::iterator iter;
        int index = 0;
        for (iter = l.begin(); iter != l.end(); iter ++, index ++) {
            if (*iter == v) {
                return index;
            }
        }
        return -1;
    }
    void updateList(list<int> l,int index, int value)
    {
        if (index > l.size()) return;
        list<int>::iterator iter = l.begin();
        while(index--) iter ++;
        *(iter) = value;
    }
};

int main(int argc, char const *argv[])
{
    // char str[] = "12312423~ifnewiufslmsdlkfmsodiwejrowejroiwejrwe";
    // char* strP = str;
    // cout << BKDRHash(strP) << endl;
    Map map;
    map.set(1,1);
    map.set(1,2);
    map.set(1,3);
    map.set(2,8);
    map.set(3,1);

    cout << "key:1 value:" << map.get(1) << endl;
    return 0;
}
