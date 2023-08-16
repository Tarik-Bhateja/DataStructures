TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
   
   TreeNode<int>* max=root;

   for(int i=0;i<root->children.size();i++)
   {
       TreeNode<int>* maxchild=maxDataNode(root->children[i]);
       if(maxchild->data>max->data)
       {
           max=maxchild;
       }
   }

   return max;


    
}