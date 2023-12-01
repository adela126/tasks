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

    queue_(queue_&& orig) : Head(orig.Head), Tail(orig.Tail){
        orig.Head = NULL;
        orig.Tail = NULL;
    }

    queue_& operator = (const queue_& orig); //присваивание

    queue_& operator = (queue_&& orig); //оператор присваивания по перемещению

    queue_& push(int x);
    queue_& pop();
    queue_& clean();
    size_t size_() const;

    friend std::ostream& operator << (std::ostream& out, const queue_&);
    friend std::istream& operator >> (std::istream& in, queue_&);

    bool isEmpty() const;
    int& GetFront();
    const int& GetFront() const;

private:
    struct Node{
        int x;
        Node *Next;
    };
    Node *Head, *Tail;
};

#endif // QUEUE_H_INCLUDED
