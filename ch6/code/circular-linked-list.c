#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* start;
    Node* end;
    int numOfNodes;
} CircularLinkedList;

CircularLinkedList* createCircularLinkedList();
void deleteCircularLinkedList(CircularLinkedList* clinkedlistPtr);
void insertNode(CircularLinkedList* clinkedlistPtr, int position, int value);
void updateNode(CircularLinkedList* clinkedlistPtr, int position, int newValue);
void deleteNode(CircularLinkedList* clinkedlistPtr, int position);
void printCircularLinkedList(CircularLinkedList* clinkedlistPtr);

int main() {
    //play with the circular linked list here :)
}

CircularLinkedList* createCircularLinkedList() {
    //dynamically allocate memory for the new circular linked list
    CircularLinkedList* clinkedlistPtr = (CircularLinkedList*) malloc(sizeof(CircularLinkedList));

    //set the initial values for the clinkedlist
    clinkedlistPtr -> start = NULL;
    clinkedlistPtr -> numOfNodes = 0;

    return clinkedlistPtr;
}

void deleteCircularLinkedList(CircularLinkedList* clinkedlistPtr) {
    Node *nodeToDelete = clinkedlistPtr -> start;
    Node *nextNode;
    while(clinkedlistPtr -> numOfNodes > 0) {
        //delete all the nodes
        if(clinkedlistPtr -> numOfNodes > 1) {
            nextNode = nodeToDelete -> next;
        }
        printf("deleteing node with value %i...\n", nodeToDelete -> value);
        free(nodeToDelete);
        nodeToDelete = nextNode;
        clinkedlistPtr -> numOfNodes--;
    }

    free(clinkedlistPtr);
    clinkedlistPtr = NULL;
}

void printCircularLinkedList(CircularLinkedList* clinkedlistPtr) {
    int count = clinkedlistPtr -> numOfNodes;
    Node* currentNodePtr = clinkedlistPtr -> start;
    int i = 0;
    while(count > 0) {
        count--;
        printf("Node %i: %i\n", i, currentNodePtr -> value);
        currentNodePtr = currentNodePtr -> next;
        i++;
    } 
}

void insertNode(CircularLinkedList* clinkedlistPtr, int position, int value) {
    Node *newNodePtr = (Node*) malloc(sizeof(Node));
    Node* temp; //used for operations throughout the function
    newNodePtr -> value = value;

    if(!(position >=0 && position <= clinkedlistPtr -> numOfNodes)) {
        printf("ERROR: Invalid position %i passed to insertNode().\nLegal positions are 0..%i\n", 
        position, clinkedlistPtr -> numOfNodes);

    } else {
        if(position == 0) {
            if(clinkedlistPtr -> numOfNodes == 0) {
                clinkedlistPtr -> start = newNodePtr;
                newNodePtr -> next = clinkedlistPtr -> start;
                clinkedlistPtr -> end = newNodePtr;
            }
            else {
                temp = clinkedlistPtr -> start;
                clinkedlistPtr -> start = newNodePtr;
                newNodePtr -> next = temp;
                temp = NULL;
            }
            
        }
        else {
            temp = clinkedlistPtr -> start;
             //move to the node before the one to be inserted
            for(int i = 0; i<position-1; i++) {
                temp = temp -> next;
            }

            newNodePtr -> next = temp -> next;
            temp -> next = newNodePtr;
            if(position == clinkedlistPtr -> numOfNodes) {clinkedlistPtr -> end = newNodePtr;} //reassign the end pointer
        }
        clinkedlistPtr -> numOfNodes++;
        clinkedlistPtr -> end -> next = clinkedlistPtr -> start; //make the end pointer point to start to make the ll circular
    }
}

void updateNode(CircularLinkedList* clinkedlistPtr, int position, int newValue) {
    if(!(position >=0 && position < clinkedlistPtr -> numOfNodes)) {
        printf("ERROR: Invalid position %i passed to updateNode().\nLegal positions are 0..%i\n", 
        position, clinkedlistPtr -> numOfNodes - 1);
    } else {
        Node* currentNodePtr = clinkedlistPtr -> start;
        for(int i = 0; i<position; i++) {
            currentNodePtr = currentNodePtr -> next;
        }

        currentNodePtr -> value = newValue;
    }
}

void deleteNode(CircularLinkedList* clinkedlistPtr, int position) {
    Node* temp, *temp_2; //used for operations throughout the function

    if(!(position >=0 && position < clinkedlistPtr -> numOfNodes)) {
        printf("ERROR: Invalid position %i passed to deleteNode().\nLegal positions are 0..%i\n", 
        position, clinkedlistPtr -> numOfNodes - 1);
    } else if (clinkedlistPtr -> numOfNodes == 0) {
        printf("ERROR: trying to delete nodes from an empty circular linked list!\n");
    } else {
        if(position == 0) {
            if(clinkedlistPtr -> numOfNodes == 1) {
                free(clinkedlistPtr -> start);
                clinkedlistPtr -> start = NULL;
            } else {
                temp = clinkedlistPtr -> start -> next;
                free(clinkedlistPtr -> start);
                clinkedlistPtr -> start = temp;
                temp = NULL; //we don't need temp anymore
            }
        }
        else if(position > 0 && position < clinkedlistPtr -> numOfNodes - 1) {
            temp = clinkedlistPtr -> start;
            //getting the node before the one to be deleted
            for(int i = 0; i<position-1; i++) {
                temp = temp -> next;
            }
            
            temp_2 = temp -> next -> next;
            free(temp -> next);
            temp -> next = temp_2;

            temp = NULL; 
            temp_2 = NULL; 
        }
        else {
            temp = clinkedlistPtr -> start;
            //getting the node before the one to be deleted
            for(int i = 0; i<position-1; i++) {
                temp = temp -> next;
            }

            free(temp -> next);
            clinkedlistPtr -> end = temp;
            temp -> next = clinkedlistPtr -> start;
            
            temp = NULL;
        }

        clinkedlistPtr -> numOfNodes--;
        clinkedlistPtr -> end -> next = clinkedlistPtr -> start;
    }
}