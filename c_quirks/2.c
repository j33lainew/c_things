#include <stdio.h>
#define STYLE1 char
int main() {
	typedef char STYLE2;
	STYLE1 x;
	STYLE2 y;
	x=255;
	y=255;
	printf("%d %d\n",x,y);
	unsigned char a,b;
	a=255;b=255;
	printf("%d %d\n",a,b);
	return 0; 
}

/* this will print out -1 -1 using gcc. Again if it UNSIGNED it will print out 255 255. Why?
Remember it loops around at 127 */
