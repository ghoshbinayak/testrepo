#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(int argc, char const *argv[])
{
	int size = 0;
	int * data = (int *)calloc(sizeof(int), 2);
	size = 2;
	for (int iii = 0; iii < 20; ++iii)
	{
		printf("%d\n", size);
		data = (int *)realloc(data, (sizeof(int))*size*2);
		memset(data + size, 0, (sizeof(int))*size);
		size = size*2;
	}
	int temp = 0;
	while(temp < size){
		printf("%d", data[temp++]);
	}

	return 0;
}