class Solution {//GFG Question
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int converttoSumTree(Node* node)
    {
         // Your code here
        if (node== NULL) return 0;
        
        int leftans=converttoSumTree(node->left);
        int rightans=converttoSumTree(node->right);
        int curr=node->data;
        node->data=leftans+rightans;
        return curr+node->data;
        
    }
    void toSumTree(Node *node)
    {
        converttoSumTree(node);
        return;

    }
};