#ifndef STD
#define STD
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
#endif

#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST
    typedef struct Node {
    int value;
    struct Node* next;
    }   Node;

    typedef struct LinkedList {
        int nodeCount;
        Node* start;
        Node* end;
    } LinkedList;

    LinkedList* createLinkedList();
    void deleteLinkedList(LinkedList* linkedListPtr);
    void insertNode(LinkedList* linkedListPtr, int position, int value);
    void updateNode(LinkedList* linkedListPtr, int position, int newValue);
    void deleteNode(LinkedList* linkedListPtr, int position);
    void printLinkedList(LinkedList* linkedListPtr);
#endif

#ifndef POLYNOMIAL
#define POLYNOMIAL
    typedef struct Term {
        int factor;
        int exponent;
    } Term;

    typedef struct Polynomial {
        LinkedList* plinkedlist;
    } Polynomial;

    Polynomial* createPolynomial(Term* terms, size_t numOfTerms);
    Polynomial* multiplyPolynomialByFactor(Polynomial* polynomial, int factor);
    void printPolynomial(Polynomial* polynomial);
#endif