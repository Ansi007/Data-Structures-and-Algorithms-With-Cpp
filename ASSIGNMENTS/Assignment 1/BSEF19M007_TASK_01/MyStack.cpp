#include<iostream>
#include "MyStack.h"
using namespace std;


template<class T>
MyStack<T>::MyStack()
{
	size = 10;
	top = -1;
	stack = new T[size];
}

template<class T>
MyStack<T>::MyStack(int s)
{
	size = s;
	top = -1;
	stack = new T[size];
}

template<class T>
void MyStack<T>::Push(T x)
{
	/*
	The function will add a receieved item to the stack
	:param s: The item recieved
	:return: True if Valid else false
	*/

	if (isFull())
		resize();

	stack[++top] = x;

}

template<class T>
T MyStack<T>::Pop()
{
	/*
	The function remove the top item from the stack
	:return: Removed item
	*/

	if (isEmpty()) {
		resize();
	}

	else if (top + 1 <= size / 4) {
		resize();
		return stack[top--];
	}

	else return stack[top--];
}

template<class T>
T MyStack<T>::Peek()
{
	/*
	The function show the top item
	:return: Top element/item
	*/

	return stack[top];
}

template<class T>
bool MyStack<T>::isFull()
{
	/*
	The function will tell if the stack is full or not
	:return: True if full else false
	*/

	return top == size - 1;
}

template<class T>
bool MyStack<T>::isEmpty()
{
	/*
	The function will tell if the stack is empty or not
	:return: True if empty else false
	*/

	return top == -1;
}

template<class T>
void MyStack<T>::resize()
{
	/*
	The function will resize the stack if stack if full or 3/4th of stack is empty
	Size is increased by 2 times if it is full
	Size is decreased by 2 times if it's  3/4th of stack is empty
	*/

	if (isFull()) {
		size *= 2;
	}

	else if (top + 1 <= size / 4) {
		size = ceil(size / 2);
	}

	if (size == 0)
		size = 2;

	T* stack2 = new T[size];

	for (int i = 0; i <= top; i++) {
		stack2[i] = stack[i];
	}

	if (size > 0)
		delete[] stack;
	stack = stack2;

}

template<class T>
MyStack<T>::~MyStack()
{
	if (size > 0)
		delete[] stack;
}


