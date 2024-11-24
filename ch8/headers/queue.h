#ifndef STD 
    #define STD
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
#endif

#ifndef ERRORS
    #define SUCCESSFUL 0;
    #define MEMORY_ERROR 100;
    #define INPUT_ERROR 103;
#endif

#ifndef QUEUE_H
    #define PTR_OUT_OF_BOUNDS -7999
    typedef struct Queue {
        int* elements;
        int start;
        int end;
        size_t size;
        int count;
    } Queue;

    Queue* createQueue(size_t size);
    int deleteQueue(Queue* queueptr);
    int push(Queue* queptr, int element);
    int pop(Queue* queptr);
    
    void debugPrintQueue(Queue* queptr, int operation, int element);
#endif