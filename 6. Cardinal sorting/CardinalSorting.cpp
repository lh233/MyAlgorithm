#include<iostream>
using namespace std;
int max(int date[],int n){//�˺��������������������������м�λ
	int max=0;
	for(int i=0;i<n;i++){
		int count=1,tem=date[i];
		while(tem/10!=0){//����ÿ������λ������count����
			tem=tem/10;
			count++;
		}
		if(count>max)
			max=count;//�����λ����ֵmax
	}
	return max;
}
void basesort(int date[],int n){
	int maxx=max(date,n);//ȡ�����λ��
	int num=1;
	for(int i=0;i<maxx;i++){//λ����������ѭ������
		int count[10];//����countΪ��ͳ��ÿ��Ͱ���˼�����
		int temp[10]['n'];//temp�൱��Ͱ��ǰһ������ǵڼ������ӣ���һ��Ϊ�˱�Ƿŵĸ���
		for(int f=0;f<10;f++){//�����������ʼ��
			count[f]=0;
		}
		for(int g=0;g<10;g++){//�����������ʼ��
			for(int z=0;z<n;z++){
				temp[g][z]=0;
			}
		}
		for(int j=0;j<n;j++){
			int fg=date[j]/num;//num�Ǳ�������Ϊÿ��ѭ���Ƚϵ�λ�ǲ�ͬ��
			int k=fg%10;
			count[k]++;
			int te=count[k]-1;
			temp[k][te]=date[j];//�����ݷ�kͰ��teλ�ϴ洢
		}
		int b=0;
		for(int h=0;h<10;h++){
			if(count[h]>0){//h>0˵��hͰ�������ִ洢
				for(int v=0;v<count[h];v++){//count[h]��hͰ�Ĵ洢����
					date[b]=temp[h][v];//��Ͱ���źõ���ȫ������Ҫ��������飬������������
					b++;
				}
			}
		}
		num=num*10;
	}
}

void print(int date[],int n){//��ӡ�ź��������
	for(int i=0;i<10;i++){
		cout<<date[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int date[10]={16,21,5,49,33,456,327,56,65,234};
	basesort(date,10);
	print(date,10);
	return 0;
}

