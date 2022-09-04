#include <iostream>


/*
题目:请实现一个函数，把字符串中的每个空格替换成"%20"。例如,输入“We are happy.”，

    则输出“We%20are%20happy.”。
    We are happy length:12
    We%20are%20happy  length:12+2*2 = 16
*/
using namespace std;

class Solution {
public:
    string replaceSpace(string s)
    {
        if(s.empty()) return s;
        int count = 0;
        for(auto i : s)
            if(i == ' ')
                count++;
        s.resize(s.length()+count*2, 0);
        for(int i = s.length()-1; i >= 0; --i)
        {
            if(s[i] != ' ')
                s[i+count*2] = s[i];
            if(s[i] == ' ')
            {
                count--;
                s[i+count*2] = '%';
                s[i+count*2+1] = '2';
                s[i+count*2+2] = '0';
            }
        }

        return s;
    }

private:
    int length;
};

int main()
{
    Solution s;
    string replaceString;
    replaceString = s.replaceSpace("We are happy.");


    cout << "Hello world!" << replaceString << endl;
    return 0;
}
