#include <stdio.h>
#include  <string.h>

// Question 1[A] a

//main( )
//{
//struct gospel
//{
//int num ;
//char mess1[50] ;
//char mess2[50] ;
//} m ;
//m.num = 1 ;
//strcpy ( m.mess1, "If all that you have is hammer" ) ;
//strcpy ( m.mess2, "Everything looks like a nail" ) ;
///* assume that the strucure is located at address 1004 */
//printf ( "\n%u %u %u", m.num, m.mess1, m.mess2 ) ;
//}

// Question 1[A] b

//struct gospel
//{
//int num ;
//char mess1[50] ;
//char mess2[50] ;
//} m1 = { 2, "If you are driven by success",
//"make sure that it is a quality drive"
//} ;
//main( )
//{
//struct gospel m2, m3 ;
//m2 = m1 ;
//m3 = m2 ;
//printf ( "\n%d %s %s", m1.num, m2.mess1, m3.mess2 ) ;
//}

// Question 1[B] a

//main( )
//{
//struct employee
//{
//char name[25] ;
//int age ;
//float bs ;
//} ;
//struct employee e ;
//strcpy ( e.name, "Hacker" ) ;
//e.age = 25 ;
//printf ( "\n%s %d", e.name, e.age ) ;
//}

// Question 1[B] b


//main( )
//{
//struct employee
//{
//char name[25] ;
//char language[10] ;
//} ;
//struct employee e = { "Hacker", "C" } ;
//printf ( "\n%s %s", e.name, e.language ) ;
//}

// Question 1[B] c

//struct virus
//{
//char signature[25] ;
//char status[20] ;
//int size ;
//} v[2] = {
//"Yankee Doodle", "Deadly", 1813,
//"Dark Avenger", "Killer", 1795
//} ;
//main( )
//{
//int i ;
//for ( i = 0 ; i <=1 ; i++ )
//printf ( "\n%s %s", v[i].signature, v[i].status ) ;
//}

// Question 1[B] d

//struct s
//{
//char ch ;
//int i ;
//float a ;
//} ;
//main( )
//{
//struct s var = { 'C', 100, 12.55 } ;
//f ( var ) ;
//g ( &var ) ;
//}
//
//f ( struct s v )
//{
//printf ( "\n%c %d %f", v.ch, v.i, v.a ) ;
//}
//
//g ( struct s *v )
//{
//printf ( "\n%c %d %f", v->ch, v->i, v->a ) ;
//}


// Question 1[B] e

//struct s
//{
//	int i ;
//	struct s *p ;
//
//};
//main( )
//{
//struct s var1, var2,*ptr,temp ;
//
//var1.i = 100 ;
//var2.i = 200 ;
//var1.p = &var2 ;
//var2.p = &var1 ;
//printf ( "\n%d %d", var1.p -> i, var2.p -> i ) ;
//}

// Question 1[C] d

//struct time
//{
//int hours ;
//int minutes ;
//int seconds ;
//} t={0,0,5} ;
//
//
//void main(){
//	struct time *tt ;
//	tt = &t ;
//	printf("%d\n",(*tt).seconds);
//	printf("%d",tt->seconds);
//}


//main( )
//{
//int arr[ ] = { 10, 20, 30, 45, 67, 56, 74 } ;
//int *i, *j ;
//i = &arr[1] ;
//j = &arr[4] ;
//printf ( "%d %d", j - i, *j - *i ) ;
//}

//main( )
//{
//int arr[ ] = { 10, 20, 36, 72, 45, 36 } ;
//int *j, *k ;
//j = &arr [ 4 ] ;
//k = ( arr + 4 ) ;
//if ( j == k )
//printf ( "The two pointers point to the same location" ) ;
//else
//printf ( "The two pointers do not point to the same location" ) ;
//}

//main( )
//{
//int num[ ] = { 24, 34, 12, 44, 56, 17 } ;
//int i ;
//for ( i = 0 ; i <= 5 ; i++ )
//{
//printf ( "\nelement no. %d ", i ) ;
//printf ( "address = %u", &num[i] ) ;
//}
//}

//main(){
//int s[4][2] = {
//{ 1234, 56 },
//{ 1212, 33 },
//{ 1434, 80 },
//{ 1312, 78 }
//} ;
//int i, j ;
//for ( i = 0 ; i <= 3 ; i++ )
//{
//printf ( "\n" ) ;
//for ( j = 0 ; j <= 1 ; j++ )
//printf ( "%d ", *( j + *(i + s) )) ;
//}
//}


//main (){
//int s[5][2] = {
//{ 1234, 56 },
//{ 1212, 33 },
//{ 1434, 80 },
//{ 1312, 78 }
//} ;
//int ( *p )[2] ;
//int i, j, *pint ;
//p = s ;
//for ( i = 0 ; i <= 3 ; i++ )
//{
//pint = p ;
//printf ( "\n" ) ;
//for ( j = 0 ; j <= 1 ; j++ ){
//printf ( "%d ", *(pint + j) ) ;
//p++;
//}
//}
//}

//void ArrPrintMatrix(char (*p)[7]){
//	char *temp ;
//	int i , j;
//	temp = p;
//	for ( i = 0 ; i < 9 ; i++){
//		printf("%c",*(temp + i));
//		if ((i+1)%3 == 0){
//			printf("\n");
//		}
//	}
//}
//
//void main (){
//	char name[3][7] = { "SHAHBAZ","AYAZ", "HELLO"};
//	ArrPrintMatrix(name);	
//}
	
	


