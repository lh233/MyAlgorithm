#include <stdio.h>
#include <stdlib.h>

#define CIRCLEBUFFER_SIZE    8
unsigned char CircleBuffer[CIRCLEBUFFER_SIZE];

unsigned char WriteIndex = 0;
unsigned char ReadIndex = 0;
unsigned char LeftSize = 0;


//检查是否有到数组末尾了
unsigned char Check_CircleBuffer(unsigned char i)
{
    return(i + 1) ==  CIRCLEBUFFER_SIZE?0:i+1;
}

//从环形数组里读取数据
unsigned char Read_CircleBuffer_Data(void)
{
    unsigned char Pos;
    if(LeftSize > 0)
    {
        Pos = ReadIndex;
        ReadIndex = Check_CircleBuffer(ReadIndex);
        LeftSize--;
        return CircleBuffer[Pos];
    }
    return 0;
}

//往环形数组内写入数据
void Write_CircleBuffer_Data(unsigned char Data)
{
    if(LeftSize < CIRCLEBUFFER_SIZE)
    {
        CircleBuffer[WriteIndex] = Data;
        WriteIndex = Check_CircleBuffer(WriteIndex);
        LeftSize++;
    }
}

void main(void)
{
    Write_CircleBuffer_Data(1);
    Read_CircleBuffer_Data();
}
