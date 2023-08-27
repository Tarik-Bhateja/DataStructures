
void inorder(BinaryTreeNode<int>* root, int k,int &i,int &ans)
{
    if(root==NULL)
    {
        return;
    }

    inorder(root->left,k,i,ans);
    i++;
    if(i==k)
    {
      ans=root->data; 
    }
    inorder(root->right,k,i,ans);

}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    int i=0;
    int ans=-1;
    inorder(root,k,i,ans);
    return ans;
}
