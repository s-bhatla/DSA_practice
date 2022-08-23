//code for gfg ques

bool bfsdetect(int V, vector<int> adj[]){
        int indegrees[V] = {0};
        for(int i = 0; i < V; i++){
            for(int j = 0; j < adj[i].size(); j++){
                indegrees[adj[i][j]]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegrees[i] == 0){
                q.push(i);
            }
        }
        int s;
        int count = 0;
        while(!q.empty()){
            s = q.front();
            q.pop();
            for(int i = 0; i < adj[s].size(); i++){
                indegrees[adj[s][i]]--;
                if(indegrees[adj[s][i]] == 0){
                    q.push(adj[s][i]);
                }
                
            }
            count++;
        }
        if(count == V){
            return 0;
        }
        else{
            return 1;
        }
    }
    
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int visited[V] = {0};
        if(bfsdetect(V, adj)){
                    return 1;
                }
        
        return 0;
    }