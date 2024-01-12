#include <iostream>
#include "singlyLinkedList.hpp"

Node::Node() {
    data = 0;
    next = NULL;
}

Node::Node(int data) {
    this->data = data;
    this->next = NULL;
}

LinkedList::LinkedList() {
    head = NULL;
    len = 0;
}

void LinkedList::insertNode(int data) {
    Node* node = new Node(data);

    if(len == 0) {
        len++;
        head = node;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = node;
    len++;

    return;
}

void LinkedList::deleteAt(int index) {
    Node* temp;

    if(len <= index || index < 0) {
        std::cout << "Index out of range!\n";
        return;
    }

    if(index == 0) {
        head = head->next;
        len--;
        return;
    }

    temp = head;
    for(int i=0; i<(index-1); i++) {
        temp = temp->next;
    }

    temp->next = temp->next->next;
    len--;
    return;
}

int LinkedList::length() {
    return len;
}

void LinkedList::printList() {
    Node* node = head;

    if(len == 0) {
        std::cout << "List contains no elements ... \n";
        return;
    }

    std::cout << "Printing list elements ... \n";

    while(node != NULL) {
        std::cout << node->data << "\n";
        node = node->next;
    }

    return;
}
