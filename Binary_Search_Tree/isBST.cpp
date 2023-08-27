#include<algorithm>
#include<bits/stdc++.h>

// void inorder(BinaryTreeNode<int>* root,vector<int> &ans)
// {
// if(root==NULL)
// {
//     return;
// }
// inorder(root->left,ans);
// ans.push_back(root->data);
// inorder(root->right,ans);
// }

bool isBST(BinaryTreeNode<int>* root,int min,int max)
{
    if(root==NULL)
    {
        return true;
    }

    if(root->data>min && root->data<max)
    {
        bool left=isBST(root->left,min,root->data);
        bool right=isBST(root->right,root->data,max);
        return (left && right);
    }
    else
    {
        return false;
    }

}
bool validateBST(BinaryTreeNode<int>* root) 
{
   
//     vector<int> ans;
//     inorder(root,ans);
//    if(is_sorted(ans.begin(),ans.end()))
//    {
//        set<int> check(ans.begin(),ans.end());
//        if(check.size()==ans.size())
//        {
//          return true;
//        }
//        else
//        {
//            return false;
//        }
       
//    }
//    else
//    {
//        return false;
//    }

return isBST(root,INT_MIN,INT_MAX);
}
