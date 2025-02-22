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

class CircularLinkedList {
	Node* head;
	Node* tail;
	int length;
public:

	CircularLinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
		this->length = 0;
	}

	void insertInEmptyList(int data) {
		if (this->head != nullptr) {
			cout << "The list is not empty." << endl;
			return;
		}
		Node* node = new Node(data);
		this->head = node;
		this->tail = node;
		node->next = node;
		length++;
	}

	void insertAtBeginning(int data) {
		if (this->head == nullptr) {
			insertInEmptyList(data);
			return;
		}
		Node* node = new Node(data);
		node->next = this->head;
		this->head = node;
		this->tail->next = this->head;
		length++;
	}

	void insertAtEnd(int data) {
		if (this->head == nullptr) {
			insertInEmptyList(data);
			return;
		}
		Node* node = new Node(data);
		this->tail->next = node;
		this->tail = node;
		this->tail->next = this->head;
		length++;
	}

	void insertAtPosition(int data, int position) {
		
		if (position < 1 || position > length + 1) {
			cout << "Invalid position." << endl;
			return;
		}
		
		if (this->head == nullptr) {
			insertInEmptyList(data);
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

		while (currentPosition != position - 1) {
			currentNode = currentNode->next;
			currentPosition++;
		}

		node->next = currentNode->next;
		currentNode->next = node;
		length++;
	}

	void deleteSingleNode() {
		delete head;
		this->head = nullptr;
		this->tail = nullptr;
		length--;
	}

	void deleteFirstNode() {
		if (this->head == nullptr) {
			cout << "The Circular Linked List is already empty." << endl;
			return;
		}
		if (this->head == this->tail) {
			deleteSingleNode();
			return;
		}

		Node* temp = this->head;
		this->head = this->head->next;
		this->tail->next = this->head;
		length--;
		delete temp;
	}

	void deleteLastNode() {
		if (this->tail == nullptr) {
			cout << "The Circular Linked List is already empty." << endl;
			return;
		}

		if (this->head == this->tail) {
			deleteSingleNode();
			return;
		}

		Node* temp = this->tail;
		Node* currentNode = this->head;

		while (currentNode->next != this->tail) {
			currentNode = currentNode->next;
		}

		currentNode->next = this->head;
		this->tail = currentNode;
		delete temp;
		length--;
	}

	void deleteSpecificNode(int position) {
		
		if (this->tail == nullptr) {
			cout << "The Circular Linked List is already empty." << endl;
			return;
		}

		if (position < 1 || position > length) {
			cout << "Invalid position." << endl;
			return;
		}
		
		if (position == 1) {
			deleteFirstNode();
			return;
		}

		if (position == length) {
			deleteLastNode();
			return;
		}

		Node* currentNode = this->head;
		int currentPosition = 1;

		while (currentPosition != position - 1) {
			currentNode = currentNode->next;
		}

		Node* temp = currentNode->next;
		currentNode->next = temp->next;
		delete temp;
		length--;
	}

	void display() {
		if(this->head == nullptr) {
			cout << "The list is empty.";
			return;
		}
		cout << "List: ";
		Node* currentNode = this->head;
		
		do {
			if (currentNode->next == this->head) {
				cout << currentNode->data;
			}
			else {
				cout << currentNode->data << " -> ";
			}
			currentNode = currentNode->next;
		} while (currentNode != this->head);

		cout << endl;
	}
};

int main() {

	CircularLinkedList CLL;

	cout << "Insert in empty value 10" << endl;
	CLL.insertInEmptyList(10);
	CLL.display();
	cout << endl;

	cout << "Insert at beginning value 5" << endl;
	CLL.insertAtBeginning(5);
	CLL.display();
	cout << endl;

	cout << "Insert at end value 20" << endl;
	CLL.insertAtEnd(20);
	CLL.display();
	cout << endl;

	cout << "Insert at position 3 value 15" << endl;
	CLL.insertAtPosition(15, 3);
	CLL.display();
	cout << endl;

	cout << "Delete first node" << endl;
	CLL.deleteFirstNode();
	CLL.display();
	cout << endl;

	cout << "Delete last node" << endl;
	CLL.deleteLastNode();
	CLL.display();
	cout << endl;

	cout << "Delete the second node" << endl;
	CLL.deleteSpecificNode(2);
	CLL.display();
	cout << endl;

	cout << "Insert numbers at positions 1, 3 and 4" << endl;
	CLL.insertAtPosition(5, 1);
	CLL.insertAtPosition(15, 3);
	CLL.insertAtPosition(20, 4);
	CLL.display();
	cout << endl;
}
