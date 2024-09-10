#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* myhelper(std::queue<string>& myq){
    if (myq.empty()) {
        return NULL;
    }
    auto ss=myq.front();
    myq.pop();
    if(ss=="#"){
        return NULL;
    }
    auto* mynode=new TreeNode(stoi(ss));
    mynode->left=myhelper(myq);
    mynode->right=myhelper(myq);
    return mynode;
}


TreeNode* reconByPreString(const string& preStr) {
    auto myq=std::queue<std::string>{};
    auto mys=stringstream{preStr};
    auto tmp=string{};
    while(getline(mys,tmp,'!')){
        myq.push(tmp);
    }
    return myhelper(myq);
}

void printTree(TreeNode* root) {
    if (!root) {
        cout << "# ";
        return;
    }
    cout << root->val << " ";   
    printTree(root->left);    
    printTree(root->right);   
}

int main() {
    string serializedTree = "12!3!#!45!#!#!6!#!#!";
    TreeNode* root = reconByPreString(serializedTree);
    printTree(root);
    return 0;
}
