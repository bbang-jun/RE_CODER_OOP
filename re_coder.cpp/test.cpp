#include<iostream>
#include<cstring>
using namespace std;

class Node {

public:
    Node* next;
    string word;

    void setWord(string Word) { this->word = Word; }
    string getWord() { return word; }
    void setNext(Node* nextnode) { this->next = nextnode; } // ���� �����Ҵ� �� ��带 �Ű������� �޾ƿ� ����
    Node* getNext() { return next; }
};

class List {
public:

    Node* head;

    Node* curWord = head;

    void setHead(string Word) {
        Node* newnode = new Node; // �����Ҵ����� ��� Ŭ������ �����Ͽ� newnode ������ ��ü ����
        head = newnode; // head�� newnode ����
        head->word = Word; // head�� ��� word�� �Ű������� ���� Word�� ���� ����
        head->next = NULL; // head�� ��� next�� NULL ����(���� ��尡 �������� �ʾ����Ƿ� NULL)
    }

    Node* getHead() { return head; } // head�� ������ �� head�� word �κа� next�� �����;� �ϹǷ� Node *



    Node* InsertNode(string Word) {
        Node* curWord = head; // curWord ������ ��ü ���� �� head ����

        while (curWord->getNext() != NULL)  // ���� ����� ���� NULL�� ������ �ݺ�(curWord�� �� ������ �̵�)
            curWord = curWord->getNext();

        curWord->setNext(new Node); // ���ο� ��� ����
        curWord = curWord->getNext(); // curWord�� ���� ������ ���� ���� �̵�
        curWord->setWord(Word); // �̵��� ���ο� ��忡�� word�� �޾ƿ� 
        curWord->setNext(NULL); // NULL�� �����Ͽ� �����Ⱚ ����(���ο� ��� ������ ������ ����)

        return curWord;
    }

    bool checkingChain(string word) {               //���� �ܾ�� chain���� �Ǵ�
        Node* curnode = head;
        while (curnode->getNext() != NULL) {
            curnode = curnode->getNext();
        }
        string nextWord = curnode->getWord();

        char beforeWordBack = nextWord[nextWord.length() - 1]; // string beforeWordBack�� ��� �Ұ�(C++ ����(��)�� ��ȯ�ϱ� ���� ������ �����ڰ� �����ϴ�.)
        char nextWordFront = word[0];

        if (beforeWordBack == nextWordFront)
            return true;
        else
            return false;
    }
};

int main(void) {

    List* list = new List;

    string input;

    while (1)
    {
        cout << "CMD(Word/exit)>> ";

        cin >> input;

        if (input == "exit")
            break;

        else if ((input.back() >= 'A' && input.back() <= 'Z') || (input.back() >= 'a' && input.back() <= 'z'))
        {
            if (input.back() >= 'A' && input.back() <= 'Z')
                input.back() += 32;

            if (!(list->getHead()))
            {
                list->setHead(input);
                cout << list->head->word << "->" << endl;
            }
            else
            {
                if (list->checkingChain(input) == true)
                {
                    Node* curWord = list->head;

                    cout << curWord->getWord() << "->";
                    curWord = curWord->getNext();

                    while (curWord)
                    {

                        Node* curnode = list->head;

                        if (curnode)
                        {
                            if (curnode->getWord() != curnode->word)
                                curnode = curnode->getNext();

                            else
                            {
                                cout << "Already Exists" << endl;
                                break;
                            }
                        }
                        else
                        {
                            list->InsertNode(input);
                            break;
                        }
                        cout << curWord->getWord() << "->" << endl;
                    }

                }
                else
                    cout << "Not Chained" << endl;
            }


        }


    }

    delete list;
    return 0;
}