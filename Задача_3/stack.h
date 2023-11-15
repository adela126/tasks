#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <ostream>
#include <exception>

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

    stack_& operator = (const stack_& orig); //присваивание

    stack_& operator = (stack_&& orig); //оператор присваивания по перемещению

    stack_& push(int x);
    stack_& pop();
    stack_& clean();
    size_t size_() const;

    const bool isEmpty() const;
    int& GetFront();
    const int& GetFront() const;

    friend std::ostream& operator << (std::ostream& out, const stack_&);
    friend std::istream& operator >> (std::istream& in, stack_&);

private:
    struct Node{
        int x;
        Node *link;
    };
    Node *top;
};

#endif // STACK_H_INCLUDED
