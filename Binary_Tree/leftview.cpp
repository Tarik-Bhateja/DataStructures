void help(Node* root,vector<int> &ans,int lvl)
{
    if(root==NULL)
    {
        return;
    }
    
    if(lvl==ans.size())
    {
        ans.push_back(root->data);
    }
    
    
    help(root->left,ans,lvl+1);
    help(root->right,ans,lvl+1);
}
vector<int> leftView(Node *root)
{
   // Your code here
  vector<int> ans;
  int lvl=0;
  help(root,ans,lvl);
  return ans;
   
}
