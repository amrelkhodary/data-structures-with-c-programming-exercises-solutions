#include "./headers/queue.h"

int main()
{

}

Queue* createQueue(int size) {
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
    nQueuePtr -> pushindex = 0;
    nQueuePtr -> popindex = 0;
    nQueuePtr -> size = 0; //here, size referes to how many elements are currently in the queue not the size of the array itself

    return nQueuePtr;
}

int deleteQueue(Queue* queueptr) {
    free(queueptr -> elements);
    free(queueptr);
}

