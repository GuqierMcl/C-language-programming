#include<stdio.h>
#define N 1.42e8
int main(){
	int i;
	double sum=0,fn=1;
	double s;
	for(i=2;i<=64;++i){
		sum=sum+fn*2.0;
		fn=sum;
	}
	s=sum/N;
	printf("%lf",s);
	return 0;
}
