#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Queue {
public:
    int front;
    int rear;
    int arr[MAX_SIZE];
    
    Queue(): front(-1), rear(-1) {}
    
    bool isEmpty() {
        return front == -1 || front > rear;
    }
    
    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }
    
    int getFront() {
        if(isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
    
    int getRear() {
        if(isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[rear];
    }
    
    void enqueue(int val) {
        if(isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        
        if(isEmpty()) {
            front = 0;
        }
        arr[++rear] = val;
    }
    
    int dequeue() {
        if(isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int ans = arr[front++];
        if(isEmpty()) {
            front = rear = -1;
        }
        return ans;
    }
    
    void display() {
        if(isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue: ";
        for(int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        
        cout << endl << endl;
    }
};

int main() {
    Queue queue;
    cout << "Verify if the queue is empty" << endl;
    cout << (queue.isEmpty() == true ? "The queue is empty." : "The queue is not empty.") << "\n\n";
    
    cout << "Added 2 to queue, and verify if the queue is empty." << endl;
    queue.enqueue(2);
    cout << (queue.isEmpty() == true ? "The queue is empty." : "The queue is not empty.") << "\n\n";

    queue.display();
 
    cout << "Added 3 to queue" << endl;
    queue.enqueue(3);
    queue.display();
 
    cout << "Added 4 to queue" << endl;
    queue.enqueue(4);
    queue.display();
    
    cout << "Added 5 to queue" << endl;
    queue.enqueue(5);
    queue.display();
    
    cout << "Added 6 to queue" << endl;
    queue.enqueue(6);
    queue.display();
    
    cout << "Added 7 to queue" << endl;
    queue.enqueue(7);
    queue.display();

    cout << "Dequeue: " << queue.dequeue() << endl;
    queue.display();
    
    cout << "Dequeue: " << queue.dequeue() << endl;
    queue.display();
    
    cout << "Dequeue: " << queue.dequeue() << endl;
    queue.display();
}
