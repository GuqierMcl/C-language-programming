#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(){
	srand(time(NULL));
	int magic=1+rand()%100,count=0;
	for(count=0;;count++){
		printf("Guess:\n");
		int guess;
		scanf("%d",&guess);
		if(guess==magic){
			printf("Right!!\n");
			break;
		}else if(guess>magic){
			printf("Too High!!\n");
			continue;
		}else{
			printf("Too Low!!\n");
			continue;
		}
	}
	printf("Count:%d",count);
	return 0;
}
