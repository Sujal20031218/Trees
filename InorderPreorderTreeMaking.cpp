#include<iostream>
#include<queue>
using namespace std;
class node{
public:
int data;
node*left;
node*right;
    node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
//--------------------------Using a inorder and preorder make a tree-----------------------------//
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
int findpos(int arr[],int n,int element)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==element) return i;
    }
    return -1;
}

//build tree using inorder and preorder traversal
node* buildTreeFromInorderPreorder(int inorder[],int preorder[],int size,int &preindex,int inorderstart,int inorderend)
{

    //base case
    if(preindex>=size ||inorderstart > inorderend ) return NULL;

    //StepA:
    int element=preorder[preindex++]; //accessing the first element of preorder[NLR] array to get the Root NOde
    node* root=new node(element);
    int pos=findpos(inorder,size,element);

    //StepB: Solving Root->left
    root->left=buildTreeFromInorderPreorder(inorder,preorder,size,preindex,inorderstart,pos-1);

    //StepC: Solving Root->Right
    root->right=buildTreeFromInorderPreorder(inorder,preorder,size,preindex,pos+1,inorderend);

    return root;
}
void levelOrderTraversal(node* root)
{
    queue<node*> q;
    q.push(root);
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
        cout<<temp->data<<endl;
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

int main()
{

int inorder[]={40,20,10,50,30,60};
int preorder[]={10,20,40,50,30,60,70};
int size=7;
int preindex=0;
int inorderstart=0;
int inorderend=size-1;
cout<<"Building tree"<<endl;
node*root=buildTreeFromInorderPreorder(inorder,preorder,size,preindex,inorderstart,inorderend);
cout<<"Printing levle order traversal"<<endl;
levelOrderTraversal(root);

    return 0;
}

