#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int SelectSort(){
	//给数组初始化 
	srand(time(NULL));
	int iArray[10],start=0;//start用于标记数组中无无序子集（右半区）的起始位置 
	int i,j,flag;
	printf("原始数组:\n");
	for(i=0;i<10;i++){
		iArray[i]=rand()%100+1;
		printf("%d ",iArray[i]);
	}//给数组赋值 
	printf("\n");
	
	//大循环 
	for(i=0;i<10;i++){
		flag=1;
		//小循环 
		for(j=10-1;j>=start;j--){
			if(iArray[j]<iArray[j-1]){
				int temp=iArray[j];
				iArray[j]=iArray[j-1];
				iArray[j-1]=temp;
				flag=0;
			}
		}
		start++;
		printf("第 %d 次排序:",i+1);
		for(j=0;j<10;j++){
			printf("%d ",iArray[j]);
		}
		printf("\n");
		if(flag){
			return i+1;//返回排序次数 
		}
	}
}
int main(){
	//7 选择排序 
	//SelectSort();
	printf("排序次数:%d\n",SelectSort());
	return 0;
}
