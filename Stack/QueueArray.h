#pragma once
#include "Queue.h"
#include "StackOverflow.h"
#include "StackUnderflow.h"
#include "WrongStackSize.h"

template <class T>
class QueueArray : public Queue<T> {
private:
    int size = 0;
    int head = -1;
    int tail = -1;
    T* queueArray;
public:
    QueueArray(int size) : size(size), head(-1), tail(-1) {
        if (size <= 0) {
            throw WrongQueueSize();
        }
        queueArray = new T[size];
    }
    ~QueueArray() {
        delete[] queueArray;
    }
    void enQueue(const T& e) {
        if (tail == size - 1) {
            throw QueueOverflow();
        }
        tail++;
        queueArray[tail] = e;
        if (head == -1) {
            head = 0;
        }
    }
    T deQueue() {
        if (isEmpty()) {
            throw QueueUnderflow();
        }
        T item = queueArray[head];
        head++;
        if (head > tail) {
            head = tail = -1;
        }
        return item;
    }
    bool isEmpty() {
        return head == -1 and tail == -1;
    }
};
