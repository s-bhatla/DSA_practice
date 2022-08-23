//dfs soln for gfg question of checking if a graph is bipartite or not


    bool dfsfxn(int V, vector<int> adj[], int color[], int s){
        
        for(int i = 0; i < adj[s].size(); i++){
            if(color[s] != -1){
                if(color[s] == 0){
                    if(color[adj[s][i]] == 0){
                        // cout << "s" << s << " and adjis" << adj[s][i] << endl;
                        return 0;
                    }
                    if(color[adj[s][i]] == -1){
                        color[adj[s][i]] = 1;
                        if(!dfsfxn(V, adj, color, adj[s][i])){
                            return 0;
                        }
                    }
                }
                if(color[s] == 1){
                    if(color[adj[s][i]] == 1){
                        // cout << "s" << s << " and adjis" << adj[s][i] << endl;
                        return 0;
                    }
                    if(color[adj[s][i]] == -1){
                        color[adj[s][i]] = 0;
                        if(!dfsfxn(V, adj, color, adj[s][i])){
                            return 0;
                        }
                    }
                }
            }
        }
        return 1;
    }


	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int color[V] = {-1};
	    for(int i = 0; i < V; i++){
	       color[i] = -1;
	    }
	    
	    for(int i = 0; i < V; i++){
	        if(color[i] == -1){
	            color[i] = 0;
	            if(!dfsfxn(V, adj, color, i)){
	               // cout << dfsfxn(V, adj, color,i) << "is\n";
	                return 0;
	            }
	        }
	    }
	    
	    return 1;
	}