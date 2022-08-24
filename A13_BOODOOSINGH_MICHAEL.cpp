#include <iostream>
#include <cmath>
using namespace std;




bool okSquare(int *p, int i){
	int a[8][5] = {	{-1},
					{0,-1},
					{0,-1},
					{0,1,2,-1},
					{0,1,3,-1},
					{1,4,-1},
					{2,3,4,-1},
					{3,4,5,6,-1}	};
	
	for(int j = 0; j < i; ++j){				//Much like the eight queens, the current square cares not for the squares after itself, only before
		if(p[i] == p[j])
			return false;					// "row" test		
	}
		
		
	for(int k = 0; a[i][k] != -1 ; ++k){	// the loop should continue moving to the next column until it reaches the "stop sign" (-1)
		if(abs(p[i] - p[a[i][k]]) == 1)   	// Checks if the current number placed is consecutive to the number before it
			return false;					//"neighbor" test
	}
		
	
	return true;
}

bool okMarraige(int *q, int i){
	int mp[3][3]={0,2,1,					//Given values for this assignment
	 			  0,2,1,					// '0' is the most desired while '2' is the least
	 		 	  1,2,0};
	
	int wp[3][3]={2,1,0,
				  0,1,2,
	 			  2,0,1};
	
	for(int k = 0; k < i; k++)
		if(q[k] == q[i])
			return false;
		
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

void printSquare(int *p){
	static int count = 0;
	cout << "Solution " << ++count << ": \n";
	
    cout << "  " << p[0] << " " << p[1] << endl;
    cout << p[2] << " " << p[3] << " " << p[4] << " " << p[5] << endl;		
    cout << "  " << p[6] << " " << p[7] << endl << endl;


}

void moveSquare(int *p, int n){
	if(n == 8){
		printSquare(p);
		return;
	}
	
	for(int j = 0; j < 8; j++){
		
		p[n] = j;
		if(okSquare(p,n))
			moveSquare(p,n+1);
		
	}
	
		
}




void printMarraige(int *q){
	static int solution = 0;
	cout << "Solution: " << ++solution << ": \n";
	
	for(int x = 0; x <= 2; x++){
		
		cout << "Man\t" << "Woman\n";
		cout << x << "\t" << q[x] << "\n";
		
	}
	cout << endl;
	
	
}



void moveMarraige(int *q, int n){
	if (n == 3){
		printMarraige(q);
		return;
}
	
	for(int j = 0; j < 3; j++){
		q[n] = j;
		
		if(okMarraige(q,n))
			moveMarraige(q,n+1);
		
		
	}
	
}


int main(){
	int p[3];
	int q[8];
	
	cout << "Eight Numbers in a Cross\n";
	moveSquare(q,0);
	cout << endl;
	
	system("pause");
	
	cout << "Stable Marraige\n";
	moveMarraige(p,0);
	
	return 0;
	
}
