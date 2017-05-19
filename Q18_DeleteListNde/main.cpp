#include <iostream>

using namespace std;

struct ListNode {
    int m_nValue;
    ListNode* m_pNext;
    ListNode(int value, ListNode* node) {
        m_nValue = value;
        m_pNext = node;
    }
};

void deleteNode(ListNode** head, ListNode* deleteP) {
    if (head == NULL || deleteP == NULL) {
        return;
    }

    // 要删除的节点不是尾节点
    if(deleteP->m_pNext != NULL) {
        ListNode* next = deleteP->m_pNext;
        deleteP->m_nValue = next->m_nValue;
        deleteP->m_pNext = next->m_pNext;
        delete next;
        next = NULL;
    }
    // 链表中只有一个节点, 要删除的节点是头节点
    else if (*head == deleteP) {
        delete *head;
        *head = NULL;
        deleteP = NULL;
    }
    // 链表中有多个节点,要删除的节点是最后一个节点
    else {
        ListNode* p = *head;
        while (p->m_pNext != deleteP) {
            p = p->m_pNext;
        }
        p->m_pNext = NULL;
        delete deleteP;
        deleteP = NULL;
    }

}

void PrintList(ListNode* head) {
    while (head != NULL) {
        cout << head->m_nValue << endl;
        head = head->m_pNext;
    }
}

int main(int argc, char* argv[])
{
    ListNode* node1 = new ListNode(1, NULL);
    ListNode* node2 = new ListNode(2, NULL);
    ListNode* node3 = new ListNode(3, NULL);
    ListNode* node4 = new ListNode(4, NULL);
    ListNode* node5 = new ListNode(5, NULL);
    node1->m_pNext = node2;
    node2->m_pNext = node3;
    node3->m_pNext = node4;
    node4->m_pNext = node5;

    //PrintList(node1);

    deleteNode(NULL, NULL);

    PrintList(node1);

    return 0;
}

