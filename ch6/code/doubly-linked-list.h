#ifndef DOUBLY_LINKED_LIST_H
#define DOULBY_LINKED_LIST_H

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
