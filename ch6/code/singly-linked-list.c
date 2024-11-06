#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

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

int main() {
   
}

void printLinkedList(LinkedList* linkedListPtr) {
    Node* currentNodePtr = linkedListPtr -> start;
    int i = 1;
    while(currentNodePtr != NULL) {
        printf("node: %i, value: %i\n", i, currentNodePtr -> value);
        currentNodePtr = currentNodePtr -> next;
        i++;
    }

    printf("\n\n");
}

LinkedList* createLinkedList() {
    LinkedList* newLinkedListPtr = (LinkedList*) malloc(sizeof(LinkedList));
    newLinkedListPtr -> nodeCount = 0;
    newLinkedListPtr -> start = NULL;
    newLinkedListPtr -> end = NULL;
    return newLinkedListPtr;
}

void deleteLinkedList(LinkedList* linkedListPtr) {
    //declare an array to store the ptrs to all nodes in the linkedlist
    Node* ptrsToNodes[linkedListPtr -> nodeCount];

    //move through the linkedlist to add the pointers to the nodes to the array
    Node* currentNodePtr = linkedListPtr -> start;
    int i = 0;
    while(currentNodePtr != NULL) {
        ptrsToNodes[i] = currentNodePtr;
        currentNodePtr = currentNodePtr -> next;
        i++;
    }

    //free those pointers one by one 
    for(int i = 0; i<linkedListPtr -> nodeCount; i++) {
        free(ptrsToNodes[i]);
        ptrsToNodes[i] = NULL; //it's best practice to set any pointer to a mem location you freed to NULL
    }

    //finally free the linkedlist pointer itself
    free(linkedListPtr);
    linkedListPtr = NULL;
}

void insertNode(LinkedList* linkedListPtr, int position, int value) {
    //create the new node
    Node* newNodePtr = (Node*) malloc(sizeof(Node));
    newNodePtr -> value = value;

    if(linkedListPtr -> nodeCount == 0) {
        //linkedlist empty, set start to be the new node
        linkedListPtr -> start = newNodePtr;
        newNodePtr -> next = NULL;
    } else {
        if(position == 0) {
            Node* afterPtr = linkedListPtr -> start;
            linkedListPtr -> start = newNodePtr;
            newNodePtr -> next = afterPtr;
        }
        else {
            //move to the before ptr
            Node* currentNode = linkedListPtr -> start;
            for(int i = 0; i< position - 1; i++) {
                currentNode = currentNode -> next;
            }

            if(currentNode -> next == NULL) {
                //before ptr is the last ptr, user want to append new node to linekdlist 
                currentNode -> next = newNodePtr;
                newNodePtr -> next = NULL;
            } else {
                Node* afterPtr = currentNode -> next;
                currentNode -> next = newNodePtr;
                newNodePtr -> next = afterPtr;
            }
        }
    }

    linkedListPtr -> nodeCount++;
}

void updateNode(LinkedList* linkedListPtr, int position, int newValue) {
    Node* toBeUpdatedPtr = linkedListPtr -> start;
    for(int i = 0; i<position; i++) {
        toBeUpdatedPtr = toBeUpdatedPtr -> next;
    }

    toBeUpdatedPtr -> value = newValue;
}

void deleteNode(LinkedList* linkedListPtr, int position) {
    if(linkedListPtr -> nodeCount == 1) {
        free(linkedListPtr -> start);
        linkedListPtr -> start = NULL;
    } else {
        if(position == 0) {
            Node* afterPtr = linkedListPtr -> start -> next;
            free(linkedListPtr -> start);
            linkedListPtr -> start = afterPtr;
        } else {
            //navigate to the node before the one to be deleted
            Node* beforePtr = linkedListPtr -> start;
            for(int i = 0; i<position - 1; i++) {
                beforePtr = beforePtr -> next;
            }

            if(beforePtr -> next -> next == NULL) {
                free(beforePtr -> next);
                beforePtr -> next = NULL;
            } else {
                Node* afterPtr = beforePtr -> next -> next;
                free(beforePtr -> next);
                beforePtr -> next = afterPtr;
            }

        }
    }

    linkedListPtr -> nodeCount--;
}