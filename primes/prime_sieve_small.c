#include<stdio.h>
main(){int m=1000000,i,j,g[1000000]={0};for(j=2;j<m;j++){if(g[j]==0)printf("%d ",j);for(i=2*j;i<m;i+=j)g[i]=1;}}


