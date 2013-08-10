#include <stdio.h>
#define MAX(x,y) (x)>(y)?(x):(y)
int main(){
	int i=10,j=5,k=0;
	printf("%d %d %d\n",i,j,k);
	k=MAX(i++,++j);
	printf("%d %d %d\n",i,j,k);
	return 0;
}

/* this code demonstrates the difference between a++ and ++a

a++ does everything using a (say 10) then incrementing it by 1
++a does everything using a+1 
*/
