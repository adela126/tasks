#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "linked list.h"
#include<initializer_list>

template <class T>
class queue_: public linked_list<T>{
public:
    queue_(): Head(NULL), Tail(NULL){}
    ~queue_();

    queue_(const queue_& orig) : Head(NULL), Tail(NULL){
        for(Node *n = orig.Head; n; n = n->Next){
            this->push(n->x);
        }
    }
    typedef typename linked_list<T>::iterator iterator;
    typedef typename linked_list<T>::const_iterator const_iterator;
    iterator begin(){
        return iterator(Head);
    }
    iterator end(){
        return iterator();
    }
    const_iterator begin() const {
        return const_iterator(Head);
    }
    const_iterator end() const{
        return const_iterator();
    }

    queue_(const std::initializer_list<T> l) : Head(NULL), Tail(NULL){
        for (typename std::initializer_list<T>::iterator i = l.begin(); i != l.end(); ++i)
            push(*i);
    }

    queue_(queue_&& orig) : Head(orig.Head), Tail(orig.Tail){
        orig.Head = NULL;
        orig.Tail = NULL;
    }

    queue_& operator = (const queue_& orig); //присваивание

    queue_& operator = (queue_&& orig); //оператор присваивания по перемещению

    queue_& push(T x);
    queue_& pop();
    queue_& clean();
    size_t size_() const;

    bool isEmpty() const;
    T& GetFront();
    const T& GetFront() const;

private:
    typedef typename linked_list<T>::Node Node;
    Node *Head, *Tail;
};

template <class T>
queue_<T>& queue_<T>::operator = (const queue_& orig){
    if(this == &orig) return *this;
    this->clean();
    for (Node *n = orig.Head; n; n = n->Next){
        this->push(n->x);
    }
    return *this;
}

template <class T>
queue_<T>& queue_<T>::operator = (queue_&& orig){ //оператор присваивания по перемещению
    this->clean();

    Head = orig.Head;
    orig.Head = NULL;

    Tail = orig.Tail;
    orig.Tail = NULL;
    return *this;
}

template <class T>
queue_<T>::~queue_<T>(){
    while (Head != NULL){
        Node *temp = Head->Next;
        delete Head;
        Head = temp;
    }
}

template <class T>
queue_<T>& queue_<T>::push(T x){
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

template <class T>
queue_<T>& queue_<T>::pop(){
    if (Head == NULL){ throw std::runtime_error("Getting an element from an empty stack"); }

    Node *temp = Head;
    Head = Head -> Next;
    delete temp;
    if (Head == NULL) { Tail = NULL; }
    return *this;

}

template <class T>
bool queue_<T>::isEmpty() const{
    return Head == NULL;
}

template <class T>
T& queue_<T>::GetFront(){
    if (Head) return (this->Head->x);
    throw std::runtime_error("Getting an element from an empty queue");
}

template <class T>
const T& queue_<T>::GetFront() const {
    if (Head) return (this->Head->x);
    throw std::runtime_error("Getting an element from an empty queue");
}

template <class T>
queue_<T>& queue_<T>::clean(){
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

template <class T>
size_t queue_<T>::size_() const{
    Node *qu = Head;
    size_t k = 0;
    while (qu != NULL){
        k++;
        qu = qu->Next;
    }
    return k;
}

/*

template <class U> std::istream& operator >> (std::istream& in, queue_<U>& q){
    U l;
    in >> l;
    q.push(l);
    return in;
}
*/
#endif // QUEUE_H_INCLUDED
