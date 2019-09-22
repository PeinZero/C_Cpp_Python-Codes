#include <stdio.h>

void mod( int n,int m){
	if (n < m){
		printf("%d\n",n);
	}
	else
	{
		n = n - m;
		mod(n,m);
	}
}

void main()
{
	int n,m;
	scanf("%d %d",&n,&m);
//	scanf("%d",&m);
	mod(n,m);
}
