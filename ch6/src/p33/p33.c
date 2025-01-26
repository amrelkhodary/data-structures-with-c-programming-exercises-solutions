/*
    PROBLEM STATEMENT: Write a program to create a singly linkedlist and 
                       reverse the list by interchanging the links and not 
                       the data. 
*/

#include "../singly-linked-list.h"

LinkedList* reverseLinkedList(LinkedList* ll);
int main() {

}

LinkedList* reverseLinkedList(LinkedList* ll) {
    Node* temp;
    Node* temp_2 = getNode(ll, ll -> nodeCount - 1);
    for(int i = ll -> nodeCount - 2; i >= 0; i--) {
        temp = getNode(ll, i);
        temp -> next -> next = temp;

    }

    temp -> next = NULL;
    ll -> start = temp_2;
    return ll;
}