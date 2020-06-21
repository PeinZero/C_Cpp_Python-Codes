#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main(){
	fstream file;
	int count = -1;
	
	string str;
	
	// input from file
	file.open("Q3fileIn.txt" , ios :: in);
	getline(file,str);
	file.close();
	
	for(int i = 0 ; str[i] != '\0' ;i++)
    {
    	str[i] = tolower(str[i]);                       // change string to lower case.
    }
	
	char array[str.length()];
	
	for (int i = 0 ; i < str.length() ; i++){
		array[i] = str[i];                                  // adding letter in array.
		count++;
		
		for (int j = 0 ; j < count ; j++){
			if (str[i] == array[j] && str[i] != ' '){     // if same letter found, enter -
				str[i] = '-';
				break;
			}
		}	
	}
	
	//Storing in file. 
	file.open("Q3fileOut.txt" , ios :: out);	
	cout<<str;
	file<<str;
	file.close();
	return 0;
}
