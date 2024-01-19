#include <iostream>

template <typename T>
class Node {
   public:
        T data;
        Node* next;
        Node* prev;

        Node<T>();
        Node<T>(T data);
};

template <typename T>
class LinkedList {
    public:
        Node<T>* head;
        Node<T>* tail;
        int len;

        LinkedList<T>();

        void insertNodeAt(T data, int index);
        int valueAt(int index);
        bool searchFor(T val);
        void deleteAt(int index);
        int length();
        void printList();
};

template <typename T>
Node<T>::Node() {
    data = 0;
    next = NULL;
}

template <typename T>
Node<T>::Node(T data) {
    this->data = data;
    next = NULL;
    prev = NULL;
}

template <typename T>
LinkedList<T>::LinkedList() {
    head = NULL;
    tail = NULL;
    len = 0;
}

template <typename T>
void LinkedList<T>::insertNodeAt(T data, int index) {
    Node<T>* node = new Node(data);

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

    Node<T>* temp = head;

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

template <typename T>
int LinkedList<T>::valueAt(int index) {
    if(index > len-1) {
        std::cout << "index out of range \n";
        return -1;
    }

    Node<T>* temp = head;
    for(int i=0; i<index; i++) {
        temp = temp->next;
    }

    return temp->data;
}

template <typename T>
bool LinkedList<T>::searchFor(T find) {
    Node<T>* temp = head;
    for(int i=0; i<len-1; i++) {
        if(temp->data == find) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template <typename T>
void LinkedList<T>::deleteAt(int index) {
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

    Node<T>* temp = head;
    for(int i=0; i<index; i++) {
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    len--;
    return;
}

template <typename T>
int LinkedList<T>::length() {
    return len;
}

template <typename T>
void LinkedList<T>::printList() {
    if(len == 0) {
        std::cout << "list is empty...\n";
        return;
    }

    Node<T>* temp = head;

    std::cout << "printing list ...\n";

    while(temp != tail) {
        std::cout << temp->data << "\n";
        temp = temp->next;
    }

    std::cout << temp->data << "\n";
    return;
}

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
