

int height(TreeNode<int> *root)
{
    
    if(root==NULL)
    {
        return 0;
    }
    
    int left=height(root->left);
    int right=height(root->right);

    return max(left,right)+1;
}



pair<int,int> diaFast(TreeNode<int> *root)
{
    if (root == NULL) {

        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diaFast(root->left);
    pair<int, int> right = diaFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second;

    pair<int, int> ans;

    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameterOfBinaryTree(TreeNode<int> *root){
	// Write Your Code Here.

    // if(root==NULL)
    // {
    //     return 0;
    // }

    // int dia1=diameterOfBinaryTree(root->left);
    // int dia2=diameterOfBinaryTree(root->right);
    // int dia3=height(root->left)+height(root->right);

    return diaFast(root).first;
}
