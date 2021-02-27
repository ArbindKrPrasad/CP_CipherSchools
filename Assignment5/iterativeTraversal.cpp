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
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        TreeNode* t = s.top(); s.pop();
        cout<<t->data<<" ";
        if(t->right!=NULL) s.push(t->right);
        if(t->left!=NULL) s.push(t->left);
        
    }
}
void inOrder(TreeNode* root){
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        TreeNode* curr= s.top(); s.pop();
        while(curr->left!=NULL){
            s.push(curr->left);
            curr = curr->left;
        }
        cout<<curr->data<<" ";
        if(curr->right!=NULL) s.push(curr->right);
        s.pop();  
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