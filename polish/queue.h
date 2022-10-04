#pragma once
#include <iostream>
using namespace std;

template<typename T>
struct Element
{
    T info;
    Element<T>* next;

};
template<typename T>
class Queue
{
private:
    Element<T>* head;
    Element<T>* tail;
public:
    Queue()
    {
        head = tail = nullptr;
    }
    Element<T>* getHead()const
    {
        return this->head;
    }
    Element<T>* getTail()const
    {
        return this->tail;
    }
    void push(T info)
    {
        Element<T>* tmp = new Element<T>;
        tmp->info = info;
        if (head == nullptr)
        {
            head = tmp;
            head->next = nullptr;
            tail = head;
        }
        else
        {
            tail->next = tmp;
            tmp->next = nullptr;
            tail = tmp;
        }
    }
    T pop()
    {
        if (head != nullptr)
        {
            T info = head->info;
            Element<T>* tmp = head;
            head = head->next;
            delete tmp;
            return info;
        }

    }

    T peek() {
        if (head != nullptr) {
            return head->info;
        }
    }
    bool empty()
    {
        return (head == nullptr) ? true : false;
    }

};