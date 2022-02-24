#include <queue>
#include <iostream>

class Node {
public:
    int value;
    Node* leftChild;
    Node* rightChild;
    Node(const int& value) : value(value) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* _find(Node* cursor, const int& value) {
        if (!cursor) {
            return nullptr;
        }

        if (cursor->value == value) {
            return cursor;
        }
        else {
            if (cursor->value > value) {
                return _find(cursor->leftChild, value);
            }
            else {
                return _find(cursor->rightChild, value);
            }
        }
    }

    void _insert(Node* cursor, const int& value) {
        Node* parent=NULL;
        while (cursor) {
            parent = cursor;
            if (parent->value > value) {
                cursor = cursor->leftChild;
            }
            else {
                cursor = cursor->rightChild;
            }
        }
        if (parent->value > value) {
            parent->leftChild = new Node(value);
        }
        else if (parent->value < value) {
            parent->rightChild = new Node(value);
        }
        else {
            std::cout << "이미 있는 값입니다." << std::endl;
        }
    }

    void _preorderTraversal(Node* cursor) {
        if (!cursor) {
            return;
        }

        std::cout << cursor->value << " ";
        this->_preorderTraversal(cursor->leftChild);
        this->_preorderTraversal(cursor->rightChild);
    }

public:
    void insert(const int& value) {
        if (!this->root) {
            this->root = new Node(value);
            return;
        }

        this->_insert(this->root, value);
    }

    Node* find(const int& value) {
        Node* cursor = this->root;
        if (!cursor) {
            return nullptr;
        }
        return this->_find(cursor, value);
    }

    void remove(const int& value) {
        Node* parent=NULL;
        Node* deleteTarget=NULL;
        Node* cursor = this->root;
        while (cursor) {
            // 노드를 삭제하기 위해서 부모값을 저장해둔다.
            if (cursor->leftChild) {
                if (cursor->leftChild->value == value) {
                    parent = cursor;
                }
            }
            else if (cursor->rightChild) {
                if (cursor->rightChild->value == value) {
                    parent = cursor;
                }
            }

            // 삭제할 노드를 탐색한다.
            if (cursor->value == value) {
                deleteTarget = cursor;
                break;
            }
            else if (cursor->value > value) {
                cursor = cursor->leftChild;
            }
            else {
                cursor = cursor->rightChild;
            }
        }

        // 자식노드가 하나도 없을 때
        if (deleteTarget->rightChild == nullptr && deleteTarget->leftChild == nullptr) {
            if (parent->leftChild == deleteTarget) {
                parent->leftChild = nullptr;
            }
            else if (parent->rightChild == deleteTarget) {
                parent->rightChild = nullptr;
            }
            delete deleteTarget;
            return;
        }

        // 자식노드가 왼쪽 하나만 있을 때
        if (deleteTarget->rightChild == nullptr && deleteTarget->leftChild != nullptr) {
            if (!parent) {
                this->root = deleteTarget->leftChild;
                delete deleteTarget;
            }
            else {
                if (parent->leftChild == deleteTarget) {
                    parent->leftChild = parent->leftChild->leftChild;
                }
                else if (parent->rightChild == deleteTarget) {
                    parent->rightChild = parent->rightChild->leftChild;
                }
                delete deleteTarget;
            }
            return;
        }
        // 자식노드가 오른쪽 하나만 있을 때
        else if (deleteTarget->rightChild != nullptr && deleteTarget->leftChild == nullptr) {
            if (!parent) {
                this->root = deleteTarget->rightChild;
                delete deleteTarget;
            }
            else {
                if (parent->leftChild == deleteTarget) {
                    parent->leftChild = parent->leftChild->rightChild;
                }
                else if (parent->rightChild == deleteTarget) {
                    parent->rightChild = parent->rightChild->rightChild;
                }
                delete deleteTarget;
            }
            return;
        }
        // 자식노드가 두 개가 있을 때
        else {
            Node* tmp=NULL;
            cursor = deleteTarget->rightChild;
            if (cursor->leftChild) {
                while (cursor->leftChild) {
                    tmp = cursor;
                    cursor = cursor->leftChild;
                }

                int tmpValue = tmp->leftChild->value;
                tmp->leftChild->value = deleteTarget->value;
                deleteTarget->value = tmpValue;

                delete tmp->leftChild;
                tmp->leftChild = nullptr;
            }
            else if (cursor->rightChild) {
                while (cursor->rightChild) {
                    tmp = cursor;
                    cursor = cursor->rightChild;
                }

                int tmpValue = tmp->rightChild->value;
                tmp->rightChild->value = deleteTarget->value;
                deleteTarget->value = tmpValue;

                delete tmp->rightChild;
                tmp->rightChild = nullptr;
            }
            return;
        }
    }

    void printTree() {
        this->_preorderTraversal(this->root);
        std::cout << std::endl;
    }
};

int main() {

    BinarySearchTree* bst = new BinarySearchTree();
    bst->insert(4);
    bst->insert(5);
    bst->insert(6);
    bst->insert(3);
    bst->insert(2);
    bst->insert(1);
    bst->insert(1); // 이미 있는 값입니다.

    std::cout << bst->find(3)->value << " 찾았습니다 !" << std::endl;

    bst->printTree();
    bst->remove(3);
    bst->printTree();
    bst->remove(1);
    bst->printTree();
    bst->remove(4);
    bst->printTree();
    bst->remove(2);
    bst->printTree();
    bst->remove(6);
    bst->printTree();

    return 0;
}