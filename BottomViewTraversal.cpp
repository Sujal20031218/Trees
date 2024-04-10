#include<iostream>
#include<queue>
#include<map>
using namespace std;
class node{
public:
int data;
node* left;
node* right;

    node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

node* buildTree(){
int data;
cout<<"Enter the data"<<endl;
cin>>data;

//base case------------
if(data==-1) return NULL;

//Step A---------------
node* root=new node(data);

//Step B------------
cout<<"Enter the data for left Node: "<<endl;
root->left= buildTree();

//Step C-----------
cout<<"Enter the data for right Node: "<<endl;
root->right=buildTree();
return root;
}

void levelOrderTraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty()) 
            {
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
        }
        
    }
}

void inorder(node* root)
{
    //base case
    if(root==NULL) return;

    //LNR
    inorder(root->left);
    cout<<root->left->data<<" ";
    inorder(root->right);

}

void preorder(node* root)
{
    //base case
    if(root==NULL) return;

    //NLR
    cout<<root->left->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root)
{
        //base case
    if(root==NULL) return;

    //LRN 
    preorder(root->left);
    preorder(root->right);
    cout<<root->left->data<<" ";
}
int height(node* root)//leetcode question
{
    if(root==NULL) return 0;
    int leftheight=height(root->left);
    int rightheight=height(root->right);
    int ans= max(leftheight,rightheight)+1;
    return ans;
}

int diameter(node* root)//leetcode question
{
    if(root==NULL) return 0;
    int opt1=diameter(root->left);
    int opt2=diameter(root->right);
    //finding for edges
    int opt3=height(root->left)+height(root->right);
    //finding for nodes
    // int opt3=height(root->left)+1+height(root->right);
    int ans=max(opt1,max(opt2,opt3));
    return ans;
}

void bottomview(node* root)
{
    if(root==NULL) return;
    //create a map for storing horizontal distance -> TOpnode->data
    map<int,int> topnode;

    //Level order
    //we will store a pair consisting of node and Horizontal distance  
    queue<pair<node* ,int> >q;
    q.push(make_pair(root,0));
    while(!q.empty())
    {
        pair<node*,int> temp=q.front(); 
        q.pop();

        node* frontnode=temp.first;
        int hd=temp.second;

            //update every value of distance
            topnode[hd]=frontnode->data;

        //node ka left ha to left me push kro with HD=-1
        if(frontnode->left) q.push(make_pair(frontnode->left,hd-1));
        //node ka right ha to right me push kro with HD=+1
        if(frontnode->right) q.push(make_pair(frontnode->right,hd+1));
    }
    //ab hamra ans store ha map me
    cout<<"Prinitng the answer: "<<endl;
    for(auto i:topnode)//Run this in online compiler then only this loop will work 
    {
        cout<<i.first<<" -> "<<i.second<<endl;
    }

}   
int main()
{
    node* root= NULL;
    root=buildTree();
    bottomview(root);
        
    
        return 0;
}