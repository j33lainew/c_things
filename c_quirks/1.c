#include <stdio.h>
int main() {
	char i=0;
	for(;i>=0;i++) 
	printf("%d\n",i);
	unsigned char j=0;
	for(;j>=0;j++) 
	printf("%d\n",j);
	return 0;
}

/* This program will print -128 using gcc.
Why? Well the for loop (initialised at i=0) will go until it reaches the largest possible positive value 
that char holds. The C standard does not specify whether or not char is signed or not!!! So It could be many
values. If signed, it will be -128 since 2^7. If unsigned, it will never end because i>=0 always! However if you
did add in another condition it would be 255 */
