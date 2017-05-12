#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int m_nKey;
    ListNode* m_pNext;
    ListNode(int value, ListNode* p=NULL) {
        m_nKey = value;
        m_pNext = p;
    }
};

// 先入后出, 用栈实现,
void PrintListReversingly_Iteratively(ListNode* pHead) {
    stack<ListNode*> nodes;

    ListNode* pNode = pHead;
    while (pNode != NULL) {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }
    while (!nodes.empty()) {
        pNode = nodes.top();
        cout << pNode->m_nKey << endl;
        nodes.pop();
    }
}

// 根据栈,要想到用递归的方式求解, 但是有一个问题就是当节点数目多的时候,可能有很深的递归,容易导致栈溢出
// 所以, 还是用栈的方法更加鲁棒性一些
void PrintListReveringly_Recursively(ListNode* pHead) {
    if (pHead != NULL) {
        if (pHead->m_pNext != NULL) {
            PrintListReversingly_Iteratively(pHead->m_pNext);
        }
        cout << pHead->m_nKey << endl;
    }
}

int main() {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    node1->m_pNext = node2;
    node2->m_pNext = node3;
    node3->m_pNext = node4;
    node4->m_pNext = node5;
    PrintListReversingly_Iteratively(node1);
    PrintListReveringly_Recursively(node1);
    return 0;
}