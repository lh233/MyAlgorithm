#include <iostream>

using namespace std;

/*
如果一个整数不等于0，那么该整数的二进制表示中至少有一位是0。

假设最后一位不是0，那么减去1，最后一位变成0而其他所有位都保持不变，也就是最后一位相当于做了取反操作，由1变成了0.

假设最后一位是0，如果该整数的二进制表示中最右边的1位于第m位，那么减去1时，第m位由1变成0，而第m位之后的所有0都变成1，
整数中第m位之前的所有位都保持不变。

把一个整数和它减去1的结果做位与运算，相当于把它最右边的1变成0。

所以，这种方法，只要这个整数有几个1，就做几次这样的操作。

综上，可以得到下列代码：

*/

static int NumberOf1_Three(int n)
{
    int count = 0;
    while (n != 0)
    {
        count++;
        n = n & (n - 1);
    }
    return count;
}


int main()
{
    int count = NumberOf1_Three(4);
    cout << "count: " << count << endl;
    return 0;
}
