//code to find dia of binary tree

// Function to return the diameter of a Binary Tree.
    int max(int a, int b, int c){
        if(a >= b && a >= c){
            return a;
        }
        if(b >= a && b >= c){
            return b;
        }
        if(c >= a && c >= b){
            return c;
        }
    }
    
    int max2(int a, int b){
        if(a >= b){
            return a;
        }
        return b;
    }
    
    int calcheight(Node *root, int height){
        if(root == NULL){
            return height;
        }
        return max2(calcheight(root->left, height + 1), calcheight(root->right, height + 1));
    }
    
    int recDia(Node *root, int height){
        if(root == NULL){
            return height;
        }
        return max(recDia(root->left, height+1), recDia(root->right, height+1), (calcheight(root->left, 0)+calcheight(root->right, 0)+1));
    }
    
    int diameter(Node* root) {
        // Your code here
        return recDia(root, 0);
    }