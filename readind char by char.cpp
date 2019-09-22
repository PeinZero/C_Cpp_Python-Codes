#include <iostream>
#include <fstream>

using namespace std;

int main(){
	fstream file;
	
	
	file.open ("file.txt",ios::out);
	char ch = '1';
	file.put(ch);
	file<<2;
	file << "\niam batman"<<endl<<"doctor who";
	
	file.close();
	
	
	file.open("file.txt",ios::in);
	
	char c;
	string line;
	
	cout<<"char by char but doesnt consider space and change line\n"<<endl;
	while( file >> c){
		cout<<c<<endl;
	}
	file.clear();
	file.seekg(0, ios::beg); 
	
	cout<<"\nchar by char but consider space and change line\n"<<endl;
	while( ! file.eof()){
		file.get(c);
		cout<<c<<endl;
	}
	file.clear();
	file.seekg(0, ios::beg); 
	
	cout<<"\nline by line\n"<<endl;
	while( ! file.eof()){ 
		getline(file,line);
		cout<<line<<endl;
	}
	file.clear();
	file.seekp(14, ios::beg); 
	
	cout<<"\nword by word  ... (words seprated by space or line)\n"<<endl;
	while( ! file.eof()){
		file>>line;
		cout<<line<<endl;		
	}	
	file.clear();
	file.seekg(0, ios::beg); 
	
	streampos begin,end;

  	begin = file.tellg();
  	file.seekg (0, ios::end);
  	end = file.tellg();
  	
	file.close();
	cout<<endl<<begin<<endl<<end<<endl;
  	cout << "\nsize is: " << (end-begin);
	
}
