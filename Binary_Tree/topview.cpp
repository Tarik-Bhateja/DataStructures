vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        
        if(root==NULL)
    {
        return ans;
    }
        map<int,int> nodes;
        queue<pair<Node*,int>> q;
        
        q.push(make_pair(root,0));
        
        while(q.size()!=0)
        {
            pair<Node*,int> temp=q.front();
            q.pop();
            
            Node* frontNode=temp.first;
            int hd=temp.second;
            
            if(nodes.find(hd)==nodes.end())
            {
            nodes[hd]=frontNode->data;
            }
            
            
            if(frontNode->left)
            {
               q.push(make_pair(frontNode->left,hd-1)); 
            }
            
            if(frontNode->right)
            {
               q.push(make_pair(frontNode->right,hd+1)); 
            }
            
        }
        
        
        for(auto i:nodes)
        {
            ans.push_back(i.second);
        }
        
        return ans;
    }
