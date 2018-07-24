/**
 * example http://blog.163.com/zhaohai_1988/blog/static/2095100852012716105847112/
 */


#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPalindrome(string str)
{
    if (str.length() <= 1) return true;
    string::iterator begin, end;
    begin = str.begin();
    end = str.end();
    end -- ;
    // cout << *(begin) << *(end) << endl;
    while(begin < end) {
        if (*(begin) != *(end)) return false;
        begin++;
        end--;
    }
    return true;
}

vector<int> maxSize(string str)
{
    int initRes[] = {1, 0};
    vector<int> res(initRes, initRes + 3);
    if (str.length() < 2) return res;
    // 初始化
    vector< vector<bool> > matrix(str.length(), vector<bool>(str.length(), false));
    for (int i=0; i<str.length(); i++) matrix[i][i] = true;
    // 使用动态规划扫描
    for (int len = 2; len <= str.length(); len ++)
    {
        for (int i = 0; i < str.length()-len+1; i++)
        {
            int j = i + len - 1;
            if (matrix[i+1][j-1] && str[i] == str[j])
            {
                matrix[i][j] = true;
                res[0] = len;
                res[1] = i;
            }
        }
    }
    
    return res;
}

vector<int> maxSizeCenter(string str)
{
    int pos = 0, len = 1;
    // 使用中心遍历法
    for (int i=0; i<str.length() -len+1; i++)
    {
        // 奇数和偶数对称
        for (int j=0;j<1;j++)
        {
            int left = i, right = i + j;
            while(left >=0 && right < str.length() && str[left] == str[right])
            {
                left --;
                right ++;
            }
            if (right-left-1 > len)
            {
                len = right-left-1;
                pos = left+1;
            }
        }
    }

    vector<int> res;
    res.push_back(len);
    res.push_back(pos);
    return res;
}

int main(int argc, char const *argv[])
{
    // 判断是否回文
    // string input;
    // do {
    //     getline(cin, input);
    //     cout << "\"" << input << "\" is:" << isPalindrome(input) << endl;
    // } while(!input.empty());
    
    string test = "111211323434111";
    // vector<int> res = maxSize(test);
    vector<int> res = maxSizeCenter(test);
    cout << res[0] << ":" << res[1] << " \t:" << test.substr(res[1], res[0]) << endl;

    return 0;
}
