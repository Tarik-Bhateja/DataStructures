#include<bits/stdc++.h>
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!

    vector<int> result;
    if(root==NULL)
    {
        return result;
    }

    bool leftToRight=true;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(q.size()!=0)
    {
        int size=q.size();
        vector<int> temp(size);

        for(int i=0;i<size;i++)
        {
            BinaryTreeNode<int>* front=q.front();
            q.pop();
            int index=leftToRight ? i:size-i-1;
            temp[index]=front->data;
            if(front->left)
            {
                q.push(front->left);
            }
            if(front->right)
            {
                q.push(front->right);
            }

        }
        leftToRight=!leftToRight;

        for(auto i:temp)
        {
            result.push_back(i);
        }


    }

    return result;

    
}
