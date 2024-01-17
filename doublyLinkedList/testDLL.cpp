#include "doublyLinkedList.hpp"
#include <iostream>

int main() {
    LinkedList list;

    list.printList();

    list.insertNodeAt(77, 0);

    list.printList();

    for(int i=0; i<20; i++) {
        list.insertNodeAt(i, 0);
    }

    list.printList();

    list.deleteAt(76);

    std::cout << "list length is " << list.length() << "\n";

    list.deleteAt(5);

    std::cout << "list length is " << list.length() << "\n";

    list.printList();

}
