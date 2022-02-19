#include <iostream>
using namespace std;

class Node {

private:
	int value; // ����� ������
	Node* leftChild = NULL; // ���� �ڽ�
	Node* rightChild = NULL; // ������ �ڽ�
	Node* next = NULL;

public:
	void setValue(int data) { this->value = data; }
	int getValue() { return this->value; }
	void setNext(Node* nextNode) { next = nextNode; } // ���� ��带 �����Ҵ����� �������
	Node* getNext(){ return next; }
};

class Queue {
private:
	Node* front; // ����Ʈ(����)
	Node* rear; // ����(����)
	int size = 0;

public:
	bool enqueue(int value);
	bool dequeue(int* value);
	bool empty() {
		if (this->size == 0)
			return true;
		else
			return false;
	}
};

bool Queue::enqueue(int data) { 
	Node* newNode = new Node; // ���� �Ҵ�
	newNode->setValue(data); // setValue �Լ��� ���� Node�� �� ����
	if (size < 5)
		if (empty()) // empty=true�϶� ó������ �ϳ��� ���ԵǹǷ� front�Ӱ� ���ÿ� rear�̴�.
			front = rear = newNode;

		else { // empty=false 1�� �̻� ������ ��
			rear->setNext(newNode); // rear ���� ���ο� ��� ����
			rear = rear->getNext(); // rear�� �� �������� ��ġ�ؾ� �ϹǷ� rear�� ��ġ�� ���� ������ �� ���� �̵�
		}
	else {
		cout << "ERROR 300" << endl; // �� ������ ������ ������ �� ������ ���
		return false;
	}
	size++;

	return true;
}

bool Queue::dequeue(int* data) {
	if (size > 0) {

	}
	else {

		cout << "Error 400" << endl;
		return false;
	}
	size--;

	return true;
}


int main(void)
{
	string command;

	while (1)
	{
		cout << "CMD>> ";
		cin >> command;

		if (command == "Enqueue") {

		}
		else if (command == "Dequeue") {

		}
		else if (command == "Print_Queue") {

		}
		else if (command == "SEARCH") {

		}
		else if (command == "PRINT") {

		}
		else if (command == "EXIT") {

		}
		else
			cout << "ERROR 100" << endl;
	}

	return 0;
}