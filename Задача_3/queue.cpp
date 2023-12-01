#include <iostream>
#include <ostream>
#include <exception>
#include "queue.h"

using namespace std;

queue_& queue_::operator = (const queue_& orig){
    if(this == &orig) return *this;
    this->clean();
    for (Node *n = orig.Head; n; n = n->Next){
        this->push(n->x);
    }
    return *this;
}

queue_& queue_::operator = (queue_&& orig){ //оператор присваивания по перемещению
    this->clean();

    Head = orig.Head;
    orig.Head = NULL;

    Tail = orig.Tail;
    orig.Tail = NULL;
    return *this;
}

queue_::~queue_(){
    while (Head != NULL){
        Node *temp = Head->Next;
        delete Head;
        Head = temp;
    }
}

queue_& queue_::push(int x){
    Node *temp = new Node;
    temp->x = x;
    temp->Next = NULL;
    if (Head != NULL){
        Tail->Next = temp;
        Tail = temp;
    }
    else Head = Tail = temp;
    return *this;
}

queue_& queue_::pop(){
    if (Head == NULL){ throw std::runtime_error("Getting an element from an empty stack"); }

    Node *temp = Head;
    Head = Head -> Next;
    delete temp;
    if (Head == NULL) { Tail = NULL; }
    return *this;

}

bool queue_::isEmpty() const{
    return Head == NULL;
}

int& queue_::GetFront(){
    if (Head) return (this->Head->x);
    throw std::runtime_error("Getting an element from an empty queue");
}

const int& queue_::GetFront() const {
    if (Head) return (this->Head->x);
    throw std::runtime_error("Getting an element from an empty queue");
}

queue_& queue_::clean(){
    if (!Head) return *this;

    Node *n = Head, *n_next;
    while ((n_next = n->Next)){
        delete n;
        n = n_next;
    }
    delete n;

    Head = NULL;
    return *this;
}

size_t queue_::size_() const{
    Node *qu = Head;
    size_t k = 0;
    while (qu != NULL){
        k++;
        qu = qu->Next;
    }
    return k;
}

std::ostream& operator << (std::ostream& out, const queue_& q){
    queue_::Node *temp = q.Head;
    while (temp != NULL){
        out << temp->x << " ";
        temp = temp->Next;
    }
    return out;
}

std::istream& operator >> (std::istream& in, queue_& q){
    int l;
    in >> l;
    q.push(l);
    return in;
}
