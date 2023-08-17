#include<bits/stdc++.h>
using namespace std;

class Node{
public:
int data;
Node* left;
Node* right;

Node(int d)
{
this->data=d;
this->left=NULL;
this->right=NULL;
}

};

void postOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
      
}


void preOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
      
}

void inOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);

}
void levelOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    queue<Node*>  q;
    q.push(root);
    q.push(NULL);


    while(q.size()!=0)
    {
        Node* front=q.front();
        q.pop();

        if(front==NULL)
        {
            cout<<endl;
            if(q.size()!=0)
            {
                q.push(NULL);
            }
        }

        else
        {
            cout<<front->data<<" ";
            if(front->left)
            {
             q.push(front->left);
            }
            if(front->right)
            {
             q.push(front->right);
            }
        }


    }

}
void buildTree(Node* &root)
{
  queue<Node*> q;

  int data;
  cout<<"Enter Data"<<endl;
  cin>>data;

  if(data==-1)
  {
    return;
  }

  root=new Node(data);

  q.push(root);

  while(q.size()!=0)
  {
    Node* front=q.front();
    q.pop();

    cout<<"Enter data to the left of "<<front->data<<endl;
    int leftdata;
    cin>>leftdata;
    if(leftdata!=-1)
    {
      front->left=new Node(leftdata);
      q.push(front->left);
    }


    cout<<"Enter data to the right of "<<front->data<<endl;
    int rightdata;
    cin>>rightdata;
    if(rightdata!=-1)
    {
      front->right=new Node(rightdata);
      q.push(front->right);
    }
    
  }


}

int main()
{
 
 Node* root=NULL;
 buildTree(root);
 
 levelOrder(root);
 cout<<endl;

 inOrder(root);
 cout<<endl;

 preOrder(root);
 cout<<endl;

 postOrder(root);

}