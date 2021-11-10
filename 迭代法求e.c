#include<stdio.h>
#define EPS 1.0e-5
int main(){
	int n;//循环次数 
	int i,j;
	//printf("请输入循环次数:\n");
	//scanf("%d",&n);
	double temp=1.0;//累加项
	double e=1.0;
	 
	for(i=1;;i++){
		if(1.0/temp*(double)i-1.0/temp<=EPS && i>1) break;
		temp*=i;
		e+=1.0/temp;
		
	}
	printf("%lf\n循环次数:%d\n",e,i-1);
	return 0;
}
