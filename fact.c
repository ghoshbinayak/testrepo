#include "stdio.h"
#include "stdlib.h"
#include "largeNo.h"

bg * fact(long);

int main(int argc, char const *argv[])
{
	FILE * input = fopen("test", "r");
	int n;
	fscanf(input, "%d", &n);
	bg * res;
	long t;
	while(n>0){
		fscanf(input, "%ld", &t);
		res = fact(t);
		display_bg(res);
		puts("");
		// trailing_zero(res);
		// trail_zeros(res);
		n--;
	}

	return 0;
}

bg * fact(long n){
	bg * res;
	bg * m;
	res = get_bg(1);
	while(n > 1){
		m = get_bg(n);
		mult_bg(res, m);
		free(m->data); free(m);
		n--;
	}
	return res;
}

