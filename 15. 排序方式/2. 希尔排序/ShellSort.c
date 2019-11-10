#include <stdio.h>
#include <malloc.h>

void Shell_sort(int *a, int len);   //函数声明

int main(void)
{
    int i;
    int len;
    int * a;
    printf("请输入要排的数的个数：");
    scanf("%d",&len);
    a = (int *)malloc(len * sizeof(int)); // 动态定义数组
    printf("请输入要排的数：\n");
    for (i = 0; i < len; i++) {    //数组值的输入
        scanf("%d",&a[i]);
    }
    Shell_sort(a, len);    //调用希尔排序函数
    printf("希尔升序排列后结果为：\n");
    for (i = 0; i < len; i++) {   //排序后的结果的输出
        printf("%d\t",a[i]);
    }
    printf("\n");

    return 0;
}
void Shell_sort(int *a, int len)
{
    int i;
    int j;
    int temp;
    int gap;  //步长
    for (gap = len / 2; gap >= 1; gap /= 2) {  // 步长初始化为数组长度的一半，每次遍历后步长减半
        for (i = 0 + gap; i < len; i += gap) {   //对步长为gap的元素进行直插排序，当gap为1时，就是直插排序
            temp = a[i];  //备份a[i]的值
            j = i - gap;  //j初始化为i的前一个元素（与i相差gap长度）
            while (j >= 0 && a[j] > temp) {
                a[j + gap] = a[j];  //将在a[i]前且比temp的值大的元素向后移动一位
                j -= gap;
            }
            a[j + gap] = temp;
        }
    }
}

