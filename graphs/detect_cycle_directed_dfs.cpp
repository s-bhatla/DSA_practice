//ans fxn for gfg question
    bool dfsrec(int V, vector<int> adj[], int visited[], int recstack[], int s){
        visited[s] = 1;
        recstack[s] = 1;
        for(int i = 0; i < adj[s].size(); i++){
            if(!visited[adj[s][i]]){
                if(dfsrec(V, adj, visited, recstack, adj[s][i])){
                    return 1;
                }
            }
            else if(recstack[adj[s][i]]){
                return 1;
            }
        }
        recstack[s] = 0;
        return 0;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int visited[V] = {0};
        int recstack[V] = {0};
        for(int i =0; i < V; i++){
            if(!visited[i]){
                
                if(dfsrec(V, adj, visited, recstack, i)){
                    return 1;
                }
            }
        }
        return 0;
    }