#include<stdio.h>
void Pri(){
	int i,j;
	printf("   ");//用于美化输出排版 
	for(i=1;i<=9;i++){//输出表头 
		printf("%4d",i);
	}
	printf("\n**************************************\n");
	for(i=1;i<=9;i++){
		printf("%d->",i);//输出列标 
		for(j=1;j<=9;j++){
			if(j<=i) printf("%4d",i*j);//使输出的九九乘法表为下三角 
		}
		printf("\n");
	}
}
int main(){
	Pri();
	return 0;
}
