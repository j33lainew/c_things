#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>

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
	int n,k;
	int i;
	int sum=0;
	int count=0;
	int a;
	struct timeval tdr0, tdr1;
	double restime;
	char string[12];
	gettimeofday(&tdr0,NULL);
	for(n=0;n<1e8;n++) {
		i=(n<<3) + (n<<1);
	//	printf("10 * %d = %d\n",n,i);
	}
	gettimeofday(&tdr1,NULL);
	timeval_subtract(&restime,&tdr1,&tdr0);
	printf("%e\n",restime);
	return 0;
}
