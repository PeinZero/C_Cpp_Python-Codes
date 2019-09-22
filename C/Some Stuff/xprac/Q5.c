#include<stdio.h>

int count5(int num){
	int temp = num ,digit=0,c=0,i,j,last;
	
	while (temp > 0){

		temp = temp/10;
		digit++;
	}
	int temp2 = digit;
//	printf("%d\n",digit);
	int arr[digit];
	temp = num;
	while ( temp > 9){
		last = temp%10;
		arr[digit-1]=last;
		digit--;
		temp = temp/10;
	}
//	printf("%d\n",digit);
//	printf("%d\n",temp);
//	getch();
	arr[digit-1]=temp;
	
	for (i =0 ; i < temp2 ; i++){
		for ( j = i+1 ; j <= i + 1 ; j++){
			if (arr[i] == 5 && arr[j] == 5){
				c = c+2;
			}
			else if ( arr[i] == 5){
				c++;
			}
//			else if ( arr[j] == 5){
//				c++;
//			}
			printf("%d %d %d\n",i,j,c);
		}
	}
	
	return c;
}


void main (){
	int num,five;
	printf("Enter A Number\n");
	scanf("%d",&num);
	five = count5(num);
	printf("The Number of 5s in this number are = %d",five);	
}
