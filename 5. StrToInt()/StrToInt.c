#include <stdio.h>
#include <stdlib.h>
/*
��Ϊ'1'-'0'=1 �������� '9'-'0'=9 '0'��ASCII����48 '1'��ASCII����49 ��������

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
