/*
    PROBLEM STATEMENT: Write a program that multiplies a polynomial 
                       with a given number using a linkedlist. 
 */

#include "../singly-linked-list.h"
#include "polynomial.h"

int main() {

}

Polynomial* createPolynomial(Term* terms, size_t numOfTerms) {
    Polynomial* nPolynomial = (Polynomial*) malloc(sizeof(Polynomial));
    nPolynomial -> plinkedlist = createLinkedList();
    if(nPolynomial == NULL) {
        printf("MEMORY ERROR: Failed to allocate memory to a new polynomial.\n");
        return NULL;
    }

    for(int i = 0; i<numOfTerms; i++) {
        insertNode(nPolynomial -> plinkedlist, nPolynomial -> plinkedlist -> nodeCount, terms[i].factor);
        insertNode(nPolynomial -> plinkedlist, nPolynomial -> plinkedlist -> nodeCount, terms[i].exponent);
    }

    return nPolynomial;
}

Polynomial* multiplyPolynomialByFactor(Polynomial* polynomial, int factor) {
    for(int i = 0; i<polynomial -> plinkedlist -> nodeCount; i+=2) {
        updateNode(polynomial -> plinkedlist, i, get(polynomial -> plinkedlist, i) * factor);
    } 

    return polynomial;
}

void printPolynomial(Polynomial* polynomial)
{
    for(int i = 0; i < polynomial -> plinkedlist -> nodeCount; i++) {
        if((i+1) % 2 == 0) {
            int exponent = get(polynomial -> plinkedlist, i);
            if(exponent == 0) {
                if(i != polynomial -> plinkedlist -> nodeCount -1 ) {
                    printf(" +");
                }

            } else {
                printf("x^%i +", exponent);

            }
        }
        else {
            printf("%i", get(polynomial -> plinkedlist, i));
        }
    }

    printf("\n");
}