#pragma once
#include "Stack.h"
#include "StackOverflow.h"
#include "StackUnderflow.h"
#include "WrongStackSize.h"

template <class T>
class StackArray : public Stack<T>
{
private:
    T* arr;
    int size = 0;
    int top = -1; 

public:
    StackArray(int s) : size(s), top(-1)
    {
        if (s <= 0)
        {
            throw WrongStackSize();
        }
        arr = new T[size];
    }

    ~StackArray()
    {
        delete[] arr;
    }

    void push(const T& e)
    {
        if (top == size - 1)
        {
            throw StackOverflow();
        }
        top++;
        arr[top] = e;
    }

    T pop()
    {
        if (top == -1)
        {
            throw StackUnderflow();
        }
        T elem = arr[top];
        top--;
        return elem;
    }

    bool isEmpty()
    {
        return top == -1;
    }
};