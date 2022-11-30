#include "llrec.h"
#include <iostream>

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot2(Node *&head, Node *&smaller, Node *&larger, int pivot) {
  if(head == NULL) {
      /*
        if ( smaller == larger ) {
            smaller = NULL;
            larger = NULL;
        }
        */
       return;
    }

     //is less than or equal to pivot, add to smaller
    if (head->val <= pivot) {
        smaller = head;
        Node* next = head->next;
        head->next = NULL;
        //getting rid of the original list
        head = NULL;
        llpivot2(next, smaller->next, larger, pivot);
    }

    //else add to the larger linked list
    else {
        larger = head;
        Node* next = head->next;
        head->next = NULL;
        //getting rid of the original list
        head = NULL;
        llpivot2(next, smaller, larger->next, pivot);
    }
    
}

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {

    smaller = NULL;
    larger = NULL;
    llpivot2(head, smaller, larger, pivot);

}
