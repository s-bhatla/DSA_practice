//solution for gfg question for checking bipartite graphs

bool bfsfxn(int V, vector<int> adj[], int color[], int s){
        queue<int> q;
	    q.push(s);
	    color[s] = 0;
	    
	    
	    while(!q.empty()){
	        s = q.front();
	        q.pop();
	       // if(color[s] != -1){ //visited
	       //     //no need maybe
	            
	       // }
	       
	        if(color[s] != -1){
	            if(color[s] == 1){ //visited
	                //
	                for(int i =0 ; i < adj[s].size(); i++){
	                    if(color[adj[s][i]] == -1){
	                        color[adj[s][i]] = 0;
	                        q.push(adj[s][i]);
	                    }
	                    else if(color[adj[s][i]] == 1){
	                       // cout << "returning for s" << s << " and adjsi"<<adj[s][i] << endl; 
	                        return 0;
	                    }
	                }
	            }
	            else if(color[s] == 0){
	                //
	                for(int i =0 ; i < adj[s].size(); i++){
	                    if(color[adj[s][i]] == -1){
	                        
	                        color[adj[s][i]] = 1;
	                        q.push(adj[s][i]);
	                    }
	                    else if(color[adj[s][i]] == 0){
	                       // cout << "returning for s" << s << " and adjsi"<<adj[s][i] << endl; 
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
	            if(!bfsfxn(V, adj, color, i)){
	               // cout << bfsfxn(V, adj, color,i) << "is";
	                return 0;
	            }
	        }
	    }
	    
	    return 1;
	}