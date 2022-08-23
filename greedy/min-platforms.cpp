int maxnum(int a, int b){
        if(a > b){
            return a;
        }
        return b;
    }
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	int count, max;
    	count = 0;
    	max = count;
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	int arrp = 0;
    	int depp = 0;
    	while(arrp < n){
    	    if(arr[arrp] <= dep[depp]){
    	        count++;
    	        arrp++;
    	    }
    	    else if(dep[depp] < arr[arrp]){
    	        count--;
    	        depp++;
    	    }
    	    max = maxnum(max, count);
    	}
    	return max;
    }