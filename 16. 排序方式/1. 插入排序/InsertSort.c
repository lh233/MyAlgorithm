// ֱ�Ӳ�������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdio.h"
//ֱ�Ӳ�������
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
            temp = a[i];          //��һ����ʱ������һ��
                for (j = i - 1; a[j] > temp && j>=0; j--){
                    a[j + 1] = a[j];                   //���±�i�������ľ�Ҫ���ƣ���Ϊ����������ں���
                }
                a[j+1] = temp;   //������Ҫע�����j+1
        }
    }
}
