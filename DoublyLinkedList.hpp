/**********************************************************************
** Program name: lab6
** Author:       Rebekah Koon
** Date:         7/30/19
** Description:  Header file for class DoublyLinkedList, which is used
**               to create a doubly-linked list of Nodes. Has member 
**               functions to set and new head and tail for the list,
**               delete the head or tail, traverse the list, traverse 
**               the list in reverse, print the head or tail value, and
**               create a doubly linked list of Nodes from a file.
**********************************************************************/

#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include "Node.hpp"

#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;

class DoublyLinkedList
{
    private:
        Node *head;
        Node *tail;

    public:
        DoublyLinkedList();

        void addNewHead(int);
        void addNewTail(int);

        void deleteHead();
        void deleteTail();

        void traverseList();
        void traverseListReverse();

        void printHeadVal();
        void printTailVal();

        void readFile();

        ~DoublyLinkedList();
};

#endif