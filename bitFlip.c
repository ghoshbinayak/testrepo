#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(int argc, char const *argv[])
{
	// allocate memory for 10^7 bits
	char * hugeNo = (char *)calloc(10000000/8 , sizeof(char));
	FILE * input = fopen("test", "r");
	unsigned int t, n, x, y, xo, yo, iii;
	fscanf(input, "%d", &t);
	int freq[16] = {0};
	while(t--){
		fscanf(input, "%d", &n);
		memset(freq, 0, 16);
		while(n--){
			fscanf(input, "%d%d", &x, &y);
			// do the flips
			x--; y--;
			xo = (7 - (x&7));
			yo = y&7;
			x = x>>3;
			y = y>>3;
			iii = 0;
			if (x != y){
				while(xo--){
					hugeNo[x] = hugeNo[x]^(1<<iii);
					iii++;
				}
				x++;
				while(x <= y){
					hugeNo[x] = ~hugeNo[x];
					x++;
				}
				iii = 7;
				while(yo--){
					hugeNo[x] = hugeNo[x]^(1<<iii);
					iii--;
				}
			}
			else {
				iii = xo;
				while(iii >= yo){
					hugeNo[x] = hugeNo[x]^(1<<iii);
					iii--;
				}
			}
		}
		// count frequency
		iii = 10000000/8;
		while(iii--){
			freq[hugeNo[iii]&15]++;
			freq[hugeNo[iii]>>4]++;
		}
		// print frequency
		iii = 16;
		while(iii--){
			printf("%d ", freq[iii]);
		}
		puts("");

	}
	return 0;
}