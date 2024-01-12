
class Node {
   public:
        int data;
        Node* next;

        Node();
        Node(int data);
};

class LinkedList {
    public:
        Node* head;
        int len;

        LinkedList();

        void insertNode(int data);
        void deleteAt(int index);
        int length();
        void printList();
};
