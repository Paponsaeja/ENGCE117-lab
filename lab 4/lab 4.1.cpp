#include <stdio.h>

void go( int **p, int *z ) {
	*p = z;
	printf("%d %p %p\n", **p, *p, p);
}

int main() {
	int b = 10;
	int c = 20;
	int *a;
	go(&a, &b);
	printf("%d %p %p\n", *a, a, &a);
	printf("--------------\n");
	go(&a, &c);
	printf("%d %p %p\n", *a, a, &a);
	return 0;
}
