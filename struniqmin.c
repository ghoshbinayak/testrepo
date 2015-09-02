    #include <stdio.h>
     
    int nunique(char *, int);
    int max(int, int);
    void swap(char *, char *, int);
    void permute(char *, char *, int, int, int);
    int gmax = 100;
    int main(int argc, char const *argv[])
    {
    	int N, T;
    	char a[20];
    	char b[20];
    	scanf("%d", &T);
    	while(T--){
    		scanf("%d", &N);
    		scanf("%s", a);
    		scanf("%s", b);
    		gmax = 100;
    	 	permute(a, b, 0, N-1, N);
    		printf("%d\n", gmax);
     
    	}
    	return 0;
    }
     
    int nunique(char * a, int n){
    	int iii = 0;
    	int c;
     
    	// count unique chars in a
    	int na = 0;
    	int flaga[26] = {0};
    	while(iii < n){
    		c = *a++ - 'a';
    		if(flaga[c] == 0){
    			flaga[c] = 1;
    			na++;
    		}
    		iii++;
    	}
    	return na;
    }
     
    int max(int a, int b){
    	return (a>b)?a:b;
    }
     
    void swap(char a[], char b[], int i){
    	char temp = b[i];
    	b[i] = a[i];
    	a[i] = temp;
    }
     
    void permute(char *a, char * b, int l, int r, int n)
    {
       int i;
       int na;
       int nb;
       int m;
       if (n == 1)
       {
       		gmax = 1;
       		return;
       }
       if (l == r){
       		return;
       }
         
       else
       {
           for (i = l; i <= r; i++)
           {
              swap(a, b, i);
              na = nunique(a, n);
              nb = nunique(b, n);
    		  if((m = max(na, nb)) < gmax){
    		  	gmax = m;
    		  }
              permute(a, b, i + 1, r, n);
              swap(a, b, i); // backtrack
              na = nunique(a, n);
              nb = nunique(b, n);
    		  if((m = max(na, nb)) < gmax){
    		  	gmax = m;
    		  }
           }
       }
    } 