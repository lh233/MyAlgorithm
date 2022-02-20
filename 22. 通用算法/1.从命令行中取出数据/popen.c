#include<stdio.h> 
#include<unistd.h> 
#include<string.h>   
int main() 
{ 
	FILE *fp=NULL;
	FILE *fh=NULL;
	char buff[128]={0};
	
	memset(buff,0,sizeof(buff));
	
	fp=popen("ls -l","r");//将命令ls-l 同过管道读到fp 
	fh=fopen("shell.c","w+");// 创建一个可写的文件 
	
	fread(buff,1,127,fp);//将fp的数据流读到buff中 
	fwrite(buff,1,127,fh);//将buff的数据写入fh指向的文件中   

	pclose(fp);
	fclose(fh);   
	return 0;   
} 