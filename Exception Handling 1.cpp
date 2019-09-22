#include<iostream> 
using namespace std; 

int fun()
{
    throw 10;
}
 
int main()
{
    try
    {
        fun();
    }
    catch (int )
    {
        cout << "Caught";
    }
    return 0;
}
