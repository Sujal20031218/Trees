#include<iostream>
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

bool findKthAncestor(node *root, int p, int &k) {
        //base case
        if(root==NULL) return false;
        //check for p 
        if(root->data==p) return true;
        bool leftans=findKthAncestor(root->left,p,k);
        bool rightans=findKthAncestor(root->right,p,k);
        //wapis ate hue we will check this
        if(leftans==true || rightans== true) k--;
        if(k==0) 
        {cout<<"Answer: "<<root->data<<endl; 
            k=-1;
        }
        return leftans||rightans;
}
int main()
{
    node* root=NULL;
    root=buildTree();
    int k=1;
    int p=4;
    bool ans=findKthAncestor(root,p,k);


    return 0;
}
