#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main () {
  fstream myfile ("example.txt" , ios::out);
  if (myfile.is_open())
  {
    myfile << "This is a line.\n";
    myfile << "This is another line.\n";
    myfile.close();
  }
  else cout << "Unable to open file";
  
  string line;
  myfile.open ("example.txt" , ios :: in);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    myfile.close();
  }

  else cout << "Unable to open file";
  
  return 0;
}
