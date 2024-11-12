#include <stdlib.h>
#include "stackll.h"

#define SUCCESSFUL 0
#define MEMORY_ERROR 1
#define INPUT_ERROR 2

Stackll* createStackll() {
    Stackll* nstackll = (Stackll*) malloc(sizeof(Stackll));
    if(nstackll == NULL) {
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
    stackllptr = NULL;

    return SUCCESSFUL;
}

int push(Stackll* stackllptr, int value) {

}

int pop(Stackll* stackllptr) {

}

int get(Stackll* stackllptr) {

}

void debug_printStackll(Stackll* stackllptr) {

}