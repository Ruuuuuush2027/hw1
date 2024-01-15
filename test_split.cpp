/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include<iostream>
#include "split.h"
#include<cstddef>

using namespace std;

void printList(Node*& list){
    Node* curr = list;
    while(curr != NULL){
        cout << curr->value << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    Node* n5 = new Node(5, nullptr);
    Node* n4 = new Node(4, n5);
    Node* n3 = new Node(3, n4);
    Node* n2 = new Node(2, n3);
    Node* n1 = new Node(1, n2);

    Node* odds = nullptr;
    Node* evens = nullptr;

    cout << "original: ";
    printList(n1);
    
    split(n1, odds, evens);

    cout << "odds: ";
    printList(odds);

    cout << "evens: ";
    printList(evens);
    
}
