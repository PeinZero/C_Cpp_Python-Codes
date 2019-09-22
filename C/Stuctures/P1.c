#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct XYZ{
	
	char pname[100];
	int id,quantity;
	float price;
	struct md {
		int mday;
		int mmonth;
		int myear;
	}mdate;
	struct ed {
		int eday;
		int emonth;
		int eyear;
	}edate;
} I;

I item[100];

int c=0;

void convert(char *ptr){
	while (*ptr != '\0'){
		if (isupper(*ptr)) { 
			*ptr = tolower(*ptr);		
		}
		++ptr;
	}
}

void add(I item []);
void search(I item[]) ;
void deleteitem(I item[]) ;
void dispayall(I item[]) ;
void update(I item[]) ;



void main (){
	int choice;
	
	do{
		system("cls");
		printf("1 - Add Product\n");
		printf("2 - Search Product\n");
		printf("3 - Delete Product\n");
		printf("4 - Display All Products\n");
		printf("5 - Update Products\n");
		printf("6 - Exit\n");
		scanf("%d",&choice);
		
		switch(choice){
			case 1 : add(item) ; break;
			case 2 : search(item) ; break;
			case 3 : deleteitem(item) ; break;
			case 4 : dispayall(item) ; break;
			case 5 : update(item) ; break;
			case 6 : system("cls") ; exit(1);
			default : printf("Wrong Choice ! Please Enter Again"); getch() ; system("cls") ;
	}
	}while (choice != 5);
	
}

void add(I item []){
	char choice;
	do{
	
		system("cls");
		printf("Enter ID of Product: ");
		scanf("%d",&item[c].id);
		printf("Enter Name of Product: ");
		fflush(stdin);
		gets(item[c].pname);
		convert(item[c].pname);
		printf("Enter Quantity of Product: ");
		scanf("%d",&item[c].quantity);
		printf("Enter Price of Product: ");
		scanf("%f",&item[c].price);
		printf("Enter Manufacturing Date (DD/MM/YEAR)\n");
		printf("Enter Day(1-31): ");
		scanf("%d",&item[c].mdate.mday);
		printf("nEnter Month(1-12): ");
		scanf("%d",&item[c].mdate.mmonth);
		printf("Enter Year: ");
		scanf("%d",&item[c].mdate.myear);
		printf("\nEnter Expiration Date (DD/MM/YEAR)\n");
		printf("Enter Day(1-31): ");
		scanf("%d",&item[c].edate.eday);
		printf("Enter Month(1-12): ");
		scanf("%d",&item[c].edate.emonth);
		printf("Enter Year: ");
		scanf("%d",&item[c].edate.eyear);
		fflush(stdin);
		c++;
		printf("\n\n\nPress y if you want to add another item, else press n: ");
		scanf(" %c",&choice);
		tolower(choice);
	}while (choice != 'n');	
	main();
}

void search(I item[]){
	int i,flag =0;;
	char search[100],choice;
	
	do {
		printf("Enter Product name to Search: ");
		fflush(stdin);
		gets(search);
		convert(search);
			
		
		for (i =0 ; i < c ; i++){
			
			if (strcmp(item[i].pname,search) == 0){
				system("cls");
				printf("Product ID = %d\n",item[i].id);
				printf("Product Name = %s\n",item[i].pname);
				printf("Product Quantity = %d\n",item[i].quantity);
				printf("Product Manufacture Date = %d/%d/%d\n",item[i].mdate.mday,item[i].mdate.mmonth,item[i].mdate.myear);
				printf("Product Expiration Date = %d/%d/%d\n",item[i].edate.eday,item[i].edate.emonth,item[i].edate.eyear);
				printf("Product Price = %f\n",item[i].price);
				flag = 0;
				break;
			}
			else flag = 1;
			
		}
		if (flag == 1){
			printf("Product NOT FOUND");
			getch();
		}
		printf("\n\n\nPress y if you want to search again, else press n: ");
		scanf(" %c",&choice);
		tolower(choice);
	}while (choice != 'n');
}

