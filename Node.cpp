/***********************************************************************
** Program name: lab6
** Author:       Rebekah Koon
** Date:         7/30/19
** Description:  Implementation file for the Node class, which keeps 
**               track of a Node's value as well as the Nodes before and
**               after the current Node. Has member functions to set and
**               get the next Node, set and get the previous Node, and 
**               set and get the current Node's value.
***********************************************************************/

#include "Node.hpp"


/***********************************************************************
** Description: Default constructor for the Node class that initializes
**              the member variables of the class.
***********************************************************************/
Node::Node()
{
    next = NULL;
    prev = NULL;
    val = 0;
}


/***********************************************************************
** Description: Void member function setNext takes a pointer to a Node
**              object as a parameter. Uses to set next.
***********************************************************************/
void Node::setNext(Node *nextIn)
{
    next = nextIn;
}


/***********************************************************************
** Description: Member function getNext returns the next Node.
***********************************************************************/
Node * Node::getNext()
{
    return next;
}


/***********************************************************************
** Description: Void member function setPrev takes a pointer to a Node
**              object as a parameter. Uses to set prev.
***********************************************************************/
void Node::setPrev(Node *prevIn)
{
    prev = prevIn;
}


/***********************************************************************
** Description: Member function getPrev returns the previous Node.
***********************************************************************/
Node * Node::getPrev()
{
    return prev;
}


/***********************************************************************
** Description: Void function setVal takes an integer as a parameter.
**              Uses to set the value of the Node.
***********************************************************************/
void Node::setVal(int valIn)
{
    val = valIn;
}


/***********************************************************************
** Description: Member function getVal returns the Node's value.
***********************************************************************/
int Node::getVal()
{
    return val;
}
