// The n queens. Find the amount of possible solutions for an n x n board
// Assignment 11: Michael Boodoosingh

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

bool validQueen(int q[], int c){
	//two tests: row test and diagonal test
	
	for(int i = 0; i < c; i++){			//starts checking from the start of the board to the last queen's column
											//we don't care for the columns after the current		
	
		if((q[i] == q[c]) || ((c-i) == abs(q[c] - q[i])))	//first condition checks for a row conflict (rook mechanics)
			return false;										//second condition checks for diagonal conflict (bishop mechanics)
	}
	
	return true;
		
}


int findSolutions(int q[],int n){
	
	bool backtracked;	//Detects if a backtrack has occured previously
	int c = 0; 			//start at the first possible column on the board
	q[0] = 0; 			//place a queen at the first column and row of the board
	
	int solutions = 0;	//This will keep track the amount of solutions there are for the n x n board
	
	
	while(true){				// The only way for the function to end is via backtracking from column 0. 
		while(c<n){				// Makes sure the program doesn't check past column n
		
			if(!backtracked)	// "Did the program just backtrack?"
				q[c] = -1; 		//ensures that we don't ignore row 0 from column 0
								
				backtracked = false;
				
				while(q[c] < n) {		//makes sure the program doesn't check past row n		
					//goto next_row;
					++q[c];				//moves the queen in the column up another row
					
					while(q[c] == n){	//If the current row is n, we have went past the last row
						
						c--;					// "Backtrack"
						if(c == -1)
							return solutions;	//Instead of the program terminating when c == -1, we simply end the function by returning the solution count
						
						
						++q[c];			//move down the row again
					}
				
					if(validQueen(q,c))	//"Is the queen in a valid spot? Does it pass the row and diagonal tests?"
						break;			//If so, there is no need to keep going down the board. End the loop early.
				}
			
			c++;				//Indicates that a queen has been placed and must move to the next column and repeat the process
		}						
		
		solutions++;			//If the column value reaches n, we must count 1 more to the solution count
		
		c--;
		if(c == -1)
			return solutions;	//After we add 1 to the solution count, we "backtrack" in order to keep finding solutions
								//Instead of the program terminating when c == -1, we simply end the function by returning the solution count
			
			
		backtracked = true;		//We skip setting the current row to -1 as we already went past the column at some point

		//Start from the top again until the column value reaches n again.
	}
	
	
	
}

int main(){
	int n;
	cout << "A11: The n queens \n";
	cout << "How many columns on the board? (Row will be the same amount) \n";
	
	cin >> n;
	
	int* q = new int[n];		// We create a new array called q with the size of n
								// q will point to some available space for an array with the size of n
	
	for(int i = 1; i <= n; i++){
	
		if(findSolutions(q,i) == 1)
			cout << "There is " << findSolutions(q,i) << " solution to the " << i << " queen problem" << endl;
			
		else
			cout << "There are " << findSolutions(q,i) << " solutions to the " << i << " queens problem" << endl;
	}
	
	delete [] q;				// Important for preventing memory leaks
	
	return 0;
	
	
	
}
