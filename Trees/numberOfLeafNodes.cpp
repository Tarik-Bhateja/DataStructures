int getLeafNodeCount(TreeNode<int>* root) {
    // Write your code here
int count=0;
     
       if(root->children.size()==0)
    {
        
        count++;
    }


    for(int i=0;i<root->children.size();i++)
{
    count+=getLeafNodeCount(root->children[i]);   
}

 return count;
}