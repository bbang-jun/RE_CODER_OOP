#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <random>
using namespace std;

class Node
{
private:
	Node* next=NULL; // 다음 노드
	bool bullet; // 총알의 유무를 확인하는 노드의 데이터 부분

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
	
	Revolver()// Revolver 클래스의 생성자
	{
		for (int i = 0; i < 6; i++) // Revolver의 생성자에서 6개의 노드 연결(문제의 요구사항)
		{
			Node* makeNode = new Node;

			if (head == NULL) // head가 NULL 상태인 경우
			{
				curnode = head;
				head = makeNode; // 동적할당으로 생성한 노드를 head에 대입
				head->setBullet(false); // false가 총알
				head->setNext(NULL); // 다음 노드가 아직 생성되지 않았으므로 다음 노드는 NULL로 초기화
			}
			else
			{
				curnode->setNext(makeNode);
				curnode = curnode->getNext();
				curnode->setBullet(true); // true는 총알x
				curnode->setNext(NULL);
			}
		}
		curnode->setNext(head); // 맨 끝에 있는 curnode가 맨 처음의 노드인 head를 가리킴(circle link)
		commandRotate(); // head에 총알이 들어 있으므로 총알의 위치를 랜덤으로 바꾸기 위해 rotate를 해줌
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

	void commandRotate() // 리볼버의 헤드를 랜덤값만큼의 다음 노드로 이동
	{
		random_device rd; // 시드값을 얻기 위한 random_device 생성
		mt19937 rotate(rd()); // random_device를 통해 난수 생성 엔진 초기화
		uniform_int_distribution<> random(1, 10); // 랜덤으로 1~10만큼 rotate함
		
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
			if (revolver->commandShoot() == false) // 총알 발사 O (죽음=false)
			{
				cout << "You Died..." << endl;

				break;
			}


			else if (revolver->commandShoot() == true) // 총알 발사 X (살음=true)
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