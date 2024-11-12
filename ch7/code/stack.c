#include <stdio.h>
#include <stdlib.h>

#define SUCCESSFUL 0
#define MEMORY_ERROR 1
#define INPUT_ERROR 2

typedef struct Stack {
    int* elementsArray;
    int current;
    int size;
} Stack;

Stack* createStack(int size);
int deleteStack(Stack* stackptr);
int push(Stack* stackptr, int element);
int pop(Stack* stackptr);

int main() {

}

Stack* createStack(int size) {

    if(size <= 0) {
        printf("Can't create a stack a size smaller than or equal to 0.\n");
        return INPUT_ERROR;
    }

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
    nStack -> current = -1; //to indicate that there are no elements yet.
    nStack -> size = size;

    return nStack;
}

int deleteStack(Stack* stackptr) {
    free(stackptr -> elementsArray);
    free(stackptr);
    
    return SUCCESSFUL;
}

int push(Stack* stackptr, int element) {
    if(stackptr -> current + 1 > stackptr -> size) {
        printf("ERROR: Stack Overflow.\n");
        return INPUT_ERROR;
    }

    stackptr -> elementsArray[stackptr -> current + 1] = element;
    stackptr -> current = stackptr -> current + 1;
    return SUCCESSFUL;
} 

int pop(Stack* stackptr) {
    if(stackptr -> current == -1) {
        printf("ERROR: Trying to pop an element off an empty stack.\n");
        return INPUT_ERROR;
    }

    stackptr -> current = stackptr -> current - 1;
    return SUCCESSFUL;
}