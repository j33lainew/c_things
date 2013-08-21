#include <stdio.h>

typedef unsigned int uint;
//input matrices p,q overwrite p
void mat_mul(uint *p,uint *q,uint k) {
	uint a,b,c,d;
	uint e,f,g,h; 
	a=p[0];b=p[1];c=p[2];d=p[3];
	e=q[0];f=q[1];g=q[2];h=q[3];
	p[0]=(a*e+b*g)%k;
	p[1]=(a*f+b*h)%k;
	p[2]=(c*e+d*g)%k;
	p[3]=(c*f+d*h)%k;
}
		
int main() {
	uint p[4]={1,1,1,0};
	uint mat[4]={1,1,1,0};
	int i;
	
	for(i=0;i<2;i++) {
			printf("%d\t%d\n",mat[2*i],mat[2*i+1]);
	}
	
	return 0;
}
