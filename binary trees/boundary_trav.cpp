//the soln for gfg ques of boundary traersal

bool isLeaf(Node* node){
        if(node->left == NULL && node->right == NULL){
            return true;
        }
        return false;
    }
    
    void inorderlvs(Node * p, vector<Node *> &lvs){
        if(p == NULL){
            return;
        }
        inorderlvs(p->left, lvs);
        if(isLeaf(p)){
            lvs.push_back(p);
        }
        inorderlvs(p->right, lvs);
        
    }
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        if(isLeaf(root)){
            vector <int> ans;
            ans.push_back(root->data);
            return ans;
        }
        vector<Node *> l;
        l.push_back(root);
        Node *p = root->left;
        
        while(p){
            if(!isLeaf(p)){
                l.push_back(p);
            }
            if(p->left == NULL){
                p = p->right;
            }
            else{
                p = p->left;
            }
        }
        vector<Node *> r;
        p = root->right;
        
        while(p){
            if(!isLeaf(p)){
                r.push_back(p);
            }
            if(p->right == NULL){
                p = p->left;
            }
            else{
                p = p->right;
            }
        }
        
        vector<Node *> lvs;
        p = root;
        inorderlvs(p, lvs);
        vector<int> ans;
        for(int i = 0; i < l.size(); i++){
            ans.push_back(l[i]->data);
        }
        for(int i = 0; i < lvs.size(); i++){
            ans.push_back(lvs[i]->data);
        }
        for(int i = r.size()-1; i >= 0 ; i--){
            ans.push_back(r[i]->data);
        }
        return ans;
    }