#include "../headers/stackll.h"

int main() {

}

Stackll* createStackll() {
    Stackll* nstackll = (Stackll*) malloc(sizeof(Stackll));
    if(nstackll == NULL) {
        printf("MEMORY ERROR: Failed to allocate memory for a new linkedlist-based stack.\n");
        return MEMORY_ERROR;
    }

    nstackll -> sdlinkedlist = createDoublyLinkedList();
    nstackll -> current = NULL;
    nstackll -> size = 0;

    return nstackll;
}
int deleteStackll(Stackll* stackllptr) {
    deleteDoublyLinkedList(stackllptr -> sdlinkedlist);
    stackllptr -> current = NULL;
    free(stackllptr);

    return SUCCESSFUL;
}
int push(Stackll* stackllptr, int element) {
    insertNode(stackllptr -> sdlinkedlist, stackllptr -> size, element);
    if(stackllptr -> current == NULL) {
        stackllptr -> current = stackllptr -> sdlinkedlist -> start;
    } else {
        stackllptr -> current = stackllptr -> current -> next;
    }
    stackllptr -> size++;

    return SUCCESSFUL;
}
int pop(Stackll* stackllptr) {
    if(stackllptr -> size <= 0) {
        printf("ERROR: Trying to pop an element off an empty linkedlist-based stack.\n");
        return INPUT_ERROR;
    }

    if(stackllptr -> size == 1) {
        stackllptr -> current = NULL;
    } else {
        stackllptr -> current = stackllptr -> current -> prev;
    }
    deleteNode(stackllptr -> sdlinkedlist, stackllptr -> size);
    stackllptr -> size--;

    return SUCCESSFUL;
}
int get(Stackll* stackllptr) {
    if(stackllptr -> size == 0) {
        printf("ERROR: Trying to get an element from an empty linkedlist-based stack.\n");
        return INPUT_ERROR;
    }

    return stackllptr -> current -> value;
}
void debug_printStackll(Stackll* stackllptr) {
    printf("----------------------------------DEBUGGING INFO--------------------------------------\n");
    printDoublyLinkedList(stackllptr -> sdlinkedlist);
    printf("\n");
    if(stackllptr -> current != NULL) {
        printf("Value of current node: %i\n", stackllptr -> current -> value);
    } else {
        printf("Value of current node: NULL\n");
    }
    printf("\n");
    prinft("Size of stack: %i\n", stackllptr -> size);

}