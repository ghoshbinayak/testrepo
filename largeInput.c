#include "stdio.h"

int main(int argc, char const *argv[])
{
	unsigned int n, k, i, count;
	scanf("%u%u", &n, &k);
	unsigned int store[n];

	// read data into store
	i = 0;
	while(i < n){
		scanf("%u", &store[i++]);
	}

	// check if divisible
	i = count = 0;
	while(i < n){
		if (store[i++] % k == 0){
			count++;
		}
	}

	printf("%u\n", count);
	return 0;
}
