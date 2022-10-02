#include <iostream>

using namespace std;

/*
斐波那契数列：1，1，2，3，5，8，13，21，34，55，89...
如果设an为该数列的第n项（），那么这句话可以写成如下形式：an = an-1 +an-2
*/

//时间复杂度O(2^n)
long long SlutionFibonacci_1(int n)
{
	if(n == 0)
		return 0;
	if(n ==1)
		return 1;
	return SlutionFibonacci_1(n-2)+SlutionFibonacci_1(n-1);
}


//时间复杂度O(n)
long long SlutionFibonacci_2(int n)
{
	int result[2] = {0,1};
	if(n<2)
		return result[n];
	int FibN = 0;
	int FibNMinus1 = 1;
	int FibNMinus2 = 0;
	for(int i=2; i<=n; i++)
	{
		FibN = FibNMinus1+FibNMinus2;
		FibNMinus2 = FibNMinus1;
		FibNMinus1 = FibN;
	}
	return FibN;
}



int main()
{
    long long n = SlutionFibonacci_1(10);
	std::cout<<"n:"<<n<<std::endl;
	long long m = SlutionFibonacci_2(10);
	std::cout<<"m:"<<m<<std::endl;
    return 0;
}
