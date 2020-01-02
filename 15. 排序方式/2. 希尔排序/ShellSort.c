#include <stdio.h>
#include <malloc.h>

void Shell_sort(int *a, int len);   //��������

int main(void)
{
    int i;
    int len;
    int * a;
    printf("������Ҫ�ŵ����ĸ�����");
    scanf("%d",&len);
    a = (int *)malloc(len * sizeof(int)); // ��̬��������
    printf("������Ҫ�ŵ�����\n");
    for (i = 0; i < len; i++) {    //����ֵ������
        scanf("%d",&a[i]);
    }
    Shell_sort(a, len);    //����ϣ��������
    printf("ϣ���������к���Ϊ��\n");
    for (i = 0; i < len; i++) {   //�����Ľ�������
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
    int gap;  //����
    for (gap = len / 2; gap >= 1; gap /= 2) {  // ������ʼ��Ϊ���鳤�ȵ�һ�룬ÿ�α����󲽳�����
        for (i = 0 + gap; i < len; i += gap) {   //�Բ���Ϊgap��Ԫ�ؽ���ֱ�����򣬵�gapΪ1ʱ������ֱ������
            temp = a[i];  //����a[i]��ֵ
            j = i - gap;  //j��ʼ��Ϊi��ǰһ��Ԫ�أ���i���gap���ȣ�
            while (j >= 0 && a[j] > temp) {
                a[j + gap] = a[j];  //����a[i]ǰ�ұ�temp��ֵ���Ԫ������ƶ�һλ
                j -= gap;
            }
            a[j + gap] = temp;
        }
    }
}

