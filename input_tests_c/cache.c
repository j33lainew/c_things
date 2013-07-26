#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>
#include <time.h>
#define size (1 << 25)
int timeval_subtract (double *result, struct timeval *x, struct timeval *y) {
	 struct timeval  result0;
  /* Perform the carry for the later subtraction by updating y. */
  if (x->tv_usec < y->tv_usec) {
    int nsec = (y->tv_usec - x->tv_usec) / 1000000 + 1;
    y->tv_usec -= 1000000 * nsec;
    y->tv_sec += nsec;
  }
  if (x->tv_usec - y->tv_usec > 1000000) {
    int nsec = (y->tv_usec - x->tv_usec) / 1000000;
    y->tv_usec += 1000000 * nsec;
    y->tv_sec -= nsec;
  }
  /* Compute the time remaining to wait.
     tv_usec is certainly positive. */
  result0.tv_sec = x->tv_sec - y->tv_sec;
  result0.tv_usec = x->tv_usec - y->tv_usec;
  *result = ((double)result0.tv_usec)/1e6 + (double)result0.tv_sec;
  /* Return 1 if result is negative. */
  return x->tv_sec < y->tv_sec;
}

int main() { 
	struct timeval tdr0, tdr1;
	int *array;
	int num_el=0;
	long int sum=0;
	int i,j;
	double restime;
	array=(int *)malloc(size*sizeof(int));
	for(j=1;j<size;j<<=1) {
		sum=0; 
		gettimeofday(&tdr0,NULL);
		for(i=0;i<size;i+=j) {
			array[i]*=1;
			sum+=array[i];
		}
		gettimeofday(&tdr1,NULL);
		timeval_subtract(&restime,&tdr1,&tdr0);
		printf("%10d\t%e\t%d\n",j,restime,sum);
		/* reset array */ 
		for(i=0;i<size;i++) {
			array[i]=1;
		}
	}	
		return 0;
}
