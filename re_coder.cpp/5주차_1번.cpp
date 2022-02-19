#include <iostream>
using namespace std;

class Node {

private:
	int value; // 노드의 데이터
	Node* leftChild = NULL; // 왼쪽 자식
	Node* rightChild = NULL; // 오른쪽 자식
	Node* next = NULL;

public:
	void setValue(int data) { this->value = data; }
	int getValue() { return this->value; }
	void setNext(Node* nextNode) { next = nextNode; } // 다음 노드를 동적할당으로 만들어줌
	Node* getNext(){ return next; }
};

class Queue {
private:
	Node* front; // 프론트(선출)
	Node* rear; // 리어(후출)
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
	Node* newNode = new Node; // 동적 할당
	newNode->setValue(data); // setValue 함수를 통한 Node의 값 설정
	if (size < 5)
		if (empty()) // empty=true일때 처음으로 하나가 삽입되므로 front임과 동시에 rear이다.
			front = rear = newNode;

		else { // empty=false 1개 이상 존재할 때
			rear->setNext(newNode); // rear 다음 새로운 노드 생성
			rear = rear->getNext(); // rear는 맨 마지막에 위치해야 하므로 rear의 위치를 새로 생성한 끝 노드로 이동
		}
	else {
		cout << "ERROR 300" << endl; // 이 문장을 위에다 넣으면 왜 오류가 뜰까
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