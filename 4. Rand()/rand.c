/*
* 假设需要生成前N个自然数的一个随机置换。例如，{4，3，1，5，2}和{3，1，4，2，5}就是合法的置换，但{5，4，1，2，1}却不是，
* 因为数1出现两次而数3却没有。这个程序常常用于模拟一些算法。我们假设存在一个随机数生成器RandInt(i,j)，它以相同的概率生成i和j之间
* 的一个整数。
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int RandInt(int i, int j)
{
    if(i == 0)
        return rand()%(j+1);
    else
        return rand()%(j-i+1) + i;
}

//算法一：  时间复杂度O（N²logN）
/*
填入从a[0]到a[n-1]的数组a,为了填入a[i]，生成随机数直到它不同于已经生成的a[0],a[1],...,a[i-1]时，再将其填入a[i].

*/

void fun1(int a[], int n)
{
    int i, j;
	int tmp;
	for (i = 0; i < n; i++)
	{
		tmp=RandInt(1, n);
		for (j = 0; j < i; j++)
		{
			if(tmp==a[j])
			{
				tmp=RandInt(1, n);
				j=-1;
			}
		}
		a[i] = tmp;
	}
}

//算法二：时间复杂度O(NlogN)
/*
同算法一，但要保存一个附加的数组，称之为Used(用过的)数组。当一个随机数ran最初被放入数组A的时候，置Used[ran]=1。

*/
void fun2(int a[], int n)
{
	int tmp;
	int used[5] = {0};
	int i;
	for (i = 0; i < n; i++)
	{
		tmp=RandInt(1, n);
		//printf("tmp = %d, used[%d] = %d\t", tmp, tmp, used[tmp]);
		while(used[tmp-1]!=0)
			tmp=RandInt(1, n);
		a[i]=tmp;
		//printf("a[%d] = %d\t", i, a[i]);
		used[tmp]=1;
	}
}

/*
算法三：时间复杂度O(N)
填写该数组使得a[i]=i+1.然后：
for(i=1; i<N; i++)
swap(&a[i], a[RandInt(0,i)]);
*/

void swap(int *a, int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

void fun3(int a[], int n)
{
    int i;
	for (i = 0; i < n; i++)
	{
		a[i]=i+1;
	}
	for (i = 1; i < n; i++)
	{
		swap(&a[i], &a[ RandInt(0, i) ]);
	}
}

int main(int argc, char ** argv)
{
    int i = 0;
    srand(time(NULL));
    int a[5] = {4, 3, 1, 5, 2};
    int b[5] = {4, 3, 1, 5, 2};
    int c[5] = {4, 3, 1, 5, 2};

    fun1(a, 5);
    fun2(b, 5);
    fun3(c, 5);


    for(i=0; i<5; i++) {
        printf("a[%d] = %d\t", i, a[i]);
        printf("b[%d] = %d\t", i, b[i]);
        printf("c[%d] = %d\t", i, c[i]);
    }


    return 0;
}
