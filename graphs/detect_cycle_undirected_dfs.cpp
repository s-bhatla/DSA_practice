//fxn only for gfg question
bool checkcycledfs(int visited[], int V, vector<int> adj[], int s, int parent){
        visited[s] = 1;
        for(int i = 0; i < adj[s].size(); i++){
            if(!visited[adj[s][i]]){
                if(checkcycledfs(visited, V, adj, adj[s][i], s)){
                    return 1;
                }
            }
            else if(visited[adj[s][i]]){
                if(adj[s][i] != parent){
                    return 1;
                }
            }
            
        }
        return 0;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int visited[V] = {0};
        for(int i = 0; i <V; i++){
            if(!visited[i]){
                if(checkcycledfs(visited, V, adj, i, -1)){
                    return 1;
                }
            }
        }
        return 0;
    }