static bool cmp(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++){
            v.push_back({start[i], end[i]});
        }
        sort(v.begin(), v.end(), cmp);
        // for(int i = 0; i < v.size(); i++){
        //     cout << v[i].first << " -=- " << v[i].second << endl;
        // }
        int ans = 1;
        int prevmin = 0;
        for(int i = 1; i < v.size(); i++){
            if(v[i].first > v[prevmin].second){
                ans++;
                prevmin = i;
            }
        }
        return ans;
    }