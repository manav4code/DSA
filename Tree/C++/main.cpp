#include<bits/stdc++.h>

class Tnode{
    public:
        int data;
        Tnode *left,*right;

        Tnode(int x){
            data = x;
            left = NULL;
            right = NULL;
        }
};

void insertTree(Tnode** root,int x){
    if(!(*root)){
        (*root) = new Tnode(x);
        return;
    }
    else{
        std::queue<Tnode*>q;
        q.push(*root);

        while(!q.empty()){
            Tnode* temp = q.front();
            q.pop();

            if(temp->left)q.push(temp->left);
            else{
                temp->left = new Tnode(x);
                return;
            }

            if(temp->right)q.push(temp->right);
            else{
                temp->right = new Tnode(x);
                return;
            }
        }
    }
    return;
}

void inorder(Tnode* root){
    if(root == NULL)return;

    std::cout << root->data << " ";
    if(root->left)inorder(root->left);
    if(root->right)inorder(root->right);
}

int main(){
    Tnode* root = NULL;
    
    int arr[] = {1,2,3,4,5,6};
    int size = sizeof(arr)/sizeof(int);

    for(auto i : arr){
        insertTree(&root,i);
    }

    inorder(root);

    return 0;
}