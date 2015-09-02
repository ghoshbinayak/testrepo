#include <stdio.h>

int max(int a, int b){
	return (a>b)?a:b;
}

int main(int argc, char const *argv[])
{
	int t, n, i, j, res;
	scanf("%d", &n);

	// input array and sum array
	int input[100][100];
	int sum[100][100];
	while(n--){
		scanf("%d", &t);
		for(i = 0; i < t; ++i){
			for (j = 0; j <= i; ++j){
				scanf("%d", &input[i][j]);
			}
		}

		i--;
		j = 0;
		while(j <= i){
			sum[i][j]  = input[i][j];
			j++;
		}

		i--;
		for(; i >= 0; i--){
			for(j = 0; j <= i; j++){
				sum[i][j] = max(input[i][j] + sum[i+1][j], input[i][j] + sum[i+1][j+1]);
			}
		}

		res = input[0][0];

		for (i = 1, j=0; i < t; ++i){
			if(max(sum[i][j], sum[i][j+1]) != sum[i][j]){
				res += input[i][j+1];
				j++;
			}
			else{
				res += input[i][j];
			}
		}

		printf("%d\n", res);
	}

	return 0;
}