/**********************************************************************
** Program name: lab6
** Author:       Rebekah Koon
** Date:         7/30/19
** Description:  Header file for the Menu class, which has functions to
**               start the program, show options the user can choose to
**               perform on a doubly linked list, and carry out the 
**               desired action for the list. Also contains a function
**               for the user to input a value for either the head or
**               tail of the list.
**********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include "validInput.hpp"
#include "DoublyLinkedList.hpp"

#include <iostream>

using std::cout;
using std::endl;

//Used to determine which option the user wants to perform
enum MenuChoices {ADD_HEAD = 1, ADD_TAIL, DELETE_HEAD, DELETE_TAIL, 
                  TRAVERSE_REVERSE, PRINT_HEAD, PRINT_TAIL, QUIT};

class Menu
{
    private:
        DoublyLinkedList *listInts;

    public:
        Menu();
        int showOptions();
        void startProgram();

        int findValue();

        ~Menu();
};

#endif