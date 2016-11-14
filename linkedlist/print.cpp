#include<stdio.h>

int main(){
	int x= 4,*y;
	y=&x;(*y)++;
	printf("%d",*y);
	return 0;
}
