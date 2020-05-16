#include <stdio.h>

int n = 5;

int hasStatic(int n){
	static int x = 0;
	x += n;
	return x;
}

int zwieksz_o_2(int x){
	static int a = 2;
	a = + x;
	return a;
}

int main() {   
    int sum = 0;
    
    printf("Result of sum is %d \n ", zwieksz_o_2(3));
    printf("Result of sum is %d \n ", zwieksz_o_2(2));
	
	for(int i = 0; i < n; i++){
		sum += hasStatic(i);
	}

	printf("Result of sum is %d.\n", sum);
    
    return 0;
}
