//soln for gfg ques for iterative inorder traversal

vector<int> inOrder(Node* root)
    {
        //code here
        stack<Node *> stk;
        vector<int> ans;
        Node* curr = root;
        while(!stk.empty() || curr != NULL){
            while(curr != NULL){
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            ans.push_back(curr->data);
            stk.pop();
            
            curr = curr->right;
        }
        return ans;
    }