#include <iostream>

using namespace std;

struct ListNode {
    int m_nValue;
    ListNode* m_pNext;

    ListNode(int value, ListNode* p) {
        m_nValue = value;
        m_pNext = p;
    }
};

void DeleteRepeatNodes(ListNode** head) {
    if (head == NULL || *head == NULL) {
        return;
    }

    ListNode* preNode = NULL;
    ListNode* pNode = *head;

    while (pNode) {
        ListNode *pNext = pNode->m_pNext;
        bool needDelete = false;
        if (pNext != NULL && pNode->m_nValue == pNext->m_nValue) {
            needDelete = true;
        }

        if (!needDelete) {
            preNode = pNode;
            pNode = pNode->m_pNext;
        } else {
            int value = pNode->m_nValue;
            ListNode *pToBeDel = pNode;
            while (pToBeDel != NULL && pToBeDel->m_nValue == value) {
                pNext = pToBeDel->m_pNext;

                delete pToBeDel;
                pToBeDel = NULL;

                pToBeDel = pNext;
            }

                // 头结点也需要被删除
            if (preNode == NULL) {
                *head = pNext;
            } else
                preNode->m_pNext = pNext;

            pNode = pNext;
        }
    }

}


int main() {

    return 0;
}