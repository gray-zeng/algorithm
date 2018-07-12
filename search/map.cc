/*
 * @Author: zengqinxiong 
 * @Date: 2018-07-10 23:12:23 
 * @Last Modified by: zengqionxiong
 * @Last Modified time: 2018-07-10 23:20:28
 */
#include <iostream>
#include <map>
using namespace std;


int main(int argc, char const *argv[])
{
    // cpp中的符号表觉得可以直接使用自带的map
    map<int, int> m1;
    m1.insert(map<int, int>::value_type(1,1));
    map<int,int>::iterator find = m1.find(1);
    cout << find->first << ":" << find->second << endl;    
    return 0;
}
