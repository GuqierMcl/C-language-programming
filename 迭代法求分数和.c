#include<stdio.h>
int main(){
	int i,j;
	double a=2,b=1,sum=0;
	for(i=1;i<=10;i++){
		int t;
		if(i%2!=0){//奇数正，偶数负 
			sum+=(a/b);
		}else{
			sum-=(a/b);
		}
		t=a;
		a=a+b;
		b=t;
	}
	printf("%lf",sum);
	return 0;
}
