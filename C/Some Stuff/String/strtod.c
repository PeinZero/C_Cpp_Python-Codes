#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
void main (){
	char *string = "65.0% is a String";
	char *sptr;
	double d;
	
	d = strtod(string,&sptr);
	printf("%s\n",string);
	printf("%0.1lf\n",d);
	printf("%s",sptr);
}
