#include <iostream>
#include <conio.h>

using namespace std;

int paths = 0;
int array[5][6] ={{0,0,0,0,0,0},
                  {0,1,1,1,1,0},
                  {0,1,1,1,1,0},
                  {0,1,0,1,1,0},
                  {0,0,0,0,0,0}};


void Path_Finder(int row_pos, int col_pos, int size_row, int size_col){

    if(row_pos == size_row && col_pos == size_col){
        paths++;
    }
    
    if(col_pos < size_col){
    	if(array[row_pos][col_pos+1] == 0)
    	{
    		Path_Finder(row_pos, col_pos+1, size_row, size_col);
		}
    }
    
    if(row_pos < size_row){
    	if(array[row_pos+1][col_pos] == 0)
    	{	
    		Path_Finder(row_pos+1, col_pos, size_row, size_col);
		}       
    }
}

int main(){
	
    Path_Finder(0, 0, 4, 5);
    cout << paths;
    return 0;
}
