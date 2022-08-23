//fxn code for gfg
bool checkcyclebfs(int visited[], int V, vector<int> adj[], int s){
        queue<pair<int, int>> q;
        int parent = -1;
        q.push({s, parent});
        visited[s] = 1;
        while(!q.empty()){
            s = q.front().first;
            parent = q.front().second;
            q.pop();
            
            for(int i = 0; i < adj[s].size(); i++){
                if(!visited[adj[s][i]]){
                    q.push({adj[s][i], s});
                    visited[adj[s][i]] = 1;
                }
                else if(adj[s][i] != parent){
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
                if(checkcyclebfs(visited, V, adj, i)){
                    return 1;
                }
            }
        }
        return 0;
    }