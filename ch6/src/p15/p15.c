/**
 * PROBLEM STATEMENT: Write a program to reverse a linkedlist using recursion.
 */

#include "../singly-linked-list.h"

void reverseLinkedList(LinkedList* ll, Node* ll_end, int* nodeCount, LinkedList* r_ll);
void appendNode(LinkedList* ll, int value);

int main() {

}

void reverseLinkedList(LinkedList* ll, Node* ll_end, int* nodeCount, LinkedList* r_ll) {
    printf("Node Count: %i\n", *nodeCount);
    if(*nodeCount == 1) 
    {
        //base case
        appendNode(r_ll, ll_end -> value);
        return;
    }

    //recursive case
    appendNode(r_ll, ll_end -> value);
    (*nodeCount)--;
    Node* newEnd = ll -> start;
    while(newEnd -> next != ll_end)
    {
        newEnd = newEnd -> next;
    }
    reverseLinkedList(ll, newEnd, nodeCount, r_ll);    
}

void appendNode(LinkedList* ll, int value)
{
    printf("inside appendNode.\n");
    insertNode(ll, ll -> nodeCount, value);
    printf("finished appendNode.\n");
}