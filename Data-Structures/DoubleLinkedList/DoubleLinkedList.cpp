#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoubleLinkedList {
public:
    Node* head;
    Node* tail;
    int length;

    DoubleLinkedList() {
        this->length = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }

    ~DoubleLinkedList() {
        Node* current = this->head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void insertAtBeginning(int data) {
        Node* node = new Node(data);
        length++;

        if (!head) {
            this->head = node;
            this->tail = node;
            return;
        }

        node->next = this->head;
        this->head->prev = node;
        this->head = node;
    }

    void insertAtEnd(int data) {
        Node* node = new Node(data);
        length++;

        if (!tail) {
            this->head = node;
            this->tail = node;
            return;
        }

        node->prev = this->tail;
        this->tail->next = node;
        this->tail = node;
    }

    void insertAtPosition(int data, int position) {
        if (position > length + 1 || position < 1) {
            cout << "Invalid position." << endl;
            return;
        }

        if (position == 1) {
            insertAtBeginning(data);
            return;
        }

        if (position == length + 1) {
            insertAtEnd(data);
            return;
        }

        Node* node = new Node(data);

        Node* currentNode = this->head;
        int currentPosition = 1;
        while (currentPosition != position) {
            currentPosition++;
            currentNode = currentNode->next;
        }
        currentNode->prev->next = node;
        node->prev = currentNode->prev;
        node->next = currentNode;
        currentNode->prev = node;
        this->length++;
    }

    void deleteFromBeginning() {
        if (this->head == nullptr) {
            cout << "There is nothing to delete." << endl;
            return;
        }

        Node* temp = this->head;

        if (this->head == this->tail) {
            this->head = nullptr;
            this->tail = nullptr;
        }
        else {
            this->head = this->head->next;
            this->head->prev = nullptr;
        }

        delete temp;
        this->length--;
    }

    void deleteFromEnd() {
        if (this->tail == nullptr) {
            cout << "There is nothing to delete." << endl;
            return;
        }

        Node* temp = this->tail;

        if (this->head == this->tail) {
            this->head = nullptr;
            this->tail = nullptr;
        }
        else {
            this->tail = this->tail->prev;
            this->tail->next = nullptr;
        }

        delete temp;
        this->length--;
    }

    void deleteFromPosition(int position) {
        if (position < 1 || position > this->length) {
            cout << "Invalid position." << endl;
            return;
        }
        if (position == 1) {
            deleteFromBeginning();
            return;
        }
        if (position == length) {
            deleteFromEnd();
            return;
        }

        Node* currentNode = this->head;
        int currentPosition = 1;

        while (currentPosition != position) {
            currentNode = currentNode->next;
            currentPosition++;
        }

        currentNode->next->prev = currentNode->prev;
        currentNode->prev->next = currentNode->next;
        delete currentNode;
        this->length--;
    }

    void printListForward() {
        Node* currentNode = this->head;
        cout << "Forward List: ";
        while (currentNode != nullptr) {
            cout << currentNode->data;
            if (currentNode->next != nullptr) {
                cout << " -> ";
            }
            currentNode = currentNode->next;
        }
        cout << endl;
    }

    void printLisReverse() {
        Node* currentNode = this->tail;
        cout << "Reverse List: ";
        while (currentNode != nullptr) {
            cout << currentNode->data;
            if (currentNode->prev != nullptr) {
                cout << " -> ";
            }
            currentNode = currentNode->prev;
        }
        cout << endl;
    }

};

int main() {
    DoubleLinkedList DLL;

    cout << "Initial List (should be empty):" << endl;
    DLL.printListForward();
    DLL.printLisReverse();
    cout << endl;

    cout << "Insert 5 at the beginning:" << endl;
    DLL.insertAtBeginning(5);
    DLL.printListForward();
    DLL.printLisReverse();
    cout << endl;

    cout << "Insert 30 at the end:" << endl;
    DLL.insertAtEnd(30);
    DLL.printListForward();
    DLL.printLisReverse();
    cout << endl;

    cout << "Insert 25 at position 2:" << endl;
    DLL.insertAtPosition(25, 2);
    DLL.printListForward();
    DLL.printLisReverse();
    cout << endl;

    cout << "Insert 20 at position 2:" << endl;
    DLL.insertAtPosition(20, 2);
    DLL.printListForward();
    DLL.printLisReverse();
    cout << endl;

    cout << "Insert 15 at position 2:" << endl;
    DLL.insertAtPosition(15, 2);
    DLL.printListForward();
    DLL.printLisReverse();
    cout << endl;

    cout << "Insert 10 at position 2:" << endl;
    DLL.insertAtPosition(10, 2);
    DLL.printListForward();
    DLL.printLisReverse();
    cout << endl;

    cout << "Delete from the beginning:" << endl;
    DLL.deleteFromBeginning();
    DLL.printListForward();
    DLL.printLisReverse();
    cout << endl;

    cout << "Delete from the end:" << endl;
    DLL.deleteFromEnd();
    DLL.printListForward();
    DLL.printLisReverse();
    cout << endl;

    cout << "Delete from position 3:" << endl;
    DLL.deleteFromPosition(3);
    DLL.printListForward();
    DLL.printLisReverse();
    cout << endl;
}
