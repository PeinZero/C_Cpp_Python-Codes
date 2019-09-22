#include <stdio.h>
#include <string.h>

void convert(char *ptr);
void main (){
	char string[100];
	printf("Enter a String\n");
	gets(string);
	printf("String before Coversion: %s\n",string);
	convert(string);
	printf("\nString After Coversion: %s",string);
}

void convert(char *ptr){
	while (*ptr != '\0'){
		if (islower(*ptr)) { 
			*ptr = toupper(*ptr);		
		}
		++ptr;
	}
}
