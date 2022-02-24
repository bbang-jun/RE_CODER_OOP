#include <iostream>
#include <cstring>
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
	void setLeftChild(Node* leftNode) { leftChild = leftNode; } // ���� �ڽ�
	Node* getLeftChild() { return leftChild; }
	void setRightChild(Node* rightNode) { rightChild = rightNode; } // ������ �ڽ�
	Node* getRightChild() { return rightChild; }
};


class Tree {
private:
	Node* root;
public:
	Tree() {
		root = NULL;
	}
	Node* getRoot() { return root; }
	void INSERT(Node*curNode, int dequeue_num);
	bool SEARCH(int data);
	void PRINT(string command); // ��� �Լ�
	void PRE(Node* curNode); // ���� ��ȸ �Լ�
	void POST(Node* curNode); // ���� ��ȸ �Լ�
	void IN(Node* curNode); // ���� ��ȸ �Լ�
};

void Tree::INSERT(Node*curNode, int dequeue_num) {
	if (root == NULL) { // ��Ʈ ��尡 ���� ���
		Node* newNode = new Node;
		newNode->setValue(dequeue_num);
		newNode->setLeftChild(NULL);
		newNode->setRightChild(NULL);
		root = curNode = newNode;
	}
	else if (curNode->getValue()>dequeue_num) { 
		if (curNode->getLeftChild() == NULL) {
			Node* newNode = new Node;
			newNode->setValue(dequeue_num);
			newNode->setLeftChild(NULL);
			newNode->setRightChild(NULL);
			curNode->setLeftChild(newNode);
		}
		else { // ���� �ڽ��� ���� ��� INSERT �Լ��� �ٽ� ���������ν� ���� ����� ��ġ�� ���� �ڽ����� �̵�
			INSERT(curNode->getLeftChild(), dequeue_num);
		}
	}
	else if (curNode->getValue()<dequeue_num) { // ������ �ڽ��� ���� ���
		if (curNode->getRightChild() == NULL) {
			Node* newNode = new Node;
			newNode->setValue(dequeue_num);
			newNode->setLeftChild(NULL);
			newNode->setRightChild(NULL);
			curNode->setRightChild(newNode);
		}
		else {
			INSERT(curNode->getRightChild(), dequeue_num);
		}
	}
}

bool Tree::SEARCH(int data) {
	Node* curNode = root;
	while (curNode != NULL) {
		if (curNode->getValue() == data) {
			return true;
		}
		else if (curNode->getValue() != data) {
			if (curNode->getValue() > data) {
				curNode = curNode->getLeftChild();
			}
			else if (curNode->getValue() < data) {
				curNode = curNode->getRightChild();
			}
		}
	}
	return false;
}

void Tree::PRINT(string command) { // ��� ����
	if (root == NULL) {
		cout << "Error 700";
	}
	if (command == "PRE") {
		PRE(root);
	}
	else if (command == "POST") {
		POST(root);
	}
	else if (command == "IN") {
		IN(root);
	}
}

void Tree::PRE(Node* curNode) {

	if (curNode != NULL) {
		cout << curNode->getValue() << "\t";
		PRE(curNode->getLeftChild());
		PRE(curNode->getRightChild());
	}
}

void Tree::POST(Node* curNode) {

	if (curNode!=NULL) {
		POST(curNode->getLeftChild());
		POST(curNode->getRightChild());
		cout << curNode->getValue() << "\t";
	}
}

void Tree::IN(Node* curNode) {

	if (curNode != NULL) {
		IN(curNode->getLeftChild());
		cout << curNode->getValue() << "\t";
		IN(curNode->getRightChild());
	}
}

class Queue {
public:
	int size;
	Node* front; // ����Ʈ(����)
	Node* rear; // ����(����)
	Queue() {
		front = NULL;
		rear = NULL;
		size = 0;
	}
	bool enqueue(int value);
	bool dequeue(int value, Tree* tree);
	bool empty() {
		if (this->size == 0)
			return true;
		else
			return false;
	}
	void Print_Queue();
};

bool Queue::enqueue(int value) {
	Node* newNode = new Node; // ���� �Ҵ�
	newNode->setValue(value); // setValue �Լ��� ���� Node�� �� ����
	if (size < 5) {
		if (empty()) // empty=true�϶� ó������ �ϳ��� ���ԵǹǷ� front�Ӱ� ���ÿ� rear�̴�.
			front = rear = newNode;

		else { // empty=false 1�� �̻� ������ ��
			rear->setNext(newNode); // rear ���� ���ο� ��� ����
			rear = rear->getNext(); // rear�� �� �������� ��ġ�ؾ� �ϹǷ� rear�� ��ġ�� ���� ������ �� ���� �̵�
		}
	}
	else {
		cout << "Error 300" << endl;
		return false;
	}
	size++;

	return true;
}

