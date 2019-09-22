#include <stdio.h>

void main (){
	char str[100];
	char *ptr = str;
	int len=0;
	
	gets(str);
	
	while (*ptr != '\0'){
		ptr++;
		len++;
	}
	printf("%d",len);
		
}
