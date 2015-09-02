#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main(int argc, char const *argv[])
{
	// FILE * input = fopen("test", "r");
	int n, trail;
	long int t;
	fscanf(stdin, "%d", &n);
	while(n--){
		fscanf(stdin, "%ld", &t);
		trail = 0;
		while(t >= 5){
			t /= 5;
			trail = trail + t;
		}
		printf("%d\n", trail);
	}
	return 0;
}