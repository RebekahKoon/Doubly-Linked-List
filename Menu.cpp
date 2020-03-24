/**********************************************************************
** Program name: lab6
** Author:       Rebekah Koon
** Date:         7/30/19
** Description:  Implementation file for the Menu class, which has
**               functions to start the program, show options the user
**               can choose to perform on a doubly linked list, and
**               carry out the desired action for the list. Also has a
**               function for the user to input a value for either the
**               new head or tail Node of the list.
**********************************************************************/


#include "Menu.hpp"


/**********************************************************************
** Description: Default constructor for the Menu class that dynamically
**              allocates memory for the DoublyLinkedList object.
**********************************************************************/
Menu::Menu()
{
    listInts = new DoublyLinkedList;
}


/**********************************************************************
** Description: Member function showOptions prints the options that the
**              user can choose from when running the program. Returns
**              the user's choice.
**********************************************************************/
int Menu::showOptions()
{
    bool validChoice;
    int choice;
    const int CHOICE_MIN = 1,
              CHOICE_MAX = 8;

    cout << "Please choose an option:" << endl;
    cout << "1. Add a new node to the head." << endl;
    cout << "2. Add a new node to the tail." << endl;
    cout << "3. Delete the first node in the list." << endl;
    cout << "4. Delete the last node in the list." << endl;
    cout << "5. Traverse the list reversely." << endl;
    cout << "6. Print head value." << endl;
    cout << "7. Print tail value." << endl;
    cout << "8. Exit the program." << endl << endl;
    cout << "Please enter your choice (1-8): ";

    //Calling validInput to see if the user entered 1 or 2
    choice = validInput(CHOICE_MIN, CHOICE_MAX);

    return choice;
}


/**********************************************************************
** Description: Void member function startProgram calls showOptions to
**              get the user's desired choice concerning what to 
**              perform for the doubly linked list. Uses this value to 
**              perform the user's choice.
**********************************************************************/
void Menu::startProgram()
{
    int choice,
        readFile,
        value;

    const int YES = 1,
              NO = 2;

    //Determining if values from file should be read into list
    cout << "Do you want to create a list from the list.txt file?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "Enter your choice (1-2): ";
    readFile = validInput(YES, NO);

    //If user wants to read file
    if (readFile == YES)
    {
        listInts->readFile();
                
        //Printing list
        listInts->traverseList();
    }

    //Finding user's choice of what option to perform
    choice = showOptions();

    //Program exits when user enters 9
    while (choice != QUIT)
    {
        //Determining what the user wants to do
        switch (choice)
        {
            //Creates a new head
            case ADD_HEAD:
                //Finding value for head
                cout << "What should the value of the head be?" << endl;
                value = findValue();

                listInts->addNewHead(value);
                cout << value << " is now the head." << endl << endl;

                //Printing list
                listInts->traverseList();
                break;

            //Creates a new tail
            case ADD_TAIL:
                //Finding value for tail
                cout << "What should the value of the tail be?" << endl;
                value = findValue();

                listInts->addNewTail(value);
                cout << value << " is now the tail." << endl << endl;

                //Printing list
                listInts->traverseList();
                break;

            //Deletes current head
            case DELETE_HEAD:
                listInts->deleteHead();

                //Printing list
                listInts->traverseList();
                break;
    
            //Deletes current tail
            case DELETE_TAIL:
                listInts->deleteTail();

                //Printing list
                listInts->traverseList();
                break;

            //Prints list in reverse order
            case TRAVERSE_REVERSE:
                listInts->traverseListReverse();
                break;

            //Prints value of the current head
            case PRINT_HEAD:
                listInts->printHeadVal();

                //Printing list
                listInts->traverseList();
                break;

            //Prints value of the current tail
            case PRINT_TAIL:
                listInts->printTailVal();

                //Printing list
                listInts->traverseList();
                break;
        }

        cout << "What would you like to do next?" << endl << endl;
        choice = showOptions();
    }
}


/**********************************************************************
** Description: Member function findValue asks the user to enter a 
**              value. Uses validInput function to determine if the 
**              value is valid. If not valid, the function will have
**              the user enter another value. Returns the value.
**********************************************************************/
int Menu::findValue()
{
    int value;

    const int MIN_VAL = -100000000,
              MAX_VAL = 100000000;

    //User enters a value to be added to the list
    cout << "Please enter an integer from " << MIN_VAL 
         << " to " << MAX_VAL << ": ";

    //Determining if input is valid
    value = validInput(MIN_VAL, MAX_VAL);

    return value;
}


/**********************************************************************
** Description: Destructor for the Menu class that deletes the 
**              dynamically allocated memory.
**********************************************************************/
Menu::~Menu()
{
    delete listInts;
}