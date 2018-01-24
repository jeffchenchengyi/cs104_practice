#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

class LinkedList {
  public:
    //Default constructor
    LinkedList();

    //Destructor
    ~LinkedList();

    //Returns the current number of items in the list
    int size() const;

    //Returns true if the list is empty, false otherwise
    bool empty() const;

    //Traverse linked list recursively and print out linked list
    //elements in order
    void recTraverse(Node* &head);

    //Inserts val so it appears at the index given as pos. If the
    //index pos is invalid, this function should return without
    //modifying the list.
    void insert(int pos, int val);

    //Insert new Node at the beginning of the linked list
    void insertAtStart(Node* &head, int val);

    //Iteratively insert new Node at the end of the linked list
    void itInsertAtEnd(Node* &head, int val);

    //Recursively insert new Node at the end of the linked list
    void recInsertAtEnd(Node* &head, int val); 

    //Removes the value at the index given by pos. If the
    //index pos is invalid, this function should return without
    //modifying the list.
    void remove(int pos);

  private:
    struct Node {
      int value;
      Node *next;
      Node(int val, Node* ptrToNode):
        value(val), next(ptrToNode) {}
    };

    //Data members
    Node* head_;
    int size_;
};

#endif