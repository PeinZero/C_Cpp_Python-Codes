#include <stdio.h>
#include  <string.h>


void main (){
	char *ptr,noun[100];
	int len,i;
	
	printf("Enter a Noun: ");
	gets(noun);
	len = strlen(noun);

	char  temp[len-1];
	
	if (noun[len -2] == 'f' && noun[len -1] == 'e'){
		char  temp[len+1];
		ptr = "ves";
		for ( i = 0 ; i < len -2 ; i++ ){
			temp[i] = noun[i];
		}
        strcat(temp,ptr);
		printf("%s", temp );
	}
	else if (noun[len -1] == 'f'){
		char  temp[len+2];
		ptr = "ves";
		for ( i = 0 ; i < len -1 ; i++ ){
			temp[i] = noun[i];
		}
        strcat(temp,ptr);
		printf("%s", temp );
	}
	else if (noun[len -1] == 'o' ||  noun[len -1] == 's' ||  noun[len -1] == 'x' || noun[len -1] == 'z'  ){
		char  temp[len+1];
		ptr = "es";
		for ( i = 0 ; i < len -1 ; i++ ){
			temp[i] = noun[i];
		}
        strcat(temp,ptr);
		printf("%s", temp );
	}
	else if (  (noun[len -2] == 'c' && noun[len -1] == 'h') ||  (noun[len -2] == 's' && noun[len -1] == 'h')  ){
		char  temp[len];
		ptr = "es";
		for ( i = 0 ; i < len -2 ; i++ ){
			temp[i] = noun[i];
		}
        strcat(temp,ptr);
		printf("%s", temp );
		
	}
	else {
		noun[len] = 's';
		for ( i = 0 ; i < len+1 ; i++ ){
			temp[i] = noun[i];
		}
		printf("%s", temp );
	}
}



