#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <random>
using namespace std;

class Node
{
private:
	Node* next=NULL; // ���� ���
	bool bullet; // �Ѿ��� ������ Ȯ���ϴ� ����� ������ �κ�

public:
	void setNext(Node* nextNode) { this->next = nextNode; }
	Node* getNext() { return next; }

	void setBullet(bool Bullet) { this->bullet = Bullet; }
	bool getBullet() { return bullet; }
};

class Revolver
{
public:
	Node* head;
	Node* curnode;
	
	Revolver()// Revolver Ŭ������ ������
	{
		for (int i = 0; i < 6; i++) // Revolver�� �����ڿ��� 6���� ��� ����(������ �䱸����)
		{
			Node* makeNode = new Node;

			if (head == NULL) // head�� NULL ������ ���
			{
				curnode = head;
				head = makeNode; // �����Ҵ����� ������ ��带 head�� ����
				head->setBullet(false); // false�� �Ѿ�
				head->setNext(NULL); // ���� ��尡 ���� �������� �ʾ����Ƿ� ���� ���� NULL�� �ʱ�ȭ
			}
			else
			{
				curnode->setNext(makeNode);
				curnode = curnode->getNext();
				curnode->setBullet(true); // true�� �Ѿ�x
				curnode->setNext(NULL);
			}
		}
		curnode->setNext(head); // �� ���� �ִ� curnode�� �� ó���� ����� head�� ����Ŵ(circle link)
		commandRotate(); // head�� �Ѿ��� ��� �����Ƿ� �Ѿ��� ��ġ�� �������� �ٲٱ� ���� rotate�� ����
	}



	bool commandShoot()
	{
		Node* curnode = head;

		if (head->getBullet() == false)
			return false;
		else
			return true;

		head = head->getNext();
	}

	void commandRotate() // �������� ��带 ��������ŭ�� ���� ���� �̵�
	{
		random_device rd; // �õ尪�� ��� ���� random_device ����
		mt19937 rotate(rd()); // random_device�� ���� ���� ���� ���� �ʱ�ȭ
		uniform_int_distribution<> random(1, 10); // �������� 1~10��ŭ rotate��
		
		int headlocation = random(rotate);

		for (int i = headlocation; i >= 1; i--)
		{
			head = head->getNext();
		}
	}
};

int main(void)
{
	string input;

	Revolver* revolver=new Revolver;

	cout << "Command list(shoot/rotate)" << endl;

	while (1)
	{
		cout << "CMD>> ";
		cin >> input;

		if (input == "shoot")
		{
			if (revolver->commandShoot() == false) // �Ѿ� �߻� O (����=false)
			{
				cout << "You Died..." << endl;

				break;
			}


			else if (revolver->commandShoot() == true) // �Ѿ� �߻� X (����=true)
				cout << "You Survived!" << endl;
		}

		else if (input == "rotate")
		{
			revolver->commandRotate();
		}
		else
			cout << "plz check your Command(shoot/rotate)";
	}


		delete revolver;
	return 0;
}