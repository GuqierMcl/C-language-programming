/*CUIT软工214 2021081159 实验六*/
#include<stdio.h>
#include<assert.h>
#include<time.h>
#include<string.h>
#include<conio.h>
#define ESC 27
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
	
	printf("请输入fNum\n");
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
	
	printf("完数和:%d 完数个数:%d\n",sumn,n);
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
void StringStudy(){
	char cStr1[20]="OK";
	char cStr2[20]={'H','e','l','l','o',' ','t','h','e',' ','w','o','r','l','d','!'};
	char cStr3[]="Programming is interesting.";
	char *pStr1="OK!";
	char *pStr2,*pStr3;
	int i;
	
	printf("Assign a string to the array or the pointer:\n");
	//cStr1="OK";
	pStr2="ABCD!";
	puts(pStr1);
	puts(pStr2);
	
	printf("Study the address of a string const:\n");
	printf("Address of\"ABCD!\":%x\n","ABCD!");
	printf("pStr2=%x\n",pStr2);
	printf("The third char of \"ABCD!\":%c\n","ABCD!"[2]);
	
	printf("Input a string to the pointer pStr1 by calling gets():\n");
	gets(pStr1);
	puts(pStr2);
	
	printf("Input \"12345 abcde\"to the arrat cStr1 by calling gets():\n");
	gets(cStr1); //输入字符串"12345 abcde" 
	puts(cStr1);
	
	printf("Input \"ABCDEF 123456\"to the array cStr1 by calling scanf():\n");
	scanf("%s",cStr1); //输入字符串"ABCDEF 123456" 
	puts(cStr1);
	
	//fflush(stdin);
	
	pStr1=cStr1;
	printf("Using getchar() to input \"Hi,hello\"ended by ENTER:\n");
	i=0;
	pStr1[i]=getchar();//输入字符串"hi,hello!" 
	while((pStr1[i]!='\n') && (i<19)){
		i++;
		pStr1[i]=getchar();
	}
	pStr1[i]='\0';
	printf("Output the string by calling printf():%s\n",pStr1);
	
	pStr1=cStr1;
	printf("Using getche() to input\"How are you\"ended by ESC:\n");
	i=0;
	pStr1[i]=getche();//输入字符串"How are you!"+ESC
	while((pStr1[i]!=ESC) && (i<19)){
		i++;
		pStr1[i]=getche();
	} 
	//pStr1[i]='\0';
	printf("\nOutput the string by calling printf():%s\n",pStr1);
	
	printf("Display string2 and string3 by calling puts():\n");
	puts(cStr2);
	puts(cStr3);
	printf("Size of the array cStr2:%d\n",sizeof(cStr2));
	printf("Size of the array cStr3:%d\n",sizeof(cStr3));
	
	printf("Using the pointer to output the string2 by calling printf():\n");
	pStr2=cStr2;
	printf("%s",pStr2);
	
	printf("Using the pointer to output the string3 by calling putchar():\n");
	pStr3=cStr3;
	while(*pStr3){
		putchar(*pStr3);
		pStr3++;
	}
	printf("The End!\n");
}
void StringOption(){
	printf("******************\n");
	printf("*请选择功能:     *\n");
	printf("*1.字符串的连接  *\n");
	printf("*2.字符串的复制  *\n");
	printf("*3.字符串的比较  *\n");
	printf("*4.字符串的逆序  *\n");
	printf("*5.求字符串长度  *\n");
	printf("******************\n");
	int ch;
	scanf("%d",&ch);
	switch(ch){
		case 1:{
			char str1[25],str2[11];
			printf("请输入两个字符串(中间用空格隔开,每个字符串不超过10个字符)进行连接:\n");
			fflush(stdin);
			scanf("%s%s",str1,str2);
			printf("连接后字符串:\n%s\n",strcat(str1,str2));
			break;
		}
		case 2:{
			char str1[11],str2[11];
			printf("请输入一个字符串(不超过10个字符)进行复制:\n");
			fflush(stdin);
			scanf("%s",str1);
			printf("字符数组:\nstr1: %s\nstr2: %s\n",str1,strcpy(str2,str1));
			break;
		}
		case 3:{
			char str1[11],str2[11];
			printf("请输入两个字符串(中间用空格隔开,每个字符串不超过10个字符)进行比较:\n");
			fflush(stdin);
			scanf("%s%s",str1,str2);
			if(strcmp(str1,str2)>0){
				printf("str1 大于 str2\n");
			}else if(strcmp(str1,str2)<0){
				printf("str1 小于 str2\n");
			}else{
				printf("两个字符串相等\n");
			}
			break;
		}
		case 4:{
			char str1[11],str2[11]={0};
			printf("请输入一个字符串(不超过10个字符)进行逆序:\n");
			fflush(stdin);
			scanf("%s",str1);
			int n;
			n=strlen(str1);//测出str1的字符串长度
			int i,k=n/2;
			strcpy(str2,str1);
			for(i=0;i<k;i++){
				str1[i]=str1[n-i-1];//一定要-1一定要-1一定要-1!!! 例如n=3是数组长度，但是str1[3]没有字符!!!垃圾东西耽误我一个小时？ 
			}
			printf("原字符串  :%s\n逆序字符串:%s\n",str2,str1);
			break;
		}
		case 5:{
			char str1[11];
			printf("请输入一个字符串(不超过10个字符)测量长度:\n");
			fflush(stdin);
			scanf("%s",str1);
			printf("字符串长度: %d",strlen(str1));
			break;
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
				if(a[i]>=b[i]){
					sum[i]=a[i]-b[i];
				}else{
					do{//如果a<b则进入循环，当随机数a>=b时跳出循环，使出题更合理 
						a[i]=rand()%10+1;
						b[i]=rand()%10+1;
					}while(a[i]<b[i]);
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
			printf("错题数:%d\n分数:%d\n",count,(10-count)*10);
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
void menu(){
	for(;;){
		printf("\n***************************************\n");
		printf("*请选择功能:                          *\n");
		printf("*  1.研究数组变量的储存               *\n");
		printf("*  2.一维数组的定义、初始化和元素引用 *\n");
		printf("*  3.指针访问一维数组                 *\n");
		printf("*  4.找寻完数及其因子                 *\n");
		printf("*  5.数组作函数参数                   *\n");
		printf("*  6.冒泡排序算法                     *\n");
		printf("*  7.选择排序算法（选做）             *\n");
		printf("*  8.字符指针、字符数组与字符串的使用 *\n");
		printf("*  9.字符串的基本操作                 *\n");
		printf("*  10.小学生算数练习+10题连做+错题重做*\n");
		printf("*  0.退出                             *\n");
		printf("***************************************\n");
		printf("请选择：\n");
		int ch;
		scanf("%d",&ch);
		switch(ch){
			case 1:StudyMem();break;
			case 2:Six_prog1();break;
			case 3:Point_Array();break;
			case 4:PerfectNum();isPerfectNum();break;
			case 5:{
				int n,i;
				printf("请输入数组元素个数iCount:\n");
				scanf("%d",&n);
				int a[n];
				printf("请输入 %d 个元素:\n",n);
				for(i=0;i<n;i++){
					scanf("%d",&a[i]);
				}
				ReverseArray(a,n);//参数是数组是，实参应是数组名，而非数组元素 
				break;
			}
			case 6:{
				int n2,j,num;
				printf("请输入需要排序的数组个数:(冒泡排序)\n");
				scanf("%d",&n2);
				int b[n2];
				printf("请输入 %d 个元素:\n",n2);
				for(j=0;j<n2;j++){
					scanf("%d",&b[j]);
				}
				printf("交换次数:%d\n",RubbleSort(b,n2));
				break;
			}
			case 7:{
				SelectSort();
				printf("排序次数:%d\n",SelectSort());
				break;
			}
			case 8:StringStudy();break;
			case 9:StringOption();break;
			case 10:SetQuestion();break;
			case 0:{
				printf("Thanks For Your Using!\n");
				return;
			}
			default:printf("Please input correct NUMBER!\n");
		}
		system("pause");
		system("cls");
	}
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
	
	//8字符指针、字符数组与字符串的使用 
	//StringStudy();
	
	//9字符串基本操作
	//StringOption(); 
	 
	//10小学生算数练习程序 
	//SetQuestion();
	
	menu();
	return 0;
}
