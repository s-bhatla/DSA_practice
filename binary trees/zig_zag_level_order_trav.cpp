//soln for gfg question

vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    if(root->right == NULL && root->left == NULL){
        ans.push_back(root->data);
        return ans;
    }
    Node * curr = root;
    int currlevel  = 0;
    queue<pair<Node *, int>> q;
    q.push({curr, 0});
    vector<int> temp;
    while(!q.empty()){
        if(currlevel != q.front().second){
            //empty temp to fill ans and do it via odd even of currlevel
            if(currlevel%2 != 0){
                for(int i = 0; i < temp.size(); i++){
                    ans.push_back(temp[i]);
                }
                temp.clear();
            }
            else{
                for(int i = temp.size()-1; i >= 0; i--){
                    ans.push_back(temp[i]);
                }
                temp.clear();
            }
        }
        curr = q.front().first;
        currlevel = q.front().second;
        temp.push_back(curr->data);
        q.pop();
        if(curr->left != NULL){
            q.push({curr->left, currlevel+1});
        }
        if(curr->right != NULL){
            q.push({curr->right, currlevel+1});
        }
    }
    if(!temp.empty()){
            //empty temp to fill ans and do it via odd even of currlevel
            if(currlevel%2 != 0){
                for(int i = 0; i < temp.size(); i++){
                    ans.push_back(temp[i]);
                }
                temp.clear();
            }
            else{
                for(int i = temp.size()-1; i >= 0; i--){
                    ans.push_back(temp[i]);
                }
                temp.clear();
            }
        }
    return ans;
}