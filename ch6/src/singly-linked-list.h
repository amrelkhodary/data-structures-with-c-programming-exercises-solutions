#ifndef STD
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
#endif

#ifndef SINGLY_LINKED_LIST
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
