#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <ostream>

using namespace std;

class stack_{
public:
    stack_(): top(NULL) {};
    ~stack_();

    stack_(const stack_& orig) : top(NULL){
        Node **temp = &top;
        for (Node *n = orig.top; n; n = n->link){
            *temp = new Node;
            (*temp)->x = n->x;
            temp = &((*temp)->link);

        }
        *temp = NULL;
    }

    stack_(stack_&& orig) : top(orig.top){ // && так обозначается ссылка, которая хранит временный объект.
        orig.top = NULL; //конструктор перемещения
    }

    stack_ operator = (const stack_& orig){ //просваивание
        if(this == &orig) return *this;
        this->clean();
        for (Node *n = orig.top; n; n = n->link){
            this->push(n->x);
        }
        return *this;
    }

    stack_ operator = (stack_&& orig){ //оператор присваивания по перемещению
        this->clean();

        top = orig.top;
        orig.top = NULL;
        return *this;
    }

    void push(int x);
    void pop();
    int peek();
    stack_& clean();
    int size_();

    const bool isEmpty() const;
    int* GetFront() const;

    friend std::ostream& operator << (std::ostream& out, const stack_&);
    friend std::istream& operator >> (std::istream& in, stack_&);

private:
    struct Node{
        int x;
        Node *link;
    };
    Node *top;
};

stack_::~stack_(){
    while (top != NULL){
        Node *temp = top->link;
        delete top;
        top = temp;
    }
}

void stack_::push(int x){
    Node *temp = new Node;
    temp->x = x;
    temp->link = top;
    top = temp;
}

void stack_::pop(){
    Node *temp = top;
    top = top->link;
    delete temp;
}

int stack_::peek(){
    if(!isEmpty()){
        return top -> x;
    }
    else exit(1);
}

const bool stack_::isEmpty() const{
    return top == NULL;
}

int* stack_::GetFront() const{
    return this->top == NULL ? NULL : &(this->top->x);
}

int stack_::size_(){
    Node *st = top;
    int k = 0;
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

#endif // STACK_H_INCLUDED
