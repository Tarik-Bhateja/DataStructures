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

Node* buildTree(Node* root)
{
  int data;
  cout<<"Enter Data: "<<endl;
  cin>>data;
  
  if(data==-1)
  {
    return NULL;
  }
  root=new Node(data);

  cout<<"Enter data to the left of "<<data<<endl;
  root->left=buildTree(root->left);

   cout<<"Enter data to the right of "<<data<<endl;
  root->right=buildTree(root->right);

  return root;
}

void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
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


int main()
{
    Node* root=NULL;

    root=buildTree(root);
    levelOrderTraversal(root);
}