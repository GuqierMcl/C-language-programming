#include<stdio.h>
#include<assert.h>
#include<time.h>
void StudyMem(){
	int iArray[5],iNum;
	char iString[5],cLetter;
	double fData[5],fNum;
	int i;
	printf("请输入 5 个整数：\n");
	for(i=0;i<5;i++){
		scanf("%d",&iArray[i]);
		printf("iArray(%d)的内存%d字节,起始地址是0x%x,值%d\n",i,sizeof(iArray[i]),&iArray[i],iArray[i]);
	}
	printf("请输入 5 个字符：\n");
	scanf("%s",iString);
	for(i=0;i<5;i++){
		printf("iString(%d)的内存%d字节,起始地址是0x%x,值%c\n",i,sizeof(iString[i]),&iString[i],iString[i]);
	}
	printf("请输入 5 个浮点数：\n");
	for(i=0;i<5;i++){
		scanf("%lf",&fData[i]);
		printf("fData(%d)的内存%d字节,起始地址是0x%x,值%lf\n",i,sizeof(fData[i]),&fData[i],fData[i]);
	}
	printf("请输入iNum:\n");
	scanf("%d",&iNum);
	printf("iNum的内存%d字节,起始地址是0x%x,值%d\n",sizeof(iNum),&iNum,iNum);
	
	printf("请输入cLetter:\n");
	fflush(stdin);
	cLetter=getchar();
	printf("cLetter的内存%d字节,起始地址是0x%x,值%c\n",sizeof(cLetter),&cLetter,cLetter);
	
	printf("请输入fNum");
	scanf("%lf",&fNum);
	printf("fNum的内存%d字节,起始地址是0x%x,值%lf\n",sizeof(fNum),&fNum,fNum);
}
void Six_prog1(){
	float fn[20];
	int i,count,max,min;
	printf("输入实际数据个数（不超过20）:\n");
	scanf("%d",&count);
	assert(count<=20);//如果count<=20.则继续执行，反之终止
	printf("请输入 %d 个数据：\n",count);
	for(i=0;i<count;i++){
		scanf("%f",&fn[i]);
	}
	max=min=0;
	for(i=0;i<count;i++){
		if(fn[i]>fn[max]) max=i;
		else if(fn[i]<fn[min]) min=i;
	}
	printf("输出结果:\n");
	printf("最大值为：%.2f  其下标为：%d\n",fn[max],max);
	printf("最小值为：%.2f  其下标为：%d\n",fn[min],min);
}
void Point_Array(){
	int iArray[]={1,2,3,4,5};
	int *p=NULL;
	
	p=iArray;
	printf("%d\n",p[0]);
	printf("%d\n",*(++p));
	printf("%d\n",*(p+2));
	printf("%d\n",*(p--));
	printf("%d\n",*p++);
	printf("%d\n",*p);
	printf("%d\n",++(*p));
	printf("%d\n",*p);
}
int PerfectNum(){//完数 
	int i,j,sum,n=0,sumn=0;
	printf("输出 1000 以内的完数及其因子:\n");
	
	for(i=1;i<=1000;i++){
		sum=0;//sum用于记录因子之和，方便判断因子之和是否等于完数 
		for(j=1;j<i;j++){
			if(i%j==0) {//求因子之和
				sum+=j;
			}
		}
		if(i==sum) {//判断因子是否等于完数
			n++;//用于记录完数个数 
			sumn+=i;//用于记录完数和 
			printf("%d=",i);
			for(j=1;j<i;j++){
				if(i%j==0) {//求因子之和
					printf("%d+",j);
				}
			}
			printf("\b \n");
		}
	}
	
	printf("完数和:%d 完数个数:%d",sumn,n);
}
void isPerfectNum(){//输入一个数判断是否是完数 
	int x;
	printf("请输入需要判断（是否是完数）的数:\n");
	scanf("%d",&x);
	int i,sum=0;
	for(i=1;i<x;i++){
		if(x%i==0){
			sum+=i;
		}
	}
	if(x==sum){
		printf("%d 是完数\n",x);
		printf("%d=",x);
		for(i=1;i<x;i++){
			if(x%i==0) {//求因子之和
				printf("%d+",i);
			}
		}
		printf("\b \n");
	}else{
		printf("%d 不是完数\n",x);
	}
}
void ReverseArray(int iArray[],int iCount){//将iArray中iCount个整数逆序放置 

	int i;
	int temp[iCount];
	printf("原数组:\n");
	for(i=0;i<iCount;i++){
		temp[iCount-1-i]=iArray[i];
		printf("%d ",iArray[i]);
	}
	printf("\n逆序数组:\n");
	for(i=0;i<iCount;i++){
		iArray[i]=temp[i];
		printf("%d ",iArray[i]);
	}
	printf("\n");
}
int RubbleSort(int iSortArray[],int iSize){
	if(iSortArray==NULL){//如果是空数组则返回0 
		return 0;
	}
	int i,j,temp,flag;
	for(i=0;i<iSize-1;i++){
	//外层循环，每次循环都将一个最大值浮到最上面 
		flag=1;
		for(j=0;j<iSize-1;j++){
			if(iSortArray[j]>iSortArray[j+1]){
				temp=iSortArray[j];
				iSortArray[j]=iSortArray[j+1];
				iSortArray[j+1]=temp;
				flag=0;
				//进行一次互换以后则标记flag=0 ,
			}
		}
		
    	printf("第 %d 轮排序: ", i+1);
    	for (j = 0; j < iSize; ++j){
        	printf("%d ", iSortArray[j]);
    	}
    	printf("\n");
    	
    	if(flag){
    		return i+1;
		}//如果flag没有被更新为0，则说明已经不需要继续下一次互换了 
	}

}
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
int MathLearn_do(int a,int f,int b,int *ansp){//接收到数据后打印题目并接收 
	int ans;
	printf("出题如下:\n%d %c %d = ?\n",a,f,b);
	scanf("%d",&ans);
	*ansp=ans;
	return 0;
}
int SetQuestion(){//出题 
	srand(time(NULL));
	int a[11],f[11],b[11],sum[11];//用数组储存操作数1、2,运算符 
	int ans,*ansp;
	int i;
	ansp=&ans;
	
	/*操作数与运算符初始化*/ 
	for(i=1;i<=10;i++){
		a[i]=rand()%10+1;
		f[i]=rand()%4+1;
		b[i]=rand()%10+1;
		switch(f[i]){
			case 1:{
				f[i]='+';
				sum[i]=a[i]+b[i];
				break;
			}
			case 2:{
				f[i]='-';
				if(a>=b) sum[i]=a[i]-b[i];
				else{
					do{//如果a<b则进入循环，当随机数a>=b时跳出循环，使出题更合理 
						a[i]=rand()%10+1;
						b[i]=rand()%10+1;
					}while((a[i]-b[i])<0);
					sum[i]=a[i]-b[i];
				}
				break;
			}
			case 3:{
				f[i]='*';
				sum[i]=a[i]*b[i];
				break;
			}
			case 4:{
				f[i]='/';
				if(a[i]%b[i]==0) sum[i]=a[i]/b[i];
				else{
					do{//如果a不能被b整除则进入循环，当随机数a能被b整除时跳出循环，使出题更合理 
						a[i]=rand()%10+1;
						b[i]=rand()%10+1;
					}while(a[i]%b[i]!=0);
					sum[i]=a[i]/b[i];
				}
				break;
			}
		}
	}//将十组操作数和运算符赋值
	
	/*用循环出题，直到错题数count为0时才跳出循环，教育小学生好帮手:)*/
	int count;//统计错题数 
	int mark[11]={0};
	do{
		for(i=1;i<=10;i++){
			if(mark[i]==0){
				ans=0;
				MathLearn_do(a[i],f[i],b[i],ansp);
				if(ans==sum[i]){
					mark[i]=1;
				}else{
					mark[i]=0;
				}
			}	
		}
		count=0;
		for(i=1;i<=10;i++){
			if(mark[i]==0) count++;
		}
		if(count==0){
			printf("Right!\n");
			break;//如果正确则跳出循环，结束答题 
		}else{
			printf("错题数:%d\n",count);
			printf("Do you want to correct your answer? Y/N\n");
			int ch;
			scanf("%c",&ch);
			fflush(stdin);
			scanf("%c",&ch);
			if(ch==89 || ch==121){
				system("cls");
				continue;
			}else{
				break;
			}
		}
	}while(count!=0);
}
int main(){
	//StudyMem();
	//Six_prog1();
	//Point_Array();
	//PerfectNum();
	//isPerfectNum();
	
	//5
//	int n,i;
//	printf("请输入数组元素个数iCount:\n");
//	scanf("%d",&n);
//	int a[n];
//	printf("请输入 %d 个元素:\n",n);
//	for(i=0;i<n;i++){
//		scanf("%d",&a[i]);
//	}
//	ReverseArray(a,n);//参数是数组是，实参应是数组名，而非数组元素 
	
	//6 冒泡排序 
//	int n2,j,num;
//	printf("请输入需要排序的数组个数:(冒泡排序)\n");
//	scanf("%d",&n2);
//	int b[n2];
//	printf("请输入 %d 个元素:\n",n2);
//	for(j=0;j<n2;j++){
//		scanf("%d",&b[j]);
//	}
//	printf("交换次数:%d\n",RubbleSort(b,n2));
	
	//7 选择排序 
	//SelectSort();
	//printf("排序次数:%d\n",SelectSort());
	
	//10
	//SetQuestion();
	
	return 0;
}
