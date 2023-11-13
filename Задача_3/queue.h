#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <ostream>

using namespace std;

class queue_{
public:
    queue_(): Head(NULL), Tail(NULL){}
    ~queue_();

    queue_(const queue_& orig) : Head(NULL), Tail(NULL){
        for(Node *n = orig.Head; n; n = n->Next){
            this->push(n->x);
        }
    }

    queue_(queue_&& orig) : Head(orig.Head){
        orig.Head = NULL;
    }

    queue_ operator = (const queue_& orig){ //просваивание
        if(this == &orig) return *this;
        this->clean();
        for (Node *n = orig.Head; n; n = n->Next){
            this->push(n->x);
        }
        return *this;
    }

    queue_ operator = (queue_&& orig){ //оператор присваивания по перемещению
        this->clean();

        Head = orig.Head;
        orig.Head = NULL;
        return *this;
    }

    void push(int x);
    void pop();
    queue_& clean();
    int size_();

    friend std::ostream& operator << (std::ostream& out, const queue_&);
    friend std::istream& operator >> (std::istream& in, queue_&);

    const bool isEmpty() const;
    int* GetFront() const;

private:
    struct Node{
        int x;
        Node *Next;
    };
    Node *Head, *Tail;
};

queue_::~queue_(){
    while (Head != NULL){
        Node *temp = Head->Next;
        delete Head;
        Head = temp;
    }
}

void queue_::push(int x){
    Node *temp = new Node;
    temp->x = x;
    temp->Next = NULL;
    if (Head != NULL){
        Tail->Next = temp;
        Tail = temp;
    }
    else Head = Tail = temp;
}

void queue_::pop(){
    if (Head != 0){
        Node *temp = Head;
        Head = Head -> Next;
        delete temp;
    }
}

const bool queue_::isEmpty() const{
    return Head == NULL;
}

int* queue_::GetFront() const{
    return this->Head == NULL ? NULL : &(this->Head->x);
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

int queue_::size_(){
    Node *qu = Head;
    int k = 0;
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

#endif // QUEUE_H_INCLUDED
