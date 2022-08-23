//the code to find the least common ancestor in binary tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(root == NULL){
           return NULL;
       }
       
       if(root->data == n1 || root->data == n2){
           return root;
       }
       
       Node* right = lca(root->right, n1, n2);
       Node* left = lca(root->left, n1, n2);
       
       if(left == NULL){
           return right;
       }
       if(right == NULL){
           return left;
       }
       return root;
       
    }