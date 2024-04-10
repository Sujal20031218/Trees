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
     int maxDepth(TreeNode* root) {
       if(root==NULL) return 0;
       int left=maxDepth(root->left);
       int right=maxDepth(root->right);
       return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int opt1= diameterOfBinaryTree(root->left);
        int opt2= diameterOfBinaryTree(root->right);
        int opt3=maxDepth(root->left)+maxDepth(root->right);//it is for edges if asked for nodes then we have to add +1 to it
        int ans=max(opt1,max(opt2,opt3));
        return ans;
    }
};