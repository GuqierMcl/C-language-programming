#include<stdio.h>
#include<time.h>
#include<math.h>
#define e 2.718281828459 
void four_test1_1(){
	int i,j;
	i=j=2;
	if(i==2)
	if(j==2)
		printf("i=%d",i=i+j);
	else
		printf("i=%d",i=i-j);
}
void four_test1_2(){
	int x;
	printf("\nPlease input x:\n");
	scanf("%d",&x);
	switch(x){
		case 1:
		case 2:printf("x<3\n");break;
		case 3:printf("x=3\n");break;
		case 4:
		case 5:printf("x>3\n");break;
		default:printf("x unknown\n");
	} 
}
void four_test2_1(){
	int n1,n2,n3,max;
	srand(time(NULL));//使随机数为非伪随机 
	n1=rand();
	n2=rand();
	n3=rand();
	printf("The three unmber are :%d %d %d\n",n1,n2,n3);
	if(n1>n2){
		if(n1>n3) max=n1;
		else max=n3;
	}else{
		if(n2>n3) max=n2;
		else max=n3;
	}
	printf("The maximum is %d\n",max);
}
void four_test2_2(){
	int n1,n2,n3,max;
	srand(time(NULL));
	n1=rand();
	n2=rand();
	n3=rand();
	printf("The three unmber are :%d %d %d\n",n1,n2,n3);
	max=n1;
	if(max>n2){
		if(max<n3) max=n3;
	}else{
		max=n2;
		if(max<n3) max=n3;
	}
	printf("The maximum is %d\n",max);
}
void Feb_days(){
	int year,days;
	printf("\nPlease input the year:");
	scanf("%d",&year);
	if((year%4==0 && year%100!=0) || year%400==0){//括号用于区分运算优先级 
		days=29;
	}else{
		days=28;
	}
	printf("The days is:%d\n",days);
}
void Tax(){
	double bonus,rate,tax,profit;
	int ch;
	printf("\nPlease input the bonus:");
	scanf("%lf",&bonus);
	printf("\nPlease choose the method:");
	scanf("%d",&ch);
	switch(ch){//个别数字，如1000,不同方法的税率rate不同，题目给的范围有歧义，非算法错误 
		case 1:{
			if(bonus<500) rate=0.00;
			if(bonus>=500 && bonus<1000) rate=0.05;
			if(bonus>=1000 && bonus<2000) rate=0.08;
			if(bonus>=2000 && bonus<5000) rate=0.10;
			if(bonus>5000) rate=0.15;
			break;
		}
		case 2:{
			if(bonus>=500){
				if(bonus<5000){
					if(bonus<2000){
						if(bonus<1000) rate=0.05;
						else rate=0.08;
					}else rate=0.10;
				}else rate=0.15;
			}else rate=0.00;
			break;
		}
		case 3:{//数据范围不大于8000 
			int t=bonus/1000;
			switch(t){
				case 0:{
					if(bonus<500) rate=0.00;
					else rate=0.05;
					break;
				}
				case 1:rate=0.08;
				case 2:
				case 3:
				case 4:rate=0.10;break;
				case 5:
				case 6:
				case 7:
				case 8:rate=0.15;break;
			}
			break;
		}
	}
	tax=bonus*rate;
	profit=bonus-tax;
	printf("The result is\nbonus=%.2lf rate=%.2lf tax=%.2lf profit=%.2lf\n",bonus,rate,tax,profit);//保留两位小数 
}
void Func(){
	int x;
	double y;
	printf("\nPlease input x:");
	scanf("%d",&x);
	if(x>0){
		y=pow(e,-x);//pow(a,b)，即a的b次幂运算，需要库函数#include<math.h> 
	}else if(x==0){
		y=1;
	}else{
		y=-pow(e,x);
	}
	printf("\ny=%.10lf\n",y);
}
double Func1(int x){
	double y;
	if(x>0){
		y=pow(e,-x);
	}else if(x==0){
		y=1;
	}else{
		y=-pow(e,x);
	}
	return y;
}
void Caculator(){
	double a,b,sum;
	char f;
	printf("\n请输入四则运算表达式：\n");
	scanf("%lf%c%lf",&a,&f,&b);
	switch(f){//根据输入的运算符进行判断并且计算结果 
		case '+':{
			sum=a+b;
			break;
		}
		case '-':{
			sum=a-b;
			break;
		}
		case '*':{
			sum=a*b;
			break;
		}
		case '/':{
			if(b-0>0.005){//除数小于0.005即认为除数等于0 
				sum=a/b;
			}else{
				printf("\nThe format is wrong!!\n");
				return;
			}
			break;
		}
	}
	printf("\nThe result is:\n%.2lf\n",sum);
}
int Triangle(){//返回值：0-不能构成三角形；1-等腰；2-等边；3-直角；4-一般三角形 
	int a,b,c;
	printf("\nPlease input triangle lengths(a b c):");
	scanf("%d%d%d",&a,&b,&c);
	if(a+b>c && a+c>b && b+c>a){
		if(a==b||a==c||b==c){
			if(a==b&&b==c&&a==c){//等边三角形即为特殊的等腰三角形，如用并列if结构将出错 
				printf("\n返回2.等边三角形.\n");
				return 2; 
			}else{
				printf("\n返回1.等腰三角形.\n");
				return 1;
			}
		}else if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a){
			printf("\n返回3.直角三角形.\n");
			return 3;
		}else{
			printf("\n返回4。一般三角形.\n");
			return 4;
		}
	}else{
		printf("\nThis isnt a Triangle!!!\n");
		return 0;
	}
}
int MathLearn(){
	int a,b,x,sum,ans;
	char f;//用于输出运算字符 
	srand(time(NULL));//a+rand()%b随机数范围[a,b-1+a]闭区间或[a,b+a)  右开区间 
	a=rand()%11;
	b=rand()%11;
	x=1+rand()%4;//1-+;2--;3-*;4-/
	switch(x){//识别运算符并进行运算 
		case 1:{
			f='+';
			sum=a+b;
			break;
		}
		case 2:{
			f='-';
			if(a>=b) sum=a-b;
			else{
				printf("ERROR!!!Give up the problem!\n");
				return 0;
			}
			break;
		}
		case 3:{
			f='*';
			sum=a*b;
			break;
		}
		case 4:{
			f='/';
			if(a%b!=0){
				printf("ERROR!!!Give up the problem!\n");
				return 0;
			}
			else sum=a/b;
			break;
		}
	}
	printf("\n%d %c %d = ?\nYour Ansuer:\n",a,f,b);
	scanf("%d",&ans);
	if(ans==sum) printf("\nRight!\n");
	else printf("\nNot Correct! Try again!\n");
	printf("\nThe Standard Answer:\n%d %c %d = %d\n",a,f,b,sum);
}
void menu(){
	for(;;){//三个表达式均为空，使for循环能无限循环，满足菜单循环要求 
		int ch;
		printf("\n***********************\n");
		printf("*请选择功能：         *\n");
		printf("*  1.求二月份天数     *\n");
		printf("*  2.税款计算         *\n");
		printf("*  3.计算分段函数值   *\n");
		printf("*  4.简单计算器       *\n");
		printf("*  5.判定三角形类型   *\n");
		printf("*  6.算数练习程序     *\n");
		printf("*  0.退出             *\n");
		printf("***********************\n");
		printf("请选择：\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:Feb_days();break;
			case 2:Tax();break;
			case 3:Func();break;
			case 4:Caculator();break;
			case 5:Triangle();break;
			case 6:MathLearn();break;
			case 0:printf("Thank You For Using!!!\n");return;
			default:printf("Inputing ERROR! Please try again!\n");
		}
		system("pause");//使程序暂停，按下Enter继续，理论上应调用库函数即#include<windows.h>
		system("cls");//清屏，理论上应调用库函数即#include<windows.h>，本程序(Devc++)未使用该头文件也能运行，原因未知 
	}
}
int main(){
	//four_test1_1();
	//four_test1_2();
	//four_test2_1();
	//four_test2_2();
	
	/*Func1函数在main里的调用*/ 
//	int x;
//	printf("\nPlease input x:");
//	scanf("%d",&x);
//	printf("\ny=%.10lf",Func1(x));
	
	//printf("\n返回值=%d",Triangle());
	
	//MathLearn();
	//Caculator();
	
	menu();
	
	return 0;
}
