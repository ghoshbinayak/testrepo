#include <stdio.h>
#include <stdlib.h>

int main()
{
	const unsigned int lim = 1000001;
	unsigned int n, i;
	scanf("%d", &n);

	// take input
	unsigned int * arr = (int *)calloc(n, sizeof(int));
	unsigned int * res = (int *)calloc(n, sizeof(int));
	i = 0;
	while(i < n){
		scanf("%d", &arr[i]);
		i++;
	}

	// counting sort
	unsigned int freq[1000001] = {0};
	i = 0;
	while(i < n){
		freq[arr[i]]++; // count the frequency
		i++;
	}

	i = 1;
	while(i < lim){
		freq[i] =freq[i] + freq[i -1]; // calculate the positions
		i++;
	}

	// create the sorted array
	i = n;
	while(i){
		i--;
		res[freq[arr[i]] - 1] = arr[i];
		freq[arr[i]]--; 
	}

	// display
	i = 0;
	while(i < n){
		printf("%d\n", res[i++]);
	}
	return 0;
}