//
// Created by Daniel Bulhosa Solorzano on 1/30/21.
//

#ifndef EXERCISE11_8_LI_H
#define EXERCISE11_8_LI_H

#include <cstdlib>

template<class T>
class Li {
public:
    struct Node {
        Node(): val(T()), next(0), previous(0) {};
        Node(T t, Node* n, Node* p): val(t), next(n), previous(p) {};
        T val;
        Node* next;
        Node* previous;

    };

    class iterator{
    public:
        iterator(): nodeptr(0) {};
        explicit iterator(Node* ptr): nodeptr(ptr) {}; // Avoid implicit usage through assigment operator
        // prefix -- returns copy of current (next) object.
        // Get next pointer from current node data member.
        // Set pointer value for this iterator object to that
        // of next node.
        iterator& operator++() {nodeptr = nodeptr -> next; return *this;};
        // postfix -- returns copy of previous object
        iterator operator++(int) {iterator temp = *this; nodeptr = nodeptr -> next; return temp;};
        iterator& operator--() {nodeptr = nodeptr -> previous; return *this;};
        iterator operator--(int) {iterator temp = *this; nodeptr = nodeptr -> previous; return temp;};
        T& operator*() {return nodeptr -> val;}; // Reference so value can be updated
        bool operator==(iterator it){return this -> nodeptr == it.nodeptr;};
        bool operator!=(iterator it){return this -> nodeptr != it.nodeptr;};
        Node* get_pointer() {return nodeptr;}

    private:
        Node* nodeptr;
    };
    typedef const iterator const_iterator;
    typedef T& referece;
    typedef const T& const_reference;
    typedef T value_type;
    typedef std::size_t size_type; // Not really sure this makes sense for this list, but it seems like a decent starting point

    Li() {create();};
    Li(size_type n, value_type t) {create(n, t);};
    Li(iterator b, iterator e) {create(b, e);};
    Li(const Li& list); // copy constructor
    Li& operator=(const Li&); // assignment operator
    ~Li() {uncreate();}; //destructor

    iterator begin() {return iterator(start);};
    const_iterator begin() const {return iterator(start);};
    iterator end() {return iterator(finish);};
    const_iterator end() const {return iterator(finish);};
    size_type size() {return listsize;};
    void push_back(T);
    void insert(T, iterator);
    void erase(iterator);
    void erase(iterator, iterator);
    void clear();


private:
    Node* start;
    Node* finish;
    size_type listsize{};

    void create();
    Node* first_node(T);
    Node* next_node(Node*, T );
    void final_node(Node*);
    void create(size_type, value_type);
    void create(iterator, iterator);
    void uncreate();

};

/*
 * Invariant: start always points to first element in
 * list and listsize always describes the number of nodes
 * in the list. finish points to one past the last element,
 * whose `next` pointer is the null pointer to denote is
 * one past last.
 */

template<class T>
void Li<T>::create(){
    // Since start and finish nodes are equal and
    // both have `next` equal to zero they are the
    // end node.
    final_node(0);
    start = finish;
    listsize = 0;
};


template<class T>
typename Li<T>::Node* Li<T>::first_node(T t){
    // Create the first node in list, set start and listsize properties
    start = new Node(t, 0, 0); // new makes the definition of this variable persistent
                               // Note that `new` returns a pointer to the object we create!
    listsize = 1;

    return start;
}

template<class T>
typename Li<T>::Node* Li<T>::next_node(Node* previous_node, T t){
    // Inject next node in sequence, increment listsize appropriately
    Node* next_node =  new Node(t, 0, previous_node);
    previous_node -> next = next_node; // Note that `new` returns a pointer to the object we create!
    listsize += 1;
    return next_node;
}

template<class T>
void Li<T>::final_node(Node* previous_node){
    // Create terminal "null" node, which is defined by having next = 0
    finish = new Node(T(), 0, previous_node); // Note that `new` returns a pointer to the object we create!
    if(previous_node != 0){
        previous_node -> next = finish;
    }
}


template<class T>
void Li<T>::create(size_type n , value_type t){
    if(n == 0){
        create();
    }

    // We use pointers to "change variable meaning" without changing "underlying value."
    // If we had made previous_node into a value rather than pointer we would have accidentally
    // changed the value of the previous node.
    Node* previous_node = first_node(t);

    for(size_type i = 0; i != n - 1; ++i){
        previous_node = next_node(previous_node, t);
    }

    final_node(previous_node);
};


template<class T>
void Li<T>::create(iterator b, iterator e){
    if(b == e){
        create(); // Case of empty list
    }

    // Same as setting with constant value but we set
    // with dereferenced value instead!
    Node* previous_node = first_node(*b);

    for(iterator i = ++b; i != e; ++i){
        previous_node = next_node(previous_node, *i);
    }

    final_node(previous_node);
};

template<class T>
void Li<T>::uncreate(){
    if(listsize == 0){
        return;
    }

    // Goes through each node and deletes it, including terminal "null" node
    Node* nextptr = start;
    while(nextptr != 0){
        Node& current_node = *nextptr;  // Needs to be a reference so that we don't copy into new object
        nextptr = current_node.next;
        delete &current_node; // Note that delete must be used with a pointer!
    }
    start = 0; listsize = 0;
};

template<class T>
Li<T>::Li(const Li& list){ // copy constructor
    create(list.begin(), list.end());
};

template<class T>
Li<T>& Li<T>::operator=(const Li& list){ // assignment operator
    // Handles self reference
    if(&list != this){
        // Same as what worked for list should work
        // Just erase what we have and recreate with the
        // contents of the list passed!
        uncreate();
        create(list.begin(), list.end());
    }

    return *this;
};

template<class T>
void Li<T>::push_back(T t){
    insert(t, end()); // Insert before "one past last" element. Having "null" node makes this a lot easier
};

template<class T>
void Li<T>::insert(T t, iterator i){
    Node* next_node = i.get_pointer(); // Maybe within enclosing class scope private members are accessible?
    // Note that if list is empty, previous of null node is `0`.
    // That means previous of new (now first) node will be zero,
    // which is what we want!
    Node* previous_node = next_node -> previous;

    // Create new node in between node passed and node before it!
    Node* new_node = new Node(t, next_node, previous_node);
    next_node -> previous = new_node;
    // Danger -- would have gotten null pointer error otherwise if there is no previous node!
    if(previous_node != 0){
        previous_node -> next = new_node;
    }
    else{
        // New node is first node!
        start = new_node;
    }
    listsize += 1;
};

template<class T>
void Li<T>::erase(iterator i){
    iterator b = i; ++i;
    erase(b, i);
};

template<class T>
void Li<T>::erase(iterator b, iterator e){
    // Erase values in open interval [b, e)
    Node* previous_node = b.get_pointer() -> previous;
    Node* next_node = e.get_pointer();

    for(iterator i = b; i != e; ++i){
        delete i.get_pointer();
        listsize -= 1;
    }

    // Link node before first erased to node after last erased!
    // Note this works even if b is first node, because then
    // `previous_node` is zero!
    next_node -> previous = previous_node;

    // Danger -- would have gotten null pointer error otherwise if there is no previous node!
    if(previous_node != 0) {
        previous_node -> next = next_node;
    }
    else{
        // e is now the first node! b must have been first node before erasing!
        start = next_node;
    }
};

template<class T>
void Li<T>::clear(){
    // Should work as well as it did in vec.
    // Only side effect will be that original list
    // position will be lost.
    uncreate();
    create();
};



#endif //EXERCISE11_8_LI_H
