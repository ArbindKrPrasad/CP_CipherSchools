#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

void preOrder(TreeNode* root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(TreeNode* root){
    if(root!=NULL){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

void postOrder(TreeNode* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}

int height(TreeNode* root){
    if(root==NULL) return 0;
    else{
        return 1+max(height(root->left), height(root->right));
    }
}

int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);
    cout<<"Preorder ";
    preOrder(root);

    cout<<"Inorder ";
    inOrder(root);

    cout<<"Postorder ";
    postOrder(root);

}