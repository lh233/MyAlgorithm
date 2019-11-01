#include <stdio.h>
#include <stdlib.h>

#include<stdio.h>
void Swap(int arr[], int low, int high)
{
    int temp;
    temp = arr[low];
    arr[low] = arr[high];
    arr[high] = temp;
}

int Partition(int arr[], int low, int high)
{
    int base = arr[low];
    while(low < high)
    {
        while(low < high && arr[high] >= base)
        {
            high --;
        }
        Swap(arr, low, high);
        while(low < high && arr[low] <= base)
        {
            low ++;
        }
        Swap(arr, low, high);
    }
    return low;
}

void QuickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int base = Partition(arr, low, high);
        QuickSort(arr, low, base - 1);
        QuickSort(arr, base + 1, high);
    }
}

int main()
{
    int n;

    printf("请输入要输入的个数：");
    scanf("%d\n",&n);
    int arr[n];
    int i , j;
    for(i = 0; i < n; i ++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\n");
    QuickSort(arr, 0, n-1);
    for(j = 0; j < n; j ++)
    {
        printf("%4d",arr[j]);
    }
    return 0;
}
