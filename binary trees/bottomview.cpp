//solution for the gfg question for finding the bottom view of the binary tree.

vector <int> bottomView(Node *root) {
        // Your Code Here
        map<int, Node*> mp;
        queue<pair<int, Node*>> q;
        q.push({0, root});
        Node* currnode;
        int currheight;
        vector<int> ans;
        while(!q.empty()){
            currnode = q.front().second;
            currheight = q.front().first;
            mp[currheight] = currnode;
            q.pop();
            if(currnode->left != NULL){
                q.push({currheight-1, currnode->left});
            }
            if(currnode->right != NULL){
                q.push({currheight+1, currnode->right});
            }
        }
        for(auto i:mp){
            ans.push_back((i.second)->data);
        }
        return ans;
    }