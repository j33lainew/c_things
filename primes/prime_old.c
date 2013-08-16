#include<stdio.h>
main(){int m=200,i,j,t,p,g[m];t=m++/2;j=1;while(j<t){p=2*j+1;for(i=j+p;i<t;i+=p)g[i]=1;j++;while(g[j]!=0)j++;}printf("2");for(i=1;2*i+1<m;i++)if(g[i]==0)printf(" %d",2*i+1);}	
