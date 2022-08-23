//this is the gfg code for checking if 2 binary trees are identical or not

//Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        if(r1 == NULL && r2 == NULL){
            return true;
        }
        else if(r1 == NULL || r2 == NULL){
            // cout << "this1";
            return false;
        }
        
        if(isIdentical(r1->right, r2->right)== false || isIdentical(r1->left, r2->left) == false){
            // cout << "this2";
            return false;
        }
        
        if(r1->data == r2->data){
            return true;
        }
        else{
            // cout << "this3";
            return false;
        }
    }