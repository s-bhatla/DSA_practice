//solution for topview of a binary tree gfg question

vector<int> topView(Node *root)
    {
        //Your code here
        map<int, Node*> mp;
        queue<pair<int, Node*>> q;
        int currdist;
        Node* currnode;
        q.push({0, root});
        while(!q.empty()){
            currnode = q.front().second;
            currdist = q.front().first;
            q.pop();
            if(!mp.count(currdist)){
                mp[currdist] = currnode;
            }
            if(currnode->left != NULL){
                q.push({currdist-1, currnode->left});
            }
            if(currnode->right != NULL){
                q.push({currdist+1, currnode->right});
            }
        }
        vector<int> ans;
        for(auto i:mp){
            ans.push_back((i.second)->data);
        }
        return ans;
    }