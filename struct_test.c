#include <stdlib.h>
#include <stdio.h>

struct simp_struct {
	int a;
	double b;
};

void foo(struct simp_struct aa) {
	aa.a=3;
	aa.b=1.24;
	printf("Inside foo\n");
	printf("%d \n",aa.a);
}

void foo2(struct simp_struct *aa) {
	aa->a=7;
	aa->b=3.14;
	
	printf("Inside foo2\n");
	printf("%d \n",(*aa).a);
}
int main() {
	struct simp_struct test;
	test.a=1;
	test.b=10.0;
	printf("%d \n",test.a);
	struct simp_struct *c;
	//need to allocate this
	c=(struct simp_struct*) malloc(sizeof *c);
	c->a=2;
	c->b=11.0;
	printf("%d \n",c->a);
	printf("%d \n",(*c).a);
	foo(test);
	printf("Outside foo\n");
	printf("%d \n",test.a);
	foo2(c);
	printf("Outside foo2\n");
	printf("%d \n",(*c).a);
	return 0;
}
