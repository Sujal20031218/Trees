#include<iostream>
#include<queue>
#include<map>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

node* buildTree() {
    int data;
    cout << "Enter the data" << endl;
    cin >> data;

    //base case------------
    if (data == -1) return NULL;

    //Step A---------------
    node* root = new node(data);

    //Step B------------
    cout << "Enter the data for left Node: " << endl;
    root->left = buildTree();

    //Step C-----------
    cout << "Enter the data for right Node: " << endl;
    root->right = buildTree();
    return root;
}

void printLeftBoundary(node* root) 
{
    if (root == NULL)
        return;
    if(root->left==NULL && root->right==NULL) return;

   cout<<root->data<<" ";
   if(root->left)
   {
    printLeftBoundary(root->left);
   }
   else{
        printLeftBoundary(root->right);
   }
   
}

void printLeafNodes(node* root) {
    if (root == NULL)
        return;
    printLeafNodes(root->left);
    if (!(root->left) && !(root->right))
        cout << root->data << " ";
    printLeafNodes(root->right);
}

void printRightBoundary(node* root) {
    if (root == NULL)
        return;
       if(root->right) printRightBoundary(root->right);
   else printRightBoundary(root->left);
          cout<<root->data<<" ";

   
}

void printBoundaryView(node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    printLeftBoundary(root->left);
    printLeafNodes(root);
    printRightBoundary(root->right);
}

int main() {
    node* root = NULL;
    root = buildTree();
    cout << "Boundary view elements of the tree: ";
    printBoundaryView(root);
    
    return 0;
}
