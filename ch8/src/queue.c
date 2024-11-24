#include "./headers/queue.h"

int main()
{

}

Queue* createQueue(int size) {
    Queue* nQueuePtr = (Queue*) malloc(sizeof(Queue));
    nQueuePtr -> elements = (int*) malloc(size * sizeof(int));
    nQueuePtr -> pushindex = 0;
    nQueuePtr -> popindex = 0;
    nQueuePtr -> size = 0; //here, size referes to how many elements are currently in the queue not the size of the array itself

    return nQueuePtr;
}
