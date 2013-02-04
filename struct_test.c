#include <stdlib.h>
#include <stdio.h>

struct simp_struct {
	int a;
	double b;
};

void foo(struct simp_struct aa) {
	aa.a=3;
	aa.b=1.24;
	printf("Inside foo: %d,%f\n",aa.a,aa.b);
}

void foo2(struct simp_struct *aa) {
	aa->a=7;
	aa->b=3.14;
	
	printf("Inside foo2: %d,%f\n",aa->a,aa->b);
}
int main() {
	struct simp_struct test;
	test.a=1;
	test.b=10.0;
	printf("Initial test value: %d,%f \n",test.a,test.b);
	struct simp_struct *c;
/* need to allocate this */
	c=(struct simp_struct*) malloc(sizeof *c);
	c->a=2;
	c->b=11.0;
/*	printf("%d \n",c->a);*/
/*	printf("%d \n",(*c).a);*/

	foo(test);
	printf("Outside foo: %d,%f\n",test.a,test.b);
	foo2(&test);
	printf("Outside foo2: %d,%f\n",test.a,test.b);
	return 0;
}
