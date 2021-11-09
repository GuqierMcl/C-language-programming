#include<stdio.h>
int ex=0;//该变量即exit，用于标记是否选择退出 ，1为真，2为假 
void prog1(){
	srand(time(NULL));
	printf("\n%d",rand());
}
void prog2(){
	printf("\n   *   ");
	printf("\n  * *  ");
	printf("\n *   * ");
	printf("\n*     *");
	printf("\n *   * ");
	printf("\n  * *  ");
	printf("\n   *   ");
}
void prog3(){
	printf("\nHello World!");
}
void swit(int ch){
	switch(ch){
		case 1:prog1();break;
		case 2:prog2();break;
		case 3:prog3();break;
		case 0:ex=1;break;
		default:printf("\nInputing ERROR!");
	}
}
void init(){
	int ch;
	printf("\n\n*******************");
	printf("\n1.输出一个随机数   ");
	printf("\n2.输出一个菱形     ");
	printf("\n3.输出'Hello World'");
	printf("\n0.退出             ");	
	printf("\n*******************");
	printf("\nPlease input ur choice:\n");
	scanf("%d",&ch);
	swit(ch);
}
int main(){
	for(;;){
		init();
		if(ex==1){
			break;
		}
	}
	/*while循环 
	while(1){
		init();
		if(ex==1){
			break;
		}
	}
	*//*do while循环 
	do{
		init();
		if(ex==1){
			break;
		}
	}while(1);
	*/
	return 0;
}
