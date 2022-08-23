//code for gfg question
vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector<int> ans;
      if(node == NULL){
          return ans;
      }
      queue<Node*> q;
      Node* curr = node;
      q.push(curr);
      while(!q.empty()){
          curr = q.front();
          q.pop();
          ans.push_back(curr->data);
          if(curr->left != NULL){
              q.push(curr->left);
          }
          if(curr->right != NULL){
              q.push(curr->right);
          }
      }
      return ans;
    }