#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    
    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class Stack {
    Node* head;
    int size;
public:
    Stack() {
        this->head = nullptr;
        this->size = 0;
    }
    
    ~Stack() {
        Node* current = this->head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
    
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = this->head;
        this->head = newNode;
        size++;
    }
    
    int pop() {
        
        if(this->head == nullptr) {
            cout << "The stack is empty." << endl;
            return -1;
        }
        Node* temp = this->head;
        this->head = temp->next;
        
        int value = temp->data;
        delete temp;
        size--;
        return value;
    }
    
    int peek() {
        
        if(this->head == nullptr) {
            cout << "The stack is empty." << endl;
            return -1;
        }
        return this->head->data;
    }
    
    bool isEmpty() {
        return this->head == nullptr;
    }
    
    void display() {
        if(this->size == 0) {
            cout << "The stack is empty." << "\n\n";
            return;
        }
        Node* currentNode = this->head;
        cout << "Stack: ";
        while(currentNode != nullptr) {
            if(currentNode->next == nullptr) {
                cout << currentNode->data << " -> NULL";
            } else {
                cout << currentNode->data << " -> ";
            }
            currentNode = currentNode->next;
        }
        cout << "\n\n";
    }
};

int main() {
    Stack stack;
    cout << "Initialized stack" << endl;
    stack.display();
    
    cout << "Pushed 2 to stack" << endl;
    stack.push(2);
    stack.display();
    
    cout << "Pushed 3 to stack" << endl;
    stack.push(3);
    stack.display();
    
    cout << "Pushed 4 to stack" << endl;
    stack.push(4);
    stack.display();
    
    cout << "Pushed 5 to stack" << endl;
    stack.push(5);
    stack.display();
    
    int value1 = stack.pop();
    cout << "Pop from stack value: " << value1 << endl;
    cout << "Stack after pop" << endl;
    stack.display();
    
    int value2 = stack.peek();
    cout << "Peek from stack value: " << value2 << endl;
    cout << "Stack after peek" << endl;
    stack.display();
 
    string isEmpty1 = stack.isEmpty() == 0 ? "false" : "true";
    cout << "Testing if stack is empty: " << isEmpty1 << endl;
    
    int value3 = stack.pop();
    cout << "Pop from stack value: " << value3 << endl;
    cout << "Stack after pop" << endl;
    stack.display();
    
    int value4 = stack.pop();
    cout << "Pop from stack value: " << value4 << endl;
    cout << "Stack after pop" << endl;
    stack.display();
    
    int value5 = stack.pop();
    cout << "Pop from stack value: " << value5 << endl;
    cout << "Stack after pop" << endl;
    stack.display();
    
    string isEmpty2 = stack.isEmpty() == 0 ? "false" : "true";
    cout << "Testing if stack is empty: " << isEmpty2 << endl;
}

