/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int depth(TreeNode* root,int &d){
        if(root == nullptr)return 0;
        int ld = depth(root->left,d);
        int rd = depth(root->right,d);
        d = max(d, ld+rd);
        return max(ld,rd)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        depth(root,d);
        return d;
    }
};