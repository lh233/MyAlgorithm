#include <stdio.h>
#include <stdlib.h>

int N, num[1024];

int main()
{
    int i=0, j=0, k=0;
    //输入数据
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", &num[i]);

    int ans = num[1]; //ans保存最大子序列和，初始化为num[1]能保证最终结果正确

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

//N是数组长度，num是待计算的数组，放在全局区是因为可以开很大的数组
int N, num[134217728];

int main()
{
    //输入数据
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
