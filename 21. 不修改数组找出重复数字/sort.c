#include <stdio.h>
#include <stdlib.h>
/*
在一个长度为n+1的数组里的所有数字都在1~n的范围内，所以数组中至少有一个数字时重复的。
请找出数组中任意一个重复的数字，但不能修改输入的数组。例如，输入长度为8的数组{2,3,5,4,3,2,6,7}，那么
对应输出的重复数字2或者3

这一题看起来和上面面试题类似，由于题目要求不能修改输入的数组，我们可以创建一个长度为n+1的辅助数组，然后逐一把原数组的每个数字复制到辅助数组。
如果原数组中被复制的数字是m，则把它复制到辅助数组中下标为m的位置。这样很容易能发现哪个数字时重复的。由于需要创建一个数组
由于需要创建一个数组，该方案需要O(n)的辅助空间。

我们以长度为8的数组{2,3,5,4,3,2,6,7}为例分析查找的过程。根据题目要求，这个长度的所有数字都在1~7的范围内。中间的数字4把1~7的范围分为两段，一段是1~4，另一段是
5~7。接下来我们统计1~4这4个数字在数组中出现的次数，它们一共出现了5次，因此这4个数字有一定重复的数字。

接下来我们再把1~4的范围一分为2，一段是1,2两个数字，另一个是3,4两个数字。数字1或者2在数组中一共出现了两次。我们在统计数字3或者4在数组中出现的次数，它们一共出现了三次。
这意味着3、4两个数字一定有一个重复了。我们再分别统计这两个数字在数组中出现的次数。接着我们发现数字3出现了两次，是一个重复的数字

*/
int countRange(const int * numbers,int length, int start, int end)
{
    if(numbers == nullptr)
        return 0;
    int count = 0;
    for(int i=0; i<length; i++)
        if(numbers[i] >= start && numbers[i] <= end)
            ++count;
    return count;
}

int getDuplication(const int *numbers, int length)
{
    if(numbers == nullptr || length <= 0)
        return -1;


    int start = 1;
    int end = length - 1;
    while(end >= start)
    {
        int middle = ((end - start) >> 1) + start;
        int count = countRange(numbers, length, start, middle);
        //计算到最后
        if(end == start)
        {
            if(count > 1)
                return start;
            else
                break;
        }

        if(count > (middle - start + 1))
            end = middle;
        else
            start = middle + 1;
    }
    return -1;
}

