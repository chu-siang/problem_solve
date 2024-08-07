#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
void print(TreeNode *root){
    if(root != nullptr)cout << root->val << ' ';
    if(root -> left != nullptr){
        print(root -> left);
    }
    if(root -> right != nullptr)print(root -> right);
}

TreeNode *createTree(vector<int>&inorder,vector<int>&postorder,int left,int right,int &index,unordered_map<int,int>&mp){
    if(left > right) return nullptr;
    int curr = postorder[index--];
    TreeNode *node = new TreeNode(curr);
    if(left == right)return node;
    int InorderIndex = mp[curr];
    node->right = createTree(inorder,postorder,InorderIndex+1,right,index,mp);
    node->left = createTree(inorder,postorder,left,InorderIndex-1,index,mp);
    return node;
}
TreeNode *buildTree(vector<int>&inorder,vector<int>&postorder){
    unordered_map<int,int>mp;
    for(int i = 0; i < inorder.size(); i++)mp[inorder[i]] = i;
    int index = inorder.size()-1;
    return createTree(inorder,postorder,0,postorder.size()-1,index,mp);
}
int main(){
    int n;
    cin >> n;
    vector<int>inorder(n),postorder(n);
    for(int i = 0; i < n; i++){
        cin >> inorder[i];
    }
    for(int i = 0; i < n; i++)cin >> postorder[i];
    TreeNode *root = buildTree(inorder,postorder);
    print(root);
    cout << '\n';
}