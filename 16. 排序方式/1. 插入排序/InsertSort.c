// 直接插入排序.cpp : 定义控制台应用程序的入口点。
//

#include "stdio.h"
//直接插入排序
void InsertSort(int a[], int len);
 void main(){
     int i;
    int a[5] = {5,3,4,6,2};
    InsertSort(a,5);

    for (i = 0; i < 5; i++)
        printf("%d ", a[i]);
}

void InsertSort(int a[] ,int len){
    int temp,i,j;
    for (i = 1; i < len;i++)
    {
        if (a[i] < a[i - 1]){
            temp = a[i];          //用一个临时变量存一下
                for (j = i - 1; a[j] > temp && j>=0; j--){
                    a[j + 1] = a[j];                   //凡事比i这个数大的就要后移，因为大的数总是在后面
                }
                a[j+1] = temp;   //这里需要注意的是j+1
        }
    }
}
