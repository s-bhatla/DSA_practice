//soln for gfg question note the type conversions.

static bool cmp(Item a, Item b){
        double ad, bd;
        ad = (double)a.value/a.weight;
        bd = (double)b.value/b.weight;
        return ad > bd;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double ans = 0.0;
        int currweight = 0;
        sort(arr, arr+n, cmp);
        int i = 0;
        for(int i = 0; i < n; i++){
            if(currweight + arr[i].weight < W){
                currweight += arr[i].weight;
                ans = ans + arr[i].value;
                // cout << ans << "iffy and wt is"<< W<<" \n";
                
            }
            else{
                ans += ((double)arr[i].value/arr[i].weight)*(W-currweight);
                break;
                // cout << ans << "elsey\n";
            }
        }
        return ans;
    }
        