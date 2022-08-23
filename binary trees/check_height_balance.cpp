//This is solution code for checking if a binary tree is height balanced or not.

//Function to check whether a binary tree is balanced or not.
    int max(int a, int b){
        if(a >= b){
            return a;
        }
        return b;
    }
    
    int recHt(Node * root, int ht){
        if(root == NULL){
            return ht;
        }
        return max(recHt(root->left, ht+1), recHt(root->right, ht+1));
    }
    
    bool isBalanced(Node *root)
    {
        //  Your Code here
        if(root == NULL){
            return true;
        }
        
        if(recHt(root->right, 0) - recHt(root->left, 0) > 1 || recHt(root->right, 0) - recHt(root->left, 0) < -1){
            return false;
        }
        
        if(isBalanced(root->right)){
            if(isBalanced(root->left)){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }