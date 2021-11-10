#include<stdio.h>
int main(){
	int n=12,i,j,sum;
	int Fn_2=1,Fn_1=1,Fn=0;
	for(i=3;i<=n;i++){
		Fn=Fn_1+Fn+2;
		Fn_2=Fn_1;
		Fn_1=Fn;
	}
	printf("\nF(%d)=%d",n,Fn);
	
	return 0;
}
