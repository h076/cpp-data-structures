#include <iostream>

// Interface

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
        void insertNodeFront(T data);
        void insertNodeBack(T data);
        T valueAt(int index);
        Node<T> nodeAt(int index);
        bool searchFor(T val);
        void deleteAt(int index);
        int length();
        void printList();
};

// Implementation

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
void LinkedList<T>::insertNodeFront(T data) {
    insertNodeAt(data, 0);
    return;
}

template <typename T>
void LinkedList<T>::insertNodeBack(T data) {
    insertNodeAt(data, len);
    return;
}

template <typename T>
void LinkedList<T>::insertNodeAt(T data, int index) {
    Node<T>* node = new Node(data);

    // if no nodes exist in list
    if(len == 0) {
        head = node;
        len++;
        return;
    }

    if(index > len) {
        std::cout << "index out of range \n";
        return;
    }

    // if node is to inserted at the start of the list
    if(index == 0) {
        if(len == 1) {
            tail = head;
        }
        node->next = head;
        head->prev = node;
        head = node;
        len++;
        return;
    }

    // if node is to be the new tail
    if(index == len) {
        if(len == 1) {
            head->next = node;
            node->prev = head;
            tail = node;
            return;
        }
        node->prev = tail;
        tail->next = node;
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
T LinkedList<T>::valueAt(int index) {
    if(index > len-1) {
        std::cout << "index out of range \n";
        return -1;
    }

    Node<T>* temp = head;
    for(int i=0; i<index+1; i++) {
        temp = temp->next;
    }

    return temp->data;
}

template <typename T>
Node<T> LinkedList<T>::nodeAt(int index) {
    if(index>len-1) {
        std::cout << "index out of range\n";
        return NULL;
    }

    Node<T> * temp = head;
    for(int i=0; i<index+1; i++) {
        temp = temp->next;
    }
    return temp;
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
            len--;
            return;
        }
        head = head->next;
        head->prev = NULL;
        len--;
        return;
    }

    if(index == len-1) {
        if(len == 2) {
            head->next = NULL;
            tail == NULL;
            len--;
            return;
        }
        tail->prev->next = NULL;
        tail = tail->prev;
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

    while(temp != NULL) {
        std::cout << temp->data << ", ";
        temp = temp->next;
    }

    std::cout << "\n";
    return;
}
