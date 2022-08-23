//soln for gfg question fro dijkstra algo implementation

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        int MAX = INT_MAX;
        vector<int> dist;
        int min = 0;
        for(int i = 0; i < V; i++){
            dist.push_back(MAX);    
        }
        dist[S] = 0;
        int visited[V] = {0};
        int mini = S;
        queue<int> q;
        q.push(S);
        while(!q.empty()){
            S = q.front();
            q.pop();
            min = MAX;
            mini = -1;
            if(!visited[S]){
                for(int i = 0; i < adj[S].size(); i++){
                    if(dist[adj[S][i][0]] > dist[S] + adj[S][i][1]){
                        dist[adj[S][i][0]] = dist[S] + adj[S][i][1];
                    }
                }
            }
            visited[S] = 1;
            for(int i = 0; i < V; i++){
                if(!visited[i]){
                    if(dist[i] < min){
                        min = dist[i];
                        mini = i;
                    }
                }
            }
            if(mini != -1){
                q.push(mini);
            }
        }
        
        return dist;
    }