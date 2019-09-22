#include <iostream>
#include <exception>
using namespace std;

struct MyException : public exception {
   const char * what () const throw () {
      return "C++ Exception";
   }
   const int hey () const  throw() {
      return 5;
   }
};
 
int main() {
   try {
      throw exception();
   } 
   catch(MyException& e) {
      std::cout << "MyException caught" << std::endl;
      std::cout << e.hey() << std::endl;
   } 
   catch(exception& e) {
      std::cout << "MyException2 caught" << std::endl;
      std::cout << e.what() << std::endl;
   }
}
