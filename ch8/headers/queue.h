#ifndef STD 
    #define STD
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
#endif

#ifndef ERRORS
    #define MEMORY_ERROR 100;
    #define INPUT_ERROR 103;
#endif

#ifndef QUEUE_H
    typedef struct Queue {
        int* elements;
        int pushindex;
        int popindex;
        int size;
    } Queue;

    Queue* createQueue(int size);
    int deleteQueue(Queue* queueptr);
    int push(Queue* queptr, int element);
    int pop(Queue* queptr);
    int get(Queue queptr);
    void debugPrintQueue(Queue* queptr);
#endif