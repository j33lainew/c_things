#include <stdio.h>
#include <stdlib.h>

void foo(double *a,int n){
	int i;
	for(i=0;i<n;i++) {
		*(a+i)=1.0/(i+2.0);
	}
}

void foo2(double *a,int n){
	double *b;
	b=a;
	int i;
	printf("\nInside foo2\n");
	for(i=0;i<n;i++) {
		*(b+i)=1.0/(i+2.0);
		printf("%lf ",*(b+i));
	}
	printf("\n");
}


int main() {
	int i;
	int n=10;
	double *f;
	double g[10];
	f=(double *) malloc(n*sizeof *f);
	printf("Allocate array\n");
	printf("Pointer array\n");
	for(i=0;i<n;i++) {
		*(f+i)=1.0/(i+1.0);
		printf("%lf ",*(f+i));
	}
	printf("\nArray\n");
	for(i=0;i<n;i++) {
		g[i]=*(f+i);
		printf("%lf ",g[i]);
	}
	printf("\n");
	foo(f,n);
	printf("Point array after foo\n");
	for(i=0;i<n;i++) {
		printf("%lf ",*(f+i));
	}
	foo2(g,n);
	printf("\nArray after foo2\n");
	for(i=0;i<n;i++) {
		printf("%lf ",g[i]);
	}
	foo(g,n);
	printf("\n");
	return 0;
}
