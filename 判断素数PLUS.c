#include<stdio.h>
#include<math.h>
int JudgePrimeNum(int x){
	int k=(int)sqrt(x),i,flag;//flag用于标记是否为素数 
	if(x==0||i==1){
		flag=0;
	}
	for(i=2;i<=k;i++){
		if(x%i==0){
			flag=0; 
			break;
		}else{
			flag=1;
		}
	}
	//if(i>k) flag=1;//若x为素数，最后一次循环会将i+1后大于k 
	//else flag=0;
	return flag;
}
int JudgePrimeNum_endl(int ibegin,int iend){
	int i,sum=0;//sum用于记录已判断素数个数 
	printf("所有的素数是:\n"); 
	for(i=ibegin;i<=iend;i++){
		if(JudgePrimeNum(i)){
			if(sum%6==0) 
				printf("\n");//如果已判断素数个数能被6整除，则换行 
			printf("%5d",i);
			sum++;
		}
	}
	return sum;
}
int main(){
//	int x;
//	printf("请输入一个整数:\n");
//	scanf("%d",&x);
//	if(JudgePrimeNum(x)) printf("\n%d是素数",x);
//	else printf("\n%d不是素数",x);
	int x,y;
	printf("请输入判断素数的范围x y:\n");
	scanf("%d%d",&x,&y);
	printf("\n%d - %d 的素数个数共 %d 个\n",x,y,JudgePrimeNum_endl(x,y));
	return 0;
}
