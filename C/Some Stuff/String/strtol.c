#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
void main (){
	char *string = "1212!415125% is a String";
	char *sptr;
	long d;
	
	d = strtol(string,&sptr,'!');
	printf("%s\n",string);
	printf("%d\n",d);
	printf("%s",sptr);
}
