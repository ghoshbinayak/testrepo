#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct big_int {
	int * data;
	int size;
	int len;
} bg;

bg * get_bg(long);
void resize_bg(bg *, int);
void mult_bg(bg *, bg *);
void display_bg(bg *);
bg * fact(long);
void trail_zeros(bg * n);

int main(int argc, char const *argv[])
{
	// FILE * input = fopen("test", "r");
	int n;
	fscanf(stdin, "%d", &n);
	bg * res;
	long t;
	while(n>0){
		fscanf(stdin, "%ld", &t);
		res = fact(t);
		trail_zeros(res);
		n--;
	}

	return 0;
}

bg * fact(long n){
	puts("begin");
	bg * res;
	bg * m;
	res = get_bg(1);
	while(n > 1){
		m = get_bg(n);
		mult_bg(res, m);
		free(m->data); free(m);
		n--;
	}
	puts("done");
	return res;
}

bg * get_bg(long n) {
	bg * res = (bg *)calloc(sizeof(bg), 1);
	res->data = (int *)calloc(sizeof(int), 2);
	res->len = 2;
	res->size = 0;
	while(n>0){
		if (res->size >= res->len){
			resize_bg(res, (res->len)*2);
		}
		res->data[res->size++] = n%10;
		n = n/10;
	}
	return res;
}

void resize_bg(bg * n, int newSize){
	if(newSize > n->len){
		n->data = (int *)realloc(n->data, (sizeof(int))*newSize);
		memset(n->data + n->len, 0, (sizeof(int))*(newSize - n->len));
		n->len = newSize; 
	}
}

void display_bg(bg * n){
	int size = n->size;
	while(size > 0){
		printf("%d", n->data[--size]);
	}
	puts("");
}

void mult_bg(bg *n, bg *m){
	int ms = m->size;
	int ns = n->size;
	int * temp;
	bg * res = get_bg(0);
	int iii, jjj, carry;

	res->size = ms + ns - 1;
	if (res->size >= res->len){
		resize_bg(res, res->size + 1);
	}

	for (iii = 0; iii < ns; ++iii){
		carry = 0;
		for (jjj = 0; jjj < ms; ++jjj){
			res->data[iii + jjj] = res->data[iii + jjj] + carry + n->data[iii]*m->data[jjj];
			carry = res->data[iii + jjj]/10;
			res->data[iii+jjj] = res->data[iii +jjj]%10;
		}
		if (carry > 0){
			res->data[iii + jjj] = carry;
		}
	}
	if (carry > 0){
		res->size++;
	}

	free(n->data);
	n->data = res->data;
	n->size = res->size;
	n->len = res->len;
	free(res);
}

void trail_zeros(bg * n){
	int count = 0;
	int temp = n->size;
	while(n->data[count++] == 0 && count < temp);
	count--;
	printf("%d\n", count);
}
