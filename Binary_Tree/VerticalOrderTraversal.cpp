vector<int> verticalOrder(Node *root)
    {
        vector<int> ans;
        map<int,map<int,vector<int>>> nodes;
        queue<pair<Node*,pair<int,int>>> q;
        
        q.push(make_pair(root,make_pair(0,0)));
        
        while(q.size()!=0)
        {
            pair<Node*,pair<int,int>> temp=q.front();
            
            Node* frontNode=temp.first;
            int hd=temp.second.first;
            int lvl=temp.second.second;
            
            q.pop();
            
            nodes[hd][lvl].push_back(frontNode->data);
            
            if(frontNode->left)
            {
                q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
            }
            
            if(frontNode->right)
            {
                q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
            }
            
            
            
        }
        
        for(auto i:nodes)
        {
            for(auto j:i.second)
            {
                for(auto k:j.second)
                {
                    ans.push_back(k);
                }
            }
        }
        
        
        return ans;
        
    }
};
