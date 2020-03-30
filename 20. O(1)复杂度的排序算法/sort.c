/*
现在让我们重排这个数组，从头到尾依次扫描这个数组中的每一个数字。当扫描到下标为i的数字时，
首先比较这个数字（用m表示）是不是等于i。如果是，则接着扫描下一个数字；如果不是，则在拿它和
第m个数字进行比较，如果它和第m个数字相等，就找到了一个重复的数字（该数字在下标为i和m个数字交换，把m放在属于它的位置。
接着再重复这个比较交换的过程，直到我们发现一个重复的数字）


以数组{2, 3, 1, 0, 2, 5, 3}为例来分析找到重复数字的步骤，数组的第0个数字（从0 开始计数，和数组下标保持一致）是2，
与它的下标不相等，于是把它和下标为2的数字1交换。交换之后的数组是{1, 3, 2, 0, 2, 5, 3}。
此时第0个数字是1，仍然与它的下标不相等，继续把它和下标为1的数字，得到数组{3, 1, 2, 0, 2, 5, 3}。接下来继续交换第0个数字3
和第3个数字0，得到数组{0, 1, 2, 3, 2, 5, 3}，在接下来的几个数字中，下标为1,2,3的3个数字分别为1,2,3,，他们的下标和数值都分别相等，
因此不需要执行任何操作。接下来扫描到下标为4的数字2，由于它的数值与它的下标不相等，在比较它和下标为2的数字。注意到此时数组下标为2的数字
也是2，也就是数字2在下标为2和下标为4的两个位置都出现了，因此找到一个重复的数字
*/

bool duplicate(int numbers[], int length, int *duplication)
{
	if(numbers == nullptr || length <= 0)
	{
		return false;
	}
	
	for(int i=0; i<length; ++i)
	{
		if(numbers[i] < 0 || numbers[i] > length-1)
			return false;
	}
	
	for(int i=0; i<length; ++i)
	{
		while(numbers[i] != i)
		{
			if(numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				return true;
			}
			
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
	
	return false;
}