//display ( int *q, int row, int col )
//{
//int i, j ;
//for ( i = 0 ; i < row ; i++ )
//{
//for ( j = 0 ; j < col ; j++ ){
//
//printf ( "%d ", * ( q + i * col + j ) ) ;
//}
//printf ( "\n" ) ;
//}
//printf ("\n" ) ;
//}
//
//show ( int ( *q )[4], int row, int col )
//{
//int i, j ;
//int *p ;
//for ( i = 0 ; i < row ; i++ )
//{
//p = q + i ;
//for ( j = 0 ; j < col ; j++ )
//printf ( "%d ", * ( p + j ) ) ;
//printf ( "\n" ) ;
//}
//printf ( "\n" ) ;
//}
//
//print ( int q[ ][4], int row, int col )
//{
//int i, j ;
//for ( i = 0 ; i < row ; i++ )
//{
//for ( j = 0 ; j < col ; j++ )
//printf ( "%d ", q[i][j] ) ;
//printf ( "\n" ) ;
//}
//printf ( "\n" ) ;
//}
//	
//main( )
//{
//int a[3][4] = {
//1, 2, 3, 4,
//5, 6, 7, 8,
//9, 0, 1, 6
//} ;
//display ( a, 3, 4 ) ;
//show ( a, 3, 4 ) ;
//print ( a, 3, 4 ) ;
//}

//main( )
//{
//static int a[ ] = { 0, 1, 2, 3, 4 } ;
//int *p[ ] = { a, a + 1, a + 2, a + 3, a + 4 } ;
//printf ( "\n%u %u %d", p, *p, * ( *p ) ) ;
//}
	
	
//main( )
//{
//int array[26], i ;
//for ( i = 0 ; i <= 25 ; i++ )
//{
//array[i] = 'A' + i ;
//printf ( "\n%d %c", array[i], array[i] ) ;
//}
//}	
	
//main( )
//{
//int size = 50, sub[size] , i ;
//for ( i = 0 ; i <= 48 ; i++ ) 
//{
//sub[i] = i ;
//printf ( "\n%d", sub[i] ) ;
//}
//}	

//main( )
//{
//int i, a = 2, b = 3 ;
//int arr[ 2 + 3 ] ;
//for ( i = 0 ; i < a+b ; i++ )
//{
//scanf ( "%d", &arr[i] ) ;
//printf ( "\n%d", arr[i] ) ;
//}
//}

//main( )
//{
//int a[5] = { 5, 1, 15, 20, 25 } ;
//int i, j, k = 1, m ;
//i = ++a[1] ;
//j = a[1]++ ;
//m = a[i++] ;
//printf ( "\n%d %d %d", i, j, m ) ;
//}

//main( )
//{
//int array[6] = { 1, 2, 3, 4, 5, 6 } ;
//int i ;
//for ( i = 0 ; i <= 5 ; i++ )
//printf ( "\n%d", array[i] ) ;
//}

//main( )
//{
//int n[3][3] = {
//2, 4, 3,
//6, 8, 5,
//3, 5, 1
//} ;
//printf ( "\n%d %d %d", *n n[3][3], n[2][2] ) ;
//}

	
//main( )
//{
//int n[3][3] = {
//2, 4, 3,
//6, 8, 5,
//3, 5, 1
//} ;
//int i, j ;
//for ( i = 0 ; i <= 2 ; i++ )
//for ( j = 0 ; j <= 2 ; j++ )
//printf ( "\n%d %d", n[i][j], *( *( n + i ) + j ) ) ;
//}	

//main( )	{
//unsigned int arr[3][3] = {
//2, 4, 6,
//9, 1, 10,
//16, 64, 5
//} ;	
//
//printf("%d", ++**arr + --arr[1][1]);
//
//}

//main (){
//	
//	static int x;
//	printf("%d",x);
//	char s[] = {"Shah Latif Town"};
//	int len = strlen(s);
//	printf("%d",len);
//
//}

//int guessme(int r , int s){
//	if (r<=0){
//		return 0;
//	}
//	else return(guessme(r-2,-1*s)+r*s);
//}
//
//void main(){
//	int r = 7 , s = 1,ans ;
//	ans = guessme(7,1);
//	printf("%d",ans);
//}	
//
//	
// Ye basically ek pointer of an array me cheezain scan aur print krwaney ke liye hai
//struct course
//{
//	int marks;
//	char subject[20];
//}*ptr; // ye abhi DMA se array banjyega agey ja ke.
//
//void main()
//
//{
//	int i, no;
//	printf("Enter the number of records.\n");
//	scanf("%d", &no);
//	
//	ptr = (struct course*) calloc(no, sizeof(struct course)); // ye lo bangya.
//	
//	for (i = 0; i<no ; i++)
//	{
//		printf("Enter the name of the subject and the marks obtained, respectively.\n");
//		scanf("%s%d", &(ptr+i)->subject, (ptr+i)->marks);
//	}
//	
//	printf("\n\nDisplay:\n");
//	
//	for (i = 0; i<no ; i++)
//	{
//		printf("%s\t%d\n", (ptr+i)->subject, (ptr+i)->marks);
//	}
//
//	for (i = 0; i<no ; i++)
//	{
//		printf("%s\t%d\n", (*(ptr+i)).subject, (*(ptr+i)).marks);
//	}
//}	
	
//int main()
//{
//	int a = 10,b=5;
//	int const * ptr = &a;
//
//
//	printf("%d", ptr);
//	return 0;
//}	
	
int main (){
	char a[] = "mahad";
	char *ptr;
	
	ptr = a;
	printf("%s",ptr);
}
	
	
	
	
	
	


