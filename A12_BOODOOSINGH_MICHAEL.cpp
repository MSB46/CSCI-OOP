// Michael Boodoosingh
// A12: Towers of Hanoi

//NOTE: Each solution should take (2^n) - 1 moves, where n is the amount of rings that will be moved


#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

void ringsOdd(int n){
	int move=0;				// Counts how many moves it will take to solve the solution
	vector<int> t[3];		// We create a vector full of arrays
	
	int to = 1;				// We start moving towards Tower B (Clockwise)
	
							// Tower A: to = 0
							// Tower B: to = 1
							// Tower C: to = 2
	
	int from = 0;			// Because the amount of rings is odd, our first move is to move the candidate (1) to tower B. Think clockwise.
	int candidate = 1;		// Candidate is the smallest available ring that hasn't been moved in the previous move
	
	for(int i = n+1; i >= 1; i--)
			t[0].push_back(i);		//By looping this line, the first array t[0] (Known as Tower A) will have the rings with the ring 1 on top and ring n+1 on the bottom
									//Ring n+1 will be there to ensure that the array is not empty but n+1 will never be referred to in the actual program. 
									// ^ Think of n+1 being like a table to the towers
		
		t[1].push_back(n+1);		//Towers B and C will not have any rings in the beginning, only a table to keep the arrays not empty.
		t[2].push_back(n+1);
		

		
		while(t[1].size() < n+1){	// The loop continues until Tower B has all n rings on the tower

			cout << "Move number " << ++move << ": Transfer ring " << candidate << " from tower " << char(from + 65) << " to tower " << char(to + 65) << endl;
			// writing of the instructions	
	
			t[to].push_back(t[from].back());	//Take the top ring of the "from" tower and move it towards the top of the "to" tower
												//Remember, t[from].back really means the top ring of the "from" tower
			
			t[from].pop_back();					//We remove the top ring of the "from" tower since we already moved it to the "to" tower
			
		
			if(		t[(to+1) % 3].back() < t[(to+2) % 3].back()		)	// Here, we find the next "from tower". 
				from = (to+1) % 3;										// The next "from" will be determined by the tower with the smallest ring (not counting the recent cadidate's new tower) 										
			else
				from = (to+2) % 3;										// The "from tower" cannot be the same tower as the last move's "from tower". It must be new.
																		// %3 ensures that "to" equals 0, 1, or 2
			if(		t[from].back() < t[(from+1)%3].back()		)
				to = (from+1) % 3 ;
			else
				to = (from+2) % 3 ;
	
			candidate = t[from].back();									// Canidate is always the top of the current "from tower"
		
		}	
	
}

void ringsEven(int n){													// The main difference between the processes of the even and odd rings
	int move=0;															// is that the even process moves counter clockwise
	vector<int> t[3];													
	
	int to = 2;															// The first "to" tower will be Tower C since we move counterclockwise from Tower A
	int from = 0;
	int candidate = 1;
	
	for(int i = n+1; i >= 1; i--)
			t[0].push_back(i);

		t[1].push_back(n+1);
		t[2].push_back(n+1);
		

		
		while(t[1].size() < n+1){
			cout << "Move number " << ++move << ": Transfer ring " << candidate << " from tower " << char(from + 65) << " to tower " << char(to + 65) << endl;
	
	
			t[to].push_back(t[from].back());
			t[from].pop_back();
		
			if(	t[(to+1) % 3].back() > t[(to+2) % 3].back()	)		// Find the next "from tower". Depends on the top ring of the non "to" towers  
				from = (to+2) % 3;
			else
				from = (to+1) % 3;
			
			if(t[(from)].back() > t[(from+2)%3].back())				// Find the next "to tower". Depends on the top ring of the from tower and the tower 
				to = (from+1) % 3 ;									//counterclockwise to the current "from" tower
			else
				to = (from+2) % 3 ;									//if the top ring of the current from tower is smaller 
																	//the next "to" is the right of the current "from" tower
																	//otherwise, it's counterclockwise to the current "from"
			candidate = t[from].back();						
		
		}	
	
	
	
	
	
}

int main(){
	int n;
	vector<int> t[3];
	
	cout << "How many rings do you want to move? ";
	cin >> n;
	cout << endl;
	
	if(n % 2 == 1)
		ringsOdd(n);
		
	else
		ringsEven(n);
	
	
	return 0;
}
