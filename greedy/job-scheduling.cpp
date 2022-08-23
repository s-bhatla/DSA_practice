//code for gfg soln for job scheduling problem

static bool cmp(Job a, Job b){
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n, cmp);
        int count = 0;
        int maxp = 0;
        int timeline[101] = {0};
        for(int i = 0; i < n; i++){
            for(int j = arr[i].dead-1; j>=0; j--){
                if(timeline[j] == 0){
                    maxp = maxp + arr[i].profit;
                    count++;
                    timeline[j] = 1;
                    break;
                }
            }
        }
        vector<int> ans;
        ans.push_back(count);
        ans.push_back(maxp);
        return ans;
    } 