//code for bellman ford gfg question. note that the adj vector is diff from the rest of the questions
vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        // Code here
        vector<int> dist;
        int MAX = 100000000;
        for(int i = 0; i < V; i++){
            dist.push_back(MAX);
        }
        dist[S] = 0;
        
        for(int i = 0; i < V-1; i++){
            for(int j = 0; j < adj.size(); j++){
                S = adj[j][1];                                           //we are relaxing the 1st node and not the 0th, because in adj list rep, edge is from 0 to 1th node, (directed) so that is why 1st node is relaxed(due to direction of edge)
                if(dist[S] > dist[adj[j][0]] + adj[j][2]){
                    dist[S] = dist[adj[j][0]] + adj[j][2];
                }
            }
        }
        return dist;
        
    }