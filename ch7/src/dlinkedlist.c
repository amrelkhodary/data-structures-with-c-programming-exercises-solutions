#include "../headers/dlinkedlist.h"


DoublyLinkedList* createDoublyLinkedList() {
    DoublyLinkedList* ndlinkedlist = (DoublyLinkedList*) malloc(sizeof(DoublyLinkedList));
    if(ndlinkedlist == NULL) {
        printf("Failed to allocate memory for a new doubly linkedlist.\n");
        return NULL;
    }
    ndlinkedlist -> start = NULL;
    ndlinkedlist -> end = NULL;
    ndlinkedlist -> count = 0;

    return ndlinkedlist;
}

int deleteDoublyLinkedList(DoublyLinkedList* dlinkedlist) {
    if(dlinkedlist -> count <= 0) {
        printf("ERROR: trying to delete a node from an empty linkedlist!\n");
        return INPUT_ERROR;
    } 
    else if (dlinkedlist -> count < 0) {
        printf("ERROR: in deleteDoublyLinkedList function, linkedlist has negative count.");
        return INPUT_ERROR;
    }
    else if(dlinkedlist -> count == 1) {
        free(dlinkedlist -> start);
        dlinkedlist -> start = NULL;
    } else {
        /*
            How the linked list will be deleted
            1   2   3   4   5   6
                ^
            d   c

            1   2   3   4   5   6
                    ^
                d   c
            
            1   2   3   4   5   6
                        ^
                    d   c
            
            1   2   3   4   5   6
                            ^
                        d   c
            
            1   2   3   4   5   6
                                ^
                            d   c
         */

        Node* current = dlinkedlist -> start -> next;
        while(current -> next != NULL) {
            free(current -> prev);
            current -> prev = NULL;
            current = current -> next;
        }

        free(current); 
        current = NULL;
    }

    free(dlinkedlist);
    dlinkedlist = NULL;
    return SUCCESSFUL;
}

int insertNode(DoublyLinkedList* dlinkedlist, int position, int value)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("ERROR: Failed to allocate memeory for a new node in the insertNode function.\n");
        return MEMORY_ERROR;
    } else {
        newNode -> value = value;
    }

    if(!positionIsValid(position, TO_INSERT, dlinkedlist)) {
        printf("ERROR: Position passed to insertNode function is NOT valid.\nLegal positions are 0..%i\n", dlinkedlist -> count);
        return INPUT_ERROR;
    }

    if(position == 0) {
        if(dlinkedlist -> count == 0) {
            //linkedlist is empty
            dlinkedlist -> start = newNode;
            dlinkedlist -> end = newNode;

            newNode -> prev = NULL; 
            newNode -> next = NULL;
        }
        else {
            //inserting at first position
            newNode -> next = dlinkedlist -> start;
            dlinkedlist -> start -> prev = newNode;
            dlinkedlist -> start = newNode;
        }
    }
    else if (position == dlinkedlist -> count) {
        //appending a node to the linkedlist
        dlinkedlist -> end -> next = newNode;
        newNode -> prev = dlinkedlist -> end;
        newNode -> next = NULL;
        dlinkedlist -> end = newNode;
    }
    else {
        //inserting a node in the middle of the linkedlist
        Node* currentNode = dlinkedlist -> start;

        //getting the node before the node to be inserted
        for(int i = 0; i<position-1; i++) {
            currentNode = currentNode -> next;
        }

        newNode -> next = currentNode -> next; 
        currentNode -> next -> prev = newNode;
        currentNode -> next = newNode;
        newNode -> prev = currentNode;
    }

    dlinkedlist -> count++;
    return SUCCESSFUL;
}

int updateNode(DoublyLinkedList* dlinkedlist, int position, int newValue)
{
    if(!positionIsValid(position, TO_UPDATE_OR_DELETE, dlinkedlist)) {
        printf("ERROR: Invalid position passed to updateNode function.\n");
        return INPUT_ERROR;
    }

    if(dlinkedlist -> count == 0) {
        printf("ERROR: Trying to update a node in an empty linked list!\n");
        return INPUT_ERROR;
    }

    if(dlinkedlist -> count <= 0) {
        printf("ERROR: Corrupted linked list passed to updateNode function; count property is negative.\n");
        return INPUT_ERROR;
    }

    Node* currentNode = dlinkedlist -> start;
    for(int i = 0; i<position; i++) {
        currentNode = currentNode -> next;
    }
    currentNode -> value = newValue;
    
    return SUCCESSFUL;  
}

int deleteNode(DoublyLinkedList* dlinkedlist, int position)
{
    if(!positionIsValid(position, TO_UPDATE_OR_DELETE, dlinkedlist))
    {
        printf("Position passed to deleteNode is NOT legal, legal positions are 0..%i\n", dlinkedlist -> count - 1);
        return INPUT_ERROR;
    }

    if(dlinkedlist -> count == 0) {
        printf("ERROR: Trying to delete a node in an empty linked list!\n");
        return INPUT_ERROR;
    }

    if(dlinkedlist -> count <= 0) {
        printf("ERROR: Corrupted linked list passed to deleteNode function; count property is negative.\n");
        return INPUT_ERROR;
    }

    if(position == 0)
    {
        if(dlinkedlist -> count == 1) {
            free(dlinkedlist -> start);
            dlinkedlist -> start = NULL;
            dlinkedlist -> end == NULL;
        }
        else {
            Node* temp = dlinkedlist -> start -> next;
            free(dlinkedlist -> start);
            dlinkedlist -> start = temp;
            temp -> prev = NULL;
        }
    }
    else if (position == dlinkedlist -> count - 1) 
    {
        Node* temp = dlinkedlist -> end -> prev;
        free(dlinkedlist -> end);
        dlinkedlist -> end = temp;
        temp -> next = NULL;
    }
    else
    {
        Node* currentNode = dlinkedlist -> start;
        Node* beforeNode;
        Node* afterNode;

        //navigate to the node to be deleted
        for(int i = 0; i<position; i++) {
            currentNode = currentNode -> next;
        }

        //get the nodes before and after the one to be deleted
        beforeNode = currentNode -> prev;
        afterNode = currentNode -> next;

        //deleted the node
        free(currentNode);
        currentNode = NULL;

        //rewire the linkedlist
        beforeNode -> next = afterNode;
        afterNode -> prev = beforeNode;
    }

    dlinkedlist -> count--;
    return SUCCESSFUL;
}


void printDoublyLinkedList(DoublyLinkedList* dlinkedlist) {
    if(dlinkedlist -> count == 0) {
        printf("Linked list is empty.\n");
        return;
    }

    Node* currentNodePtr = dlinkedlist -> start;
    int i = 1;
    while(currentNodePtr != NULL) {
        printf("node: %i, value: %i\n", i, currentNodePtr -> value);
        currentNodePtr = currentNodePtr -> next;
        i++;
    }

    printf("\n\n");
}

bool positionIsValid(int position, int objective, DoublyLinkedList* dlinkedlist) {
    switch(objective) {
        case TO_INSERT:
            if(position >=0 && position <=dlinkedlist -> count) {
                return true;
            } return false;
            break;
        case TO_UPDATE_OR_DELETE:
            if(position >=0 && position < dlinkedlist -> count) {
                return true;
            } return false;
            break;
        default:
            printf("ERROR: Invalid input to switch expression in positionIsValid function.\n");
            return INPUT_ERROR; //this works out because in C, booleans are integers under the hood.
    }
}
