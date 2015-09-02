#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main(int argc, char const *argv[])
{
	// FILE * input = fopen("test", "r");
	int n, len;
	char t1_str[100];
	char t2_str[100];
	unsigned long int t1, t2;

	fscanf(stdin, "%d", &n);

	while(n > 0){
		fscanf(stdin, "%s", &t1_str[1]);
		len = strlen(&t1_str[1]);

		// keep a copy
		strcpy(&t2_str[0], &t1_str[1]);

		// last to first
		t1_str[0] = t1_str[len];
		t1_str[len] = '\0';
		t1 = atol(&t1_str[0]);

		// first to last
		t2_str[len] = t2_str[0];
		t2_str[len +1] = '\0';
		t2 = atol(&t2_str[1]);

		// print result
		if (t1 > t2){
			printf("%i\n", t1);
		}
		else {
			printf("%i\n", t2);
		}

		n--;
	}
	// fclose(input);
	return 0;
}