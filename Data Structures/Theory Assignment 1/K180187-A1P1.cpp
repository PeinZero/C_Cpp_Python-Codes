#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
using namespace std;

class Puzzle{
	int n, m, howManyToSearch;
	char **puzzle;                // 2d array using double pointer.
	string *toFind;				  // 1d array using pointer.
	
	public:		
		Puzzle(){
			fstream file;
		
			//input from File
			file.open("Q1fileIn.txt" , ios::in);
			file>>n>>m;
			
			// dynmaic memory allocation of 2d Array (puzzle).
			puzzle = new char* [n];
			for (int i = 0 ; i < n ; i++){
				puzzle[i] = new char [m];
			}
			
			//input from File
			for (int i = 0 ; i < n ; i++){
				fflush(stdin);
				file>>puzzle[i];
			}	
			file>>howManyToSearch;
			
			toFind = new string[howManyToSearch] ;       // Array[toFind] to store all words that are to be searched.
			
			for ( int i = 0 ; i < howManyToSearch ; i++){
				file>>toFind[i];
			}
		}		
		
		void CallPuzzleSolver();
		int* PuzzleSolver(char **puzzle,string toFind);
};

void Puzzle :: CallPuzzleSolver(){
	fstream file;                             	
	file.open("Q1fileOut.txt" , ios::out);
	
	for(int i = 0 ; i < howManyToSearch ; i++ ) {
		
		// safe check to avoid function call if searched word lenght is greater than row/column.
		
		if (toFind[i].length() > n || toFind[i].length() > m){  
			file<<"n"<<endl;                                           
			continue;
		}
		
		int *array = PuzzleSolver(puzzle,toFind[i]);           // function calling.
		
		// storing starting position in file 
		if ( array[0] == 110 ){
			file<<"n"<<endl; 
		}
		else file<<array[0]<<array[1]<<endl;
	}	
	file.close();
}

int* Puzzle ::  PuzzleSolver(char **puzzle,string wordToBeSearched){	
	int x,y;
	int strlen = wordToBeSearched.length() ;
	bool searchFailed = true ;
	string searchingWord;
	
	// 1D array using pointer for storing starting positions (x,y).
	int *startingPosition;
	startingPosition = new int[2];	
	
	for ( int i = 0 ; i < n ; i++){
		
		for ( int j = 0 ; j < m ; j++){
			
			// finding first letter of the searched word.
			if (puzzle[i][j] == wordToBeSearched[0]){  
				
				x = i;
				y = j;
	
				// checking right from starting position (x,y).
				if (  ( y+strlen <= m ) && ( puzzle[x][y+1] == wordToBeSearched[1] /* comparing second letter */) ){

					for ( int i = y ; i < ( y + strlen ) ; i++){  
						searchingWord = searchingWord+ puzzle[x][i];  // concating a string to compare with searched word
					}
					
					if (searchingWord == wordToBeSearched){
						startingPosition[0] = x;            //storing x and y at index 0 and 1 of array respectively.
						startingPosition[1] = y;
						searchFailed = false;
						return startingPosition;
					}
					searchingWord = "\0";
				}	
				
				// checking left from starting position(x,y).
				if ( ( y - strlen >= -1 )  && ( puzzle[x][y-1] == wordToBeSearched[1] ) ){

					for ( int i = y ; i > ( y - strlen ) ; i--){
						searchingWord = searchingWord+ puzzle[x][i];
					}
					
					if (searchingWord == wordToBeSearched){
						startingPosition[0] = x;
						startingPosition[1] = y;
						searchFailed = false;
						return startingPosition;
					}
					searchingWord = "\0";
				}
				
				// checking down from starting position(x,y).
				if ( ( x + strlen <= n ) && ( puzzle[x+1][y] == wordToBeSearched[1] ) ){
					
					for ( int i = x ; i < ( x + strlen ) ; i++){
						searchingWord = searchingWord+ puzzle[i][y];
					}
					
					if (searchingWord == wordToBeSearched){
						startingPosition[0] = x;
						startingPosition[1] = y;
						searchFailed = false;
						return startingPosition;
					}
					searchingWord = "\0";
				}
				
				// checking up from starting position(x,y).
				
				if ( ( x - strlen >= -1 ) && ( puzzle[x-1][y] == wordToBeSearched[1] ) ){
					
					for ( int i = x ; i > (x - strlen ) ; i--){
						searchingWord = searchingWord+ puzzle[i][y];
					}
					
					if (searchingWord == wordToBeSearched){
						startingPosition[0] = x;
						startingPosition[1] = y;
						searchFailed = false;
						return startingPosition;
					}	
					searchingWord = "\0";	
				}
			}
		}
	}
	
	// if word not found then store 'n' in array.
	if (searchFailed == true){
		startingPosition[0] = 110;       			// 110 is ascii of n.
		return startingPosition;
	}
}

int main(){
	Puzzle puzzle;	
	puzzle.CallPuzzleSolver();		
	return 0;
}
