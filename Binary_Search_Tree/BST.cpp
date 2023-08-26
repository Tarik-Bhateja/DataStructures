#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
int data;
Node* left;
Node* right;

Node(int data)
{
    this->data=data;
    this->left=NULL;
    this->right=NULL;
}

};

void levelOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(q.size()!=0)
    {
        Node* frontNode=q.front();
        q.pop();

        if(frontNode==NULL)
        {
            cout<<endl;
            if(q.size()!=0)
            {
                q.push(NULL);
            }
        }

        else
        {
            cout<<frontNode->data<<" ";
            if(frontNode->left)
            {
                q.push(frontNode->left);
            }
            if(frontNode->right)
            {
                q.push(frontNode->right);
            }
        }

    }
}

Node*  insertIntoBst(Node* &root,int data)
{
if(root==NULL)
{
    root=new Node(data);
    return root;
}

if(data>root->data)
{
    root->right=insertIntoBst(root->right,data);
}

else
{
    root->left=insertIntoBst(root->left,data);
}

return root;


}



void takeInput(Node* &root)
{
    int data;
    cin>>data;
    
    while(data!=-1)
    {
        root=insertIntoBst(root,data);
        cin>>data;
    }
}
int main() {

    Node* root=NULL;
    cout<<"Enter Data to Create a BST"<<endl;
    takeInput(root);
    levelOrder(root);
   
}
