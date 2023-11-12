#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <ostream>

struct Node{
    int x;
    Node *link;
};

class stack_{
public:
    stack_(): top(NULL);
    ~stack_();

    void push(int x);
    void pop();

    const bool isEmpty() const;


private:
    Node *top;
};

~stack_(){
    Node *temp = top;
    while (top != NULL){
        top = top->link;
        delete temp;
    }
}

void push(int x){
    Node *temp = new Node;
    if (!temp) {
        cout << "\nStack Overflow";
        exit(1);
    }
    temp->x = x;
    temp->link = top;
    top = temp;
}

void pop(){
    Node *temp = top;
    top = top->link;
    delete temp;
}

const bool isEmpty() const{
    return top == NULL;
}

#endif // STACK_H_INCLUDED
