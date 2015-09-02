#include <stdio.h>

int lead(int a, int b){
	return (a>b)?(a-b):(b-a);
}

int main()
{
	int n, t, i;
	scanf("%d", &n);
	int scores[10000][2];
	int maxlead = -1;
	int index = 0;
	// read the inputs
	i = 0;
	while(i < n){
		scanf("%d%d", &scores[i][0], &scores[i][1]);
		i++;		
	}

	while(n--){
		if((t=lead(scores[n][0], scores[n][1])) > maxlead){
			maxlead = t;
			index = n;
		}
	}

	int winner = (scores[index][0]>scores[index][1])?1:2;
	printf("%d %d\n", winner, maxlead);
	return 0;
}