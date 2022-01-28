#include<iostream>
#include<cstring>
using namespace std;

class Node {

public:
    Node* next;
    string word;

    void setWord(string Word) { this->word = Word; }
    string getWord() { return word; }
    void setNext(Node* nextnode) { this->next = nextnode; } // 새로 동적할당 된 노드를 매개변수로 받아올 예정
    Node* getNext() { return next; }
};

class List {
public:

    Node* head;

    Node* curWord = head;

    void setHead(string Word) {
        Node* newnode = new Node; // 동적할당으로 노드 클래스를 생성하여 newnode 포인터 객체 생성
        head = newnode; // head에 newnode 대입
        head->word = Word; // head의 멤버 word에 매개변수로 받은 Word의 값을 저장
        head->next = NULL; // head의 멤버 next가 NULL 대입(다음 노드가 생성되지 않았으므로 NULL)
    }

    Node* getHead() { return head; } // head를 가져올 때 head의 word 부분과 next를 가져와야 하므로 Node *



    Node* InsertNode(string Word) {
        Node* curWord = head; // curWord 포인터 객체 생성 후 head 대입

        while (curWord->getNext() != NULL)  // 현재 노드의 끝이 NULL일 때까지 반복(curWord를 맨 끝으로 이동)
            curWord = curWord->getNext();

        curWord->setNext(new Node); // 새로운 노드 생성
        curWord = curWord->getNext(); // curWord를 새로 생성한 다음 노드로 이동
        curWord->setWord(Word); // 이동한 새로운 노드에서 word를 받아옴 
        curWord->setNext(NULL); // NULL을 대입하여 쓰레기값 방지(새로운 노드 생성이 가능한 상태)

        return curWord;
    }

    bool checkingChain(string word) 
    {               //이전 단어와 chain인지 판단
        Node* curWord = head;
        while (curWord->getNext() != NULL) {
            curWord = curWord->getNext();
        }
        string nextWord = curWord->getWord();

        char beforeWordBack = nextWord[nextWord.length()-1]; // string beforeWordBack은 사용 불가(C++ 에서(으)로 변환하기 위한 적절한 생성자가 없습니다.)
        char nextWordFront = word[0];

        if (beforeWordBack == nextWordFront)
            return true;
        else
            return false;
    }

    bool checkingSame(string word)
    {
        Node* curWord = head;

        while (curWord)
        {
            if (curWord->getWord() == word) // 같은 단어가 있을 경우 false 반환
                return false;
            curWord = curWord->getNext();
        }
        return true;
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
            if (input.front() >= 'A' && input.front() <= 'Z')
                input.front() += 32;
            if (input.back() >= 'A' && input.back() <= 'Z')
                input.back() += 32;

            if (!(list->getHead()))
            {
                list->setHead(input);
                cout << list->head->word << "->" << endl;
            }
            else
            {
                if (list->checkingChain(input)==true) // 체인인지 체킹
                {
                    if (list->checkingSame(input)) // 같은 단어가 아닌지 체킹
                    {
                        list->InsertNode(input);

                        list->curWord = list->head;
                        while (list->curWord)
                        {
                            cout << list->curWord->getWord() << "->";
                            list->curWord = list->curWord->getNext();
                        }
                        cout << endl;

                    }
                    else
                        cout << "Already Exists" << endl;
                }
                else
                    cout << "Not Chained" << endl;
            }
        }
    }
    delete list;

    return 0;
}