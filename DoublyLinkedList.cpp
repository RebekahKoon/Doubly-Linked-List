/**********************************************************************
** Program name: lab6
** Author:       Rebekah Koon
** Date:         7/30/19
** Description:  Implementation file for class DoublyLinkedList, which
**               is used to create a doubly-linked list. Has member 
**               functions to set and new head and tail for the list, 
**               delete the head or tail, traverse the list, traverse 
**               the list in reverse, print the head or tail value, and
**               create a doubly linked list from a file.
**********************************************************************/

#include "DoublyLinkedList.hpp"


/**********************************************************************
** Description: Default constructor for the DoublyLinkedList class. 
**              Initializes head and tail member variables to null.
**********************************************************************/
DoublyLinkedList::DoublyLinkedList()
{
    head = NULL;
    tail = NULL;
}


/**********************************************************************
** Description: Void member function addNewHead takes an integer as a 
**              parameter. Uses the value to create a new Node object,
**              which will be used as the new head of the list.
**              Source: https://www.youtube.com/watch?v=YJRRpXYldVQ
**********************************************************************/
void DoublyLinkedList::addNewHead(int val)
{
    //If empty list, head and tail both point to new Node object
    if (head == NULL && tail == NULL)
    {
        head = new Node;
        head->setVal(val);
        tail = head;
    }

    //If list is not empty
    else
    {
        Node *newHead = new Node;

        //Setting value of new head
        newHead->setVal(val);

        //previous Node for new head will point to null
        newHead->setPrev(NULL);

        //The old head's previous Node is the new head
        head->setPrev(newHead);

        //The new head's next Node is the old head
        newHead->setNext(head);

        //New Node object is now the head
        head = newHead;
    }
}


/**********************************************************************
** Description: Void member function addNewTail takes an integer as a 
**              parameter. Uses the value to create a new Node object,
**              which will be used as the new tail of the list.
**              Source: https://www.youtube.com/watch?v=YJRRpXYldVQ
**********************************************************************/
void DoublyLinkedList::addNewTail(int val)
{
    //If empty list, head and tail both point to new Node object
    if (head == NULL && tail == NULL)
    {
        tail = new Node;
        tail->setVal(val);

        head = tail;
    }

    //If list is not empty
    else
    {
        Node *newTail = new Node;

        //Setting value of new tail
        newTail->setVal(val);

        //next Node for new tail will point to null
        newTail->setNext(NULL);

        //The old tail's next Node is the new tail
        tail->setNext(newTail);

        //The new tail's previous Node is the old tail
        newTail->setPrev(tail);

        //New Node object is now the tail
        tail = newTail;
    }
}


/**********************************************************************
** Description: Void member function deleteHead deletes the Node object
**              that is first in the list.
**              Source: Gaddis et al., section 18.5
**********************************************************************/
void DoublyLinkedList::deleteHead()
{
    //If list is empty
    if (head == NULL && tail == NULL)
    {
        cout << "There are no values in the list to delete." << endl << endl;
    }

    //If there is only one Node in the list
    else if (head == tail)
    {
        cout << head->getVal() << " will be deleted." << endl << endl;

        delete head;

        //head and tail will point to null
        head = NULL;
        tail = NULL;
    }

    else
    {
        cout << head->getVal() << " will be deleted." << endl << endl;

        //Finding Node after head
        Node *temp = head->getNext();

        delete head;

        //Making Node after head the new head
        head = temp;
        head->setPrev(NULL);
    }
}


/**********************************************************************
** Description: Void member function deleteTail deletes the Node object
**              that is last in the list.
**              Source: Gaddis et al., section 18.5
**********************************************************************/
void DoublyLinkedList::deleteTail()
{
    //If list is empty
    if (head == NULL && tail == NULL)
    {
        cout << "There are no values in the list to delete." << endl << endl;
    }

    //If there is only one Node in the list
    else if (head == tail)
    {
        cout << tail->getVal() << " will be deleted." << endl << endl;

        delete tail;
        
        //head and tail will point to null
        head = NULL;
        tail = NULL;
    }

    else
    {
        cout << tail->getVal() << " will be deleted." << endl << endl;

        //Finding Node before tail
        Node *temp = tail->getPrev();

        delete tail;

        //Making Node before tail the new tail
        tail = temp;
        tail->setNext(NULL);
    }
    
}


