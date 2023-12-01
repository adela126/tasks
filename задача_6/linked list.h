#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

#include <ostream>

template <class T>
class linked_list{
public:
    virtual linked_list& push(T x) = 0;
    virtual linked_list& pop() = 0;
    virtual bool isEmpty() const = 0;
    virtual T& GetFront() = 0;
    virtual const T& GetFront() const = 0;
    virtual size_t size_() const = 0;
    virtual ~linked_list() {}

    class iterator{
    public:
        typedef typename linked_list<T>::Node Node;
        iterator(Node* p = NULL) : h(p) {}
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        T& operator * (){
            return h->x;
        }

        iterator operator ++ (){
            h = h->Next;
            return *this;
        }

        bool operator != (const iterator& r) const{
            return h != r.h;
        }

    private:

        Node* h;

    };

    class const_iterator{
    public:
        typedef typename linked_list<T>::Node Node;
        const_iterator(Node* p = NULL) : h(p) {}
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using pointer = const T*;
        using reference = const T&;
        const T& operator * ()const {
            return h->x;
        }

        const_iterator operator ++ (){
            h = h->Next;
            return *this;
        }

        const_iterator operator = (const iterator& r){
            h = r.h;
            return *this;
        }

        bool operator == (const iterator& r) const{
            return h == r.h;
        }

        bool operator == (const const_iterator& r) const{
            return h == r.h;
        }

        bool operator != (const const_iterator& r) const{
            return h != r.h;
        }

        bool operator != (const iterator& r) const{
            return h != r.h;
        }

        template <class U> friend std::ostream& operator << (std::ostream& out, const linked_list<U>& l){
            for (const auto &i: l)
                out << i << " ";
            return out;
        }

    virtual iterator begin() = 0;
    virtual iterator end() = 0;
    virtual const_iterator begin () const = 0;
    virtual const_iterator end() const = 0;


    private:

        Node* h;

    };

protected:
    struct Node{
        T x;
        Node *Next;
    };
};




#endif // LINKED_LIST_H_INCLUDED
