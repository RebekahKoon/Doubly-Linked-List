/***********************************************************************
** Program name: lab6
** Author:       Rebekah Koon
** Date:         7/30/19
** Description:  Header file for the Node class, which is used to keep
**               track of a Node's value as well as the Nodes before and
**               after the current Node. Has member functions to set and
**               get the next Node, set and get the previous Node, and 
**               set and get the current Node's value.
***********************************************************************/

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

class Node
{
    private:
        Node *next;
        Node *prev;
        int val;
    
    public:
        Node();

        void setNext(Node *);
        Node * getNext();

        void setPrev(Node *);
        Node * getPrev();

        void setVal(int);
        int getVal();
};

#endif