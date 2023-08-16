#include <iostream>
#include<queue>
#include<vector>
using namespace std;

template<typename T>
class TreeNode{
public:
T data;
vector<TreeNode<T>*> children;
TreeNode(T data)
{
    this->data=data;
}

};



TreeNode<int>* takeInput()
{
    int rootData;
    cout<<"Enter Root Data :"<<endl;
    cin>>rootData;
    TreeNode<int>* root=new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() !=0)
    {
        TreeNode<int> * front=pendingNodes.front();
        pendingNodes.pop();

        int n;
        cout<<"Enter Number of childeren for: "<<front->data<<endl;
        cin>>n;

        for(int i=0;i<n;i++)
        {
            int childData;
           cout<<"Enter data for the "<<i<<"th child of: "<<front->data<<endl;
           cin>>childData;
           TreeNode<int>* child=new TreeNode<int>(childData);
           front->children.push_back(child);
           pendingNodes.push(child);
        }
    }
    return root;
}

void printLevelWise(TreeNode<int>* root) {
    // Write your code here
    queue<TreeNode<int>*> pending;
    pending.push(root);

    while(pending.size()!=0)
    {
       TreeNode<int>* front=pending.front();
       pending.pop();

       cout<<front->data<<":"; 
       for(int i=0;i<front->children.size();i++)
       {
            if(i==0)
            {
             cout<<front->children[i]->data;
             pending.push(front->children[i]);
            }
            else{
                 cout<<","<<front->children[i]->data;
             pending.push(front->children[i]);
            }
            
           
       }
       cout<<endl;

       
    }


    


}

void printData(TreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }

    cout<<root->data<<" :";
    for(int i=0;i<root->children.size();i++)
    {
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;

    for(int i=0;i<root->children.size();i++)
    {
        printData(root->children[i]);
    }


}

void printAtLevelK(TreeNode<int>* root ,int k)
{
    if(k==0)
    {
        cout<<root->data<<endl;
        return;
    }

    for(int i=0;i<root->children.size();i++)
    {
        printAtLevelK(root->children[i],k-1);
    }
}

int main() {

    TreeNode<int>* root=takeInput();
    // printLevelWise(root);
    printAtLevelK(root,1);


  
}
