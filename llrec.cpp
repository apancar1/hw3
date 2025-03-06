#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
	if (head == nullptr){
		smaller = nullptr; 
		larger = nullptr; 
		return; 
		// if the head is null, that is when we stop (nothing left)
	}
	Node* curr = head; 
	// get curr ptr 
	head = head->next; 
	Node* smallPtr = nullptr; 
	Node* largePtr = nullptr; 
	// these are to keep track of the locations sicne smaller and larger are head ptrs 
	// this variable is made to be used in recursive call 
	//head->next = nullptr; 
	llpivot(head, smallPtr, largePtr, pivot);
	// head recursion 
	// for tail recursion you need tail ptr - so code is now changed to allocate for head recursion
	// this is why the extra ptrs are needed 
	// dont want the node to have any next node (this would disrupt it being added into its new list)
	if (curr->val <= pivot){
		// check if it should go in smaller
		smaller = curr; 
		curr->next = smallPtr; 
		larger = largePtr;
		// set the smaller, change the loc of smaller ptr to the next one. large remains the same 
	}
	if (curr->val > pivot){
		// same logic as smaller but for bigger
		larger = curr; 
		curr->next = largePtr; 
		smaller = smallPtr;  
	}
	// make sure the head is nullptr (as specified in instructions)
	//head = nullptr;
	// recursive call 
}