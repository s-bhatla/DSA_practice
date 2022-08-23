//soln code for basic gfg question of subset sums

void recsum(vector<int> arr, int N, vector<int>& ans, int sum, int p){
        if(p == N){
            ans.push_back(sum);
            return;
        }
        recsum(arr, N, ans, sum+arr[p], p+1);
        recsum(arr, N, ans, sum, p+1);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        recsum(arr, N, ans, 0, 0);
        return ans;
    }