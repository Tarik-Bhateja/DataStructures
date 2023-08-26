#include<bits/stdc++.h>

void getM(BinaryTreeNode<int> *root,int &maxi,int &mini){

    if(!root){

        return;

    }

    maxi = max(root->data,maxi);

    mini = min(root->data,mini);

    getM(root->left,maxi,mini);

    getM(root->right,maxi,mini);

}

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {

    int maxi = INT_MIN;

    int mini = INT_MAX;

 

    getM(root,maxi,mini);

    return make_pair(mini,maxi);

}
