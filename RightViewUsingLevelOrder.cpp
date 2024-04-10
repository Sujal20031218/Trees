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

void printLeftView(node* root) {
    if (root == NULL)
        return;

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
       int n = q.size();
        for (int i = 1; i <= n; i++) {
            node* temp = q.front();
            q.pop();
            // Print the last node of each level (rightmost node)
            if (i == n)
                cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

int main() {
    node* root = NULL;
    root = buildTree();
    cout << "Left view elements of the tree: ";
    printLeftView(root);
    
    return 0;
}
