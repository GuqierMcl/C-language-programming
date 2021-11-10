#include<stdio.h>
int main(){
	int i,sum=0,fn=1;
	for(i=9;i>=1;i--){
		sum=(fn+1)*2;
		fn=sum;
	}
	
	printf("%d\n",sum);
	return 0;
}
