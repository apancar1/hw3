#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T> // do private inheritance 
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};



template <typename T> 
Stack<T>::Stack() : std::vector<T>(){
	// constructor 
}


template <typename T> 
Stack<T>::~Stack(){
	// destructor 
} 


template <typename T>
bool Stack<T>::empty() const{
	return std::vector<T>::empty(); 
	// from vector class (inherited)
}

template <typename T>
size_t Stack<T>::size() const{
	return std::vector<T>::size();
	// inherited from vector class 
}

template <typename T>
void Stack<T>::push(const T& item){
	std::vector<T>::push_back(item);
	// simply add the item to the back of the vector (push back is from vector class)
}

template <typename T> 
void Stack<T>::pop(){
	// this shoudl throw 
	// first check if empty 
	if (empty()){
		throw std::underflow_error("The stack is empty, so there is nothing to pop!");
	}
	// if not empty, get the item that was most recently added (the top)
	std::vector<T>::pop_back(); 
	// inherited from vector class 
	// use pop_back instead of back bc you want to remvoe it as well
	// dont return val since it is void 
}

template <typename T>
const T& Stack<T>::top() const{
	// this should throw 
	// same implementation as pop but only use back since we dont want to remove element
	if (empty()){
		throw std::underflow_error("The stack is empty, so there is no top element!");
	}
	return std::vector<T>::back(); 
	// return val 
}

#endif