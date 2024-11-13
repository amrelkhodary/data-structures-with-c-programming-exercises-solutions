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

}
int pop(Stackll* stackllptr) {

}
int get(Stackll* stackllptr) {

}
void debug_printStackll(Stackll* stackllptr) {

}