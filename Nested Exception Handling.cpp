#include <iostream> 
using namespace std; 
  
int main() 
{ 
    try { 
        try  { 
            throw 20; 
        } 
        catch (int n) { 
        	 
			 n = n +10;
             cout << "Handle Partially "<<n<<endl; 
             throw ;   //Re-throwing an exception 
             // as there is nothing infront of throw , the n recieved by the above will be thrown as it to below catch.
        } 
    } 
    catch (int n) { 
        cout << "Handle remaining "<<n; 
    } 
    return 0; 
}
