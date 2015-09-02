#include "largeNo.h"

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

void add_bg(bg *n, bg *m){
	int ms = m->size;
	int ns = n->size;
	bg * res = get_bg(0);
	int len = (ms>ns)?(ms +2):(ns + 1);
	if (res->len < len) {
		resize_bg(res, len);
	}

	resize_bg(n, len);
	resize_bg(m, len);

	int iii = 0, carry = 0;
	while(iii < ms || iii < ns){
		res->data[iii] =carry + m->data[iii] + n->data[iii];
		carry = res->data[iii]/10;
		res->data[iii] = res->data[iii]%10;
		iii++;
	}
	if (carry > 0){
		res->data[iii++] = carry;
	}
	res->size = iii;
	n->data = res->data;
	n->len = res->len;
	n->data = res->data;
	n->size = res->size;
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
