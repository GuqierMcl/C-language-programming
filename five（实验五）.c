#include<stdio.h>
#include<time.h>
#include<math.h>
#define N 1005
#define EPS 1.0e-5

int dectobin(int n){//该函数用于将十进制数转化为二进制 
	int sum=0;
	int y,x=1;//y表示余数，x为叠加的系数
	while(n!=0){
		y=n%2;
		sum+=x*y;
		x*=10;
		n/=2;
	}
	return sum;
}
int Count_One_Bits(unsigned short uValue){
	int iSum=0;
	uValue=dectobin(uValue);//将输入的十进制数转化为二进制进而计算 
	while(uValue){
		if(uValue%2==1){
			iSum++;	
		}
		uValue/=10;
	}
	return iSum;
}
int Greatest_Common_Divisor(int p,int q){
	int r;
	if(p>0 && q>0){
		if(p<q){
			int mid;
			mid=p;
			p=q;
			q=mid;
		}
		while((r=p%q)!=0){
			p=q;
			q=r;
			r=p%q;
		}
		return q;
	}else{
		return -1;
	}
}
int IsPrimeNumber(int m){
	int k=(int)sqrt(m),i,flag;//flag用于标记是否为素数 ,1为TRUE，0为FALSE 
	if(m==0||i==1){
		flag=0;
	}
	for(i=2;i<=k;i++){
		if(m%i==0){
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
void TestPrime(){
	int i;
	for(i=1;i<=1000;i++){
		if(IsPrimeNumber(i)) printf("%4d是素数\n",i);
		else printf("%4d不是素数\n",i);
	} 
}
void StatisticsNum(){
	int a[11];//数组0-10一共十一个整数 
	int i,sum=0,num=0;
	printf("请输入任意10个数：\n"); 
	for(i=1;i<=10;i++){
		scanf("%d",&a[i]);
		if(a[i]>0){
			sum+=a[i];
		}
		if(a[i]%2==0){
			num++;
		}
	}
	printf("正数之和：%d 偶数个数：%d\n",sum,num);
}
void SatisticsChar(){
	char a[N];
	printf("请输入一串字符，以#结束:\n");
	int i,num=0,numa=0;
	for(i=1;;i++){
		char temp=getchar();
		if(temp!='#'){
			a[i]=temp;
			num++;
			if(temp>=97 && temp<=122) numa++;
		}else{
			break;
		}
	}
	printf("字符个数：%d 小写字母个数：%d\n",num,numa);
}
int StatisticsMax(int n){
	int i;
	int a[N];
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(i>=2){
			if(a[i-1]>a[i]){
				a[i]=a[i-1];
			}
		}
	}
	printf("最大值：%d\n",a[n]);
	return a[n];
}
void five_test5_1(){
	int a,b;
	for(a=1,b=1;a<=100;a++){
		printf("a=%d,",a);
		if(b>=20)
			break;
		if(b%3==1){
			b+=3;
			continue;
		}
		b-=5;
	}
	printf("\n");
}
void five_test5_2(){
	int m=1,n=3;
	do{
		n+=m++;//m的值先调用后自加 
		if(n%7==0)
			continue;
		else ++m;
	}while(n<15);
	printf("m=%d,n=%d\n",m,n);
}
void Apple(){
	int i=1,num=2;
	float w=0.8,mon;
	do{
		mon=num*w;
		printf("第 %d 天：%d 个苹果，%.2f 元\n",i,num,mon);
		num=num*2-1;
		i++;
	}while(num<=100);
}
void Count_e(){//EPS为10^-5 
	double e=1.0,f=0,n=1.0;
	int i,j,count=0;
	for(i=1;;i++){
		for(j=1;j<=i;j++){
			n=n/(double)(j);
		}
		count++;
		if(i>1 && f-n<=EPS){
			break;
		}
		e+=n;
		f=n;
		n=1.0;
	}
	printf("e值 %lf ,总累加项数 %d\n",e,count);
}
int SumPolynomial(int n){//约定n<10 
	int i,j;
	int t;
	int sum=0;
	for(i=1;i<=n;i++){
		t=0;//每次计算初始化 
		for(j=0;j<i;j++){//计算每一项 
			t=t*10+i;
		}
		sum+=t;
	}
	return sum;
}
void TimesTable(){
	int i,j;
	printf("九九乘法表：\n");
	for(i=1;i<=9;i++){
		for(j=1;j<=9;j++){
			if(i>=j){
				printf("  %d * %d = %-2d",i,j,i*j);
			}
		}
		printf("\n");
	}
}
int Pattern(int n){//n为图案总行数，总行数不超过40，且应为奇数 
	int i,j,k=(n-1)/2;
	if(n>0 && n<40 && (n%2!=0)){
		printf("\n");
		for(i=1;i<=n;i++){
			if(i<=k){
				if(i-1==0){
					for(j=1;j<=n-2*(i-1);j++){
						printf("*");
					}
				}else{
					for(j=1;j<=(i-1);j++){
						printf(" ");
					}
					for(j=1;j<=n-2*(i-1);j++){
						printf("*");
					}
				}
			}else{
				if(i==n){
					for(j=1;j<=n;j++){
						printf("*");
					}
				}else{
					for(j=1;j<=n-i;j++){
						printf(" ");
					}
					for(j=1;j<=n-2*(n-i);j++){
						printf("*");
					}
				}
			}
			printf("\n");
		}
		return 1;
	}else{//参数有误，返回0；否则，返回1 
		printf("错误！请输入大小为0-40的奇数");
		return 0;
	}
}
int MathLearn_PLUS(){
	srand(time(NULL));
	int a,f,fChar,b,sum;
	a=rand()%10+1;
	f=rand()%4+1;
	b=rand()%10+1;
	switch(f){
		case 1:{
			sum=a+b;
			fChar='+';
			break;
		}
		case 2:{
			sum=a-b;
			fChar='-';
			break;
		}
		case 3:{
			sum=a*b;
			fChar='*';
			break;
		}
		case 4:{
			sum=a/b;
			fChar='/';
			break;
		}
	}
	printf("请计算以下题目:\n %d %c %d = ?\n",a,fChar,b);
	int i,wron=0;
	for(i=1;i<=3;i++){
		int ans;
		scanf("%d",&ans);
		if(ans==sum){
			printf("Right!\n");
			break;
		}else if(ans!=sum && i==3){
			printf("You Have Tryed Too Much!\n");
			wron++;
		}else{
			printf("Not Correct!Try again!\n");
			wron++;
		}
	}
	return wron;//返回错题数 
}
void PerfectNum(){//完数 
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
			for(j=1;j<i;j++){
				if(i%j==0) {//求因子之和
					printf("%d+",j);
				}
			}
			printf("\b");
			printf("=%d\n",i);
		}
	}
	
	printf("完数和:%d 完数个数:%d\n",sumn,n);
}
int DaffodilNum(){
	int i;
	printf("将输出(100-999)范围的水仙花数:\n");
	for(i=100;i<=999;i++){
		int a1=i%10;
		int a2=(i/10)%10;
		int a3=i/100;
		if(a1*a1*a1+a2*a2*a2+a3*a3*a3==i){
			printf("%d = %d^3 + %d^3 + %d^3\n",i,a1,a2,a3);
		}
	}
}
void GetBall(){
	int i,j,z;
	int n=0;
	        printf("序号 红-白-黑\n");
	for(i=0;i<=3;i++){
		for(j=0;j<=3;j++){
			z=8-i-j;
			if(z<=6){
				n++;
				printf("%2d:  %d-%d-%d\n",n,i,j,z);
			}
		}
	}
	printf("共 %d 种取法\n",n);
}
void menu_1(){
	int ch;
	printf("\n***********************\n");
	printf("*请选择功能：         *\n");
	printf("*  1.统计正数和&偶数  *\n");
	printf("*  2.统计字符         *\n");
	printf("*  3.找出最大值       *\n");
	printf("***********************\n");
	printf("请选择：\n");
	scanf("%d",&ch);
	switch(ch){
		case 1:StatisticsNum();break;
		case 2:SatisticsChar();break;
		case 3:{
			int n;
			printf("请输入个数n:\n"); 
			scanf("%d",&n);
			StatisticsMax(n);
			break;
		}
	}
}
void menu(){
	for(;;){//三个表达式均为空，使for循环能无限循环，满足菜单循环要求 
		int ch;
		printf("\n***********************\n");
		printf("*请选择功能:(题号)      *\n");
		printf("*  1.求最大公约数(2)    *\n");
		printf("*  2.判断素数(3)        *\n");
		printf("*  3.循环统计(4)->      *\n");
		printf("*  4.苹果购买方案(6)    *\n");
		printf("*  5.迭代法求e值(7)     *\n");
		printf("*  6.循环求多项式和(8)  *\n");
		printf("*  7.打印乘法表(9)      *\n");
		printf("*  8.编程图案显示(10)   *\n");
		printf("*  9.求1k内完数和(11)   *\n");
		printf("*  10.打印水仙花数(12)  *\n");
		printf("*  11.取球方案(13)      *\n");
		printf("*  12.算数练习PLUS      *\n");
		printf("*  0.退出               *\n");
		printf("*************************\n");
		printf("请选择：\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:{
				int p,q;
				printf("输入正整数 p 和 q:\n");
				scanf("%d%d",&p,&q);
				int g=Greatest_Common_Divisor(p,q);
				if(g==-1)
					{printf("请输入正整数！");
				}else{
					printf("正整数 %d 和 %d 的最大公约数为 %d\n",p,q,g);
				}
				break;
			}
			case 2:{
				int x;
				printf("请输入一个整数:\n");
				scanf("%d",&x);
				if(IsPrimeNumber(x)) printf("%d是素数\n",x);
				else printf("%d不是素数\n",x);
				break;
			}
			case 3:{
				menu_1();
				break;
			}
			case 4:Apple();break;
			case 5:Count_e();break;
			case 6:{
				int r;
				printf("请输入多项式和的个数：\n");
				scanf("%d",&r);
				printf("运算结果：\n%d\n",SumPolynomial(r));
				break;
			}
			case 7:TimesTable();break;
			case 8:{
				int y;
				printf("请输入图案总行数n：\n");
				scanf("%d",&y);
				Pattern(y);
				break;
			}
			case 9:PerfectNum();break; 
			case 10:DaffodilNum();break;
			case 11:GetBall();break;
			case 12:MathLearn_PLUS();break;
			case 0:printf("Thank You For Using!!!\n");return;
			default:printf("Inputing ERROR! Please try again!\n");
		}
		system("pause");//使程序暂停，按下Enter继续，理论上应调用库函数即#include<windows.h>
		system("cls");//清屏，理论上应调用库函数即#include<windows.h>，本程序(Devc++)未使用该头文件也能运行，原因未知 
	}
}
int main(){
//	//1
//	printf("Input uValue:\n");
//	int v;
//	scanf("%d",&v);
//	printf("%d\n",Count_One_Bits(v));
//
//	//2
//	int p,q;
//	printf("输入正整数 p 和 q:\n");
//	scanf("%d%d",&p,&q);
//	int g=Greatest_Common_Divisor(p,q);
//	if(g==-1)
//		{printf("请输入正整数！");
//	}else{
//		printf("正整数 %d 和 %d 的最大公约数为 %d\n",p,q,g);
//	}
//
//	//3
//	int x;
//	printf("请输入一个整数:\n");
//	scanf("%d",&x);
//	if(IsPrimeNumber(x)) printf("%d是素数\n",x);
//	else printf("%d不是素数\n",x);
//	//TestPrime();//用于判断1-1000的素数 
//	
//	//4
//	StatisticsNum();
//	SatisticsChar();
//	int n;
//	printf("请输入个数n:\n"); 
//	scanf("%d",&n);
//	StatisticsMax(n);
//	
//	//5
//	//five_test5_1();
//	//five_test5_2();
//	
//	//6
//	Apple();
//	
//	//7
//	Count_e();
//	
	//8
//	int r;
//	printf("请输入多项式和的个数：\n");
//	scanf("%d",&r);
//	printf("运算结果：\n%d\n",SumPolynomial(r));
//
//	//9
//	TimesTable();
//	
//	//10
//	int y;
//	printf("请输入图案总行数n：\n");
//	scanf("%d",&y);
//	Pattern(y);
	
	//11求完数 
	//PerfectNum();
	 
	//12求水仙花数 
	//DaffodilNum();
	
	//13
	//GetBall();
	
	//14
	//MathLearn_PLUS();
	
	menu();
	return 0;
}
