#include <stdio.h>
#include <string.h>


void permute(char *ptr,int len,int c){
	int i;
	char temp;
	
	if (c == len -1){
		printf("%s\n",ptr);
	}
	else
	{
		for(i=c; i < len ; i++){
			temp = ptr[c];
			ptr[c] = ptr[i];
			ptr[i] = temp;
			permute(ptr,len,c+1);
			temp = ptr[c];
			ptr[c] = ptr[i];
			ptr[i] = temp;
			
		}
	}
}

void main (){
	char str[100];
	int len =0 , c=0;
	
	gets(str);
	
	len = strlen(str);
	
	permute(str,len,c);
}
