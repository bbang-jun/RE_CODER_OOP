#include<iostream>
#include<cstring>
using namespace std;

class Node { // ���
private:
    string word;
    Node* leftChild = NULL;
    Node* rightChild = NULL;

public:
    void setWord(string Word) { this->word = Word; }
    string getWord() { return this->word; }
    void setLeftChild(Node* snode) { leftChild = snode; } // ���� �ڽ�
    Node* getLeftChild() { return leftChild; }
    void setRightChild(Node* snode) { rightChild = snode; } // ������ �ڽ�
    Node* getRightChild() { return rightChild; }
};

class Tree { // Ʈ��
private:
    Node* root = NULL; // rootNode�� �ʱⰪ�� NULL
public:
    Node* getRoot() { return root; }
    void INSERT(Node* curnode, string word); // ���� �Լ�
    void PRINT(string command); // ��� �Լ�
    void PRE(Node* curnode); // ���� ��ȸ �Լ�
    void POST(Node* curnode); // ���� ��ȸ �Լ�
    void IN(Node* curnode); // ���� ��ȸ �Լ�
};

void Tree::INSERT(Node* curNode, string Word) { // ���� �Լ�

    if (root == NULL) { // rootNode�� ���� �� 
        Node* newNode = new Node;
        newNode->setWord(Word); // �ܾ�
        newNode->setLeftChild(NULL); // �ڽ��� ���� �����Ƿ� NULL
        newNode->setRightChild(NULL); // �ڽ��� ���� �����Ƿ� NULL
        root = newNode; // ���� ������ ��尡 rootNode�� �ȴ�.
    }

    // ù��° �Ű������� �� ū ��� (strcmp �Լ��� ���� ���� c_str()�� ���Ͽ� string ���� char* ������ ��ȯ)
    // ù��° �Ű������� �� ũ�� 1�� ��ȯ�ϴµ� �� "=1"�� �� �Ǵ��� ã�ƺ���(���� ������ �� �ִ� lvalue���� �մϴ�.)
    else if (strcmp(curNode->getWord().c_str(), Word.c_str()) > 0) { 
        if (curNode->getLeftChild() == NULL) { // ���� �ڽ��� ���� ���
            Node* newNode = new Node;
            newNode->setWord(Word);
            newNode->setLeftChild(NULL);
            newNode->setRightChild(NULL);
            curNode->setLeftChild(newNode);
        }
        else { // ���� �ڽ��� ���� ��� INSERT �Լ��� �ٽ� ���������ν� ���� ����� ��ġ�� ���� �ڽ����� �̵�
            INSERT(curNode->getLeftChild(), Word);
        }
    }

    else if (strcmp(curNode->getWord().c_str(), Word.c_str()) < 0) { // �ι�° �Ű������� �� ū ���
        if (curNode->getRightChild() == NULL) {
            Node* newNode = new Node;
            newNode->setWord(Word);
            newNode->setLeftChild(NULL);
            newNode->setRightChild(NULL);
            curNode->setRightChild(newNode);
        }
        else {
            INSERT(curNode->getRightChild(), Word);
        }
    }
}

void Tree::PRINT(string command) { // ��� ����

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

    if (curNode) {
        cout << curNode->getWord() << " ";
        PRE(curNode->getLeftChild());
        PRE(curNode->getRightChild());

    }
}

void Tree::POST(Node* curNode) {

    if (curNode) {
        POST(curNode->getLeftChild());
        POST(curNode->getRightChild());
        cout << curNode->getWord() << " ";
    }
}

void Tree::IN(Node* curNode) {

    if (curNode) {
        IN(curNode->getLeftChild());
        cout << curNode->getWord() << " ";
        IN(curNode->getRightChild());
    }
}

int main(void) 
{
    string command;
    string word;
    Tree* bst = new Tree;

    while (1) {
        cin >> command;

        if (command == "INSERT") {
            cin >> word;
            bst->INSERT(bst->getRoot(), word);
        }

        else if (command == "FIND") {
        }

        else if (command == "DELETE") {
        }

        else if (command == "PRINT") {
            cin >> word;
            bst->PRINT(word);
            cout << endl;
        }

        else if (command == "END") {
            break;
        }
    }

    delete bst;
}