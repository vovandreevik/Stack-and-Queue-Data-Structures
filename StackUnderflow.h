#pragma once
#include <exception>

class StackUnderflow : public std::exception
{
public:
    const char* what() const noexcept
    {
        return "Stack underflow";
    }
};

class QueueUnderflow : public std::exception 
{
public:
    const char* what() const noexcept
    {
        return "Queue is empty!";
    }
};