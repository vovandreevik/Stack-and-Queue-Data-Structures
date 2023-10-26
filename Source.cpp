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
    std::cout << "Stack testing\n";
    try
    {
        StackArray<int> intStack(-3);

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

        StackArray<std::string> stringStack(2);

        stringStack.push("a");
        stringStack.push("b");
        stringStack.push("c");
        std::cout << std::endl;

        while (!stringStack.isEmpty())
        {
            std::cout << stringStack.pop() << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(-1);
    }

    //function
    std::cout << "\nFunction testing\n";
    std::string text = "[a{b]c}(d)";
    int maxDeep = 3;

    bool isBalanced = checkBalanceBrackets(text, maxDeep);

    std::cout << text <<(isBalanced ? " is balanced" : " is not balanced") << std::endl;

    std::string text1 = "{a[b]c}(d)";
    int maxDeep1 = 3;

    bool isBalanced1 = checkBalanceBrackets(text1, maxDeep1);

    std::cout << text1 << (isBalanced1 ? " is balanced" : " is not balanced") << std::endl;

    std::string text2 = "{a[b]c}(d)[";
    int maxDeep2 = 3;

    bool isBalanced2 = checkBalanceBrackets(text2, maxDeep2);

    std::cout << text2 << (isBalanced2 ? " is balanced" : " is not balanced") << std::endl;

    //QueueArray
    std::cout << "\nQueue testing\n";
    try {
        QueueArray<int> queue(-3);
        queue.enQueue(1);
        queue.enQueue(2);
        queue.enQueue(3);
        while (!queue.isEmpty()) {
            std::cout << queue.deQueue() << " ";
        }
        std::cout << std::endl;
        queue.deQueue();
        std::cout << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
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