#include <stdlib.h>
#include <stdio.h>

int array[]={23,34,12,17,204,99,16};
#define TOTAL (sizeof(array)/sizeof(array[0]))


int main() {
	unsigned int a,b,c;
	a=3;
	b=sizeof a;
	printf("%d\n",b);
	b=sizeof (a);
	printf("%d\n",b);
	int d=-1,x;
	if (d<=b-2) {
		x=array[d+1];
		printf("%d\n",x);
	}
	printf("d=%d \t b-2=%d\n",d,b-2);
	c=-1;
	printf("%u\n",c);
	c=-10;
	printf("%u\n",c);
	return 0;
}
