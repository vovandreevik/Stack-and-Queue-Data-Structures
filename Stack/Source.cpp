#include <iostream>
#include <string>
#include "StackArray.h"
#include "QueueArray.h"
#include "StackOverflow.h"
#include "StackUnderflow.h"
#include "WrongStackSize.h"

bool checkBalanceBrackets(const std::string& text, const int maxDeep);

int main()
{
    //StackArray
    try
    {
        StackArray<int> intStack(-1);

        intStack.push(1);
        intStack.push(2);
        intStack.push(3);

        while (!intStack.isEmpty())
        {
            std::cout << intStack.pop() << " ";
        }
        std::cout << std::endl;
        intStack.pop();
        std::cout << std::endl;

        StackArray<std::string> stringStack(-6);

        stringStack.push("a");
        stringStack.push("b");
        stringStack.push("c");
        stringStack.push("d");
        std::cout << std::endl;

        while (!stringStack.isEmpty())
        {
            std::cout << stringStack.pop() << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        exit(-1);
    }

    //function
    std::string text = "[a{b]c}(d)";
    int maxDeep = 3;

    bool isBalanced = checkBalanceBrackets(text, maxDeep);

    std::cout << (isBalanced ? "Balanced" : "Not balanced") << std::endl;

    std::string text1 = "{a[b]c}(d)";
    int maxDeep1 = 3;

    bool isBalanced1 = checkBalanceBrackets(text1, maxDeep);

    std::cout << (isBalanced1 ? "Balanced" : "Not balanced") << std::endl;

    //QueueArray
    try {
        QueueArray<int> queue(-7);
        queue.enQueue(1);
        queue.enQueue(2);
        queue.enQueue(3);
        queue.enQueue(4);
        queue.enQueue(5);
        queue.enQueue(6);
        while (!queue.isEmpty()) {
            std::cout << queue.deQueue() << " ";
        }
        std::cout << std::endl;
        queue.deQueue();
        std::cout << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        exit(-1);
    }

    return 0;
}

bool checkBalanceBrackets(const std::string& text, const int maxDeep)
{
    Stack<char>* temp = new StackArray<char>(text.size());

    int roundCount = 0;
    int squareCount = 0;
    int curlyCount = 0;
    for (int i = 0; i < text.size(); i++)
    {
        char siqn = text[i];
        switch (siqn)
        {
        case '(':
            if (roundCount + squareCount + curlyCount >= maxDeep)
                return false;
            roundCount++;
            temp->push(siqn);
            break;
        case ')':
            if (roundCount == 0 or temp->pop() != '(')
                return false;
            roundCount--;
            break;
        case '[':
            if (roundCount + squareCount + curlyCount >= maxDeep)
                return false;
            squareCount++;
            temp->push(siqn);
            break;
        case ']':
            if (squareCount == 0 or temp->pop() != '[')
                return false;
            squareCount--;
            break;
        case '{':
            if (roundCount + squareCount + curlyCount >= maxDeep)
                return false;
            curlyCount++;
            temp->push(siqn);
            break;
        case '}':
            if (curlyCount == 0 or temp->pop() != '{')
                return false;
            curlyCount--;
            break;
        }
    }

    bool result = temp->isEmpty() and roundCount == 0 and squareCount == 0 and curlyCount == 0;
    delete temp;
    return result;
}