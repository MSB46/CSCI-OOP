// The k bishops problem. Find the amount of possible solutions for an n x n board
// Assignment 15: Michael Boodoosingh

#include <iostream>
#include <cmath>
using namespace std;

static int count = 0;


bool ok(int *q, int c, int n){					//Think of c as an individual square of the board instead of a whole column
	//one test only: diagonal test
	
	for(int i = 0; i < c; i++){					//starts checking from the start of the board to the last bishop's column
												//we don't care for the squares after the current one		
										
		if((q[i]/n) + (q[i]%n) == (q[c]/n) + (q[c]%n) || ((q[i]/n) - (q[i]%n) == (q[c]/n) - (q[c]%n)))
			return false;	
							
		//Imagine each box in the checkerboard is assigned a number starting from
		//spot 0 at the topright box. So in a 6x6 board, the bottom right is spot 35					

		//In a 6x6 board, there cannot be a bishop on spot 0 and 35 at the same time
		//Likewise, there cannot be a bishop on both spot 24 and spot 14 (a picture would help for visualization)
	
		//So we use the if statement about to prevent the bool from returning true under similar conditions
		// We divide each element by n since the size of the board always varies
		// Otherwise, the if statement is rather similar to the eight queens
	
	}
	
	return true;
		
}

int factorial(int n){
	static int m[1000] = {};	//Memoization. Loads values of smaller factorials quicker
	if(n == 1 || n == 0)
		return 1;				//Base case
		
	if(m[n] != 0) return m[n];	//Returns whatever is recorded in the memo
	
	m[n] = n * factorial(n-1);	//If not in the memo, multiply the current value of n by smaller factorials until n == 1 or 0
		
	return m[n];				//Same as line 41
	
}

void backTrack(int &c, int q[], int n, int k, int count){
	c--;					//go back a column
	if(c == -1){
		
		cout << "\nOn a " << n << "x" << n << " board with " << k << " bishops" << ", there will be " <<count/factorial(k) << " solutions." << endl;	
		// We divide the count by the factorial of the amount of bishops. This will prevent any repeated solutions with a different order of bishops 
        
		delete[] q;			//Stops memory leaks
		
		exit(1); 			//only way for the program to terminate
	}
}


int main(){
	int n,k;
	//n >= k 
	
	cout << "Enter the length of the board\n";
	cin >> n;
	cout << "\nHow many bishops will you use?\n";
	cin >> k;
	
	int* q = new int[k];		// We create a new array called q with the size of n
								// q will point to some available space for an array with the size of n
	
	while(n < k){
		cout << "\n(The length must be greater or equal to the amount of bishops) Enter the length of the board\n";
		cin >> n;
		cout << "\nHow many bishops will you use?\n";
		cin >> k;
	}
	
	int c = 0; 			//start at the first possible column on the board
	q[0] = 0; 			//place a queen at the first column and row of the board
	
	bool backtracked;	//Detects if a backtrack has occured previously
	
	while(true){				// The only way for the loop and the program to end is via backtracking from column 0. 
		while(c<k){				// Otherwise, we don't want the loop to end ever
		
			if(!backtracked)	// "Did the program just backtrack?"
				q[c] = -1; 		//ensures that we don't ignore row 0 from column 0
								
				backtracked = false;
				
				while(q[c] < n*n) {		// Unlike eight queens, we are not only checking each "column", but every single box on the board. So we use n*n
					++q[c];				
					while(q[c] == n*n){
						backTrack(c,q,n,k,count);	 	//Must backtrack
						++q[c];							//move down the row again
					}
				
					if(ok(q,c,n))		//"Is the bishop in a valid spot? Does it pass the diagonal test?"
						break;			//If so, there is no need to keep going down the board. End the loop early.
				}
			
			c++;				//Indicates that a bishop has been placed and must move to the next column and repeat the process
		}						
		
		count++;							//If the spot value is at its furthest, all bishops are properly placed and must be counted
		backTrack(c,q,n,k,count);			//After the solution is recorded, we backtrack in order to keep finding solutions
		backtracked = true;					//We skip setting the current row to -1 as we already went past the column at some point

	}
	


	return 0;

	
}
