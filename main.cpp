/**********************************************************************
** Program name: lab6
** Author:       Rebekah Koon
** Date:         7/30/19
** Description:  This program creates a doubly linked list of Node
**               objects whose values are inputted by the user. The 
**               program uses the Menu class to create this list. 
**               Choices are presented to the user which they can 
**               perform. Options include adding a head or tail to the
**               list, deleting the head or tail, traversing the list, 
**               traversing the list in reverse order, printing the 
**               head or tail, and creating a list by reading a file.
**               After the user is finished, they select quit to end
**               the program.
**********************************************************************/

#include "Menu.hpp"
#include <iostream>

using std::cout;
using std::cin;

int main()
{
    Menu programMenu;
    
    cout << "Note: extra credit is implemented." << endl << endl;

    //Starts the program by having user select their option to perform
    programMenu.startProgram();

    cout << "Goodbye!" << endl;

    return 0;
}