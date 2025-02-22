#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;

	// constructor for the node
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

class SingleLinkedList {
public:
	// head of the SLL
	Node* head;
	int length;

	SingleLinkedList() {
		this->head = NULL;
		this->length = 0;
	}

	void insertAtBeginning(int value) {
		this->length++;
		Node* node = new Node(value);
		node->next = this->head;
		this->head = node;
	}

	void insertAtEnd(int value) {
		Node* node = new Node(value);
		this->length++;
		if (this->head == NULL) {
			this->head = node;
			return;
		}
		Node* currentNode = this->head;
		while (currentNode->next != NULL) {
			currentNode = currentNode->next;
		}
		currentNode->next = node;
	}
	
	void insertAtPosition(int position, int value) {
		if (position < 1 || position > length + 1) {
			cout << "The position is higher than the length of the Linked List." << endl;
			return;
		}

		if (position == 1) {
			insertAtBeginning(value);
			return;
		}
		Node* node = new Node(value);
		this->length++;

		Node* currentNode = this->head;
		int currentPosition = 1;

		while (currentPosition < position - 1) {
			currentNode = currentNode->next;
			currentPosition++;
		}
		node->next = currentNode->next;
		currentNode->next = node;
	}

	void deleteFromBeginning() {
		if (this->head == NULL) {
			cout << "The Linked List is already empty." << endl;
			return;
		}
		Node* temp = this->head;
		this->head = this->head->next;
		delete temp;
		this->length--;
	}

	void deleteFromEnd() {
		if (this->head == NULL) {
			cout << "The Linked List is already empty." << endl;
			return;
		}
		this->length--;
		if (this->head->next == NULL) {
			delete this->head;
			this->head = NULL;
			return;
		}

		Node* currentNode = this->head;
		while (currentNode->next->next != NULL) {
			currentNode = currentNode->next;
		}
		delete currentNode->next;
		currentNode->next = NULL;
	}

	void deleteFromPosition(int position) {
		if (position < 1 || position > length) {
			cout << "The position is higher than the length of the Linked List." << endl;
			return;
		}
		
		this->length--;
		
		if (position == 1) {
			Node* temp = this->head;
			this->head = this->head->next;
			delete temp;
			return;
		}
		
		int currentPosition = 1;
		Node* currentNode = this->head;
		while (currentPosition < position - 1) {
			currentNode = currentNode->next;
			currentPosition++;
		}
		Node* temp = currentNode->next;
		currentNode->next = temp->next;
		delete temp;
	}

	void display() {
		if (this->head == NULL) {
			cout << "There is nothing to display, the head of the Linked List is NULL." << endl;
			return;
		}
		Node* temp = this->head;
		while (temp != NULL) {
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << "NULL";
	}

};

int main() {
	SingleLinkedList list1;

	// Insert elements at the end
	list1.insertAtEnd(10);
	list1.insertAtEnd(20);

	// Insert element at the beginning
	list1.insertAtBeginning(5);

	// Insert element at a specific position
	list1.insertAtPosition(3, 15);

	cout << "Linked list after insertions: ";
	list1.display();

	// Delete element from the beginning
	list1.deleteFromBeginning();
	cout << "\nLinked list after deleting from beginning: ";
	list1.display();

	// Delete element from the end
	list1.deleteFromEnd();
	cout << "\nLinked list after deleting from end: ";
	list1.display();

	// Delete element from a specific position
	list1.deleteFromPosition(2);
	cout << "\nLinked list after deleting from position 2: ";
	list1.display();

	return 0;
}
