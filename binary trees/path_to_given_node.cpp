//this is the soln for finding path to given node on interview bit
//ALSO FUCK INTERVIEW BUT THAT FUCKING SCAM OF A FUCKING WEBSITE THE PIECE OF FUCKING SHIT FUCK THIS CODE HAS THE CORRECT OUTPUT IN ARR@ BUT +IN TESTCASE IT DOESNT RETURN THE SAME VALUE FUCK THIS PIECE OF SHIT ASS WEBSITE
//FUCK INTERVIEWBIT

 vector<int> arr;
 
 bool trav(TreeNode* A, int B){
     if(A == NULL){
         return false;
     }
     if(A->val == B){
         arr.push_back(B);
         return true;
     }
     if (trav(A->left, B) || (trav(A->right, B))){
         arr.push_back(A->val);
         return true;
     }
     return false;
 }
 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> arr2;
    if(trav(A, B)){
        for(int i = arr.size()-1; i >= 0; i--){
            arr2.push_back(arr[i]);
        }
    }
    return arr2;
}
