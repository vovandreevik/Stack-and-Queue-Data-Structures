# C++ Stack and Queue Data Structures

This C++ project implements stack and queue data structures using two different classes:
- `StackArray` for stack data structure.
- `QueueArray` for queue data structure.

These classes provide essential operations such as push/pop (for stacks) and enQueue/deQueue (for queues). Additionally, the project includes custom exception classes for stack and queue operations.

## Project Structure

The project consists of the following files:

- `Stack.h` and `StackArray.h`: Stack data structure classes and headers.
- `Queue.h` and `QueueArray.h`: Queue data structure classes and headers.
- `StackOverflow.h`, `StackUnderflow.h`, `QueueOverflow.h`, and `QueueUnderflow.h`: Custom exception classes.
- `main.cpp`: A sample application that demonstrates the usage of stack and queue classes.
- `WrongStackSize.h` and `WrongQueueSize.h`: Custom exception classes for incorrect stack or queue sizes.

## Usage
The program allows you to use stack and queue data structures, demonstrating the key operations:

### Stack Operations:
- Push: Add an item to the stack.
- Pop: Remove the top element from the stack.
- Check for emptiness.
- Queue Operations:
- Enqueue: Add an item to the queue.
- Dequeue: Remove the front element from the queue.
- Check for emptiness.
- Custom Exception Classes
- StackOverflow: Thrown when a stack operation results in an overflow.
- StackUnderflow: Thrown when a stack operation results in an underflow.
- QueueOverflow: Thrown when a queue operation results in an overflow.
- QueueUnderflow: Thrown when a queue operation results in an underflow.
- WrongStackSize: Thrown for incorrect stack sizes.
- WrongQueueSize: Thrown for incorrect queue sizes.
