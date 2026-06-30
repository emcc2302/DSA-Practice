#include<iostream>
#include<queue>
using namespace std;

class node{
    public:

    int data;
    node* left;
    node* right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;

    root=new node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}


void levelOrderTraversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL); // level 0 is completed so we use NULL as a next line or seperator

    while(!q.empty()){
        node*temp=q.front();
        q.pop();

        if(temp==NULL){
            //purana level complete hoo chuka h
            cout<<endl;
            if(!q.empty()){
                //queue still has some element
                q.push(NULL);
            }
        }

        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);

            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}


void inorder(node* root){
    if(root==NULL) return ;
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}

void preorder(node* root){
    if(root==NULL) return ;
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
}


void postorder(node* root){
    if(root==NULL) return ;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<endl;
}


int main()
{

    node* root=NULL;

    root=buildTree(root);

    cout<<"Printing the level order traversal output "<<endl;
    levelOrderTraversal(root);

    cout<<"The inorder traversal is: "<<endl;
    inorder(root);

    cout<<"The preorder traversal is : "<<endl;
    preorder(root);


    cout<<"The postorder traversal is : "<<endl;
    postorder(root);
return 0;
}