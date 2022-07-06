#include <stdio.h>

int main()
{
	int N;       // VALUE FOR NUMBER
	float sum;   // VALUE FOR DECIMAL(todsaniyom)
	char x;     // VALUE FOR ALPHABET 
		printf("Please enter value: ");
		scanf("%d  %f  %c", &N , &sum , &x);
		printf(" %d  %5.2f  %c", N , sum , x); // 5 main 2 decimal
		return 0 ; // endfunction
}
