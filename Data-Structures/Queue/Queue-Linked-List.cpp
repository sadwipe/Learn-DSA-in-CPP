#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Queue {
    Node* front;
    Node* rear;
    int length;

public:
    Queue() {
        this->front = nullptr;
        this->rear = nullptr;
        this->length = 0;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() {
        return this->front == nullptr;
    }

    void enqueue(int data) {
        Node* node = new Node(data);
        length++;
        if (isEmpty()) {
            this->front = this->rear = node;
            return;
        }
        this->rear->next = node;
        this->rear = node;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "The Queue is empty." << endl;
            return -1;
        }
        
        int value = this->front->data;
        Node* temp = this->front;
        
        this->front = this->front->next;
        
        delete temp;
        length--;
        

        if (this->front == nullptr) {
            this->rear = nullptr;
        }

        return value;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "The Queue is empty." << endl;
            return -1;
        }
        return this->front->data;
    }

    int getRear() {
        if (isEmpty()) {
            cout << "The Queue is empty." << endl;
            return -1;
        }
        return this->rear->data;
    }

    int getLength() {
        return this->length;
    }

    void display() {
        if (isEmpty()) {
            cout << "The queue is empty." << endl;
            return;
        }
        Node* currentNode = this->front;
        while (currentNode != nullptr) {
            if (currentNode->next == nullptr) {
                cout << currentNode->data << " -> NULL\n\n";
                break;
            }
            cout << currentNode->data << " -> ";
            currentNode = currentNode->next;
        }
    }
};

int main() {
    Queue queue;
    
    cout << "Test isEmpty()" << endl;
    cout << (queue.isEmpty() ? "The queue is empty" : "The queue is not empty") << "\n\n";

    queue.enqueue(1);
    cout << "Enqueued 1" << "\n";
    queue.display();

    queue.enqueue(2);
    cout << "Enqueued 2" << "\n";
    queue.display();

    queue.enqueue(3);
    cout << "Enqueued 3" << "\n";
    queue.display();

    cout << "The front is: " << queue.getFront() << endl;
    cout << "The rear is: " << queue.getRear() << endl;

    cout << "\nThe lenght of the queue is: " << queue.getLength() << "\n\n\n";

    cout << "Dequeued " << queue.dequeue() << "\n";
    queue.display();

    cout << "\nDequeued " << queue.dequeue() << "\n";
    queue.display();

    cout << "\nDequeued " << queue.dequeue() << "\n";
    queue.display();
}
