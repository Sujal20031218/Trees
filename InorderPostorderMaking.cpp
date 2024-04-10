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
//--------------------------Using a inorder and Postorder make a tree-----------------------------//
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
int findpos(int arr[],int n,int element)
{
    for(int i=n;i>=0;i--)
    {
        if(arr[i]==element) return i;
    }
    return -1;
}

//build tree using inorder and preorder traversal
node* buildTreeFromInorderPostorder(int inorder[],int postorder[],int size,int &postindex,int inorderstart,int inorderend)
{

    //base case
    if(postindex < 0 ||inorderstart > inorderend ) return NULL;

    //StepA:
    int element=postorder[postindex--]; //accessing the first element of postorder array to get the Root NOde
    node* root=new node(element);
    int pos=findpos(inorder,size,element);

    //StepB: Solving Root->Right
    root->right=buildTreeFromInorderPostorder(inorder,postorder,size,postindex,pos+1,inorderend);
    //StepC: Solving Root->left
    root->left=buildTreeFromInorderPostorder(inorder,postorder,size,postindex,inorderstart,pos-1);
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

int main()
{

int inorder[]={40,20,10,50,30,60};
int postorder[]={40,20,50,60,30,10};
int size=6;
int postindex=size-1;
int inorderstart=0;
int inorderend=size-1;
cout<<"Building tree"<<endl;
node*root=buildTreeFromInorderPostorder(inorder,postorder,size,postindex,inorderstart,inorderend);
cout<<"Printing levle order traversal"<<endl;
levelOrderTraversal(root);

    return 0;
}

