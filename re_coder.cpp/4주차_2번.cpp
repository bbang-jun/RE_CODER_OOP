#include <iostream>
#include <cstring>
#include <stdlib.h>
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
private:
	Node* head;

public:
	Revolver()// Revolver Ŭ������ ������
	{
		head = NULL;
		Node* curnode = new Node;

			for (int i = 0; i < 6; i++) // Revolver�� �����ڿ��� 6���� ��� ����(������ �䱸����)
			{
				if (head == NULL) // head�� NULL ������ ���
				{
					head = new Node;
					curnode = head;
					head->setBullet(false); // false�� �Ѿ�
					head->setNext(NULL);

				}
				else
				{
					curnode->setNext(new Node);
					curnode = curnode->getNext();
					curnode->setBullet(true); // true�� �Ѿ�x
					if(i==5)
						curnode->setNext(head); // �� ���� �ִ� curnode�� �� ó���� ����� head�� ����Ŵ(circle link)
					else
						curnode->setNext(NULL);
					
				}
			}

		
		commandRotate(); // head�� �Ѿ��� ��� �����Ƿ� �Ѿ��� ��ġ�� �������� �ٲٱ� ���� rotate�� ����
	}


	bool commandShoot()
	{
		Node* curnode = head;

		if (head->getBullet() == false)
			return false;
		else
			return true;
		// head = head->getNext(); (��� ��带 �̵��Ϸ��� �������� �ۼ������� ������� ���ϹǷ� 
	}

	void moveHead()
	{
		head = head->getNext();
	}

	void commandRotate() // �������� ��带 ��������ŭ�� ���� ���� �̵�
	{
		random_device rd; // �õ尪�� ��� ���� random_device ����
		mt19937 rotate(rd()); // random_device�� ���� ���� ���� ���� �ʱ�ȭ
		uniform_int_distribution<> random(1, 100); // �������� 1~100��ŭ rotate��
		
		int headPosition = random(rotate);

		for (int i = headPosition; i >= 1; i--)
		{
			head = head->getNext();
		}
	}
};

int main(void)
{
	string input;

	Revolver* revolver = new Revolver;

	cout << "Command list(shoot/rotate)" << endl;

	while (1)
	{
		cout << "CMD>> ";
		cin >> input;

		if (strcmp(input.c_str(), "shoot") == 0)
		{
			if (revolver->commandShoot() == false) // �Ѿ� �߻� O (����=false)
			{
				cout << "You Died..." << endl;

				break;
			}

			else if (revolver->commandShoot() == true) // �Ѿ� �߻� X (����=true)
				cout << "You Survived!" << endl;

			revolver->moveHead();
		}

		else if (input == "rotate")
		{
			revolver->commandRotate();
			system("cls");
		}
		else
			cout << "plz check your Command(shoot/rotate)" << endl;
	}


		delete revolver;
	return 0;
}