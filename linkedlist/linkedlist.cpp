#include <iostream>
#include <stdlib.h>

#include "linkedlist.h"

//Code for each prototyped method in linkedlist.h
using namespace std;

LinkedList::LinkedList() {
    head_ = NULL;
    size_ = 0;
}

LinkedList::~LinkedList() {
    //Deallocate memory from heap if need be
}

//Traverse linked list recursively and print out linked list
//elements in order
void recTraverse(Node* &head) {
    if(head == NULL) {
      return;
    }
    cout << head->value << endl;
    recTraverse(head->next);
}

//Traverse linked list recursively and print out linked list
//elements in reverse order
void recTraverse(Node* &head) {
    if(head == NULL) {
      return;
    }
    recTraverse(head->next);
    cout << head->value << endl;
}

//Insert new Node at the beginning of the linked list
void insertAtStart(Node* &head, int val) {
    
    //Create a pointer to Node from stack
    //Create a new Node in heap memory
    Node* nodePtr = new Node;
    
    //Make data member "Node* next" in new 
    //node point to the same Node that head
    //is pointing to, AKA, connecting new node
    //to the first Node element of list
    nodePtr->next = head;
    
    //Change new node's "value"
    nodePtr->value = val;

    //Or use the member initialisation
    //Node* nodePtr = new Node(val, head);
    
    //Get head to point to the new node by 
    //making it the same pointer as nodePtr
    head = nodePtr;
}

//Iteratively insert new Node at the end of the linked list
void itInsertAtEnd(Node* &head, int val) {
    
    //Create a pointer to Node from stack
    //Create a new Node in heap memory
    Node* nodePtr = new Node(val, NULL);
    
    //Check if my head is pointing to NULL,
    //AKA, an empty list, then make my head
    //point to the new Node 
    if(head == NULL) {
        head = nodePtr;
    } else {
        
        //Create new pointer that points to same
        //Node element as head
        Node* copyOfHead = head;
    
        //Go to the end of the list, will know
        //we reached when "Node* next" is pointing 
        //to NULL
        while(copyOfHead->next != NULL) {
            copyOfHead = copyOfHead->next;
        }
        
        //Making last Node element point to the 
        //new Node
        copyOfHead->next = nodePtr;
    }
}

//Recursively insert new Node at the end of the linked list
void recInsertAtEnd(Node* &head, int val) {
    
    //Base Case: When my head is pointing to NULL,
    //AKA, head is the same as the "Node* next" in
    //the last Node element and get head to point 
    //to a new Node in heap memory and initliase 
    //"value" and "Node* next = NULL" 
    if(head == NULL) {
        head = new Node(val, NULL);
    } 
    //Recursive case: Pass the "Node* next" of the
    //Node element that head is pointing to to the 
    //function, making it seem like head is pointing 
    //to the next Node element of the list until it 
    //reaches the end of the list in the base case
    else {
        recInsertAtEnd(head->next, val);
    }
}