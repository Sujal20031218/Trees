class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root==NULL) return NULL;
        //check for p and q
        if(root->val==p->val) return p;
        if(root->val == q->val) return q;
        TreeNode*  leftans=lowestCommonAncestor(root->left,p,q);
        TreeNode*  rightans=lowestCommonAncestor(root->right,p,q);

        if(leftans== NULL && rightans ==NULL) return NULL;
        else if(leftans!=NULL && rightans== NULL) return leftans;
        else if(leftans==NULL && rightans!= NULL) return rightans;
        //LCA Found so return root value-: if both left and right are not null then we are there at the lca
        else return root;

    }