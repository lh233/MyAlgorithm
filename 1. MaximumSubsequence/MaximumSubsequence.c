#include <stdio.h>
#include <stdlib.h>

int N, num[1024];

int main()
{
    int i=0, j=0, k=0;
    //��������
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", &num[i]);

    int ans = num[1]; //ans������������кͣ���ʼ��Ϊnum[1]�ܱ�֤���ս����ȷ

    for(i=1; i<=N; i++) {
        for(j=i; j<=N; j++) {
            int s = 0;
            for(k=i; k<=j; k++) {
                s += num[k];
            }
            if(s > ans) ans = s;
        }
    }
    printf("%d\n", ans);

    return 0;
}


/*
#include <stdio.h>

//N�����鳤�ȣ�num�Ǵ���������飬����ȫ��������Ϊ���Կ��ܴ������
int N, num[134217728];

int main()
{
    //��������
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d", &num[i]);

    num[0] = 0;
    int ans = num[1];
    for(int i = 1; i <= N; i++) {
        if(num[i - 1] > 0) num[i] += num[i - 1];
        else num[i] += 0;
        if(num[i] > ans) ans = num[i];
    }

    printf("%d\n", ans);

    return 0;
}

*/
