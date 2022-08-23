//this is the soln fxn for "Subsets" problem in gfg. It does not work 
//for the same leetcode question as that one doesnt allow duplicate sets

void recsubsets(vector<int>& nums, vector<vector<int>>& ans, vector<int> sub, int N, int p){
        if(p == N){
            ans.push_back(sub);
            return;
        }
        
        recsubsets(nums, ans, sub, N, p+1);
        sub.push_back(nums[p]);
        recsubsets(nums, ans, sub, N, p+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int N = nums.size();
        vector<int> subs;
        recsubsets(nums, ans, subs, N, 0);
        sort(ans.begin() ,ans.end());
        return ans;
    }