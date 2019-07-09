#include <stdio.h>
#include <stdlib.h>
/*
因为'1'-'0'=1 ………… '9'-'0'=9 '0'的ASCII等于48 '1'的ASCII等于49 …………

*/
int StrToInt(char *string)
{
    int number = 0;
    while(*string != 0){
        number = number*10 + *string -'0';
        ++string;
    }

    return number;
}

int main()
{
    int number = 0;
    number = StrToInt("123");
    printf("number = %d\n", number);
    return 0;
}
