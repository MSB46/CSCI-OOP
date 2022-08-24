// Eight queens program with visual appeal
// Assignment 9: Michael Boodoosingh

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


void print(int q[]){
	static int solutions = 0; 	//static keeps track of how many solutions were implemented before the current print
	solutions++;				//counts one more possible solution to the problem
	int i,j,k,l;
	
	typedef char box[5][7];
	
	box bb,wb,bq,wq,*board[8][8];			//board is an array full of pointers
	
	//fill in bb=black box and wb=whitebox
 	for(i=0;i<5;i++)
 		for(j=0;j<7;j++){
		 	wb[i][j]=' ';
 			wq[i][j]=' ';
 			bb[i][j]=char(219);
 			bq[i][j]=char(219);
 	}
	
	//Draw the queen in both the black queen and white queen boxes
	wq[1][1] = char(219);
	wq[2][1] = char(219);
	wq[3][1] = char(219);
	wq[3][2] = char(219);
	wq[3][3] = char(219);
	wq[3][2] = char(219);
	wq[2][3] = char(219);
	wq[1][3] = char(219);
	wq[3][4] = char(219);
	wq[3][5] = char(219);
	wq[2][5] = char(219);
	wq[1][5] = char(219);
	
	bq[1][1] = ' ';
	bq[2][1] = ' ';
	bq[3][1] = ' ';
	bq[3][2] = ' ';
	bq[3][3] = ' ';
	bq[3][2] = ' ';
	bq[2][3] = ' ';
	bq[1][3] = ' ';
	bq[3][4] = ' ';
	bq[3][5] = ' ';
	bq[2][5] = ' ';
	bq[1][5] = ' ';
	
	
	//fill board with pointers to bb and wb in alternate positions
 	for(i=0;i<8;i++)
 		for(j=0;j<8;j++)
 			if((i+j)%2==0)
 				board[i][j]=&wb;	//Taking away the '&' would make the compiler say: "cannot convert 'box {aka char [5][7]}' to 'char (*)[5][7]' in assignment"
									//Absence of '&' indicates that wb is dereferenced? 
 			else
 				board[i][j]=&bb;
 				
 	// print the board via the pointers in array board
	
	
	//modify the board using q
	for(i=0;i<8;i++)
		if((q[i] + i) % 2 == 0)
			board[q[i]][i] = &wq;	
		else
			board[q[i]][i] = &bq;
			
	cout << endl<< "Solution #" << solutions << ":" << endl;
	
	//first print upper border
	cout << "  ";
	
	for(i=0;i<7*8;i++)
		cout<<'_';
	cout << endl;
	
	//now print the board
	for(i=0;i<8;i++)				// We want to print completely from top to bottom which involves printing from left to right first. 
									// Therefore, integer i moves the slowest since it keeps track of which row we are in the board
	
		for(k=0;k<5;k++){			// int k will move the second slowest since the variable also helps move down the board.
									// However, k is responsible for telling the program the vertical position inside the box which makes this variable faster than i
		
			cout <<" "<<char(179); // prints the left border
			
			for(j=0;j<8;j++)		//Integer j keeps track of which column of the board we are in, making j more frequent than both i and k
			
				for(l=0;l<7;l++)	//Finally, integer l will be the most frequent since l is the variable that does the main printing
									// integer l also keeps track of the horizontal position inside the box 
				
					cout << (*board[i][j])[k][l];	//*board[i][j] is represented by either wb or bb depending on i and j's values
													// However, if there is supposed to be a queen in a certain box, it is represented by either
													// wq or bq depending on the position of the box on the board.
			
			
		
		cout << char(179) << endl; 		//prints the right border
		}

	
	
	
	//before exiting print lower border
	cout << " ";
	for(i=0;i<7*8;i++)
		cout << char(196);
	cout<<endl;	


}
	
	
	//backtrack occurs right after function ends


void backTrack(int &c){
	c--;					//go back a column
	if(c == -1)			//we shouldn't backtrack behind 0
		exit(1); 			//only way for the program to terminate
}


int main(){
	int q[8]; 			//the number representing each element will determine the row number the queen is on in the column
	int c = 0; 			//start at the first possible column on the board
	q[0] = 0; 			//place a queen at the first column and row of the board
	
	bool backtracked;	//Detects if a backtrack has occured previously
	
	
	 
	cout << "A9: Eight Queens (Fancy)" << "\n";


	
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
			
			c++;				//Indicates that a queen has been placed and must move to the next column and repeat the process
		}						
		
		print(q);				//If the column value is 8, all eight queens are properly placed and must be recorded
		system("pause");
		backTrack(c);			//After the solution is recorded, we backtrack in order to keep finding solutions
		backtracked = true;		//We skip setting the current row to -1 as we already went past the column at some point

		//Start from the top again until the column value is 8 again.
	}
 }
		
	
	
	
	

