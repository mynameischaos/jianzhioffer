#include <iostream>

using namespace std;

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder) {
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = NULL;

    if (startPreorder == endPreorder) {
        if (startInorder == endInorder && *startPreorder == * startInorder)
            return root;
        else
            throw std::exception();
    }

    // 在中序遍历中找到根节点的值
    int* rootInorder = startInorder;
    while (rootInorder <= endInorder && *rootInorder != rootValue)
        rootInorder++;

    if (rootInorder == endInorder && *rootInorder != rootValue)
        throw std::exception();

    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength;
    if (leftLength > 0) {
        root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
    }
    if (leftLength < endPreorder - startPreorder) {
        root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
    }
    return root;
}

// 后序遍历二叉树
void midOrderTree(BinaryTreeNode* root) {
    if (root->m_pLeft != NULL)
        midOrderTree(root->m_pLeft);
    if (root->m_pRight != NULL) {
        midOrderTree(root->m_pRight);
    }
    cout << root->m_nValue << endl;
}

BinaryTreeNode* Construct(int* preorder, int* inorder, int length) {
    if (preorder == NULL || inorder == NULL || length < 0)
        return NULL;
    return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}
int main() {
    int forwardList[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int middleList[] = {4, 7, 2, 1, 5, 3, 8, 6};
    BinaryTreeNode* root = Construct(forwardList, middleList, 8);
    midOrderTree(root);
    return 0;
}