//this is the solution code for the gfg question get max width of binary tree.

int getMaxWidth(Node* root) {
        // Your code here
        queue<pair<int, Node*>> q;
        int width = 0;
        Node* currnode = root;
        int currlevel = 1;
        int currwidth = 1;
        q.push({currlevel, currnode});
        while(!q.empty()){
            currlevel = q.front().first;
            currnode = q.front().second;
            q.pop();
            if(currlevel != q.front().first){
                if(currwidth > width){
                    width = currwidth;
                }
                currwidth = 1;
            }
            else{
                currwidth++;
            }
            if(currnode->left != NULL){
                q.push({currlevel+1, currnode->left});
            }
            if(currnode->right != NULL){
                q.push({currlevel+1, currnode->right});
            }
        }
        return width;
    }