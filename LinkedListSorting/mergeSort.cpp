#include "LinkedList.cpp"
#include <iostream>
#include <random>

void populateList(LinkedList<int> &);
void mergeSort(LinkedList<int> *);
void sort(Node<int> **);
Node<int> * merge(Node<int> *, Node<int> *);
void shuntingYard(Node<int> *, Node<int> **, Node<int> **);

int main() {
    LinkedList<int> list;

    populateList(list);

    std::cout << "List before merge sort ...\n";

    list.printList();

    mergeSort(&list);

    std::cout << "List after merge sort ...\n";

    list.printList();
    return 0;
}

void populateList(LinkedList<int> & list) {
    for(int i=0; i<100; i++) {
        list.insertNodeFront(rand() % 101);
    }
    return;
}

void mergeSort(LinkedList<int> * list) {
    Node<int>* ref = list->head;
    sort(&ref);
    list->head = ref;
    Node<int>* temp = list->head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    list->tail = temp;
}

void sort(Node<int> ** headRef) {
    Node<int>* head = *headRef;
    Node<int>* a;
    Node<int>* b;

    if(head == NULL || head->next == NULL) {
        return;
    }

    shuntingYard(head, &a, &b);
    sort(&a);
    sort(&b);
    *headRef = merge(a, b);
}

Node<int>* merge(Node<int> * a, Node<int> * b) {
    Node<int>* res = NULL;
    if(a == NULL) {
        return b;
    }else if(b == NULL) {
        return a;
    }

    if(a->data <= b->data) {
        res = a;
        res->next = merge(a->next, b);
    }else {
        res = b;
        res->next = merge(a, b->next);
    }
    return res;
}

void shuntingYard(Node<int> * head, Node<int> ** a, Node<int> ** b) {
    Node<int>* slow = head;
    Node<int>* fast = head->next;

    while(fast->next != NULL) {
        fast = fast->next;
        if(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *a = head;
    *b = slow->next;
    slow->next = NULL;
    (*b)->prev = NULL;
}
