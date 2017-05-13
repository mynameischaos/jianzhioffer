#include <iostream>

using namespace std;

struct BinaryTreeNode {
    char m_cValue;
    BinaryTreeNode* m_pParent;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
    BinaryTreeNode(char value, BinaryTreeNode* parent=NULL, BinaryTreeNode* left=NULL, BinaryTreeNode* right=NULL) {
        m_cValue = value;
        m_pLeft = left;
        m_pParent = parent;
        m_pRight = right;
    }
};

BinaryTreeNode* findNextNode(BinaryTreeNode* cur) {
    if (cur->m_pParent != NULL && cur->m_pRight == NULL && cur->m_pParent->m_pLeft == cur)
        return cur->m_pParent;
    if (cur->m_pRight != NULL) {
        BinaryTreeNode* rightNode = cur->m_pRight;
        while (rightNode->m_pLeft != NULL)
            rightNode = rightNode->m_pLeft;
        return rightNode;
    } else {
        BinaryTreeNode* pre;
        while (cur->m_pParent != NULL) {
            pre = cur;
            cur = cur->m_pParent;
            if (cur->m_pLeft == pre)
                return cur;
        }
        return NULL;
    }
}

int main() {
    BinaryTreeNode node1('a');
    BinaryTreeNode node2('b');
    BinaryTreeNode node3('c');
    BinaryTreeNode node4('d');
    BinaryTreeNode node5('e');
    BinaryTreeNode node6('f');
    BinaryTreeNode node7('g');
    BinaryTreeNode node8('h');
    BinaryTreeNode node9('i');

    node1.m_pLeft = &node2;
    node1.m_pRight = &node3;
    node2.m_pParent = &node1;
    node3.m_pParent = &node1;
    node2.m_pLeft = &node4;
    node2.m_pRight = &node5;
    node3.m_pLeft = &node6;
    node3.m_pRight = &node7;
    node4.m_pParent = &node2;
    node5.m_pParent = &node2;
    node5.m_pLeft = &node8;
    node5.m_pRight = &node9;
    node6.m_pParent = &node3;
    node7.m_pParent = &node3;
    node8.m_pParent = &node5;
    node9.m_pParent = &node5;
    BinaryTreeNode* result = findNextNode(&node9);
    if (result != NULL)
        cout << result->m_cValue << endl;
    else
        cout << "not found" << endl;
    return 0;
}