#include <string>
#include <iostream> 
#include <fstream> 

using namespace std; 
  

class Contestant { 
public: 

    string Name; 
    int Age, Ratings; 
  

    int input(); 
  
    int output_highest_rated(); 
}; 
  

int Contestant::input() 
{ 
    fstream file_obj; 
  

    file_obj.open("Input.txt", ios::out); 
  

    Contestant obj; 
  
    string str = "Micheal"; 
    int age = 18 ;
	int ratings = 2500; 
  
    obj.Name = str; 
    obj.Age = age; 
    obj.Ratings = ratings; 
  
    // Writing the object's data in file 
    file_obj.write((char*)&obj, sizeof(obj)); 
  
    fflush(stdin);
	str = "Terry"; 
    age = 21; 
    ratings = 3200; 
  
    obj.Name = str; 
    obj.Age = age; 
    obj.Ratings = ratings; 
  
    // Writing the object's data in file 
    file_obj.write((char*)&obj, sizeof(obj)); 
  
    return 0; 
} 
  

int Contestant::output_highest_rated() 
{ 
    // Object to read from file 
    fstream file_obj; 
  
    // Opening file in input mode 
    file_obj.open("Input.txt", ios::in);
  
    // Object of class contestant to input data in file 
    Contestant obj; 
  
    // Reading from file into object "obj" 
    file_obj.read((char*)&obj, sizeof(obj)); 
  
    // max to store maximum ratings 
    int max = 0; 
  
    // Highest_rated stores the name of highest rated contestant 
    string Highest_rated; 
  
    // Checking till we have the feed 
    while (!file_obj.eof()) { 
        // Assigning max ratings 
        if (obj.Ratings > max) { 
            max = obj.Ratings; 
            Highest_rated = obj.Name; 
        } 
  
        // Checking further 
        file_obj.read((char*)&obj, sizeof(obj)); 
    } 
  
    // Output is the highest rated contestant 
    cout << Highest_rated; 
    return 0; 
} 
  
// Driver code 
int main() 
{ 
    // Creating object of the class 
    Contestant object; 
  
    // Inputting the data 
    object.input(); 
  
    // Extracting the max rated contestant 
    object.output_highest_rated(); 
  
    return 0; 
} 
