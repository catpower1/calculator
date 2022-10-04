#pragma once
#include <iostream>
#include "queue.h"
#include "stack.h"
using namespace std;

class MyList {
private:
    string* strings;
    int capacity;
    int currentIndex;
    int size;
public:
    MyList(int capacity = 3)
    {
        this->currentIndex = 0;
        this->capacity = capacity;
        this->size = capacity;
        strings = new string[this->size];

    }
    void addElement(string element)
    {
        if (currentIndex >= size)
        {
            string* tmp = new string[this->size + capacity];
            for (int i = 0; i < this->size; i++)
            {

                tmp[i] = this->strings[i];

            }
            this->strings = tmp;

            this->size += this->capacity;
        }
        this->strings[currentIndex] = element;

        currentIndex++;
    }
    string getElement(int index)
    {
        if (index < this->size)
            return this->strings[index];

    }
    int getSize()
    {
        return this->currentIndex;
    }
};
MyList transform(string expression)
{
    MyList list;
    string tmp;
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ') continue;
        if (expression[i] != '+' && expression[i] != '-' && expression[i] != '*' && expression[i] != '/' && expression[i] != '(' && expression[i] != ')') {
            tmp += expression[i];
            if (i == expression.length() - 1)
                list.addElement(tmp);
            continue;
        }
        else {
            if (tmp != "") {
                list.addElement(tmp);
            }
            tmp = expression[i];
            list.addElement(tmp);
        }
        tmp = "";
    }
    
    return list;
}