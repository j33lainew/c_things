/* a simple sieve method for finding all the primes below a certain number 
It is quite fast up to about 10^7
*/
#include <stdio.h>
#include <stdlib.h>
int *new_sieve(int max_int,int *np) {
	int size;
	int *grid, *ngrid;
	int i,j,prime;
	// 2 is the first prime
	int tot_prime=1;
	//immediately remove all even numbers
	if( max_int %2 ==0) { size=max_int/2; }
	else { size=(max_int+1)/2;}
	//if grid[i]=0 after sieve it is prime
	grid=(int *)malloc(size*sizeof(int));
	//note that i=0 corresponds to 2
	//remove all multiples of prime
	// 1  2  3  4  5  6  7  8  9  10
	// 3  5  7  9 11 13 15 17 19 21
	// e.g. starting at j=1 (i.e. 3) remove
	// every third entry
	// in general starting at j, remove every 2j+1 entry
	j=1;
	while(j<size) {
		prime=2*j+1;
		for(i=j+prime;i<size;i+=prime) {
			grid[i]=1;
		}
		j++;
		while(grid[j]!=0) j++;
		tot_prime++;
	}
	*np=tot_prime;	
	ngrid=(int *)malloc(tot_prime*sizeof(int));
	i=1;
	ngrid[0]=2;
	for(j=1;j<size;j++) {
		if(grid[j]==0) {
			ngrid[i]=2*j+1;
			i++;
		}
	} 
	return ngrid;
}
int main() {

	int n0=0,nmax=1000000;
	int i=0;
	int *prime_sieve;
	prime_sieve=new_sieve(nmax,&n0);
	//printf("There are %d primes below %d\n",n0,nmax);
	for(i=0;i<n0;i++) printf("%d ",prime_sieve[i]);
	//printf("\n");	
	return 0;
}
