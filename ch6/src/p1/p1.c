/* 
    PROBLEM STATEMENT: Write a program that removes all nodes that have duplicate information
    EXAMPLE INPUT: 2 -> 3 -> 5 -> 1 -> 2 -> 10 -> 3 -> 6
    EXAMPLE OUTPUT: 5 -> 1 -> 10 -> 6 (removed all instances of 2 and 3)
*/

#include "../singly-linked-list.h"
LinkedList* removeDuplicates(LinkedList* ll);

int main() {

}

LinkedList* removeDuplicates(LinkedList* ll) {
    if(ll -> nodeCount <=1) {
        printf("Linkedlist have one or zero nodes.\n");
        return ll;
    }

    Node* start = ll -> start;
    Node* current = ll -> start -> next;
    Node* temp;
    int startIndex = 0;
    int currentIndex;
    bool dflag = false;

    while(start != NULL && start -> next != NULL) {
        current = start -> next;
        currentIndex = startIndex + 1;

        while(current != NULL) {
            if(current -> value == start -> value) {
                dflag = true;
                temp = current -> next;
                deleteNode(ll, currentIndex);
                current = temp;
            }
            else {
                current = current -> next;
                currentIndex++;
            }
            
        }

        if(dflag) {
            temp = start -> next;
            deleteNode(ll, startIndex);
            start = temp;
            dflag = false;
        } else {
            start = start -> next;
            startIndex++;
        }
    }
        
       

    return ll;
}