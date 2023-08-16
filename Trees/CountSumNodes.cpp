#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

int sumOfNodes(TreeNode<int>* root) {
    // Write your code here

    int sum=root->data;


    for(int i=0;i<root->children.size();i++)
    {
        sum+=sumOfNodes(root->children[i]);
    }

    return sum;


}

int countOfNodes(TreeNode<int>* root) {
    // Write your code here

    int ans=1;


    for(int i=0;i<root->children.size();i++)
    {
        ans+=countOfNodes(root->children[i]);
    }

    return ans;


}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    cout << countOfNodes(root);
    cout << sumOfNodes(root);
}