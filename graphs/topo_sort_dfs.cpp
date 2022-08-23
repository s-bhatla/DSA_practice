//code for gfg question
//Function to return list containing vertices in Topological order. 
	
	stack<int> dfs(int V, vector<int> adj[], stack<int> stk, int s, int visited[]){
	    visited[s] = 1;
	    for(int i = 0; i < adj[s].size(); i++){
	        if(!visited[adj[s][i]]){
	            stk = dfs(V, adj, stk, adj[s][i], visited);
	        }
	    }
	    stk.push(s);
	    return stk;
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> ans;
	    stack<int> stk;
	    int visited[V] = {0};
	    for(int i = 0; i < V; i++){
	        if(!visited[i]){
	            stk = dfs(V, adj, stk, i, visited);
	        }
	    }
	    while(!stk.empty()){
	        ans.push_back(stk.top());
	        stk.pop();
	    }
	    
	    return ans;
	}