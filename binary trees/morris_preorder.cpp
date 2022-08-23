//soln for gfg question - iterative preorder traversal

vector<int> preOrder(Node* root)
    {
        //code here
        vector<int> ans;
        Node * curr = root;
        stack<Node *> stk;
        stk.push(curr);
        while(!stk.empty()){
            curr = stk.top();
            ans.push_back(curr->data);
            stk.pop();
            if(curr->right != NULL){
                stk.push(curr->right);
            }
            if(curr->left != NULL){
                stk.push(curr->left);
            }
        }
        return ans;
    }