#include <stdio.h>
#include <stdlib.h>

#define SUCCESSFUL 0
#define MEMORY_ERROR 1

typedef struct Stack {
    int* elementsArray;
    int* current;
} Stack;

Stack* createStack(int size);
int deleteStack(Stack* stackptr);


int main() {

}

Stack* createStack(int size) {
    Stack* nStack = (Stack*) malloc(sizeof(Stack));
    if(nStack == NULL) {
        printf("ERROR: Failed to allocate memory for a new stack\n");
        return MEMORY_ERROR;
    }
    nStack -> elementsArray = (int*) malloc(size * sizeof(int));
    if(nStack -> elementsArray == NULL) {
        printf("ERROR: Failed to allocate memory to elements array inside new stack. \n");
        return MEMORY_ERROR;
    }
    nStack -> current = nStack -> elementsArray[0];

    return nStack;
}

int deleteStack(Stack* stackptr) {
    free(stackptr -> elementsArray);
    free(stackptr);
    
    return SUCCESSFUL;
}