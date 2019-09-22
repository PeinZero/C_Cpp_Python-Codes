#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
	char *noun;
	int strl, i;
	char string1[]="ves";
	char string2[]="es";
	char string3[]="s";
	char noun1[100];
	char newnoun[100];
	
	
	noun= (char *) malloc(1*sizeof(char));
	
	printf("Enter the singular noun: ");
	gets(noun);
	
	strl= strlen(noun);
	
	if (noun[strl-1]=='f')
	{
		for (i=0 ; i<strl-1 ; i++)
		{
			noun1[i] = noun[i];
			noun1 = (char*)realloc(noun1, strl+2);
				
		}
		printf("%s", strcat(noun1, string1));
	}
	
	else if (noun[strl-1]=='e' && noun[strl-2]=='f')
	{
		for (i=0 ; i<strl-2 ; i++)
		{
			noun = (char*)realloc(noun, strl+1);
			noun1[i] = noun[i];	
		}
		printf("%s", strcat(noun1, string1));
	}
	
	else if ((noun[strl-1]=='o') || (noun[strl-1]=='h' && noun[strl-2]=='c') || (noun[strl-1]=='s') || (noun[strl-1]=='h' && noun[strl-2]=='s') || (noun[strl-1]=='x') || (noun[strl-1]=='z'))
	{
		noun = (char*)realloc(noun, strl+1);
		printf("%s", strcat(noun, string2));
	}
	
	else
	{
		printf("%s", strcat(noun, string3));
	}
}
