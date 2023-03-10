#pragma once
#include <exception>

class WrongStackSize : public std::exception
{
public:
    const char* what() const noexcept
    {
        return "Wrong stack size";
    }
};

class WrongQueueSize : public std::exception 
{
public:
    const char* what() const noexcept
    {
        return "Invalid queue size!";
    }
};