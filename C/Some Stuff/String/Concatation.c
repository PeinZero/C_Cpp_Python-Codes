#include <stdio.h>

void concat( char *s1, const char *s2 ); 

int main( void )
{
 char string1[ 80 ]; 
 char string2[ 80 ];

 printf( "Enter strings 1: " );
 scanf( "%s" , string1 );
 printf( "Enter strings 2: " );
 scanf("%s", string2);
 concat( string1, string2 );
 printf("%s", string1 );
 return 0; 
 } 


 void concat( char *s1, const char *s2 )
 {
 	while ( *s1 != '\0' ) {
 		s1++;
	}
 	for ( ; *s1 = *s2; s1++, s2++ ) {
 	} 
} 
