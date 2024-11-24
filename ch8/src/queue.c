#include "../headers/queue.h"

#define OPERATION_PUSH 300
#define OPERATION_POP 400

int main()
{
    
}

Queue* createQueue(size_t size) {
    if(size <= 0) {
        printf("INPUT ERROR: trying to create a queue with a size less than or equalling zero.\n");
        return INPUT_ERROR;
    }

    Queue* nQueuePtr = (Queue*) malloc(sizeof(Queue));
    if(nQueuePtr == NULL) {
        printf("MEMORY_ERROR: failed to allocate memory to new queue.\n");
        return MEMORY_ERROR;
    }
    nQueuePtr -> elements = (int*) malloc(size * sizeof(int));
    if(nQueuePtr -> elements == NULL) {
        printf("MEMORY_ERROR: failed to allocate memory for elements array inside new queue.\n");
        return MEMORY_ERROR;
    }
    nQueuePtr -> start = 0;
    nQueuePtr -> end = 0;
    nQueuePtr -> size = size;
    nQueuePtr -> count = 0;

    return nQueuePtr;
}

int deleteQueue(Queue* queueptr) {
    free(queueptr -> elements);
    free(queueptr);
}

int push(Queue* queptr, int element) {
    //check if the queue is already full
    if(queptr -> count == queptr -> size) {
        printf("INPUT ERROR: trying to push an element into a full queue.\n");
        return INPUT_ERROR;
    }

    //push the element
    queptr -> elements[queptr -> end] = element;
    queptr -> count++;

    //shift the end pointer
    if(queptr -> count == queptr -> size) {
        queptr -> end = PTR_OUT_OF_BOUNDS;
    } else {
        queptr -> end = (queptr -> start + queptr -> count) % 3;
    }

    return SUCCESSFUL;
}

int pop(Queue* queueptr) {
    //check if queue is empty
    if(queueptr -> count <= 0) {
        printf("INPUT_ERROR: trying to pop an element off an empty queue.\n");
        return INPUT_ERROR;
    }

    //get the element to pop it later in the function
    int popElement = queueptr -> elements[queueptr -> start];
    queueptr -> count--;

    //shift the start pointer
    queueptr -> start = (queueptr -> start + 1) % 3;
    if(queueptr -> end == PTR_OUT_OF_BOUNDS) {
        queueptr -> end = (queueptr -> start + queueptr -> count) % 3;
    }

    //return the pop element
    return popElement;
}

void debugPrintQueue(Queue* queueptr, int operation, int element) {
    if(operation == OPERATION_PUSH) {
        push(queueptr, element);
    }
    else if(operation == OPERATION_POP) {
        printf("output of the pop operation is: %i\n", pop(queueptr));
    }
    printf("DEBUGGING: queue -> elements: ");
    for(int i = 0; i<queueptr -> size; i++) {
        printf("%i ", queueptr -> elements[i]);
    }
    printf("\n DEBUGGING: queue -> count = %i\n", queueptr -> count);
    printf("DEBUGGING: queue -> start = %i\n", queueptr -> start);
    printf("DEBUGGING: queue -> end = %i\n\n\n", queueptr -> end);
}
