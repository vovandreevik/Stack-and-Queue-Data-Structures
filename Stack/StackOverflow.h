#pragma once
#include <exception>

class StackOverflow : public std::exception
{
public:
    const char* what() const noexcept
    {
        return "Stack overflow";
    }
};

class QueueOverflow : public std::exception 
{
public:
    const char* what() const noexcept
    {
        return "Queue is full!";
    }
};