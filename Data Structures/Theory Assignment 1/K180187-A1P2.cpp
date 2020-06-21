#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
using namespace std;

int PossiblePaths(char **maze,int basePosition,int awayFromBasePos,int n, int m);

int main(){
	fstream file,file2;
	int n,m,paths;
	
	// input from file
	file.open("Q2fileIn.txt", ios :: in);	
	file>>n>>m;
	
	if ( m > 9 ){                                                     // m should be less than 10.
		cout<<"m should be less than 10.\nProgram ended."<<endl;
		file2.open("Q2fileOut.txt", ios :: out);
		file2<<"m should be less than 10.\nProgram ended.";
		file2.close();
		exit(1);
	}
	
	// creating 2D array using double pointer.
	char **maze;
	maze = new char* [n];
	
	for (int i = 0 ; i < n ; i++){
		maze[i] = new char [m];
	}
		
	// input from file
	for (int i = 0 ; i < n ; i++){
		for (int j = 0 ; j < m ; j++){	
			file>>maze[i][j];
			
			if (maze[i][j] != '0' && maze[i][j] != '1'){                                // maze can only have 0 or 1.
				cout<<"Maze should contain 0 and 1 only. Maze["<<i<<"]["<<j<<"] = "<<maze[i][j]<<"\nProgram ended."<<endl;
				file2.open("Q2fileOut.txt", ios :: out);
				file2<<"Maze should contain 0 and 1 only. Maze["<<i<<"]["<<j<<"] = "<<maze[i][j]<<"\nProgram ended.";
				file2.close();
				exit(1);
			}
		}
	}
	file.close();
	
	// storing possible paths in file.
	file2.open("Q2fileOut.txt", ios :: out);
	
	paths = PossiblePaths(maze,0,0,n,m);              // function calling.
	file2<<paths;
	cout<<paths<<endl;
	
	file2.close();
	
	return 0;
}

int PossiblePaths(char **maze,int basePosition,int awayFromBasePos, int n, int m ){		
		static int paths = 0;
		
		// when reached at exit, increment paths.
		if(basePosition== (n-1) && awayFromBasePos == (m-1) && maze[basePosition][awayFromBasePos] == '0'){
			++paths;
			return paths ;
		}		
		
		if (maze[basePosition][awayFromBasePos] == '0' && awayFromBasePos < m && basePosition < n){
			if (awayFromBasePos != (m-1)){								 // if at last column stop moving further. 								
				PossiblePaths(maze,basePosition,awayFromBasePos+1,n,m);  // move right.
			}
			if (basePosition != (n-1)){									 // if at last row stop moving further.
				PossiblePaths(maze,basePosition+1,awayFromBasePos,n,m);  // move left.
			}
			return paths;
		}
		else if (maze[basePosition][awayFromBasePos] == '1'){     // if at current position, there is a barrier move back.
			return paths;
		}
}
