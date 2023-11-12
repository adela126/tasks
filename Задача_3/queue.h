#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <ostream>

struct Node{
    int x;
    Node *Next;
};

class queue_{
public:
    queue_(): Head(NULL), Tail(NULL){}
    ~queue_();

    void push(int x);
    void pop();

    friend std::ostream& operator << (std::ostream& out, const queue_&);
    friend std::istream& operator >> (std::istream& in, const queue_&);

    const bool isEmpty() const;
    const int GetFront() const;

private:
    Node *Head, *Tail;
};

~queue_(){
    Node *temp = Head;
    while (Head != NULL){
        temp = Head -> Next;
        delete Head;
        Head = temp;
    }
}

void push(int x){
    Node *temp = new Node;
    if (!temp) {
        cout << "\nStack Overflow";
        exit(1);
    }
    temp->x = x;
    temp->Next = NULL;
    if (Head != NULL){
        Tail->Next = temp;
        Tail = temp;
    }
    else Head = Tail = temp;
}

void pop(){
    if (Head != 0){
        Node *temp = Head;
        Head = Head -> Next;
        delete temp;
    }
}

const bool isEmpty() const{
    return Head == NULL;
}

const int GetFront() const{
    return *this->Head == NULL ? NULL : &(*this->Head->x);
}

std::ostream& operator << (std::ostream& out, const queue_& q){
    Node *temp = Head;
    while (temp != NULL){
        out << temp->x << " ";
        temp = temp->Next;
    }
    return out;
}

std::istream& operator >> (std::istream& in, const queue_& q){
    int q;
    in >> q;
    push(q);
}

#endif // QUEUE_H_INCLUDED
