//a2_boodoosingh_michael.cpp


#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


string add(string a, string b){
    	string answer = "";
    	string zeroAdd;
    	int x = (a.length() - 1), y = (b.length() - 1);
    	
    	
		int lengthDiff = abs(x-y);  //finds the difference in the string lengths of both strings
    	
    	for(int i = 0; i < lengthDiff; i++){
			zeroAdd += "0";		
		}
		
		if(a.length()< b.length())
			a = zeroAdd + a;
			
		else if(b.length()< a.length())
			b = zeroAdd + b;
			
		//evens out the lengths of strings a and b ^		
		
	    int u[x] = {0};
		int v[y] = {0};
		
		    	
		for(int i = x; i >= 0; i--)
			u[i] = (a[i] - '0');		// converts each digit in string a to an int. Important for the operation.
			
		for(int i = y; i >= 0; i--)	
			v[i] = (b[i] - '0');		//same as above but with string b
		
		
		int carry = 0;						//there is no carry at the start so the default is 0
		
		for(int i = x; i >= 0; i--){		//start from the last numbers in strings a and b
			int sum = u[i] + v[i] + carry;	// if there is a carry in the next loop the program will know to add it
  				
  					
			answer = char(sum%10 + '0') + answer;	//as the program goes backwards, so would the answer so we place the string in the back
			

			carry = sum/10;							//checks if a carry is needed
			// Concept of carrying over
		}
		
		if(carry > 0)
			answer = char(carry + '0') + answer;	
		//ensures a carry to the last digit if needed (even after the loop ends)
		
		
		return answer;
		

		

}

int main() {
        string x,y;
        
        START:
                cout << "Enter the first digit ";
                cin >> x;

                if(x == "done")
                        goto END;

                cout << "Enter the second digit ";
                cin >> y;
                
                if(y == "done")
                		goto END;
                
                cout << "The sum is " + add(x,y);
                cout << endl;
    	
		goto START;


		END: 
				cout << "Done.";
				
				
        return 0;


}


