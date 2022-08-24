// "Stable Marraige" Backtracking Method
// Assignment 7: Michael Boodoosingh

#include <iostream>
#include <stdlib.h>

using namespace std;
 
bool ok(int q[], int i){
	
	int mp[3][3]={0,2,1,					//Given values for this assignment
	 			  0,2,1,
	 		 	  1,2,0};
	
	int wp[3][3]={2,1,0,
				  0,1,2,
	 			  2,0,1};
											//Once again, this is a similar layout to the previous assignments
	for(int j = 0; j < i; j++){				//The program should only be concerned for the previous relationships. 
											//It shouldn't worry about what comes next
		if(q[i] == q[j])
			return false;					// "cheating test" nobody should have more than one match
	}
	
	for(int j = 0; j < i; j++){                      // "preference test" checks to see if there is a mutual preference in other people
	
          if( ( mp[i][q[j]]<mp[i][q[i]] ) && ( wp[q[j]][i]<wp[q[j]][j]) ) //if the current man prefers the new woman to his partner and 
					return false;										// if the new woman prefers the current man to her partner (condition 2)
                														// Unstable case #1
				     
          if( ( wp[q[i]][j]<wp[q[i]][i] ) && ( mp[j][q[i]]<mp[j][q[j]]) ) //if the new man prefers the current woman to his partner and
                return false;      										  //if the current woman prefers the new man to her partner 
    																	  //Unstable case #2
	}		
					
	return true;

}

void print(int q[]){
	static int solution = 0; // keeps count of the solutions before it
    solution++;				//counts one more possible solution to the problem
	
	cout <<"Stable Match #" << solution << ":" << endl;
    
	cout << "Man" << "\t" << "Woman" << endl;
		
	for(int i = 0; i < 3; i++){	
		cout << i << "\t" << q[i] << endl;
	}
		
	cout << endl;
}

void backTrack(int &man){
	man--;					//go back to the previous man
	if(man == -1)			//we shouldn't backtrack behind 0
		exit(1); 			//only way for the program to terminate
	
}

int main(){
	int i = 1;				//integer i represents the man
	int q[3];				//q[i] represents the woman (there are three men and three women)
	q[0] = 0;				//We start by setting the first man with the first woman
	bool backtracked;
	
	while(true){
		while(i < 3){				//keep the loop going until a valid match for all three men are found
			if(!backtracked)
				q[i] = -1;			//q[i] repeatedly gets added by 1 so by setting q[i] to -1 at first, we don't skip out on 0
				
			backtracked = false;
			
			
			while(q[i] < 3) {		//the loop keeps looks through the women until the program finds a valid match for the current man			
				++q[i];				//move to the next woman 
							
			
				while(q[i] == 3){	//there are no more than 3 women (woman 0, 1, and 2) so we backtrack
					backTrack(i);	//indicates that there are no valid matches for the current man. Must backtrack
					++q[i];			//the program goes back to the previous man and searches for the next woman and onwards
				}
				
			if(ok(q,i))			//"Is there a stable match?"
				break;			//If so, there is no need to keep going. End the loop early.
			}
			
			i++;				//Go to thd next man
			
		}
		print(q);				//As we reached the 3rd man, everyone has a proper match so we must print
		backTrack(i);			//After the solution is recorded, we go back to the previous man in order to keep finding solutions
		backtracked = true;		//We skip the assignment of the current woman to -1 (only necessary in the beginnning)  

		//Start from the top again and search until everyone gets a match again.
		
		
	}	
}
