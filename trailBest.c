#include <stdio.h>
#include <stdlib.h>
 
int z(int n)
{
    int r = 0, num = n; 
	while (num >= 5)
	{
		num = num / 5;
		r += num;
	}
	return r;
}
 
int readuint()
{
	int n = 0;
	char c = fgetc(stdin);
	do {
		n = n * 10 + (c - '0');
	} while ((c = fgetc(stdin)) != '\n');
 
	return n;
}
 
void readuints(int* nArray, int nCount, int nElemStrMaxLen)
{
	int len = (nElemStrMaxLen + 1) * nCount;
	char* str = (char*) malloc(len);
	char* c = str;
 
	register int n, z;
 
	fread(str, 1, len, stdin);
	int i;
	for (i = 0; i < nCount; i++) {
		n = 0;
		do {
			n = n * 10 + (*c - '0');
		} while (*(++c) != '\n');
		c++;
 
		z = 0;
		while (n >= 5) {
			n = (n << 1) / 10;
			z += n;
		}
 
		nArray[i] = z;
	}
 
	free(str);
}
 
void writeuints(int* nArray, int nCount, int nElemStrMaxLen)
{
	int len = (nElemStrMaxLen + 1) * nCount;
	char* str = (char*) malloc(len);
	char* c = str + len;
 
	for (nCount--; nCount >= 0; nCount--) {
		int n = nArray[nCount];
		*(--c) = '\n';
 
		do {
			*(--c) = n % 10 + '0';
			n /= 10;
		} while (n > 0);
	}
 
	fwrite(c, 1, str + len - c, stdout);
	free(str);
}
 
int main()
{
	int t = readuint();
	int* nArray = (int*) calloc(t, sizeof(int));
	readuints(nArray, t, 9);
	writeuints(nArray, t, 9);
 
	free(nArray);
	return 0;
}  