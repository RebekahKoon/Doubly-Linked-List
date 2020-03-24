## Program name: lab6
## Author:       Rebekah Koon
## Date:         7/30/19
## Description:  This program creates a doubly linked list of values inputted
##               by the user. The user can add a head or tail, delete a head
##               or tail, traverse a list in reverse order, or print the

lab6: Node.o DoublyLinkedList.o Menu.o validInput.o main.o
	g++ -g Node.o DoublyLinkedList.o Menu.o validInput.o main.o -o lab6

Node.o: Node.cpp Node.hpp
	g++ -c Node.cpp

DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.hpp
	g++ -c DoublyLinkedList.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -c Menu.cpp

validInput.o: validInput.cpp validInput.hpp
	g++ -c validInput.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o lab6