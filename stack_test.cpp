#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include "stack.h"
using namespace std;

int main()
{
	Stack<int> testStack; 
	// create stack 

	for (int i = 0; i < 5; i++){
		testStack.push(i);
	}
	// test adding 5 elements

	// now want to test to see order of pop 
	while (!testStack.empty()){
		cout << testStack.top() << " ";
		testStack.pop();
	}
	cout << endl; 
	cout << "Size: " << testStack.size() << endl;
	cout << "Empty? " << testStack.empty() << endl;
	// output was 4 3 2 1 0 which is correct 

	// test the error part 
	//cout << testStack.top() << endl; 
	//testStack.pop();

	// test with double 
	Stack<double> DoubleStack; 
	DoubleStack.push(5.6);
	DoubleStack.push(7.8);
	cout << "First element: " << DoubleStack.top() << endl; 
	cout << "Stack size: " << DoubleStack.size() << endl; 

	// test with strings 
	Stack<string> stringStack; 
	stringStack.push("first");
	cout << "String first element: " << stringStack.top() << endl;
}