#include "stdio.h"

void delete(int a [], int);
void display(int a[]);
void shout(void);

int size = 5;
int main(int argc, char const *argv[])
{
	int array[5] = {1,2,3,4,5};

	int pos;
	printf("%s\n", "enter position to delete: ");
	scanf("%d", &pos);
	delete(array, pos);
	display(array);
	return 0;
}

void delete(int array[], int pos){
	if (pos > size){
		printf("%s\n", "error: element not found!");
		return;
	}
	while(pos < size) {
		array[pos - 1] = array[pos];
		pos++;
	}
	size--;
}

void display(int array[]){
	int i = 0;
	while(i < size){
		printf("%d ", array[i++]);
	}
}

void shout(void){
	printf("%s\n", "hello");
}