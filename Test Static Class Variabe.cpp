#include<stdio.h>
#include<iostream>
using namespace std;
class ATM
{
public:
static int balance;
};

int ATM::balance = 250;  // this cannot be done without static.

main()
{
ATM ob1,ob2,ob3;
cout<<ob1.balance++<<endl;
cout<<ob2.balance++<<endl;
cout<<ob3.balance;
}
