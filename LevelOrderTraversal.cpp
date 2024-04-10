class Solution {
public:
//here what we will use is we will have 2 datastructures one will be the queue and 
//the other will be a vector storing the levels order wises
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root== NULL) return ans;//if the treenode is empty then we have to return the blank ans
        queue<TreeNode*> q;//so we have initialized a queue
        q.push(root);//now we have inserted our frist value which is the root node in the queue
        while(!q.empty())
        {
            //no we will find the level
            vector<int>level;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                //traversing through each node 
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
                //now storing the main value of the node in the level vector 
                level.push_back(node->val);
            }
            //now storing the levels in the ans vector
            ans.push_back(level);
        }
        return ans;
    }
};
