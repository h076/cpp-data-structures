class Node {
   public:
        int data;
        Node* next;
        Node* prev;

        Node();
        Node(int data);
};

class LinkedList {
    public:
        Node* head;
        Node* tail;
        int len;

        LinkedList();

        void insertNodeAt(int data, int index);
        int valueAt(int index);
        bool searchFor(int val);
        void deleteAt(int index);
        int length();
        void printList();
};
