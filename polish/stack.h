#pragma once
#include <iostream>
using namespace std;
template<typename T>
struct Point {
	T info;
	Point* next;
};

template<typename T>
class Stack
{
private:
    Element<T>* top;
public:
    Stack() :top{ nullptr }
    {

    }
    ~Stack()
    {
        if (top != nullptr)
        {
            Element<T>* tmp = top;
            while (top)
            {
                tmp = top->next;
                delete top;
                top = tmp;

            }


        }
    }
    void push(T info)
    {
        Element<T>* element = new Element<T>;
        element->info = info;
        element->next = top;
        top = element;
    }
    T peek()
    {
        if (top != nullptr)
        {
            return top->info;
        }
    }
    T pop()
    {
        if (top != nullptr)
        {
            Element<T>* tmp = top;

            top = tmp->next;
            T value = tmp->info;
            delete tmp;
            return value;

        }
    }
    bool empty()
    {
        return (top == nullptr) ? true : false;
    }
    Element<T>* getTop()const
    {
        return this->top;
    }
};