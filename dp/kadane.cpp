//leetcode solution for max sum subarray problem using kadane's algo

int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxsum = INT_MIN;
        int currsum = 0;
        for(int i = 0; i < n; i++){
            currsum = currsum + nums[i];
            if(currsum > maxsum){
                maxsum = currsum;
            }
            if(currsum < 0){
                currsum = 0;
            }
        }
        return maxsum;
    }