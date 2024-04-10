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
int height(TreeNode* root)
{
    if(root==NULL) return 0;
    int leftheight=height(root->left);
    int rightheight=height(root->right);
    int ans= max(leftheight,rightheight)+1;
    return ans;
}

    bool isBalanced(TreeNode* root) {
        //base case 
        if(root==NULL) return true;
        //1case
        int leftheight=height(root->left);
        int rightheight=height(root->right);
        int diff= abs(leftheight-rightheight) ;
        int ans=(diff<=1);
        //Recursion
        bool leftans=isBalanced(root->left);
        bool rightans=isBalanced(root->right);
        if(ans && leftans && rightans ) return true;
        else return false;
    }
};