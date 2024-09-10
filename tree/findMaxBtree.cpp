#include <iostream>
#include <climits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* posOrder(TreeNode* head, int record[3]) {
    if (head == nullptr) {
        record[0] = 0;      
        record[1] = INT_MAX;     
        record[2] = INT_MIN;      
        return nullptr;
    }

    int value = head->val;
    TreeNode* left = head->left;
    TreeNode* right = head->right;

    int lRecord[3], rRecord[3];

    TreeNode* lBST = posOrder(left, lRecord);
    TreeNode* rBST = posOrder(right, rRecord);

    int lSize = lRecord[0];
    int lMin = lRecord[1];
    int lMax = lRecord[2];

    int rSize = rRecord[0];
    int rMin = rRecord[1];
    int rMax = rRecord[2];

    record[1] = std::min(lMin, value);
    record[2] = std::max(rMax, value);

    if (left == lBST && right == rBST && lMax < value && value < rMin) {
        record[0] = lSize + rSize + 1;
        return head;  
    }

    record[0] = std::max(lSize, rSize);
    return lSize > rSize ? lBST : rBST;
}

TreeNode* largestBSTSubtree(TreeNode* head) {
    int record[3];
    return posOrder(head, record);
}

int main() {
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(3);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(13);
    root->right->left->left = new TreeNode(4);
    root->right->left->right = new TreeNode(16);

    TreeNode* largestBST = largestBSTSubtree(root);

    if (largestBST) {
        std::cout << "Largest BST subtree root value: " << largestBST->val << std::endl;
    } else {
        std::cout << "No BST subtree found." << std::endl;
    }

    return 0;
}
