//gfg code for topological sort using kahn's algo

//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> ans;
	    queue<int> q;
	    int indegrees[V] = {0};
	    int temp;
	    for(int i = 0; i < V; i++){
	        //storing indegrees
	        for(int j = 0; j < adj[i].size(); j++){
	            indegrees[adj[i][j]]++;
	        }
	    }
	   for(int i = 0; i < V; i++){
	       if(indegrees[i] == 0){
	           q.push(i);
	       }
	   }
	   
	    int s;
	    while(!q.empty()){
	        s = q.front();
	        q.pop();
	        ans.push_back(s);
	        for(int i = 0; i < adj[s].size(); i++){
	            indegrees[adj[s][i]]--;
	            if(indegrees[adj[s][i]] == 0){
	                q.push(adj[s][i]);
	            }
	        }
	    }
	    return ans;
	    
	}