#include<iostream>
#include<exception>
using namespace std;

int MinInOrder(int *, int, int);

int Min(int * numbers, int length)
{
	if (numbers == nullptr || length <= 0)
    {
        cout << "Invalid parameters" << endl;
        return -1;
    }

	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;
	while (numbers[index1] >= numbers[index2])
	{
		if (index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}

		indexMid = (index1 + index2) / 2;

		//����±�index1��index2��indexMidָ�������������ȣ���ֻ��˳�����
		if (numbers[index1] == numbers[indexMid] && numbers[indexMid] == numbers[index2])
			return MinInOrder(numbers, index1, index2);

		if (numbers[indexMid] >= numbers[index1])
		{
			index1 = indexMid;
		}
		else if (numbers[indexMid] <= numbers[index2])
		{
			index2 = indexMid;
		}
	}
	return numbers[indexMid];
}

//˳�����
int MinInOrder(int * numbers, int index1, int index2)
{
	int result = numbers[index1];
	for (int i = index1 + 1; i <= index2; ++i)
	{
		if (result > numbers[i])
			result = numbers[i];
	}
	return result;
}

//����
int main()
{
	int numbers[] = { 3, 4, 5, 1, 2 };
	int length = sizeof(numbers) / sizeof(numbers[0]);
	cout<<Min(numbers, length)<<endl;
	system("pause");
	return 0;
}
