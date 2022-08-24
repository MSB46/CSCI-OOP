//Find the shortest path based on the given 2D array w ("weight")
//A14: Michael Boodoosingh


#include <iostream>
using namespace std;

int const rows = 5;
int const cols = 6;

string path[rows][cols];	//We want to record which rows are involved for the shortest path. We use string because we don't want math operations to change the recorded path


int cost(int i, int j){			// i is the row, j is the column
	int w[rows][cols] = {
	{3,4,1,2,8,6},
	{6,1,8,2,7,4},
	{5,9,3,9,9,5},
	{8,4,1,3,2,6},
	{3,7,2,8,6,4}	};
	
	static int m[rows][cols]   = {};	//Memo. All elements should start at 0
	
	if(m[i][j] != 0)		//If we return to an element that has already been changed, we return it
		return m[i][j];		//Increase the speed of the runtime?
		
	if(j == 0){
		path[i][j] = to_string(i);	//If the column is at 0, we record the row value to the path array
		return w[i][0];				//Base case. Remember we want to move from the right to the left of the 'map'
	}

	
	
	int up = cost((i+rows-1)%rows,j-1);			//It helps if you draw a picture. If you're at the top row, you move to the bottom in the next column.
												// j-1 is essentially referring to "the column of the left"
	
	int left = cost(i,j-1);						// row stays the same, move left
	
	
	int down = cost((i+1)%rows,j-1);			//It helps if you draw a picture. If you're at the bottom row, you move to the top in the next column.
	
	int minimum;
	minimum = min(min(up,left), down);			// Determine the lowest cost between left, down, and up
	
	// We want to record the row that is associated with the lowest cost
	
	if(minimum == up)
		path[i][j] = path[(i+rows-1)%rows][j-1] + to_string(i);		//Updates the path index 
	
	if(minimum == left)
		path[i][j] = path[i][j-1] + to_string(i);
		
	if(minimum == down)
		path[i][j] = path[(i+1)%rows][j-1] + to_string(i);
	
	m[i][j] = w[i][j] + minimum;			//adds the indicated minimum and the current position's weight to the memo
	
	return m[i][j];							//returns whatever is recorded
	
}



int main(){
	
	
	int smallest = 0;
	
	for(int y = 0; y < rows; y++)						//We use cols -1 as that is the furthest the memo and weight arrays can go since we typed w[rows][cols]
		if(cost(y,cols-1) < cost(smallest,cols-1))		//check for the lowest cost by using a loop, 
			smallest = y;								//check the cost of each row and replace if the cost of the current lowest is bigger than the cost of the recent row
	
	cout << "\nThe shortest path is of length " << cost(smallest, cols-1);
	cout << ".\nThe rows of the path from left to right are " << path[smallest][cols-1] << ".";
	
	
	return 0;
	
	
	
	
	
}
