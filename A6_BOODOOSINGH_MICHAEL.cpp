// "Eight Numbers in a Cross" Backtacking Method
// Assignment 6: Michael Boodoosingh


#include <iostream>
#include <stdlib.h>

using namespace std;

// For the following arrays, we want to indicate where the second loop will stop because 
// each square will stop searching at different times.
// Example: square 1 will stop searching after it checks square 0 
// 			while square 7 stops after it checks squares 3, 4, 5, and 6

// Indicated by the second for loop below, the -1 in each array is used as a "stop sign"

/* The order of each box is resembled as:

	   	  square1  	square2
square0   square3  	square4  square5
	      square6  	square7

*/

bool ok(int q[], int s){
	int a[8][5] = { {-1,-1,-1,-1,-1}, 		//square 0
	{0,-1,-1,-1,-1},						
	{1,-1,-1,-1,-1},						//Note: any number that is not -1 is another square 
	{0,1,2,-1,-1},							//Example: square 3 is concerned for squares 0, 1, and 2 as those squares are all adjacent to 4
	{1,2,3,-1,-1}, 							//However, s3 should not care for 4,6, or 7 as those squares should still be blank
	{2,4,-1,-1,-1}, 
	{0,3,4,-1,-1}, 							
	{3,4,5,6,-1} };							//square 7
	
	for(int j = 0; j < s; ++j){				//Much like the eight queens, the current square cares not for the squares after itself, only before
		if(q[s] == q[j])
			return false;					// "row" test
	}
		
		
	for(int k = 0; a[s][k] != -1 ; ++k){	// the loop should continue moving to the next column until it reaches the "stop sign" (-1)
		if(abs(q[s] - q[a[s][k]]) == 1)   	// Checks if the current number placed is consecutive to the number before it
			return false;					//"neighbor" test
	}
		
	
	return true;
}

void print(int q[8]){
    static int solution = 0; // keeps count of the solutions before it
    solution++;				//counts one more possible solution to the problem
	
	cout <<"Solution #" << solution << ":" << endl;
    cout << endl;
    cout << "  " << q[1] << " " << q[2] << endl;
    cout << q[0] << " " << q[3] << " " << q[4] << " " << q[5] << endl;		//refer to line 17
    cout << "  " << q[6] << " " << q[7] << endl << endl;
}

void backTrack(int &sq){
	sq--;					//go back a square
	if(sq == -1)			//we shouldn't backtrack behind 0
		exit(1); 			//only way for the program to terminate
}

int main(){
	
	int s = 0;			//we must start at square 0
	int q[8] = {0};		//all values of the array must be initialized to 0
	bool backtracked;	//Detects if a backtrack has occured previously
	
	while(true){		//same as previous assignment: only way for a program to terminate is via backtracking
		while(s < 8){			// after the loop ends, we print and backtrack
			if(!backtracked)
				q[s] = 0;		// as the program starts, we must assign q[0] as 0 so we start the placement of the first number (which is 1)
								
				while(q[s] <= 8) {		//the loop keeps going until the program finds a valid spot for the current number			
					++q[s];				//move to the next number (from 1 to 8)
					
					while(q[s] > 8){	//there cannot be a number greater than 8 so we backtrack
						backTrack(s);	//indicates that there are no valid spots for the current column. Must backtrack
						++q[s];			//go to the next number
					}
					
				if(ok(q,s))			//"Is the number in a valid spot"
					break;			//If so, there is no need to keep going. End the loop early.
				}
				
			s++;					//move to the next square
			backtracked = false;	//indicates that a backtrack hasn't occured (yet)
			
		}
		print(q);				//As we reached the 8th square, all numbers are placed properly so we must print
		backTrack(s);			//After the solution is recorded, we backtrack and go back a square in order to keep finding solutions
		backtracked = true;		//We skip setting the current number to square 0 (only necessary in the beginnning)  

		//Start from the top again until the square stays at 8 again.
	}
}
