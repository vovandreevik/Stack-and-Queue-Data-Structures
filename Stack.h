#pragma once
template <class T>
class Stack
{
public:
	virtual ~Stack() {}
	virtual void push(const T& e) = 0; // Adding an item to the stack
	virtual T pop() = 0; // Removing the top element
	virtual bool isEmpty() = 0; // Checking the stack for emptiness
};
