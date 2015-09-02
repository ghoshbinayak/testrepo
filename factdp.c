#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct big_int {
	int * data;
	int size;
	int len;
} bg;

// array to store factorials upto 100
bg * LUT[101];

void resize_bg(bg * n, int newSize){
	if(newSize > n->len){
		n->data = (int *)realloc(n->data, (sizeof(int))*newSize);
		memset(n->data + n->len, 0, (sizeof(int))*(newSize - n->len));
		n->len = newSize; 
	}
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


void display_bg(bg * n){
	int size = n->size;
	while(size > 0){
		printf("%d", n->data[--size]);
	}
	puts("");
}

bg * mult_bg(bg *n, bg *m){
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
	return res;
}

void genfact(){
	bg * res;
	bg * m;
	bg * n;
	res = get_bg(1);
	int i = 1;
	while(i <= 100){
		m = get_bg(i);
		res = mult_bg(res, m);
		free(m->data); free(m);
		LUT[i] = res;
		i++;
	}

	LUT[0] = get_bg(1);
}

void fact(int n){
	display_bg(LUT[n]);
}

int main(int argc, char const *argv[])
{
	int n, t;
	fscanf(stdin, "%d", &n);
	genfact();
	// display_bg(LUT[1]);
	while(n--){
		fscanf(stdin, "%d", &t);
		fact(t);
	}
	return 0;
}

