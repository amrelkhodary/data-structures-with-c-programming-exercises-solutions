#ifndef STACKLL_H
#define STACKLL_H

    #include "dlinkedlist.h"

    /*
        defining the linkedlist stack type that will be based on 
        the doubly linkedlist.
        It has two fields, the doubly linked list and the ptr to the current node
    */
    typedef struct Stackll {
        DoublyLinkedList* sdlinkedlist;
        Node* current;
        int size;
    } Stackll;

    /**
     * function to allocate memory for a new stack implemented with a linkedlist
     */
    Stackll* createStackll();

    /*
        function to free the memory allocated previously for a linkedlist stack
     */
    int deleteStackll(Stackll* stackllptr);

    /*
        function to push a new element into a linkedlist stack
    */
    int push(Stackll* stackllptr, int value);

    /*
        function to pop an element off a linkedlist stack
    */
    int pop(Stackll* stackllptr);

    /*
        function to get the current element from a linkedlist stack
    */
    int get(Stackll* stackllptr);

    /*
        function that prints all the information about a linkedlist stack
        (FOR DEBUGGING PURPOSES ONLY)
    */
    void debug_printStackll(Stackll* stackllptr);

#endif