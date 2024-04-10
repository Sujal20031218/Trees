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

void printLeftView(node* root,vector<int> & ans,int level) {
    if (root == NULL)
        return;

    //store value
    if(level==ans.size())
    {
        ans.push_back(root->data);
    }

    //left jao
    printLeftView(root->left,ans,level+1);
    //right jao
    printLeftView(root->right,ans,level+1);

}

int main() {
    node* root = NULL;
    root = buildTree();
    vector<int>ans;
    int level=0;
    cout << "Left view elements of the tree: ";
    printLeftView(root,ans,0);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}
