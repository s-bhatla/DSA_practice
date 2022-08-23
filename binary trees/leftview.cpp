//code for the gfg quesiton

vector<int> leftView(Node *root)
{
   // Your code here
   
   vector<int> ans;
   if(root == NULL){
       return ans;
   }
   Node * curr = root;
   queue<Node*> q;
   q.push(curr);
   int nsize;
   while(!q.empty()){
       ans.push_back(q.front()->data);
       nsize = q.size();
       for(int i = 0; i < nsize; i++){
           curr = q.front();
           q.pop();
           if(curr->left != NULL){
            q.push(curr->left);
           }
           if(curr->right != NULL){
            q.push(curr->right);
           }
       }
   }
   return ans;
}
