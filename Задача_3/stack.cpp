#include <istream>
#include <ostream>
#include <exception>
#include "stack.h"

using namespace std;

stack_& stack_::operator = (const stack_& orig){ //просваивание
    if(this == &orig) return *this;
    this->clean();
    Node **temp = &top;
    for (Node *n = orig.top; n; n = n->link){
        *temp = new Node;
        (*temp)->x = n->x;
        temp = &((*temp)->link);
    }
    return *this;
}

stack_& stack_::operator = (stack_&& orig){
    this->clean();

    top = orig.top;
    orig.top = NULL;
    return *this;
}

stack_::~stack_(){
    while (top != NULL){
        Node *temp = top->link;
        delete top;
        top = temp;
    }
}

stack_& stack_::push(int x){
    Node *temp = new Node;
    temp->x = x;
    temp->link = top;
    top = temp;
    return *this;
}

stack_& stack_::pop(){
    Node *temp = top;
    if (top == NULL){
        throw std::runtime_error("Removing an element from an empty stack");
    }
    top = top->link;
    delete temp;
    return *this;
}

const bool stack_::isEmpty() const{
    return top == NULL;
}

int& stack_::GetFront(){
    if (top) return (this->top->x);
    throw std::runtime_error("Getting an element from an empty stack");
}

const int& stack_::GetFront() const {
    if (top) return (this->top->x);
    throw std::runtime_error("Getting an element from an empty stack");
}

size_t stack_::size_() const {
    Node *st = top;
    size_t k = 0;
    while(st != NULL){
        k++;
        st = st -> link;
    }
    return k;
}

stack_& stack_::clean(){
    if (!top) return *this;

    Node *n = top, *n_next;
    while ((n_next = n->link)){
        delete n;
        n = n_next;
    }
    delete n;

    top = NULL;
    return *this;
}

std::ostream& operator << (std::ostream& out, const stack_& s){
    stack_::Node *temp = s.top;
    while (temp != NULL){
        out << temp->x << " ";
        temp = temp->link;
    }
    return out;
}

std::istream& operator >> (std::istream& in, stack_& s){
    int c;
    in >> c;
    s.push(c);
    return in;
}