bool Queue::dequeue(int value, Tree* tree) {
	Node* curNode = front;
	Node* temp;
	if (size > 0) {
		if(value>size){
			value = size; 
		}
		for (int i = 0; i < value; i++) {
			tree->INSERT(tree->getRoot(), curNode->getValue());
			temp = curNode;
			curNode = curNode->getNext();
			front = curNode;
			delete temp;
			size--;
		}
	}
	else
		return false;

	return true;
}

void Queue::Print_Queue() {
	Node* curNode = front;
	if (curNode == NULL)
		cout << "Error 500" << endl;
	else {
		while (curNode != NULL) {
			cout << curNode->getValue() << "\t";
			curNode = curNode->getNext();
		}
		cout << endl;
	}
}

int main(void)
{
	string command=" ";
	string print_way;
	int data = 0;
	char str[50];
	char commandStr[15];
	Queue* queue = new Queue;
	Tree* tree = new Tree;

	while (1)
	{
		cout << "CMD>> ";
		/*cin >> command;*/
		cin.getline(str, 20);
		strcpy(commandStr, str);
		char* commandPtr = strtok(commandStr, " \n"); // ����, ����(����)�� ���� �� ��ūȭ ����

		if (commandPtr == NULL) { // strtok�� �߶� ��ū�� �ƹ� �͵� ���� ���(�ƿ� �ƹ��͵� �Էµ��� �ʾ��� ��)
			cout << "Error 100" << endl;
			continue;
		}
		else 
			command = commandPtr;

		if (command == "Enqueue") {
			commandPtr = strtok(NULL, " "); // ������ ������ ������ ��(Enqueue�� �Է����� ��)
			if (commandPtr == NULL) // �ƹ��͵� �Է����� �ʾ��� ��
				cout << "Error 200" << endl;
			else {
				data = atoi(commandPtr); // ���ڿ��� ������ ��ȯ�Ͽ� int�� ���� data�� �־���
				commandPtr = strtok(NULL, " "); // ó���� �ڸ� ���� ���� �ٽ� ������ ���� �� ���� ��ūȭ

				if (commandPtr != NULL) // Enqueue ���� �ƹ��͵� ���� ��
					cout << "Error 200" << endl;
				else {
					if (!data) { // ������ �ƴ� ��� (��½� 0�� ����)
						cout << "Error 200" << endl;
					}
					else // ���� �϶� enqueue ����
						queue->enqueue(data);
				}
			}
		}
		else if (command == "Dequeue") {
			commandPtr = strtok(NULL, " ");
			if (commandPtr == NULL)
				cout << "Error 200" << endl;
			else {
				data = atoi(commandPtr);
				commandPtr = strtok(NULL, " ");

				if (commandPtr != NULL)
					cout << "Error 200" << endl;
				else {
					if (!data) 
						cout << "Error 200" << endl;
					else {
						if (!queue->dequeue(data, tree))
							cout << "Error 400" << endl;
					}
						

				}
			}	
		}
		else if (command == "Print_Queue") {
			queue->Print_Queue();
		}
		else if (command == "SEARCH") {
			commandPtr = strtok(NULL, " ");

			if (commandPtr == NULL)
				cout << "Error 200" << endl;
			else {
				data = atoi(commandPtr);
				commandPtr = strtok(NULL, " ");

				if (commandPtr != NULL)
					cout << "Error 200" << endl;
				else
					if (!data)
						cout << "Error 200" << endl;
					else {
						if (tree->SEARCH(data))
							cout << data << " is exists" << endl;
						else
							cout << "Error 600" << endl;
					}
			}
		}
		else if (command == "PRINT") {
			commandPtr = strtok(NULL, " ");
			if (commandPtr == NULL)
				cout << "Error 200" << endl;
			else {
				print_way = commandPtr;
				commandPtr = strtok(NULL, " ");
				if (commandPtr != NULL)
					cout << "Error 200" << endl;
				else {
					tree->PRINT(print_way);
					cout << endl;
				}
			}
		}
		else if (command == "EXIT") {
			break;
		}
		else
			cout << "Error 100" << endl;
	}

	delete queue;
	delete tree;
	return 0;
}