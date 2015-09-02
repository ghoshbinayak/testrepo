#include <stdio.h>
#include "stdlib.h"

int main(int argc, char const *argv[])
{
	char * x = (char *)calloc(10, 1);
	x[5] = 8;
	printf("%u\n", x[5]);
	return 0;
}