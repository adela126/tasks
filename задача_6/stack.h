#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "linked list.h"

template <class T>
class stack_: public linked_list<T>{
public:
    stack_(): top(NULL) {};
    ~stack_();

    stack_(const stack_& orig) : top(NULL){
        Node **temp = &top;
        for (Node *n = orig.top; n; n = n->Next){
            *temp = new Node;
            (*temp)->x = n->x;
            temp = &((*temp)->Next);
        }
        *temp = NULL;
    }

    typedef typename linked_list<T>::iterator iterator;
    typedef typename linked_list<T>::const_iterator const_iterator;
    iterator begin(){
        return iterator(top);
    }
    iterator end(){
        return iterator();
    }
    const_iterator begin() const {
        return const_iterator(top);
    }
    const_iterator end() const{
        return const_iterator();
    }

    const_iterator cbegin() const {
        return const_iterator(top);
    }
    const_iterator cend() const{
        return const_iterator();
    }

    stack_(const std::initializer_list<T> l) : top(NULL){
        for (typename std::initializer_list<T>::iterator i = l.begin(); i != l.end(); ++i)
            push(*i);
    }

    stack_(stack_&& orig) : top(orig.top){ // && так обозначается ссылка, которая хранит временный объект.
        orig.top = NULL; //конструктор перемещения
    }

    stack_& operator = (const stack_& orig); //присваивание

    stack_& operator = (stack_&& orig); //оператор присваивания по перемещению

    stack_& push(T x);
    stack_& pop();
    stack_& clean();
    size_t size_() const;

    bool isEmpty() const;
    T& GetFront();
    const T& GetFront() const;

private:
    typedef typename linked_list<T>::Node Node;
    Node *top;
};

template <class T>
stack_<T>& stack_<T>::operator = (const stack_& orig){ //просваивание
    if(this == &orig) return *this;
    this->clean();
    Node **temp = &top;
    for (Node *n = orig.top; n; n = n->Next){
        *temp = new Node;
        (*temp)->x = n->x;
        temp = &((*temp)->Next);
    }
    *temp = NULL;
    return *this;
}

template <class T>
stack_<T>& stack_<T>::operator = (stack_&& orig){
    this->clean();

    top = orig.top;
    orig.top = NULL;
    return *this;
}

template <class T>
stack_<T>::~stack_<T>(){
    while (top != NULL){
        Node *temp = top->Next;
        delete top;
        top = temp;
    }
}

template <class T>
stack_<T>& stack_<T>::push(T x){
    Node *temp = new Node;
    temp->x = x;
    temp->Next = top;
    top = temp;
    return *this;
}

template <class T>
stack_<T>& stack_<T>::pop(){
    Node *temp = top;
    if (top == NULL){
        throw std::runtime_error("Removing an element from an empty stack");
    }
    top = top->Next;
    delete temp;
    return *this;
}

template <class T>
bool stack_<T>::isEmpty() const{
    return top == NULL;
}

template <class T>
T& stack_<T>::GetFront(){
    if (top) return (this->top->x);
    throw std::runtime_error("Getting an element from an empty stack");
}

template <class T>
const T& stack_<T>::GetFront() const {
    if (top) return (this->top->x);
    throw std::runtime_error("Getting an element from an empty stack");
}

template <class T>
size_t stack_<T>::size_() const {
    Node *st = top;
    size_t k = 0;
    while(st != NULL){
        k++;
        st = st ->Next;
    }
    return k;
}

template <class T>
stack_<T>& stack_<T>::clean(){
    if (!top) return *this;

    Node *n = top, *n_next;
    while ((n_next = n->  Next)){
        delete n;
        n = n_next;
    }
    delete n;

    top = NULL;
    return *this;
}

#endif // STACK_H_INCLUDED
