#include <iostream>
#include "LinkedList.hpp"

int main() {
    LinkedList<int> intList;
    LinkedList<char> charList;

    intList.printList();

    intList.insertNodeAt(77, 0);
    charList.insertNodeAt('h', 0);
    charList.insertNodeAt('a', 1);
    charList.insertNodeAt('r', 2);
    charList.insertNodeAt('r', 3);
    charList.insertNodeAt('y', 4);

    charList.printList();
    intList.printList();

    for(int i=0; i<20; i++) {
        intList.insertNodeAt(i, 0);
    }

    intList.printList();

    intList.deleteAt(76);

    std::cout << "int list length is " << intList.length() << "\n";

    intList.deleteAt(5);
    charList.deleteAt(3);

    std::cout << "int list length is " << charList.length() << "\n";

    intList.printList();
    charList.printList();
}
