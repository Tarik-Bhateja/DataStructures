pair<bool,int> check(TreeNode<int>* root)
{
    if(root==NULL)
    {
        pair<bool,int> p=make_pair(true,0);
        return p;
    }

    if(root->left==NULL && root->right==NULL )
    {
        pair<bool,int> p=make_pair(true,root->val);
        return p;
    }

    pair<bool,int> left=check(root->left);
    pair<bool,int> right=check(root->right);

    bool leftAns=left.first;
    bool rightAns=right.first;
    bool cond=root->val==left.second+right.second;

    pair<bool,int> ans;
    if(leftAns && rightAns && cond)
    {
        ans.first=true;
        ans.second=2*root->val;
        return ans;
    }
    else
    {
        ans.first=false;
        return ans;
    }

}

bool isSumTree(TreeNode<int> *root)
{
    // Write your code here.
    return check(root).first;
}