/**********************************************************************
** Description: Void member function traverseList prints all of the
**              values held by the Nodes within the list from the top
**              of the list to the bottom.
**              Source: https://www.youtube.com/watch?v=5s0x8bc9DvQ
**********************************************************************/
void DoublyLinkedList::traverseList()
{
    //If list is empty
    if (head == NULL && tail == NULL)
    {
        cout << "The list is empty." << endl << endl;
    }

    //If list is not empty
    else
    {
        cout << "The values in the list are:" << endl;

        //Points to Node that will be printed
        Node *currentItem = head;

       //Printing all values from head to tail until list reaches end
        while (currentItem)
        {
            int value = currentItem->getVal();
            cout << value << endl;

            currentItem = currentItem->getNext();
        }

        cout << endl;
    }
}


/**********************************************************************
** Description: Void member function traverseListReverse prints all of
**              the values held by the Nodes within the list from the
**              bottom of the list to the top.
**              Source: https://www.youtube.com/watch?v=5s0x8bc9DvQ
**********************************************************************/
void DoublyLinkedList::traverseListReverse()
{
    //If list is empty
    if (head == NULL && tail == NULL)
    {
        cout << "The list is empty." << endl << endl;
    }

    //If list is not empty
    else
    {
        cout << "The values of the list in reverse are:" << endl;

        //Points to Node that will be printed
        Node *currentItem = tail;

        //Printing all values from tail to head until reaches end
        while (currentItem)
        {
            int value = currentItem->getVal();
            cout << value << endl;

            currentItem = currentItem->getPrev();
        }

        cout << endl;
    }
}


/**********************************************************************
** Description: Void member function printHeadVal prints the value of
**              the head Node object if the list is not empty.
**********************************************************************/
void DoublyLinkedList::printHeadVal()
{
    //If list is empty
    if (head == NULL && tail == NULL)
    {
        cout << "There are no values in the list." << endl << endl;
    }

    else
    {
        //Finding the value of the head Node
        int headVal = head->getVal();

        cout << "The head value is: " << headVal << endl << endl;
    }
}


/**********************************************************************
** Description: Void member function printTailVal prints the value of 
**              the tail Node object if the list is not empty.
**********************************************************************/
void DoublyLinkedList::printTailVal()
{
    //If the list is empty
    if (head == NULL && tail == NULL)
    {
        cout << "There are no values in the list." << endl << endl;
    }
    
    else
    {
        //Finding the value of the tail Node
        int tailVal = tail->getVal();

        cout << "The tail value is: " << tailVal << endl << endl;
    }
}


/**********************************************************************
** Description: Void member function readFile reads values from a text
**              file. If the file is available, deletes the current
**              list and creates a Node object for each of the values
**              within the file.
**              Source: Gaddis et al., section 17.2
**********************************************************************/
void DoublyLinkedList::readFile()
{
    int value;
    ifstream inNode;

    inNode.open("list.txt");

    //If file cannot be opened
    if (!inNode)
    {
        cout << "The file could not be opened." << endl << endl;
    }

    else
    {
        cout << "list.txt will be read." << endl << endl;

        //Deletes objects already in the list before reading the file
        if (head != NULL)
        {
            //Points to the current Node to be deleted
            Node *currentNode = head;

            //Keeps deleting until reaches end of list
            while (currentNode != NULL)
            {
                Node *garbage = currentNode;

                //Finding next value to delete
                currentNode = currentNode->getNext();

                delete garbage;
            }

            delete currentNode;
            head = NULL;
            tail = NULL;
        }

        //Reading the file's values
        while (inNode >> value)
        {
            //Add value to end of list
            addNewTail(value);
        }
    }

    inNode.close();
}


/**********************************************************************
** Description: Destructor for DoublyLinkedList class that deallocates
**              dynamically created memory.
**              Source: Gaddis et al., section 17.2
**********************************************************************/
DoublyLinkedList::~DoublyLinkedList()
{
    Node *currentNode = head;

    //Keeps deleting until reaches end of list
    while(currentNode != NULL)
    {
        Node *garbage = currentNode;

        //Finding next value to delete
        currentNode = currentNode->getNext();

        delete garbage;
    }

    delete currentNode;
}