#include "llrec.h"
#include <iostream>

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {

    if(head == NULL) {
       return;
    }


     //is less than or equal to pivot, add to smaller
    if (head->val <= pivot) {
        smaller = head;
        Node* next = head->next;
        head->next = NULL;
        //getting rid of the original list
        head = NULL;
        llpivot(next, smaller->next, larger, pivot);
    }

    //else add to the larger linked list
    else {
        larger = head;
        Node* next = head->next;
        head->next = NULL;
        //getting rid of the original list
        head = NULL;
        llpivot(next, smaller, larger->next, pivot);
    }
    


}
