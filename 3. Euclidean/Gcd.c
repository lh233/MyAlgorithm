#include <stdio.h>
#include <stdlib.h>

unsigned int Gcd(unsigned int M, unsigned int N)
{
    unsigned int Rem;

    while( N > 0 )
    {
        Rem = M % N;
        M = N;
        N = Rem;
    }
    return M;
}

int main()
{
    unsigned int ret;

    ret = Gcd(50, 15);

    printf("最大公因数是%d\n", ret);
    return 0;
}
