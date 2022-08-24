// Creation of the Integration Function
// Assignment 10: Michael Boodoosingh

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std; 

typedef double (*FUNC)(double);			// Creates a synonym for a double function (indicated by "typedef double")
										// FUNC represents functions of one variable that take a double as input and returns a double. Thi
										// After "*FUNC", we place "(double)" to indicate that the type of function accepts one double as a parameter

double line(double x){
	return x;

}

double square(double x){
	return x*x;
}

double cube(double x){
	return x*x*x;

}



double integrate(FUNC f, double a, double b){
	double sum = 0;
	for(double i = a; i <= b; i += 0.0000001){					// Start from the value of a and stop at the value of b. "0.0000001" is the interval and our width
																// The more zeros we add, the more accurate the sum would be
		
		sum += f(i) * 0.0000001;								// Multiply the height which is f(i) by the width/interval which is 0.0000001 to get 
																// the area of a rectangle
																// We use += because we want to add each rectangle's area to get the intergral
 }
	return sum;													// We need to return the sum of all rectangles to get the integral
}

int main(){
	
	cout<< "The integral of f(x)=x between 1 and 5 is: " << integrate(line, 1, 5)<<endl;
	cout<< "The integral of f(x)=x^2 between 1 and 5 is:" <<integrate(square, 1, 5)<<endl;
	cout<< "The integral of f(x)=x^3 between 1 and 5 is:" <<integrate(cube, 1, 5)<<endl;
	
	
	
	
	
	
	return 0;
}
