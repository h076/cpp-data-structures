#include "singlyLinkedList.hpp"
#include <iostream>

int main() {
    LinkedList list;

    list.printList();

    //list.insertNode(77);

    list.printList();

    for(int i=0; i<20; i++) {
        list.insertNode(i);
    }

    list.printList();

    list.deleteAt(76);

    std::cout << "list length is " << list.length() << "\n";

    list.deleteAt(5);

    std::cout << "list length is " << list.length() << "\n";

    list.printList();
}
