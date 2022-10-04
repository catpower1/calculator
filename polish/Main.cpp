#include <iostream>
#include <string>
#include "mylist.h"
#include "queue.h"
#include "stack.h"
using namespace std;

void rule1(MyList list, int& index, Stack<string>& texas, Queue<string>& california) {
    texas.push(list.getElement(index));
}

void rule2(MyList list, int& index, Stack<string>& texas, Queue<string>& california) {
    string tmp = texas.pop();
    california.push(tmp);
    index--;
}

void rule3(MyList list, int& index, Stack<string>& texas, Queue<string>& california) {
    texas.pop();
}

void rule4(MyList list, int& index, Stack<string>& texas, Queue<string>& california) {
    
}
void rule5(MyList list, int& index, Stack<string>& texas, Queue<string>& california) {
    cerr << "incorrect" << endl;
    index = list.getSize();
    while (texas.empty() == false) {
        texas.pop();
    }
    while (california.empty() == false) {
        california.pop();
    }
}

int decode(string elem) {
    if (elem == "&")
        return 0;
    else if (elem == "+")
        return 1;
    else if (elem == "-")
        return 2;
    else if (elem == "*")
        return 3;
    else if (elem == "/")
        return 4;
    else if (elem == "(")
        return 5;
    else if (elem == ")")
        return 6;
}

void p(MyList list, Stack<string>& texas, Queue<string>& california) {
    void(*Rules[6][7])(MyList,int&,Stack<string>&,Queue<string>&);
    texas.push("&");
    int i = 0;
    Rules[0][0] = rule4;    Rules[0][1] = rule1;    Rules[0][2] = rule1;    Rules[0][3] = rule1;    Rules[0][4] = rule1;    Rules[0][5] = rule1;    Rules[0][6] = rule5;
    Rules[1][0] = rule2;    Rules[1][1] = rule2;    Rules[1][2] = rule2;    Rules[1][3] = rule1;    Rules[1][4] = rule1;    Rules[1][5] = rule1;    Rules[1][6] = rule2;
    Rules[2][0] = rule2;    Rules[2][1] = rule2;    Rules[2][2] = rule2;    Rules[2][3] = rule1;    Rules[2][4] = rule1;    Rules[2][5] = rule1;    Rules[2][6] = rule2;
    Rules[3][0] = rule2;    Rules[3][1] = rule2;    Rules[3][2] = rule2;    Rules[3][3] = rule2;    Rules[3][4] = rule2;    Rules[3][5] = rule1;    Rules[3][6] = rule2;
    Rules[4][0] = rule2;    Rules[4][1] = rule2;    Rules[4][2] = rule2;    Rules[4][3] = rule2;    Rules[4][4] = rule2;    Rules[4][5] = rule1;    Rules[4][6] = rule2;
    Rules[5][0] = rule5;    Rules[5][1] = rule1;    Rules[5][2] = rule1;    Rules[5][3] = rule1;    Rules[5][4] = rule1;    Rules[5][5] = rule1;    Rules[5][6] = rule3;
    for (; i < list.getSize(); i++) {
         if (list.getElement(i) == "&"
             || list.getElement(i) == "+"
             || list.getElement(i) == "-"
             || list.getElement(i) == "*"
             || list.getElement(i) == "/"
             || list.getElement(i) == "("
             || list.getElement(i) == ")") {
             Rules[decode(texas.peek())][decode(list.getElement(i))](list, i, texas, california);
         }
         else if (list.getElement(i) != "&"
                  && list.getElement(i) != "+"
                  && list.getElement(i) != "-"
                  && list.getElement(i) != "*"
                  && list.getElement(i) != "/"
                  && list.getElement(i) != "("
                  && list.getElement(i) != ")") {
                  california.push(list.getElement(i));
              }      
    }
    if (texas.empty() == true) return;
    while (texas.peek() != "&")
      rule2(list,i, texas, california);
}

float calculate(Queue<string>& cali)
{
    if (cali.empty() == true) return 0;
    float numbers[3]{ 0,0,0 };
    for (int i = 0; cali.empty() == false;)
    {
        if (cali.peek() == "+") 
        {
            i--;
            numbers[i - 1] += numbers[i];
            cali.pop();
            
        }
        else if (cali.peek() == "-") 
        {
            i--;
            numbers[i - 1] -= numbers[i];
            cali.pop();
            
        }
        else if (cali.peek() == "*")         
        {
            i--;
            numbers[i - 1] *= numbers[i];
            cali.pop();
            
        }
        else if(cali.peek() == "/") {
            i--;
            numbers[i - 1] /= numbers[i];
            cali.pop();
            
        }
        else {
            numbers[i] = stof(cali.pop());
            i++;
        }

    }
    return numbers[0];
}

int main() {
    Stack<string> stack;
    Queue<string> queue;
    MyList list;
    list = transform("11+22-(999-888)/77");
    p(list, stack, queue);
    // while для перервірки запису
   /* while (queue.empty() == false) {
        cout << queue.pop() << ' '  << endl;

    }*/

    cout << calculate(queue) << endl; // cout для перевірки розрахунку

}


