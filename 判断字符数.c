#include<stdio.h>
#include<time.h>
int main(){
	int A=0,a=0,n=0,o=0;
	printf("Please input characters:\n");
	for(;;){
		char c;
		scanf("%c",&c);
		if(c!='\n'){
			if((c>=65 && c<=90) || (c>=97 && c<=122) || (c>=48 && c<=57)){
				if(c>=65 && c<=90) A++;
				if(c>=97 && c<=122) a++;
				if(c>=48 && c<=57) n++;	
			}else{
				o++;
			}	
		}else{
			break;
		}
	}
	printf("大写字母：%d\n小写字母：%d\n数字字符：%d\n其他字符：%d\n",A,a,n,o);
	return 0;
}
