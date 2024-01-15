/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include<cstddef>

/* Add a prototype for a helper function here if you need */
void insert(Node*& list, int val);

void split(Node*& in, Node*& odds, Node*& evens)
{
    if(in == nullptr)
        return;
    
    if(in->value % 2 == 1)
        insert(odds, in->value);
    else
        insert(evens, in->value);
    
    split(in->next, odds, evens);
    delete in;
    in = nullptr;
}

/* If you needed a helper function, write it here */
void insert(Node*& list, int val){
    if(list == nullptr){
        Node* newnode = new Node(val, nullptr);
        list = newnode;
    }
    else if(list->next == nullptr){
        Node* newnode = new Node(val, nullptr);
        list->next = newnode;
    }
    else{
        insert(list->next, val);
    }
}