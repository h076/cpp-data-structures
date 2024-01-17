#include "doublyLinkedList.hpp"
#include <iostream>

Node::Node() {
    data = 0;
    next = NULL;
}

Node::Node(int data) {
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
}

LinkedList::LinkedList() {
    head = NULL;
    tail = NULL;
    len = 0;
}

void LinkedList::insertNodeAt(int data, int index) {
    Node* node = new Node(data);

    // if no nodes exist in list
    if(len == 0) {
        head = node;
        tail = node;
        len++;
        return;
    }

    if(index > len) {
        std::cout << "index out of range \n";
        return;
    }

    // if node is to inserted at the start of the list
    if(index == 0) {
        node->next = head;
        head->prev = node;
        node->prev = tail;
        tail->next = node;
        head = node;
        len++;
        return;
    }

    // if node is to be the new tail
    if(index == len) {
        node->next = head;
        node->prev = tail;
        tail->next = node;
        head->prev = node;
        tail = node;
        len++;
        return;
    }

    Node* temp = head;

    for(int i=0; i<index; i++) {
        temp = temp->next;
    }

    temp->prev->next = node;
    node->prev = temp->prev;
    temp->prev = node;
    node->next = temp;
    len++;
    return;
}

int LinkedList::valueAt(int index) {
    if(index > len-1) {
        std::cout << "index out of range \n";
        return -1;
    }

    Node* temp = head;
    for(int i=0; i<index; i++) {
        temp = temp->next;
    }

    return temp->data;
}

bool LinkedList::searchFor(int find) {
    Node* temp = head;
    for(int i=0; i<len-1; i++) {
        if(temp->data == find) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void LinkedList::deleteAt(int index) {
    if(index > len-1) {
        std::cout << "index out of range \n";
        return;
    }

    if(index == 0) {
        if(len == 1) {
            head = NULL;
            tail = NULL;
            len--;
            return;
        }
        head = head->next;
        head->prev = tail;
        tail->next = head;
        len--;
        return;
    }

    if(index == len-1) {
        tail->prev->next = head;
        tail = tail->prev;
        head->prev = tail;
        len--;
    }

    Node* temp = head;
    for(int i=0; i<index; i++) {
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    len--;
    return;
}

int LinkedList::length() {
    return len;
}

void LinkedList::printList() {
    if(len == 0) {
        std::cout << "list is empty...\n";
        return;
    }

    Node* temp = head;

    std::cout << "printing list ...\n";

    while(temp != tail) {
        std::cout << temp->data << "\n";
        temp = temp->next;
    }

    std::cout << temp->data << "\n";
    return;
}
