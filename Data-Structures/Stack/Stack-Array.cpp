#include <iostream>
using namespace std;

#define MAX 1000

class Stack {
    int top;
    
public:
    int a[MAX]; // maximum size of the stack.
    Stack() {
        this->top = -1;
    }
    
    bool push(int x) {
        if(top >= (MAX - 1)) {
            cout << "Stack overflow" << endl;
            return false;
        } else {
            a[++top] = x;
            cout << x << " pushed into stack" << endl;
            return true;
        }
    }
    
    int pop() {
        if(top < 0) {
            cout << "Stack underflow" << endl;
            return 0;
        }
        int x = a[top--];
        return x;
    }
    
    int peek() {
        if(top < 0) {
            cout << "The stack is empty" << endl;
            return 0;
        }
        return a[top];
    }
    
    int isEmpty() {
        return (top < 0);
    }
    
    void display() {
        for(int i = top; i > -1; i--) {
            cout << a[i] << endl;
        }
    }
    
};

int main()
{
    Stack s;
    s.push(10);
    s.display();
    cout << endl;
    s.push(20);
    s.display();
    cout << endl;
    s.push(30); 
    s.display();
    cout << endl;
    
    cout << "Element " << s.pop() << " popped from the stack" << endl;
    s.display();
    
    cout << "Top element is: " << s.peek() << endl; 
}
