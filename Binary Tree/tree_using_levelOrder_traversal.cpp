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

// node* buildTree(node* root){
//     cout<<"Enter the data: "<<endl;
//     int data;
//     cin>>data;

//     root=new node(data);

//     if(data==-1){
//         return NULL;
//     }

//     cout<<"Enter data for inserting in left of "<<data<<endl;
//     root->left = buildTree(root->left);
//     cout<<"Enter data for inserting in right of "<<data<<endl;
//     root->right=buildTree(root->right);
//     return root;
// }


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

void buildFromLevelOrderTraversal(node* &root){
    queue<node*>q;
    cout<<"Enter data for root: "<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);

    while(!q.empty()){
        node*temp=q.front();
        q.pop();

        cout<<"Enter left node for: "<< temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left=new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for : "<< temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            temp->right=new node(rightData);
            q.push(temp->right);
        }
    }
}



int main()
{

    node* root=NULL;

    // root=buildTree(root);

    // cout<<"Printing the level order traversal output "<<endl;
    buildFromLevelOrderTraversal(root);
    levelOrderTraversal(root);
return 0;
}