void deleteitem(I item[]) {
	int i,flag =0;;
	char search[100],choice;
	
	do {
		printf("Enter Product name to Delete: ");
		fflush(stdin);
		gets(search);
		convert(search);
		
		
		for (i =0 ; i < c ; i++){
			
			if (strcmp(item[i].pname,search) == 0){
				item[i].id = 0;
				strcpy(item[i].pname,"deleted");
				item[i].quantity = 0;
				item[i].price = 0;
				item[i].mdate.mday = 0;
				item[i].mdate.mmonth = 0;
				item[i].mdate.myear = 0;
				item[i].edate.eday = 0;
				item[i].edate.emonth = 0;
				item[i].edate.eyear = 0;
				flag = 0;
				break;
			}
			else flag = 1;
			
		}
		if (flag == 1){
			printf("Product NOT FOUND");
			getch();
		}
		else printf("Product Deleted\n");
		printf("\nPress y if you want to delete another item, else press n: ");
		scanf(" %c",&choice);
		tolower(choice);
	}while (choice != 'n');
	
}

void dispayall(I item[]){
	int i;
	system("cls");
	for ( i = 0 ; i < c ; i++){
	 	if (item[i].pname == "deleted"){
	 		printf("%s\n",item[i].pname);
	 		continue;
		}
		
		printf("Product ID = %d\n",item[i].id);
		printf("Product Name = %s\n",item[i].pname);
		printf("Product Quantity = %d\n",item[i].quantity);
		printf("Product Manufacture Date = %d/%d/%d\n",item[i].mdate.mday,item[i].mdate.mmonth,item[i].mdate.myear);
		printf("Product Expiration Date = %d/%d/%d\n",item[i].edate.eday,item[i].edate.emonth,item[i].edate.eyear);
		printf("Product Price = %f\n",item[i].price);
		printf("\n");
	}
	
	getch();
}

void update(I item[]) {
	int i,flag =0;;
	char search[100],choice;
	
	do {
		system("cls");fflush(stdin);
		printf("Enter Product name to update: ");
		fflush(stdin);
		gets(search);
		convert(search);
			
		
		for (i =0 ; i < c ; i++){
			
			if (strcmp(item[i].pname,search) == 0){
				system("cls");
				printf("which attribute you want to update ?\n");
				printf("1- ID\n2- Product Name\n3-Product Quantity\n4-Product Manufacture Date\n5-Product Expiration Date\n6-Product Price\n");
				scanf("%d",&choice);
				switch(choice){
					case 1 : 
						printf("Enter New ID of Product: ");
						scanf("%d",&item[i].id);
					break;
					case 2 : 
						printf("Enter New Name of Product: ");
						fflush(stdin);
						gets(item[i].pname);
						convert(item[i].pname);
					break;
					case 3 : 
						printf("Enter New Quantity of Product: ");
						scanf("%d",&item[i].quantity);
					break;
					case 4 : 
						printf("Enter New Manufacturing Date (DD/MM/YEAR)\n");
						printf("Enter Day(1-31): ");
						scanf("%d",&item[i].mdate.mday);
						printf("nEnter Month(1-12): ");
						scanf("%d",&item[i].mdate.mmonth);
						printf("Enter Year: ");
						scanf("%d",&item[i].mdate.myear);
					break;
					case 5 : 
						printf("\nEnter Expiration Date (DD/MM/YEAR)\n");
						printf("Enter Day(1-31): ");
						scanf("%d",&item[i].edate.eday);
						printf("Enter Month(1-12): ");
						scanf("%d",&item[i].edate.emonth);
						printf("Enter Year: ");
						scanf("%d",&item[i].edate.eyear);
					
					break;
					case 6 : 
						printf("Enter New Price of Product: ");
						scanf("%f",&item[i].price);
					break;
					default:
						printf("You have entered wrong choice.\nPlease enter again."); getch();

				}
				flag = 0;
				break;
			}
			else flag = 1;
			
		}
		if (flag == 1){
			printf("Product NOT FOUND");
			getch();
		}
		printf("\n\n\nPress y if you want to update another item, else press n: ");
		scanf(" %c",&choice);
		tolower(choice);
	}while (choice != 'n');
}
