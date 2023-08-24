  pair<int,int> solve(Node* root,pair<int,int> &ans)
    {
        if(root==NULL)
        {
            pair<int,int> p=make_pair(0,0);
            return p;
        }
        
        pair<int,int> leftAns=solve(root->left,ans);
        pair<int,int> rightAns=solve(root->right,ans);
        
        ans.first=root->data+leftAns.second+rightAns.second;
        ans.second=max(leftAns.first,leftAns.second)+max(rightAns.first,rightAns.second);
        return ans;
    }
    int getMaxSum(Node *root) 
    {
       pair<int,int> ans=solve(root,ans);
       return max(ans.first,ans.second);
    }
