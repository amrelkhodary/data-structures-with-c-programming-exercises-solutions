#ifndef ERRORS
    #define ERRORS
    #define SUCCESSFUL 0
    #define MEMORY_ERROR 1
    #define INPUT_ERROR 2
#endif

#ifndef STD
    #define STD
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
#endif

#ifndef DOUBLY_LINKED_LIST_H
 #define DOULBY_LINKED_LIST_H

 #define TO_INSERT 10
 #define TO_UPDATE_OR_DELETE 20

 typedef struct Node {
     int value;
     struct Node* prev;
     struct Node* next;
 } Node;
 
 typedef struct DoublyLinkedList {
     Node* start;
     Node* end;
     int count;
 } DoublyLinkedList;
 
 DoublyLinkedList* createDoublyLinkedList();
 int deleteDoublyLinkedList(DoublyLinkedList* dlinkedlist);
 int insertNode(DoublyLinkedList* dlinkedlist, int position, int value);
 int updateNode(DoublyLinkedList* dlinkedlist, int position, int newValue);
 int deleteNode(DoublyLinkedList* dlinkedlist, int position);
 
 bool positionIsValid(int position, int objective, DoublyLinkedList* dlinkedlist);
 void printDoublyLinkedList(DoublyLinkedList* dlinkedlist);

#endif

