//this is the soln to coding ninjas ques for all traversals of binary trees,but it doesnt work.
//because it cant import stack. dumbass. Also i feel this is kind of a dumb question. 
// just see strivers video or check the notes for algo

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> inorder;
    vector<int> preorder;
    vector<int> postorder;
    stack<pair<BinaryTreeNode<int> *, int>> s;
    BinaryTreeNode<int> * curr = root;
    int currnum = 1;
    s.push({curr, 1});
    while(!s.empty()){
        curr = s.top().first;
        currnum = s.top().second;
        s.pop();
        if(currnum == 1){
            preorder.push_back(curr->data);
            s.push({curr, 2});
            if(curr->left != NULL){
                s.push({curr->left, 1});
            }
        }
        if(currnum == 2){
            inorder.push_back(curr->data);
            s.push({curr, 3});
            if(curr->right != NULL){
                s.push({curr->right, 3});
            }
        }
        if(currnum == 3){
            postorder.push_back(curr->data);
        }
    }
    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);
    
    return ans;
}

