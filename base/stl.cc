/*
 * @Author: zengqinxiong 
 * @Date: 2018-07-04 21:35:02 
 * @Last Modified by: zengqionxiong
 * @Last Modified time: 2018-07-04 21:57:58
 * 
 * 参考链接：https://blog.csdn.net/u014465639/article/details/70241850
 */


#include <iostream>
#include <vector>
#include <map>
using namespace std;

void order()
{
    // vector(向量)
    vector<int> vec1;
    vector<int> vec2(vec1);
    vector<int> vec3(vec1.begin(), vec2.end());
    vector<int> vec4(10);
    vector<int> vec5(10, 3);

    vec1.insert(vec1.end(), 1);
    cout << vec1[0] << endl;

    vec1.pop_back();
    vec1.insert(vec1.end(), 3, 2);
    int length = vec1.size();
    cout << "circulation" << endl;
    for (int i = 0; i < length; i++)
    {
        cout << vec1[i] << endl;
    }
    // vector<int>::const_iterator iterator = vec1.begin();
    // for(; iterator != vec1.end(); iterator ++)
    // {
    //     cout << *(iterator);
    // }
    // vec1.erase(vec1.begin(), vec1.end());
    // vec1.clear();
    /// 

    // list(列表)
    // 类似vector 但是内存实现是链表，而且支持reverse等操作

    // deque(队列)
    // 基本同vector 但是支持push_front，底层上某一位置的操作的花费是线性时间
}

void relation()
{
    // map(集合)
    map<int, string> map1;
    map1[3] = "Saniya";
    map1.insert(map<int, string>::value_type(2, "Diyabi"));
    map1.insert(make_pair<int, string>(4, "V5"));

    string str = map1[3];
    map1.erase(3);
    
    for (map<int, string>::iterator iter = map1.begin(); iter != map1.end(); iter++ )
    {
        cout << iter->first << "-" << iter->second << endl; 
    }

    // set(映射)

    // multimap(多重集合)

    // multiset(多重映射)
}


void container()
{
    // stack(栈)

    // queue(队列)
    
    // priority_queue(优先队列)
}


int main(int argc, char const *argv[])
{
    // 顺序容器
    order();

    // 关联容器
    relation();

    // 容器适配器
    container();

    return 0;
}
