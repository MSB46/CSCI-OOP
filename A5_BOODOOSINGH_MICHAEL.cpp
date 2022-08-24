// Eight queens array without the use of labels
// Assignment 5: Michael Boodoosingh

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

bool validQueen(int x[], int co){
	//two tests: row test and diagonal test
	
	for(int i = 0; i < co; i++){			//starts checking from the start of the board to the last queen's column
											//we don't care for the columns after the current		
	
		if((x[i] == x[co]) || ((co-i) == abs(x[co] - x[i])))	//first condition checks for a row conflict (rook mechanics)
			return false;										//second condition checks for diagonal conflict (bishop mechanics)
	}
	
	return true;
		
	}


void print(int a[]){
	static int solutions = 0; 	//static keeps track of how many solutions we're implemented before the current print
	solutions++;				//counts one more possible solution to the problem
	
	//int board[8][8] = {0};		// represents the eight columns and eight rows in the board. All spots must start without a queen
									// used for printing the 2D version of the board
	
	cout << solutions << ":" << endl;
	
	for(int i = 0; i < 8; i++){
		cout << a[i];						//each loop represents each column. Prints the row each column;s queen is on
	}
	cout << endl << endl;

	/*
	for(int i = 0; i < 8; i++)				// refer to line 31 for the loops on lines 41 and 44
		 board[a[i]][i] = 1;				//sets all of the current positions of all eight of the valid queens to "1"
		
	for(int a = 0; a < 8; a++){
		for(int b = 0; b < 8; b++){
			cout<<board[a][b]<<" ";			//prints the positions with "a" being the row and "b" being the column
		}
		cout << "\n";
	}
	*/
	
	//backtrack occurs right after function ends
}

void backTrack(int &co){
	co--;					//go back a column
	if(co == -1)			//we shouldn't backtrack behind 0
		exit(1); 			//only way for the program to terminate
}


int main(){
	int q[8]; 			//the number representing each element will determine the row number the queen is on in the column
	int c = 0; 			//start at the first possible column on the board
	q[0] = 0; 			//place a queen at the first column and row of the board
	
	bool backtracked;	//Detects if a backtrack has occured previously

	cout << "A5: Eight Queens (No Labels)" << "\n";


	
//next_row:
	while(true){				// The only way for the loop and the program to end is via backtracking from column 0. 
		while(c<8){				// Otherwise, we don't want the loop to end ever
		
			if(!backtracked)	// "Did the program just backtrack?"
				q[c] = -1; 		//ensures that we don't ignore row 0 from column 0
								
				backtracked = false;
				
				while(q[c] < 8) {		//the loop keeps going until the program finds a valid spot for the column's queen			
					//goto next_row;
					++q[c];				//moves the queen in the column up another row
					while(q[c] == 8){
						backTrack(c);	//indicates that there are no valid spots for the current column. Must backtrack
						++q[c];			//move down the row again
					}
				
					if(validQueen(q,c))	//"Is the queen in a valid spot? Does it pass the row and diagonal tests?"
						break;			//If so, there is no need to keep going down the board. End the loop early.
				}
			//goto next_col;
			c++;				//Indicates that a queen has been placed and must move to the next column and repeat the process
		}						
		
		print(q);				//If the column value is 8, all eight queens are properly placed and must be recorded
		backTrack(c);			//After the solution is recorded, we backtrack in order to keep finding solutions
		backtracked = true;		//We skip setting the current row to -1 as we already went past the column at some point

		//Start from the top again until the column value is 8 again.
	}
 }
		
	
	
	
	

