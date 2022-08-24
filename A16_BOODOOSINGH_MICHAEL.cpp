//Rational Number Class
//A16: Michael Boodoosingh

#include <iostream>
using namespace std;

class Rat{
	private:
		int n;			//These values are private which means nothing but member functions and friends can access these variables 
		int d;			// AKA: Data hiding
	
	public:				//Anything within public can be accessed (like get/set functions) AKA: Encapsulation
		Rat(){			//If a rat is made with no parameters. Automatically assign both the num and deno.
			n = 0;
			d = 1;
		}
		
		Rat(int a){		//If a rat is made with only one parameter. Automatically assign the denominator
			n = a;
			d = 1;
		}
		
		Rat(int a, int b){
			n = a;				//Set the numerator to a
			d = b;				//Set the denominator to b
			
			
		
		}
		
		int getN(){	return n;}	//Get numerator (N) or denominator (D)
		int getD(){ return d;}
		
		void setN(int x){		//Just in case we want to assign a rat's numerator/denominator to something else
			n = x;
		}
		void setD(int x){
			d = x;
		}
		
		
		Rat operator+(Rat r){		//These functions allow the use of various signs like '+' by assigning them a different purpose (AKA: Overloading) 
			Rat t;
			t.n = d * r.n + n * r.d;  
			t.d = r.d * d;
			
			simplify(t);		//Simplify the fraction if needed
			return t;
		}
		
		Rat operator-(Rat r){						// t.n/t.d - r.n/t.d 
			Rat t;
			t.n = n * r.d  - d * r.n;  
			t.d = r.d * d;
			
			simplify(t);
			return t;
		}
		
		Rat operator*(Rat r){
			Rat t;
			t.n = n * r.n;  
			t.d = d * r.d;
			
			simplify(t);
			return t;
		}
		
		Rat operator/(Rat r){
			Rat t;
			t.n = n * r.d;  			//Switch the placements of r.d and r.n. Much like flipping the second fraction's numerator and denominator
			t.d = d * r.n;	
			
			simplify(t);
			return t;
		}
		
		Rat simplify(Rat &t){								//Allows simplifying within the class (for any mathematical operation)
			for(int i = max(t.n,t.d); i >= 2; i--){			//Find the highest number between num and deno. 
				if((t.d % i == 0) && (t.n % i == 0)){		//Lowest number must be 2.
					t.n = (t.n/i); 
					t.d = (t.d/i);
					break;									//Find the first number that both n and d are divisible by
			}		
		}
			
}
		
		friend ostream& operator<<(ostream& os,Rat r);		//friends aren't member functions, but outside functions that can access the private values of a class
		friend istream& operator>>(istream& is, Rat &r);	// We must implement the ">>" and "<<" operators for our Rat class 
		

};

ostream& operator<<(ostream& os, Rat r){						//We use the address of the output stream os in order to ensure that the rat is the output
	if(r.n > r.d && (r.n % r.d) != 0){											//Detects if the rational number is a mixed number (Numerator > Denominator)
		os << (r.n/r.d) << " and " << (r.n%r.d) << "/" << r.d << endl;
	}
	
	else															//Otherwise, just use the normal structure of a fraction
		os << r.n << "/" << r.d << endl;
	return os;
		
}

istream& operator>>(istream& is, Rat &r){
	is >> r.n >> r.d;
	return is;
}

void simplify(Rat &t){										//Outside function used for simplifying fractions outside the class
	for(int i = max(t.getN(),t.getD()); i >= 2; i--){		//We use getN and getD because we don't have access to the variables n and d
		if((t.getD() % i == 0) && (t.getN() % i == 0)){		//getN and getD do get access to those variables however
			t.setN(t.getN()/i); 			//Assigns the numerator to it's current numerator divided by the highest number n is divisible by
			t.setD (t.getD()/i);
			break;							//end the loop. We found our number.
		}		
	}			
}

int main(){	
	int a,b,c,d;
	while(true){
	
	cout<< "===========================\nEnter the numerator: ";
	cin >> a;
	cout<< "\nEnter the denominator: ";
	cin >> b; 
	
	if(b==0)			//Let's not divide by zero shall we? Unless you want to terminate the program, then by all means do it.
		exit(1);
		
	Rat *x = new Rat(a,b);			//Create a new rational number using the user-entered values. Pointer towards a Rat
	
	simplify(*x);			//X is the pointer to the rational number of numerator a and denominator b. Dereferencing it gives us the fraction
	cout << *x;				
	
	cout<< "\n===========================\nEnter a numerator for another fraction: ";
	cin >> c;
	cout<< "\nEnter the denominator: ";
	cin >> d; 
	
	if(d==0)
		exit(1);
				
	Rat *y = new Rat(c,d);		//Create a new rational number using the user-entered values. Pointer towards a Rat
	
	simplify(*y);
	cout << *y;				//Find the value of the dereferenced pointer
	
	string choice;
	cout << "\n===========================\nWhat would you like to do with these fractions? \nAdd\nSubtract\nMultiply\nDivide\n\n(Type only the first letter in upper case)\n\n";
	cin >> choice;
	
	if(choice == "A")
		cout << *x + *y;
		
	else if(choice == "S")
		cout << *x - *y;
	
	else if(choice == "M")
		cout << *x * *y;
	
	else if(choice == "D")
		cout << *x / *y;
	
	else exit(1);

	delete x;		// Memory leaks are a big no-no
	delete y;
	
		
	}
}
