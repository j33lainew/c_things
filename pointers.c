#include <stdio.h>

int main() {
	int a=10;
	int *b=&a;
	int *c;
	c=&a;
	printf("a=%d\n",a);
	printf("b=%d\n",*b);
	printf("c=%d\n",*c);
	return 0;
}

/* This little program demonstrates why I think C syntax is horrible. 

int *b=&a

define b to a pointer of type and set it equal to the address of a

int *c;
c=&a
does the same thing!!!!!!!!!!

But, more importantly *c deferences the point in the printf statement.

This is an annoying ambiguity because int *c and printf("%d\n",*c) the *c means 
two different things

I personally think the operation of assigning a pointer and dereferencing should be different. Just as an example

int !p=&a
printf("%d\n",*p);
int !c;
c=&a
printf("%d\n",*c);

removes some of the ambiguity. Here !c DEFINES a pointer type while *c DEREFERENCES it.

*/
