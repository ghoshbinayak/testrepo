#include <stdlib.h>
#include <stdio.h>

int compar(const void * a, const void * b){
	int *x;
	int *y;
	x = (int *)a;
	y = (int *)b;
	if((*x) == (*y)){
		return 0;
	}

	return ((*x)>(*y))?1:-1;
}

int main()
{
	int n, i;
	scanf("%d", &n);

	// take input
	int arr[n];
	i = 0;
	while(i < n){
		scanf("%d", &arr[i++]);
	}

	// sort
	qsort(&arr[0], n, sizeof(int), &compar);

	// display
	i = 0;
	while(i < n){
		printf("%d\n", arr[i++]);
	}
	return 0;
}